/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef COMMAND_H
#define COMMAND_H

//Did the above so I could include it in define.h without inheritance problems

/*********************************************************
 define file for commands dealing with the dude.

 Contents of the File:
        I.      Flee from Player
        II.     Player Information
        III.    Dialogue Information
*********************************************************/

// include files that are needed after other declarations are made.
#include "reppoint.h"


/*********************************************************
 General interaction dealing with the dude
 should he attack people in a community
*********************************************************/
variable global_temp;

#define Get_Rotation_Away_From_Dude(x)      rotation_to_tile(tile_num(dude_obj),tile_num(x))

#define Run_Away_From_Dude_Dir              Get_Rotation_Away_From_Dude(self_obj)
#define run_away_from_dist                  random(3, 10)
#define push_away_from_dist                 random(2, 5)

#define run_away_tile_dir(x)                tile_num_in_direction(tile_num(self_obj), x, run_away_from_dist)
#define Run_Away_From_Dude_Tile             run_away_tile_dir(Run_Away_From_Dude_Dir)

#define Current_Distance_From_Obj(the_obj)  tile_distance_objs(self_obj,the_obj)
#define Current_Distance_From_Dude          Current_Distance_From_Obj(dude_obj)
#define distance_dude                       tile_distance_objs(self_obj,dude_obj)

#define Future_Distance_From_Obj(x, y)      tile_num_in_direction(tile_num(x), ((has_trait(TRAIT_OBJECT,x,OBJECT_CUR_ROT) + 3)%6), y)
#define Future_Distance_From_Dude(x)        Future_Distance_From_Obj(dude_obj, x)

#define away_from_tile_type(x, type, dist)  if (anim_busy(self_obj) == false) then begin                                                             \
                                               global_temp := rotation_to_tile(x, self_tile);                                                        \
                                               animate_##type##_to_tile(tile_num_in_direction(self_tile, global_temp, dist));                        \
                                               global_temp := (global_temp + 1) % 6;                                                                 \
                                               while ((anim_busy(self_obj) == false) and (global_temp != rotation_to_tile(x, self_tile))) do begin   \
                                                  ndebug("flee loop: rot == "+global_temp);                                                       \
                                                  animate_##type##_to_tile(tile_num_in_direction(self_tile, global_temp, dist));                     \
                                                  global_temp := (global_temp + 1) % 6;                                                              \
                                               end                                                                                                   \
                                            end

#define simulate_push(x)                    away_from_tile_type(tile_num_in_direction(self_tile, rotation_to_tile(x, self_tile), 1), move, push_away_from_dist)
#define flee_from_tile(x)                   away_from_tile_type(x, run, run_away_from_dist)
#define Flee_From_Dude                      if ((Current_Distance_From_Dude < 8) or (self_can_see_dude)) then begin  \
                                               flee_from_tile(dude_tile)                                             \
                                            end

#define Flee_From_Dude_Force                if ((Current_Distance_From_Dude < 8) or (self_can_see_dude)) then begin  \
                                                animate_run_to_tile_force(Run_Away_From_Dude_Tile);                  \
                                            end

#define Follow_Dude(X,Y)                    if (Current_Distance_From_Dude > X) then begin                  \
                                               if (Current_Distance_From_Dude > X*2) then begin             \
                                                  animate_run_to_tile(Future_Distance_From_Dude(Y));        \
                                               end else begin                                               \
                                                  animate_move_to_tile(Future_Distance_From_Dude(Y));       \
                                               end                                                          \
                                            end

#define get_follow_point_dist(the_obj)      ((tile_distance_objs(the_obj, self_obj) / 5) + 1)
#define follow_obj_point(the_range, the_dist, the_obj)                                                            \
                                            if (Current_Distance_From_Dude > the_range) then begin                \
                                                if (Current_Distance_From_Dude > (the_range * 2)) then begin    \
                                                   anim_run_to_point_rate(tile_num_in_direction(tile_num(the_obj), rotation_to_tile(tile_num(the_obj), self_tile), the_dist), get_follow_point_dist(the_obj))   \
                                                end else begin                                                  \
                                                   anim_move_to_point_rate(tile_num_in_direction(tile_num(the_obj), rotation_to_tile(tile_num(the_obj), self_tile), the_dist), get_follow_point_dist(the_obj))  \
                                                end                                                             \
                                            end
#define party_follow_dude_point(the_range, the_dist)                                                              \
                                            if (Current_Distance_From_Dude > the_range) then begin                \
                                                if (anim_busy(self_obj) == false) then begin                      \
                                                   dest_tile := tile_num_in_direction(tile_num_in_direction(dude_tile, Run_Away_From_Dude_Dir, the_dist), random(0, 5), random(0, 2)); \
                                                   if (Current_Distance_From_Dude > (the_range * 2)) then begin   \
                                                      animate_run_to_tile(dest_tile);                             \
                                                   end else begin                                                 \
                                                      animate_move_to_tile(dest_tile);                            \
                                                   end                                                            \
                                                end else if (self_distance_from_dude < tile_distance(self_tile, dest_tile)) then begin  \
                                                   reg_anim_clear(self_obj);                                      \
                                                end                                                               \
                                            end
#define follow_dude_point(the_range, the_dist)     follow_obj_point(the_range, the_dist, dude_obj)

#define Follow_Dude_Run_Only(X,Y)           if (Current_Distance_From_Dude > X) then begin                  \
                                               animate_run_to_tile(Future_Distance_From_Dude(Y));           \
                                            end

#define Follow_Obj_Run_Only(O,X,Y)          if (tile_distance_objs(self_obj,O) > X) then begin              \
                                               animate_run_to_tile(Future_Distance_From_Obj(O, Y));         \
                                            end
#define Get_In_Obj_Face(the_obj)            if (tile_distance_objs(self_obj, the_obj) > 1) then begin                                                              \
                                               animate_move_to_tile(tile_num_in_direction(tile_num(the_obj), has_trait(TRAIT_OBJECT,the_obj,OBJECT_CUR_ROT), 1));  \
                                            end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin                        \
                                               if (anim_busy(self_obj) == false) then begin                                                                        \
                                                  Face_Critter(the_obj, self_obj);                                                                                 \
                                               end                                                                                                                 \
                                            end
#define Get_In_Face_Run_Dist(the_obj,dist)  if (tile_distance_objs(self_obj, the_obj) > 1) then begin                                                              \
                                               animate_run_to_tile(tile_num_in_direction(tile_num(the_obj), has_trait(TRAIT_OBJECT,the_obj,OBJECT_CUR_ROT), dist));\
                                            end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin                        \
                                               if (anim_busy(self_obj) == false) then begin                                                                        \
                                                  Face_Critter(the_obj, self_obj);                                                                                 \
                                               end                                                                                                                 \
                                            end

#define next_and_face_obj(the_obj, the_type, the_rate)                                                                                                             \
                                             if (tile_distance_objs(self_obj, the_obj) > 1) then begin                                                             \
                                                the_type(tile_num_in_direction(tile_num(the_obj), rotation_to_tile(tile_num(the_obj),tile_num(self_obj)), 1)); /* Seraph's Fix: 'the_type' only takes one argument. Thanks Rob! */\
                                             end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin                       \
                                                if (anim_busy(self_obj) == false) then begin                                                                       \
                                                   Face_Critter(the_obj, self_obj);                                                                                \
                                                end                                                                                                                \
                                             end

#define point_next_and_face_obj(the_obj, the_type, the_rate)                                                                                                       \
                                             if (tile_distance_objs(self_obj, the_obj) > 1) then begin                                                             \
                                                the_type(tile_num_in_direction(tile_num(the_obj), rotation_to_tile(tile_num(the_obj),tile_num(self_obj)), 1)) /* Seraph's Fix: 'the_type' only takes one argument. Thanks Rob! */\
                                             end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin                       \
                                                if (anim_busy(self_obj) == false) then begin                                                                       \
                                                   Face_Critter(the_obj, self_obj);                                                                                \
                                                end                                                                                                                \
                                             end

#define Get_Next_To_Obj_And_Face_Rate(the_obj, x)     next_and_face_obj(the_obj, animate_move_to_tile, x)
#define Get_Next_To_Obj_And_Face(the_obj)             next_and_face_obj(the_obj, animate_move_to_tile, 1)
#define Run_Next_To_Obj_And_Face_Rate(the_obj, x)     next_and_face_obj(the_obj, animate_run_to_tile, x)
#define Run_Next_To_Obj_And_Face(the_obj)             next_and_face_obj(the_obj, animate_run_to_tile, 1)
#define point_move_next_and_face_Rate(the_obj, x)     point_next_and_face_obj(the_obj, anim_move_to_point, x)
#define point_move_next_and_face(the_obj)             point_next_and_face_obj(the_obj, anim_move_to_point, 1)
#define point_run_next_and_face_Rate(the_obj, x)      point_next_and_face_obj(the_obj, anim_run_to_point, x)
#define point_run_next_and_face(the_obj)              point_next_and_face_obj(the_obj, anim_run_to_point, 1)

// the Z is a variable LOCAL variable that stores the tile where the dude was last time it was told to follow
//    this will keep the animation for the follow clean

#define closest_clear_tile(obj, the_tile, x)       x := the_tile;                                                                   \
                                                   while ((x != tile_num(obj)) and (tile_is_blocked(x, elevation(obj)))) do begin   \
                                                      x := tile_num_in_direction(x, rotation_to_tile(x, tile_num(obj)), 1);         \
                                                   end
// this is like the above but uses to regular variables instead of local vars
// this steps like the old step macro, but it's faster and better
//
variable dest_tile;
variable step_tile;
#define FAIL_STEP_ACTION                           if (tile_get_next_critter(tile_num_in_direction(self_tile, self_cur_rot, 1), self_elevation, 0) != 0) then begin \
                                                      simulate_push(tile_num_in_direction(self_tile, self_cur_rot, 1))                                              \
                                                   end else step_tile := -10;
//#define FAIL_STEP_ACTION                           step_tile := -5;
#define move_to_point(the_tile, move_type, x)                                                                                                                                                   \
                                                   if ((self_tile != the_tile) and (the_tile != 0)) then begin                                                                                  \
                                                      if ((dest_tile == the_tile) and (step_tile < 0)) then begin                                                                               \
                                                         step_tile += 1;                                                                                                                        \
                                                         ndebug("step_tile: " + step_tile);                                                                                                  \
                                                      end else if (anim_busy(self_obj) == false) then begin                                                                                     \
                                                         dest_tile := the_tile;                                                                                                                 \
                                                         step_tile := the_tile;                                                                                                                 \
                                                         animate_##move_type##_to_tile(step_tile);                                                                                              \
                                                         while ((anim_busy(self_obj) == false) and (((tile_distance(self_tile, the_tile)) >= (tile_distance(step_tile, the_tile))))) do begin   \
                                                            ndebug("rot: " + rotation_to_tile(step_tile, self_tile));                                                                        \
                                                            step_tile := tile_num_in_direction(step_tile, rotation_to_tile(step_tile, self_tile), (x % tile_distance(step_tile, self_tile)));   \
                                                            ndebug("step_var: " + step_tile);                                                                                                \
                                                            animate_##move_type##_to_tile(step_tile);                                                                                           \
                                                         end                                                                                                                                    \
                                                         if (anim_busy(self_obj) == false) then begin                                                                                           \
                                                            FAIL_STEP_ACTION                                                                                                                    \
                                                         end                                                                                                                                    \
                                                      end else if ((tile_distance(self_tile, the_tile)) < (tile_distance(dest_tile, the_tile))) then begin                                      \
                                                         reg_anim_clear(self_obj);                                                                                                              \
                                                      end                                                                                                                                       \
                                                   end

