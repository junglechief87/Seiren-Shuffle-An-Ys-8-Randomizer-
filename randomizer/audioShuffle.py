import re
import random
import csv
import sys
import os
import soundfile as sf

#Storing the original final as a variable for backup
ORIGINAL_FILE = r"""//===BGMテーブル=================================================
#include "inc/music.h"

//		×：候補曲も無い
//		△：とりあえず入れてみた
//		○：まぁいいんじゃないの
//		◎：ほぼ決定稿

//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
//定義が違えば同じ曲を指定していてもマップ切り替え時に曲がリスタートする
//マップデフォ曲で　BGM_Nothing　を指定しても無音にならず、直前のマップで鳴っていた曲が鳴り続ける
//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★

//	y8_tes01	1	00588450	05644537		//フィールド系１
//	y8_tes02	1	01680192	05286272		//フィールド系２
//	y8_tes03	1	00323584	04512384		//フィールド系３
//	y8_tes04	1	00144528	05904504		//ダンジョン系１
//	y8_tes05	1	00607878	06120524		//ダンジョン系２
//	y8_tes06	1	01334919	06744948		//村系

//tbl	BGM_NO			  filename	 LOOP	LoopStart	 LoopEnd		Comment

// システム系
bgmtbl	BGM_TITLE			y8_title	1	00128608	03925990	//		 	タイトル
bgmtbl	BGM_OPENING			y8_op		0	00000000	00000000	//			オープニング
//bgmtbl	BGM_GAMEOVER		y8_over		1	00128319	03925705	// 			ゲームオーバー
bgmtbl	BGM_ENDING			y8_end		0	00000000	00000000	// 			エンディング
bgmtbl	BGM_LOGO			y8_logo		0	00000000	00000000	// 			ロゴ
bgmtbl	BGM_PUZZLE			y8_muon		1	00050000	01000000	// 			パズル用ＢＧＭ

//00122607	04953308

// フィールド
bgmtbl	BGM_FIELD_101		y8_f101		1	00450784	08694455	//	南部平地
bgmtbl	BGM_FIELD_201		y8_f201		1	00098080	05788656	//	南部浜辺
bgmtbl	BGM_FIELD_301		y8_f301		1	00639640	05490112	//	南部森
bgmtbl	BGM_FIELD_401		y8_f401		1	00328772	05355682	//	南部高原・丘陵
bgmtbl	BGM_FIELD_501		y8_f501		1	00305912	08226094	//	北部山岳、天崖丘陵
bgmtbl	BGM_FIELD_601		y8_f601		1	00128672	05469714	//	古代原生林・大湿原
bgmtbl	BGM_FIELD_701		y8_f701		1	00349512	07973043	//	古代平原
bgmtbl	BGM_FIELD_801		y8_f801		1	00105751	07176616	//	トワル街道、悠久の丘
bgmtbl	BGM_FIELD_901		y8_f901		1	00369783	05622903	//	過去編フィールド（ダーナ操作）

// 街
bgmtbl	BGM_TOWN_101		y8_t101		1	00180381	05099922	// 	漂流村
bgmtbl	BGM_TOWN_201		y8_e004		1	00319871	04455262	// 	タナトスの小屋、最初期の漂流村
bgmtbl	BGM_TOWN_301		y8_t301		1	00560282	05382620	// 	エタニア市街_過去
bgmtbl	BGM_TOWN_302		y8_e002		1	00331200	05399552	// 	エタニア市街_現代廃墟
bgmtbl	BGM_TOWN_401		y8_t401		1	01808828	05401031	// 	エタニア王宮、大樹の寺院
bgmtbl	BGM_TOWN_501		y8_t501		1	00098042	04804148	// 	漂流村（第３部以降）
bgmtbl	BGM_TOWN_601		y8_muon		1	00050000	01000000	//	


// ダンジョン
bgmtbl	BGM_DUNGEON_101		y8_d101		1	00788522	07192984	// 	珊瑚の森
bgmtbl	BGM_DUNGEON_201		y8_d201		1	00460100	04928428	// 	巨木の密林
bgmtbl	BGM_DUNGEON_301		y8_d301		1	00370110	05554088	// 	侵食谷
bgmtbl	BGM_DUNGEON_401		y8_d401		1	00207792	07450198	// 	ジャンダルム
bgmtbl	BGM_DUNGEON_501		y8_d501		1	00402656	06777280	// 	ラスダン：はじまりの大樹
bgmtbl	BGM_DUNGEON_502		y8_d502		1	00704928	04885504	// 	ラスダン：回廊
bgmtbl	BGM_DUNGEON_503		y8_d503		1	02631730	06111642	// 	ラスダン：選択の間
bgmtbl	BGM_DUNGEON_601		y8_d601		1	00724836	06796180	// 	バハの斜塔
bgmtbl	BGM_DUNGEON_701		y8_d701		1	00654369	06545343	// 	王家の谷
bgmtbl	BGM_DUNGEON_801		y8_d801		1	00271160	06394231	//	始生代の大穴

bgmtbl	BGM_DUNGEON_901		y8_d901		1	00504892	05784919	//	洞窟系サブダン
bgmtbl	BGM_DUNGEON_902		y8_d902		1	00164848	04499016	//	建物系サブダン
bgmtbl	BGM_DUNGEON_903		y8_d903		1	00024098	04651812	//	幽霊船
bgmtbl	BGM_DUNGEON_904		y8_d904		1	00109325	02972754	//	はじまりの深淵

//bgmtbl	BGM_DUNGEON_910		y8_d9101		1	00271992	05598264	//	ＰＳ４追加：地下聖堂過去
//bgmtbl	BGM_DUNGEON_910		y8_d9102		1	01643520	05832704	//	ＰＳ４追加：地下聖堂過去
//bgmtbl	BGM_DUNGEON_910		y8_d9103		1	00681472	06885627	//	ＰＳ４追加：地下聖堂過去
bgmtbl	BGM_DUNGEON_910		y8_d910		1	00070724	05007872	//	ＰＳ４追加：地下聖堂過去
bgmtbl	BGM_DUNGEON_911		y8_d911		1	01220468	06157687	//	ＰＳ４追加：地下聖堂現代
bgmtbl	BGM_DUNGEON_912		y8_d912		1	00681472	06885627	//	ＰＳ４追加：地下聖堂過去第６層

bgmtbl	BGM_DUNGEON_920		y8_d920		1	01643520	05832704	//	ＰＳ４追加：夜ダンジョン

// ボス戦
bgmtbl	BGM_BOSS_001		y8_b001		1	00550204	06136139	// 中ボス戦闘	ダンジョン中継（特にセリフとかないやつ）
bgmtbl	BGM_BOSS_002		y8_b002		1	00231790	05351933	// ザコイベント戦闘
bgmtbl	BGM_BOSS_003		y8_b003		1	00284597	04907818	// 大ボス１　ダンジョン締め、古代種
bgmtbl	BGM_BOSS_004		y8_b004		1	01528198	07699650	// 大ボス２　護り人
bgmtbl	BGM_BOSS_005		y8_b005		1	01312665	06134911	// オケアノス
//bgmtbl	BGM_BOSS_006		y8_b006		1	01118352	07972024	// エンドログラム
bgmtbl	BGM_BOSS_006		y8_b006		1	01403792	07552558	// エンドログラム
//bgmtbl	BGM_BOSS_007		y8_b007		1	01403792	07552558	// はじまりのいのち
bgmtbl	BGM_BOSS_007		y8_b007		1	01601216	05587200	// はじまりのいのち
bgmtbl	BGM_BOSS_009		y8_b009		1	01215552	05485952	// はじまりのいのち（子供）
bgmtbl	BGM_BOSS_008		y8_b008		1	00939816	05302217	// 迎撃戦

bgmtbl	BGM_BOSS_010		y8_b010		1	00757955	06580613	// ＰＳ４追加：制圧戦
bgmtbl	BGM_BOSS_011		y8_b011		1	00817664	05176797	// ＰＳ４追加：イオ戦

// イベント系
bgmtbl	BGM_EVENT_001		y8_e001		1	00508788	04920703	//	コミカル
bgmtbl	BGM_EVENT_002		y8_e002		1	00331200	05399552	//	アドルの夢・過去編回想
bgmtbl	BGM_EVENT_003		y8_e003		1	00566058	06144929	//	船上シーン
bgmtbl	BGM_EVENT_004		y8_e004		1	00319871	04455262	//	会話汎用
bgmtbl	BGM_EVENT_005		y8_e005		1	00335440	05472744	//	夜、しんみり
bgmtbl	BGM_EVENT_006		y8_muon		1	00050000	01000000	//	
bgmtbl	BGM_EVENT_007		y8_e007		1	00143372	03485240	//	宴会２ワルツ
bgmtbl	BGM_EVENT_008		y8_e008		1	00438580	04470579	//	不安・シリアス
bgmtbl	BGM_EVENT_009		y8_muon		1	00050000	01000000	//	
bgmtbl	BGM_EVENT_010		y8_e010		1	00251459	02979832	//	緊張
bgmtbl	BGM_EVENT_011		y8_e011		1	00199194	04629940	//	危機
bgmtbl	BGM_EVENT_012		y8_e012		1	00283386	05352414	//	戦闘前
bgmtbl	BGM_EVENT_013		y8_e013		1	00793655	07132054	//	神秘系
bgmtbl	BGM_EVENT_014		y8_e014		1	01406031	06548622	//	メテオ襲来
bgmtbl	BGM_EVENT_015		y8_e015		1	02062640	08503544	//	ダーナのテーマ
bgmtbl	BGM_EVENT_016		y8_e016		1	00149353	04323264	//	絆系
bgmtbl	BGM_EVENT_017		y8_e017		1	00307275	05083861	//	深刻
bgmtbl	BGM_EVENT_018		y8_e018		1	00396549	05877763	//	大地神マイア登場
bgmtbl	BGM_EVENT_019		y8_e019		1	00367047	03000264	//	演奏会
bgmtbl	BGM_EVENT_020		y8_muon		1	00050000	01000000	//	

bgmtbl	BGM_MUON			y8_muon		1	00050000	01000000	//

//---------------------------------------------------------------------
// 無音・曲停止

bgmtbl	BGM_Nothing			ed6999		0	00000000	00000000		// 検索終了コード

//---------------------------------------------------------------------



"""

