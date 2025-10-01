Killap's Fallout 2 Restoration Project - Version 2.3.3 (Installer)

============
Information:
============
The purpose of this project is to add back into Fallout 2 all the missing content (locations, NPCs, quests, items, etc) that were pulled or left unfinished in the original game. This expansion attempts to stay true to what made Fallout great and thus the new content you find is not something I felt that would be cool to see, but rather a reality of what the original devs wanted. I admit that I had to make some judgment calls here and there, but the core of what you will see is something originally thought up by the Fallout 2 devs. I hope you enjoy this expansion and you are able to get even more greatness out of Fallout 2. If you have any questions/comments feel free to e-mail me at "sniper@madd-net.net" You can also find me on the No Mutants Allowed forum found at http://www.nma-fallout.com/forum/ If you cannot reach me by e-mail, I suggest posting there. Thanks and enjoy!


Note: A full list of new content is found at the end of the installation.
Note2: Previous save games before using this expansion will no longer work. You will have to start a new game!
Note3: For non English users, you may need to rename the: 
\BlackIsle\Fallout2\data\Text\English folder to whatever language you are using, such as German, in order to play.
  **This is only needed if your language was not an option in the installer or all the new NPCs are giving "ERROR" dialogues.**


===========================
Frequently Asked Questions:
===========================
Q: Do I need to install the official 1.02 patch or your unofficial patch as well?
A: No. All the fixes found in the official and unofficial patch are already included.

Q: Can I use official 1.02 patch saves or your unofficial patch saves with this mod?
A: No, sadly you cannot. Any save game made before using this mod is not compatible. All future versions, however, are compatible with previous versions of my work unless otherwise noted.

Q: How do I know if this mod is installed correctly?
A: There is a small rock at the beginning of the game. This rock is found just outside the Temple of Trials, behind Klint. Looking at the rock should display some text and give the version of the mod you are running. In addition, you should see a version number in the lower right corner of the main menu to the game. You must see BOTH the rock and a version number on the main menu to be 100% sure the mod is installed correctly.

Q: I have a version of the game that had children removed. Do I need to apply a separate patch to fix this?
A: No. My unofficial patch (which is part of this mod) already includes the missing children frms.

Q: On startup, Fallout 2 crashes with a 'Failure initializing input devices' error.
A: Go to your Fallout 2 directory and look for a file called ddraw.ini. In the [input] section, change BackgroundKeyboard to 1 and see if that fixes the error. If it doesn't, change BackgroundMouse to 1 too.

Q: I'm getting black screens/psychedelic colour schemes
A: Go to your Fallout 2 directory and look for a file called ddraw.ini. In the [Graphics] section, change Mode to 4.

Q: Fallout refuses to run, displaying the message 'Fallout appears to be running in compatibility mode'.
A: Turn compatibility mode settings off. Do this by right clicking fallout2.exe, switching to the compatibility tab and unchecking everything. 

Q: I don't like the speed I am moving on the world map. It's too fast/too slow. How can I change this?
A: Map movement speed was a troubling issue before but has now been effectively addressed. The issue before was a result of the speed of your CPU and thus the faster clock speed you have, the faster you would move across the map. This has been addressed though and the setting used in this mod should be much like the speed that was originally intended with computers of the late 1990s. If you feel things are still too slow or too fast now, this can easily be changed. Go to your Fallout 2 directory and look for a file called ddraw.ini. Search for something called "WorldMapDelay2=" If you did not alter this already, it should say "WorldMapDelay2=66" Changing it to a higher value will make things go slower and changing it to a lower value will speed things up. If the map is still stuttering for you even after lowering the value, make sure WorldMapFPSPatch, WorldMapFPS and WorldMapDelay are all set to 0.

Q: How do I change the resolution of the game?
A: Thanks to Mash's resolution patch you can finally play Fallout 2 at resolutions higher than 640x480. To change the resolution, you must be at the main menu of the game. Go to 'Options' and then click 'Screen Settings'. Once you've configured it the way you want, click 'Done' to save your changes. As of 4.0.2 of Mash's patch, you can also change the resolution outside the game by running 'f2_res_Config.exe', found inside your main Fallout 2 directory.

