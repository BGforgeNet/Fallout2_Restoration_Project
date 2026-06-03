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
{100}{}{You see a wooden crate.}
{101}{}{You see a metal locker.}
{212}{}{You see a refrigerator.}

# description_proc

# Perception Check Critical Success
{102}{}{You see a sturdy container with a lock (which can be picked with
 lockpicks) and a highly explosive trap in the frame, which
 you may be able to pry open.}
{103}{}{You see a sturdy container with a lock on it and a highly
 explosive trap in the frame, which you may be able to
 pry open.}
{104}{}{You see a sturdy container with no apparent locking device and
 a highly explosive trap in the frame, which you may be able
 to pry open.}
{105}{}{You see a sturdy container with an old, rusty lock and a highly
 explosive trap in the frame, which you may be able to pry
 open.}

{106}{}{You see a sturdy container with a lock (which can be picked with
 lockpicks) and a trap in the frame, which you may be able to
 pry open.}
{107}{}{You see a sturdy container with a lock on it and a trap in
 the frame, which you may be able to pry open.}
{108}{}{You see a sturdy container with no apparent locking device and
 a trap in the frame, which you may be able to pry open.}
{109}{}{You see a sturdy container with an old, rusty lock and a trap
 in the frame, which you may be able to pry open.}

{110}{}{You see a sturdy container with a lock (which can be picked with
 lockpicks) and a cut wire in the frame, which you may be
 able to pry open.}
{111}{}{You see a sturdy container with a lock on it and a severed wire
 in the frame, which you may be able to pry open.}
{112}{}{You see a sturdy container with no apparent locking device and
 a severed wire in the frame, which you may be able to pry
 open.}
{113}{}{You see a sturdy container with an old, rusty lock and a cut
 wire in the frame, which you may be able to pry open.}

{114}{}{You see a sturdy container with a lock (which can be picked with
 lockpicks), which you may be able to pry open.}
{115}{}{You see a sturdy container with a lock on it, which you may be
 able to pry open.}
{116}{}{You see a sturdy container with no apparent locking device,
 which you may be able to pry open.}
{117}{}{You see a sturdy container with an old, rusty lock, which
 you may be able to pry open.}

# Perception Check Success

{118}{}{You see a sturdy container with a lock (which can be picked with
 lockpicks) and a highly explosive trap in the frame.}
{119}{}{You see a sturdy container with a lock on it and a highly
 explosive trap in the frame.}
{120}{}{You see a sturdy container with no apparent locking device and
 a highly explosive trap in the frame.}
{121}{}{You see a sturdy container with an old, rusty lock and a highly
 explosive trap in the frame.}

{122}{}{You see a sturdy container with a lock (which can be picked with
 lockpicks) and a trap in the frame.}
{123}{}{You see a sturdy container with a lock on it and a trap in
 the frame.}
{124}{}{You see a sturdy container with no apparent locking device and
 a trap in the frame.}
{125}{}{You see a sturdy container with an old, rusty lock and a trap
 in the frame.}

{126}{}{You see a sturdy container with a lock (which can be picked with
 lockpicks) and a cut wire in the frame.}
{127}{}{You see a sturdy container with a lock on it and a severed wire
 in the frame.}
{128}{}{You see a sturdy container with no apparent locking device and
 a severed wire in the frame.}
{129}{}{You see a sturdy container with an old, rusty lock and a cut
 wire in the frame.}

{130}{}{You see a sturdy container with a lock (which can be picked with
 lockpicks) on it.}
{131}{}{You see a sturdy container with a lock on it.}
{132}{}{You see a sturdy container with no apparent locking device.}
{133}{}{You see a sturdy container with an old, rusty lock.}

# Perception Check Critical Failure

{134}{}{You see a damaged container with a lock (which can be picked with
 lockpicks) and a highly explosive trap in the frame.}
{135}{}{You see a damaged container with a lock on it and a highly
 explosive trap in the frame.}
{136}{}{You see a damaged container with no apparent locking device and
 a highly explosive trap in the frame.}
{137}{}{You see a damaged container with an old, rusty lock and a highly
 explosive trap in the frame.}

{138}{}{You see a damaged container with a lock (which can be picked with
 lockpicks) and a trap in the frame.}
{139}{}{You see a damaged container with a lock on it and a trap in
 the frame.}
{140}{}{You see a damaged container with no apparent locking device and
 a trap in the frame.}
{141}{}{You see a damaged container with an old, rusty lock and a trap
 in the frame.}

{142}{}{You see a damaged container with a lock (which can be picked with
 lockpicks) and a cut wire in the frame.}
{143}{}{You see a damaged container with a lock on it and a severed wire
 in the frame.}
{144}{}{You see a damaged container with no apparent locking device and
 a severed wire in the frame.}
{145}{}{You see a damaged container with an old, rusty lock and a cut
 wire in the frame.}

