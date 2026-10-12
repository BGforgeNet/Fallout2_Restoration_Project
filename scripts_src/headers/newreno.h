/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef NEWRENO_H
#define NEWRENO_H

#define set_next_float_time(x,y,z)                    set_local_var(z, game_time + (random(x,y) * ONE_GAME_SECOND))
#define set_next_float_time_def(z)                    set_next_float_time(15,30,z)

#ifndef mid_tile
   #define mid_tile(x,y)                              temp_tile := x;                                                                    \
                                                      while (tile_distance(temp_tile, y) > (tile_distance(x,y)/2)) do                    \
                                                         temp_tile := tile_num_in_direction(temp_tile, rotation_to_tile(temp_tile,y), 1)
#endif
#ifndef random_tile_in_box
   #define random_tile_in_box(ul, ur, lr, ll)         mid_tile(ul,lr);                                                                        \
                                                      temp_tile := tile_num_in_direction(temp_tile, random(0,5), (tile_distance(ul,lr))/2);   \
                                                      if (tile_in_box(temp_tile, ul, ur, lr, ll) == false) then temp_tile := 0
#endif
#define Meet_Obj_Face(the_obj)                        if (tile_distance_objs(self_obj, the_obj) > 1) then begin                          \
                                                         mid_tile(self_tile, tile_num(the_obj));                                         \
                                                         animate_move_to_tile(temp_tile);                                                \
                                                      end else if (rotation_to_tile(tile_num(self_obj),tile_num(the_obj)) != self_cur_rot) then begin  \
                                                         Face_Critter(the_obj, self_obj);                                                \
                                                      end
#define random_tile_in_gym                            random_tile_in_box(24479, 24471, 26471, 26479)

#define set_new_reno_watcher(the_var)                 if ((obj_is_visible_flag(self_obj)) and (self_elevation == dude_elevation)) then begin                                                              \
                                                         if (the_var == 0) then begin                                                                            \
                                                            the_var := self_obj;                                                                                 \
                                                         end else if ((obj_can_see_obj(the_var, dude_obj) == false) or (is_critter_dead(the_var))) then begin    \
                                                            the_var := self_obj;                                                                                 \
                                                         end                                                                                                     \
                                                      end

 // timer event paramaters
#define new_song_param                                (0)
#define float_param                                   (1)
#define first_sight_param                             (2)
#define tamper_door_param                             (3)
#define door_use_param                                (4)
#define open_grave_param                              (5)
#define disarm_grave_param                            (6)
#define blow_up_grave_param                           (7)
#define attack_param                                  (8)
#define force_talk_param                              (9)
#define tamper_safe_param                             (10)
#define check_grave_param                             (11)
#define car_comment_param                             (12)
#define dogs_bark_param                               (13)
#define special_floater_param                         (14)
#define assassinate_param                             (15)
#define check_player_param                            (16)
#define return_rotation_param                         (17)
#define pause_param                                   (18)
#define call_guards_param                             (19)
#define explode_self_param                            (20)
#define wander_param                                  (21)
#define guard_export_param                            (22)
#define rotate_to_action_param                        (23)
#define move_bishop_to_safe_param                     (24)
#define heard_explosion_param                         (24)
#define control_boxers_param                          (25)
#define change_round_param                            (26)
#define punch_thrown_param                            (27)
#define new_round_param                               (28)
#define other_boxer_down_param                        (29)
#define other_boxer_up_param                          (30)
#define post_sex_param                                (31)
#define kitty_sex_param                               (32)
#define hide_param                                    (33)
#define fight_over_param                              (34)
#define off_run_away_param                            (35)
#define heard_help_param                              (36)
#define just_did_mrs_bishop_param                     (37)
#define off_following_param                           (38)
#define diggin_willie_param                           (39)
#define back_to_diggin_param                          (40)
#define knockout_param                                (41)
#define round_over_param                              (42)
#define slot_win_param                                (43)
#define warning_loop_param                            (44)
#define no_whore_floats_param                         (45)
#define start_fight_param                             (46)
#define off_head_help_param                           (47)
#define check_ui_param                                (48)
#define sing_param                                    (100)

#define tamper_good_CSObj_param                       (200)
#define tamper_CSObj_param                            (201)

variable last_timed_obj;
variable last_timed_param;
#define nr_add_timer_event_tic(obj, ticks, param)     last_timed_obj := obj;                 \
                                                      last_timed_param := last_timed_param;  \
                                                      rm_fixed_timer_event(obj, param);      \
                                                      add_timer_event(obj, ticks, param)
#define nr_add_timer_event(obj, sec, param)           nr_add_timer_event_tic(obj, game_ticks(sec), param)
#define nr_add_timer_event_rand(obj, x, y, param)     nr_add_timer_event_tic(obj, game_ticks(x) + random(0, game_ticks((y) - (x))), param)


// new reno flags
#define set_new_reno_flag_on(x,n)                     set_gvar_bit_on(GVAR_NEW_RENO_FLAG_##n, x)
#define set_new_reno_flag_off(x,n)                    set_gvar_bit_off(GVAR_NEW_RENO_FLAG_##n, x)
#define get_new_reno_flag(x,n)                        gvar_bit(GVAR_NEW_RENO_FLAG_##n, x)

// new reno flag 1 bits
#define lil_jesus_dead_bit                            bit_1
#define marjorie_called_guards_bit                    bit_2
#define jjj_dead_bit                                  bit_3
#define mordino_known_bit                             bit_4
#define richard_wright_known_bit                      bit_5
#define know_renesco_bit                              bit_6
#define know_scott_bit                                bit_7
#define jules_slander_bit                             bit_8
#define jjj_slander_bit                               bit_9
#define renesco_slander_bit                           bit_10
#define examined_body_bit                             bit_11
#define jet_canister_poison_bit                       bit_12
#define renesco_dead_bit                              bit_13
#define lloyd_dead_bit                                bit_14
#define know_lasers_bit                               bit_15
#define secret_trade_bit                              bit_16
#define nikki_bribed_bit                              bit_17
#define nikki_lead_bit                                bit_18
#define thousand_caps_bit                             bit_19
#define salvatore_done_bit                            bit_20
#define salvatore_call_guards_bit                     bit_21
#define nikki_lloyd_bit                               bit_22
#define nikki_dead_bit                                bit_23
#define lloyd_locale_desperado_bit                    bit_24
#define lloyd_locale_upstairs_bit                     bit_25
#define nikki_intro_bit                               bit_26
#define treasure_bit                                  bit_27
#define lloyd_took_money_bit                          bit_28
#define blow_up_grave_bit                             bit_29
#define did_lloyd_golgotha_placement_bit              bit_30
#define jules_dead_bit                                bit_31
#define corvega_bishop_bit                            bit_32
// flag 2
#define pritchard_bit                                 bit_1
#define know_jules_bit                                bit_2
#define know_jjj_bit                                  bit_3
#define know_lil_jesus_bit                            bit_4
#define know_mordino_bit                              bit_5
#define know_salvatore_bit                            bit_6
#define mrs_bishop_warning_bit                        bit_7
#define told_to_move_out_bit                          bit_8
#define mission_aborted_bit                           bit_9
#define richard_wright_room_bit                       bit_10
#define chris_reccomends_bit                          bit_11
#define jules_killed_cody_bit                         bit_12
#define monte_fingered_jules_bit                      bit_13
#define cody_fingered_jules_bit                       bit_14
#define cody_dead_bit                                 bit_15
#define look_cody_bit                                 bit_16
#define jjj_truth_bit                                 bit_17
#define know_algernon_bit                             bit_18
#define know_algernon_weapons_bit                     bit_19
#define know_algernon_fake_death_bit                  bit_20
#define algernon_dead_bit                             bit_21
#define uncovered_lloyd_grave_bit                     bit_22
#define eldridge_dead_bit                             bit_23
#define bros_dead_bit                                 bit_24
#define assassinated_big_jesus_bit                    bit_25
#define big_jesus_dead_bit                            bit_26
#define lil_jesus_dealer_bit                          bit_27
#define flufer_bit                                    bit_28
#define making_porn_bit                               bit_29
#define touched_stolen_car_bit                        bit_30
#define no_whore_floats_bit                           bit_31
#define masticator_bit_ear_bit                        bit_32
// flag 3
#define bishop_assassinated_bit                       bit_1
#define trap_safe_bit                                 bit_2
#define boxer_resting_bit                             bit_3
#define boxer_killed_bit                              bit_4
#define know_tully_bit                                bit_5
#define tully_drinks_bit                              bit_6
#define divorce_bit                                   bit_7
#define bishop_raiders_bit                            bit_8
#define tully_dead_bit                                bit_9
#define mckneely_dead_bit                             bit_10
#define holyfeld_dead_bit                             bit_11
#define masticator_dead_bit                           bit_12
#define fighting_main_boxer_bit                       bit_13
#define killed_opponent_bit                           bit_14
#define jules_warned_bit                              bit_15
#define know_cody_bit                                 bit_16
#define saw_secret_trade_bit                          bit_17
#define made_slave_guild_guy_bit                      bit_18
#define raiders_secret_enterance_bit                  bit_19
#define mrs_bishop_win_bit                            bit_20
#define compartment_bit                               bit_22
#define vault_city_wrong_place_bit                    bit_23
#define pritchard_exp_bit                             bit_24
#define band_killed_bit                               bit_25
#define dug_up_willie_bit                             bit_26
#define car_is_now_being_stolen_bit                   bit_27
#define eldridge_bed_time_bit                         bit_28
#define did_enter_base_bit                            bit_29
#define fight_is_on_bit                               bit_30
#define marcus_laid_bit                               bit_31
#define witness_transaction_bit                       bit_32
// flag 4
#define player_bites_masticator_ear_bit               bit_1
#define ui_should_be_disabled_bit                     bit_2
#define chop_shop_hostile_bit                         bit_3
#define porn_studio_hostile_bit                       bit_4
#define myron_date_bit                                bit_5

//for Ms Kitty, Myron date - added by killap
#define myron_date                     get_new_reno_flag(myron_date_bit, 4)
#define set_myron_date                 if (myron_date == false) then begin             \
                                          give_xp(EXP_NEW_RENO_WHORE_FOR_MYRON);       \
                                       end                                             \
                                       set_new_reno_flag_on(myron_date_bit, 4)

// for dan
#define marcus_laid                                   get_new_reno_flag(marcus_laid_bit, 3)
#define set_marcus_laid                               set_new_reno_flag_on(marcus_laid_bit, 3)

#define made_slave_guild_guy                          get_new_reno_flag(made_slave_guild_guy_bit, 3)
#define set_made_slave_guild_guy                      set_new_reno_flag_on(made_slave_guild_guy_bit, 3)

// generic use anywhere

#define tell_anouncer_to_switch_ui                    if (cur_map_index == MAP_NEW_RENO_2) then begin                \
                                                         if (announcer_obj != 0) then begin                          \
                                                            nr_add_timer_event(announcer_obj, 0, check_ui_param);    \
                                                         end                                                         \
                                                      end
#define ui_should_be_disabled                         get_new_reno_flag(ui_should_be_disabled_bit, 4)
#define set_ui_should_be_disabled                     tell_anouncer_to_switch_ui                               \
                                                      set_new_reno_flag_on(ui_should_be_disabled_bit, 4)
#define off_ui_should_be_disabled                     tell_anouncer_to_switch_ui                               \
                                                      set_new_reno_flag_off(ui_should_be_disabled_bit, 4)

#ifndef tile_in_box
#define tile_in_box(x, ul, ur, lr, ll)                tile_in_tile_rect(ul, ur, ll, lr, x)
#endif
#define obj_in_loc(obj, ul, ur, lr, ll, map, elev)    ((tile_in_box(tile_num(obj), ul, ur, lr, ll)) and (cur_map_index == map) and ((elevation(obj) == elev) or (-1 == elev)))

#define check_companion(x)                            (obj_can_see_obj(self_obj, party_member_obj(x)))

// companions
#define myron_is_dude_companion                       check_companion(PID_MYRON)
#define robobrain_is_dude_companion                   check_companion(PID_BRAINBOT)
#define marcus_is_dude_companion                      check_companion(PID_MARCUS)
#define lenny_is_dude_companion                       check_companion(PID_LENNY)
#define sulik_is_dude_companion                       check_companion(PID_SULIK)
#define robodog_is_dude_companion                     check_companion(PID_CYBERDOG)
#ifndef miria_is_dude_companion
   #define miria_is_dude_companion                    check_companion(PID_MIRIA)
#endif
#define davin_is_dude_companion                       check_companion(PID_DAVIN)
#ifndef vic_is_dude_companion
   #define vic_is_dude_companion                      check_companion(PID_VIC)
#endif
#define macrae_is_dude_companion                      check_companion(PID_JOHN_MACRAE)

// generic end

// property check macros
// general object in locations
#define obj_in_lloyds_room(x)                         (obj_in_loc(x, 12899, 12895, 14495, 14499, MAP_NEW_RENO_1, 2))
#define obj_cats_paw_building(x)                      (obj_in_loc(x, 20493, 20481, 26481, 26493, MAP_NEW_RENO_1, 0))
#define obj_mordino_casino(x)                         ((obj_in_loc(x, 10696, 10676, 17478, 17496, MAP_NEW_RENO_1, 0)) or  \
                                                       (obj_in_loc(x, 10676, 10662, 17462, 17478, MAP_NEW_RENO_1, 0)) or  \
                                                       (obj_in_loc(x, 12262, 12250, 14650, 14662, MAP_NEW_RENO_1, 0)))
#define obj_mordino_basement(x)                       (obj_in_loc(x, 9882, 9848, 18248, 18282, MAP_NEW_RENO_1, 1))
#define obj_mordino_2nd_floor(x)                      ((obj_in_loc(x, 10700, 10666, 17466, 17500, MAP_NEW_RENO_1, 2)) or  \
                                                       (obj_in_loc(x, 12666, 12654, 14654, 14666, MAP_NEW_RENO_1, 2)))
#define obj_mordino_property(x)                       (obj_in_loc(x, 8292, 8246, 15046, 15092, MAP_NEW_RENO_1, 0))
#define obj_pimp_team_1(x)                            ((obj_in_loc(x, 8296, 8258, 15858, 15896, MAP_NEW_RENO_1, 0)) or    \
                                                       (obj_in_loc(x, 12744, 12712, 20312, 20344, MAP_NEW_RENO_2, 0)))
#define obj_pimp_team_2(x)                            ((obj_in_loc(x, 11134, 11106, 19506, 19534, MAP_NEW_RENO_1, 0)) or  \
                                                       (obj_in_loc(x, 7902, 7862, 20262, 20302, MAP_NEW_RENO_2, 0)))
#define obj_pimp_team_3(x)                            (obj_in_loc(x, 21544, 21512, 30312, 30344, MAP_NEW_RENO_2, 0))
#define obj_pimp_team_4(x)                            (obj_in_loc(x, 21502, 21466, 30266, 30301, MAP_NEW_RENO_2, 0))
#define obj_junkie_house_property(x)                  (obj_in_loc(x, 11930, 11910, 18710, 18730, MAP_NEW_RENO_1, 0))
#define obj_salvatore_casino(x)                       ((obj_in_loc(x, 15940, 15916, 19516, 19540, MAP_NEW_RENO_2, 0)) or  \
                                                       (obj_in_loc(x, 13528, 13516, 15916, 15928, MAP_NEW_RENO_2, 0)))
#define obj_salvatore_2nd_floor(x)                    (obj_in_loc(x, 25528, 25504, 29104, 29128, MAP_NEW_RENO_2, 1))
#define obj_salvatore_property(x)                     (obj_in_loc(x, 13540, 13516, 19516, 19540, MAP_NEW_RENO_2, 0))
#define obj_porn_studio_building(x)                   (obj_in_loc(x, 22340, 22316, 29516, 29540, MAP_NEW_RENO_2, 0))
#define obj_porn_stuidio_stage(x)                     (obj_in_loc(x, 24334, 24322, 25922, 25934, MAP_NEW_RENO_2, 0))
#define obj_boxing_gym_building(x)                    (obj_in_loc(x, 22298, 22266, 29466, 29498, MAP_NEW_RENO_2, 0))
#define obj_boxing_gym_ring(x)                        (obj_in_loc(x, 24479, 24471, 26471, 26479, MAP_NEW_RENO_2, 0))
#define obj_bishop_casino(x)                          (obj_in_loc(x, 7898, 7896, 19462, 19498, MAP_NEW_RENO_2, 0))
#define obj_bishop_2nd_floor(x)                       (obj_in_loc(x, 10298, 10262, 19462, 19498, MAP_NEW_RENO_2, 1))
#define obj_bishop_3rd_floor(x)                       (obj_in_loc(x, 10298, 10262, 19462, 19498, MAP_NEW_RENO_2, 2))
#define obj_bishop_boxing_arena(x)                    (obj_in_loc(x, 15128, 15094, 26694, 26728, MAP_NEW_RENO_BOXING, 0))
#define obj_bishop_boxing_arena_ring(x)               (obj_in_loc(x, 21916, 21906, 24306, 24316, MAP_NEW_RENO_BOXING, 0))
#define obj_bishop_property(x)                        (obj_in_loc(x, 7898, 7862, 19462, 19498, MAP_NEW_RENO_2, 0))
#define obj_wright_front_yard(x)                      (obj_in_loc(x, 24312, 24294, 26694, 26712, MAP_NEW_RENO_4, 0))
#define obj_wright_richards_room(x)                   (obj_in_loc(x, 21528, 21516, 23116, 23128, MAP_NEW_RENO_4, 0))
#define obj_wright_property(x)                        (obj_in_loc(x, 19528, 19478, 26678, 26728, MAP_NEW_RENO_4, 0))
#define obj_wright_house(x)                           ((obj_wright_property(x)) and (obj_wright_front_yard(x) == false))
#define obj_comedian_audience(x)                      (obj_in_loc(x, 12295, 12281, 14681, 14695, MAP_NEW_RENO_2, 0))
// general tile in locations (assumes you are on the same map and are at the correct elevation
#define tile_cats_paw_building(x)                     (tile_in_box(x, 20493, 20481, 26481, 26493))
#define tile_mordino_casino(x)                        ((tile_in_box(x, 8292, 8262, 15062, 15092)) or        \
                                                       (tile_in_box(x, 9862, 9858, 15058, 15062)) or        \
                                                       (tile_in_box(x, 10258, 10246, 12246, 12258)))
