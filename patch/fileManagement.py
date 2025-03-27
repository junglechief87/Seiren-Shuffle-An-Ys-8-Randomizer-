import shutil
import os
import sys
import fsspec

parent_directory = os.path.join(os.path.dirname(sys.executable))
#originalFiles = os.listdir(parent_directory)
copiedFiles = os.path.join(parent_directory, 'Original Game Files')
repo = fsspec.filesystem("github", org="junglechief87", repo="Seiren-Shuffle-An-Ys-8-Randomizer-", ref='test')
folders = ['script/',
           'inc/',
           'text/en/']

def copyOriginalGameFiles():
    try:
        shutil.copytree(src=parent_directory, dst=copiedFiles, ignore=shutil.ignore_patterns('Seiren Shuffle.exe','Original Game Files'), dirs_exist_ok=False)
    except:
        """do nothing if the files already exist"""

def downloadFiles():
    for folder in folders:
        os.makedirs(folder, exist_ok=True)
        repo.get(repo.ls(folder), os.path.join(parent_directory,folder))

def restoreOriginalGameFiles():
    shutil.copytree(copiedFiles, parent_directory, dirs_exist_ok=True)
