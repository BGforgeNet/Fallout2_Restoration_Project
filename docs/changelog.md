## Changelog

- This file lists changes for RPU only (since RP 2.3.3).
- In addition to the below list, RPU releases contain all applicable fixes from the corresponding [UPU releases](https://github.com/BGforgeNet/Fallout2_Unofficial_Patch/blob/master/docs/changelog.md).
- Sometimes UPU or RPU may be updated independently, which is why you might see gaps in version numbers.
- Versions `2.4.*` contain [updated maps](https://forums.bgforge.net/viewtopic.php?t=371) produced by Pixote, and related script changes. Otherwise, they follow the same patch level convention.

---

- [Version 34](#version-34)
- [Version 33](#version-33)
- [Version 32](#version-32)
- [Version 30](#version-30)
- [Version 29](#version-29)
- [Version 28](#version-28)
- [Version 27](#version-27)
- [Version 26](#version-26)
- [Version 25](#version-25)
- [Version 24](#version-24)
- [Version 23](#version-23)
- [Version 22](#version-22)
- [Version 21](#version-21)
- [Version 20](#version-20)
- [Version 18](#version-18)
- [Version 17](#version-17)
- [Version 16](#version-16)
- [Version 14](#version-14)
- [Version 13](#version-13)
- [Version 12](#version-12)
- [Version 11](#version-11)
- [Version 10](#version-10)
- [Version 9](#version-9)
- [Version 8](#version-8)
- [Version 7](#version-7)
- [Version 6](#version-6)
- [Version 5](#version-5)
- [Version 4](#version-4)
- [Version 3](#version-3)
- [Version 2](#version-2)
- [Version 1](#version-1)
- killap's RP 2.3.3
  - [readme](rp-readme.txt)
  - [changelog](rp-changelog.txt)

### Version 34

(AKA 2.3.34, 2.4.34)

All the same fixes as in [UPU v34](https://github.com/BGforgeNet/Fallout2_Unofficial_Patch/blob/master/docs/changelog.md#version-34).

### Version 33

(AKA 2.3.33, 2.4.33)

#### General

- Alcohol and Tragic addictions [will correctly show tags](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/326) when in effect.

#### Locations

- Arroyo
  - Fixed scenery alignment in Temple.
- EPA
  - The hologram computer [can now be fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/325) using multitool and supertool.

### Version 32

(AKA 2.3.32, 2.4.32)

#### General

[Reordered](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/322) the ending slides to keep tank vagrants as the last one.

#### Locations

- Abbey
  - Edited map lighting handling for Abbey (and also Dr.Sheng's hideout) to be more natural.
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/275) xp messages with correct Swift Learner bonus for Abbey.
  - Fixed incorrect xp reward for causing Jack the healer to melt.
- Arroyo
  - Fixed missing light source in temple map.
- Den
  - Fixed Karl not disappearing after walking out of view.
- Klamath
  - Fixed the golden gecko pelt appearance in the locked room in Klamath downtown.
- Navarro
  - Added a failsafe for the player getting stuck in Navarro (if they killed the landing pad guards before boarding the vertibird during the secret transaction in New Reno).
  - Added a check for the commander to the surrender dialog option, as there's no point in taking the player to an empty room.
- NCR
  - Fixed reputation check for Vortis (regardless of karma if PC has Cult perk).
- Umbra Tribe
  - Fixed the injured hunter (Serin) getting stuck in the cave on his way to exit.
  - Tribesmen will no longer play equip spear animation every time that combat is started.
  - One female tribal gets a sledgehammer instead, to show Pixote's extra tribal animation.
  - Fishermen have their inventory fixed, before they had a stack of 0 poles.
  - Patched up borders for the waterside map.
- Vault Village
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/314) an intermittent crash on entering the zone.

### Version 30

- General
  - Fix: new PCs properly get Virgin of the Wastes title (broken in v29).
  - Fix: Alcohol addiction now also applies when using alcohol from inventory. Penalty for addiction is changed to -1 Agi, -1 Cha, like in other Fallout games (previously was -2 PE). Finally, drug-related perks are also taken into account.
- Random encounters
  - Fixed Arroyo Nomads encounter possibly missing some critters.
- EPA
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/pull/288) EPA holograms multiplying floaters on save/load.
  - [Fix](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/286): Kitsune is no longer prevented from using Lockpick skill when wearing Power Armor.

### Version 29

#### General

- Enhanced worldmap: visible city ruins are now present on tiles set as the "city" terrain type, by Lexx.
- Installer
  - More components are optional.

#### Locations

- Abbey
  - PC now always [notes](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/266) Peterson's complaints about crops.
- Den
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/138) Lara giving out duplicate reward in residential area.
- NCR
  - Fixed Merk's warning float about the stairs.
- Primitive Tribe
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/267) Sulik's appearance after parting ways with him in his tribe.
- San Francisco
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/252) the submarine quest activating again after killing the dock guard.
  - Fixed Dr. Wong's assassination sequence.
- Vault City
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/pull/260) intermittent crash when entering Vault City.

### Version 28

[Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/237) car disappearing if PC already has it when returning Jonny to his parents in Modoc.

Introduced in v27. To hotfix, download and extract [this](https://github.com/BGforgeNet/Fallout2_Restoration_Project/files/12673833/modmain.int.zip) into `data/scripts`.

### Version 27

- New animations for Cat Jules, from [black dude](https://github.com/rotators/fallout-animations/tree/master/Male_BlackDude) set.
- [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/147) improved mysterious stranger causing lag in a random encounter.
- Increased lighting in some of the darker areas.
- Abbey
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/pull/219) double reward for killing the small deathclaw.
- San Francisco
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/165) stupid characters being unable to return the decomposing body to Dr. Wong.
- Vault City
  - Chief Librarian Kohl will give a [pointer to Abbey](https://github.com/BGforgeNet/Fallout2_Restoration_Project/pull/220).
- Vault Village
  - Changed critter placement so one "strong peasant" does not block the desk (contain minor loot) in the "upgraded" village elevations.

### Version 26

- Hero Appearance updated to version 2.6.
- Party Orders updated to version 1.11.

### Version 25

Fixed [crash in EPA](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/129) when sfall QoL features weren't selected during installation.

### Version 24

Maintenance release: bugfixes from UPU, expanded Polish translation.

### Version 23

Fixed Cassidy missing talking head.

### Version 22

- [Animations](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/107)
  - Extended flamer animations are moved into a separated component, and updated.
  - Green ghoul "magic hands ground" animation is enabled.
  - For some critters, restored original, higher fps walking animations and added an option to speed them up.
- Den
  - [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/100) loading in-combat save in Den Residential area.
- [Cassidy head](https://github.com/BGforgeNet/Fallout2_Cassidy_Head) is now a separate mod (included), and uses Joey Bracken's voice by default.
- Umbra Tribe
  - Fixed [black screen](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/108) upon entering the area in German version.

### Version 21

Updated sfall to 4.3.0.1.

### Version 20

- General
  - XP rewards for Kaga are [more consistent](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/78). Also, Kaga will wield more appropriate weapons at each level (2: hunting rifle instead of 14mm pistol, 3: assault rifle instead of combat shotgun, 4: super cattle prod instead of laser rifle).
  - Linux: fixed AmmoMod installation on case sensitive fs.
- NPC
  - Cat Jules' Melee and Unarmed skills [properly increase](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/66) when he hits level 5.
  - Lenny will [keep his appearance](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/68) when custom options are used in NPC Armor settings.
  - Sulik will no longer [endlessly complain](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/72) about being poisoned after being hit by poison in EPA.
- Abbey
  - PC can get a book from a [shelf in top right corner](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/86) of the 2nd level in Abbey.
- Den
  - Drug dealer in Residential area will no longer get an extra Desert Eagle each time the map is entered.
- EPA
  - EPA bots will have some [weapons](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/73). Also, they can be disabled with Repair, like Sierra ones.
  - [Plants](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/87)
    - Will use their special spikes.
    - PC no longer can (try) to talk to them.
    - Won't keep combat going when they don't see the enemy.
    - Using the spray will award the same XP as killing them normally.
    - Will display dying animation when spray is used on them.
    - All this also applies to plants inside EPA.

### Version 18

Updated [Hero Appearance](https://github.com/BGforgeNet/Fallout2_Hero_Appearance) to v2.1, shipping only canon sets by default.

### Version 17

- Kaga now has [consistent stats and HP](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/57).

### Version 16

- Separated [NPC armor](https://github.com/BGforgeNet/Fallout2_NPC_Armor) mod.
- Added Italian and Hungarian translations.
- Fixed a leftover from YAAM, incorrect stats for BB ammo.

### Version 14

- Fixed auto installer not allowing to select a directory in some cases.
- Fixed `AllowSoundForFloats` placement in `ddraw.ini`
- Enabled more QoL options: `WorldMapTerrainInfo`, `ActionPointsBar`, increased `NumSoundBuffers` to 16.

### Version 13

- Multiple fixes and updates from [UPU](https://github.com/BGforgeNet/Fallout2_Unofficial_Patch).
- Added [high quality music](https://github.com/BGforgeNet/Fallout2-HQ-music).

### Version 12

- Fixed incorrect `WorldMapSlots` placement in `ddraw.ini`.
- Fixed re-stocking Red 888 Guns (introduced in v11).
- Fixed `rpu-install.command` being left out on cleanup.

### Version 11

- [Fixed](https://github.com/BGforgeNet/Fallout2_Restoration_Project/issues/32) custom `ddraw.ini` configuration.
- [Removed](https://github.com/BGforgeNet/Fallout2_Unofficial_Patch/issues/35) old workarounds for 'too many items'.
- Moved more ini files into `mods` directory.

### Version 10

- General
  - Disabled `AIBestWeaponFix` by default, as it's not much of a fix.
  - Fixed Goris de-robing script so that it'll actually enable `UseFileSystemOverride` when necessary.
  - Fixed sound path correction in the installation script.
  - Added a `.command` installation script for Mac OSX users.
- Arroyo
  - Plant/corn from EPA seeds gets placed on the correct elevation now.
- Den
  - The drug dealer and his bodyguard now receive/equip their weapons at the first time the player enters the Den Residential map.
- EPA
  - Planted seed will now properly grow in the green level.
- San Francisco
  - Fixed bug with being unable to disable force field to Shi emperor.
  - Added previously missing UP fixes:
    - AHS-7 will properly turn hostile upon pickpocket.
    - Emperor force field is disabled with Repair, not Science.
    - Blowing up Emperor field emitter will set Shi hostile.
    - Badger will stock Bozar and G11E.
    - Badger will keep re-stocking after 7 years.

### Version 9

- General
  - Allowed all Kaga versions to be knocked down, for consistency.
  - Added [Party Orders](https://github.com/BGforgeNet/Fallout2_Party_Orders) to release package.
  - Added missing "being hit" animation for Sulik in leather armor.
  - Fixed rifle animations preventing NPCs from equiping those rifles.
  - Fixed Kitsune being unable to equip weapons and not showing armor.
- Den
  - Fixed missing orphan floats.
- EPA
  - Fixed Depressed Mr. Handy causing slowdowns.
- Modoc
  - Fixed being unable to resque Jonny if talked to him before starting the quest.
  - Fixed shitty death narration being stuck.

### Version 8

Added missing item highlight and party control mods.

### Version 7

- Enabled some QoL features in sfall: `DontTurnOffSneakIfYouRun`, `NumbersInDialogue`, `WorldMapFontPatch`, `PartyMemberExtraInfo`.
- Removed files identical to their `master.dat` versions.
- Removed duplicate files from animations components.
- Fixed Russian character descriptions being shown when using English language.
- Fixed several worldmap markers being shown in Russian when using English language.

### Version 6

- Added npc armor frms and hopefully the last missing files from 2.3.3 auto installer.
- Fixed npc armor and ammo mod script installation on unixes.

### Version 5

Fixed more packaging artefacts.

### Version 4

Added missing `scripts.lst`.

### Version 3

- Created a complete package.
- Added localizations.
- Converted some options from install time into separate dat packages and/or ini settings.

### Version 2

Repacked into .dat file.

### Version 1

- General
  - Damage formula no longer erroneously defaults to YAAM.
  - Various under the hood changes and optimizations.
- Abbey
  - Computer desk in SW map corner gives a message when used.
  - Both deatchclaws have correct scripts now.
  - Fixed brother Paul not giving access to computers if the beast was killed, but the book wasn't retrieved.
- Broken Hills
  - Allowed to use lockpicks in Chad's quest.
- Den
  - Fixed dealer's bodyguard description.
  - Deleted 0-stack ammo pack from Metzger's desk.
  - Bobby's floats tweaked to reflect he's packing things.
- Enclave
  - Fixed RP NPC suffering no damage in the puzzle room.
  - Fixed vertibird pad area being immune to meltdown countdown and FEV poisoning.
- Klamath
  - Fixed Duntons offering the job on the pastures, then telling the PC off. Also, fixed CoP check in their script.
- Gecko
  - Lenny: moved ammo from hands to inventory.
- Hubologists' stash
  - Added proper messages for using skills and items on the top door.