#define tile_mordino_basement(x)                      (tile_in_box(x, 9882, 9848, 18248, 18282))
#define tile_mordino_2nd_floor(x)                     ((tile_in_box(x, 10700, 10666, 17466, 17500, )) or    \
                                                       (tile_in_box(x, 12666, 12654, 14654, 14666)))
#define tile_mordino_property(x)                      (tile_in_box(x, 8292, 8246, 15046, 15092))
#define tile_in_big_jesus_room(x)                     (tile_in_box(x, 11688, 11678, 13278, 13288))
#define tile_stable_marjorie_lab(x)                   (tile_in_box(x, 15142, 15122, 18322, 18342))
#define tile_pimp_team_1_map_1(x)                     (tile_in_box(x, 8296, 8258, 15858, 15896))
#define tile_pimp_team_1_map_2(x)                     (tile_in_box(x, 12744, 12712, 20312, 20344))
#define tile_pimp_team_1(x)                           ((tile_pimp_team_1_map_1(x)) or                       \
                                                       (tile_pimp_team_1_map_2(x)))
#define tile_pimp_team_2_map_1(x)                     (tile_in_box(x, 11134, 11106, 19506, 19534))
#define tile_pimp_team_2_map_2(x)                     (tile_in_box(x, 7902, 7862, 20262, 20302))
#define tile_pimp_team_2(x)                           ((tile_pimp_team_2_map_1(x)) or                       \
                                                       (tile_pimp_team_2_map_2(x)))
#define tile_pimp_team_3(x)                           (tile_in_box(x, 21544, 21512, 30312, 30344))
#define tile_pimp_team_4(x)                           (tile_in_box(x, 21502, 21466, 30266, 30301))
#define tile_junkie_house_property(x)                 (tile_in_box(x, 11930, 11910, 18710, 18730))
#define tile_salvatore_casino(x)                      ((tile_in_box(x, 15940, 15916, 19516, 19540)) or      \
                                                       (tile_in_box(x, 13528, 13516, 15916, 15928)))
#define tile_salvatore_2nd_floor(x)                   (tile_in_box(x, 25528, 25504, 29104, 29128))
#define tile_salvatore_property(x)                    (tile_in_box(x, 13540, 13516, 19516, 19540))
#define tile_porn_studio_building(x)                  (tile_in_box(x, 22340, 22316, 29516, 29540))
#define tile_porn_stuidio_stage(x)                    (tile_in_box(x, 24334, 24322, 25922, 25934))
#define tile_boxing_gym_building(x)                   (tile_in_box(x, 22298, 22266, 29466, 29498))
#define tile_boxing_gym_ring(x)                       (tile_in_box(x, 24479, 24471, 26471, 26479))
#define tile_bishop_casino(x)                         (tile_in_box(x, 7898, 7896, 19462, 19498))
#define tile_bishop_2nd_floor(x)                      (tile_in_box(x, 10298, 10262, 19462, 19498))
#define tile_bishop_3rd_floor(x)                      (tile_in_box(x, 10298, 10262, 19462, 19498))
#define tile_bishop_boxing_arena(x)                   (tile_in_box(x, 15128, 15094, 26694, 26728))
#define tile_bishop_boxing_arena_ring(x)              (tile_in_box(x, 21916, 21906, 24306, 24316))
#define tile_bishop_property(x)                       (tile_in_box(x, 7898, 7862, 19462, 19498))
#define tile_wright_front_yard(x)                     (tile_in_box(x, 24312, 24294, 26694, 26712))
#define tile_wright_richards_room(x)                  (tile_in_box(x, 21528, 21516, 23116, 23128))
#define tile_wright_property(x)                       (tile_in_box(x, 19528, 19478, 26678, 26728))
#define tile_wright_orville_room(x)                   (tile_in_box(x, 22893, 22879, 26479, 26493))
#define tile_wright_house(x)                          ((tile_wright_property(x)) and (tile_wright_front_yard(x) == false))

// eldridge weapon shops
#define obj_in_eldridge_front_room(x)                 obj_in_loc(x, 26125, 26115, 29715, 29725, MAP_NEW_RENO_3, 0)
#define obj_in_eldridge_back_room(x)                  obj_in_loc(x, 22519, 22507, 24307, 24319, MAP_NEW_RENO_3, 0)
#define obj_in_eldridge_store_area(x)                 obj_in_loc(x, 22334, 22306, 29506, 29534, MAP_NEW_RENO_3, 0)
#define tile_in_eldridge_store_area(x)                tile_in_box(x, 22334, 22306, 29506, 29534)
#define tile_in_eldridge_front_room(x)                tile_in_box(x, 26125, 26115, 27915, 27925)
// wrights start
// destroy still
#define still_mission_none                            (0)
#define still_mission_assigned                        (1)
#define still_mission_reward                          (2)
#define set_still_mission(x)                          set_global_var(GVAR_NEW_RENO_WRIGHT_STILL_MISSION, x)
#define get_still_mission(x)                          (global_var(GVAR_NEW_RENO_WRIGHT_STILL_MISSION) == x)

#define wright_permission_bit                         bit_1
#define mrs_wright_destroyed_still_bit                bit_2
#define gave_gun_bit                                  bit_3
#define wright_dead_bit                               bit_4
#define know_mrs_wright_bit                           bit_5
#define mrs_wright_dead_bit                           bit_6
#define chris_recommends_bit                          bit_7
#define know_still_bit                                bit_8
#define wright_known_bit                              bit_9
#define wright_asssassinated_bit                      bit_10
#define kill_daddy_bit                                bit_11
#define kill_daddy_karma_bit                          bit_12
#define mrs_wright_pissed_bit                         bit_13
#define know_mr_wright_bit                            bit_14
#define ethyl_discovered_still_bit                    bit_15
#define went_to_still_map_bit                         bit_16

#define set_wright_flag(x)                            set_gvar_bit_on(GVAR_NEW_RENO_WRIGHT_FLAGS, x)
#define off_wright_flag(x)                            set_gvar_bit_off(GVAR_NEW_RENO_WRIGHT_FLAGS, x)
#define get_wright_flag(x)                            gvar_bit(GVAR_NEW_RENO_WRIGHT_FLAGS, x)

#define wright_permission                             get_wright_flag(wright_permission_bit)
#define set_wright_permission                         set_wright_flag(wright_permission_bit)
#define off_wright_permission                         off_wright_flag(wright_permission_bit)

#define child_play_area_heart                         (25703)
#define wright_house_heart                            (21903)
#define obj_on_wright(x)                              obj_wright_property(x)

#define mrs_wright_destroyed_still                    get_wright_flag(mrs_wright_destroyed_still_bit)
#define set_mrs_wright_destroyed_still                if (mrs_wright_destroyed_still == false) then begin   \
                                                         display_msg(nr_mstr(1500));                        \
                                                         give_xp(EXP_NEW_RENO_MRS_WRIGHT_DESTROY_STILL);    \
                                                      end                                                   \
                                                      set_wright_flag(mrs_wright_destroyed_still_bit)

#define wright_known                                  get_wright_flag(wright_known_bit)
#define set_wright_known                              set_wright_flag(wright_known_bit)

#define gave_gun                                      get_wright_flag(gave_gun_bit)
#define set_gave_gun                                  set_wright_flag(gave_gun_bit)

#define wright_dead                                   get_wright_flag(wright_dead_bit)
#define set_wright_dead                               set_wright_flag(wright_dead_bit)

#define wright_assassinated                           get_wright_flag(wright_assassinated_bit)
#define set_wright_assassinated                       set_wright_dead;                          \
                                                      set_wright_flag(wright_assassinated_bit)

#define kill_daddy                                    get_wright_flag(kill_daddy_bit)
#define set_kill_daddy                                set_wright_flag(kill_daddy_bit)

#define kill_daddy_karma                              get_wright_flag(kill_daddy_karma_bit)
#define set_kill_daddy_karma                          if (kill_daddy_karma == false) then begin             \
                                                         inc_general_rep(REP_BONUS_NEW_RENO_KILL_DADDY);    \
                                                      end                                                   \
                                                      set_wright_flag(kill_daddy_karma_bit)

#define know_mrs_wright                               get_wright_flag(know_mrs_wright_bit)
#define set_know_mrs_wright                           set_wright_flag(know_mrs_wright_bit)

#define mrs_wright_dead                               get_wright_flag(mrs_wright_dead_bit)
#define set_mrs_wright_dead                           set_wright_flag(mrs_wright_dead_bit)

#define chris_recommends                              get_wright_flag(chris_recommends_bit)
#define set_chris_recommends                          set_wright_flag(chris_recommends_bit)

#define know_still                                    get_wright_flag(know_still_bit)
#define set_know_still                                set_wright_flag(know_still_bit)

#define mrs_wright_pissed                             get_wright_flag(mrs_wright_pissed_bit)
#define set_mrs_wright_pissed                         set_wright_flag(mrs_wright_pissed_bit)

#define know_mr_wright                                get_wright_flag(know_mr_wright_bit)
#define set_know_mr_wright                            set_wright_flag(know_mr_wright_bit)   // ### not being set anywhere

#define ethyl_visible_on_map_three_time               ((global_var(GVAR_NEW_RENO_ETHYL_MEETING_TIME) < game_time) and (global_var(GVAR_NEW_RENO_ETHYL_MEETING_TIME) != 0))
#define ethyl_discovered_still                        get_wright_flag(ethyl_discovered_still_bit)
#define set_ethyl_discovered_still                    if (global_var(GVAR_NEW_RENO_ETHYL_MEETING_TIME) == 0) then begin       \
                                                         set_global_var(GVAR_NEW_RENO_ETHYL_MEETING_TIME, game_time + ticks_til_hour(600));  \
                                                      end                                                                     \
                                                      set_wright_flag(ethyl_discovered_still_bit)

#define went_to_still_map                             get_wright_flag(went_to_still_map_bit)
#define set_went_to_still_map                         set_wright_flag(went_to_still_map_bit)
// still
variable check_still_kill;
#define poison_still_effects                          ((global_var(GVAR_NEW_RENO_POISON_STILL_TIME) < game_time) and (global_var(GVAR_NEW_RENO_POISON_STILL_TIME) != 0))
#define check_poison_kill_critter                     if (poison_still_effects) then begin                                                        \
                                                         if ((random(1,5) == 4) or (NAME == SCRIPT_NCFTULLY)) then begin                          \
                                                            if (NAME == SCRIPT_NCFTULLY) then begin                                               \
                                                               set_tully_dead;                                                                    \
                                                            end                                                                                   \
                                                            get_self_family(check_still_kill);                                                    \
                                                            if (check_still_kill == family_none) then begin                                       \
                                                               kill_critter(self_obj, random(ANIM_fall_back_blood_sf, ANIM_fall_front_blood_sf)); \
                                                            end else begin                                                                        \
                                                               destroy_object(self_obj);                                                          \
                                                            end                                                                                   \
                                                         end                                                                                      \
                                                      end
#define still_status_none                             (0)
#define still_status_poisoned                         (1)
#define still_status_wrecked                          (2)
#define get_still_status(x)                           (global_var(GVAR_NEW_RENO_WRIGHT_STILL) == x)
#define set_still_status(x)                           if (x != still_status_poisoned) then begin                                 \
                                                         if (x == still_status_wrecked) then begin                               \
                                                            if (get_still_status(still_status_wrecked) == false) then begin      \
                                                               inc_reno_rep(REP_NEW_RENO_DESTROY_WRIGHT_STILLS);                 \
                                                               /*display_mstr(200);*/                                            \
                                                               if (get_still_mission(still_mission_assigned)) then begin         \
                                                                  give_xp(EXP_NEW_RENO_DESTROY_STILL);                           \
                                                               end                                                               \
                                                               dec_family_counter_amt(family_wright, 20);                        \
                                                            end                                                                  \
                                                         end                                                                     \
                                                         set_global_var(GVAR_NEW_RENO_POISON_STILL_TIME, 0);                     \
                                                      end else if (global_var(GVAR_NEW_RENO_POISON_STILL_TIME) == 0) then begin  \
                                                         if (get_still_status(still_status_none)) then begin                     \
                                                            inc_general_rep(REP_BONUS_NEW_RENO_POISON_STILL);                    \
                                                         end                                                                     \
                                                         set_global_var(GVAR_NEW_RENO_POISON_STILL_TIME, game_time + (3 * ONE_GAME_DAY));  \
                                                      end                                                                        \
                                                      set_global_var(GVAR_NEW_RENO_WRIGHT_STILL, x)

// Mystery
#define MYSTERY_STATE_NOTHING                         (0)
#define MYSTERY_STATE_ASSIGNED                        (1)
#define MYSTERY_STATE_BAD_SOLVED                      (2)
#define MYSTERY_STATE_SOLVED                          (3)
#define set_mystery_flag(x)                           if (get_mystery_flag(MYSTERY_STATE_ASSIGNED)) then begin       \
                                                         if (x == MYSTERY_STATE_SOLVED) then begin                   \
                                                            inc_reno_rep(REP_NEW_RENO_SOLVE_MURDER);                 \
                                                            inc_reno_rep(REP_NEW_RENO_SOLVE_MURDER_BONUS);           \
                                                         end else if (x == MYSTERY_STATE_BAD_SOLVED) then begin      \
                                                            inc_reno_rep(REP_NEW_RENO_SOLVE_MURDER);                 \
                                                         end                                                         \
                                                      end                                                            \
                                                      set_global_var(GVAR_NEW_RENO_WRIGHT_MYSTERY, x)
#define get_mystery_flag(x)                           (global_var(GVAR_NEW_RENO_WRIGHT_MYSTERY) == x)
#define clear_mystery                                 if (global_var(GVAR_NEW_RENO_WRIGHT_MYSTERY) == MYSTERY_STATE_ASSIGNED) then begin \
                                                         set_mystery_flag(MYSTERY_STATE_BAD_SOLVED);  \
                                                      end
// wrights end

// willie start
#define dug_up_willie                                 get_new_reno_flag(dug_up_willie_bit, 3)
#define set_dug_up_willie                             set_new_reno_flag_on(dug_up_willie_bit, 3)
// willie end

// salvatore start
#define saw_secret_trade                              get_new_reno_flag(saw_secret_trade_bit, 3)
#define set_saw_secret_trade                          set_new_reno_flag_on(saw_secret_trade_bit, 3)

#define obj_on_salvatore(x)                           ((obj_salvatore_casino(x)) or (obj_salvatore_2nd_floor(x)))
#define secret_trade_disrupted                        (get_new_reno_flag(secret_trade_bit, 1) or (Fallout2_enclave_destroyed))
#define secret_trade_nothing                          (secret_trade_disrupted == false)
#define set_secret_trade_disrupted                    if (secret_trade_nothing) then begin               \
                                                         dec_family_counter_amt(family_salvatore, 20);   \
                                                      end                                                \
                                                      set_new_reno_flag_on(secret_trade_bit, 1)

#define guard_assignment_none                         (0)
#define guard_assignment_mason                        (1)
#define guard_assignment_assigned                     (2)
#define guard_assignment_success                      (3)
#define guard_assignment_failed                       (4)
#define set_guard_assignment(x)                       set_global_var(GVAR_NEW_RENO_GUARD_ASSIGNMENT, x)
#define get_guard_assignment(x)                       (global_var(GVAR_NEW_RENO_GUARD_ASSIGNMENT) == x)
#define clear_guard_assignment                        if (global_var(GVAR_NEW_RENO_GUARD_ASSIGNMENT) >= guard_assignment_assigned) then begin \
                                                         set_guard_assignment(guard_assignment_failed);                                       \
                                                      end
// salvatore end
// bishop

// chop shop start
#define touched_stolen_car                            get_new_reno_flag(touched_stolen_car_bit, 2)
#define set_touched_stolen_car                        set_new_reno_flag_on(touched_stolen_car_bit, 2)

#define car_is_now_being_stolen                       get_new_reno_flag(car_is_now_being_stolen_bit, 3)
#define set_car_is_now_being_stolen                   set_new_reno_flag_on(car_is_now_being_stolen_bit, 3)
#define off_car_is_now_being_stolen                   set_new_reno_flag_off(car_is_now_being_stolen_bit, 3)

#define chop_shop_hostile                             get_new_reno_flag(chop_shop_hostile_bit, 4)
#define set_chop_shop_hostile                         set_new_reno_flag_on(chop_shop_hostile_bit, 4)

#define stolen_car_none                               (0)
#define stolen_car_stolen                             (1)
#define stolen_car_recovered                          (2)
#define stolen_car_drive_away                         (3)
#define set_stolen_car(x)                             if (global_var(GVAR_NEW_RENO_STOLEN_CAR) < x) then set_global_var(GVAR_NEW_RENO_STOLEN_CAR, x); \
                                                      ndebug("stolen_car state == "+global_var(GVAR_NEW_RENO_STOLEN_CAR))
#define get_stolen_car(x)                             (global_var(GVAR_NEW_RENO_STOLEN_CAR) == x)
#define car_at_chop_shop                              ((get_stolen_car(stolen_car_stolen)) or (get_stolen_car(stolen_car_recovered)))
#define car_was_stolen                                (global_var(GVAR_NEW_RENO_STOLEN_CAR) >= stolen_car_stolen)
#define car_at_new_reno_1                             (car_at_chop_shop == false)
#define car_has_been_recovered                        ((get_stolen_car(stolen_car_recovered)) or (get_stolen_car(stolen_car_drive_away)))

