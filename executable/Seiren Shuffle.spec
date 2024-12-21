# -*- mode: python ; coding: utf-8 -*-

a = Analysis(
    ['../Seiren Shuffle.pyw'],
    pathex=[],
    binaries=[],
    datas=[('../shared/','shared/'),('../randomizer/','randomizer/'),('../patch/','patch/')],
    hiddenimports=['soundfile'],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=['*.spec','dist/','build/'],
    noarchive=False,
)
pyz = PYZ(a.pure)

exe = EXE(pyz,
          a.scripts,
          a.binaries,
          a.zipfiles,
          a.datas,
          name='Seiren Shuffle',
          icon='../shared/ysR Logo.ico',
          debug=False,
          strip=False,
          upx=False,
          runtime_tmpdir=None,
          console=True )
