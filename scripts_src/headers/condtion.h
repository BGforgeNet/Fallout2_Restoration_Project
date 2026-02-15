/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef CONDTION_H
#define CONDTION_H

/**********************************************************
   Filename: Condtion.h

   Purpose: This file is used to map the conditionals used
            within the scripting tool which the designers
            will be using.

   Structure of File
        I.      Variables
        II.     Standard Conditionals
        III.    Forked End Conditionals
        IV.     Giving Items
            A.  Armor
            B.  Weapons
            C.  Ammo
            D.  Medical
            E.  Containers
            F.  Books
            G.  Tools
            H.  Misc.

   Created: Novermber 10, 1997

   Updated:
        November 13, 1997   - rwh2
            Added In giving Inventory Items
**********************************************************/

/************************************************************************
**********************      Variables       *****************************
************************************************************************/

#define ROLL_CRITICAL_FAILURE           0
#define ROLL_FAILURE                    1
#define ROLL_SUCCESS                    2
#define ROLL_CRITICAL_SUCCESS           3

variable ProtoOfItemGiven;
variable ValueOfRollCheck:=ROLL_FAILURE;

/************************************************************************
*******************   Standard Conditionals    **************************
************************************************************************/

#ifndef day
#define day                     ((game_time_hour >= 700) and (game_time_hour < 1800))
#endif
#ifndef night
#define night                   ((game_time_hour < 600) or (game_time_hour >= 1900))
#endif
#define dude_low_iq             (get_critter_stat(dude_obj,STAT_iq) < 4)

/* Truth */
#define COND000(x)              if TRUE then

/* Gender */
#define COND001(x)              if (get_critter_stat(dude_obj,STAT_gender) == GENDER_MALE) then
#define COND002(x)              if (get_critter_stat(dude_obj,STAT_gender) == GENDER_FEMALE) then

/* Time of Day */
#define COND003(x)              if day then
#define COND004(x)              if night then

/* Reaction */
#define COND005(x)              if (local_var(LVAR_reaction_level) == BAD) then
#define COND006(x)              if (local_var(LVAR_reaction_level) == NEUTRAL) then
#define COND007(x)              if (local_var(LVAR_reaction_level) == GOOD) then
#define COND008(x)              if (critter_is_fleeing) then
#define COND009(x)              if (local_var(LVAR_personal_enemy) == 1) then

/* Karma */
#define COND010(x)              if (has_rep_berserker) then
#define COND011(x)              if (not(has_rep_berserker)) then
#define COND012(x)              if (has_rep_champion) then
#define COND013(x)              if (not(has_rep_champion)) then
#define COND014(x)              if (has_rep_childkiller) then
#define COND015(x)              if (not(has_rep_childkiller)) then

#define COND016(x)              if (check_general_rep >= x) then
#define COND017(x)              if (check_general_rep <= x) then


/* Weapon And Armor */
#define COND018(x)              if (dude_is_armed) then
#define COND020(x)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_PURPLE_ROBE) then
#define COND021(x)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_JACKET) then
#define COND022(x)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_ARMOR) then
#define COND023(x)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_METAL_ARMOR) then
//#define COND023(x)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_COMBAT_ARMOR) then
#define COND025(x)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_BROTHERHOOD_COMBAT_ARMOR) then
#define COND026(x)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_POWERED_ARMOR) then
#define COND027(x)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_HARDENED_POWER_ARMOR) then
#define COND028(x)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_TESLA_ARMOR) then

/* Skills */
#define COND029(x)              if (is_success(roll_vs_skill(dude_obj,SKILL_SPEECH,x))) then
#define COND030(x)              if (has_skill(dude_obj,SKILL_SPEECH) >= x) then
#define COND031(x)              if (has_skill(dude_obj,SKILL_SPEECH) <= x) then

#define COND032(x)              if (is_success(roll_vs_skill(dude_obj,SKILL_BARTER,x))) then
#define COND033(x)              if (has_skill(dude_obj,SKILL_BARTER) >= x) then
#define COND034(x)              if (has_skill(dude_obj,SKILL_BARTER) <= x) then

#define COND035(x)              if (is_success(roll_vs_skill(dude_obj,SKILL_SCIENCE,x))) then
#define COND036(x)              if (has_skill(dude_obj,SKILL_SCIENCE) >= x) then
#define COND037(x)              if (has_skill(dude_obj,SKILL_SCIENCE) <= x) then

#define COND038(x)              if (is_success(roll_vs_skill(dude_obj,SKILL_OUTDOORSMAN,x))) then
#define COND039(x)              if (has_skill(dude_obj,SKILL_OUTDOORSMAN) >= x) then
#define COND040(x)              if (has_skill(dude_obj,SKILL_OUTDOORSMAN) <= x) then