// t-ray
// these global vars seem switched, but that's the way it is due to a little mix up
#define get_super_car                                 (global_var(GVAR_NEW_RENO_CAR_UPGRADE) != 0)
#define set_super_car                                 if (get_super_car == false) then begin                   \
                                                         set_car_carry_amount((110*car_carry_amount) / 100);   \
                                                      end                                                      \
                                                      set_global_var(GVAR_NEW_RENO_CAR_UPGRADE, 1);            \
                                                      gfade_out(ONE_GAME_SECOND);                              \
                                                      game_time_advance(ONE_GAME_HOUR);                        \
                                                      gfade_in(ONE_GAME_SECOND)


#define get_ram_plate                                 (global_var(GVAR_NEW_RENO_SUPER_CAR) != 0)
#define set_ram_plate                                 if (get_ram_plate == false) then begin                      \
                                                         gfade_out(ONE_GAME_SECOND);                              \
                                                            game_time_advance(ONE_GAME_HOUR * 2);                 \
                                                            set_car_carry_amount((190*car_carry_amount) / 100);   \
                                                         gfade_in(ONE_GAME_SECOND);                               \
                                                      end                                                         \
                                                      set_global_var(GVAR_NEW_RENO_SUPER_CAR, 1)
// chop shop end
#define obj_on_bishop(x)                              ((obj_bishop_casino(x)) or (obj_bishop_2nd_floor(x)) or (obj_bishop_3rd_floor(x)) or (obj_bishop_boxing_arena(x)))

#define band_killed                                   get_new_reno_flag(band_killed_bit, 3)
#define set_band_killed                               set_new_reno_flag_on(band_killed_bit, 3)
// mordino start
#define obj_on_mordino(x)                             ((obj_mordino_casino(x)) or (obj_mordino_basement(x)) or (obj_mordino_2nd_floor(x)))

#define obj_on_family_property(the_obj, the_family)   (((the_family == family_salvatore) and (obj_on_salvatore(the_obj))) or   \
                                                       ((the_family == family_bishop) and (obj_on_bishop(the_obj))) or         \
                                                       ((the_family == family_mordino) and (obj_on_mordino(the_obj))) or       \
                                                       ((the_family == family_wright) and (obj_on_wright(the_obj))))

#define assassinated_big_jesus                        get_new_reno_flag(assassinated_big_jesus_bit, 2)
#define set_assassinated_big_jesus                    if (assassinated_big_jesus == false) then begin          \
                                                         display_mstr(875);                                    \
                                                         give_xp(EXP_NEW_RENO_ASSASSINATE_BIG_JESUS);          \
                                                         set_new_reno_flag_on(assassinated_big_jesus_bit, 2);  \
                                                      end                                                      \
                                                      set_big_jesus_dead

#define big_jesus_dead                                get_new_reno_flag(big_jesus_dead_bit, 2)
#define set_big_jesus_dead                            set_new_reno_flag_on(big_jesus_dead_bit, 2)

#define delivery_none                                 (0)
#define delivery_assigned                             (1)
#define delivery_delivered                            (2)
#define delivery_done                                 (3)
#define get_delivery(x)                               (global_var(GVAR_NEW_RENO_DELIVERY) == x)
#define set_delivery(x)                               if ((get_delivery(delivery_none)) and (x == delivery_done)) then begin                               \
                                                      end else if (x > global_var(GVAR_NEW_RENO_DELIVERY)) then set_global_var(GVAR_NEW_RENO_DELIVERY, x); \
                                                      ndebug("delivery == "+global_var(GVAR_NEW_RENO_DELIVERY))
#define clear_delivery                                set_delivery(delivery_done);

#define assassination_none                            (0)
#define assassination_assigned                        (1)
#define assassination_done                            (2)
#define get_assassination(x)                          (global_var(GVAR_NEW_RENO_ASSASSINATION) == x)
#define set_assassination(x)                          if ((x == assassination_done) and (get_assassination(assassination_none))) then begin \
                                                      end else set_global_var(GVAR_NEW_RENO_ASSASSINATION, x)
#define clear_assassination                           set_assassination(assassination_done);

#define lil_jesus_refers_none                         (0)
#define lil_jesus_refers_no                           (1)
#define lil_jesus_refers_yes                          (2)
#define lil_jesus_refers_slaver                       (3)
#define get_lil_jesus_refers(x)                       (global_var(GVAR_NEW_RENO_LIL_JESUS_REFERS) == x)
#define set_lil_jesus_refers(x)                       set_global_var(GVAR_NEW_RENO_LIL_JESUS_REFERS, x)

#define mordino_known                                 get_new_reno_flag(mordino_known_bit, 1)
#define set_mordino_known                             set_new_reno_flag_on(mordino_known_bit, 1)

// mordino end

// corsican bros start
#define bros_dead                                     get_new_reno_flag(bros_dead_bit, 2)
#define set_bros_dead                                 set_new_reno_flag_on(bros_dead_bit, 2)

#define fluf                                          get_new_reno_flag(flufer_bit, 2)
#define set_fluf                                      set_new_reno_flag_on(flufer_bit, 2)

#define porn_studio_hostile                           get_new_reno_flag(porn_studio_hostile_bit, 4)
#define set_porn_studio_hostile                       set_new_reno_flag_on(porn_studio_hostile_bit, 4)

#define extortion_bros_none                           (0)
#define extortion_bros_assigned                       (1)
#define extortion_bros_collected                      (2)
#define extortion_bros_done                           (3)
#define get_extortion_bros(x)                         (global_var(GVAR_NEW_RENO_EXTORTION_BROS) == x)
#define set_extortion_bros(x)                         if ((x == extortion_bros_done) and (get_extortion_bros(extortion_bros_none))) then begin \
                                                      end else set_global_var(GVAR_NEW_RENO_EXTORTION_BROS, x)
#define clear_extortion                               set_extortion_bros(extortion_bros_done);

#define making_porn                                   get_new_reno_flag(making_porn_bit, 2)
#define set_making_porn                               set_new_reno_flag_on(making_porn_bit, 2)
#define off_making_porn                               set_new_reno_flag_off(making_porn_bit, 2)
// corsican bros end

// tully start
#ifndef dude_has_booze
#define dude_has_booze                                ((obj_is_carrying_obj_pid(dude_obj, PID_ROENTGEN_RUM) > 0) or     \
                                                       (obj_is_carrying_obj_pid(dude_obj, PID_GAMMA_GULP_BEER) > 0) or  \
                                                       (obj_is_carrying_obj_pid(dude_obj, PID_BOOZE) > 0) or            \
                                                       (obj_is_carrying_obj_pid(dude_obj, PID_BEER) > 0) or             \
                                                       (obj_is_carrying_obj_pid(dude_obj, PID_ROT_GUT) > 0))
#endif
#define know_tully                                    get_new_reno_flag(know_tully_bit, 3)
#define set_know_tully                                set_new_reno_flag_on(know_tully_bit, 3)

#define tully_drinks                                  get_new_reno_flag(tully_drinks_bit, 3)
#define set_tully_drinks                              set_new_reno_flag_on(tully_drinks_bit, 3)

#define divorce                                       get_new_reno_flag(divorce_bit, 3)
#define set_divorce                                   set_new_reno_flag_on(divorce_bit, 3)

#define tully_dead                                    get_new_reno_flag(tully_dead_bit, 3)
#define set_tully_dead                                set_new_reno_flag_on(tully_dead_bit, 3)
// tully end

// get the property that critter is on
#define get_self_family(the_result)                   the_result := family_none;                                  \
                                                      if (obj_on_salvatore(self_obj)) then begin                  \
                                                         the_result := family_salvatore;                          \
                                                      end else if (obj_on_bishop(self_obj)) then begin            \
                                                         the_result := family_bishop;                             \
                                                      end else if (obj_on_mordino(self_obj)) then begin           \
                                                         the_result := family_mordino;                            \
                                                      end else if (obj_on_wright(self_obj)) then begin            \
                                                         the_result := family_wright;                             \
                                                      end                                                         \
                                                      ndebug("" + the_result)
// setting the correct team based on the family
#define set_family_team(the_family)                   if (the_family == family_salvatore) then begin                                         \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_SALVATORE);   \
                                                      end else if (the_family == family_bishop) then begin                                   \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_BISHOP);      \
                                                      end else if (the_family == family_mordino) then begin                                  \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_MORDINO);     \
                                                      end else if (the_family == family_wright) then begin                                   \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_WRIGHT);      \
                                                      end                                                                                    \
                                                      ndebug("")
#define get_and_set_family(temp)                      get_self_family(temp);           \
                                                      set_family_team(temp)
// kill family member
// see some of the macros in command.h
#define set_family_and_name(the_family,the_name)      set_global_var(GVAR_NEW_RENO_MADE_MAN, (the_family * 100) + the_name)
#define set_made_man_rep(the_fam, val)                set_global_var(GVAR_MADE_MAN_SALVATORE + the_fam - 1, val)
#define set_dude_family(x)                            if (x == family_salvatore) then begin                             \
                                                         set_made_man_rep(family_salvatore, 1);                         \
                                                         set_family_and_name(family_salvatore, dude_made_man_number);   \
                                                      end else if (x == family_bishop) then begin                       \
                                                         set_made_man_rep(family_bishop, 1);                            \
                                                         set_family_and_name(family_bishop, dude_made_man_number);      \
                                                      end else if (x == family_mordino) then begin                      \
                                                         set_made_man_rep(family_mordino, 1);                           \
                                                         set_family_and_name(family_mordino, dude_made_man_number);     \
                                                      end else if (x == family_wright) then begin                       \
                                                         set_made_man_rep(family_wright, 1);                            \
                                                         set_family_and_name(family_wright, dude_made_man_number);      \
                                                      end else if (x == family_none) then begin                         \
                                                         set_made_man_rep(family_salvatore, 0);                         \
                                                         set_made_man_rep(family_bishop, 0);                            \
                                                         set_made_man_rep(family_mordino, 0);                           \
                                                         set_made_man_rep(family_wright, 0);                            \
                                                         set_family_and_name(0, 0);                                     \
                                                      end

// attack family
#define clear_family_flags(x)                         if (x == family_salvatore) then begin           \
                                                         off_salvatore_permission                     \
                                                         clear_tribute                                \
                                                         clear_track_lloyd                            \
                                                         clear_guard_assignment                       \
                                                      end else if (x == family_bishop) then begin     \
                                                         off_bishop_permission                        \
                                                         /* To make sure delivery quest gets crossed off and Moore doesn't remind about it anymore */ \
                                                         if (global_var(GVAR_MOORE_ACCEPT_DELIVERY) == ACCEPT_DELIVERY_ASSIGNED) then begin  \
                                                            set_briefcase_flag(ACCEPT_DELIVERY_FAILED); \
                                                         end                                          \
                                                         clear_snuff_carlson                          \
                                                         clear_snuff_westin                           \
                                                      end else if (x == family_mordino) then begin    \
                                                         clear_delivery                               \
                                                         clear_extortion                              \
                                                         clear_assassination                          \
                                                      end else if (x == family_wright) then begin     \
                                                         set_sad_nothing;                             \
                                                         clear_mystery                                \
                                                         off_wright_flag(wright_permission_bit);      \
                                                      end
#define attack_family(x)                              clear_family_flags(x)                           \
                                                      set_family_warning_on(warning_attack, x);       \
                                                      if (x != family_none) then begin                \
                                                         if (x == dude_family) then begin             \
                                                            inc_reno_rep(REP_NEW_RENO_KILLED_BOSS);   \
                                                            set_dude_family(family_none)              \
                                                         end                                          \
                                                      end                                             \
                                                      ndebug("called attack family("+(nr_mstr(200 + x))+")");
// made man end
#define set_team_pimp                                 if (obj_pimp_team_1(self_obj)) then begin                                          \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_PIMP_1);  \
                                                      end else if (obj_pimp_team_2(self_obj)) then begin                                 \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_PIMP_2);  \
                                                      end else if (obj_pimp_team_3(self_obj)) then begin                                 \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_PIMP_3);  \
                                                      end else if (obj_pimp_team_4(self_obj)) then begin                                 \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_NEW_RENO_PIMP_4);  \
                                                      end

// these ones are for the guards themselves
#define check_wield_pid(x)                            if (obj_is_carrying_obj_pid(self_obj, x)>0) then begin   \
                                                         wield_obj(obj_carrying_pid_obj(self_obj, x));         \
                                                      end
#define wield_best_new_reno_weapon                    if (self_is_armed == false) then begin                \
                                                         if (anim_busy(self_obj) == false) then begin       \
                                                            check_wield_pid(PID_GREASE_GUN)                 \
                                                            else check_wield_pid(PID_LASER_PISTOL)          \
                                                            else check_wield_pid(PID_TOMMY_GUN)             \
                                                            else check_wield_pid(PID_COMBAT_SHOTGUN)        \
                                                            else check_wield_pid(PID_10MM_SMG)              \
                                                            else check_wield_pid(PID_SHOTGUN)               \
                                                            else check_wield_pid(PID_HUNTING_RIFLE)         \
                                                            else check_wield_pid(PID_44_MAGNUM_REVOLVER)    \
                                                            else check_wield_pid(PID_10MM_PISTOL)           \
                                                            else check_wield_pid(PID_THROWING_KNIFE)        \
                                                            else check_wield_pid(PID_SWITCHBLADE)           \
                                                            else check_wield_pid(PID_COMBAT_KNIFE)          \
                                                            else check_wield_pid(PID_KNIFE)                 \
                                                            else check_wield_pid(PID_SPIKED_KNUCKLES)       \
                                                         end                                                \
                                                      end

// golgotha
#define golgotha_known                                (town_known(AREA_GOLGATHA) != MARK_STATE_UNKNOWN)
#define set_golgotha_known                            mark_on_map(AREA_GOLGATHA)

// chop shop
#define chop_shop_known                               map_is_known(MAP_NEW_RENO_CHOP_SHOP)
#define set_chop_shop_known                           mark_area_known(MARK_TYPE_MAP, MAP_NEW_RENO_CHOP_SHOP, MARK_STATE_KNOWN)

// chop shop
#define stables_known                                 (town_known(AREA_RENO_STABLES) != MARK_STATE_UNKNOWN)
#define set_stables_known                             mark_on_map(AREA_RENO_STABLES)

// suspect
#define suspect_state_none                            (0)
#define suspect_state_suspect                         (1)
#define suspect_state_clear                           (2)
#define set_suspect(x)                                if (global_var(x) == suspect_state_none) then begin   \
                                                         set_global_var(x, suspect_state_suspect);          \
                                                      end
#define suspect_jagged_jimmy_j                        set_suspect(GVAR_NEW_RENO_SUSPECT_JJJ)
#define suspect_jules                                 set_suspect(GVAR_NEW_RENO_SUSPECT_JULES)
#define suspect_renesco                               set_suspect(GVAR_NEW_RENO_SUSPECT_LIL_JESUS)
#define suspect_lil_jesus                             set_suspect(GVAR_NEW_RENO_SUSPECT_RENESCO)

// tribute
#define tribute_none                                  (0)
#define tribute_mason                                 (1)
#define tribute_assigned                              (2)
#define tribute_refused                               (3)
#define tribute_failed                                (4)
#define tribute_collected                             (5)
#define tribute_salvatore                             (6)
#define tribute_done                                  (7)
#define set_tribute(x)                                set_global_var(GVAR_NEW_RENO_TRIBUTE, x)
#define get_tribute(x)                                (global_var(GVAR_NEW_RENO_TRIBUTE) == x)
#define clear_tribute                                 if (global_var(GVAR_NEW_RENO_TRIBUTE) >= tribute_assigned) then begin   \
                                                         set_tribute(tribute_done);                                           \
                                                      end

// pritchard
#define pritchard                                     get_new_reno_flag(pritchard_bit, 2)
#define set_pritchard                                 set_new_reno_flag_on(pritchard_bit, 2)

#define pritchard_exp                                 get_new_reno_flag(pritchard_exp_bit, 3)
#define set_pritchard_exp                             if (pritchard_exp == false) then begin             \
                                                         gfade_out(ONE_GAME_SECOND);                     \
                                                            game_time_advance(ONE_GAME_MINUTE * 15);     \
                                                            script_overrides;                            \
                                                            give_xp(EXP_NEW_RENO_PRITCHARD_GRAVE);       \
                                                            mark_sierra_army_base_on_map                 \
                                                            display_mstr(150);                           \
                                                         gfade_in(ONE_GAME_SECOND);                      \
                                                      end                                                \
                                                      set_new_reno_flag_on(pritchard_exp_bit, 3)

