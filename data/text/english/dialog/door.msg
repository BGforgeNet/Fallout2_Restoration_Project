#############################################################
#  Message File: Door.msg                                   #
#                                                           #
#  Note: Characters within curly braces (like line 100)     #
#        will be read in as a message string. Caution       #
#        should be used when making comments. All comments  #
#        should be prepended with a pound symbol for        #
#        visual ease. This does not comment out the line    #
#        though.                                            #
#                                                           #
#  Purpose: This message file contains the information      #
#           concerning doors in a locked state, trapped     #
#           state, locked and trapped state.                #
#                                                           #
#  Log: Please note any changes that have been made to this #
#       file and comment which lines have changed.          #
#       April 19,1998 nbk: added message line to be used    #
#                          for doors opened with keys.      #
#                                                           #
#  Created: September 26, 1997                              #
#                                                           #
#  Updated:                                                 #
#############################################################

#############################################################
#  The following lines are for description of the door. The #
#  first lines, line 100-1, are for the look_at_proc. The   #
#  remainder until the next block are for description_proc  #
#  based one skill and perception success.                  #
#############################################################

# look_at_proc
{100}{}{You see a wooden door.}
{101}{}{You see a metal door.}

# description_proc

# Perception Check Critical Success
{102}{}{You see a sturdy door with a lock (which can be picked with
 lockpicks) and a highly explosive trap in the doorframe, which
 you may be able to pry open.}
{103}{}{You see a sturdy door with a lock on it and a highly
 explosive trap in the doorframe, which you may be able to
 pry open.}
{104}{}{You see a sturdy door with no apparent locking device and
 a highly explosive trap in the doorframe, which you may be able
 to pry open.}
{105}{}{You see a sturdy door with an old, rusty lock and a highly
 explosive trap in the doorframe, which you may be able to pry
 open.}

{106}{}{You see a sturdy door with a lock (which can be picked with
 lockpicks) and a trap in the doorframe, which you may be able to
 pry open.}
{107}{}{You see a sturdy door with a lock on it and a trap in
 the doorframe, which you may be able to pry open.}
{108}{}{You see a sturdy door with no apparent locking device and
 a trap in the doorframe, which you may be able to pry open.}
{109}{}{You see a sturdy door with an old, rusty lock and a trap
 in the doorframe, which you may be able to pry open.}

{110}{}{You see a sturdy door with a lock (which can be picked with
 lockpicks) and a cut wire in the doorframe, which you may be
 able to pry open.}
{111}{}{You see a sturdy door with a lock on it and a severed wire
 in the doorframe, which you may be able to pry open.}
{112}{}{You see a sturdy door with no apparent locking device and
 a severed wire in the doorframe, which you may be able to pry
 open.}
{113}{}{You see a sturdy door with an old, rusty lock and a cut
 wire in the doorframe, which you may be able to pry open.}

{114}{}{You see a sturdy door with a lock (which can be picked with
 lockpicks), which you may be able to pry open.}
{115}{}{You see a sturdy door with a lock on it, which you may be
 able to pry open.}
{116}{}{You see a sturdy door with no apparent locking device,
 which you may be able to pry open.}
{117}{}{You see a sturdy door with an old, rusty lock, which
 you may be able to pry open.}

# Perception Check Success

{118}{}{You see a sturdy door with a lock (which can be picked with
 lockpicks) and a highly explosive trap in the doorframe.}
{119}{}{You see a sturdy door with a lock on it and a highly
 explosive trap in the doorframe.}
{120}{}{You see a sturdy door with no apparent locking device and
 a highly explosive trap in the doorframe.}
{121}{}{You see a sturdy door with an old, rusty lock and a highly
 explosive trap in the doorframe.}

{122}{}{You see a sturdy door with a lock (which can be picked with
 lockpicks) and a trap in the doorframe.}
{123}{}{You see a sturdy door with a lock on it and a trap in
 the doorframe.}
{124}{}{You see a sturdy door with no apparent locking device and
 a trap in the doorframe.}
{125}{}{You see a sturdy door with an old, rusty lock and a trap
 in the doorframe.}

{126}{}{You see a sturdy door with a lock (which can be picked with
 lockpicks) and a cut wire in the doorframe.}
{127}{}{You see a sturdy door with a lock on it and a severed wire
 in the doorframe.}
{128}{}{You see a sturdy door with no apparent locking device and
 a severed wire in the doorframe.}
{129}{}{You see a sturdy door with an old, rusty lock and a cut
 wire in the doorframe.}