Q: My CPU seems to be at 100% usage when playing this game. What gives!?
A: Go to your Fallout 2 directory and look for a file called ddraw.ini. In the [Misc] section, look for a setting called ProcessorIdle. Change this to 1. If the game is still running at very high usage, then go back to the ddraw.ini file and set ProcessorIdle back to -1. Now, open up f2_res.ini and look for CPU_USAGE_FIX and set it to 1. Do NOT have both the ddraw.ini and f2_res.ini settings set to 1 at the same time. Hopefully one of those will make your computer happy again.

Q: I'm using the new appearance mod and my character is spinning too quickly/slowly on the inventory and character screens. Can I modify the rotation speed?
A: Sure. Go to your Fallout 2 directory and look for a file called ddraw.ini. Search for something called "SpeedInventoryPCRotation=" The default value is 220. Larger values make it slower, smaller values make it faster.

Q: I don't like some of the options I chose in the installer. Can I go back and change them?
A: Many of the options you picked in the installer can be changed at any time. Go to your Fallout 2 directory and look for a file called ddraw.ini. Look through it for any options you wish to modify. "EnableHeroAppearanceMod=", "DamageFormula=" and "PartyMemberNonRandomLevelUp=" are some of the options you could have set via the RP installer. The file is well documented, so it is pretty easy to tell what each option will do to your game. However, I suggest only making changes to this file if you really know what you're doing or were told to make a specific change.

Q: I'm stuck on this one quest. Help me!
A: Morticia and others have compiled a detailed walkthrough for my work. You can access it here: https://f2rp.bgforge.net/


=================
Acknowledgements:
=================
• Without the use of Per's Fallout 2 walkthrough, I would not have been able to pinpoint the majority of the bugs fixed in my patch. Thanks!
• Several fixes from my patch are taken from the work done by Seraph in his patch and I am truly grateful for the work he's done. Thanks!
• I used the updated Official Mapper scripts (1.02D) by Haenlomal as the base to my patch. Much thanks for his work on this!
• This mod utilizes Timeslip's Fallout 2 engine tweaks. Without this, several bugs that exist in the game would continue to remain unfixable. Thanks as well to Haenlomal for his contributions here!
• Thanks to Mash for his amazing high resolution patch!
• This mod includes graphics made by Pixote, Continuum, Crowley, the makers of Fallout: Between Good & Evil, Nikki, Wild_qwerty, the makers of Mutants Rising, Grayswandir, and x'il.
• This mod includes work done by Skynet, Corpse, Chris Parks, TeamX, ART, Glovz, Lich, Lisac2k, deadlus, and pelicano.
• This mod includes dialogue written by Adam Dravean, Bofast, Minigun Jim, encinodude, Yamu, and Mikael Grizzly.
• Thanks to MIB88 for input on ideas, coding, content, etc!
• Thanks to Ivan Zaharath and others for the Polish translation!
• Thanks to HawK-EyE and others for the French translation!
• Thanks to Mr. Wolna and others for the German translation!
• Big thanks to Josan12 and Jotisz for their work on the NPC Armor mod and misc animations!
• Thanks to hologram for composing music for the Primitive Tribe!
• Thanks to Aguirre, Agris, Josan12, tobecooper and Ardent for their work with lip synching Cassidy's new talking head.
• Thanks to Morticia for writing and compiling a walkthrough for my work!
• Thanks to tomten, Slowhand, GanymeDes, Nevill, Darek, Ochrei, Morticia, Petrell, and others for maintaining the F2RP Technical Info wiki page!
• Thanks to gracul for finding out the cause of the EPA elevator crash!
• Thanks to Darek for finding out the cause of the Primitive Tribe crash under windows 9x, narrowing down the items involved in the infamous "too many items" bug, the shopkeeper restocking problem, and so much more!
• Thanks to NovaRain for being an outstanding beta tester!
• And lastly, thanks to all the friendly people over at No Mutants Allowed with all the help they have provided. Thanks!