// lloyd
#define uncovered_lloyd_grave                         get_new_reno_flag(uncovered_lloyd_grave_bit, 2)
#define set_uncovered_lloyd_grave                     set_new_reno_flag_on(uncovered_lloyd_grave_bit, 2)
#define off_uncovered_lloyd_grave                     set_new_reno_flag_off(uncovered_lloyd_grave_bit, 2)
// took money
#define lloyd_took_money                              get_new_reno_flag(lloyd_took_money_bit, 1)
#define set_lloyd_took_money                          set_new_reno_flag_on(lloyd_took_money_bit, 1)
// tiles
#define under_grave_tile_dude                         (22295)
#define under_grave_tile_lloyd                        (21901)
#define mordino_grave_tile                            (20117)
// took money
#define lloyd_took_money                              get_new_reno_flag(lloyd_took_money_bit, 1)
#define set_lloyd_took_money                          set_new_reno_flag_on(lloyd_took_money_bit, 1)
// treasure
#define lloyd_treasure                                get_new_reno_flag(treasure_bit, 1)
#define set_lloyd_treasure                            set_new_reno_flag_on(treasure_bit, 1)
// escape
#define escape_none                                   (0)
#define escape_bodyguard                              (1)
#define escape_threaten                               (2)
#define escape_follow                                 (3)
#define escape_half                                   (4)
#define escape_all                                    (5)
#define escape_betrayed                               (6)
#define escape_nikki                                  (7)
#define set_escape(x)                                 set_global_var(GVAR_NEW_RENO_ESCAPE, x)
#define get_escape(x)                                 (global_var(GVAR_NEW_RENO_ESCAPE) == x)
// locale
#define lloyd_locale_desperado                        get_new_reno_flag(lloyd_locale_desperado_bit, 1)
#define set_lloyd_locale_desperado                    set_new_reno_flag_on(lloyd_locale_desperado_bit, 1)
#define lloyd_locale_upstairs                         get_new_reno_flag(lloyd_locale_upstairs_bit, 1)
#define set_lloyd_locale_upstairs                     set_new_reno_flag_on(lloyd_locale_upstairs_bit, 1)
// dead
#define lloyd_dead                                    get_new_reno_flag(lloyd_dead_bit, 1)
#define set_lloyd_dead                                set_new_reno_flag_on(lloyd_dead_bit, 1)
// tracking lloyd
#define track_lloyd_none                              (0)
#define track_lloyd_mason                             (1)
#define track_lloyd_assigned                          (2)
#define track_lloyd_salvatore                         (3)
#define track_lloyd_done                              (4)
#define track_lloyd_nikki_done                        (5)
#define get_track_lloyd(x)                            (global_var(GVAR_NEW_RENO_TRACK_LLOYD) == x)
#define set_track_lloyd(x)                            set_global_var(GVAR_NEW_RENO_TRACK_LLOYD, x)
#define clear_track_lloyd                             if (global_var(GVAR_NEW_RENO_TRACK_LLOYD) >= track_lloyd_assigned) then begin \
                                                         set_track_lloyd(track_lloyd_done);                                         \
                                                      end
#define nikki_lloyd                                   get_new_reno_flag(nikki_lloyd_bit, 1)
#define set_nikki_lloyd                               set_new_reno_flag_on(nikki_lloyd_bit, 1)

// renesco
#define set_know_renesco                              set_new_reno_flag_on(know_renesco_bit, 1)
#define know_renesco                                  get_new_reno_flag(know_renesco_bit, 1)
#define mine_reward_cash                              (global_var(GVAR_BH_MINE) == MINE_REWARD_CASH)
#define mine_reward_free                              (global_var(GVAR_BH_MINE) == MINE_REWARD_FREE)
#define set_mine_has_tools                            set_global_var(GVAR_BH_MINE, global_var(GVAR_BH_MINE) + (MINE_HAS_PARTS_CASH - MINE_REWARD_CASH))
#define renesco_slander                               get_new_reno_flag(renesco_slander_bit, 1)
#define set_renesco_slander                           set_new_reno_flag_on(renesco_slander_bit, 1)
#define dude_has_renesco_spectacles                   (obj_is_carrying_obj_pid(dude_obj, PID_SPECTACLES) > 0)
#define remove_spectacles_from_dude                   remove_pid_qty(dude_obj, PID_SPECTACLES, 1)
#define dude_has_empty_jet_canister                   (obj_is_carrying_obj_pid(dude_obj, PID_EMPTY_JET))
#define renesco_dead                                  get_new_reno_flag(renesco_dead_bit, 1)
#define set_renesco_dead                              set_new_reno_flag_on(renesco_dead_bit, 1)
#define off_renesco_dead                              set_new_reno_flag_off(renesco_dead_bit, 1)

// jules
#define jules_dead                                    get_new_reno_flag(jules_dead_bit, 1)
#define set_jules_dead                                set_new_reno_flag_on(jules_dead_bit, 1)

#define jules_slander                                 get_new_reno_flag(jules_slander_bit, 1)
#define set_jules_slander                             set_new_reno_flag_on(jules_slander_bit, 1)

#define know_jules                                    get_new_reno_flag(know_jules_bit, 2)
#define set_know_jules                                set_new_reno_flag_on(know_jules_bit, 2)

#define monte_fingered_jules                          get_new_reno_flag(monte_fingered_jules_bit, 2)
#define set_monte_fingered_jules                      set_new_reno_flag_on(monte_fingered_jules_bit, 2)

#define jules_eldridge_none                           (0)
#define jules_eldridge_refer                          (1)
#define jules_eldridge_discount                       (2)
#define set_jules_eldridge(x)                         set_global_var(GVAR_NEW_RENO_JULES_ELDRIDGE, x)
#define get_jules_eldridge(x)                         (global_var(GVAR_NEW_RENO_JULES_ELDRIDGE) == x)

#define jules_kitty_none                              (0)
#define jules_kitty_refer                             (1)
#define jules_kitty_discount                          (2)
#define set_jules_kitty(x)                            set_global_var(GVAR_NEW_RENO_JULES_KITTY, x)
#define get_jules_kitty(x)                            (global_var(GVAR_NEW_RENO_JULES_KITTY) == x)

// kitty
#define MAGAZINES_NOTHING                             (0)
#define MAGAZINES_ASSIGNED                            (1)
#define MAGAZINES_DONE                                (2)
#define get_magazines(x)                              (global_var(GVAR_NEW_RENO_KITTY_MAGAZINES) == x)
#define set_magazines(x)                              if ((x == MAGAZINES_DONE) and (get_magazines(MAGAZINES_DONE) == false)) then begin  \
                                                         display_mstr(800);                                                               \
                                                         inc_reno_rep(REP_NEW_RENO_KITTY_MAGAZINES);                                      \
                                                         give_xp(EXP_NEW_RENO_KITTY_MAGAZINES);                                           \
                                                      end                                                                                 \
                                                      if (global_var(GVAR_NEW_RENO_KITTY_MAGAZINES) < x) then set_global_var(GVAR_NEW_RENO_KITTY_MAGAZINES, x)
#define no_whore_floats                               get_new_reno_flag(no_whore_floats_bit, 2)
#define set_no_whore_floats                           set_new_reno_flag_on(no_whore_floats_bit, 2)
#define off_no_whore_floats                           set_new_reno_flag_off(no_whore_floats_bit, 2)

// eldridge
#define eldrdige_closed                               (night)
#define eldridge_open                                 ((game_time_hour >= 600) and (game_time_hour <= 2100))
#define eldridge_front_room_tile                      (26719)
#define eldridge_back_room_tile                       (23110)
#define tile_is_eldridge_front_door(x)                (x == 27920)
#define eldridge_dead                                 get_new_reno_flag(eldridge_dead_bit, 2)
#define set_eldridge_dead                             set_new_reno_flag_on(eldridge_dead_bit, 2)

#define eldridge_bed_time                             get_new_reno_flag(eldridge_bed_time_bit, 3)
#define set_eldridge_bed_time                         set_new_reno_flag_on(eldridge_bed_time_bit, 3)
#define off_eldridge_bed_time                         set_new_reno_flag_off(eldridge_bed_time_bit, 3)

#define fetch_laser_none                              (0)
#define fetch_laser_assigned                          (1)
#define fetch_laser_given                             (2)
#define get_fetch_laser(x)                            (global_var(GVAR_NEW_RENO_ELDRIDGE_PISTOL_QUEST) == x)
#define set_fetch_laser(x)                            set_global_var(GVAR_NEW_RENO_ELDRIDGE_PISTOL_QUEST, x)

// algernon
#define know_algernon                                 get_new_reno_flag(know_algernon_bit, 2)
#define set_know_algernon                             set_new_reno_flag_on(know_algernon_bit, 2)

#define know_algernon_weapons                         get_new_reno_flag(know_algernon_weapons_bit, 2)
#define set_know_algernon_weapons                     set_new_reno_flag_on(know_algernon_weapons_bit, 2)

#define know_algernon_fake_death                      get_new_reno_flag(know_algernon_fake_death_bit, 2)
#define set_know_algernon_fake_death                  set_new_reno_flag_on(know_algernon_fake_death_bit, 2)

#define algernon_dead                                 get_new_reno_flag(algernon_dead_bit, 2)
#define set_algernon_dead                             set_new_reno_flag_on(algernon_dead_bit, 2)

// jagged jimmy j
#define jjj_dead                                      get_new_reno_flag(jjj_dead_bit, 1)
#define set_jjj_dead                                  set_new_reno_flag_on(jjj_dead_bit, 1)

#define jjj_slander                                   get_new_reno_flag(jjj_slander_bit, 1)
#define set_jjj_slander                               set_new_reno_flag_on(jjj_slander_bit, 1)

#define jet_canister_poison                           get_new_reno_flag(jet_canister_poison_bit, 1)
#define set_jet_canister_poison                       set_new_reno_flag_on(jet_canister_poison_bit, 1)

#define know_jjj                                      get_new_reno_flag(know_jjj_bit, 2)
#define set_know_jjj                                  set_new_reno_flag_on(know_jjj_bit, 2)

#define jjj_truth                                     get_new_reno_flag(jjj_truth_bit, 2)
#define set_jjj_truth                                 set_new_reno_flag_on(jjj_truth_bit, 2)

// cody
#define look_cody                                     get_new_reno_flag(look_cody_bit, 2)
#define set_look_cody                                 set_new_reno_flag_on(look_cody_bit, 2)

#define cody_fingered_jules                           get_new_reno_flag(cody_fingered_jules_bit, 2)
#define set_cody_fingered_jules                       set_new_reno_flag_on(cody_fingered_jules_bit, 2)

#define know_cody                                     get_new_reno_flag(know_cody_bit, 3)
#define set_know_cody                                 set_new_reno_flag_on(know_cody_bit, 3)

#define cody_dead                                     get_new_reno_flag(cody_dead_bit, 2)
#define set_cody_dead                                 set_new_reno_flag_on(cody_dead_bit, 2)

#define jules_killed_cody                             get_new_reno_flag(jules_killed_cody_bit, 2)
#define set_jules_killed_cody                         set_cody_dead;                                  \
                                                      set_new_reno_flag_on(jules_killed_cody_bit, 2)

#define jules_warned                                  get_new_reno_flag(jules_warned_bit, 3)
#define set_jules_warned                              if (jules_warned == false) then begin                 \
                                                         inc_general_rep(REP_BONUS_NEW_RENO_SCARE_JULES);   \
                                                         inc_reno_rep(REP_NEW_RENO_SCARE_JULES);            \
                                                      end                                                   \
                                                      set_new_reno_flag_on(jules_warned_bit, 3)

#define cody_knows_car                                get_new_reno_flag(cody_knows_car_bit, 2)
#define set_cody_knows_car                            set_new_reno_flag_on(cody_knows_car_bit, 2)

// scott
#define set_know_scott                                set_new_reno_flag_on(know_scott_bit, 1)
#define know_scott                                    get_new_reno_flag(know_scott_bit, 1)

// mcgee's macros start
#define mcgee_family                                  (family_bishop)
#define mcgee_state_none                              (0)
#define mcgee_state_played_machine                    (1)
#define mcgee_state_jackpot                           (2)
#define mcgee_state_jackpot_settled                   (3)
#define mcgee_none                                    (global_var(GVAR_NEW_RENO_MCGEE_SEED) == mcgee_state_none)
#define mcgee_played_machine                          (global_var(GVAR_NEW_RENO_MCGEE_SEED) == mcgee_state_played_machine)
#define mcgee_jackpot                                 (global_var(GVAR_NEW_RENO_MCGEE_SEED) == mcgee_state_jackpot)
#define mcgee_jackpot_settled                         (global_var(GVAR_NEW_RENO_MCGEE_SEED) == mcgee_state_jackpot_settled)
//killap comment out
//#define set_mcgee_played_machine                      if (mcgee_state_none) then begin                                \
//                                                         set_global_var(GVAR_NEW_RENO_MCGEE_SEED, mcgee_state_played_machine);   \
//                                                      end
#define set_mcgee_played_machine                      set_global_var(GVAR_NEW_RENO_MCGEE_SEED, mcgee_state_played_machine);  //killap

#define set_mcgee_jackpot_settled                     set_global_var(GVAR_NEW_RENO_MCGEE_SEED, mcgee_state_jackpot_settled);
#define dude_leaving_mcgee_casino                     (tile_bishop_casino(dude_tile) == false)
#define mcgee_playing_slots                           (tile_distance_objs(mcGeeOBJ,mcGeeSlotMachineOBJ) <= 2)

#define mcgee_known_state_none                        (0)
#define mcgee_known_state_known                       (1)
#define mcgee_known_state_dead                        (-1)
#define mcgee_known                                   (global_var(GVAR_NEW_RENO_MCGEE_KNOWN) == mcgee_known_state_known)
#define mcgee_unknown                                 (global_var(GVAR_NEW_RENO_MCGEE_KNOWN) == mcgee_known_state_none)
#define mcgee_dead                                    (global_var(GVAR_NEW_RENO_MCGEE_KNOWN) == mcgee_known_state_dead)
#define set_mcgee_known                               set_global_var(GVAR_NEW_RENO_MCGEE_KNOWN, mcgee_known_state_known)
#define set_mcgee_dead                                set_global_var(GVAR_NEW_RENO_MCGEE_KNOWN, mcgee_known_state_dead)
// mcgee's macros end

// lil' jesus start
#define lil_jesus_family                              (family_mordino)
#define lil_jesus_state_none                          (0)
#define lil_jesus_state_dead                          (-1)
#define lil_jesus_dead                                (get_new_reno_flag(lil_jesus_dead_bit, 1))
#define set_lil_jesus_dead                            set_new_reno_flag_on(lil_jesus_dead_bit, 1)
#define stables_mordino_is_mission                    (false) // ###
#define know_lil_jesus                                (get_new_reno_flag(know_lil_jesus_bit, 1))
#define set_know_lil_jesus                            set_new_reno_flag_on(know_lil_jesus_bit, 1)
#define lil_jesus_dealer                              (get_new_reno_flag(lil_jesus_dealer_bit, 2))
#define set_lil_jesus_dealer                          set_new_reno_flag_on(lil_jesus_dealer_bit, 2)
// lil' jesus end

// marjorie reed start
#define marjorie_called_guards                        (get_new_reno_flag(marjorie_called_guards_bit, 1))
#define set_marjorie_called_guards                    set_new_reno_flag_on(marjorie_called_guards_bit, 1)
#define off_marjorie_called_guards                    set_new_reno_flag_off(marjorie_called_guards_bit, 1)
// marjorie reed end

// sierra_army_depot
#define sad_state_nothing                             (0)
#define sad_state_assigned                            (1)
#define sad_state_done                                (2)
#define set_sad(x)                                    if (x > global_var(GVAR_NEW_RENO_SAD)) then set_global_var(GVAR_NEW_RENO_SAD, x)
#define get_sad(x)                                    (global_var(GVAR_NEW_RENO_SAD) == x)
#define sad_nothing                                   get_sad(sad_state_nothing)
#define set_sad_nothing                               set_sad(sad_state_nothing)
#define sad_assigned                                  get_sad(sad_state_assigned)
#define set_sad_assigned                              set_sad(sad_state_assigned)
#define sad_done                                      get_sad(sad_state_done)
#define force_sad_done                                set_sad(sad_state_done)
#define set_sad_done                                  set_sad_got_in;                           \
                                                      if (sad_assigned) then force_sad_done
#define sad_got_in                                    ((get_new_reno_flag(did_enter_base_bit, 3)) or (sad_done))
#define set_sad_got_in                                set_new_reno_flag_on(did_enter_base_bit, 3)
#define sad_contaminated                              (global_var(GVAR_SIERRA_BASE_CONTAMINATION_TIMER) != 0)

// carlson start
#define snuff_carlson_none                            (0)
#define snuff_carlson_assigned                        (1)
#define snuff_carlson_succeed                         (2)
#define get_snuff_carlson(x)                          (global_var(GVAR_NEW_RENO_CARLSON_SNUFF_PIP) == x)
#define set_snuff_carlson(x)                          if (x == snuff_carlson_assigned) then begin                                                \
                                                         if (get_snuff_carlson(snuff_carlson_none)) then begin                                   \
                                                            inc_general_rep(REP_BONUS_ACCEPT_CARLSON_HIT);                                       \
                                                         end                                                                                     \
                                                         set_carlson_flag(CARLSON_ACCEPT_SNUFF);                                                 \
                                                      end                                                                                        \
                                                      if ((x == snuff_carlson_succeed) and (get_snuff_carlson(snuff_carlson_none))) then begin   \
                                                      end else if (x > global_var(GVAR_NEW_RENO_CARLSON_SNUFF_PIP)) then set_global_var(GVAR_NEW_RENO_CARLSON_SNUFF_PIP, x)
#define clear_snuff_carlson                           set_snuff_carlson(snuff_carlson_succeed);
#define carlson_nothing                               ((get_snuff_carlson(snuff_carlson_none)) and (carlson_dead == false))
#define carlson_price                                 (global_var(GVAR_NEW_RENO_CARLSON_PRICE))
#define carlson_price_nothing                         (carlson_price == -1)
#define set_carlson_price(x)                          set_global_var(GVAR_NEW_RENO_CARLSON_PRICE, x);
// carlson end