{146}{}{You see a damaged container with a lock (which can be picked with
 lockpicks).}
{147}{}{You see a damaged container with a lock on it.}
{148}{}{You see a damaged container with no apparent locking device.}
{149}{}{You see a damaged container with an old, rusty lock.}

# Perception Check Failure

{150}{}{You see an old container with a lock (which can be picked with
 lockpicks) and a highly explosive trap in the frame.}
{151}{}{You see an old container with a lock on it and a highly
 explosive trap in the frame.}
{152}{}{You see an old container with no apparent locking device and
 a highly explosive trap in the frame.}
{153}{}{You see an old container with an old, rusty lock and a highly
 explosive trap in the frame.}

{154}{}{You see an old container with a lock (which can be picked with
 lockpicks) and a trap in the frame.}
{155}{}{You see an old container with a lock on it and a trap in
 the frame.}
{156}{}{You see an old container with no apparent locking device and
 a trap in the frame.}
{157}{}{You see an old container with an old, rusty lock and a trap
 in the frame.}

{158}{}{You see an old container with a lock (which can be picked with
 lockpicks) and a cut wire in the frame.}
{159}{}{You see an old container with a lock on it and a severed wire
 in the frame.}
{160}{}{You see an old container with no apparent locking device and
 a severed wire in the frame.}
{161}{}{You see an old container with an old, rusty lock and a cut
 wire in the frame.}

{162}{}{You see an old container with a lock (which can be picked with
 lockpicks).}
{163}{}{You see an old container with a lock on it.}
{164}{}{You see an old container with no apparent locking device.}
{165}{}{You see an old container with an old, rusty lock.}

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
{170}{}{You deftly pick the lock on the container.}
{171}{}{Your lack of skill has jammed the lock on this container.}
{172}{}{You fail to pick the lock on this container.}

# Lock Door
{189}{}{You deftly lock the container.}
{190}{}{You fail to lock the container.}

# Find Trap on the Door
{194}{}{You find a trap on the container.}
{195}{}{You fail to find any traps on the container.}

# Disarm the Trap on the Door
{196}{}{You skillfully disarm the trap.}
{198}{}{You fail to disarm the trap.}

# NPC uses a skill on the door
# The following lines are prepended by the NPC's name

# Unlock Door
{173}{}{ deftly picks the lock on the container.}
{174}{}{'s lack of skill has jammed the lock on this container.}
{175}{}{ failed to pick the lock on this container.}

# Lock Door
{191}{}{ deftly locks the container.}
{192}{}{ failed to lock the container.}

# Find Trap on the Door
{199}{}{ finds a trap on the container.}
{200}{}{ fails to find any traps on the container.}

# Disarm the Trap on the Door
{201}{}{ skillfully disarms the trap.}
{202}{}{ fails to disarm the trap.}

# Using a key on the door.
{400}{}{You unlock the container.}

#############################################################
#  The following lines are for when the player tries to     #
#  use items on the door which are not lockpicks.           #
#############################################################

# Player uses an item on the door
{176}{}{You bust the lock off the container.}
{177}{}{You strain your back while trying to bust the lock off and take a point of damage.}

# The following set of lines is to be translated as:
# You strain your back while trying to bust the lock off and
# take [x] points of damage.

{178}{}{You strain your back while trying to bust the lock off and
 take }
{179}{}{ points of damage.}
{180}{}{You are too weak to bust the lock off.}

# NPC uses an item on the door
# The following lines are prepended by the NPC's name
{181}{}{ busts the lock off the container.}
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

{193}{}{The explosives don't even put a scratch on the container.}

#############################################################
#  Reporting Door Status should it be used.                 #
#############################################################

{203}{}{The container appears to be locked.}
{204}{}{You notice a trap on the container.}

# NPC finds trap
# The following line is to be translated as:
# NPC notices a trap in the door jamb.

{205}{}{ notices a trap on the container jamb.}

#############################################################
#  Setting traps on a door and whether the door is open or  #
#  closed to set the trap.                                  #
#############################################################

# Player tries to set a trap on an open door
{206}{}{You are unable to place a trap on this container, because
 the container is open.}

# NPC tries to set a trap on an open door
{207}{}{ is unable to place a trap on this container, because the
 container is open.}

# Player tries to set a trap on a closed door
{208}{}{You skillfully set a trap in the container.}
{209}{}{You fail to properly set the trap in the container.}

# NPC tries to set a trap on a closed door
{210}{}{ skillfully sets a trap on the container.}
{211}{}{ fails to properly set the trap in the container.}

# PC critically fails to set a trap
{610}{}{You fail spectacularly, and the explosive goes off prematurely.}
# NPC critically fails to set a trap
{611}{}{ fails spectacularly, and the explosive goes off prematurely.}