#define COND041(x)              if (is_success(roll_vs_skill(dude_obj,SKILL_REPAIR,x))) then
#define COND042(x)              if (has_skill(dude_obj,SKILL_REPAIR) >= x) then
#define COND043(x)              if (has_skill(dude_obj,SKILL_REPAIR) <= x) then

#define COND044(x)              if (is_success(roll_vs_skill(dude_obj,SKILL_DOCTOR,x))) then
#define COND045(x)              if (has_skill(dude_obj,SKILL_DOCTOR) >= x) then
#define COND046(x)              if (has_skill(dude_obj,SKILL_DOCTOR) <= x) then

#define COND047(x)              if (is_success(roll_vs_skill(dude_obj,SKILL_FIRST_AID,x))) then
#define COND048(x)              if (has_skill(dude_obj,SKILL_FIRST_AID) >= x) then
#define COND049(x)              if (has_skill(dude_obj,SKILL_FIRST_AID) <= x) then

/* Stats */
#define COND050(x)              if (is_success(do_check(dude_obj,STAT_st,x))) then
#define COND051(x)              if (get_critter_stat(dude_obj,STAT_st) >= x) then
#define COND052(x)              if (get_critter_stat(dude_obj,STAT_st) <= x) then

#define COND053(x)              if (is_success(do_check(dude_obj,STAT_pe,x))) then
#define COND054(x)              if (get_critter_stat(dude_obj,STAT_pe) >= x) then
#define COND055(x)              if (get_critter_stat(dude_obj,STAT_pe) <= x) then

#define COND056(x)              if (is_success(do_check(dude_obj,STAT_en,x))) then
#define COND057(x)              if (get_critter_stat(dude_obj,STAT_en) >= x) then
#define COND058(x)              if (get_critter_stat(dude_obj,STAT_en) <= x) then

#define COND059(x)              if (is_success(do_check(dude_obj,STAT_ch,x))) then
#define COND060(x)              if (get_critter_stat(dude_obj,STAT_ch) >= x) then
#define COND061(x)              if (get_critter_stat(dude_obj,STAT_ch) <= x) then

#define COND062(x)              if (is_success(do_check(dude_obj,STAT_ag,x))) then
#define COND063(x)              if (get_critter_stat(dude_obj,STAT_ag) >= x) then
#define COND064(x)              if (get_critter_stat(dude_obj,STAT_ag) <= x) then

#define COND065(x)              if (is_success(do_check(dude_obj,STAT_lu,x))) then
#define COND066(x)              if (get_critter_stat(dude_obj,STAT_lu) >= x) then
#define COND067(x)              if (get_critter_stat(dude_obj,STAT_lu) <= x) then

/* Health */
#define COND068(x)              if (get_poison(dude_obj) > 0) then
#define COND069(x)              if (get_critter_stat(dude_obj,STAT_current_rad) > 0) then
#define COND070(x)              if (get_critter_stat(dude_obj,STAT_current_hp) >= ((x * get_critter_stat(dude_obj,STAT_max_hp))/100)) then
#define COND071(x)              if (get_critter_stat(dude_obj,STAT_current_hp) <= ((x * get_critter_stat(dude_obj,STAT_max_hp))/100)) then

/* Money */
#define COND072(x)              if (item_caps_total(dude_obj) >= x) then
#define COND073(x)              if (item_caps_total(dude_obj) <= x) then

/* Age */
#define COND074(x)              if (get_critter_stat(dude_obj,STAT_age) >= x) then
#define COND075(x)              if (get_critter_stat(dude_obj,STAT_age) <= x) then

/* Times Talked */
#define COND076(x)              if (local_var(LVAR_Herebefore) == x) then

/* Party */
#define COND077(x)              if (party_member_count(DONT_LIST_HIDDEN_MEMBERS) >= x) then


/************************************************************************
*******************     Fork Conditionals      **************************
************************************************************************/

/* Truth */
#define FORK000(x,Node1,Node2)              if TRUE then                    \
                                                call Node1;                 \
                                            else                            \
                                                call Node2

/* Gender */
#define FORK001(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_gender) == GENDER_MALE) then     \
                                                call Node1;                                                     \
                                            else                                                                \
                                                call Node2

#define FORK002(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_gender) == GENDER_FEMALE) then   \
                                                call Node1;                                                     \
                                            else                                                                \
                                                call Node2

/* Time of Day */
#define FORK003(x,Node1,Node2)              if day then                     \
                                                call Node1;                 \
                                            else                            \
                                                call Node2

#define FORK004(x,Node1,Node2)              if night then                   \
                                                call Node1;                 \
                                            else                            \
                                                call Node2

/* Reaction */
#define FORK005(x,Node1,Node2)              if (local_var(LVAR_reaction_level) == BAD) then         \
                                                call Node1;                                         \
                                            else                                                    \
                                                call Node2