// westin start
#define snuff_westin_none                             (0)
#define snuff_westin_assigned                         (1)
#define snuff_westin_fail                             (2)
#define snuff_westin_succeed                          (3)
#define get_snuff_westin(x)                           (global_var(GVAR_NEW_RENO_WESTIN_SNUFF_PIP) == x)
#define set_snuff_westin(x)                           if (x == snuff_westin_assigned) then begin                                          \
                                                         if (get_snuff_westin(snuff_westin_none)) then begin                              \
                                                            inc_general_rep(REP_BONUS_ACCEPT_WESTIN_HIT);                                 \
                                                         end                                                                              \
                                                         set_westin_flag(WESTIN_ACCEPT_SNUFF);                                            \
                                                      end                                                                                 \
                                                      if ((x >= snuff_westin_fail) and (get_snuff_westin(snuff_westin_none))) then begin  \
                                                      end else if (x > global_var(GVAR_NEW_RENO_WESTIN_SNUFF_PIP)) then set_global_var(GVAR_NEW_RENO_WESTIN_SNUFF_PIP, x)
#define westin_nothing                                ((get_snuff_westin(snuff_westin_none)) and (westin_dead == false))
#define clear_snuff_westin                            set_snuff_westin(snuff_westin_fail);
#define westin_price                                  (global_var(GVAR_NEW_RENO_WESTIN_PRICE))
#define westin_price_nothing                          (westin_price == -1)
#define set_westin_price(x)                           set_global_var(GVAR_NEW_RENO_WESTIN_PRICE, x);
// westin end

// john bishop start
#define bishop_raiders                                get_new_reno_flag(bishop_raiders_bit, 3)
#define set_bishop_raiders                            set_new_reno_flag_on(bishop_raiders_bit, 3)

#define raiders_secret_enterance                      get_new_reno_flag(raiders_secret_enterance_bit, 3)
#define set_raiders_secret_enterance                  mark_on_map(AREA_RAIDERS)                             \
                                                      set_new_reno_flag_on(raiders_secret_enterance_bit, 3)

#define bishop_room_tile                              (11287)

#define corvega_bishop                                get_new_reno_flag(corvega_bishop_bit, 1)
#define set_corvega_bishop                            set_new_reno_flag_on(corvega_bishop_bit, 1)

#define bishop_snuff                                  (get_bishop_flag(BISHOP_ACCEPT_SNUFF))

#define bishop_dead                                   status_is_dead(GVAR_NEW_RENO_BISHOP)
#define set_bishop_dead                               if (bishop_dead == false) then begin                                                                     \
                                                         if ((get_snuff_westin(snuff_westin_assigned)) and (get_bishop_flag(BISHOP_ACCEPT_SNUFF))) then begin  \
                                                            inc_general_rep(REP_BONUS_BETRAY_BISHOP);                                                          \
                                                         end                                                                                                   \
                                                      end                                                                                                      \
                                                      set_bishop_flag(BISHOP_DEAD);                                                                            \
                                                      set_status_dead(GVAR_NEW_RENO_BISHOP)

#define bishop_permission                             status_is_special(GVAR_NEW_RENO_BISHOP)
#define set_bishop_permission                         set_status_special(GVAR_NEW_RENO_BISHOP)
#define off_bishop_permission                         change_status_off(GVAR_NEW_RENO_BISHOP, PERSON_SPECIAL)

#define bishop_warning                                status_is_warned(GVAR_NEW_RENO_BISHOP)
#define set_bishop_warning                            set_status_warned(GVAR_NEW_RENO_BISHOP)

#define bishop_known                                  status_is_known(GVAR_NEW_RENO_BISHOP)
#define set_bishop_known                              set_status_known(GVAR_NEW_RENO_BISHOP)

#define bishop_known_personally                       status_is_spoken_to(GVAR_NEW_RENO_BISHOP)
#define set_bishop_known_personally                   set_status_spoken_to(GVAR_NEW_RENO_BISHOP)
// john bishop end

// louis salvatore start
#define is_salvatore_door                             ((self_tile == 27316) and (cur_map_index == MAP_NEW_RENO_2) and (self_elevation == 1))

#define salvatore_dead                                status_is_dead(GVAR_NEW_RENO_SALVATORE)
#define set_salvatore_dead                            set_status_dead(GVAR_NEW_RENO_SALVATORE)

#define salvatore_assassinated                        status_is_assassinated(GVAR_NEW_RENO_SALVATORE)
#define set_salvatore_assassinated                    set_status_assassinated(GVAR_NEW_RENO_SALVATORE)

#define salvatore_permission                          status_is_special(GVAR_NEW_RENO_SALVATORE)
#define set_salvatore_permission                      set_status_special(GVAR_NEW_RENO_SALVATORE)
#define off_salvatore_permission                      change_status_off(GVAR_NEW_RENO_SALVATORE, PERSON_SPECIAL)

#define salvatore_warning                             status_is_warned(GVAR_NEW_RENO_SALVATORE)
#define set_salvatore_warning                         set_status_warned(GVAR_NEW_RENO_SALVATORE)

#define salvatore_known                               status_is_known(GVAR_NEW_RENO_SALVATORE)
#define set_salvatore_known                           set_status_known(GVAR_NEW_RENO_SALVATORE)

#define salvatore_known_personally                    status_is_spoken_to(GVAR_NEW_RENO_SALVATORE)
#define set_salvatore_known_personally                set_status_spoken_to(GVAR_NEW_RENO_SALVATORE)
// salvatore guard assignment
#define know_lasers                                   get_new_reno_flag(know_lasers_bit, 1)
#define set_know_lasers                               set_new_reno_flag_on(know_lasers_bit, 1)

#define thousand_caps                                 get_new_reno_flag(thousand_caps_bit, 1)
#define set_thousand_caps                             set_new_reno_flag_on(thousand_caps_bit, 1)

#define salvatore_done                                get_new_reno_flag(salvatore_done_bit, 1)
#define set_salvatore_done                            clear_family_flags(family_salvatore)         \
                                                      set_new_reno_flag_on(salvatore_done_bit, 1)

// nikki
#define nikki_dead                                    get_new_reno_flag(nikki_dead_bit, 1)
#define set_nikki_dead                                set_new_reno_flag_on(nikki_dead_bit, 1)

#define nikki_bribed                                  get_new_reno_flag(nikki_bribed_bit, 1)
#define set_nikki_bribed                              set_new_reno_flag_on(nikki_bribed_bit, 1)

#define nikki_lead                                    get_new_reno_flag(nikki_lead_bit, 1)
#define set_nikki_lead                                set_new_reno_flag_on(nikki_lead_bit, 1)

#define nikki_intro                                   get_new_reno_flag(nikki_intro_bit, 1)
#define set_nikki_intro                               set_new_reno_flag_on(nikki_intro_bit, 1)

// call guards
#define salvatore_called_guards                       get_new_reno_flag(salvatore_call_guards_bit, 1)
#define set_salvatore_called_guards_on                set_new_reno_flag_on(salvatore_call_guards_bit, 1);    \
                                                      attack_family(family_salvatore)
#define set_salvatore_called_guards_off               set_new_reno_flag_off(salvatore_call_guards_bit, 1)

// respect
#define salvatore_respect                             (global_var(GVAR_NEW_RENO_SALVATORE_RESPECT))
#define inc_salvatore_respect(x)                      inc_global_var_amt(GVAR_NEW_RENO_SALVATORE_RESPECT,x)
#define dec_salvatore_respect(x)                      dec_global_var_amt(GVAR_NEW_RENO_SALVATORE_RESPECT,x)

// tracking lloyd
#define salvatore_pistol_none                         (0)
#define salvatore_pistol_mason                        (1)
#define salvatore_pistol_received                     (2)
#define set_salvatore_pistol(x)                       set_global_var(GVAR_NEW_RENO_SALVATORE_PISTOL, x)
#define get_salvatore_pistol(x)                       (global_var(GVAR_NEW_RENO_SALVATORE_PISTOL) == x)
// louis salvatore end

// angela bishop start
#define angela_bed_tile                               (13289)
#define angela_bed_rotation                           (2)
#define angela_self_room_elev                         (2)
#define angela_self_room_tile                         (14089)
#define angela_dude_room_tile                         (14087)

#define angela_dead                                   status_is_dead(GVAR_NEW_RENO_ANGELA)
#define set_angela_dead                               set_status_dead(GVAR_NEW_RENO_ANGELA)

#define angela_rejected                               status_is_special(GVAR_NEW_RENO_ANGELA)
#define set_angela_rejected                           set_status_special(GVAR_NEW_RENO_ANGELA)

#define angela_banged                                 status_is_sex(GVAR_NEW_RENO_ANGELA)
#define set_angela_banged                             set_status_sex(GVAR_NEW_RENO_ANGELA)

#define angela_known                                  status_is_known(GVAR_NEW_RENO_ANGELA)
#define set_angela_known                              set_status_known(GVAR_NEW_RENO_ANGELA)

#define angela_rape                                   status_is_spoken_to_special(GVAR_NEW_RENO_ANGELA)
#define set_angela_rape                               set_status_spoken_to_special(GVAR_NEW_RENO_ANGELA)

#define angela_pregnant                               status_is_special_2(GVAR_NEW_RENO_ANGELA)
#define set_angela_pregnant                           set_status_special_2(GVAR_NEW_RENO_ANGELA)
#define off_angela_pregnant                           off_status_special_2(GVAR_NEW_RENO_ANGELA)

// angela bishop end

// mrs bishop start
#define mrs_bishop_self_bed_tile                      (15891)
#define mrs_bishop_dude_bed_tile                      (15890)
#define mrs_bishop_bed_rotation                       (2)
#define mrs_bishop_room_elev                          (2)
#define mrs_bishop_self_room_tile                     (16690)
#define mrs_bishop_dude_room_tile                     (16688)

#define mrs_b_combo_1                                 (global_var(GVAR_NEW_RENO_MRS_BISHOP_COMBINATION) / 10000)
#define mrs_b_combo_2                                 (((global_var(GVAR_NEW_RENO_MRS_BISHOP_COMBINATION) / 100)) % 100)
#define mrs_b_combo_3                                 (global_var(GVAR_NEW_RENO_MRS_BISHOP_COMBINATION) % 100)
#define mrs_bishop_combination                        ("" + mrs_b_combo_1 + " - " + mrs_b_combo_2 + " - " + mrs_b_combo_3)
#define know_mrs_bishop_combination                   (global_var(GVAR_NEW_RENO_MRS_BISHOP_COMBINATION) != 0)
#define random_combination                            ((random(1,99) * 10000) + (random(1,99) * 100) + random(1,99))
#define set_mrs_bishop_combination                    set_global_var(GVAR_NEW_RENO_MRS_BISHOP_COMBINATION, random_combination);  \
                                                      ndebug("   set_mrs_bishop_combination == "+mrs_bishop_combination);
#define check_mrs_bishop_combination                  if (global_var(GVAR_NEW_RENO_MRS_BISHOP_COMBINATION) == 0) then begin                    \
                                                         if (obj_on_screen(self_obj)) then begin                              \
                                                             set_mrs_bishop_combination                                       \
                                                         end                                                                  \
                                                      end                                                                        \
                                                      ndebug("check_mrs_bishop_combination == "+mrs_bishop_combination);
#define compartment                                   get_new_reno_flag(compartment_bit, 3)
#define set_compartment                               if (compartment == false) then begin                              \
                                                         give_pid_qty(mrs_bishop_safe_obj, PID_DERMAL_PIP_BOY_DISK, 1)  \
                                                      end                                                               \
                                                      set_new_reno_flag_on(compartment_bit, 3)

#define mrs_bishop_dead                               status_is_dead(GVAR_NEW_RENO_MRS_BISHOP)
#define set_mrs_bishop_dead                           set_status_dead(GVAR_NEW_RENO_MRS_BISHOP)

#ifndef mrs_bishop_rejected
#define mrs_bishop_rejected                           status_is_special(GVAR_NEW_RENO_MRS_BISHOP)
#endif
#ifndef set_mrs_bishop_rejected
#define set_mrs_bishop_rejected                       set_status_special(GVAR_NEW_RENO_MRS_BISHOP)
#endif

#define mrs_bishop_banged                             status_is_sex(GVAR_NEW_RENO_MRS_BISHOP)
#define set_mrs_bishop_banged                         set_status_sex(GVAR_NEW_RENO_MRS_BISHOP)

#define mrs_bishop_pregnant                           status_is_special_2(GVAR_NEW_RENO_MRS_BISHOP)
#define set_mrs_bishop_pregnant                       set_status_special_2(GVAR_NEW_RENO_MRS_BISHOP)

#define mrs_bishop_known                              status_is_known(GVAR_NEW_RENO_MRS_BISHOP)
#define set_mrs_bishop_known                          set_status_known(GVAR_NEW_RENO_MRS_BISHOP)

#define trap_safe                                     get_new_reno_flag(trap_safe_bit, 3)
#define set_trap_safe                                 set_new_reno_flag_on(trap_safe_bit, 3)

#define mrs_bishop_warning                            get_new_reno_flag(mrs_bishop_warning_bit, 3)
#define set_mrs_bishop_warning                        set_new_reno_flag_on(mrs_bishop_warning_bit, 3)

#define mrs_bishop_win                                get_new_reno_flag(mrs_bishop_win_bit, 3)
#define set_mrs_bishop_win                            if (mrs_bishop_win == false) then begin               \
                                                         inc_reno_rep(REP_NEW_RENO_MRS_BISHOP_CONVINCE);    \
                                                      end                                                   \
                                                      set_new_reno_flag_on(mrs_bishop_win_bit, 3)

#define mrs_bishop_rape                               status_is_spoken_to_special(GVAR_NEW_RENO_MRS_BISHOP)
#define set_mrs_bishop_rape                           set_status_spoken_to_special(GVAR_NEW_RENO_MRS_BISHOP)

#define vault_city_wrong_place                        get_new_reno_flag(vault_city_wrong_place_bit, 3)
#define set_vault_city_wrong_place                    set_new_reno_flag_on(vault_city_wrong_place_bit, 3)

#define mr_bishop_safe_none                           (0)
#define mr_bishop_safe_touched                        (1)
#define mr_bishop_safe_know                           (2)
#define set_mr_bishop_safe(x)                         if (global_var(GVAR_MR_BISHOP_SAFE) < x) then set_global_var(GVAR_MR_BISHOP_SAFE, x)
#define mr_bishop_safe(x)                             (global_var(GVAR_MR_BISHOP_SAFE) == x)

#define call_bishop_safe_guard                        if (bishop_roof_guard_obj != 0) then begin                                 \
                                                         help_me_obj := self_obj;                                                \
                                                         nr_add_timer_event(bishop_roof_guard_obj, 0, heard_explosion_param);    \
                                                      end
// mrs bishop end

// bishop stairs start
#define bishop_assassinated                           get_new_reno_flag(bishop_assassinated_bit, 3)
#define set_bishop_assassinated                       set_new_reno_flag_on(bishop_assassinated_bit, 3)
/*
#define bishop_stair_guard_tile                       (17873)
#define bishop_stair_guard_dir                        (4)
#define stair_state_no_guard                          (0)
#define stair_state_has_guard                         (1)
#define stair_state_used_stairs                       (2)
#define get_stair_state                               (map_var(MVAR_STAIR_GUARD))
#define set_stair_state(x)                            set_map_var(MVAR_STAIR_GUARD, x)
#define used_bishop_stairs                            get_stair_state == stair_state_used_stairs
#define off_used_bishop_stairs                        set_stair_state(stair_state_has_guard)
#define set_used_bishop_stairs                        set_stair_state(stair_state_used_stairs)
#define obj_in_bishop_stair_loc(x)                    obj_in_loc(x, 17078, 17062, 19462, 19478, MAP_NEW_RENO_2, 1)
*/
// bishop stairs end

// briefcase start
// NEW RENO / NCR / VAULT CITY
#define get_briefcase_flag(x)                         (global_var(GVAR_MOORE_ACCEPT_DELIVERY) == x)
#define set_briefcase_flag(x)                         set_global_var(GVAR_MOORE_ACCEPT_DELIVERY, x)

#define briefcase_delivery_assigned                   get_briefcase_flag(ACCEPT_DELIVERY_ASSIGNED)
#define briefcase_delivery_happy                      get_briefcase_flag(ACCEPT_DELIVERY_HAPPY)
#define set_briefcase_delivery_happy                  set_briefcase_flag(ACCEPT_DELIVERY_HAPPY)
#define briefcase_delivery_death                      get_briefcase_flag(ACCEPT_DELIVERY_DEATH)
#define set_briefcase_delivery_death                  set_briefcase_flag(ACCEPT_DELIVERY_DEATH)
#define remove_happy_briefcase                        remove_pid_qty(dude_obj, PID_MOORE_GOOD_BRIEFCASE, 1)    \
                                                      set_briefcase_delivery_happy
#define remove_death_briefcase                        remove_pid_qty(dude_obj, PID_MOORE_BAD_BRIEFCASE, 1)     \
                                                      set_briefcase_delivery_death
#define dude_has_happy_briefcase                      (obj_is_carrying_obj_pid(dude_obj, PID_MOORE_GOOD_BRIEFCASE) > 0)
#define dude_has_death_briefcase                      (obj_is_carrying_obj_pid(dude_obj, PID_MOORE_BAD_BRIEFCASE) > 0)
// briefcase end

// redding related start
//#define REDDING_PROBLEM_NONE                (0)
//#define REDDING_PROBLEM_KNOW_EXISTS         (1)
//#define REDDING_PROBLEM_KNOW_JET            (2)
//#define REDDING_PROBLEM_DELIVERED_ANTIDOTE  (3)
//#define REDDING_PROBLEM_DONE                (4)
#define get_redding_problem(x)                        (global_var(GVAR_VAULT_REDDING_PROBLEM) == x)
#define set_redding_problem(x)                        set_global_var(GVAR_VAULT_REDDING_PROBLEM, x)
#define set_redding_problem_know_jet                  if (global_var(GVAR_VAULT_REDDING_PROBLEM) < REDDING_PROBLEM_KNOW_JET) then set_redding_problem(REDDING_PROBLEM_KNOW_JET)
#define set_redding_problem_know_exists               if (get_redding_problem(REDDING_PROBLEM_NONE)) then set_redding_problem(REDDING_PROBLEM_KNOW_EXISTS)
#define check_redding_problem_known                   ((get_redding_problem(REDDING_PROBLEM_KNOW_EXISTS)) or (get_redding_problem(REDDING_PROBLEM_KNOW_JET)))
// redding related end

