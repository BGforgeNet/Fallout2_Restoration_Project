#define basename "rpu"
#define backup_dir "backup\" + basename
#define mods_dir "{app}\mods"
; build process shenanigans, see inno.sh
#define version "v0"

[Setup]
AppName=Fallout 2 Restoration Project
AppVerName=Fallout 2 Restoration Project {#version}
AppId=Fallout 2 Restoration Project
AppPublisher=BGforge
AppPublisherURL=https://bgforge.net
AppSupportURL=https://forums.bgforge.net/viewforum.php?f=34
AppUpdatesURL=https://github.com/BGforgeNet/Fallout2_Restoration_Project
VersionInfoTextVersion={#version}
DefaultDirName=C:\Games\Fallout2
AppendDefaultDirName=no
DisableProgramGroupPage=yes
OutputBaseFilename={#basename}_v{#version}
Compression=lzma
DirExistsWarning=no
Uninstallable=no
InfoBeforeFile=before.rtf
SetupIconFile=nuclear.ico
DisableDirPage=no
UsePreviousAppDir=no
AlwaysShowDirOnReadyPage=yes

[Files]
Source: "release\*.*"; DestDir: "{app}"; Components: core; Flags: ignoreversion recursesubdirs overwritereadonly
#include "files_translations.iss"
Source: "optional\rpu_alternative_explosions.dat"; DestDir: "{#mods_dir}"; Components: alternative_explosions; Flags: ignoreversion overwritereadonly
Source: "optional\rpu_enhanced_worldmap.dat"; DestDir: "{#mods_dir}"; Components: worldmap; Flags: ignoreversion overwritereadonly
Source: "optional\rpu_rifle_animations.dat"; DestDir: "{#mods_dir}"; Components: wpn_anims\rifle; Flags: ignoreversion overwritereadonly
Source: "optional\rpu_wakizashi_animations.dat"; DestDir: "{#mods_dir}"; Components: wpn_anims\wakizashi; Flags: ignoreversion overwritereadonly
Source: "optional\rpu_extended_flamer.dat"; DestDir: "{#mods_dir}"; Components: wpn_anims\ext_flamer; Flags: ignoreversion overwritereadonly
Source: "optional\cassidy_head.dat"; DestDir: "{#mods_dir}"; Components: cassidy_head; Flags: ignoreversion overwritereadonly
Source: "optional\cassidy_voice_joey_bracken_hq.dat"; DestDir: "{#mods_dir}"; Components: cassidy_head; Flags: ignoreversion overwritereadonly
Source: "optional\rpu_improved_mysterious_stranger.dat"; DestDir: "{#mods_dir}"; Components: imp_stranger; Flags: ignoreversion overwritereadonly
Source: "optional\walk_speed_fix_low_fps.dat"; DestDir: "{#mods_dir}"; Components: walk_speed\low_fps; Flags: ignoreversion overwritereadonly
Source: "optional\goris_fast_derobing_low_fps.dat"; DestDir: "{#mods_dir}"; Components: goris\low_fps; Flags: ignoreversion overwritereadonly

[INI]
#include "ini_translations.iss"
#include "ini_qol.iss"
#include "ini_debug.iss"
#include "ini_sound.iss"
#include "ini_ammo.iss"

[Dirs]
Name: "{app}\{#backup_dir}"

[Run]
Filename: "{app}\{#basename}-install.bat"; Parameters: "> {#backup_dir}\log.txt 2>&1"; WorkingDir: "{app}"; Description: "install script";

[Components]
Name: "core"; Description: "Core"; Types: "custom"; Flags: fixed;
Name: "translation"; Description: "Language"; Types: "custom"; Flags: fixed;
#include "components_translations.iss"

#include "components_ammo.iss"

Name: "walk_speed"; Description: "Walk speed fix"; Types: "custom";
Name: "walk_speed\high_fps"; Description: "High FPS"; Flags: exclusive disablenouninstallwarning;
Name: "walk_speed\low_fps"; Description: "Low FPS"; Flags: exclusive disablenouninstallwarning;

Name: "goris"; Description: "Faster derobing for Goris"; Types: "custom";
Name: "goris\high_fps"; Description: "High FPS"; Flags: exclusive disablenouninstallwarning;
Name: "goris\low_fps"; Description: "Low FPS"; Flags: exclusive disablenouninstallwarning;

Name: "qol"; Description: "Enable sfall QoL features"; Types: "custom";

Name: "worldmap"; Description: "Visually enhanced world map"; Types: "custom";  Flags: disablenouninstallwarning

Name: "wpn_anims"; Description: "Weapon animations"; Types: "custom"
Name: "wpn_anims\rifle"; Description: "New rifle animations"; Types: "custom"; Flags: disablenouninstallwarning;
Name: "wpn_anims\wakizashi"; Description: "New wakizashi blade animations"; Types: "custom"; Flags: disablenouninstallwarning;
Name: "wpn_anims\ext_flamer"; Description: "Extended flamer attack animations"; Types: "custom"; Flags: disablenouninstallwarning;

Name: "cassidy_head"; Description: "Talking head and voice for Cassidy"; Types: "custom"; Flags: disablenouninstallwarning;

Name: "imp_stranger"; Description: "Improved Mysterious Stranger"; Types: "custom";  Flags: disablenouninstallwarning

Name: "alternative_explosions"; Description: "Alternative explosion animations (from Tactics)"; Flags: disablenouninstallwarning

[Types]
Name: "custom"; Description: "Custom Selection"; Flags: iscustom

#include "preinstall.iss"
