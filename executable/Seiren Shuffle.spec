# -*- mode: python ; coding: utf-8 -*-

a = Analysis(
    ['../Seiren Shuffle.pyw'],
    pathex=[],
    binaries=[],
    datas=[('../shared/','shared/'),('../randomizer/','randomizer/'),('../patch/','patch/')],
    hiddenimports=[],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[],
    noarchive=False,
    optimize=0,
)
pyz = PYZ(a.pure)

exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          name='Seiren Shuffle',
          icon='ysR Logo.ico'
          debug=False,
          strip=False,
          upx=False,
          runtime_tmpdir=None,
          console=False )