// vault city related start
//#define JET_WILL_GET                        (1)
//#define JET_DECLINED_JOB                    (2)
//#define JET_GIVEN_JET                       (3)
//#define JET_ANTIDOTE_FOUND                  (4)
//#define JET_BLACKMAIL_ON                    (5)
//#define JET_BLACKMAIL_OVER                  (6)
#define jet_quest                                     (global_var(GVAR_VAULT_JET_QUEST))
#define get_jet_quest(x)                              (jet_quest == x)
#define set_jet_quest(x)                              set_global_var(GVAR_VAULT_JET_QUEST)

// vault city related end

// boxing start
#define other_boxer_name                              nr_mstr(random(700, 719))
#define vs_boxer_name                                 nr_mstr(700 + (50 * fighting_main_boxer) + fight_level)

#define boxer_resting                                 (get_new_reno_flag(boxer_resting_bit, 3))
#define set_boxer_resting                             set_new_reno_flag_on(boxer_resting_bit, 3)
#define off_boxer_resting                             set_new_reno_flag_off(boxer_resting_bit, 3)

#define killed_opponent                               (get_new_reno_flag(killed_opponent_bit, 3))
#define set_killed_opponent                           set_new_reno_flag_on(killed_opponent_bit, 3)
#define off_killed_opponent                           set_new_reno_flag_off(killed_opponent_bit, 3)

#define boxer_killed                                  (get_new_reno_flag(boxer_killed_bit, 3))
#define set_boxer_killed                              set_new_reno_flag_on(boxer_killed_bit, 3)

#define mckneely_dead                                 (get_new_reno_flag(mckneely_dead_bit, 3))
#define set_mckneely_dead                             set_new_reno_flag_on(mckneely_dead_bit, 3)

#define holyfeld_dead                                 (get_new_reno_flag(holyfeld_dead_bit, 3))
#define set_holyfeld_dead                             set_new_reno_flag_on(holyfeld_dead_bit, 3)

#define masticator_dead                               (get_new_reno_flag(masticator_dead_bit, 3))
#define set_masticator_dead                           set_new_reno_flag_on(masticator_dead_bit, 3)
#define masticator_bit_ear                            (get_new_reno_flag(masticator_bit_ear_bit, 3))
#define set_masticator_bit_ear                        if (masticator_bit_ear == false) then begin           \
                                                         set_critter_stat(dude_obj, STAT_ch, -1);           \
                                                         display_msg(nr_mstr(1600));                        \
                                                         give_pid_qty(dude_obj, PID_PLAYERS_EAR, 1)         \
                                                      end                                                   \
                                                      set_new_reno_flag_on(masticator_bit_ear_bit, 3)
#define player_bites_masticator_ear                   (get_new_reno_flag(player_bites_masticator_ear_bit, 4))
#define set_player_bites_masticator_ear               if (player_bites_masticator_ear == false) then begin  \
                                                         display_msg(nr_mstr(1700));                        \
                                                         give_pid_qty(dude_obj, PID_MASTICATORS_EAR, 1)     \
                                                      end                                                   \
                                                      set_new_reno_flag_on(player_bites_masticator_ear_bit, 4)

#define stuart_deal                                   (global_var(GVAR_NEW_RENO_STUART_DEAL))
#define set_stuart_deal(x)                            set_global_var(GVAR_NEW_RENO_STUART_DEAL, x)

#define fight_level_done                              (3)
#define fight_level                                   (global_var(GVAR_NEW_RENO_FIGHT_LEVEL))
#define inc_fight_level                               if (global_var(GVAR_NEW_RENO_FIGHT_LEVEL) <= fight_level_done) then begin  \
                                                         display_msg(nr_mstr(1400 + fight_level + ( ((fight_level >= 3) and (not(fighting_main_boxer))) * 2 )));                               \
                                                         inc_global_var(GVAR_NEW_RENO_FIGHT_LEVEL);                              \
                                                         if (fight_level == 1) then begin                                        \
                                                            give_xp(EXP_NEW_RENO_BOXER_LEVEL_1);                                 \
                                                            inc_reno_rep(REP_NEW_RENO_BOXER_LEVEL_1);                            \
                                                         end else if (fight_level == 2) then begin                               \
                                                            give_xp(EXP_NEW_RENO_BOXER_LEVEL_2);                                 \
                                                            inc_reno_rep(REP_NEW_RENO_BOXER_LEVEL_2);                            \
                                                         end else if (fight_level == 3) then begin                               \
                                                            give_xp(EXP_NEW_RENO_BOXER_LEVEL_3);                                 \
                                                            inc_reno_rep(REP_NEW_RENO_BOXER_LEVEL_3);                            \
                                                         end else if (fight_level == 4) then begin                               \
                                                            give_xp(EXP_NEW_RENO_BOXER_LEVEL_4);                                 \
                                                            inc_reno_rep(REP_NEW_RENO_BOXER_LEVEL_4);                            \
                                                            critter_mod_skill(dude_obj, SKILL_UNARMED_COMBAT, 5);                \
                                                            global_temp := get_pc_extra_stat(STAT_dmg_resist) + 5;               \
                                                            set_pc_extra_stat(STAT_dmg_resist, global_temp);                     \
                                                            set_global_var(GVAR_NEW_RENO_HAS_REP_PRIZEFIGHTER, 1);               \
                                                            display_msg(nr_mstr(1404));                                          \
                                                         end                                                                     \
                                                      end                                                                        \
                                                      ndebug("inc_fight_level == " + fight_level)

#define split_stuart_deal(x)                          item_caps_adjust(dude_obj, ((100 - stuart_deal) * x)/100);  \
                                                      item_caps_adjust(self_obj, (stuart_deal * x)/100);

#define collect_fight_money                           if (stuart_deal != 0) then begin                      \
                                                         if (fight_level == 2) then begin                   \
                                                            split_stuart_deal(800)                          \
                                                         end else if (fight_level == 3) then begin          \
                                                            split_stuart_deal(2000)                         \
                                                         end else begin                                     \
                                                            split_stuart_deal(100)                          \
                                                         end                                                \
                                                      end

#define fighting_main_boxer                           (get_new_reno_flag(fighting_main_boxer_bit, 3))
#define set_fighting_main_boxer                       set_new_reno_flag_on(fighting_main_boxer_bit, 3)
#define off_fighting_main_boxer                       set_new_reno_flag_off(fighting_main_boxer_bit, 3)

#define fight_is_on                                   get_new_reno_flag(fight_is_on_bit, 3)
#define set_fight_is_on                               set_new_reno_flag_on(fight_is_on_bit, 3)
#define off_fight_is_on                               set_new_reno_flag_off(fight_is_on_bit, 3)
#define create_boxer                                                                                        \
         set_fighting_main_boxer;                                                                           \
         if (fight_level == 1) then begin                                                                   \
            if (mckneely_dead == false) then begin                                                          \
               prize_fighter_obj := PID_MCKNEELY;                                                           \
               if (mckneely_obj != 0) then begin                                                            \
                  check_set_obj_visiblility(mckneely_obj, true);                                            \
               end                                                                                          \
            end else begin                                                                                  \
               prize_fighter_obj := PID_BOXER_3;                                                            \
               off_fighting_main_boxer;                                                                     \
            end                                                                                             \
         end else if (fight_level == 2) then begin                                                          \
            if (holyfeld_dead == false) then begin                                                          \
               prize_fighter_obj := PID_HOLYFELD;                                                           \
               if (hollyfeld_obj != 0) then begin                                                           \
                  check_set_obj_visiblility(hollyfeld_obj, true);                                           \
               end                                                                                          \
            end else begin                                                                                  \
               prize_fighter_obj := PID_BOXER_1;                                                            \
               off_fighting_main_boxer;                                                                     \
            end                                                                                             \
         end else if (fight_level == 3) then begin                                                          \
            if (masticator_dead == false) then begin                                                        \
               prize_fighter_obj := PID_MASTICATOR;                                                         \
            end else begin                                                                                  \
               prize_fighter_obj := PID_BOXER_1;                                                            \
               off_fighting_main_boxer;                                                                     \
            end                                                                                             \
         end else begin                                                                                     \
            prize_fighter_obj := PID_BOXER_2;                                                               \
         end                                                                                                \
         prize_fighter_obj := create_object_sid(prize_fighter_obj, 0, 0, SCRIPT_NCPRZFTR);                  \
         give_pid_qty(prize_fighter_obj, PID_SPECIAL_BOXER_WEAPON, 1)                                       \
         critter_add_trait(prize_fighter_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM, TEAM_NEW_RENO_FIGHTING_BOXER);   \
         critter_add_trait(prize_fighter_obj, TRAIT_OBJECT, OBJECT_AI_PACKET, AI_BOXER);                    \
         ndebug("creating boxer")

#define fight_status_fighting                         (0)
#define fight_status_ko                               (1)
#define fight_status_tko                              (2)
#define fight_status_disqualified                     (3)
#define fight_status_decision                         (4)

#define fight_status_raw                              (global_var(GVAR_NEW_RENO_FIGHT_STATUS))
#define fight_status                                  (fight_status_raw + (-2 * fight_status_raw * (fight_status_raw < 0)))
#define check_fight_status(x)                         (fight_status_raw == x)
#define set_fight_status(x)                           if (x != fight_status_fighting) then begin                                  \
                                                         if (check_fight_status(fight_status_fighting)) then begin                \
                                                            set_global_var(GVAR_NEW_RENO_FIGHT_STATUS, x);                        \
                                                            nr_add_timer_event(announcer_obj, 5, 200);                            \
                                                         end                                                                      \
                                                      end else set_global_var(GVAR_NEW_RENO_FIGHT_STATUS, fight_status_fighting); \
                                                      ndebug("set_fight_status("+x+") == "+fight_status_raw)
#define dude_won_fight                                (fight_status_raw > 0)
#define boxer_won_fight                               (fight_status_raw < 0)

#define dude_punches                                  (local_var(LVAR_Dude_Punches))
#define inc_dude_punches                              inc_local_var(LVAR_Dude_Punches);              \
                                                      ndebug("total punches dude thrown == " + dude_punches)
#define clear_dude_punches                            set_local_var(LVAR_Dude_Punches, 0)

#define boxer_punches                                 (local_var(LVAR_Self_Punches))
#define inc_boxer_punches                             inc_local_var(LVAR_Self_Punches);              \
                                                      ndebug("total punches boxer thrown == " + boxer_punches)
#define clear_boxer_punches                           set_local_var(LVAR_Self_Punches, 0)

#define boxer_score                                   (global_var(GVAR_NEW_RENO_BOXER_SCORE))
#define inc_boxer_score(x)                            inc_global_var_amt(GVAR_NEW_RENO_BOXER_SCORE, x)
#define clear_boxer_score                             set_global_var(GVAR_NEW_RENO_BOXER_SCORE, 0)

#define dude_score                                    (global_var(GVAR_NEW_RENO_DUDE_SCORE))
#define inc_dude_score(x)                             inc_global_var_amt(GVAR_NEW_RENO_DUDE_SCORE, x)
#define clear_dude_score                              set_global_var(GVAR_NEW_RENO_DUDE_SCORE, 0)

#define currently_fighting                            (global_var(GVAR_NEW_RENO_ROUND_TIME) != 0)
#define seconds_til_round_over                        ((global_var(GVAR_NEW_RENO_ROUND_TIME) - game_time)/10)
#define round_time_over                               ((seconds_til_round_over <= 0) and (currently_fighting))
#define set_new_round_time                            set_global_var(GVAR_NEW_RENO_ROUND_TIME, game_time + ONE_GAME_MINUTE)

#define move_boxers_to_corners                        ndebug("move_boxers_to_corners: start");                 \
                                                      move_to(dude_obj, 24479, self_elevation);                \
                                                      critter_uninjure(dude_obj, DAM_KNOCKED_DOWN);            \
                                                      if ((prize_fighter_obj != 0) and (killed_opponent == false)) then begin   \
                                                         move_to(prize_fighter_obj, 26471, self_elevation);    \
                                                         animate_stand_obj(prize_fighter_obj);                 \
                                                         critter_uninjure(prize_fighter_obj, DAM_KNOCKED_DOWN);\
                                                         Face_Critter(prize_fighter_obj, dude_obj);            \
                                                         Face_Critter(dude_obj, prize_fighter_obj);            \
                                                      end                                                      \
                                                      animate_stand_obj(dude_obj);                             \
                                                      ndebug("move_boxers_to_corners: end");
#define start_boxing_match                            ndebug("start boxing match: start");                     \
                                                      gfade_out(ONE_GAME_SECOND);                              \
                                                         set_fight_is_on;                                      \
                                                         set_ui_should_be_disabled;                            \
                                                         reg_anim_clear(dude_obj);                             \
                                                         move_obj_inven_to_obj(dude_obj, new_reno_temp_box);   \
                                                         call doVaultBoxerAppearance;                          \
                                                         clear_dude_score;                                     \
                                                         clear_boxer_score;                                    \
                                                         off_killed_opponent;                                  \
                                                         set_global_var(GVAR_NEW_RENO_ROUND_TIME, 0);          \
                                                         set_fight_status(fight_status_fighting);              \
                                                         if (game_time_hour < 2100) then begin                 \
                                                            game_time_advance_hour(2100);                      \
                                                         end                                                   \
                                                         set_global_var(GVAR_NEW_RENO_ROUND_NUMBER, 1);        \
                                                         if (fighting_boxer_1_obj != 0) then begin             \
                                                            check_set_obj_visiblility(fighting_boxer_1_obj, true);    \
                                                         end                                                   \
                                                         if (fighting_boxer_2_obj != 0) then begin             \
                                                            check_set_obj_visiblility(fighting_boxer_2_obj, true);    \
                                                         end                                                   \
                                                         if (obj_carrying_pid_obj(new_reno_temp_box, PID_PLATED_BOXING_GLOVES)) then begin    \
                                                            give_pid_qty(dude_obj, PID_SPECIAL_PLATED_BOXING_GLOVES, 1)                      \
                                                            wield_obj_critter(dude_obj, restock_obj);                                \
                                                         end else if (obj_carrying_pid_obj(new_reno_temp_box, PID_BOXING_GLOVES)) then begin  \
                                                            give_pid_qty(dude_obj, PID_SPECIAL_BOXING_GLOVES, 1)                             \
                                                            wield_obj_critter(dude_obj, restock_obj);          \
                                                         end                                                   \
                                                         move_to(dude_obj, tile_num(announcer_obj), self_elevation); \
                                                         create_boxer;                                         \
                                                         move_boxers_to_corners                                \
                                                         check_set_obj_visiblility(announcer_obj, false);      \
                                                         check_set_obj_visiblility(ring_girl_obj, false);      \
                                                         nr_add_timer_event(announcer_obj, 5, 100);            \
                                                      gfade_in(ONE_GAME_SECOND);                               \
                                                      ndebug("tile_set_center(tile_num(announcer_obj)): " + tile_set_center(tile_num(announcer_obj))); \
                                                      ndebug("start boxing match: end")
#define heal_boxer(x)                                 critter_heal(x, get_critter_stat(x, STAT_en))

#define start_boxing_round                            ndebug("start boxing round: start");                     \
                                                      gfade_out(ONE_GAME_SECOND);                              \
                                                         game_time_advance(ONE_GAME_MINUTE);                   \
                                                         check_set_obj_visiblility(announcer_obj, true);       \
                                                         check_set_obj_visiblility(ring_girl_obj, true);       \
                                                         float_msg(dude_obj, message_str(SCRIPT_NCRNGGRL,100) + global_var(GVAR_NEW_RENO_ROUND_NUMBER) + message_str(SCRIPT_NCRNGGRL,101), FLOAT_MSG_WARNING); \
                                                         move_boxers_to_corners                                \
                                                         set_new_round_time;                                   \
                                                      gfade_in(ONE_GAME_SECOND);                               \
                                                      off_ui_should_be_disabled;                               \
                                                      play_sfx("boxbell1");                                    \
                                                      attack_setup(prize_fighter_obj, dude_obj);               \
                                                      ndebug("start boxing round: end")
#define end_boxing_round                              play_sfx("boxbell2");                                                   \
                                                         terminate_combat;                                                    \
                                                         gfade_out(ONE_GAME_SECOND);                                          \
                                                         check_set_obj_visiblility(announcer_obj, true);                      \
                                                         check_set_obj_visiblility(ring_girl_obj, true);                      \
                                                         ndebug("end boxing round start");                                    \
                                                         set_ui_should_be_disabled;                                           \
                                                         ndebug("combat terminated");                                         \
                                                         set_global_var(GVAR_NEW_RENO_ROUND_TIME, 0);                         \
                                                         inc_global_var(GVAR_NEW_RENO_ROUND_NUMBER);                          \
                                                         animate_stand_obj(dude_obj);                                         \
                                                         if ((prize_fighter_obj != 0) and (killed_opponent == false)) then begin   \
                                                            animate_stand_obj(prize_fighter_obj);                             \
                                                         end                                                                  \
                                                         if (check_fight_status(fight_status_fighting)) then begin            \
                                                            ndebug("check_fight_status(fight_status_fighting)");              \
                                                            move_boxers_to_corners                                            \
                                                            inc_dude_score(9);                                                \
                                                            inc_boxer_score(9);                                               \
                                                            if ((dude_punches > boxer_punches) or ((dude_punches == boxer_punches) and (random(0,1)))) then begin  \
                                                               inc_dude_score(1);                                             \
                                                            end else begin                                                    \
                                                               inc_boxer_score(1);                                            \
                                                            end                                                               \
                                                            if (global_var(GVAR_NEW_RENO_ROUND_NUMBER) <= 12) then begin      \
                                                               heal_boxer(dude_obj);                                          \
                                                               heal_boxer(prize_fighter_obj);                                 \
                                                               clear_dude_punches;                                            \
                                                               clear_boxer_punches;                                           \
                                                               check_set_obj_visiblility(ring_girl_obj, false);               \
                                                               nr_add_timer_event(announcer_obj, 5, 110);                     \
                                                            end else begin                                                    \
                                                               if (boxer_score > dude_score) then begin                       \
                                                                  lose_boxing_match(fight_status_decision);                   \
                                                               end else begin                                                 \
                                                                  win_boxing_match(fight_status_decision);                    \
                                                               end                                                            \
                                                            end                                                               \
                                                         end                                                                  \
                                                         set_ui_should_be_disabled;                                           \
                                                      gfade_in(ONE_GAME_SECOND);                                              \
                                                      ndebug("end boxing round end")