#define anim_move_to_point_rate(the_tile, x)       move_to_point(the_tile, move, x)
#define anim_move_to_point(the_tile)               anim_move_to_point_rate(the_tile, 1)
#define anim_run_to_point_rate(the_tile, x)        move_to_point(the_tile, run, x)
#define anim_run_to_point(the_tile)                anim_run_to_point_rate(the_tile, 1)

// walk/run
#define self_walk_to_tile(tile)             animate_move_obj_to_tile(self_obj,tile,ANIMATE_WALK)
#define self_run_to_tile(tile)              animate_move_obj_to_tile(self_obj,tile,ANIMATE_RUN)
#define self_run_to_tile_force(tile)        animate_move_obj_to_tile(self_obj,tile,ANIMATE_RUN_FORCE)
#define dude_run_to_tile(tile)              animate_move_obj_to_tile(dude_obj,tile,ANIMATE_RUN)
// rotate
#define self_rotation_to_dude               rotation_to_tile(self_tile,dude_tile)
#define obj_rotate(obj,dir)                 anim(obj,ANIMATE_ROTATION,dir)
#define dude_rotate(dir)                    obj_rotate(dude_obj,dir)
#define self_rotate(dir)                    obj_rotate(self_obj,dir)
#define dude_rotation_to_self               rotation_to_tile(dude_tile,self_tile)
#define self_look_at_dude                   anim(self_obj,ANIMATE_ROTATION,self_rotation_to_dude)
// stand
#define dude_stand                          animate_stand_obj(dude_obj)
#define self_stand                          animate_stand_obj(self_obj)
// and whatever
#define self_set_frame(frame)               anim(self_obj,ANIMATE_SET_FRAME,frame)

// map variables that share the same number throught the maps are listed here

#define critter_is_armed(x)                 (((obj_item_subtype(critter_inven_obj(x,INVEN_TYPE_RIGHT_HAND))) == item_type_weapon) or \
                                             ((obj_item_subtype(critter_inven_obj(x,INVEN_TYPE_LEFT_HAND))) == item_type_weapon))
/**
 * Returns True if anyone is party carries a weapon openly, False othewise.
 * - Goris is skipped, as he's cloaked.
 * @ret {bool} armed
 */
procedure party_is_armed() begin
   foreach (variable who in party_member_list_critters) begin
      if obj_pid(who) == PID_GORIS then continue;
      if critter_is_armed(who) then return true;
   end
   return false;
end
#define critter_weight(x)                   (100 + ((get_critter_stat(x,STAT_gender) == GENDER_MALE) * 50) + (get_critter_stat(x,STAT_st) * 5) - ((get_critter_stat(x,STAT_ag) + get_critter_stat(x,STAT_en))/3))
#define critter_wearing_armor(x)            (obj_item_subtype(critter_inven_obj(x,INVEN_TYPE_WORN)) == item_type_armor)

// items in hands
#define get_left_hand(cr)                 critter_inven_obj(cr,INVEN_TYPE_LEFT_HAND)
#define dude_left_hand                    get_left_hand(dude_obj)
#define self_left_hand                    get_left_hand(self_obj)
#define get_right_hand(cr)                critter_inven_obj(cr,INVEN_TYPE_RIGHT_HAND)
#define dude_right_hand                   get_right_hand(dude_obj)
#define self_right_hand                   get_right_hand(self_obj)

#define dude_is_stupid                      (dude_iq <= 3)
#define dude_is_stupid_talk                 (dude_iq + dude_smooth_talker <= 3)
#define dude_name                           (obj_name(dude_obj))
#define dude_gender                         (get_critter_stat(dude_obj,STAT_gender))
#define dude_strength                       (get_critter_stat(dude_obj,STAT_st))
#define dude_perception                     (get_critter_stat(dude_obj,STAT_pe))
#define dude_endurance                      (get_critter_stat(dude_obj,STAT_en))
#define dude_charisma                       (get_critter_stat(dude_obj,STAT_ch))
#define dude_iq                             (get_critter_stat(dude_obj,STAT_iq))
#define dude_iq_talk                        (get_critter_stat(dude_obj,STAT_iq) + dude_smooth_talker)
#define dude_agility                        (get_critter_stat(dude_obj,STAT_ag))
#define dude_luck                           (get_critter_stat(dude_obj,STAT_lu))
#ifndef dude_level
#define dude_level                          (get_pc_stat(PCSTAT_level))
#endif
#define dude_age                            (get_critter_stat(dude_obj,STAT_age))
#define dude_weight                         critter_weight(dude_obj)

#define dude_moron_not_vegetable            (((get_critter_stat(dude_obj,STAT_iq)) > 1) and ((get_critter_stat(dude_obj,STAT_iq)) < 3) )

#define dude_is_male                        (dude_gender == GENDER_MALE)
#define dude_is_female                      (dude_gender == GENDER_FEMALE)
#define dude_is_armed                       critter_is_armed(dude_obj)
#define dude_wearing_armor                  critter_wearing_armor(dude_obj)

#define get_armor(cr)                       critter_inven_obj(cr,INVEN_TYPE_WORN)
#define dude_armor                          get_armor(dude_obj)
#define self_armor                          get_armor(self_obj)

#define dude_has_power_armor                (((obj_is_carrying_obj_pid(dude_obj, PID_POWERED_ARMOR)) +            \
                                              (obj_is_carrying_obj_pid(dude_obj, PID_ADVANCED_POWER_ARMOR)) +     \
                                              (obj_is_carrying_obj_pid(dude_obj, PID_ADVANCED_POWER_ARMOR_MK2)) + \
                                              (obj_is_carrying_obj_pid(dude_obj, PID_HARDENED_POWER_ARMOR))) > 0)

#define dude_wielding_knife                 ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_KNIFE) or                \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_THROWING_KNIFE) or       \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_RIPPER) or               \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_COMBAT_KNIFE) or         \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_SWITCHBLADE) or          \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_SHIV) or                 \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_LIL_JESUS_WEAPON) or     \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_RIGHT_HAND)) == PID_WAKIZASHI_BLADE) or      \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_KNIFE) or                 \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_THROWING_KNIFE) or        \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_RIPPER) or                \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_COMBAT_KNIFE) or          \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_SWITCHBLADE) or           \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_SHIV) or                  \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_LIL_JESUS_WEAPON) or      \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_LEFT_HAND)) == PID_WAKIZASHI_BLADE))

#define dude_wearing_power_armor            ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_POWERED_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_ADVANCED_POWER_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_ADVANCED_POWER_ARMOR_MK2) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_HARDENED_POWER_ARMOR))

#define dude_wearing_leather_armor          ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_JACKET) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_LEATHER_ARMOR_MK_II) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_CURED_LEATHER_ARMOR))

#define dude_wearing_combat_armor           ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_COMBAT_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_BROTHERHOOD_COMBAT_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_COMBAT_ARMOR_MK_II))

#define dude_wearing_metal_armor            ((obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_METAL_ARMOR) or \
                                             (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_METAL_ARMOR_MK_II))

#define dude_wearing_vault_suit             ((critter_inven_obj2(dude_obj, INVEN_TYPE_WORN)) == 0)
#define dude_wearing_coc_robe               (obj_pid(critter_inven_obj(dude_obj,INVEN_TYPE_WORN)) == PID_PURPLE_ROBE)

#define dude_has_gambling_skills            ((dude_iq > 3) and (has_skill(dude_obj, SKILL_GAMBLING) >= 25))

#define dude_is_sneaking                    (using_skill(dude_obj,SKILL_SNEAK))
#define dude_is_walking                     (art_anim(obj_art_fid(dude_obj)) == ANIM_walk)
#define dude_is_running                     (art_anim(obj_art_fid(dude_obj)) == ANIM_running)
#define dude_is_poisoned                    (get_poison(dude_obj))
#define dude_is_irradiated                  (get_critter_stat(dude_obj, STAT_current_rad))
#define dude_is_crippled                    ((critter_state(dude_obj) bwand DAM_CRIP_LEG_LEFT)  or \
                                             (critter_state(dude_obj) bwand DAM_CRIP_LEG_RIGHT) or \
                                             (critter_state(dude_obj) bwand DAM_CRIP_ARM_LEFT)  or \
                                             (critter_state(dude_obj) bwand DAM_CRIP_ARM_RIGHT))

#define get_rads(cr)                        get_critter_stat(cr,STAT_current_rad)
#define dude_rads                           get_rads(dude_obj)
#define self_rads                           get_rads(self_obj)

#define get_cur_rot(cr)                     has_trait(TRAIT_OBJECT,cr,OBJECT_CUR_ROT)
#define dude_cur_rot                        (has_trait(TRAIT_OBJECT,dude_obj,OBJECT_CUR_ROT))
#define dude_inv_rot                        ((dude_cur_rot + 3)%6)
#define dude_tile                           (tile_num(dude_obj))
#define dude_elevation                      (elevation(dude_obj))

#define tile_behind_obj(who)                (tile_num_in_direction(tile_num(who),((has_trait(TRAIT_OBJECT,who,OBJECT_CUR_ROT) + 3) % 6), 1))
#define tile_behind_obj_rng(who, rng)       (tile_num_in_direction(tile_num(who),((has_trait(TRAIT_OBJECT,who,OBJECT_CUR_ROT) + 3) % 6), rng))

#define dude_cur_hits                       (get_critter_stat(dude_obj,STAT_current_hp))
#define dude_max_hits                       (get_critter_stat(dude_obj,STAT_max_hp))

#define dude_mental_block                   (has_trait(TRAIT_PERK,dude_obj,PERK_mental_block))
#define dude_presence                       (has_trait(TRAIT_PERK,dude_obj,PERK_presence))
#define dude_awareness                      (has_trait(TRAIT_PERK,dude_obj,PERK_bonus_awareness))
#define dude_fortune_finder                 (has_trait(TRAIT_PERK,dude_obj,PERK_fortune_finder))
#define dude_smooth_talker                  (has_trait(TRAIT_PERK,dude_obj,PERK_smooth_talker))

#define dude_caps                           (item_caps_total(dude_obj))
#define dude_caps_adjust(caps)              item_caps_adjust(dude_obj,caps)

#define dude_has_car                        (global_var(GVAR_PLAYER_GOT_CAR))
#define dude_is_pornstar                    dude_has_porn_star_rep
#define dude_is_high                        drug_influence(dude_obj)
#define dude_found_geck                     global_var(GVAR_VAULT13_FOUND_GECK)


#define dude_stat_win(X,Y)                  ((do_check(dude_obj,X,Y)) > (do_check(self_obj,X,0)))
#define dude_stat_lose(X,Y)                 ((do_check(dude_obj,X,Y)) < (do_check(self_obj,X,0)))
#define dude_stat_tie(X,Y)                  ((do_check(dude_obj,X,Y)) == (do_check(self_obj,X,0)))
#define dude_can_see_self                   obj_can_see_obj(dude_obj,self_obj)