#define FORK006(x,Node1,Node2)              if (local_var(LVAR_reaction_level) == NEUTRAL) then     \
                                                call Node1;                                         \
                                            else                                                    \
                                                call Node2

#define FORK007(x,Node1,Node2)              if (local_var(LVAR_reaction_level) == GOOD) then        \
                                                call Node1;                                         \
                                            else                                                    \
                                                call Node2

#define FORK008(x,Node1,Node2)              if (critter_is_fleeing) then                \
                                                call Node1;                             \
                                            else                                        \
                                                call Node2

#define FORK009(x,Node1,Node2)              if (local_var(LVAR_personal_enemy) == 1) then   \
                                                call Node1;                                 \
                                            else                                            \
                                                call Node2

/* Karma */
#define FORK010(x,Node1,Node2)              if (has_rep_berserker) then                 \
                                                call Node1;                             \
                                            else                                        \
                                                call Node2

#define FORK011(x,Node1,Node2)              if (not(has_rep_berserker)) then            \
                                                call Node1;                             \
                                            else                                        \
                                                call Node2

#define FORK012(x,Node1,Node2)              if (has_rep_champion) then                  \
                                                call Node1;                             \
                                            else                                        \
                                                call Node2

#define FORK013(x,Node1,Node2)              if (not(has_rep_champion)) then             \
                                                call Node1;                             \
                                            else                                        \
                                                call Node2

#define FORK014(x,Node1,Node2)              if (has_rep_childkiller) then               \
                                                call Node1;                             \
                                            else                                        \
                                                call Node2

#define FORK015(x,Node1,Node2)              if (not(has_rep_childkiller)) then          \
                                                call Node1;                             \
                                            else                                        \
                                                call Node2


#define FORK016(x,Node1,Node2)              if (check_general_rep >= x) then            \
                                                call Node1;                             \
                                            else                                        \
                                                call Node2

#define FORK017(x,Node1,Node2)              if (check_general_rep <= x) then            \
                                                call Node1;                             \
                                            else                                        \
                                                call Node2

/* Weapon And Armor */
#define FORK018(x,Node1,Node2)              if (dude_is_armed) then         \
                                                call Node1;                 \
                                            else                            \
                                                call Node2

#define FORK019(x,Node1,Node2)              if ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) != PID_LEATHER_ARMOR) and             \
                                                (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) != PID_METAL_ARMOR) and               \
                                                (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) != PID_POWERED_ARMOR) and             \
                                                (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) != PID_COMBAT_ARMOR) and              \
                                                (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) != PID_LEATHER_JACKET) and            \
                                                (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) != PID_PURPLE_ROBE) and               \
                                                (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) != PID_HARDENED_POWER_ARMOR) and      \
                                                (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) != PID_BROTHERHOOD_COMBAT_ARMOR) and  \
                                                (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) != PID_TESLA_ARMOR)) then             \
                                                call Node1;                                                                                 \
                                            else                                                                                            \
                                                call Node2

#define FORK020(x,Node1,Node2)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_PURPLE_ROBE) then   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK021(x,Node1,Node2)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_JACKET) then            \
                                                call Node1;                                                                                 \
                                            else                                                                                            \
                                                call Node2

#define FORK022(x,Node1,Node2)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_ARMOR) then             \
                                                call Node1;                                                                                 \
                                            else                                                                                            \
                                                call Node2

#define FORK023(x,Node1,Node2)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_METAL_ARMOR) then               \
                                                call Node1;                                                                                 \
                                            else                                                                                            \
                                                call Node2

/*#define FORK023(x,Node1,Node2)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_COMBAT_ARMOR) then              \
                                                call Node1;                                                                                 \
                                            else                                                                                            \
                                                call Node2
*/
#define FORK025(x,Node1,Node2)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_BROTHERHOOD_COMBAT_ARMOR) then  \
                                                call Node1;                                                                                 \
                                            else                                                                                            \
                                                call Node2

#define FORK026(x,Node1,Node2)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_POWERED_ARMOR) then             \
                                                call Node1;                                                                                 \
                                            else                                                                                            \
                                                call Node2

#define FORK027(x,Node1,Node2)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_HARDENED_POWER_ARMOR) then      \
                                                call Node1;                                                                                 \
                                            else                                                                                            \
                                                call Node2

#define FORK028(x,Node1,Node2)              if (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_TESLA_ARMOR) then               \
                                                call Node1;                                                                                 \
                                            else                                                                                            \
                                                call Node2