#define call_fight_over                               ndebug("call fight over: start");                              \
                                                      gfade_out(ONE_GAME_SECOND);                                    \
                                                         set_global_var(GVAR_NEW_RENO_ROUND_TIME, 0);                \
                                                         set_ui_should_be_disabled;                                  \
                                                         move_to(dude_obj, 25076, self_elevation);                   \
                                                         anim(dude_obj, ANIMATE_ROTATION, 3);                        \
                                                         if (prize_fighter_obj != 0) then begin                      \
                                                            if (killed_opponent) then begin                          \
                                                               check_set_obj_visiblility(prize_fighter_obj, true);   \
                                                               prize_fighter_obj := 0;                               \
                                                            end else begin                                           \
                                                               animate_stand_obj(prize_fighter_obj);                 \
                                                               critter_uninjure(prize_fighter_obj, DAM_KNOCKED_DOWN);\
                                                               move_to(prize_fighter_obj, 25674, self_elevation);    \
                                                               anim(prize_fighter_obj, ANIMATE_ROTATION, 3);         \
                                                            end                                                      \
                                                         end                                                         \
                                                         check_set_obj_visiblility(ring_girl_obj, true);             \
                                                         check_set_obj_visiblility(announcer_obj, false);            \
                                                         set_ui_should_be_disabled;                                  \
                                                      gfade_in(ONE_GAME_SECOND);                                     \
                                                      ndebug("call fight over: end")

#define lose_boxing_match(x)                          set_fight_status(-x);            \
                                                      call_fight_over;                 \
                                                      ndebug("lose boxing match: "+ self_name)
#define win_boxing_match(x)                           set_fight_status(x);             \
                                                      call_fight_over;                 \
                                                      ndebug("win boxing match: " + self_name)
#define cleanup_boxing_match                          ndebug("cleanup boxing match: start");                                                                                                                                     \
                                                      gfade_out(ONE_GAME_SECOND);                                                                                                                                                \
                                                         set_ui_should_be_disabled;                                                                                                                                              \
                                                         off_fight_is_on;                                                                                                                                                        \
                                                         if (prize_fighter_obj != 0) then begin                                                                                                                                  \
                                                            destroy_object(prize_fighter_obj);                                                                                                                                   \
                                                         end                                                                                                                                                                     \
                                                         check_set_obj_visiblility(announcer_obj, true);                                                                                                                         \
                                                         remove_pid_qty(dude_obj, PID_SPECIAL_PLATED_BOXING_GLOVES, 1)                                                                                                           \
                                                         remove_pid_qty(dude_obj, PID_SPECIAL_BOXING_GLOVES, 1)                                                                                                                  \
                                                         move_obj_inven_to_obj(new_reno_temp_box, dude_obj);                                                                                                                     \
                                                         critter_attempt_placement(dude_obj, tile_num_in_direction(tile_num(stuart_little_obj), has_trait(TRAIT_OBJECT,stuart_little_obj,OBJECT_CUR_ROT), 1), self_elevation);   \
                                                         Face_Critter(stuart_little_obj, dude_obj);                                                                                                                              \
                                                         Face_Critter(dude_obj, stuart_little_obj);                                                                                                                              \
                                                         check_set_obj_visiblility(ring_girl_obj, true);            \
                                                         check_set_obj_visiblility(announcer_obj, true);            \
                                                         nr_add_timer_event(stuart_little_obj, 2, fight_over_param);                                                                                                             \
                                                         game_time_advance(ONE_GAME_MINUTE);                                                                                                                                     \
                                                      ndebug("cleanup boxing match: end")

#define hidden_for_fight                              lvar_bit(LVAR_Flags, hidden_for_fight_bit)
#define set_hidden_for_fight                          set_lvar_bit_on(LVAR_Flags, hidden_for_fight_bit)
#define off_hidden_for_fight                          set_lvar_bit_off(LVAR_Flags, hidden_for_fight_bit)
#define check_hide_durring_boxing_fight               if (fight_is_on) then begin                                             \
                                                         if (obj_is_visible_flag(self_obj)) then begin                        \
                                                            if (tile_boxing_gym_building(self_tile) == false) then begin      \
                                                               check_set_obj_visiblility(self_obj, true);                     \
                                                               set_hidden_for_fight;                                          \
                                                            end                                                               \
                                                         end                                                                  \
                                                      end else if (hidden_for_fight) then begin                               \
                                                         check_set_obj_visiblility(self_obj, false);                          \
                                                         off_hidden_for_fight;                                                \
                                                      end
// boxing end

// general townsperson/patron start
#define check_visible_townsperson                     if (random(1, 10) <= 6 + (night)) then begin \
                                                         check_set_obj_visiblility(self_obj, false);      \
                                                      end else begin                               \
                                                         check_set_obj_visiblility(self_obj, true);       \
                                                      end
// general townsperson/patron end


// myron start
#define MYRON_KNOWN_BIT                               bit_1
#define MYRON_WHORES_BIT                              bit_2
#define MYRON_CONVINCED_BIT                           bit_3
#define MYRON_LEFT_BIT                                bit_4
#define MYRON_DEAD_BIT                                bit_5
#define MYRON_STASH_BIT                               bit_6
//#define MYRON_CONVINCED_BIT                           bit_7
#define MYRON_SUPERSTIM_BIT                           bit_8
#define MYRON_CALLED_GUARDS_BIT                       bit_9
#define MYRON_STASH_FOUND_BIT                         bit_10
#define MYRON_GAVE_ID_BIT                             bit_11
#define MYRON_GUARD_1_DEAD_BIT                        bit_12
#define MYRON_GUARD_2_DEAD_BIT                        bit_13
#define MYRON_KITTY_BIT                               bit_14
#define MYRON_PERMISSION_BIT                          bit_15

#define get_myron_flag(x)                             (gvar_bit(GVAR_NEW_RENO_MYRON, x))
#define set_myron_flag(x)                             set_gvar_bit_on(GVAR_NEW_RENO_MYRON, x)
#define off_myron_flag(x)                             set_gvar_bit_off(GVAR_NEW_RENO_MYRON, x)

#define both_myron_guards_dead                        ((get_myron_flag(MYRON_GUARD_1_DEAD_BIT)) and (get_myron_flag(MYRON_GUARD_2_DEAD_BIT)))
#define set_myron_guard_dead                          if (get_myron_flag(MYRON_GUARD_1_DEAD_BIT) == false) then set_myron_flag(MYRON_GUARD_1_DEAD_BIT); \
                                                      else set_myron_flag(MYRON_GUARD_2_DEAD_BIT)

#define know_myron                                    get_myron_flag(MYRON_KNOWN_BIT)
#define set_know_myron                                set_myron_flag(MYRON_KNOWN_BIT)

#define myron_kitty                                   get_myron_flag(MYRON_KITTY_BIT)
#define set_myron_kitty                               set_myron_flag(MYRON_KITTY_BIT)

#define myron_permission                              get_myron_flag(MYRON_PERMISSION_BIT)
#define set_myron_permission                          set_myron_flag(MYRON_PERMISSION_BIT)
#define off_myron_permission                          off_myron_flag(MYRON_PERMISSION_BIT)

#define know_myron_whores                             get_myron_flag(MYRON_WHORES_BIT)
#define set_know_myron_whores                         set_myron_flag(MYRON_WHORES_BIT)

#define stash_know                                    get_myron_flag(MYRON_STASH_BIT)
#define set_stash_know                                set_golgotha_known                 \
                                                      set_myron_flag(MYRON_STASH_BIT)

#define stash_found                                   get_myron_flag(MYRON_STASH_FOUND_BIT)
#define set_stash_found                               set_myron_flag(MYRON_STASH_FOUND_BIT)

#define myron_convinced                               get_myron_flag(MYRON_CONVINCED_BIT)
#define set_myron_convinced                           set_myron_flag(MYRON_CONVINCED_BIT)

#define myron_called_guards                           get_myron_flag(MYRON_CALLED_GUARDS_BIT)
#define set_myron_called_guards                       set_myron_flag(MYRON_CALLED_GUARDS_BIT)

#define myron_dead                                    get_myron_flag(MYRON_DEAD_BIT)
#define set_myron_dead                                set_myron_flag(MYRON_DEAD_BIT)

#define superstim                                     get_myron_flag(MYRON_SUPERSTIM_BIT)
#define set_superstim                                 set_myron_flag(MYRON_SUPERSTIM_BIT)

#define myron_left_stables                            get_myron_flag(MYRON_LEFT_BIT)
#define set_myron_left_stables                        set_myron_flag(MYRON_LEFT_BIT)

// this actually is set in marjoree reed
#define gave_ident                                    get_myron_flag(MYRON_GAVE_ID_BIT)
#define set_gave_ident                                set_myron_flag(MYRON_GAVE_ID_BIT)

#define jet_source_none                               (0)
#define jet_source_hinted_at                          (1)
#define jet_source_discovered                         (2)
#define jet_source_cure_known                         (3)
#define jet_source_cure_made                          (4)
#define jet_source                                    (global_var(GVAR_NEW_RENO_JET_SOURCE))
#define get_jet_source(x)                             (jet_source == x)
#define set_jet_source(x)                             set_global_var(GVAR_NEW_RENO_JET_SOURCE, x)
// myron end

#define know_mordino                                  (get_new_reno_flag(know_mordino_bit, 2))
#define set_know_mordino                              set_new_reno_flag_on(know_mordino_bit, 2)

#define know_salvatore                                (get_new_reno_flag(know_salvatore_bit, 2))
#define set_know_salvatore                            set_new_reno_flag_on(know_salvatore_bit, 2)

// richard
#define richard_wright_known                          (get_new_reno_flag(richard_wright_known_bit, 1))
#define set_richard_wright_known                      set_new_reno_flag_on(richard_wright_known_bit, 1)
#define richard_wright_room                           (get_new_reno_flag(richard_wright_room_bit, 2))
#define set_richard_wright_room                       set_new_reno_flag_on(richard_wright_room_bit, 2)

#define examined_body                                 (get_new_reno_flag(examined_body_bit, 1))
#define set_examined_body                             set_new_reno_flag_on(examined_body_bit, 1)

#define robobrain_skynet                              (global_var(GVAR_BRAIN_BOT_BRAIN) == BRAIN_CYBERNETIC)
#define looking_for_geck                              (dude_found_geck == false)
#define max_names_per_list                            (5)
#define id_badge_pid                                  (PID_STABLES_ID_BADGE)
#define dude_has_id_badge                             (obj_is_carrying_obj_pid(dude_obj, id_badge_pid) > 0)
#define family_to_casino_nam(x)                       (nr_mstr(220 + x))
#define enclave_destroyed                             Fallout2_enclave_destroyed
#define looking_for_vault_13                          Fallout2_vault13_looking
#define tribe_kidnapped                               Fallout2_tribe_kidnapped
#define on_fix_tanker_quest                           Fallout2_fix_tanker

variable stored_msg;
variable stored_node;
variable top_msg;
variable var_num;

// THESE ARE MORE OR LESS LIBRARY FUNCTIONS TO SET THE NAME OF THE MADE MAN, ETC.
procedure ChooseFromList;
procedure CLICK_PREV  begin
   top_msg -= max_names_per_list;
   call ChooseFromList;
end

#define finalize_option(x)    set_global_var(var_num, ((global_var(var_num)/100)*100) + ((x)%100))

procedure CLICK_0  begin
   finalize_option(top_msg);
   call stored_node;
end
procedure CLICK_1  begin
   finalize_option(top_msg + 1);
   call stored_node;
end
procedure CLICK_2  begin
   finalize_option(top_msg + 2);
   call stored_node;
end
procedure CLICK_3  begin
   finalize_option(top_msg + 3);
   call stored_node;
end
procedure CLICK_4  begin
   finalize_option(top_msg + 4);
   call stored_node;
end
procedure CLICK_MORE  begin
   top_msg += max_names_per_list;
   call ChooseFromList;
end