#This has the values for the original audio that can get randomized. This is useful when you add external audio so that we can still keep the clean loops from the original ingame bgm
BGM_DATA = {
    "y8_f801": ["1", "00105751", "07176616"],
    "y8_e005": ["1", "00335440", "05472744"],
    "y8_d701": ["1", "00654369", "06545343"],
    "y8_d501": ["1", "00402656", "06777280"],
    "y8_d912": ["1", "00681472", "06885627"],
    "y8_d902": ["1", "00164848", "04499016"],
    "y8_d101": ["1", "00788522", "07192984"],
    "y8_f101": ["1", "00450784", "08694455"],
    "y8_e015": ["1", "02062640", "08503544"],
    "y8_t501": ["1", "00098042", "04804148"],
    "y8_t101": ["1", "00180381", "05099922"],
    "y8_e001": ["1", "00508788", "04920703"],
    "y8_d904": ["1", "00109325", "02972754"],
    "y8_e018": ["1", "00396549", "05877763"],
    "y8_b007": ["1", "01601216", "05587200"],
    "y8_b002": ["1", "00231790", "05351933"],
    "y8_d301": ["1", "00370110", "05554088"],
    "y8_d201": ["1", "00460100", "04928428"],
    "y8_b010": ["1", "00757955", "06580613"],
    "y8_b003": ["1", "00284597", "04907818"],
    "y8_e019": ["1", "00367047", "03000264"],
    "y8_d901": ["1", "00504892", "05784919"],
    "y8_f601": ["1", "00128672", "05469714"],
    "y8_d903": ["1", "00024098", "04651812"],
    "y8_f901": ["1", "00369783", "05622903"],
    "y8_f501": ["1", "00305912", "08226094"],
    "y8_e010": ["1", "00251459", "02979832"],
    "y8_title": ["1", "00128608", "03925990"],
    "y8_b006": ["1", "01403792", "07552558"],
    "y8_b005": ["1", "01312665", "06134911"],
    "y8_e008": ["1", "00438580", "04470579"],
    "y8_logo": ["1", "00000000", "00480000"],
    "y8_e012": ["1", "00283386", "05352414"],
    "y8_e002": ["1", "00331200", "05399552"],
    "y8_d801": ["1", "00271160", "06394231"],
    "y8_e004": ["1", "00319871", "04455262"],
    "y8_e016": ["1", "00149353", "04323264"],
    "y8_d503": ["1", "02631730", "06111642"],
    "y8_d910": ["1", "00070724", "05007872"],
    "y8_b004": ["1", "01528198", "07699650"],
    "y8_end": ["1", "00000000", "12816000"],
    "y8_e017": ["1", "00307275", "05083861"],
    "y8_d601": ["1", "00724836", "06796180"],
    "y8_e013": ["1", "00793655", "07132054"],
    "y8_f401": ["1", "00328772", "05355682"],
    "y8_b011": ["1", "00817664", "05176797"],
    "y8_f301": ["1", "00639640", "05490112"],
    "y8_b009": ["1", "01215552", "05485952"],
    "y8_b001": ["1", "00550204", "06136139"],
    "y8_e007": ["1", "00143372", "03485240"],
    "y8_t401": ["1", "01808828", "05401031"],
    "y8_e003": ["1", "00566058", "06144929"],
    "y8_b008": ["1", "00939816", "05302217"],
    "y8_d920": ["1", "01643520", "05832704"],
    "y8_d502": ["1", "00704928", "04885504"],
    "y8_d401": ["1", "00207792", "07450198"],
    "y8_f701": ["1", "00349512", "07973043"],
    "y8_t301": ["1", "00560282", "05382620"],
    "y8_op": ["1", "00000000", "07968000"],
    "y8_e011": ["1", "00199194", "04629940"],
    "y8_d911": ["1", "01220468", "06157687"],
    "y8_f201": ["1", "00098080", "05788656"],
    "y8_e014": ["1", "01406031", "06548622"]
}