/* Skills */
#define FORK029(x,Node1,Node2)              ValueOfRollCheck:=roll_vs_skill(dude_obj,SKILL_SPEECH,x);                       \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK030(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_SPEECH) >= x) then                                 \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK031(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_SPEECH) <= x) then                                 \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK032(x,Node1,Node2)              ValueOfRollCheck:=roll_vs_skill(dude_obj,SKILL_BARTER,x);                           \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK033(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_BARTER) >= x) then                                     \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK034(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_BARTER) <= x) then                                     \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK035(x,Node1,Node2)              ValueOfRollCheck:=roll_vs_skill(dude_obj,SKILL_SCIENCE,x);                          \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK036(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_SCIENCE) >= x) then                                    \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK037(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_SCIENCE) <= x) then                                    \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK038(x,Node1,Node2)              ValueOfRollCheck:=roll_vs_skill(dude_obj,SKILL_OUTDOORSMAN,x);                      \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK039(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_OUTDOORSMAN) >= x) then                                \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK040(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_OUTDOORSMAN) <= x) then                                \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK041(x,Node1,Node2)              ValueOfRollCheck:=roll_vs_skill(dude_obj,SKILL_REPAIR,x);                           \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK042(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_REPAIR) >= x) then                                     \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK043(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_REPAIR) <= x) then                                     \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK044(x,Node1,Node2)              ValueOfRollCheck:=roll_vs_skill(dude_obj,SKILL_DOCTOR,x);                           \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK045(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_DOCTOR) >= x) then                                     \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK046(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_DOCTOR) <= x) then                                     \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK047(x,Node1,Node2)              ValueOfRollCheck:=roll_vs_skill(dude_obj,SKILL_FIRST_AID,x);                        \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK048(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_FIRST_AID) >= x) then                                  \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK049(x,Node1,Node2)              if (has_skill(dude_obj,SKILL_FIRST_AID) <= x) then                                  \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


/* Stats */
#define FORK050(x,Node1,Node2)              ValueOfRollCheck:=do_check(dude_obj,STAT_st,x);                                     \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK051(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_st) >= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK052(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_st) <= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK053(x,Node1,Node2)              ValueOfRollCheck:=do_check(dude_obj,STAT_pe,x);                                     \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK054(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_pe) >= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK055(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_pe) <= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK056(x,Node1,Node2)              ValueOfRollCheck:=do_check(dude_obj,STAT_en,x);                                     \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK057(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_en) >= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK058(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_en) <= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK059(x,Node1,Node2)              ValueOfRollCheck:=do_check(dude_obj,STAT_ch,x);                                     \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK060(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_ch) >= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK061(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_ch) <= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK062(x,Node1,Node2)              ValueOfRollCheck:=do_check(dude_obj,STAT_ag,x);                                     \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK063(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_ag) >= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK064(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_ag) <= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


#define FORK065(x,Node1,Node2)              ValueOfRollCheck:=do_check(dude_obj,STAT_lu,x);                                     \
                                            if (is_success(ValueOfRollCheck)) then                                              \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK066(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_lu) >= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK067(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_lu) <= x) then                                   \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


/* Health */
#define FORK068(x,Node1,Node2)              if (get_poison(dude_obj) > 0) then                                                  \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK069(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_current_rad) > 0) then                           \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK070(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_current_hp) >= ((x * get_critter_stat(dude_obj,STAT_max_hp))/100)) then   \
                                                call Node1;                                                                                                      \
                                            else                                                                                                                 \
                                                call Node2

#define FORK071(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_current_hp) <= ((x * get_critter_stat(dude_obj,STAT_max_hp))/100)) then   \
                                                call Node1;                                                                                                      \
                                            else                                                                                                                 \
                                                call Node2


/* Money */
#define FORK072(x,Node1,Node2)              if (item_caps_total(dude_obj) >= x) then                                            \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK073(x,Node1,Node2)              if (item_caps_total(dude_obj) <= x) then                                            \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


/* Age */
#define FORK074(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_age) >= x) then                                  \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

#define FORK075(x,Node1,Node2)              if (get_critter_stat(dude_obj,STAT_age) <= x) then                                  \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


/* Times Talked */
#define FORK076(x,Node1,Node2)              if (local_var(LVAR_Herebefore) == x) then                                           \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2

/* Is Critical */
#define FORK077(x,Node1,Node2)              if (is_critical(ValueOfRollCheck)) then                                             \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


/* Party */
#define FORK078(x,Node1,Node2)              if (party_member_count(DONT_LIST_HIDDEN_MEMBERS) >= x) then                         \
                                                call Node1;                                                                     \
                                            else                                                                                \
                                                call Node2


/************************************************************************
*******************   Giving Away Items     *****************************
************************************************************************/


/******************************************************************
***************       Armor                         ***************
******************************************************************/

#define ITEM001(x,Node1)                    ProtoOfItem:=create_object(PID_PURPLE_ROBE,0,0);                              \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                                \
                                            call Node1
