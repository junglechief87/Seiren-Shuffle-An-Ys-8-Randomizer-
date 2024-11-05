import re
import random
import csv
import sys
import os
from pydub import AudioSegment

# returns a list with the info of all audios 
# (filename, loopFlag, loopstart, loopend) from bgm folder
def generate_audio_info():
  # Load ys8audio.csv to get the original audio info
  original_audio_info = []
  exe_dir = os.path.dirname(sys.executable)
  csv_path = os.path.join(exe_dir, 'shared', 'database', 'ys8audio.csv')

  try:
    with open(csv_path, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            filename, loop_flag, loop_start, loop_end = row
            original_audio_info.append((filename, loop_flag, loop_start, loop_end))
  except FileNotFoundError:
    print(f"Error: The file '{csv_path}' was not found.")
  except Exception as e:
    print(f"An error occurred: {e}")

  # Get a set of original filenames for O(1) comparison
  original_filenames = {info[0] for info in original_audio_info}

  # List to store all audio information, including extra audio files
  all_audio_info = original_audio_info.copy()

  # Process extra audio files in the bgm folder
  #bgm_folder = '../bgm'
  bgm_folder = os.path.join(exe_dir, 'bgm')
  for filename in os.listdir(bgm_folder):
      if filename.endswith('.ogg'):
          # Remove '.ogg' extension
          file_base_name = filename[:-4]
          
          # Skip files that are part of the original audio
          if file_base_name in original_filenames or file_base_name == 'y8_muon':
              continue

          # Load the audio file to get its duration in seconds
          audio_path = os.path.join(bgm_folder, filename)
          loop_flag = "1"
          audio = AudioSegment.from_file(audio_path)
          track_length_in_seconds = audio.duration_seconds

          # Calculate LoopEnd
          loop_end = int(track_length_in_seconds * 48000) - 24000

          # Create tuple with filename, LoopFlag, LoopStart, and LoopEnd
          extra_audio_info = (file_base_name, loop_flag, '00000000', f"{loop_end:08d}")
          all_audio_info.append(extra_audio_info)
          
  return all_audio_info

def randomize_bgmtbl(seed):
    # File path to the bgmtbl.tbl file
    #file_path = "../text/bgmtbl.tbl"
    exe_dir = os.path.dirname(sys.executable)
    txt_folder = os.path.join(exe_dir, 'text')
    file_path = os.path.join(txt_folder, 'bgmtbl.tbl')

    try:
        # Read the file with Shift-JIS encoding
        with open(file_path, 'r', encoding='shift_jis') as file:
            lines = file.readlines()

        # Rows to be excluded from shuffling (audioless files)
        excluded_rows = [
            "bgmtbl\tBGM_MUON\t\t\ty8_muon\t\t1\t00050000\t01000000\t//",
            "bgmtbl\tBGM_Nothing\t\t\ted6999\t\t0\t00000000\t00000000\t\t// 検索終了コード",
            "bgmtbl\tBGM_EVENT_020\t\ty8_muon\t\t1\t00050000\t01000000\t//",
            "bgmtbl\tBGM_PUZZLE\t\t\ty8_muon\t\t1\t00050000\t01000000\t// \t\t\tパズル用ＢＧＭ",
            "bgmtbl\tBGM_TOWN_601\t\ty8_muon\t\t1\t00050000\t01000000\t//",
            "bgmtbl\tBGM_EVENT_006\t\ty8_muon\t\t1\t00050000\t01000000\t//",
            "bgmtbl\tBGM_EVENT_009\t\ty8_muon\t\t1\t00050000\t01000000\t//",
        ]

        # Extract rows starting with "bgmtbl" and their audio info
        bgmtbl_rows = []
        for line in lines:
            # Skip excluded rows
            if line.strip() in excluded_rows:
                # print(line.strip())
                continue

            if line.startswith("bgmtbl"):
                # Use regex to match the components in each bgmtbl row
                match = re.match(r"(bgmtbl\s+\S+\s+)(\S+)\s+(\d+)\s+(\d+)\s+(\d+)(\s+//.*)?", line)
                if match:
                    prefix = match.group(1)  # "bgmtbl" and the track name
                    audio_file = match.group(2)  # Audio file name
                    loop_flag = match.group(3)  # Loop flag
                    loop_start = match.group(4)  # Loop start
                    loop_end = match.group(5)  # Loop end
                    comment = match.group(6) if match.group(6) else ""  # Comment
                    bgmtbl_rows.append([prefix, audio_file, loop_flag, loop_start, loop_end, comment])

        # Extract only the audio file name, loop start, and loop end for shuffling
        #audio_data = [(row[1], row[3], row[4]) for row in bgmtbl_rows]
        audio_data = generate_audio_info()
        random.seed(seed)
        random.shuffle(audio_data)

        # Assign the shuffled values back to the rows
        for i, row in enumerate(bgmtbl_rows):
            row[1], row[2], row[3], row[4] = audio_data[i]

        # Rebuild the modified lines
        modified_lines = []
        bgmtbl_index = 0
        for line in lines:
            if line.startswith("bgmtbl") and line.strip() not in excluded_rows:
                modified_line = f"{bgmtbl_rows[bgmtbl_index][0]}{bgmtbl_rows[bgmtbl_index][1]}\t" \
                                f"{bgmtbl_rows[bgmtbl_index][2]}\t{bgmtbl_rows[bgmtbl_index][3]}\t" \
                                f"{bgmtbl_rows[bgmtbl_index][4]}{bgmtbl_rows[bgmtbl_index][5]}\n"
                modified_lines.append(modified_line)
                bgmtbl_index += 1
            else:
                modified_lines.append(line)

        # Write the modified content back to the file
        with open(file_path, 'w', encoding='shift_jis') as file:
            file.writelines(modified_lines)

        #print("File modified successfully.")

    except FileNotFoundError:
        print(f"File '{file_path}' not found.")
    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    randomize_bgmtbl()