#define dude_item(x)                        obj_carrying_pid_obj(dude_obj, x)
#define dude_item_count(x)                  obj_is_carrying_obj_pid(dude_obj, x)

#define dude_is_addict                      (has_trait(TRAIT_TRAIT, dude_obj, TRAIT_drug_addict))

// spouse related
#define spouse_none                       (0)
#define spouse_female                     (1)
#define spouse_male                       (2)
#define dude_spouse_is_male               (global_var(GVAR_PLAYER_MARRIED) == spouse_male)
#define dude_spouse_is_female             (global_var(GVAR_PLAYER_MARRIED) == spouse_female)
#define dude_is_married                   (global_var(GVAR_PLAYER_MARRIED) != spouse_none)
#define set_dude_married                  if ((dude_is_married == false) and (dude_was_married == false)) then begin    \
                                             if (NAME == SCRIPT_MCDAVIN) then begin                                     \
                                                set_global_var(GVAR_PLAYER_MARRIED, spouse_male);                       \
                                             end else if (NAME == SCRIPT_MCMIRIA) then begin                                                             \
                                                set_global_var(GVAR_PLAYER_MARRIED, spouse_female);                     \
                                             end                                                                        \
                                          end                                                                           \
                                          ndebug("set_dude_married")
#define dude_spouse_was_male              (global_var(GVAR_PLAYER_WAS_MARRIED) == spouse_male)
#define dude_spouse_was_female            (global_var(GVAR_PLAYER_WAS_MARRIED) == spouse_female)
#define dude_was_married                  (global_var(GVAR_PLAYER_WAS_MARRIED) != 0)
#define set_dude_was_married              ndebug("start: set_dude_was_married");                                     \
                                          if ((dude_is_married) and (dude_was_married == false)) then begin             \
                                             ndebug("   GVAR_PLAYER_WAS_MARRIED before == " + global_var(GVAR_PLAYER_WAS_MARRIED)); \
                                             set_global_var(GVAR_PLAYER_WAS_MARRIED, global_var(GVAR_PLAYER_MARRIED));  \
                                             ndebug("   GVAR_PLAYER_WAS_MARRIED after == " + global_var(GVAR_PLAYER_WAS_MARRIED));  \
                                             set_global_var(GVAR_PLAYER_MARRIED, spouse_none);                          \
                                          end                                                                           \
                                          ndebug("finished: set_dude_was_married")

/*********************************************************
 General information dealing with a critter script
*********************************************************/
#define self_attack_dude                    if (critter_is_fleeing(self_obj)) then begin        \
                                               if (anim_busy(self_obj) == false) then begin     \
                                                  Flee_From_Dude                                \
                                               end                                              \
                                            end else attack(dude_obj)

// stats
#define self_name                           (obj_name(self_obj))
#define self_gender                         (get_critter_stat(self_obj,STAT_gender))
#define self_strength                       (get_critter_stat(self_obj,STAT_st))
#define self_perception                     (get_critter_stat(self_obj,STAT_pe))
#define self_endurance                      (get_critter_stat(self_obj,STAT_en))
#define self_charisma                       (get_critter_stat(self_obj,STAT_ch))
#define self_iq                             (get_critter_stat(self_obj,STAT_iq))
#define self_agility                        (get_critter_stat(self_obj,STAT_ag))
#define self_luck                           (get_critter_stat(self_obj,STAT_lu))

// more stats
#define get_strength(cr)                    get_critter_stat(cr,STAT_st)
#define get_perception(cr)                  get_critter_stat(cr,STAT_pe)
#define get_endurance(cr)                   get_critter_stat(cr,STAT_en)
#define get_charisma(cr)                    get_critter_stat(cr,STAT_ch)
#define get_iq(cr)                          get_critter_stat(cr,STAT_iq)
#define get_agility(cr)                     get_critter_stat(cr,STAT_ag)
#define get_luck(cr)                        get_critter_stat(cr,STAT_lu)

// gender
#define get_gender(cr)                      get_critter_stat(cr,STAT_gender)
#define is_male(cr)                         (get_gender(cr) == GENDER_MALE)
#define is_female(cr)                       (get_gender(cr) == GENDER_FEMALE)
#define self_is_male                        (self_gender == GENDER_MALE)
#define self_is_female                      (self_gender == GENDER_FEMALE)

#define self_is_armed                       critter_is_armed(self_obj)
#define self_wearing_armor                  critter_wearing_armor(self_obj)

// perks and traits
#define get_perk(cr,perk)                   has_trait(TRAIT_PERK,cr,perk)
#define dude_perk(perk)                     get_perk(dude_obj,perk)
#define self_perk(perk)                     get_perk(self_obj,perk)
#define get_trait(cr,trait)                 has_trait(TRAIT_TRAIT,cr,trait)
#define dude_trait(trait)                   get_trait(dude_obj,trait)
#define self_trait(trait)                   get_trait(self_obj,trait)

#define self_carrying_laser_pistol \
   ((obj_pid(critter_inven_obj(self_obj,INVEN_TYPE_LEFT_HAND)) == PID_LASER_PISTOL) or \
   (obj_pid(critter_inven_obj(self_obj,INVEN_TYPE_RIGHT_HAND)) == PID_LASER_PISTOL))

#define self_is_sneaking                    (using_skill(self_obj,SKILL_SNEAK))
#define self_is_walking                     (art_anim(obj_art_fid(self_obj)) == ANIM_walk)
#define self_is_running                     (art_anim(obj_art_fid(self_obj)) == ANIM_running)
#define self_is_poisoned                    (get_poison(self_obj))

#define self_cur_rot                        (has_trait(TRAIT_OBJECT,self_obj,OBJECT_CUR_ROT))
#define self_inv_rot                        ((self_cur_rot + 3)%6)
#define self_tile                           (tile_num(self_obj))
#define source_tile                         tile_num(source_obj)
#define self_elevation                      (elevation(self_obj))

#define self_pid                            (obj_pid(self_obj))

// team
#define self_team                           has_trait(TRAIT_OBJECT,self_obj,OBJECT_TEAM_NUM)
#define get_team(cr)                        has_trait(TRAIT_OBJECT,cr,OBJECT_TEAM_NUM)
#define set_team(cr,team)                   critter_add_trait(cr,TRAIT_OBJECT,OBJECT_TEAM_NUM,team)
#define set_self_team(team)                 set_team(self_obj,team)

// ai
#define self_ai                             has_trait(TRAIT_OBJECT,self_obj,OBJECT_AI_PACKET)
#define get_ai(cr)                          has_trait(TRAIT_OBJECT,cr,OBJECT_AI_PACKET)
#define set_ai(cr,ai)                       critter_add_trait(cr,TRAIT_OBJECT,OBJECT_AI_PACKET,ai)
#define set_self_ai(ai)                     set_ai(self_obj,ai)

// visibility
#define self_visible                        obj_is_visible_flag(self_obj)
#define set_obj_invisible(cr)               set_obj_visibility(cr,1)
#define set_obj_visible(cr)                 set_obj_visibility(cr,0)
#define set_self_invisible                  set_obj_visibility(self_obj, true)
#define set_self_visible                    set_obj_visibility(self_obj, false)
#define is_visible(cr)                      has_trait(TRAIT_OBJECT,cr,OBJECT_VISIBILITY) // aka obj_is_visible_flag(x)

// hp
#define self_cur_hits                       (get_critter_stat(self_obj,STAT_current_hp))
#define self_max_hits                       (get_critter_stat(self_obj,STAT_max_hp))
#define get_cur_hits(cr)                    get_critter_stat(cr,STAT_current_hp)
#define get_max_hits(cr)                    get_critter_stat(cr,STAT_max_hp)

#define self_mental_block                   (has_trait(TRAIT_PERK,self_obj,PERK_mental_block))
#define self_presence                       (has_trait(TRAIT_PERK,self_obj,PERK_presence))
#define self_awareness                      (has_trait(TRAIT_PERK,self_obj,PERK_bonus_awareness))
#define self_fortune_finder                 (has_trait(TRAIT_PERK,self_obj,PERK_fortune_finder))

#define self_caps                           (item_caps_total(self_obj))
#define self_caps_adjust(caps)              item_caps_adjust(self_obj,caps)

#define self_fid                            (obj_art_fid(self_obj))

#define skill_success(x,y,z)                (is_success(roll_vs_skill(x,y,z)))
#define stat_success(x,y,z)                 (is_success(do_check(x,y,z)))

/**
 * Like `roll_vs_skill`, but for stat roll checks.
 * Because `do_check` can't generate criticals.
 * Returns one of the ROLL_* constants, can be used in `is_critical`.
 * Average luck of 5 provides DnD-like 1/20 chance to upgrade success to critical.
 * For failures, engine doesn't use mods, we follow suit.
 * Maybe Jinxed should work here too.
 * @arg {ObjPtr} who Critter
 * @arg {int} stat STAT_*
 * @arg {int} mod Difficulty mod
 * @ret {int}
 */
procedure roll_vs_stat(variable who, variable stat, variable mod) begin
   variable rnd = random(1, 100);
   variable success = is_success(do_check(who, stat, mod));
   // success
   if success then begin
       // critical
       if (rnd + (get_critter_stat(who, STAT_lu) - 5)) > 95 then return ROLL_CRITICAL_SUCCESS;
       else return ROLL_SUCCESS;
   end else begin // failure
     // critical
     if rnd > 95 then return ROLL_CRITICAL_FAILURE;
   end
   return ROLL_FAILURE;
end

#define self_can_see_dude                   obj_can_see_obj(self_obj,dude_obj)
#define self_can_hear_dude                  obj_can_hear_obj(self_obj,dude_obj)
#define self_distance_from_dude             tile_distance(self_tile, dude_tile)
#define self_is_high                        drug_influence(self_obj)

#define self_item(x)                        obj_carrying_pid_obj(self_obj, x)
#define self_item_count(x)                  obj_is_carrying_obj_pid(self_obj, x)
#define get_item(cr,pid)                    obj_carrying_pid_obj(cr,pid)
#define get_item_count(cr,pid)              obj_is_carrying_obj_pid(cr,pid)

// some timer event macros
#define check_set_obj_visiblility(the_obj, x)       if (obj_is_visible_flag(the_obj) == x) then set_obj_visibility(the_obj, x)

#define flush_add_timer_event(obj, time, param)    rm_fixed_timer_event(obj, param);               \
                                                   add_timer_event(obj, time, param)
#define flush_add_timer_event_sec(obj, sec, param) flush_add_timer_event(obj, game_ticks(sec), param)

/******************************************************************
 General commands getting information about time
******************************************************************/

#define morning                             ((game_time_hour >= 600) and  (game_time_hour < 700))
#ifndef day
#define day                                 ((game_time_hour >= 700) and  (game_time_hour < 1800))
#endif
#define evening                             ((game_time_hour >= 1800) and (game_time_hour < 1900))
#ifndef night
#define night                               ((game_time_hour >= 1900) or  (game_time_hour < 600))
#endif