#define ITEM002(x,Node1)                    ProtoOfItem:=create_object(PID_LEATHER_JACKET,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                                \
                                            call Node1
#define ITEM003(x,Node1)                    ProtoOfItem:=create_object(PID_LEATHER_ARMOR,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                                \
                                            call Node1
#define ITEM004(x,Node1)                    ProtoOfItem:=create_object(PID_METAL_ARMOR,0,0);                              \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                                \
                                            call Node1
#define ITEM005(x,Node1)                    ProtoOfItem:=create_object(PID_COMBAT_ARMOR,0,0);                             \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                                \
                                            call Node1
#define ITEM006(x,Node1)                    ProtoOfItem:=create_object(PID_BROTHERHOOD_COMBAT_ARMOR,0,0);                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                                \
                                            call Node1
#define ITEM007(x,Node1)                    ProtoOfItem:=create_object(PID_POWERED_ARMOR,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                                \
                                            call Node1
#define ITEM008(x,Node1)                    ProtoOfItem:=create_object(PID_HARDENED_POWER_ARMOR,0,0);                     \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                                \
                                            call Node1
#define ITEM009(x,Node1)                    ProtoOfItem:=create_object(PID_TESLA_ARMOR,0,0);                              \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                                \
                                            call Node1

/******************************************************************
***************       Weapons                       ***************
******************************************************************/

#define ITEM015(x,Node1)                    ProtoOfItem:=create_object(PID_KNIFE,0,0);                                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM016(x,Node1)                    ProtoOfItem:=create_object(PID_CLUB,0,0);                                   \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM017(x,Node1)                    ProtoOfItem:=create_object(PID_SLEDGEHAMMER,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM018(x,Node1)                    ProtoOfItem:=create_object(PID_SPEAR,0,0);                                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM019(x,Node1)                    ProtoOfItem:=create_object(PID_10MM_PISTOL,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM020(x,Node1)                    ProtoOfItem:=create_object(PID_10MM_SMG,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM021(x,Node1)                    ProtoOfItem:=create_object(PID_HUNTING_RIFLE,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM022(x,Node1)                    ProtoOfItem:=create_object(PID_FLAMER,0,0);                                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM023(x,Node1)                    ProtoOfItem:=create_object(PID_MINIGUN,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM024(x,Node1)                    ProtoOfItem:=create_object(PID_ROCKET_LAUNCHER,0,0);                        \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM025(x,Node1)                    ProtoOfItem:=create_object(PID_PLASMA_RIFLE,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM026(x,Node1)                    ProtoOfItem:=create_object(PID_LASER_PISTOL,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM027(x,Node1)                    ProtoOfItem:=create_object(PID_DESERT_EAGLE,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM028(x,Node1)                    ProtoOfItem:=create_object(PID_ROCK,0,0);                                   \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM029(x,Node1)                    ProtoOfItem:=create_object(PID_CROWBAR,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM030(x,Node1)                    ProtoOfItem:=create_object(PID_BRASS_KNUCKLES,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM031(x,Node1)                    ProtoOfItem:=create_object(PID_14MM_PISTOL,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM032(x,Node1)                    ProtoOfItem:=create_object(PID_ASSAULT_RIFLE,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM033(x,Node1)                    ProtoOfItem:=create_object(PID_PLASMA_PISTOL,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM034(x,Node1)                    ProtoOfItem:=create_object(PID_FRAG_GRENADE,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM035(x,Node1)                    ProtoOfItem:=create_object(PID_PLASMA_GRENADE,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM036(x,Node1)                    ProtoOfItem:=create_objectPID_PULSE_GRENADE(,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM037(x,Node1)                    ProtoOfItem:=create_object(PID_GATLING_LASER,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM038(x,Node1)                    ProtoOfItem:=create_object(PID_THROWING_KNIFE,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM039(x,Node1)                    ProtoOfItem:=create_object(PID_SHOTGUN,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM040(x,Node1)                    ProtoOfItem:=create_object(PID_SUPER_SLEDGE,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM041(x,Node1)                    ProtoOfItem:=create_object(PID_RIPPER,0,0);                                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM042(x,Node1)                    ProtoOfItem:=create_object(PID_LASER_RIFLE,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM043(x,Node1)                    ProtoOfItem:=create_object(PID_ALIEN_LASER_PISTOL,0,0);                     \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM044(x,Node1)                    ProtoOfItem:=create_object(PID_9MM_MAUSER,0,0);                             \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM045(x,Node1)                    ProtoOfItem:=create_object(PID_SNIPER_RIFLE,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM046(x,Node1)                    ProtoOfItem:=create_object(PID_MOLOTOV_COCKTAIL,0,0);                       \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM047(x,Node1)                    ProtoOfItem:=create_object(PID_CATTLE_PROD,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM048(x,Node1)                    ProtoOfItem:=create_object(PID_RED_RYDER_BB_GUN,0,0);                       \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM049(x,Node1)                    ProtoOfItem:=create_object(PID_RED_RYDER_LE_BB_GUN,0,0);                    \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM050(x,Node1)                    ProtoOfItem:=create_object(PID_TURBO_PLASMA_RIFLE,0,0);                     \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM051(x,Node1)                    ProtoOfItem:=create_object(PID_SPIKED_KNUCKLES,0,0);                        \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM052(x,Node1)                    ProtoOfItem:=create_object(PID_POWER_FIST,0,0);                             \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM053(x,Node1)                    ProtoOfItem:=create_object(PID_COMBAT_KNIFE,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM054(x,Node1)                    ProtoOfItem:=create_object(PID_223_PISTOL,0,0);                             \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM055(x,Node1)                    ProtoOfItem:=create_object(PID_COMBAT_SHOTGUN,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1