{130}{}{You see a sturdy door with a lock (which can be picked with
 lockpicks) on it.}
{131}{}{You see a sturdy door with a lock on it.}
{132}{}{You see a sturdy door with no apparent locking device.}
{133}{}{You see a sturdy door with an old, rusty lock.}

# Perception Check Critical Failure

{134}{}{You see a damaged door with a lock (which can be picked with
 lockpicks) and a highly explosive trap in the doorframe.}
{135}{}{You see a damaged door with a lock on it and a highly
 explosive trap in the doorframe.}
{136}{}{You see a damaged door with no apparent locking device and
 a highly explosive trap in the doorframe.}
{137}{}{You see a damaged door with an old, rusty lock and a highly
 explosive trap in the doorframe.}

{138}{}{You see a damaged door with a lock (which can be picked with
 lockpicks) and a trap in the doorframe.}
{139}{}{You see a damaged door with a lock on it and a trap in
 the doorframe.}
{140}{}{You see a damaged door with no apparent locking device and
 a trap in the doorframe.}
{141}{}{You see a damaged door with an old, rusty lock and a trap
 in the doorframe.}

{142}{}{You see a damaged door with a lock (which can be picked with
 lockpicks) and a cut wire in the doorframe.}
{143}{}{You see a damaged door with a lock on it and a severed wire
 in the doorframe.}
{144}{}{You see a damaged door with no apparent locking device and
 a severed wire in the doorframe.}
{145}{}{You see a damaged door with an old, rusty lock and a cut
 wire in the doorframe.}

{146}{}{You see a damaged door with a lock (which can be picked with
 lockpicks).}
{147}{}{You see a damaged door with a lock on it.}
{148}{}{You see a damaged door with no apparent locking device.}
{149}{}{You see a damaged door with an old, rusty lock.}

# Perception Check Failure

{150}{}{You see an old door with a lock (which can be picked with
 lockpicks) and a highly explosive trap in the doorframe.}
{151}{}{You see an old door with a lock on it and a highly
 explosive trap in the doorframe.}
{152}{}{You see an old door with no apparent locking device and
 a highly explosive trap in the doorframe.}
{153}{}{You see an old door with an old, rusty lock and a highly
 explosive trap in the doorframe.}

{154}{}{You see an old door with a lock (which can be picked with
 lockpicks) and a trap in the doorframe.}
{155}{}{You see an old door with a lock on it and a trap in
 the doorframe.}
{156}{}{You see an old door with no apparent locking device and
 a trap in the doorframe.}
{157}{}{You see an old door with an old, rusty lock and a trap
 in the doorframe.}

{158}{}{You see an old door with a lock (which can be picked with
 lockpicks) and a cut wire in the doorframe.}
{159}{}{You see an old door with a lock on it and a severed wire
 in the doorframe.}
{160}{}{You see an old door with no apparent locking device and
 a severed wire in the doorframe.}
{161}{}{You see an old door with an old, rusty lock and a cut
 wire in the doorframe.}

{162}{}{You see an old door with a lock (which can be picked with
 lockpicks).}
{163}{}{You see an old door with a lock on it.}
{164}{}{You see an old door with no apparent locking device.}
{165}{}{You see an old door with an old, rusty lock.}

#############################################################
#  The following lines are for damage done to the player or #
#  critter who tried to open the door, or failed a traps    #
#  roll.                                                    #
#############################################################

# The following sets of lines are to be translated as:
# You set off the trap and were hit for [x] points of damage.
# NPC sets of the trap and was hit for [x] points of damage.

# Player sets off the trap
{166}{}{You set off the trap and were hit for }
{167}{}{ points of damage.}

# NPC sets off the trap
{168}{}{ sets off the trap and was hit for }
{169}{}{ points of damage.}

#############################################################
#  The following lines are for when the player uses skills  #
#  on the door.                                             #
#############################################################

# Player uses a skill on the door
# Unlock Door
{170}{}{You deftly pick the lock on the door.}
{171}{}{Your lack of skill has jammed the lock on this door.}
{172}{}{You fail to pick the lock on this door.}

# Lock Door
{189}{}{You deftly lock the door.}
{190}{}{You fail to lock the door.}

# Find Trap on the Door
{194}{}{You find a trap on the door.}
{195}{}{You fail to find any traps on the door.}

# Disarm the Trap on the Door
{196}{}{You skillfully disarm the trap.}
{198}{}{You fail to disarm the trap.}

# NPC uses a skill on the door
# The following lines are prepended by the NPC's name