#define GAME_TIME_SUBSECOND_RESOLUTION  (10)
#define SECONDS_PER_MINUTE              (60)
#define MINUTES_PER_HOUR                (60)
#define HOURS_PER_DAY                   (24)
#define DAYS_PER_YEAR                   (365)
                                // Seconds Minutes Hours Days Months ==> Year
#define GAME_TIME_IN_YEARS   (game_time / (GAME_TIME_SUBSECOND_RESOLUTION * SECONDS_PER_MINUTE * MINUTES_PER_HOUR * HOURS_PER_DAY * DAYS_PER_YEAR))
#define GAME_TIME_IN_DAYS    (game_time / (GAME_TIME_SUBSECOND_RESOLUTION * 60 * 60 * 24))
#define GAME_TIME_IN_HOURS   (game_time / (GAME_TIME_SUBSECOND_RESOLUTION * SECONDS_PER_MINUTE * MINUTES_PER_HOUR))
#define GAME_TIME_IN_MINUTES (game_time / (GAME_TIME_SUBSECOND_RESOLUTION * SECONDS_PER_MINUTE))
#define GAME_TIME_IN_SECONDS (game_time / GAME_TIME_SUBSECOND_RESOLUTION)


#define ticks_til_hour(x)                 ((ONE_GAME_DAY * (game_time_hour > (x))) + ((((x)/100) - (game_time_hour/100)) * ONE_GAME_HOUR) + ((((x)%100) - (game_time_hour%100)) * ONE_GAME_MINUTE))
#define game_time_advance_hour(x)         game_time_advance(ticks_til_hour(x))

// use times in define.h for passed_time(example: ONE_GAME_DAY)
#define time_has_passed(old_time, passed_time)      ((passed_time + old_time) <= game_time)
// get the actual amout of time that has passed
#define amt_time_has_passed(old_time, time_unit)  ((game_time - old_time) / time_unit)

#define one_second_passed(old_time)       time_has_passed(old_time,ONE_GAME_SECOND)
#define one_minute_passed(old_time)       time_has_passed(old_time,ONE_GAME_MINUTE)
#define one_hour_passed(old_time)         time_has_passed(old_time,ONE_GAME_HOUR)
#define one_day_passed(old_time)          time_has_passed(old_time,ONE_GAME_DAY)
#define one_week_passed(old_time)         time_has_passed(old_time,ONE_GAME_WEEK)
#define one_month_passed(old_time)        time_has_passed(old_time,ONE_GAME_MONTH)

/***************************************************************
****************  Dialogue Information   ***********************
***************************************************************/
#ifndef floater
   #define floater(x)           float_msg(self_obj, message_str(NAME,x), FLOAT_COLOR_NORMAL)
#endif
#define floater_rand(x,y)       floater(random(x,y))

#define dude_floater(x)         float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_NORMAL)
#define dude_floater_rand(x,y)  dude_floater(random(x,y))
#define dude_floater_bad(x)     float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_BAD)
#define dude_floater_sick(x)    float_msg(dude_obj, message_str(NAME,x), FLOAT_COLOR_SICK)

variable in_dialog;
variable forced_node;
#define start_dialog_at_node(x)                       if (in_dialog == false) then begin           \
                                                         in_dialog := true;                        \
                                                         start_gdialog(NAME,self_obj,4,-1,-1);     \
                                                         gSay_Start;                               \
                                                            call x;                                \
                                                         gSay_End;                                 \
                                                         end_dialogue;                             \
                                                         in_dialog := false;                       \
                                                      end else call x

#define force_dialog_start(the_node)            ndebug("force_dialog_start("+forced_node+"): "+self_name);  \
                                                      forced_node := the_node;                                    \
                                                      dialogue_system_enter

#define check_forced_dialog                           if (forced_node != 0) then begin          \
                                                         ndebug("calling forced dialog: "+forced_node);\
                                                         start_dialog_at_node(forced_node);     \
                                                         forced_node := 0;                      \
                                                      end

/*
FLOAT_MSG_BLACK
FLOAT_MSG_PURPLE
FLOAT_MSG_NEAR_WHITE
FLOAT_MSG_BLUE
*/
#define FLOAT_COLOR_NORMAL          FLOAT_MSG_YELLOW
#define FLOAT_COLOR_SICK            FLOAT_MSG_GREEN
#define FLOAT_COLOR_BAD             FLOAT_MSG_RED
#define FLOAT_COLOR_GOOD            FLOAT_MSG_WHITE
#define FLOAT_COLOR_SFX             FLOAT_MSG_LIGHT_GREY
#define FLOAT_COLOR_SAD             FLOAT_MSG_GREY
#define FLOAT_COLOR_AFRAID          FLOAT_MSG_LIGHT_RED
#define FLOAT_COLOR_PAIN            FLOAT_MSG_LIGHT_GREY
#define FLOAT_COLOR_HIGH            FLOAT_MSG_PURPLE
#define FLOAT_COLOR_WHISPER         FLOAT_MSG_GREY

#define obj_floater_type(z,x,type)  float_msg(z, x, FLOAT_COLOR_NORMAL + ((type - FLOAT_COLOR_NORMAL) * has_trait(TRAIT_PERK, dude_obj, PERK_empathy)))
#define floater_type_msg(x, type)   obj_floater_type(self_obj, x, type)
#define floater_type(x, type)       floater_type_msg(mstr(x), type)
#define floater_bad(x)              floater_type(x, FLOAT_COLOR_BAD)
#define floater_bad_rand(x,y)       floater_bad(random(x,y))
#define floater_sick(x)             floater_type(x, FLOAT_COLOR_SICK)
#define floater_sick_rand(x,y)      floater_sick(random(x,y))
#define floater_afraid(x)           floater_type(x, FLOAT_COLOR_AFRAID)
#define floater_afraid_rand(x,y)    floater_afraid(random(x,y))
#define floater_high(x)             floater_type(x, FLOAT_COLOR_HIGH)
#define floater_high_rand(x,y)      floater_high(random(x,y))
#define floater_good(x)             floater_type(x, FLOAT_COLOR_GOOD)
#define floater_good_rand(x,y)      floater_good(random(x,y))

#define mstr(x)                     message_str(NAME,x)
#define display_mstr(x)             display_msg(mstr(x))
#define g_mstr(x)                   message_str(SCRIPT_GENERIC,x)
#define g_grunt                     g_mstr(random(300,303))
#define g_bye                       g_mstr(random(375,376))

#define LOW_IQ                      (-3)

#define Reply(x)                    gSay_Reply(NAME,x)
#define Reply_Rand(x,y)             Reply(random(x,y))
#define GMessage(x)                 gSay_Message(NAME,x,GOOD_REACTION)
#define NMessage(x)                 gSay_Message(NAME,x,NEUTRAL_REACTION)
#define BMessage(x)                 gSay_Message(NAME,x,BAD_REACTION)

// this converts a number from 0-100 to the text representing the number, ie: 1 -> "one", 40 -> "forty-one"
#define num_to_num_text(x)          g_mstr(2000+x)

// Option(Message Number, Node Number, IQ)         ==>     giQ_Option(IQ, Message Number, Node Number)      -rwh2 (11/12/97)
#define GOption(x,y,z)              giQ_Option(z,NAME,x,y,GOOD_REACTION)
#define NOption(x,y,z)              giQ_Option(z,NAME,x,y,NEUTRAL_REACTION)
#define BOption(x,y,z)              giQ_Option(z,NAME,x,y,BAD_REACTION)
#define GLowOption(x,y)             giQ_Option(LOW_IQ,NAME,x,y,GOOD_REACTION)
#define NLowOption(x,y)             giQ_Option(LOW_IQ,NAME,x,y,NEUTRAL_REACTION)
#define BLowOption(x,y)             giQ_Option(LOW_IQ,NAME,x,y,BAD_REACTION)

#define display_mstr_rand(x,y)      display_msg(mstr(random(x,y)))

/***************************************************************
****************  Global Variable commands *********************
***************************************************************/
#define inc_global_var_amt(x,y)     set_global_var(x,global_var(x)+y)
#define inc_global_var(x)           inc_global_var_amt(x,1)
#define dec_global_var_amt(x,y)     set_global_var(x,global_var(x)-y)
#define dec_global_var(x)           dec_global_var_amt(x,1)

/***************************************************************
****************  map Variable commands ************************
***************************************************************/
#define inc_map_var_amt(x,y)        set_map_var(x,map_var(x)+y)
#define inc_map_var(x)              inc_map_var_amt(x,1)
#define dec_map_var_amt(x,y)        set_map_var(x,map_var(x)-y)
#define dec_map_var(x)              dec_map_var_amt(x,1)

/***************************************************************
****************  Local Variable commands **********************
***************************************************************/
#define inc_local_var_amt(x,y)      set_local_var(x,local_var(x)+y)
#define inc_local_var(x)            inc_local_var_amt(x,1)
#define dec_local_var_amt(x,y)      set_local_var(x,local_var(x)-y)
#define dec_local_var(x)            dec_local_var_amt(x,1)

/***************************************************************
**************** Bit Manipulation Macros ***********************
***************************************************************/
#define MAXINT 4294967295                 //Max int
#define INV(x) (MAXINT - x)               //An inverse function

// get bit state
#define gvar_bit(x, the_bit)                          ((global_var(x) bwand the_bit) != 0)
#define mvar_bit(x, the_bit)                          ((map_var(x) bwand the_bit) != 0)
#define lvar_bit(x, the_bit)                          ((local_var(x) bwand the_bit) != 0)

// switch bit on
#define set_gvar_bit_on(x, the_bit)                   set_global_var(x, global_var(x) bwor the_bit)
#define set_mvar_bit_on(x, the_bit)                   set_map_var(x, map_var(x) bwor the_bit)
#define set_lvar_bit_on(x, the_bit)                   set_local_var(x, local_var(x) bwor the_bit)

// switch bit off
#define set_gvar_bit_off(x, the_bit)                  set_global_var(x, global_var(x) bwand INV(the_bit))
#define set_mvar_bit_off(x, the_bit)                  set_map_var(x, map_var(x) bwand INV(the_bit))
#define set_lvar_bit_off(x, the_bit)                  set_local_var(x, local_var(x) bwand INV(the_bit))

// truncates a number
#define trunc(x)                (x * -(x<1))

/******************************************************************
 General commands setting and getting the map exit
******************************************************************/
// note set either exit or next to 0 for invalid
#define set_map_exit_tiles(the_exit,the_next)     set_global_var(GVAR_MAP_EXIT_TILE,the_exit);  set_global_var(GVAR_MAP_NEXT_TILE,the_next)
#define map_exit_tile                             (global_var(GVAR_MAP_EXIT_TILE))
#define map_next_tile                             (global_var(GVAR_MAP_NEXT_TILE))

/******************************************************************
 General commands for checking and changing status variables
         note: variable needs to be global for the functions to work
         note: the defines for the status's are in GLOBAL.H
******************************************************************/
#define change_status_on(status_var, which_status)    set_gvar_bit_on(status_var, which_status);
#define change_status_off(status_var, which_status)   set_gvar_bit_off(status_var, which_status);