/******************************************************************
***************       Ammo                          ***************
******************************************************************/

#define ITEM070(x,Node1)                    ProtoOfItem:=create_object(PID_EXPLOSIVE_ROCKET,0,0);                       \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM071(x,Node1)                    ProtoOfItem:=create_object(PID_10MM_JHP,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM072(x,Node1)                    ProtoOfItem:=create_object(PID_10MM_AP,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM073(x,Node1)                    ProtoOfItem:=create_object(PID_44_MAGNUM_JHP,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM074(x,Node1)                    ProtoOfItem:=create_object(PID_FLAMETHROWER_FUEL,0,0);                      \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM075(x,Node1)                    ProtoOfItem:=create_object(PID_14MM_AP,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM076(x,Node1)                    ProtoOfItem:=create_object(PID_223_FMJ,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM077(x,Node1)                    ProtoOfItem:=create_object(PID_5MM_JHP,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM078(x,Node1)                    ProtoOfItem:=create_object(PID_5MM_AP,0,0);                                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM079(x,Node1)                    ProtoOfItem:=create_object(PID_ROCKET_AP,0,0);                              \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM080(x,Node1)                    ProtoOfItem:=create_object(PID_SMALL_ENERGY_CELL,0,0);                      \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM081(x,Node1)                    ProtoOfItem:=create_object(PID_MICRO_FUSION_CELL,0,0);                      \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM082(x,Node1)                    ProtoOfItem:=create_object(PID_SHOTGUN_SHELLS,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM083(x,Node1)                    ProtoOfItem:=create_object(PID_44_FMJ_MAGNUM,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM084(x,Node1)                    ProtoOfItem:=create_object(PID_9MM_BALL,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM085(x,Node1)                    ProtoOfItem:=create_object(PID_BBS,0,0);                                    \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1


/******************************************************************
***************       Medical                       ***************
******************************************************************/

#define ITEM095(x,Node1)                    ProtoOfItem:=create_object(PID_STIMPAK,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM096(x,Node1)                    ProtoOfItem:=create_object(PID_FIRST_AID_KIT,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM097(x,Node1)                    ProtoOfItem:=create_object(PID_RADAWAY,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM098(x,Node1)                    ProtoOfItem:=create_object(PID_ANTIDOTE,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM099(x,Node1)                    ProtoOfItem:=create_object(PID_MENTATS,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM100(x,Node1)                    ProtoOfItem:=create_object(PID_MUTATED_FRUIT,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM101(x,Node1)                    ProtoOfItem:=create_object(PID_BUFFOUT,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM102(x,Node1)                    ProtoOfItem:=create_object(PID_DOCTORS_BAG,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM103(x,Node1)                    ProtoOfItem:=create_object(PID_RAD_X,0,0);                                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM104(x,Node1)                    ProtoOfItem:=create_object(PID_PSYCHO,0,0);                                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM105(x,Node1)                    ProtoOfItem:=create_object(PID_SUPER_STIMPAK,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1


/******************************************************************
***************       Container                     ***************
******************************************************************/

