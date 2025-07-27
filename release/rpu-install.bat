set "bdir=backup\rpu"
set "scripts_dir=data\scripts"

if not exist %bdir% mkdir %bdir%

if exist patch000.dat (
  move patch000.dat %bdir%\
)
if exist f2_res.dat (
  move f2_res.dat %bdir%\
)

:: Backup old mods_order.txt if exists
if exist mods\mods_order.txt (
  move mods\mods_order.txt %bdir%\
)
move /y mods_order.txt mods\mods_order.txt

:: I don't know how to iterate over files in batch properly, so just moving back and forth
move /y data %bdir%\
mkdir data\sound
move /y %bdir%\data\savegame data\
move /y %bdir%\data\*.txt data\
move /y %bdir%\data\*.gcd data\
move /y %bdir%\data\sound\music data\sound\

:: old appearance mod in directories
set appearances=hfr00s00,hfr00s01,hfr00s02,hmr00s00,hmr00s01,hmr00s02
for %%a in (%appearances%) do (
  if exist appearance\%%a (
    if not exist %bdir%\appearance mkdir %bdir%\appearance
    move appearance\%%a %bdir%\appearance\
  )
)

:: sfall scripts
mkdir %scripts_dir%
move /y gl_ammomod.int %scripts_dir%\

del /s rpu-install.sh rpu-install.bat rpu-install.command
echo RPU installed. Backup is in %bdir%