#define print_option(the_num, print_canceled)                        \
   if (print_canceled == false) then begin                           \
      if (nr_mstr(top_msg + the_num) != "") then begin               \
         NOption(nr_mstr(top_msg + the_num), CLICK_##the_num, 001);  \
      end else begin                                                 \
         print_canceled := true;                                     \
      end                                                            \
   end

procedure ChooseFromList begin
variable do_cancel;
   Reply(stored_msg);
   if (nr_mstr(top_msg - 1) != "") then begin
      NOption(nr_mstr(150), CLICK_PREV, 001);
   end
   print_option(0, do_cancel)
   print_option(1, do_cancel)
   print_option(2, do_cancel)
   print_option(3, do_cancel)
   print_option(4, do_cancel)
   if (do_cancel == false) then begin
      if (nr_mstr(top_msg + max_names_per_list) != "") then begin
         NOption(nr_mstr(151), CLICK_MORE, 001);
      end
   end
end

// settugng name macros
#define setup_set_made_man_name(the_msg, the_node, the_family)          \
         begin                                                          \
            if (the_family == family_bishop) then begin                 \
               inc_reno_rep(REP_NEW_RENO_MADE_MAN_BISHOP);              \
            end else if (the_family == family_wright) then begin        \
               inc_reno_rep(REP_NEW_RENO_MADE_MAN_WRIGHT);              \
            end else if (the_family == family_salvatore) then begin     \
               inc_reno_rep(REP_NEW_RENO_MADE_MAN_SALVATORE);           \
            end else if (the_family == family_mordino) then begin       \
               inc_reno_rep(REP_NEW_RENO_MADE_MAN_MORDINO);             \
            end                                                         \
            set_global_var(family_warning_var(the_family), 0);          \
            set_dude_family(the_family)                                 \
            var_num := GVAR_NEW_RENO_MADE_MAN;                          \
            top_msg := made_man_msg_start + 1;                          \
            stored_msg := the_msg;                                      \
            stored_node := the_node;                                    \
            call ChooseFromList;                                        \
         end

/*#define setup_set_porn_star_name(the_msg, the_node)                     \
         begin                                                          \
            var_num := GVAR_NEW_RENO_PORN_STAR;                         \
            top_msg := porn_star_msg_start + (50*dude_is_female) + 1;   \
            stored_msg := the_msg;                                      \
            stored_node := the_node;                                    \
            call ChooseFromList;                                        \
         end*/

#define setup_set_porn_star_name(the_msg, the_node)                     \
         begin                                                          \
            var_num := GVAR_NEW_RENO_PORN_STAR;                         \
            set_global_var(var_num, 0);                                 \
            top_msg := porn_star_msg_start + (50*dude_is_female) + 1;   \
            stored_msg := the_msg;                                      \
            stored_node := the_node;                                    \
            call ChooseFromList;                                        \
         end

#define setup_set_prizefighter_name(the_msg, the_node)                  \
         begin                                                          \
            var_num := GVAR_NEW_RENO_PRIZEFIGHTER;                      \
            top_msg := prizefighter_msg_start + 1;                      \
            stored_msg := the_msg;                                      \
            stored_node := the_node;                                    \
            call ChooseFromList;                                        \
         end

// insert message macro
variable floater_patch_msg;
#define floater_rand_with_check(x, y, the_patch, the_adj)                                                                     \
         floater_patch_msg := random(x, y);                                                                                   \
         if (is_insert_message(floater_patch_msg)) then begin                                                                 \
            float_msg(self_obj, mstr(floater_patch_msg) + the_patch + mstr(floater_patch_msg + the_adj), FLOAT_COLOR_NORMAL); \
         end else                                                                                                             \
            floater(floater_patch_msg)

// helicopter shit start
#define witness_transaction                           get_new_reno_flag(witness_transaction_bit, 3)
#define set_witness_transaction                       if (witness_transaction == false) then begin    \
                                                         display_msg(nr_mstr(1550));                  \
                                                         give_xp(EXP_NEW_RENO_WITNESS_TRANSACTION);   \
                                                      end                                             \
                                                      set_new_reno_flag_on(witness_transaction_bit, 3)
variable hs_temp;

#define helicopter_script_combat_p_proc

#define helicopter_script_node998                                                \
         ndebug("helicopter_script_node998");                                    \
         set_hostile;                                                            \
         if (get_guard_assignment(guard_assignment_none) == false) then begin    \
            set_guard_assignment(guard_assignment_failed);                       \
         end                                                                     \
         if (secret_trade_disrupted == false) then begin                         \
            set_secret_trade_disrupted;                                          \
            if (get_guard_assignment(guard_assignment_none)) then begin          \
               flush_add_timer_event(self_obj, 0, 250);                          \
            end                                                                  \
         end                                                                     \
         if (combat_is_initialized == false) then begin                          \
            attack(dude_obj);                                                    \
         end

#define short_line_time                   (ONE_GAME_SECOND * 3)
#define medium_line_time                  (ONE_GAME_SECOND * 5)
#define long_line_time                    (ONE_GAME_SECOND * 7)
#define hs_timer_add(x,y,z)               if (x != 0) then begin                                \
                                             flush_add_timer_event(x, y, z);                    \
                                          end                                                   \
                                          flush_add_timer_event(self_obj, y - 5, float_param)

#define hs_move_obj_to_tile(the_obj, the_tile)                             \
         if (tile_num(the_obj) != the_tile) then begin                     \
            animate_move_obj_to_tile(the_obj, the_tile, ANIMATE_WALK);     \
            hs_temp := false;                                              \
         end

#define told_to_move_out                        get_new_reno_flag(told_to_move_out_bit, 2)
#define set_told_to_move_out                    set_new_reno_flag_on(told_to_move_out_bit, 2)
#define unset_told_to_move_out                  set_new_reno_flag_off(told_to_move_out_bit, 2)

#define hs_assignment_tile                      (22319)
#define safe_distance                           (3)
#define warn_distance                           (3)
#define abort_mission_distance                  (5)
#ifdef GENERIC_HS_GUARD
   #define helicopter_script_timed_event_p_proc                                                          \
            ndebug("generic guard watching player");                                                     \
            if (salvatore_guard_obj == self_obj) then begin                                              \
               if (get_guard_assignment(guard_assignment_assigned)) then begin                           \
                  if (tile_distance(hs_assignment_tile, dude_tile) <= safe_distance) then begin          \
                     ndebug("you're in a safe spot, resetting said_message");                            \
                     off_said_message;                                                                   \
                  end else if (tile_distance(hs_assignment_tile, dude_tile) <= abort_mission_distance) then begin \
                     ndebug("getting into some bad mojo now");                                           \
                     if ((said_message == false) and (salvatore_guard_obj != 0)) then begin              \
                        set_said_message;                                                                \
                        reg_anim_clear(dude_obj);                                                        \
                        Face_Critter(dude_obj, self_obj);                                                \
                        float_msg(self_obj, mstr(random(300, 302)), FLOAT_COLOR_NORMAL);                 \
                     end                                                                                 \
                  end else begin                                                                         \
                     set_guard_assignment(guard_assignment_failed);                                      \
                     if (salvatore_guard_1_obj != 0) then begin                                          \
                        flush_add_timer_event(salvatore_guard_1_obj, 0, 350);                            \
                     end else if (salvatore_guard_2_obj != 0) then begin                                 \
                        flush_add_timer_event(salvatore_guard_2_obj, 0, 350);                            \
                     end else begin                                                                      \
                        helicopter_script_node998                                                        \
                     end                                                                                 \
                  end                                                                                    \
                  nr_add_timer_event(self_obj, 1, float_param);                                          \
               end                                                                                       \
            end
#else
   #define helicopter_script_timed_event_p_proc                                        \
            ndebug("secret trade event: name == "+self_name+" / fixed == "+fixed_param);  \
            if (fixed_param == float_param) then begin                                 \
               float_msg(self_obj, " ", FLOAT_COLOR_NORMAL);                           \
            end else if (fixed_param == rotate_to_action_param) then begin             \
               if (salvatore_guard_1_obj != 0) then begin                              \
                  Face_Critter(self_obj, salvatore_guard_1_obj);                       \
               end else if (salvatore_guard_2_obj != 0) then begin                     \
                  Face_Critter(self_obj, salvatore_guard_2_obj);                       \
               end else if (power_armor_1_obj != 0) then begin                         \
                  Face_Critter(self_obj, power_armor_1_obj);                           \
               end else if (power_armor_2_obj != 0) then begin                         \
                  Face_Critter(self_obj, power_armor_2_obj);                           \
               end                                                                     \
            end else if (fixed_param >= 350) then begin                                \
               floater(fixed_param);                                                   \
               if (self_can_see_dude == false) then begin                              \
                  Face_Critter(self_obj, dude_obj);                                    \
               end                                                                     \
               if (fixed_param == 350) then begin                                      \
                  set_guard_assignment(guard_assignment_failed);                       \
                  hs_timer_add(salvatore_guard_2_obj, short_line_time, 351);           \
               end else if (fixed_param == 351) then begin                             \
                  hs_timer_add(power_armor_1_obj, short_line_time, 352);               \
               end else if (fixed_param == 352) then begin                             \
                  hs_timer_add(power_armor_2_obj, short_line_time, 353);               \
               end else if (fixed_param == 353) then begin                             \
                  helicopter_script_node998                                            \
               end                                                                     \
               helicopter_script_node998                                               \
            end else if ((secret_trade_disrupted == false) and (get_guard_assignment(guard_assignment_failed) == false)) then begin \
               hs_temp := true;                                                        \
               if (fixed_param == 200) then begin                                      \
                  hs_timer_add(salvatore_guard_2_obj, short_line_time, 201);           \
               end else if (fixed_param == 201) then begin                             \
                  hs_timer_add(power_armor_1_obj, short_line_time, 202);               \
               end else if (fixed_param == 202) then begin                             \
                  hs_move_obj_to_tile(salvatore_guard_1_obj, 20324)                    \
                  hs_move_obj_to_tile(salvatore_guard_2_obj, 20120)                    \
                  hs_move_obj_to_tile(power_armor_1_obj, 19521)                        \
                  hs_move_obj_to_tile(power_armor_2_obj, 19926)                        \
                  if (hs_temp) then begin                                              \
                     hs_timer_add(salvatore_guard_2_obj, medium_line_time, 203);       \
                  end                                                                  \
               end else if (fixed_param == 203) then begin                             \
                  hs_timer_add(power_armor_1_obj, medium_line_time, 204);              \
               end else if (fixed_param == 204) then begin                             \
                  hs_timer_add(power_armor_2_obj, medium_line_time, 205);              \
               end else if (fixed_param == 205) then begin                             \
                  hs_timer_add(salvatore_guard_2_obj, long_line_time, 206);            \
               end else if (fixed_param == 206) then begin                             \
                  hs_timer_add(power_armor_1_obj, medium_line_time, 207);              \
               end else if (fixed_param == 207) then begin                             \
                  hs_timer_add(power_armor_2_obj, medium_line_time, 208);              \
               end else if (fixed_param == 208) then begin                             \
                  hs_timer_add(salvatore_guard_2_obj, long_line_time, 209);            \
               end else if (fixed_param == 209) then begin                             \
                  hs_timer_add(power_armor_1_obj, medium_line_time, 210);              \
               end else if (fixed_param == 210) then begin                             \
                  hs_timer_add(power_armor_2_obj, short_line_time, 211);               \
                  nr_add_timer_event_tic(handy_obj, 5, 0);                             \
               end else if (fixed_param == 211) then begin                             \
                  if (handy_obj != 0) then begin                                       \
                     flush_add_timer_event(handy_obj, 0, float_param);                 \
                  end                                                                  \
                  hs_timer_add(salvatore_guard_2_obj, short_line_time, 212);           \
               end else if (fixed_param == 212) then begin                             \
                  hs_timer_add(salvatore_guard_2_obj, long_line_time, 213);            \
               end else if (fixed_param == 213) then begin                             \
                  set_told_to_move_out;                                                \
                  if (get_guard_assignment(guard_assignment_none) == false) then begin \
                     set_guard_assignment(guard_assignment_success);                   \
                  end else begin                                                       \
                     set_witness_transaction;                                          \
                  end                                                                  \
               end                                                                     \
               if (hs_temp) then begin                                                 \
                  floater(fixed_param);                                                \
               end else begin                                                          \
                  flush_add_timer_event(self_obj, ONE_GAME_SECOND, fixed_param);       \
               end                                                                     \
            end else begin                                                             \
               floater(fixed_param);                                                   \
               if (fixed_param == 250) then begin                                      \
                  hs_timer_add(salvatore_guard_1_obj, short_line_time, 251);           \
               end else if (fixed_param == 251) then begin                             \
                  hs_timer_add(salvatore_guard_2_obj, short_line_time, 252);           \
               end else if (fixed_param == 252) then begin                             \
                  hs_timer_add(power_armor_1_obj, short_line_time, 253);               \
               end else if (fixed_param == 253) then begin                             \
                  hs_timer_add(power_armor_2_obj, short_line_time, 254);               \
               end else if (fixed_param >= 350) then begin                             \
                  if (self_can_see_dude == false) then begin                           \
                     Face_Critter(self_obj, dude_obj);                                 \
                  end                                                                  \
                  if (fixed_param == 350) then begin                                   \
                     set_guard_assignment(guard_assignment_failed);                    \
                     hs_timer_add(salvatore_guard_2_obj, short_line_time, 351);        \
                  end else if (fixed_param == 351) then begin                          \
                     hs_timer_add(power_armor_1_obj, short_line_time, 352);            \
                  end else if (fixed_param == 352) then begin                          \
                     hs_timer_add(power_armor_2_obj, short_line_time, 353);            \
                  end else if (fixed_param == 353) then begin                          \
                     helicopter_script_node998                                         \
                  end                                                                  \
                  helicopter_script_node998                                            \
               end else if (fixed_param >= 300) then begin                             \
                  if (self_can_see_dude == false) then begin                           \
                     Face_Critter(self_obj, dude_obj);                                 \
                     flush_add_timer_event(self_obj, short_line_time, rotate_to_action_param);  \
                  end                                                                  \
               end                                                                     \
            end
#endif

// helicopter shit end

// warnings macros start
#define warning_result_none                           (0)
#define warning_result_warning_given                  (1)
#define warning_result_warning_wait                   (2)
#define warning_result_attack                         (3)

#define warning_attack                                bit_1
#define warning_family                                bit_2
#define warning_weapon                                bit_3
#define warning_sneak                                 bit_4
#define warning_robobrain                             bit_5
#define warning_marcus                                bit_6
#define warning_lenny                                 bit_7
#define warning_stairs                                bit_8
#define warning_armor                                 bit_9
#define warning_door                                  bit_10
#define warning_safe                                  bit_11
#define warning_myron_door                            bit_12
#define warning_tamper                                bit_13

#define family_warning_var(the_family)                (GVAR_SALVATORE_WARNINGS + the_family - 1)
#define warning_var                                   family_warning_var(self_family)
#define set_family_warning_on(the_warning,the_family) set_gvar_bit_on(family_warning_var(the_family), the_warning)
#define set_warning_on(which_warning)                 set_family_warning_on(which_warning,self_family)
#define warning_is_on(which_warning)                  (gvar_bit(warning_var, which_warning))
#define warning_is_off(which_warning)                 (warning_is_on(which_warning) == false)

#define warned_attack                                 warning_is_on(warning_attack)
#define warned_family                                 warning_is_on(warning_family)
#define warned_weapon                                 warning_is_on(warning_weapon)
#define warned_sneak                                  warning_is_on(warning_sneak)
#define warned_robobrain                              warning_is_on(warning_robobrain)
#define warned_marcus                                 warning_is_on(warning_marcus)
#define warned_lenny                                  warning_is_on(warning_lenny)
#define warned_stairs                                 warning_is_on(warning_stairs)
#define warned_armor                                  warning_is_on(warning_armor)
#define warned_door                                   warning_is_on(warning_door)
#define warned_safe                                   warning_is_on(warning_safe)
#define warned_myron_door                             warning_is_on(warning_myron_door)
#define warned_tamper                                 warning_is_on(warning_tamper)

#define warning_time                                  (60)
#define warning_message_time                          (15)

#define warning_timer_up                              (global_var(GVAR_NEW_RENO_WARNING_TIMER) <= game_time)

// new school warning macros
// have default as well as modified
#ifndef WARNING_IGNORE_ALL_CASE
   #define WARNING_IGNORE_ALL_CASE                    ((dude_wearing_power_armor == false) and (Fallout2_enclave_destroyed == false) and (dude_family != self_family))
#endif
#ifndef WARNING_IGNORE_CASE
   #define WARNING_IGNORE_CASE                        ((dude_has_porn_star_rep) or (dude_is_prizefighter))  // redefinable
#endif
#define WARNING_FAMILY_CONDITIONS                     dude_is_made_man                 // redefinable
#define WARNING_WEAPON_CONDITIONS                     dude_is_armed                    // redefinable
#define WARNING_SNEAK_CONDITIONS                      dude_is_sneaking                 // redefinable
#define WARNING_ROBOBRAIN_CONDITIONS                  robobrain_is_dude_companion      // redefinable
#define WARNING_MARCUS_CONDITIONS                     marcus_is_dude_companion         // redefinable
#define WARNING_LENNY_CONDITIONS                      lenny_is_dude_companion          // redefinable
#define WARNING_ATTACK_ACTION                         // redefinable
#define call_warning_loop                             nr_add_timer_event_rand(self_obj, 2, 4, warning_loop_param)
#define check_give_warning(cond, type, action)        if (warning_result == warning_result_none) then begin                            \
                                                         if (cond) then begin                                                          \
                                                            if (warning_is_on(type)) then begin                                        \
                                                               warning_result := warning_result_warning_wait;                          \
                                                               if (warning_timer_up) then begin                                        \
                                                                  warning_result := warning_result_attack;                             \
                                                                  WARNING_ATTACK_ACTION                                                \
                                                                  set_warning_on(warning_attack);                                      \
                                                               end else if ((global_var(GVAR_NEW_RENO_GUARD_MESSAGE_TIMER) < GAME_TIME_IN_SECONDS) or (is_click)) then begin \
                                                                  set_global_var(GVAR_NEW_RENO_GUARD_MESSAGE_TIMER, GAME_TIME_IN_SECONDS + warning_message_time);            \
                                                                  action                                                               \
                                                               end                                                                     \
                                                            end else begin                                                             \
                                                               set_global_var(GVAR_NEW_RENO_GUARD_MESSAGE_TIMER, GAME_TIME_IN_SECONDS + warning_message_time);  \
                                                               set_global_var(GVAR_NEW_RENO_WARNING_TIMER, GAME_TIME_IN_SECONDS + warning_time);                \
                                                               set_warning_on(type);                                                   \
                                                               action                                                                  \
                                                               warning_result := warning_result_warning_given;                         \
                                                            end                                                                        \
                                                         end                                                                           \
                                                      end

#ifdef WARNING_FAMILY_ACTION
   #define CHECK_FAMILY                               check_give_warning(WARNING_FAMILY_CONDITIONS, warning_family, WARNING_FAMILY_ACTION) else
#else
   #define CHECK_FAMILY
#endif

#ifdef WARNING_WEAPON_ACTION
   #define CHECK_WEAPON                               check_give_warning(WARNING_WEAPON_CONDITIONS, warning_weapon, WARNING_WEAPON_ACTION) else
#else
   #define CHECK_WEAPON
#endif

#ifdef WARNING_SNEAK_ACTION
   #define CHECK_SNEAK                                check_give_warning(WARNING_SNEAK_CONDITIONS, warning_sneak, WARNING_SNEAK_ACTION) else
#else
   #define CHECK_SNEAK
#endif

#ifdef WARNING_ROBOBRAIN_ACTION
   #define CHECK_ROBOBRAIN                            check_give_warning(WARNING_ROBOBRAIN_CONDITIONS, warning_robobrain, WARNING_ROBOBRAIN_ACTION) else
#else
   #define CHECK_ROBOBRAIN
#endif

#ifdef WARNING_MARCUS_ACTION
   #define CHECK_MARCUS                               check_give_warning(WARNING_MARCUS_CONDITIONS, warning_marcus, WARNING_MARCUS_ACTION) else
#else
   #define CHECK_MARCUS
#endif

#ifdef WARNING_LENNY_ACTION
   #define CHECK_LENNY                                check_give_warning(WARNING_LENNY_CONDITIONS, warning_lenny, WARNING_LENNY_ACTION) else
#else
   #define CHECK_LENNY
#endif

#ifndef check_should_weild_weapon
   #define check_should_weild_weapon                  if (anim_busy(self_obj) == false) then begin                         \
                                                         if (warning_timer_up) then begin                                  \
                                                            if (self_is_armed) then begin                                  \
                                                               if (warning_is_off(warning_attack)) then begin              \
                                                                  if (warning_result == warning_result_none) then begin    \
                                                                     inven_unwield;                                        \
                                                                  end                                                      \
                                                               end                                                         \
                                                            end                                                            \
                                                         end else begin                                                    \
                                                            wield_best_new_reno_weapon                                     \
                                                         end                                                               \
                                                      end
#endif

#define check_all_warnings                            warning_result := warning_result_none;                                  \
                                                      if ((combat_is_initialized == false) and (self_visible)) then begin     \
                                                         if (self_can_see_dude) then begin                                    \
                                                            if (WARNING_IGNORE_ALL_CASE) then begin                           \
                                                               if (obj_on_family_property(dude_obj, self_family)) then begin  \
                                                                  CHECK_FAMILY                                                \
                                                                  CHECK_WEAPON                                                \
                                                                  if (WARNING_IGNORE_CASE == false) then begin                \
                                                                     CHECK_SNEAK                                              \
                                                                     CHECK_ROBOBRAIN                                          \
                                                                     CHECK_MARCUS                                             \
                                                                     CHECK_LENNY                                              \
                                                                     begin                                                    \
                                                                     end                                                      \
                                                                  end                                                         \
                                                               end else begin                                                 \
                                                                  ndebug("obj_on_family_property(dude_obj, self_family)");    \
                                                               end                                                            \
                                                            end else begin                                                    \
                                                               ndebug("WARNING_IGNORE_ALL_CASE == false");                    \
                                                            end                                                               \
                                                         end                                                                  \
                                                         check_should_weild_weapon                                            \
                                                      end
/*
#define WARNING_ATTACK_ACTION
#define WARNING_FAMILY_ACTION
#define WARNING_WEAPON_ACTION
#define WARNING_SNEAK_ACTION
#define WARNING_ROBOBRAIN_ACTION
#define WARNING_MARCUS_ACTION
#define WARNING_LENNY_ACTION
*/
// warnings macros end

#endif // NEWRENO_H