#define ITEM120(x,Node1)                    ProtoOfItem:=create_object(PID_FRIDGE,0,0);                                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM121(x,Node1)                    ProtoOfItem:=create_object(PID_ICE_CHEST_LEFT,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM122(x,Node1)                    ProtoOfItem:=create_object(PID_ICE_CHEST_RIGHT,0,0);                        \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM123(x,Node1)                    ProtoOfItem:=create_object(PID_BAG,0,0);                                    \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM124(x,Node1)                    ProtoOfItem:=create_object(PID_BACKPACK,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM125(x,Node1)                    ProtoOfItem:=create_object(PID_BROWN_BAG,0,0);                              \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM126(x,Node1)                    ProtoOfItem:=create_object(PID_FOOTLOCKER_CLEAN_LEFT,0,0);                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM127(x,Node1)                    ProtoOfItem:=create_object(PID_FOOTLOCKER_RUSTY_LEFT,0,0);                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM128(x,Node1)                    ProtoOfItem:=create_object(PID_FOOTLOCKER_CLEAN_RIGHT,0,0);                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM129(x,Node1)                    ProtoOfItem:=create_object(PID_FOOTLOCKER_RUSTY_RIGHT,0,0);                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM130(x,Node1)                    ProtoOfItem:=create_object(PID_LOCKER_CLEAN_LEFT,0,0);                      \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM131(x,Node1)                    ProtoOfItem:=create_object(PID_LOCKER_RUSTY_LEFT,0,0);                      \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM132(x,Node1)                    ProtoOfItem:=create_object(PID_LOCKER_CLEAN_RIGHT,0,0);                     \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM133(x,Node1)                    ProtoOfItem:=create_object(PID_LOCKER_RUSTY_RIGHT,0,0);                     \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM134(x,Node1)                    ProtoOfItem:=create_object(PID_WALL_LOCKER_CLEAN_LEFT,0,0);                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM135(x,Node1)                    ProtoOfItem:=create_object(PID_WALL_LOCKER_CLEAN_RIGHT,0,0);                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM136(x,Node1)                    ProtoOfItem:=create_object(PID_WALL_LOCKER_RUSTY_LEFT,0,0);                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM137(x,Node1)                    ProtoOfItem:=create_object(PID_WALL_LOCKER_RUSTY_RIGHT,0,0);                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM138(x,Node1)                    ProtoOfItem:=create_object(PID_CONTAINER_WOOD_CRATE,0,0);                   \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM139(x,Node1)                    ProtoOfItem:=create_object(PID_VAULT_DWELLER_BONES,0,0);                    \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1


/******************************************************************
***************       Books                         ***************
******************************************************************/

#define ITEM150(x,Node1)                    ProtoOfItem:=create_object(PID_BIG_BOOK_OF_SCIENCE,0,0);                    \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM151(x,Node1)                    ProtoOfItem:=create_object(PID_DEANS_ELECTRONICS,0,0);                      \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM152(x,Node1)                    ProtoOfItem:=create_object(PID_FIRST_AID_BOOK,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM153(x,Node1)                    ProtoOfItem:=create_object(PID_SCOUT_HANDBOOK,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM154(x,Node1)                    ProtoOfItem:=create_object(PID_GUNS_AND_BULLETS,0,0);                       \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM155(x,Node1)                    ProtoOfItem:=create_object(PID_CATS_PAW,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM156(x,Node1)                    ProtoOfItem:=create_object(PID_TECHNICAL_MANUAL,0,0);                       \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM157(x,Node1)                    ProtoOfItem:=create_object(PID_CHEMISTRY_MANUAL,0,0);                       \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1


/******************************************************************
***************       Tools                         ***************
******************************************************************/

#define ITEM165(x,Node1)                    ProtoOfItem:=create_object(PID_DYNAMITE,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM166(x,Node1)                    ProtoOfItem:=create_object(PID_GEIGER_COUNTER,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM167(x,Node1)                    ProtoOfItem:=create_object(PID_STEALTH_BOY,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM168(x,Node1)                    ProtoOfItem:=create_object(PID_MOTION_SENSOR,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM169(x,Node1)                    ProtoOfItem:=create_object(PID_MULTI_TOOL,0,0);                             \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM170(x,Node1)                    ProtoOfItem:=create_object(PID_ELECTRONIC_LOCKPICKS,0,0);                   \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM171(x,Node1)                    ProtoOfItem:=create_object(PID_LOCKPICKS,0,0);                              \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM172(x,Node1)                    ProtoOfItem:=create_object(PID_PLASTIC_EXPLOSIVES,0,0);                     \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM173(x,Node1)                    ProtoOfItem:=create_object(PID_ROPE,0,0);                                   \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1


/******************************************************************
***************       Misc.                         ***************
******************************************************************/