# Unlock Door
{173}{}{ deftly picks the lock on the door.}
{174}{}{'s lack of skill has jammed the lock on this door.}
{175}{}{ failed to pick the lock on this door.}

# Lock Door
{191}{}{ deftly locks the door.}
{192}{}{ failed to lock the door.}

# Find Trap on the Door
{199}{}{ finds a trap on the door.}
{200}{}{ fails to find any traps on the door.}

# Disarm the Trap on the Door
{201}{}{ skillfully disarms the trap.}
{202}{}{ fails to disarm the trap.}

#############################################################
#  The following lines are for when the player tries to     #
#  use items on the door which are not lockpicks.           #
#############################################################

# Player uses an item on the door
{176}{}{You bust the lock off the door.}
{177}{}{You strain your back while trying to bust the lock off and take a point of damage.}

# The following set of lines is to be translated as:
# You strain your back while trying to bust the lock off and
# take [x] points of damage.

{178}{}{You strain your back while trying to bust the lock off and take }
{179}{}{ points of damage.}
{180}{}{You are too weak to bust the lock off.}

# NPC uses an item on the door
# The following lines are prepended by the NPC's name
{181}{}{ busts the lock off the door.}
{182}{}{ strains his back while trying to bust the lock off and takes a point of damage.}

# The following line set of lines is to be translated as:
# NPC strains his back while trying to bust the lock off and
# takes [x] points of damage

{183}{}{ strains his back while trying to bust the lock off and takes }
{184}{}{ points of damage.}

{185}{}{ is too weak to bust the lock.}
{186}{}{ strains her back while trying to bust the lock off and takes a point of damage.}

# The following line set of lines is to be translated as:
# NPC strains her back while trying to bust the lock off and
# takes [x] points of damage

{187}{}{ strains her back while trying to bust the lock off and takes }
{188}{}{ points of damage.}

{601}{}{It is open, dummy.}

# Crowbar bent
{620}{}{You bend the crowbar beyond recognition. It's useless now.}
{621}{}{ bends the crowbar beyond recognition. It's useless now.}

#############################################################
#  Damage done to the door due to explosives.               #
#############################################################

{193}{}{That doesn't even put a scratch on the door.}

#############################################################
#  Reporting Door Status should it be used.                 #
#############################################################

{203}{}{The door appears to be locked.}
{204}{}{You notice a trap in the door jamb.}

# NPC finds trap
# The following line is to be translated as:
# NPC notices a trap in the door jamb.

{205}{}{ notices a trap in the door jamb.}

#############################################################
#  Setting traps on a door and whether the door is open or  #
#  closed to set the trap.                                  #
#############################################################

# Player tries to set a trap on an open door
{206}{}{You are unable to place a trap on this door, because
 the door is open.}

# NPC tries to set a trap on an open door
{207}{}{ is unable to place a trap on this door, because the
 door is open.}

# Player tries to set a trap on a closed door
{208}{}{You skillfully set a trap in the door frame.}
{209}{}{You fail to properly set the trap in the door frame.}

# NPC tries to set a trap on a closed door
{210}{}{ skillfully sets a trap in the door frame.}
{211}{}{ fails to properly set the trap in the door frame.}

# PC critically fails to set a trap
{610}{}{You fail spectacularly, and the explosive goes off prematurely.}
# NPC critically fails to set a trap
{611}{}{ fails spectacularly, and the explosive goes off prematurely.}

{300}{}{You unlock the door.}
{301}{}{You lock the door.}
{302}{}{You are unable to lock this door while it is open.}
{303}{}{That key does not fit in this lock.}

# for broken doors
{320}{}{There's no way to lock this door.}
{330}{}{This door is jammed open.}

# Using a key on the door. (YES THIS IS A DUPLICATE BUT PLEASE DO NOT REMOVE..
# IT MOST LIKELY IS BEING USED BY A DOOR SCRIPT SOMEWHERE)
{400}{}{You unlock the door.}

{414}{}{You see a sturdy door with a lock (which can be picked with
 lockpicks), which you may be able to pry open.}
{415}{}{You see a sturdy door with a lock on it, which you may be
 able to pry open.}
{416}{}{You see a sturdy door with no apparent locking device,
 which you may be able to pry open.}
{417}{}{You see a sturdy door which you may be able to pry open.}

{500}{}{This door is too heavy to pry open.}
{501}{}{Looks like you need to get the generator working first.}
{502}{}{You see: Elevator door.}
{503}{}{Looks like you need an electric device to open this lock.}