#define set_status_known(status_var)                  change_status_on(status_var, PERSON_KNOWN)
#define set_status_attacked(status_var)               change_status_on(status_var, PERSON_ATTACKED)
#define set_status_killed(status_var)                 change_status_on(status_var, PERSON_KILLED)
#define set_status_assassinated(status_var)           change_status_on(status_var, PERSON_ASSASSINATED)
#define set_status_dead(status_var)                   change_status_on(status_var, PERSON_DEAD)
#define set_status_spoken_to(status_var)              change_status_on(status_var, PERSON_SPOKEN_TO)
#define set_status_spoken_to_special(status_var)      change_status_on(status_var, PERSON_SPOKEN_TO_SPECIAL)
#define set_status_special(status_var)                change_status_on(status_var, PERSON_SPECIAL)
#define set_status_special_2(status_var)              change_status_on(status_var, PERSON_SPECIAL_2)
#define set_status_in_party(status_var)               change_status_on(status_var, PERSON_IN_PARTY)
#define set_status_not_in_party(status_var)           change_status_off(status_var, PERSON_IN_PARTY)
#define set_status_warned(status_var)                 change_status_on(status_var, PERSON_WARNED)
#define set_status_sex(status_var)                    change_status_on(status_var, PERSON_SEX)

#define status_is(status_var, check_status)           (gvar_bit(status_var, check_status))

#define status_is_known(status_var)                   (status_is(status_var, PERSON_KNOWN))
#define status_is_unknown(status_var)                 (status_is_known(status_var) == false)
#define status_is_attacked(status_var)                (status_is(status_var, PERSON_ATTACKED))
#define status_is_killed(status_var)                  (status_is(status_var, PERSON_KILLED))
#define status_is_assassinated(status_var)            (status_is(status_var, PERSON_ASSASSINATED))
#define status_is_dead(status_var)                    (status_is(status_var, PERSON_DEAD))
#define status_is_spoken_to(status_var)               (status_is(status_var, PERSON_SPOKEN_TO))
#define status_is_spoken_to_special(status_var)       (status_is(status_var, PERSON_SPOKEN_TO_SPECIAL))
#define status_is_special(status_var)                 (status_is(status_var, PERSON_SPECIAL))
#define status_is_special_2(status_var)               (status_is(status_var, PERSON_SPECIAL_2))
#define status_is_in_party(status_var)                (status_is(status_var, PERSON_IN_PARTY))
#define status_is_not_in_party(status_var)            (status_is(status_var, PERSON_IN_PARTY) == false)
#define status_is_warned(status_var)                  (status_is(status_var, PERSON_WARNED))
#define status_is_sex(status_var)                     (status_is(status_var, PERSON_SEX))

#define status_is_alive(status_var)                   (not (status_is_killed(status_var) or status_is_assassinated(status_var) or status_is_dead(status_var)))


/******************************************************************
 General commands getting information about cities
******************************************************************/
#define abbey_visible_on_map                (town_known(AREA_ABBEY) != MARK_STATE_UNKNOWN)
#define arroyo_visible_on_map               (town_known(AREA_ARROYO) != MARK_STATE_UNKNOWN)
#define broken_hills_visible_on_map         (town_known(AREA_BROKEN_HILLS) != MARK_STATE_UNKNOWN)
#define colusa_visible_on_map               (town_known(AREA_NAVARRO) != MARK_STATE_UNKNOWN)
#define den_visible_on_map                  (town_known(AREA_DEN) != MARK_STATE_UNKNOWN)
#define enclave_visible_on_map              (town_known(AREA_THE_ENCLAVE) != MARK_STATE_UNKNOWN)
#define EPA_visible_on_map                  (town_known(AREA_EPA) != MARK_STATE_UNKNOWN)
#define gecko_visible_on_map                (town_known(AREA_GECKO) != MARK_STATE_UNKNOWN)
#define klamath_visible_on_map              (town_known(AREA_KLAMATH) != MARK_STATE_UNKNOWN)
#define military_base_visible_on_map        (town_known(AREA_MILITARY_BASE) != MARK_STATE_UNKNOWN)
#define modoc_visible_on_map                (town_known(AREA_MODOC) != MARK_STATE_UNKNOWN)
#define new_CA_republic_visible_on_map      (town_known(AREA_NCR) != MARK_STATE_UNKNOWN)
#define primitive_tribe_visible_on_map      (town_known(AREA_PRIMITIVE_TRIBE) != MARK_STATE_UNKNOWN)
#define redding_visible_on_map              (town_known(AREA_REDDING) != MARK_STATE_UNKNOWN)
#define new_reno_visible_on_map             (town_known(AREA_NEW_RENO) != MARK_STATE_UNKNOWN)
#define san_francisco_visible_on_map        (town_known(AREA_SAN_FRANCISCO) != MARK_STATE_UNKNOWN)
#define sierra_army_base_visible_on_map     (town_known(AREA_SIERRA_ARMY_BASE) != MARK_STATE_UNKNOWN)
#define vault_13_visible_on_map             (town_known(AREA_VAULT_13) != MARK_STATE_UNKNOWN)
#define vault_15_visible_on_map             (town_known(AREA_VAULT_15) != MARK_STATE_UNKNOWN)
#define vault_city_visible_on_map           (town_known(AREA_VAULT_CITY) != MARK_STATE_UNKNOWN)
#define vault_fake_13A_visible_on_map       (town_known(AREA_FAKE_VAULT_13A) != MARK_STATE_UNKNOWN)
#define vault_fake_13B_visible_on_map       (town_known(AREA_FAKE_VAULT_13B) != MARK_STATE_UNKNOWN)

#define abbey_visit                         (town_known(AREA_ABBEY) == MARK_STATE_VISITED)
#define arroyo_visit                        (town_known(AREA_ARROYO) == MARK_STATE_VISITED)
#define broken_hills_visit                  (town_known(AREA_BROKEN_HILLS) == MARK_STATE_VISITED)
#define colusa_visit                        (town_known(AREA_NAVARRO) == MARK_STATE_VISITED)
#define den_visit                           (town_known(AREA_DEN) == MARK_STATE_VISITED)
#define enclave_visit                       (town_known(AREA_THE_ENCLAVE) == MARK_STATE_VISITED)
#define EPA_visit                           (town_known(AREA_EPA) == MARK_STATE_VISITED)
#define gecko_visit                         (town_known(AREA_GECKO) == MARK_STATE_VISITED)
#define klamath_visit                       (town_known(AREA_KLAMATH) == MARK_STATE_VISITED)
#define military_base_visit                 (town_known(AREA_MILITARY_BASE) == MARK_STATE_VISITED)
#define modoc_visit                         (town_known(AREA_MODOC) == MARK_STATE_VISITED)
#define new_CA_republic_visit               (town_known(AREA_NCR) == MARK_STATE_VISITED)
#define primitive_tribe_visit               (town_known(AREA_PRIMITIVE_TRIBE) == MARK_STATE_VISITED)
#define redding_visit                       (town_known(AREA_REDDING) == MARK_STATE_VISITED)
#define new_reno_visit                      (town_known(AREA_NEW_RENO) == MARK_STATE_VISITED)
#define san_francisco_visit                 (town_known(AREA_SAN_FRANCISCO) == MARK_STATE_VISITED)
#define sierra_army_base_visit              (town_known(AREA_SIERRA_ARMY_BASE) == MARK_STATE_VISITED)
#define vault_13_visit                      (town_known(AREA_VAULT_13) == MARK_STATE_VISITED)
#define vault_15_visit                      (town_known(AREA_VAULT_15) == MARK_STATE_VISITED)
#define vault_city_visit                    (town_known(AREA_VAULT_CITY) == MARK_STATE_VISITED)
#define arroyo_destroyed_visit              (town_known(AREA_ARROYO_DESTROYED) == MARK_STATE_VISITED)
#define vault_fake_13A_visit                (town_known(AREA_FAKE_VAULT_13A) == MARK_STATE_VISITED)
#define vault_fake_13B_visit                (town_known(AREA_FAKE_VAULT_13B) == MARK_STATE_VISITED)

#define mark_on_map(x)                      if (town_known(x) == MARK_STATE_UNKNOWN) then begin          \
                                               ndebug("  mark_on_map("+x+")");                        \
                                               mark_area_known(MARK_TYPE_TOWN, x, MARK_STATE_KNOWN);     \
                                            end

#define unmark_on_map(x)                    if (town_known(x) != MARK_STATE_UNKNOWN) then begin          \
                                               ndebug(" unmark_on_map("+x+")");                       \
                                               mark_area_known(MARK_TYPE_TOWN, x, MARK_STATE_UNKNOWN);   \
                                            end

#define mark_abbey_on_map                   mark_on_map(AREA_ABBEY)
#define mark_arroyo_on_map                  mark_on_map(AREA_ARROYO)
#define mark_broken_hills_on_map            mark_on_map(AREA_BROKEN_HILLS)
#define mark_colusa_on_map                  mark_on_map(AREA_NAVARRO)
#define mark_navarro_on_map                 mark_on_map(AREA_NAVARRO)
#define mark_den_on_map                     mark_on_map(AREA_DEN)
#define mark_enclave_on_map                 mark_on_map(AREA_THE_ENCLAVE)
#define mark_EPA_on_map                     mark_on_map(AREA_EPA)
#define mark_gecko_on_map                   mark_on_map(AREA_GECKO)
#define mark_klamath_on_map                 mark_on_map(AREA_KLAMATH)
#define mark_military_base_on_map           mark_on_map(AREA_MILITARY_BASE)
#define mark_modoc_on_map                   mark_on_map(AREA_MODOC)
#define mark_new_CA_republic_on_map         mark_on_map(AREA_NCR)
#define mark_primitive_tribe_on_map         mark_on_map(AREA_PRIMITIVE_TRIBE)
#define mark_redding_on_map                 mark_on_map(AREA_REDDING)
#define mark_new_reno_on_map                mark_on_map(AREA_NEW_RENO)
#define mark_san_francisco_on_map           mark_on_map(AREA_SAN_FRANCISCO)
#define mark_sierra_army_base_on_map        mark_on_map(AREA_SIERRA_ARMY_BASE)
#define mark_vault_13_on_map                mark_on_map(AREA_VAULT_13)
#define mark_vault_15_on_map                mark_on_map(AREA_VAULT_15)
#define mark_vault_city_on_map              mark_on_map(AREA_VAULT_CITY)
#define mark_vault_fake_13A_on_map          mark_on_map(AREA_FAKE_VAULT_13A)
#define mark_vault_fake_13B_on_map          mark_on_map(AREA_FAKE_VAULT_13B)

#define unmark_vault_fake_13A_on_map        unmark_on_map(AREA_FAKE_VAULT_13A)

/******************************************************************
 General commands STOMACH(ha stomach, ha ha ha) info
******************************************************************/
// these are the different amounts food fills the stomach
#define starting_stomach_full          (75)
#define drink_meal                     (5)
#define snack_meal                     (10)
#define light_meal                     (25)
#define medium_meal                    (50)
#define large_meal                     (75)
#define huge_meal                      (90)
// these are macros for dealing with the stomach
#define max_stomach_size               (100 + (2 * (dude_endurance - 10)))
#define dude_stomach_amt               (global_var(GVAR_DUDE_STOMACH))
#define dude_can_eat_food(amt)         ((dude_stomach_amt + amt) <= max_stomach_size)
#define dude_eat_food(amt)             inc_global_var_amt(GVAR_DUDE_STOMACH, amt); /* Seraph's Fix: changed 'inc_global_var' to inc_global_var_amt */\
                                       if (global_var(GVAR_DUDE_STOMACH) < 0) then                         \
                                          set_global_var(GVAR_DUDE_STOMACH,0);                             \
                                       else if (global_var(GVAR_DUDE_STOMACH) > max_stomach_size) then     \
                                          set_global_var(GVAR_DUDE_STOMACH,max_stomach_size)
