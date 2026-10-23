## Installation on Linux/MacOS

- You can follow the procedure for Windows, launching the exe with wine.
- Alternatively, you can perform the installation manually:
  1. Download `rpu_v*.zip` from the [latest release](https://github.com/BGforgeNet/Fallout2_Restoration_Project/releases/latest) page.
  1. If the game resides on a case-sensitive filesystem, lowercase game directory recursively.
  1. Extract the archive into the main game directory, overwriting files when asked.
  1. Launch `rpu-install.sh` (Linux) or `rpu-install.command` (MacOS).
  1. To play a localized version, see [translations](translations.md).

### Special note
When launching the game, you **must** set dll overrides: `WINEDLLOVERRIDES='ddraw.dll=n,b' wine fallout2.exe` (or use `winecfg` to configure them). If you don't do that, the game may run, but the restoration project will not apply correctly.