# returns a list with the info of all audios 
# (filename, loopFlag, loopstart, loopend) from bgm folder
def generate_audio_info():
  # Load ys8audio.csv to get the original audio info
  original_audio_info = {} #Filename => [loop_flag, loop_start, loop_end]
  exe_dir = os.path.dirname(sys.executable)

  for filename in BGM_DATA.keys():
    original_audio_info[filename] = [BGM_DATA[filename][1], BGM_DATA[filename][2]] # [loop_start, loop_end]

  # List to store all audio information, including extra audio files
  all_audio_info = []

  # Process extra audio files in the bgm folder
  bgm_folder = os.path.join(exe_dir, 'bgm')
  for filename in os.listdir(bgm_folder):
    if filename.endswith('.ogg'):
      # Remove '.ogg' extension
      file_base_name = filename[:-4]
      loop_flag = "1"
      loop_start = '00000000'
      loop_end = '00000000'
          
      # Skip audioless files
      if file_base_name == 'y8_muon':
        continue
    
      if file_base_name in original_audio_info:
        loop_start, loop_end = original_audio_info[file_base_name]
      else: 
        audio_path = os.path.join(bgm_folder, filename)

        #loop_end = int(track_length_in_seconds * 48000)
        loop_end = len(sf.SoundFile(audio_path))

      # Create tuple with filename, LoopFlag, LoopStart, and LoopEnd
      loop_end = int(loop_end)
      extra_audio_info = (file_base_name, loop_flag, loop_start, f"{loop_end:08d}")
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
            audio_index = i % len(audio_data)  # Cycle through audio_data
            row[1], row[2], row[3], row[4] = audio_data[audio_index]

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
        print(f"An error occurred at randomize_bgmtbl: {e}")


def restore_original_bgm():
    exe_dir = os.path.dirname(sys.executable)
    bgm_path = os.path.join(exe_dir, "text", "bgmtbl.tbl")
    
    try:
        # Write with explicit Shift-JIS encoding and Windows line endings
        with open(bgm_path, 'w', encoding='shift_jis', newline='\r\n') as f:
            f.write(ORIGINAL_FILE)
        print("Original BGM table was restored!")
        return True
    except Exception as e:
        print(f"Failed restoring original bgm file: {str(e)}")
        return False

if __name__ == "__main__":
    randomize_bgmtbl()