#define dude_stomach_percent_full      ((100 * dude_stomach_amt) / max_stomach_size)
#define dude_stomach_full              (dude_stomach_percent_full >= 95)
#define dude_stomach_hungry            (dude_stomach_percent_full <= 5)
#define dude_can_eat(x)                ((dude_stomach_amt + x) <= max_stomach_size)
// these are so that a pid can be compared to see which food class it is
#define pid_is_drink_pid(x)            ((x==PID_NUKA_COLA) or (x==PID_BEER) or (x==PID_BOOZE) or (x==PID_WATER_FLASK))
#define pid_is_snack_pid(x)            ((x==PID_IGUANA_ON_A_STICK) or (x==PID_MEAT_ON_A_STICK))
#define pid_is_light_meal_pid(x)       ((x==PID_BOX_OF_NOODLES) or (x==PID_FROZEN_DINNER))
#define pid_is_medium_meal(x)          false    // this is because we don't have any generic items that qualify
#define pid_is_large_meal(x)           false    // this is because we don't have any generic items that qualify
#define pid_is_huge_meal(x)            false    // this is because we don't have any generic items that qualify
#define dude_has_fast_metabolism       (has_trait(TRAIT_OBJECT,dude_obj,TRAIT_fast_metabolism))
#define amt_food_digested_in_time(x)   (((1 + dude_has_fast_metabolism) * (game_time - x)) / (ONE_GAME_MINUTE * 3))

/******************************************************************
 General commands restocking inventory
 note: this is generally placed in the "box" of a merchant to refil it every so once in a while
       only call this when it's time to restock the "box"... see "diTubBox.ssl" for a hint
       but most of all, have fun, remember, fun
******************************************************************/
variable restock_amt;
variable restock_obj;
variable restock_trash;
variable removed_qty;
#define transfer_pid_between_objs(source, target, the_pid, qty)                           \
         restock_amt := qty;                                                              \
         if (obj_is_carrying_obj_pid(source, the_pid) < qty) then begin                   \
            restock_amt := obj_is_carrying_obj_pid(source, the_pid);                      \
         end                                                                              \
         if (restock_amt > 0) then begin                                                  \
            restock_obj := obj_carrying_pid_obj(source, the_pid);                         \
            restock_trash := rm_mult_objs_from_inven(source, restock_obj, restock_amt);   \
            add_mult_objs_to_inven(target, restock_obj, restock_amt);                     \
         end

#define transfer_all_pid_between_objs(source, target, the_pid)                            \
         restock_amt := obj_is_carrying_obj_pid(source, the_pid);                         \
         if (restock_amt > 0) then begin                                                  \
            restock_obj := obj_carrying_pid_obj(source, the_pid);                         \
            restock_trash := rm_mult_objs_from_inven(source, restock_obj, restock_amt);   \
            add_mult_objs_to_inven(target, restock_obj, restock_amt);                     \
         end

#define give_pid_qty(who_obj, the_pid, pid_qty)                                           \
           restock_obj := create_object(the_pid,0,0);                                     \
           add_mult_objs_to_inven(who_obj, restock_obj, (pid_qty));

#define remove_armor(who_obj)                                                                            \
            if (critter_wearing_armor(who_obj)) then begin                                               \
               restock_obj := critter_inven_obj(who_obj,INVEN_TYPE_WORN);                                \
               ndebug("armour pid == "+obj_pid(restock_obj));                                         \
               rm_obj_from_inven(who_obj, restock_obj);                                                  \
               add_obj_to_inven(who_obj, restock_obj);                                                   \
            end

#define remove_pid_qty(who_obj, the_pid, pid_qty)                                            \
           removed_qty := obj_is_carrying_obj_pid(who_obj,the_pid);                          \
           if ((pid_qty) < removed_qty) then begin                                           \
              removed_qty := pid_qty;                                                        \
           end                                                                               \
           if (removed_qty > 0) then begin                                                   \
              restock_obj := obj_carrying_pid_obj(who_obj, the_pid);                         \
              if (obj_type(self_obj) == 1) then begin                                        \
                 restock_obj := obj_carrying_pid_obj(who_obj, the_pid);                      \
                 if (critter_inven_obj(self_obj,INVEN_TYPE_WORN) == restock_obj) then begin  \
                    remove_armor(who_obj)                                                    \
                 end else if ((critter_inven_obj(who_obj, INVEN_TYPE_LEFT_HAND) == restock_obj) or (critter_inven_obj(who_obj, INVEN_TYPE_RIGHT_HAND) == restock_obj)) then begin     \
                    inven_unwield(who_obj);                                                  \
                 end                                                                         \
              end                                                                            \
              restock_amt := rm_mult_objs_from_inven(who_obj, restock_obj, removed_qty);     \
              destroy_object(restock_obj);                                                   \
           end                                                                               \
           restock_obj := 0;                                                                 \
           restock_amt := 0;

#define stock_pid_qty(who_obj, the_pid, pid_qty)                                                   \
        if (obj_is_carrying_obj_pid(who_obj,the_pid) < pid_qty) then begin                         \
           give_pid_qty(self_obj, the_pid, pid_qty - obj_is_carrying_obj_pid(who_obj,the_pid))     \
        end else if (obj_is_carrying_obj_pid(who_obj,the_pid) > pid_qty) then begin                \
           remove_pid_qty(who_obj, the_pid, (obj_is_carrying_obj_pid(who_obj,the_pid) - pid_qty))  \
        end else begin                                                                             \
           restock_obj := 0;                                                                       \
        end

#define check_restock_item(the_item, min_amt, max_amt, res_perc)                    \
        restock_amt := random(min_amt, max_amt);                                    \
        if (obj_is_carrying_obj_pid(self_obj, the_item) < restock_amt) then begin   \
            if (res_perc >= random(1,100)) then begin                               \
               stock_pid_qty(self_obj, the_item, restock_amt)                       \
            end                                                                     \
        end else begin                                                              \
           stock_pid_qty(self_obj, the_item, restock_amt)                           \
        end
#define check_restock_item_min_limit(the_item, min_amt, max_amt, res_perc)          \
        if (obj_is_carrying_obj_pid(self_obj, the_item) < min_amt) then begin       \
           check_restock_item(the_item, min_amt, max_amt, res_perc)                 \
        end

/******************************************************************
 general macros for arming an object
 note: passing 0 through to the special_ammo_pid will give ammo of the lowest possible damage type
******************************************************************/
#define give_obj_weapon(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty, wield_me)       \
        stock_pid_qty(who_obj, weapon_pid, weapon_qty)                                       \
        if (wield_me) then begin                                                             \
           if (obj_is_carrying_obj_pid(who_obj, weapon_pid)) then begin                      \
              wield_obj_critter(who_obj, obj_carrying_pid_obj(who_obj, weapon_pid));         \
           end else begin                                                                    \
              ndebug("NOT ARMING THE WEAPON!!!");                                            \
           end                                                                               \
        end                                                                                  \
        if (ammo_pid != 0) then begin                                                        \
           stock_pid_qty(who_obj, ammo_pid, ammo_qty)                                        \
        end else begin                                                                       \
           if ((weapon_pid == PID_10MM_PISTOL) or                                            \
               (weapon_pid == PID_ZIP_GUN) or                                                \
               (weapon_pid == PID_10MM_SMG)) then begin                                      \
              stock_pid_qty(who_obj, PID_10MM_JHP, ammo_qty)                                 \
           end else if ((weapon_pid == PID_HUNTING_RIFLE) or                                 \
                        (weapon_pid == PID_BOZAR) or                                         \
                        (weapon_pid == PID_LIGHT_SUPPORT_WEAPON) or                          \
                        (weapon_pid == PID_SNIPER_RIFLE) or                                  \
                        (weapon_pid == PID_223_PISTOL) or                                    \
                        (weapon_pid == PID_SCOPED_HUNTING_RIFLE)) then begin                 \
              stock_pid_qty(who_obj, PID_223_FMJ, ammo_qty)                                  \
           end else if ((weapon_pid == PID_FLAMER) or                                        \
                        (weapon_pid == PID_IMPROVED_FLAMETHROWER)) then begin                \
              stock_pid_qty(who_obj, PID_FLAMETHROWER_FUEL, ammo_qty)                        \
           end else if ((weapon_pid == PID_MINIGUN) or                                       \
                        (weapon_pid == PID_INDEPENDENT) or                                   \
                        (weapon_pid == PID_AVENGER_MINIGUN) or                               \
                        (weapon_pid == PID_ASSAULT_RIFLE_EXT_MAG) or                         \
                        (weapon_pid == PID_ASSAULT_RIFLE)) then begin                        \
              stock_pid_qty(who_obj, PID_5MM_JHP, ammo_qty)                                  \
           end else if (weapon_pid == PID_ROCKET_LAUNCHER) then begin                        \
              stock_pid_qty(who_obj, PID_EXPLOSIVE_ROCKET, ammo_qty)                         \
           end else if ((weapon_pid == PID_PLASMA_RIFLE) or                                  \
                        (weapon_pid == PID_YK42B_PULSE_RIFLE) or                             \
                        (weapon_pid == PID_GATLING_LASER) or                                 \
                        (weapon_pid == PID_LASER_RIFLE) or                                   \
                        (weapon_pid == PID_LASER_RIFLE_EXT_CAP) or                           \
                        (weapon_pid == PID_TURBO_PLASMA_RIFLE)) then begin                   \
              stock_pid_qty(who_obj, PID_MICRO_FUSION_CELL, ammo_qty)                        \
           end else if ((weapon_pid == PID_LASER_PISTOL) or                                  \
                        (weapon_pid == PID_POWER_FIST) or                                    \
                        (weapon_pid == PID_MEGA_POWER_FIST) or                               \
                        (weapon_pid == PID_RIPPER) or                                        \
                        (weapon_pid == PID_CATTLE_PROD) or                                   \
                        (weapon_pid == PID_SUPER_CATTLE_PROD) or                             \
                        (weapon_pid == PID_PLASMA_PISTOL) or                                 \
                        (weapon_pid == PID_PLASMA_PISTOL_EXT_CART) or                        \
                        (weapon_pid == PID_PHAZER) or                                        \
                        (weapon_pid == PID_YK32_PULSE_PISTOL) or                             \
                        (weapon_pid == PID_ALIEN_LASER_PISTOL) or                            \
                        (weapon_pid == PID_MAGNETO_LASER_PISTOL)) then begin                 \
              stock_pid_qty(who_obj, PID_SMALL_ENERGY_CELL, ammo_qty)                        \
           end else if ((weapon_pid == PID_DESERT_EAGLE) or                                  \
                        (weapon_pid == PID_44_MAGNUM_SPEEDLOADER) or                         \
                        (weapon_pid == PID_DESERT_EAGLE_EXT_MAG) or                          \
                        (weapon_pid == PID_44_MAGNUM_REVOLVER)) then begin                   \
              stock_pid_qty(who_obj, PID_44_MAGNUM_JHP, ammo_qty)                            \
           end else if (weapon_pid == PID_14MM_PISTOL) then begin                            \
              stock_pid_qty(who_obj, PID_14MM_AP, ammo_qty)                                  \
           end else if ((weapon_pid == PID_SHOTGUN) or                                       \
                        (weapon_pid == PID_PANCOR_JACKHAMMER) or                             \
                        (weapon_pid == PID_SAWED_OFF_SHOTGUN) or                             \
                        (weapon_pid == PID_COMBAT_SHOTGUN) or                                \
                        (weapon_pid == PID_HK_CAWS)) then begin                              \
              stock_pid_qty(who_obj, PID_SHOTGUN_SHELLS, ammo_qty)                           \
           end else if (weapon_pid == PID_9MM_MAUSER) then begin                             \
              stock_pid_qty(who_obj, PID_9MM_BALL, ammo_qty)                                 \
           end else if (weapon_pid == PID_HK_P90C) then begin                                \
              stock_pid_qty(who_obj, PID_9MM_AMMO, ammo_qty)                                 \
           end else if (weapon_pid == PID_ROBO_ROCKET_LAUNCHER) then begin                   \
              stock_pid_qty(who_obj, PID_ROBO_ROCKET_AMMO, ammo_qty)                         \
           end else if (weapon_pid == PID_SPRINGER_RIFLE) then begin                         \
              stock_pid_qty(who_obj, PID_ROCK, ammo_qty)                                     \
           end else if ((weapon_pid == PID_RED_RYDER_BB_GUN) or                              \
                        (weapon_pid == PID_RED_RYDER_LE_BB_GUN) or                           \
                        (weapon_pid == PID_JONNY_BB_GUN)) then begin                         \
              stock_pid_qty(who_obj, PID_BBS, ammo_qty)                                      \
           end else if ((weapon_pid == PID_TOMMY_GUN) or                                     \
                        (weapon_pid == PID_GREASE_GUN)) then begin                           \
              stock_pid_qty(who_obj, PID_45_CALIBER_AMMO, ammo_qty)                          \
           end else if ((weapon_pid == PID_FN_FAL) or                                        \
                        (weapon_pid == PID_FN_FAL_NIGHT_SCOPE) or                            \
                        (weapon_pid == PID_M60)) then begin                                  \
              stock_pid_qty(who_obj, PID_7_62MM_AMMO, ammo_qty)                              \
           end else if ((weapon_pid == PID_M72_GAUSS_RIFLE) or                               \
                        (weapon_pid == PID_PK12_GAUSS_PISTOL)) then begin                    \
              stock_pid_qty(who_obj, PID_2MM_EC_AMMO, ammo_qty)                              \
           end else if ((weapon_pid == PID_HK_G11) or                                        \
                        (weapon_pid == PID_HK_G11E) or                                       \
                        (weapon_pid == PID_VINDICATOR_MINIGUN)) then begin                   \
              stock_pid_qty(who_obj, PID_4_7MM_CASELESS, ammo_qty)                           \
           end else if (weapon_pid == PID_NEEDLER_PISTOL) then begin                         \
              stock_pid_qty(who_obj, PID_HN_NEEDLER_CARTRIDGE, ammo_qty)                     \
           end                                                                               \
        end