#define ITEM180(x,Node1)                    ProtoOfItem:=create_object(PID_BOTTLE_CAPS,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
// Reserved item! Don't use! Broken!
#define ITEM181(x,Node1)                    ProtoOfItem:=create_object(RESERVED_ITEM00,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM182(x,Node1)                    ProtoOfItem:=create_object(PID_WATER_CHIP,0,0);                             \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM183(x,Node1)                    ProtoOfItem:=create_object(PID_DOG_TAGS,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM184(x,Node1)                    ProtoOfItem:=create_object(PID_ELECTRONIC_BUG,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM185(x,Node1)                    ProtoOfItem:=create_object(PID_HOLODISK,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM186(x,Node1)                    ProtoOfItem:=create_object(PID_BRIEFCASE,0,0);                              \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM187(x,Node1)                    ProtoOfItem:=create_object(PID_FUZZY_PAINTING,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM188(x,Node1)                    ProtoOfItem:=create_object(PID_FLARE,0,0);                                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM189(x,Node1)                    ProtoOfItem:=create_object(PID_IGUANA_ON_A_STICK,0,0);                      \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM190(x,Node1)                    ProtoOfItem:=create_object(PID_KEY,0,0);                                    \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM191(x,Node1)                    ProtoOfItem:=create_object(PID_KEYS,0,0);                                   \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM192(x,Node1)                    ProtoOfItem:=create_object(PID_WATCH,0,0);                                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM193(x,Node1)                    ProtoOfItem:=create_object(PID_MOTOR,0,0);                                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM194(x,Node1)                    ProtoOfItem:=create_object(PID_SCORPION_TAIL,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM195(x,Node1)                    ProtoOfItem:=create_object(PID_RED_PASS_KEY,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM196(x,Node1)                    ProtoOfItem:=create_object(PID_BLUE_PASS_KEY,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM197(x,Node1)                    ProtoOfItem:=create_object(PID_PUMP_PARTS,0,0);                             \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM198(x,Node1)                    ProtoOfItem:=create_object(PID_GOLD_LOCKET,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM199(x,Node1)                    ProtoOfItem:=create_object(PID_RADIO,0,0);                                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM200(x,Node1)                    ProtoOfItem:=create_object(PID_LIGHTER,0,0);                                \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM201(x,Node1)                    ProtoOfItem:=create_object(PID_MEAT_ON_A_STICK,0,0);                        \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM202(x,Node1)                    ProtoOfItem:=create_object(PID_TAPE_RECORDER,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM203(x,Node1)                    ProtoOfItem:=create_object(PID_NUKE_KEY,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM204(x,Node1)                    ProtoOfItem:=create_object(PID_NUKA_COLA,0,0);                              \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM205(x,Node1)                    ProtoOfItem:=create_object(PID_ALIEN_SIDE,0,0);                             \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM206(x,Node1)                    ProtoOfItem:=create_object(PID_ALIEN_FORWARD,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM207(x,Node1)                    ProtoOfItem:=create_object(PID_URN,0,0);                                    \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM208(x,Node1)                    ProtoOfItem:=create_object(PID_TANGLERS_HAND,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM209(x,Node1)                    ProtoOfItem:=create_object(PID_FLOWER,0,0);                                 \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM210(x,Node1)                    ProtoOfItem:=create_object(PID_NECKLACE,0,0);                               \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM211(x,Node1)                    ProtoOfItem:=create_object(PID_PSYCHIC_NULLIFIER,0,0);                      \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM212(x,Node1)                    ProtoOfItem:=create_object(PID_BEER,0,0);                                   \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM213(x,Node1)                    ProtoOfItem:=create_object(PID_BOOZE,0,0);                                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM214(x,Node1)                    ProtoOfItem:=create_object(PID_WATER_FLASK,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM215(x,Node1)                    ProtoOfItem:=create_object(PID_ACCESS_CARD,0,0);                            \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM216(x,Node1)                    ProtoOfItem:=create_object(PID_BLACK_COC_BADGE,0,0);                        \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM217(x,Node1)                    ProtoOfItem:=create_object(PID_RED_COC_BADGE,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM218(x,Node1)                    ProtoOfItem:=create_object(PID_BARTER_TANDI,0,0);                           \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM219(x,Node1)                    ProtoOfItem:=create_object(PID_BARTER_LIGHT_HEALING,0,0);                   \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM220(x,Node1)                    ProtoOfItem:=create_object(PID_BARTER_MEDIUM_HEALING,0,0);                  \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM221(x,Node1)                    ProtoOfItem:=create_object(PID_BARTER_HEAVY_HEALING,0,0);                   \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM222(x,Node1)                    ProtoOfItem:=create_object(PID_SECURITY_CARD,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM223(x,Node1)                    ProtoOfItem:=create_object(PID_TOGGLE_SWITCH,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM224(x,Node1)                    ProtoOfItem:=create_object(PID_YELLOW_PASS_KEY,0,0);                        \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM225(x,Node1)                    ProtoOfItem:=create_object(PID_SMALL_STATUETTE,0,0);                        \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM226(x,Node1)                    ProtoOfItem:=create_object(PID_BOX_OF_NOODLES,0,0);                         \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM227(x,Node1)                    ProtoOfItem:=create_object(PID_FROZEN_DINNER,0,0);                          \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1
#define ITEM228(x,Node1)                    ProtoOfItem:=create_object(PID_MOTIVATOR,0,0);                              \
                                            add_mult_objs_to_inven(dude_obj,ProtoOfItem,x)                              \
                                            call Node1

#endif // CONDTION_H