#define arm_obj(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty)                give_obj_weapon(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty, true)
#define stock_weapon_obj(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty)       give_obj_weapon(who_obj, weapon_pid, weapon_qty, ammo_pid, ammo_qty, false)

/******************************************************************
 general macros/defines related to having sex
******************************************************************/
// is_sex_god is temporary for when the player gets the sex perk ***
#define is_sex_god               ((global_var(GVAR_PLAYER_SEX_LEVEL)>=100) or (dude_has_porn_star_rep))
#define have_sex_time_obj(x)     (((get_critter_stat(x,STAT_en)) * random(4,8)) * ONE_GAME_MINUTE)
#define have_quickie_time_obj(x) (((get_critter_stat(x,STAT_en)) * random(2,4)) * ONE_GAME_MINUTE)
#define have_sex_time            have_sex_time_obj(dude_obj)
#define advance_sex_time         game_time_advance(have_sex_time)
// these are to be compared to sex_rating
#define sex_rating_great         (9)
#define sex_rating_good          (7)
#define sex_rating_normal        (5)
#define sex_rating_bad           (3)
#define sex_rating_horrible      (2)
// returns a value between 1 and 10 on how good the sex was
#define obj_sex_rating(x)        ((((get_critter_stat(x,STAT_ch)*50) +                    \
                                    (get_critter_stat(x,STAT_en)*25) +                    \
                                    (get_critter_stat(x,STAT_ag)*13) +                    \
                                    (get_critter_stat(x,STAT_st)*12))/100) +              \
                                    (has_trait(TRAIT_PERK,x,PERK_kama_sutra_perk) * 2) +  \
                                    (has_trait(TRAIT_TRAIT,x,TRAIT_sex_appeal)) +         \
                                    (is_sex_god * 2 * (x == dude_obj)))
#define dude_sex_rating          obj_sex_rating(dude_obj)
#define self_sex_rating          obj_sex_rating(self_obj)
#define up_sex_status_amt(x)     inc_global_var_amt(GVAR_PLAYER_SEX_LEVEL, dude_sex_rating * x);   \
                                 inc_global_var_amt(GVAR_SEX_COUNTER, x);                          \
                                 if (global_var(GVAR_SEX_COUNTER) >= 10) then begin                \
                                    set_global_var(GVAR_GIGALO, 1);                                \
                                 end                                                               \
                                 if (dude_sex_rating >= sex_rating_great) then begin               \
                                    set_global_var(GVAR_SEXPERT, 1);                               \
                                 end                                                               \
                                 if (global_var(GVAR_DUDE_VIRGIN) == 1) then                       \
                                    set_global_var(GVAR_DUDE_VIRGIN,0)

#define up_sex_status            up_sex_status_amt(1)
#define do_default_sex           advance_sex_time;    \
                                 up_sex_status

#define destroy_obj_inven(obj)                      \
   global_temp := create_object(PID_FOOTLOCKER_CLEAN_LEFT,0,0); \
   move_obj_inven_to_obj(obj, global_temp);                     \
   destroy_object(global_temp)

/*******************************************************************************************************************
********** These represent the players acomplishments through the game *********************************************
********** Note: these reflect the Fallout2 variable designers put in the scripts assuming we were *****************
********** going to have a magic variable to keep track of the player stats throught the game **********************
*******************************************************************************************************************/
#define f2_state_v13_looking                          (0)
#define f2_state_v13_known                            (1)   // set -Chris H
#define f2_state_v13_found                            (2)   // set -Chris H
#define f2_state_v13_entered                          (3)   // set -Chris H
#define f2_state_tribe_kidnapped                      (4)   // ### state not set
#define f2_state_fix_tanker                           (5)   // didn't need to exist
#define f2_state_tanker_fix_known                     (6)   // set -Chris H
#define f2_state_tanker_fixed                         (7)   // set -Chris H
#define f2_state_enclave_destroyed                    (8)   // ### state not set

#define set_f2(x)                                     if (global_var(GVAR_FALLOUT_2) < x) then set_global_var(GVAR_FALLOUT_2, x)
#define force_f2(x)                                   set_global_var(GVAR_FALLOUT_2, x)
#define get_f2(x)                                     (global_var(GVAR_FALLOUT_2) == x)
#define f2_flag_any                                   (global_var(GVAR_FALLOUT_2))

#define Fallout2_vault13_looking                      get_f2(f2_state_v13_looking)
#define Fallout2_vault13_location_known               get_f2(f2_state_v13_known)
#define Fallout2_vault13_found                        get_f2(f2_state_v13_found)
#define Fallout2_vault13_entered                      get_f2(f2_state_v13_entered)
#define Fallout2_tribe_kidnapped                      get_f2(f2_state_tribe_kidnapped)
#define Fallout2_fix_tanker                           get_f2(f2_state_fix_tanker)
#define Fallout2_tanker_known                         get_f2(f2_state_tanker_fix_known)
#define Fallout2_tanker_fixed                         get_f2(f2_state_tanker_fixed)
#define Fallout2_enclave_destroyed                    get_f2(f2_state_enclave_destroyed)

/*
#define Fallout2_nothing                              (false) // ***
#define Fallout2_vault13_looking                      (vault_13_visible_on_map == false)
#define Fallout2_vault13_location_known               ((vault_13_visible_on_map) and (vault_13_visit == false))
#define Fallout2_vault13_found                        (vault_13_visit)
#define Fallout2_vault13_entered                      ((vault_13_visit) and map_is_known(MAP_VAULT_13))
#define Fallout2_tribe_kidnapped                      (arroyo_destroyed_visit)
#define Fallout2_fix_tanker                           (false) // ***
#define Fallout2_tanker_known                         (false) // ***
#define Fallout2_tanker_fixed                         (false) // ***
#define Fallout2_enclave_destroyed                    (false) // ***
*/

// Info relating to carry weight, how much something costs, and weights
#define pid_weight(x)                                   proto_data(x,it_weight)
#define obj_weight(x)                                   pid_weight(obj_pid(x))
#define pid_cost(x)                                     proto_data(x, it_cost)
#define obj_cost(x)                                     pid_cost(obj_pid(x))

#define amt_cost_barter(who1, who2, x)                  floor(2 * x * ((160.0 + has_skill(who2,SKILL_BARTER)) / (160.0 + has_skill(who1,SKILL_BARTER))))
#define pid_cost_barter(who1, who2, x)                  amt_cost_barter(who1, who2, pid_cost(x))
#define obj_cost_barter(who1, who2, x)                  pid_cost_barter(who1, who2, obj_pid(x))
#define who_max_carry(x)                                get_critter_stat(x,STAT_carry_amt)
#define who_carry_amount(x)                             has_trait(TRAIT_OBJECT, x, OBJECT_CUR_WEIGHT)
#define who_inven_free_amt(x)                           (who_max_carry(x) - who_carry_amount(x))


/********************************************************************
*******************   Game time Limits   ****************************
********************************************************************/

#ifndef TIME_LIMIT_1
#define TIME_LIMIT_1                        (60)
#endif
#ifndef TIME_LIMIT_2
#define TIME_LIMIT_2                        (120)
#endif
#ifndef TIME_LIMIT_3
#define TIME_LIMIT_3                        (180)
#endif
#ifndef TIME_LIMIT_4
#define TIME_LIMIT_4                        (240)
#endif

#define reached_tl_1                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_1)
#define reached_tl_2                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_2)
#define reached_tl_3                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_3)
#define reached_tl_4                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_4)


/********************************************************************
************   These are for cutting down on the lvars   ************
********************************************************************/
// for examples of use, see new reno and raiders
// default bits for character flag
#define herebefore_bit                                bit_1
#define hostile_bit                                   bit_2
#define examined_bit                                  bit_3
#define personal_enemy_bit                            bit_4
#define initialized_bit                               bit_5
#define is_float_bit                                  bit_7
#define destroy_me_bit                                bit_8
#define heard_call_bit                                bit_9

// here before
#define herebefore                                    lvar_bit(LVAR_Flags, herebefore_bit)
#define set_herebefore                                set_lvar_bit_on(LVAR_Flags, herebefore_bit)
#define off_herebefore                                set_lvar_bit_off(LVAR_Flags, herebefore_bit)
// hostile
#define hostile                                       lvar_bit(LVAR_Flags, hostile_bit)
#define set_hostile                                   set_lvar_bit_on(LVAR_Flags, hostile_bit)
#define off_hostile                                   set_lvar_bit_off(LVAR_Flags, hostile_bit)
// examined
#define examined                                      lvar_bit(LVAR_Flags, examined_bit)
#define set_examined                                  set_lvar_bit_on(LVAR_Flags, examined_bit)
// personal enemy
#define personal_enemy                                lvar_bit(LVAR_Flags, personal_enemy_bit)
#define set_personal_enemy                            set_lvar_bit_on(LVAR_Flags, personal_enemy_bit); set_hostile
// initialized
#define destroy_me                                    lvar_bit(LVAR_Flags, destroy_me_bit)
#define set_destroy_me                                set_lvar_bit_on(LVAR_Flags, destroy_me_bit)
// initialized
#define initialized                                   lvar_bit(LVAR_Flags, initialized_bit)
#define set_initialized                               set_lvar_bit_on(LVAR_Flags, initialized_bit)
// heard_call
#define heard_call                                    lvar_bit(LVAR_Flags, heard_call_bit)
#define set_heard_call                                set_lvar_bit_on(LVAR_Flags, heard_call_bit)
// set message type
#define is_float                                      lvar_bit(LVAR_Flags, is_float_bit)
#define is_click                                      (is_float == false)
#define set_is_float                                  set_lvar_bit_on(LVAR_Flags, is_float_bit)
#define set_is_click                                  set_lvar_bit_off(LVAR_Flags, is_float_bit)
#define create_out_of_business(tile, elev, pid)                                                                                                                       \
         if ((tile_contains_pid_obj(tile, elev, PID_OUT_OF_BUSINESS_NORTH) == 0) and (tile_contains_pid_obj(tile, elev, PID_OUT_OF_BUSINESS_EAST) == 0)) then begin   \
            global_temp := create_object_sid(pid, 0, 0, SCRIPT_ZICLOSED);                                                                                             \
            set_obj_visibility(global_temp,true);                                                                                                                     \
            move_to(global_temp, tile, elev);                                                                                                                         \
         end                                                                                                                                                          \
         ndebug("created out of business @ tile == " + tile + " / elevation == " + elev)
#define create_north_out_of_business(x, e)            create_out_of_business(x, e, PID_OUT_OF_BUSINESS_NORTH)
#define create_east_out_of_business(x, e)             create_out_of_business(x, e, PID_OUT_OF_BUSINESS_EAST)

/*******************************************************************************************************************
********** These are new reno macros that are used in other scripts ************************************************
*******************************************************************************************************************/
// new reno macros start
#define nr_mstr(x)                                    message_str(SCRIPT_NEWR1,(x))

// porn star start
#define porn_star_msg_start                           (500)
#define dude_has_porn_star_rep                        (global_var(GVAR_NEW_RENO_PORN_STAR) > 0)
#define dude_porn_star_number                         (global_var(GVAR_NEW_RENO_PORN_STAR))
#define porn_star_name                                (nr_mstr(porn_star_msg_start + dude_porn_star_number))
// porn star end

// prize fighter start
#define prizefighter_msg_start                        (400)
#define dude_is_prizefighter                          (global_var(GVAR_NEW_RENO_HAS_REP_PRIZEFIGHTER) > 0)
#define dude_prizefighter_number                      (global_var(GVAR_NEW_RENO_PRIZEFIGHTER))
#define prizefighter_name                             (nr_mstr(prizefighter_msg_start + dude_prizefighter_number))
// prize fighter end

// made man start
#define family_name_msg_start                         (200)
#define made_man_msg_start                            (300)
#define dude_is_made_man                              (global_var(GVAR_NEW_RENO_MADE_MAN) > 0)
#define family_none                                   (0)
#define family_salvatore                              (1)
#define family_bishop                                 (2)
#define family_mordino                                (3)
#define family_wright                                 (4)
#define dude_family                                   (global_var(GVAR_NEW_RENO_MADE_MAN)/100)
#define dude_made_man_number                          (global_var(GVAR_NEW_RENO_MADE_MAN)%100)
#define dude_family_name                              (nr_mstr(family_name_msg_start + dude_family))
#define made_man_num_to_name(x)                       (nr_mstr(made_man_msg_start + x))
#define made_man_name                                 made_man_num_to_name(dude_made_man_number)
#define salvatore_power                               (global_var(GVAR_SALVATORE_FAMILY_COUNTER))
#define bishop_power                                  (global_var(GVAR_BISHOP_FAMILY_COUNTER))
#define mordino_power                                 (global_var(GVAR_MORDINO_FAMILY_COUNTER))
#define wright_power                                  (global_var(GVAR_WRIGHT_FAMILY_COUNTER))
#define dec_family_counter_amt(the_family, x)         if (family_crushed(the_family) == false) then begin                        \
                                                         if (the_family == family_salvatore) then begin                          \
                                                            dec_global_var_amt(GVAR_SALVATORE_FAMILY_COUNTER,x);                 \
                                                         end else if (the_family == family_bishop) then begin                    \
                                                            dec_global_var_amt(GVAR_BISHOP_FAMILY_COUNTER,x);                    \
                                                         end else if (the_family == family_mordino) then begin                   \
                                                            dec_global_var_amt(GVAR_MORDINO_FAMILY_COUNTER,x);                   \
                                                         end else if (the_family == family_wright) then begin                    \
                                                            dec_global_var_amt(GVAR_WRIGHT_FAMILY_COUNTER,x);                    \
                                                         end                                                                     \
                                                      end                                                                        \
                                                      ndebug("\nfamily standings: ");                                         \
                                                      ndebug("\n  Salvatore == "+global_var(GVAR_SALVATORE_FAMILY_COUNTER));  \
                                                      ndebug("\n  Bishop == "+global_var(GVAR_BISHOP_FAMILY_COUNTER));        \
                                                      ndebug("\n  Mordino == "+global_var(GVAR_MORDINO_FAMILY_COUNTER));      \
                                                      ndebug("\n  Wright == "+global_var(GVAR_WRIGHT_FAMILY_COUNTER))
#define family_crushed(x)                             (((x == family_salvatore) and (global_var(GVAR_SALVATORE_FAMILY_COUNTER) <= -1)) or \
                                                       ((x == family_bishop) and (global_var(GVAR_BISHOP_FAMILY_COUNTER) <= -1)) or       \
                                                       ((x == family_mordino) and (global_var(GVAR_MORDINO_FAMILY_COUNTER) <= -1)) or     \
                                                       ((x == family_wright) and (global_var(GVAR_WRIGHT_FAMILY_COUNTER) <= -1)))
#define set_family_crushed(the_family)                if (the_family == family_salvatore) then begin                             \
                                                         set_global_var(GVAR_SALVATORE_FAMILY_COUNTER, -1);                      \
                                                      end else if (the_family == family_bishop) then begin                       \
                                                         set_global_var(GVAR_BISHOP_FAMILY_COUNTER, -1);                         \
                                                      end else if (the_family == family_mordino) then begin                      \
                                                         set_global_var(GVAR_MORDINO_FAMILY_COUNTER, -1);                        \
                                                      end else if (the_family == family_wright) then begin                       \
                                                         set_global_var(GVAR_WRIGHT_FAMILY_COUNTER, -1);                         \
                                                      end
#define dec_family_counter(the_family)                dec_family_counter_amt(the_family, 1)
// made man end
// new reno macros end

// den macros start
#define state_vic_known_no                         (0)
#define state_vic_known_merchant                   (1)
#define state_vic_known_name                       (2)
#define vic_known(x)                               (global_var(GVAR_DEN_VIC_KNOWN) == x)
#define set_vic_known(x)                           if (x > global_var(GVAR_DEN_VIC_KNOWN)) then set_global_var(GVAR_DEN_VIC_KNOWN, x)
// den macros end

// raiders macros start
#define raiders_dead_bit                              bit_1
#define raiders_marcus_bit                            bit_2
#define raiders_robobrain_bit                         bit_3
#define raiders_bonenose_bit                          bit_4
#define raiders_alarm_bit                             bit_5
#define know_raiders_trap_bit                         bit_6
//begin added by killap
#define raiders_scout_left_bit                        bit_7
//end added by killap


#define raiders_dead                                  gvar_bit(GVAR_RAIDERS_FLAGS, raiders_dead_bit)
#define set_raiders_dead                              set_gvar_bit_on(GVAR_RAIDERS_FLAGS, raiders_dead_bit)
#define raiders_marcus                                gvar_bit(GVAR_RAIDERS_FLAGS, raiders_marcus_bit)
#define set_raiders_marcus                            set_gvar_bit_on(GVAR_RAIDERS_FLAGS, raiders_marcus_bit)
#define raiders_robobrain                             gvar_bit(GVAR_RAIDERS_FLAGS, raiders_robobrain_bit)
#define set_raiders_robobrain                         set_gvar_bit_on(GVAR_RAIDERS_FLAGS, raiders_robobrain_bit)
#define raiders_bonenose                              gvar_bit(GVAR_RAIDERS_FLAGS, raiders_bonenose_bit)
#define set_raiders_bonenose                          set_gvar_bit_on(GVAR_RAIDERS_FLAGS, raiders_bonenose_bit)
#define raiders_alarm                                 gvar_bit(GVAR_RAIDERS_FLAGS, raiders_alarm_bit)
#define set_raiders_alarm                             set_gvar_bit_on(GVAR_RAIDERS_FLAGS, raiders_alarm_bit)
#define off_raiders_alarm                             set_gvar_bit_off(GVAR_RAIDERS_FLAGS, raiders_alarm_bit)
#define know_raiders_trap                             gvar_bit(GVAR_RAIDERS_FLAGS, know_raiders_trap_bit)
#define set_know_raiders_trap                         set_gvar_bit_on(GVAR_RAIDERS_FLAGS, know_raiders_trap_bit)
#define off_know_raiders_trap                         set_gvar_bit_off(GVAR_RAIDERS_FLAGS, know_raiders_trap_bit)
//added by killap
#define raiders_scout_left                            gvar_bit(GVAR_RAIDERS_FLAGS, raiders_scout_left_bit)
#define set_raiders_scout_left                        set_gvar_bit_on(GVAR_RAIDERS_FLAGS, raiders_scout_left_bit)
//end added by killap
// raiders macros end

//see the file for disambiguation
#include "command_extra.h"

#define prone_to_gas(x) ( \
  not protected_from_gas(x) and (critter_kill_type(x) != KILL_TYPE_robot_kills) \
)
#define can_be_gas_poisoned(x) ((x == dude_obj) and not (protected_from_gas(x)))

#endif // COMMAND_H
