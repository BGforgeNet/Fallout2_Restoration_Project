/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef DEN_H
#define DEN_H

#define den_mstr(x)                                message_str(SCRIPT_DENBUS1,(x))
#define den_display_mstr(x)                        display_msg(den_mstr(x))

#define free_vic_pip_none                          (0)
#define free_vic_pip_assigned                      (1)
#define free_vic_pip_done                          (2)
#define set_free_vic_pip(x)                        if (global_var(GVAR_QUEST_VIC_DEVICE) < x) then set_global_var(GVAR_QUEST_VIC_DEVICE, x)

#define car_part_pip_none                          (0)
#define car_part_pip_assigned                      (1)
#define car_part_pip_done                          (2)
#define set_car_part_pip(x)                        if (global_var(GVAR_DEN_CAR_PART_PIP) < x) then set_global_var(GVAR_DEN_CAR_PART_PIP, x)

#define anna_locket_pip_none                       (0)
#define anna_locket_pip_assigned                   (1)
#define anna_locket_pip_done                       (2)
#define set_anna_locket_pip(x)                     if (global_var(GVAR_DEN_ANNA_LOCKET_PIP) < x) then set_global_var(GVAR_DEN_ANNA_LOCKET_PIP, x)
#define get_anna_locket_pip(x)                     (global_var(GVAR_DEN_ANNA_LOCKET_PIP) == x)

// generic all around functions
#ifndef tile_in_box
#define tile_in_box(x, ul, ur, lr, ll)             tile_in_tile_rect(ul, ur, ll, lr, x)
#endif
#ifndef mid_tile
#define mid_tile(x,y)                              global_temp := x;                                                   \
                                                   while (tile_distance(global_temp, y) > (tile_distance(x,y)/2)) do   \
                                                      global_temp := tile_num_in_direction(global_temp, rotation_to_tile(global_temp,y), 1)
#endif
#ifndef random_tile_in_box
#define random_tile_in_box(ul, ur, lr, ll)         mid_tile(ul,lr);                                                                                   \
                                                   global_temp := tile_num_in_direction(global_temp, random(0,5), random(0, (tile_distance(ul,lr))/2));   \
                                                   if (tile_in_box(global_temp, ul, ur, lr, ll) == false) then global_temp := 0
#endif

// timed event params
#define timed_event_float                          (0)
#define timed_event_wander                         (1)
#define timed_event_get_high                       (2)
#define timed_event_off_crazy_rant                 (3)
#define timed_event_post_sex                       (4)
#define timed_event_clubbed                        (5)
#define timed_event_door_tamper                    (6)
#define timed_event_door_lockpick                  (7)
#define timed_event_unlock_door                    (8)
#define timed_event_special                        (9)
#define timed_event_jerkin                         (10)
#define timed_event_car_tamper                     (11)
#define timed_event_thief                          (12)
#define timed_event_attack                         (13)
#define timed_event_post_change                    (14)

// store defines
#define store_def_tubby                            (1)
#define store_def_becky                            (2)
#define store_def_flick                            (3)
#define store_def_hole                             (4)
#define store_def_mom                              (5)

// business hearts
#define tubby_heart                                (17709)
#define becky_heart                                (17468)
#define flick_heart                                (25681)
// bus 2
#define hole_heart                                 (14508)
#define mom_heart                                  (24883)

// boxes
#define tile_in_slave_pen(x)                       tile_in_box(x, 8483, 8465, 14065, 14083)
#define tile_in_anna_room(x)                       tile_in_box(x, 27913, 27903, 29703, 29713)
//#define tile_in_tubbys(x)                          tile_in_box(x, 16713, 16703, 19303, 19313)
#define tile_in_tubbys(x)                          tile_in_box(x, 16513, 16302, 19502, 19513)
#define tile_in_beckys(x)                          tile_in_box(x, 16679, 16667, 19467, 19479)
#define tile_in_flicks(x)                          tile_in_box(x, 24087, 24077, 26277, 26287)
#define tile_in_hole(x)                            tile_in_box(x, 14315, 14305, 16305, 16315)
#define tile_in_moms(x)                            tile_in_box(x, 24491, 24477, 25877, 25891)

// maps 1
#define random_tile_in_anna_room                   random_tile_in_box(27913, 27903, 29703, 29713)
#define random_tile_in_tubbys                      random_tile_in_box(16713, 16703, 19303, 19313)
#define random_tile_in_beckys                      random_tile_in_box(16679, 16667, 19467, 19479)
#define random_tile_in_flicks                      random_tile_in_box(24087, 24077, 26277, 26287)
#define random_tile_in_street_1_box                random_tile_in_box(15700, 15682, 23482, 23500)

// map 2
#define random_tile_in_slave_pen                   random_tile_in_box(8483, 8465, 14065, 14083)
#define random_tile_in_hole                        random_tile_in_box(14315, 14305, 16305, 16315)
#define random_tile_in_moms                        random_tile_in_box(24491, 24477, 25877, 25891)
#define random_tile_in_street_2_box                random_tile_in_box(17104, 17094, 24094, 24104)

// tile
#define metzger_sex_tile                           (14867)
#define metzger_player_sex_tile                    (15469)
#define slave_place_tile_1                         (12271)
#define slave_place_tile_2                         (12077)
#define slave_place_tile_3                         (10075)
#define frankie_sex_tile                           (13118)
#define frankie_player_sex_tile                    (13116)
#define joey_sex_tile                              (17853)
#define joey_player_sex_tile                       (18454)
#define sheila_sex_tile                            (12908)
#define sheila_player_sex_tile                     (12707)
#define billy_sex_tile                             (15699)
#define billy_player_sex_tile                      (15900)

// flags & bits
#define set_den_flag_on(x,n)                       set_gvar_bit_on(GVAR_DEN_FLAG_##n, x)
#define set_den_flag_off(x,n)                      set_gvar_bit_off(GVAR_DEN_FLAG_##n, x)
#define get_den_flag(x,n)                          gvar_bit(GVAR_DEN_FLAG_##n, x)

// den_flags_1 start
#define metzger_dead_bit                           bit_1
#define frankie_dead_bit                           bit_2
#define tubby_dead_bit                             bit_3
#define flick_dead_bit                             bit_4
#define becky_dead_bit                             bit_5
#define vic_dead_bit                               bit_6
#define mom_dead_bit                               bit_7
#define slaver1_dead_bit                           bit_8
#define slaver2_dead_bit                           bit_9
#define slaver3_dead_bit                           bit_10
#define fred_dead_bit                              bit_11
#define derek_dead_bit                             bit_12
#define heather_dead_bit                           bit_13
#define joey_dead_bit                              bit_14
#define robby_dead_bit                             bit_15
#define metzger_known_bit                          bit_16
#define frankie_known_bit                          bit_17
#define becky_cost_bit                             bit_18
#define robby_left_bit                             bit_19
#define vic_talk_bit                               bit_20
#define heather_fix_bit                            bit_21
#define slaves_free_bit                            bit_22
#define gave_metzger_party_stuff_bit               bit_23
//#define robby_left_bit                             bit_24
//#define vic_talk_bit                               bit_25
//#define heather_fix_bit                            bit_26
#define killed_slave_on_run_bit                    bit_27
#define vic_free_bit                               bit_28
#define vic_trader_bit                             bit_29
#define crates_ID_bit                              bit_30
#define gang1_hostile_bit                          bit_31
#define gave_anna_locket_bit                       bit_32

#define metzger_dead                               get_den_flag(metzger_dead_bit, 1)
#define set_metzger_dead                           if (global_var(GVAR_DEN_METZGER_GANG_KILL_TIMER) == 0) then begin                     \
                                                      inc_den_rep(REP_TOWN_DEN_KILL_METZGER);                                            \
                                                      inc_general_rep(REP_BONUS_KILL_METZGER);                                           \
                                                      display_mstr(800);                                                                 \
                                                      give_xp(EXP_KILL_METZGER);                                                         \
                                                      set_global_var(GVAR_DEN_METZGER_GANG_KILL_TIMER, game_time + (2 * ONE_GAME_DAY));  \
                                                   end                                                                                   \
                                                   set_den_flag_on(metzger_dead_bit, 1)

#define frankie_dead                               get_den_flag(frankie_dead_bit, 1)
#define set_frankie_dead                           if (frankie_dead == false) then begin           \
                                                      create_north_out_of_business(16310, 0);      \
                                                   end                                             \
                                                   set_den_flag_on(frankie_dead_bit, 1)

#define tubby_dead                                 get_den_flag(tubby_dead_bit, 1)
#define set_tubby_dead                             if (tubby_dead == false) then begin          \
                                                      create_north_out_of_business(19504, 0);   \
                                                   end                                          \
                                                   set_den_flag_on(tubby_dead_bit, 1)

#define flick_dead                                 get_den_flag(flick_dead_bit, 1)
#define set_flick_dead                             set_den_flag_on(flick_dead_bit, 1)

#define becky_dead                                 get_den_flag(becky_dead_bit, 1)
#define set_becky_dead                             if (becky_dead == false) then begin          \
                                                      inc_den_rep(REP_TOWN_DEN_KILL_BECKY);     \
                                                      create_east_out_of_business(18480, 0);    \
                                                   end                                          \
                                                   set_den_flag_on(becky_dead_bit, 1)

#define vic_dead                                   get_den_flag(vic_dead_bit, 1)
#define set_vic_dead                               set_den_flag_on(vic_dead_bit, 1)

#define mom_dead                                   get_den_flag(mom_dead_bit, 1)
#define set_mom_dead                               if (mom_dead == false) then begin            \
                                                      inc_den_rep(REP_TOWN_DEN_KILL_MOM);       \
                                                      create_north_out_of_business(26686, 0);   \
                                                   end                                          \
                                                   set_den_flag_on(mom_dead_bit, 1)

#define slaver1_dead                               get_den_flag(slaver1_dead_bit, 1)
#define set_slaver1_dead                           set_den_flag_on(slaver1_dead_bit, 1)
#define off_slaver1_dead                           set_den_flag_off(slaver1_dead_bit, 1)

#define slaver2_dead                               get_den_flag(slaver2_dead_bit, 1)
#define set_slaver2_dead                           set_den_flag_on(slaver2_dead_bit, 1)
#define off_slaver2_dead                           set_den_flag_off(slaver2_dead_bit, 1)

#define slaver3_dead                               get_den_flag(slaver3_dead_bit, 1)
#define set_slaver3_dead                           set_den_flag_on(slaver3_dead_bit, 1)
#define off_slaver3_dead                           set_den_flag_off(slaver3_dead_bit, 1)

#define fred_dead                                  get_den_flag(fred_dead_bit, 1)
#define set_fred_dead                              set_den_flag_on(fred_dead_bit, 1)
#define off_fred_dead                              set_den_flag_off(fred_dead_bit, 1)

#define derek_dead                                 get_den_flag(derek_dead_bit, 1)
#define set_derek_dead                             set_den_flag_on(derek_dead_bit, 1)
#define off_derek_dead                             set_den_flag_off(derek_dead_bit, 1)

#define heather_dead                               get_den_flag(heather_dead_bit, 1)
#define set_heather_dead                           set_den_flag_on(heather_dead_bit, 1)
#define off_heather_dead                           set_den_flag_off(heather_dead_bit, 1)

#define joey_dead                                  get_den_flag(joey_dead_bit, 1)
#define set_joey_dead                              set_den_flag_on(joey_dead_bit, 1)
#define off_joey_dead                              set_den_flag_off(joey_dead_bit, 1)

#define robby_dead                                 get_den_flag(robby_dead_bit, 1)
#define set_robby_dead                             set_den_flag_on(robby_dead_bit, 1)
#define off_robby_dead                             set_den_flag_off(robby_dead_bit, 1)

#define metzger_known                              get_den_flag(metzger_known_bit, 1)
#define set_metzger_known                          set_den_flag_on(metzger_known_bit, 1)
#define off_metzger_known                          set_den_flag_off(metzger_known_bit, 1)

#define frankie_known                              get_den_flag(frankie_known_bit, 1)
#define set_frankie_known                          set_den_flag_on(frankie_known_bit, 1)
#define off_frankie_known                          set_den_flag_off(frankie_known_bit, 1)

#define becky_cost                                 get_den_flag(becky_cost_bit, 1)
#define set_becky_cost                             set_den_flag_on(becky_cost_bit, 1)
#define off_becky_cost                             set_den_flag_off(becky_cost_bit, 1)

#define robby_left                                 get_den_flag(robby_left_bit, 1)
#define set_robby_left                             set_den_flag_on(robby_left_bit, 1)
#define off_robby_left                             set_den_flag_off(robby_left_bit, 1)

#define vic_talk                                   get_den_flag(vic_talk_bit, 1)
#define set_vic_talk                               set_den_flag_on(vic_talk_bit, 1)
#define off_vic_talk                               set_den_flag_off(vic_talk_bit, 1)

#define heather_fix                                get_den_flag(heather_fix_bit, 1)
#define set_heather_fix                            set_den_flag_on(heather_fix_bit, 1)
#define off_heather_fix                            set_den_flag_off(heather_fix_bit, 1)

#define vic_trader                                 get_den_flag(vic_trader_bit, 1)
#define set_vic_trader                             if (vic_trader == false) then begin                   \
                                                      display_mstr(900);                                 \
                                                      give_xp(EXP_VIC_TRADER_LEARNED);                   \
                                                      inc_general_rep(REP_BONUS_VIC_TRADER_LEARNED);     \
                                                   end                                                   \
                                                   set_den_flag_on(vic_trader_bit, 1)
#define off_vic_trader                             set_den_flag_off(vic_trader_bit, 1)

#define robby_left                                 get_den_flag(robby_left_bit, 1)
#define set_robby_left                             set_den_flag_on(robby_left_bit, 1)
#define off_robby_left                             set_den_flag_off(robby_left_bit, 1)

#define vic_talk                                   get_den_flag(vic_talk_bit, 1)
#define set_vic_talk                               set_den_flag_on(vic_talk_bit, 1)
#define off_vic_talk                               set_den_flag_off(vic_talk_bit, 1)

#define heather_fix                                get_den_flag(heather_fix_bit, 1)
#define set_heather_fix                            set_den_flag_on(heather_fix_bit, 1)
#define off_heather_fix                            set_den_flag_off(heather_fix_bit, 1)

#define slaves_free                                get_den_flag(slaves_free_bit, 1)
#define set_slaves_free                            if (slaves_free == false) then begin               \
                                                      display_mstr(700);                              \
                                                      give_xp(EXP_FREE_SLAVES);                       \
                                                      inc_general_rep(REP_BONUS_DEN_FREE_SLAVES);     \
                                                   end                                                \
                                                   set_den_flag_on(slaves_free_bit, 1)
#define off_slaves_free                            set_den_flag_off(slaves_free_bit, 1)

#define vic_free                                   get_den_flag(vic_free_bit, 1)
#define set_vic_free                               set_free_vic_pip(free_vic_pip_done);   \
                                                   set_den_flag_on(vic_free_bit, 1)

#define crates_ID                                  get_den_flag(crates_ID_bit, 1)
#define set_crates_ID                              if (crates_ID == false) then begin     \
                                                      give_xp(EXP_CRATE_EXP);             \
                                                   end                                    \
                                                   set_den_flag_on(crates_ID_bit, 1)

#define gang1_hostile                              get_den_flag(gang1_hostile_bit, 1)
#define set_gang1_hostile                          set_den_flag_on(gang1_hostile_bit, 1)
#define off_gang1_hostile                          set_den_flag_off(gang1_hostile_bit, 1)

#define gave_metzger_party_stuff                   get_den_flag(gave_metzger_party_stuff_bit, 1)
#define set_gave_metzger_party_stuff               set_den_flag_on(gave_metzger_party_stuff_bit, 1)
#define off_gave_metzger_party_stuff               set_den_flag_off(gave_metzger_party_stuff_bit, 1)

#define killed_slave_on_run                        get_den_flag(killed_slave_on_run_bit, 1)
#define set_killed_slave_on_run                    set_den_flag_on(killed_slave_on_run_bit, 1)
#define off_killed_slave_on_run                    set_den_flag_off(killed_slave_on_run_bit, 1)

#define gave_anna_locket                           get_den_flag(gave_anna_locket_bit, 1)
#define set_gave_anna_locket                       set_den_flag_on(gave_anna_locket_bit, 1)
// den_flags_1 end

// den_flags_2 start
#define aidan_jet_bit                              bit_1
#define aidan_reward_bit                           bit_2
#define derek_talk_bit                             bit_3
#define aidan_tip_metzger_bit                      bit_4
#define aidan_tip_hole_bit                         bit_5
#define becky_sex_bit                              bit_6
#define becky_dishonest_bit                        bit_7
#define becky_karma_neg_bit                        bit_8
#define becky_work_bit                             bit_9
#define heather_talk_bit                           bit_10
#define robby_talk_bit                             bit_11
#define becky_paw_bit                              bit_13
#define becky_why_cheap_bit                        bit_14
#define fred_remembers_bit                         bit_15
#define fred_talk_bit                              bit_16
#define crazy_addict_bit                           bit_17
#define metzger_sex_bit                            bit_18
#define smitty_dead_bit                            bit_19
#define mom_attacked_bit                           bit_20
#define mom_killed_bit                             bit_21
#define on_slave_run_bit                           bit_22
#define radio_fixed_bit                            bit_23
#define abandon_slave_run_bit                      bit_24
#define hostile_slavers_bit                        bit_25
#define dude_spotted_on_slave_run_bit              bit_26
#define slave_tagged_bit                           bit_27
#define still_known_bit                            bit_28
#define still_broken_bit                           bit_29
#define attacked_slaver_on_run_bit                 bit_30
#define metzger_permission_bit                     bit_31
#define tyler_dead_bit                             bit_32

#define aidan_jet                                  get_den_flag(aidan_jet_bit, 2)
#define set_aidan_jet                              set_den_flag_on(aidan_jet_bit, 2)
#define off_aidan_jet                              set_den_flag_off(aidan_jet_bit, 2)

#define aidan_reward                               get_den_flag(aidan_reward_bit, 2)
#define set_aidan_reward                           set_den_flag_on(aidan_reward_bit, 2)
#define off_aidan_reward                           set_den_flag_off(aidan_reward_bit, 2)

#define aidan_tip_metzger                          get_den_flag(aidan_tip_metzger_bit, 2)
#define set_aidan_tip_metzger                      set_den_flag_on(aidan_tip_metzger_bit, 2)
#define off_aidan_tip_metzger                      set_den_flag_off(aidan_tip_metzger_bit, 2)

#define aidan_tip_hole                             get_den_flag(aidan_tip_hole_bit, 2)
#define set_aidan_tip_hole                         set_den_flag_on(aidan_tip_hole_bit, 2)
#define off_aidan_tip_hole                         set_den_flag_off(aidan_tip_hole_bit, 2)

#define becky_sex                                  get_den_flag(becky_sex_bit, 2)
#define set_becky_sex                              set_den_flag_on(becky_sex_bit, 2)
#define off_becky_sex                              set_den_flag_off(becky_sex_bit, 2)

#define becky_dishonest                            get_den_flag(becky_dishonest_bit, 2)
#define set_becky_dishonest                        set_den_flag_on(becky_dishonest_bit, 2)
#define off_becky_dishonest                        set_den_flag_off(becky_dishonest_bit, 2)

#define becky_karma_neg                            get_den_flag(becky_karma_neg_bit, 2)
#define set_becky_karma_neg                        set_den_flag_on(becky_karma_neg_bit, 2)
#define off_becky_karma_neg                        set_den_flag_off(becky_karma_neg_bit, 2)

#define becky_work                                 get_den_flag(becky_work_bit, 2)
#define set_becky_work                             set_den_flag_on(becky_work_bit, 2)
#define off_becky_work                             set_den_flag_off(becky_work_bit, 2)

#define heather_talk                               get_den_flag(heather_talk_bit, 2)
#define set_heather_talk                           set_den_flag_on(heather_talk_bit, 2)
#define off_heather_talk                           set_den_flag_off(heather_talk_bit, 2)

//#define becky_j4_ready                             get_den_flag(becky_j4_ready_bit, 2)
//#define set_becky_j4_ready                         set_den_flag_on(becky_j4_ready_bit, 2)
//#define off_becky_j4_ready                         set_den_flag_off(becky_j4_ready_bit, 2)

#define becky_paw                                  get_den_flag(becky_paw_bit, 2)
#define set_becky_paw                              set_den_flag_on(becky_paw_bit, 2)
#define off_becky_paw                              set_den_flag_off(becky_paw_bit, 2)

#define becky_why_cheap                            get_den_flag(becky_why_cheap_bit, 2)
#define set_becky_why_cheap                        set_den_flag_on(becky_why_cheap_bit, 2)
#define off_becky_why_cheap                        set_den_flag_off(becky_why_cheap_bit, 2)

#define fred_remembers                             get_den_flag(fred_remembers_bit, 2)
#define set_fred_remembers                         set_den_flag_on(fred_remembers_bit, 2)
#define off_fred_remembers                         set_den_flag_off(fred_remembers_bit, 2)

#define fred_talk                                  get_den_flag(fred_talk_bit, 2)
#define set_fred_talk                              set_den_flag_on(fred_talk_bit, 2)
#define off_fred_talk                              set_den_flag_off(fred_talk_bit, 2)

#define derek_talk                                 get_den_flag(derek_talk_bit, 2)
#define set_derek_talk                             set_den_flag_on(derek_talk_bit, 2)
#define off_derek_talk                             set_den_flag_off(derek_talk_bit, 2)

#define robby_talk                                 get_den_flag(robby_talk_bit, 2)
#define set_robby_talk                             set_den_flag_on(robby_talk_bit, 2)
#define off_robby_talk                             set_den_flag_off(robby_talk_bit, 2)

#define crazy_addict                               get_den_flag(crazy_addict_bit, 2)
#define set_crazy_addict                           set_den_flag_on(crazy_addict_bit, 2)
#define off_crazy_addict                           set_den_flag_off(crazy_addict_bit, 2)

#define metzger_sex                                get_den_flag(metzger_sex_bit, 2)
#define set_metzger_sex                            set_den_flag_on(metzger_sex_bit, 2)

#define smitty_dead                                get_den_flag(smitty_dead_bit, 2)
#define set_smitty_dead                            set_den_flag_on(smitty_dead_bit, 2)

#define mom_attacked                               get_den_flag(mom_attacked_bit, 2)
#define set_mom_attacked                           set_den_flag_on(mom_attacked_bit, 2)
#define off_mom_attacked                           set_den_flag_off(mom_attacked_bit, 2)

#define mom_killed                                 get_den_flag(mom_killed_bit, 2)
#define set_mom_killed                             set_den_flag_on(mom_killed_bit, 2)
#define off_mom_killed                             set_den_flag_off(mom_killed_bit, 2)

#define on_slave_run                               get_den_flag(on_slave_run_bit, 2)
#define set_on_slave_run                           set_den_flag_on(on_slave_run_bit, 2)
#define off_on_slave_run                           set_den_flag_off(on_slave_run_bit, 2)

#define radio_fixed                                get_den_flag(radio_fixed_bit, 2)
#define set_radio_fixed                            set_den_flag_on(radio_fixed_bit, 2)

#define abandon_slave_run                          get_den_flag(abandon_slave_run_bit, 2)
#define set_abandon_slave_run                      set_den_flag_on(abandon_slave_run_bit, 2)
#define off_abandon_slave_run                      set_den_flag_off(abandon_slave_run_bit, 2)

#define hostile_slavers                            get_den_flag(hostile_slavers_bit, 2)
#define set_hostile_slavers                        set_den_flag_on(hostile_slavers_bit, 2)
#define off_hostile_slavers                        set_den_flag_off(hostile_slavers_bit, 2)

#define dude_spotted_on_slave_run                  get_den_flag(dude_spotted_on_slave_run_bit, 2)
#define set_dude_spotted_on_slave_run              set_den_flag_on(dude_spotted_on_slave_run_bit, 2)
#define off_dude_spotted_on_slave_run              set_den_flag_off(dude_spotted_on_slave_run_bit, 2)

#define slave_tagged                               get_den_flag(slave_tagged_bit, 2)
#define set_slave_tagged                           set_den_flag_on(slave_tagged_bit, 2)
#define off_slave_tagged                           set_den_flag_off(slave_tagged_bit, 2)

#define still_known                                get_den_flag(still_known_bit, 2)
#define set_still_known                            set_den_flag_on(still_known_bit, 2)

#define still_broken                               get_den_flag(still_broken_bit, 2)
#define set_still_broken                           set_den_flag_on(still_broken_bit, 2)
#define off_still_broken                           set_den_flag_off(still_broken_bit, 2)

#define attacked_slaver_on_run                     get_den_flag(attacked_slaver_on_run_bit, 2)
#define set_attacked_slaver_on_run                 set_den_flag_on(attacked_slaver_on_run_bit, 2)
#define off_attacked_slaver_on_run                 set_den_flag_off(attacked_slaver_on_run_bit, 2)

#define metzger_permission                         get_den_flag(metzger_permission_bit, 2)
#define set_metzger_permission                     set_den_flag_on(metzger_permission_bit, 2)

#define tyler_dead                                 get_den_flag(tyler_dead_bit, 2)
#define set_tyler_dead                             set_den_flag_on(tyler_dead_bit, 2)
// den_flags_2 end

// den_flags_3 start
#define know_church_bit                            bit_1
#define anna_spoken_bit                            bit_2
//#define joey_dead_bit                              bit_3
#define gave_fred_winnings_bit                     bit_4
#define cleared_unclaimed_car_bit                  bit_5
#define gang_1_hostile_bit                         bit_6
#define gang_2_hostile_bit                         bit_7
#define becky_known_bit                            bit_8
#define lara_dead_bit                              bit_9
#define gang_1_dead_bit                            bit_10
#define gang_2_dead_bit                            bit_11
#define player_has_destroyed_still_bit             bit_12
//#define becky_known_bit                            bit_13
#define mom_fingered_joey_bit                      bit_14
#define thugs_hostile_bit                          bit_15
#define took_car_off_den_bus_1_bit                 bit_16
#define gang_2_member_2_killed_bit                 bit_17
#define gang_2_member_3_killed_bit                 bit_18
#define gang_2_member_4_killed_bit                 bit_19
#define church_cleared_speech_bit                  bit_20
#define gang_war_dude_stray_message_bit            bit_21
#define returned_to_church_bit                     bit_22
#define at_party_fight_bit                         bit_23

#define rebecca_dead                               becky_dead
#define set_rebecca_dead                           set_becky_dead

#define anna_spoken                                get_den_flag(anna_spoken_bit, 3)
#define set_anna_spoken                            set_den_flag_on(anna_spoken_bit, 3)

#define mom_fingered_joey                          get_den_flag(mom_fingered_joey_bit, 3)
#define set_mom_fingered_joey                      set_den_flag_on(mom_fingered_joey_bit, 3); ndebug("set_mom_fingered_joey")

//#define joey_dead                                  get_den_flag(joey_dead_bit, 3)
//#define set_joey_dead                              set_den_flag_on(joey_dead_bit, 3)

#define gave_fred_winnings                         get_den_flag(gave_fred_winnings_bit, 3)
#define set_gave_fred_winnings                     if (gave_fred_winnings) then begin           \
                                                      set_fred_money(2000);                     \
                                                   end                                          \
                                                   set_den_flag_on(gave_fred_winnings_bit, 3)

#define cleared_unclaimed_car                      get_den_flag(cleared_unclaimed_car_bit, 3)
#define set_cleared_unclaimed_car                  set_den_flag_on(cleared_unclaimed_car_bit, 3)

#define gang_1_hostile                             get_den_flag(gang_1_hostile_bit, 3)
#define set_gang_1_hostile                         set_den_flag_on(gang_1_hostile_bit, 3)

#define gang_2_hostile                             get_den_flag(gang_2_hostile_bit, 3)
#define set_gang_2_hostile                         set_den_flag_on(gang_2_hostile_bit, 3)

#define becky_known                                get_den_flag(becky_known_bit, 3)
#define set_becky_known                            set_den_flag_on(becky_known_bit, 3)

#define lara_dead                                  get_den_flag(lara_dead_bit, 3)
#define set_lara_dead                              set_den_flag_on(lara_dead_bit, 3)

#define gang_1_dead                                get_den_flag(gang_1_dead_bit, 3)
#define set_gang_1_dead                            if (gangwar(state_gangwar_in_fight)) then begin    \
                                                      set_gangwar(state_gangwar_2won);                \
                                                   end                                                \
                                                   set_den_flag_on(gang_1_dead_bit, 3)

#define gang_2_dead                                get_den_flag(gang_2_dead_bit, 3)
#define set_gang_2_dead                            if (gangwar(state_gangwar_in_fight)) then begin    \
                                                      set_gangwar(state_gangwar_1won);                \
                                                   end                                                \
                                                   set_den_flag_on(gang_2_dead_bit, 3)

#define player_has_destroyed_still                 get_den_flag(player_has_destroyed_still_bit, 3)
#define set_player_has_destroyed_still             set_den_flag_on(player_has_destroyed_still_bit, 3)

#define know_church                                get_den_flag(know_church_bit, 3)
#define set_know_church                            set_den_flag_on(know_church_bit, 3)

#define becky_known                                get_den_flag(becky_known_bit, 3)
#define set_becky_known                            set_den_flag_on(becky_known_bit, 3)

#define thugs_hostile                              get_den_flag(thugs_hostile_bit, 3)
#define set_thugs_hostile                          set_den_flag_on(thugs_hostile_bit, 3)

#define took_car_off_den_bus_1                     get_den_flag(took_car_off_den_bus_1_bit, 3)
#define set_took_car_off_den_bus_1                 set_den_flag_on(took_car_off_den_bus_1_bit, 3)

#define gang_2_member_2_killed                     get_den_flag(gang_2_member_2_killed_bit, 3)
#define set_gang_2_member_2_killed                 set_den_flag_on(gang_2_member_2_killed_bit, 3)
#define gang_2_member_3_killed                     get_den_flag(gang_2_member_3_killed_bit, 3)
#define set_gang_2_member_3_killed                 set_den_flag_on(gang_2_member_3_killed_bit, 3)
#define gang_2_member_4_killed                     get_den_flag(gang_2_member_4_killed_bit, 3)
#define set_gang_2_member_4_killed                 set_den_flag_on(gang_2_member_4_killed_bit, 3)



#define church_cleared_speech                      get_den_flag(church_cleared_speech_bit, 3)
#define set_church_cleared_speech                  set_den_flag_on(church_cleared_speech_bit, 3)

#define gang_war_dude_stray_message                get_den_flag(gang_war_dude_stray_message_bit, 3)
#define set_gang_war_dude_stray_message            set_den_flag_on(gang_war_dude_stray_message_bit, 3)
#define returned_to_church                         get_den_flag(returned_to_church_bit, 3)
#define set_returned_to_church                     set_den_flag_on(returned_to_church_bit, 3)

#define at_party_fight                             get_den_flag(at_party_fight_bit, 3)
#define set_at_party_fight                         set_den_flag_on(at_party_fight_bit, 3)
#define clear_at_party_fight                       set_den_flag_off(at_party_fight_bit, 3)


// den_flags_3 end

// non bits
#define state_jet_known_no                         (0)
#define state_jet_known_yes                        (1)
#define state_jet_known_detail                     (2)
#define jet_known(x)                               (global_var(GVAR_DEN_JET_KNOWN) == x)
#define set_jet_known(x)                           if (x > global_var(GVAR_DEN_JET_KNOWN)) then set_global_var(GVAR_DEN_JET_KNOWN, x)

#define state_car_regulator_none                   (0)
#define state_car_regulator_known                  (1)
#define state_car_regulator_found                  (2)
#define car_regulator(x)                           (global_var(GVAR_DEN_CAR_REGULATOR) == x)
#define set_car_regulator(x)                       if (x > global_var(GVAR_DEN_CAR_REGULATOR)) then set_global_var(GVAR_DEN_CAR_REGULATOR, x)

#define state_car_booster_none                     (0)
#define state_car_booster_known                    (1)
#define state_car_booster_found                    (2)
#define car_booster(x)                             (global_var(GVAR_DEN_CAR_BOOSTER) == x)
#define set_car_booster(x)                         if (x > global_var(GVAR_DEN_CAR_BOOSTER)) then set_global_var(GVAR_DEN_CAR_BOOSTER, x)

#define state_still_quest_no                       (0)
#define state_still_quest_serching                 (1)
#define state_still_quest_asked_to_destroy         (2)
#define state_still_quest_destroyed                (3)
#define state_still_quest_finished                 (4)
#define still_quest(x)                             (global_var(GVAR_QUEST_MAGGIE_STILL) == x)
#define set_still_quest(x)                         if (x > global_var(GVAR_QUEST_MAGGIE_STILL)) then set_global_var(GVAR_QUEST_MAGGIE_STILL, x);  \
                                                   ndebug("set_still_quest("+x+") == "+global_var(GVAR_QUEST_MAGGIE_STILL))

#define state_becky_job_none                       (0)
#define state_becky_job_collect                    (1)
#define state_becky_job_collect_done               (2)
#define state_becky_job_book                       (3)
#define state_becky_job_no_jobs                    (4)
//#define state_becky_job_gang                       (3)
//#define state_becky_job_fix                        (4)
#define becky_job(x)                               (global_var(GVAR_DEN_BECKY_JOB) == x)
#define set_becky_job(x)                           if (x > global_var(GVAR_DEN_BECKY_JOB)) then set_global_var(GVAR_DEN_BECKY_JOB, x);  \
                                                   ndebug("set_becky_job("+x+") == "+global_var(GVAR_DEN_BECKY_JOB))

variable caught_thief;
#define check_catch_thief                                                              \
         caught_thief := false;                                                        \
         if (cur_map_index == MAP_DEN_ENTRANCE) then begin                             \
            if ((tile_in_beckys(source_obj)) and (becky_guard_obj != 0)) then begin    \
               flush_add_timer_event(becky_guard_obj, 0, timed_event_thief);           \
            end                                                                        \
         end

/**
 * Set `becky_guard_obj` to current critter if currently unset or closer to PC that current guard obj.
 */
#define set_becky_guard \
   if (becky_guard_obj == 0) then begin \
      becky_guard_obj := self_obj; \
   end else if (tile_distance_objs(self_obj, dude_obj) < tile_distance_objs(becky_guard_obj, dude_obj)) then begin \
      becky_guard_obj := self_obj; \
   end


// gang war start
#define setup_gang_fight                           gfade_out(ONE_GAME_SECOND);                   \
                                                      set_gangwar(state_gangwar_in_fight);       \
                                                      if (game_time_hour > 600) then begin       \
                                                         game_time_advance_hour(100);            \
                                                      end                                        \
                                                   gfade_in(ONE_GAME_SECOND);                    \
                                                   load_map(MAP_DEN_BUSINESS,0)

#define state_gangwar_none                         (0)
#define state_gangwar_crates                       (1)
#define state_gangwar_ask                          (2)
#define state_gangwar_permission                   (3)
#define state_gangwar_find                         (4)
#define state_gangwar_weakness                     (5)
#define state_gangwar_fight                        (6)
#define state_gangwar_coward                       (7)
#define state_gangwar_no_show                      (8)
#define state_gangwar_in_fight                     (9)
#define state_gangwar_1won                         (10)
#define state_gangwar_2won                         (11)



#define gangwar(x)                                 (global_var(GVAR_DEN_GANGWAR) == x)
#define set_gangwar(x)                             if (x == state_gangwar_permission) then begin                              \
                                                      if (gangwar(state_gangwar_ask)) then begin                              \
                                                         den_display_mstr(1400);                                              \
                                                         give_xp(EXP_PERMISSION_FROM_METZGER);                                \
                                                      end                                                                     \
                                                      set_metzger_permission;                                                 \
                                                   end else if (x == state_gangwar_crates) then begin                         \
                                                      set_know_church;                                                        \
                                                   end else if (x == state_gangwar_weakness) then begin                       \
                                                      start_gang_d_day_timer;                                                 \
                                                      if (gangwar(state_gangwar_find)) then begin                             \
                                                         den_display_mstr(1300);                                              \
                                                         give_xp(EXP_FIND_GANG_WEAKNESS);                                     \
                                                      end                                                                     \
                                                   end else if (x == state_gangwar_2won) then begin /* Seraph: Changed state_gangwar_1won to state_gangwar_2won. Part of Haenlomal's gangwar fix. */ \
                                                      if ((gangwar(state_gangwar_1won) == false) and (gangwar(state_gangwar_2won) == false)) then begin  \
                                                         den_display_mstr(200);                                               \
                                                         give_xp(EXP_GANG_BATTLE_OVER);                                       \
                                                      end                                                                     \
                                                   end else if (x == state_gangwar_1won) then begin /* Seraph: Changed state_gangwar_2won to state_gangwar_1won. Part of Haenlomal's gangwar fix. */ \
                                                      if ((gang_2_hostile) and (gangwar(state_gangwar_1won) == false) and (gangwar(state_gangwar_2won) == false)) then begin  \
                                                         /* if (gang_trap(state_gang_trap_no) == false) then begin */ /* Seraph: Part of Haenlomal's gangwar fix. */ \
                                                            inc_general_rep(REP_BONUS_BETRAY_LARA);                           \
                                                            den_display_mstr(300);                                            \
                                                            give_xp(EXP_GANG_BATTLE_BETRAY_LARA);                             \
                                                         /* end */ /* Seraph: Part of Haenlomal's gangwar fix. */             \
                                                      end                                                                     \
                                                   end                                                                        \
                                                   if (x > global_var(GVAR_DEN_GANGWAR)) then                                 \
                                                      set_global_var(GVAR_DEN_GANGWAR, x);                                    \
                                                   ndebug("set_gangwar("+x+") == "+global_var(GVAR_DEN_GANGWAR))
#define state_gang_trap_no                         (0)
#define state_gang_trap_set                        (1)
#define state_gang_trap_noshow                     (2)
#define gang_trap(x)                               (global_var(GVAR_DEN_GANG_TRAP) == x)
#define set_gang_trap(x)                           if (x > global_var(GVAR_DEN_GANG_TRAP)) then set_global_var(GVAR_DEN_GANG_TRAP, x)

#define state_gang_door_no                         (0)
#define state_gang_door_yes                        (1)
#define state_gang_door_never                      (2)
#define gang_door(x)                               (global_var(GVAR_DEN_GANG_DOOR) == x)
#define set_gang_door(x)                           if (x == state_gang_door_yes) then begin              \
                                                      if (gang_door(state_gang_door_no)) then begin      \
                                                         den_display_mstr(1100);                         \
                                                         if (has_rep_slaver) then begin                  \
                                                            give_xp(EXP_TALK_INTO_CRATES_SLAVER);        \
                                                         end else if (metzger_known) then begin          \
                                                            give_xp(EXP_TALK_INTO_CRATES_METZGER_KNOWN); \
                                                         end else begin                                  \
                                                            give_xp(EXP_TALK_INTO_CRATES_THREATEN);      \
                                                         end                                             \
                                                      end                                                \
                                                   end                                                   \
                                                   set_global_var(GVAR_DEN_GANG_DOOR, x)

#define gang_1                                     (GVAR_DEN_GANG_1_COUNT)
#define gang_2                                     (GVAR_DEN_GANG_2_COUNT)

#define inc_gang_counter(the_gang)                 if (the_gang == gang_1) then begin                             \
                                                      if (cur_map_index != MAP_DEN_RESIDENTIAL) then              \
                                                         inc_global_var(gang_1);                                  \
                                                   end else if (cur_map_index == MAP_DEN_ENTRANCE) then begin     \
                                                      inc_global_var(gang_2);                                     \
                                                   end                                                            \
                                                   ndebug("inc_gang_counter == " + global_var(the_gang) + " / cur_map_index == "+cur_map_index+"/"+MAP_DEN_ENTRANCE)

#define dec_gang_counter(the_gang)                 if (the_gang == gang_1) then begin                                            \
                                                      dec_global_var(gang_1);                                                    \
                                                      if (global_var(gang_1) <= 0) then begin                                    \
                                                         set_gang_1_dead;                                                        \
                                                      end                                                                        \
                                                   end else if (the_gang == gang_2) then begin                                   \
                                                      if ((gangwar(state_gangwar_2won) == false) and (gang_1_dead == false)) then begin  \
                                                         dec_global_var(gang_2);                                                 \
                                                         if (global_var(gang_2) <= 0) then begin                                 \
                                                            set_gang_2_dead;                                                     \
                                                         end                                                                     \
                                                      end                                                                        \
                                                   end                                                                           \
                                                   ndebug("dec_gang_counter == " + global_var(the_gang))

#define check_switch_gang_team(x)                  if (self_gang == gang_##x) then begin                                                \
                                                      if (gang_##x##_hostile) then begin                                                \
                                                         if (self_team == TEAM_PLAYER) then begin                                       \
                                                            critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_DEN_GANG_##x); \
                                                         end                                                                            \
                                                      end                                                                               \
                                                   end
#define gang_combat_p_proc                         if (fixed_param == COMBAT_SUBTYPE_TURN) then begin    \
                                                      check_switch_gang_team(1)                          \
                                                      else check_switch_gang_team(2)                     \
                                                   end

/*
#define kill_gang_member(obj,gang)                 if (random(0,1)) then begin                                                   \
                                                      kill_critter(obj, random(ANIM_bad_landing, ANIM_big_hole));                \
                                                   end else if (random(0,1)) then begin                                          \
                                                      kill_critter(obj, random(ANIM_chunks_of_flesh, ANIM_dancing_autofire));    \
                                                   end else begin                                                                \
                                                      kill_critter(obj, random(ANIM_fall_back_blood, ANIM_fall_front_blood));    \
                                                   end
                                                   dec_gang_counter(gang)
*/
#define kill_gang_member(obj,gang)                 dest_gang_member;                                                           \
                                                   destroy_object(self_obj);                                                   \

#define unlock_church_door                         if (church_door_obj != 0) then begin               \
                                                      if (obj_is_locked(church_door_obj)) then begin  \
                                                         obj_unlock(church_door_obj);                 \
                                                      end                                             \
                                                   end

#define kill_gang_2_timer_up                       ((game_time >= global_var(GVAR_DEN_METZGER_GANG_KILL_TIMER)) and (global_var(GVAR_DEN_METZGER_GANG_KILL_TIMER) != 0))
#define gang_member_damage                         if (self_gang == gang_1) then begin                                                  \
                                                      unlock_church_door                                                                \
                                                      if (source_obj == dude_obj) then begin                                            \
                                                         if (self_team == TEAM_PLAYER) then begin                                       \
                                                            critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_DEN_GANG_1);   \
                                                         end                                                                            \
                                                         set_gang_1_hostile;                                                            \
                                                      end                                                                               \
                                                   end else if (self_gang == gang_2) then begin                                         \
                                                      if (source_obj == dude_obj) then begin                                            \
                                                         if (self_team == TEAM_PLAYER) then begin                                       \
                                                            critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_DEN_GANG_2);   \
                                                         end                                                                            \
                                                         set_gang_2_hostile;                                                            \
                                                      end                                                                               \
                                                   end

#define dest_gang_member                           if (self_gang == gang_1) then begin                                     \
                                                      inc_evil_critter                                                     \
                                                      /*if (NAME == SCRIPT_DCTYLER) then begin                             \
                                                         set_tyler_dead;                                                   \
                                                      end*/                                                                \
                                                      if (gang_1_member_1 == self_obj) then gang_1_member_1 := 0;          \
                                                      else if (gang_1_member_2 == self_obj) then gang_1_member_2 := 0;     \
                                                      else if (gang_1_member_3 == self_obj) then gang_1_member_3 := 0;     \
                                                      else if (gang_1_member_4 == self_obj) then gang_1_member_4 := 0;     \
                                                      else if (gang_1_member_5 == self_obj) then gang_1_member_5 := 0;     \
                                                   end else if (self_gang == gang_2) then begin                            \
                                                      inc_good_critter                                                     \
                                                      if (gang_2_member_1 == self_obj) then begin gang_2_member_1 := 0;    \
                                                      end else if (obj_pid(self_obj) == PID_GUN_GUARD_MALE)  then begin    \
                                                        gang_2_member_2 := 0;                                              \
                                                        set_gang_2_member_2_killed;                                        \
                                                      end else if (obj_pid(self_obj) == PID_MELEE_GUARD_MALE) then begin   \
                                                        gang_2_member_3 := 0;                                              \
                                                        set_gang_2_member_3_killed;                                        \
                                                      end else if (obj_pid(self_obj) == PID_AGILE_GUARD_FEMALE) then begin \
                                                        gang_2_member_4 := 0;                                              \
                                                        set_gang_2_member_4_killed;                                        \
                                                      end else if (gang_2_member_5 == self_obj) then gang_2_member_5 := 0; \
                                                   end                                                                     \
                                                   dec_gang_counter(self_gang)
#define gang_hostile                               (((self_gang == gang_1) and (gang_1_hostile)) or ((self_gang == gang_2) and (gang_2_hostile)))

variable the_follow_obj;
#define set_gang_2_follow                          if (gang_1_member_1 != 0 and obj_is_visible_flag(gang_1_member_1)) then the_follow_obj := gang_1_member_1;                            \
                                                   else if (gang_1_member_2 != 0 and obj_is_visible_flag(gang_1_member_2)) then the_follow_obj := gang_1_member_2;                            \
                                                   else if (gang_1_member_3 != 0 and obj_is_visible_flag(gang_1_member_3)) then the_follow_obj := gang_1_member_3;                            \
                                                   else if (gang_1_member_4 != 0 and obj_is_visible_flag(gang_1_member_4)) then the_follow_obj := gang_1_member_4;                            \
                                                   else if (gang_1_member_5 != 0 and obj_is_visible_flag(gang_1_member_5)) then the_follow_obj := gang_1_member_5;

#define gang_2_follow_to_attack                    the_follow_obj := 0;                                           \
                                                   set_gang_2_follow                                              \
                                                   if (the_follow_obj != 0) then begin                            \
                                                      if (obj_can_see_obj(self_obj, the_follow_obj)) then begin   \
                                                         attack(the_follow_obj);                                  \
                                                      end else if (anim_busy(self_obj) == false) then begin       \
                                                         Get_In_Face_Run_Dist(the_follow_obj,random(1,3))         \
                                                      end                                                         \
                                                   end

#define gang_critter_p_proc                        if (obj_is_visible_flag(self_obj)) then begin                                 \
                                                      if (gangwar(state_gangwar_in_fight)) then begin                            \
                                                         if (self_gang == gang_2) then begin                                     \
                                                            gang_2_follow_to_attack                                              \
                                                         end else if (self_gang == gang_1) then begin                            \
                                                         end                                                                     \
                                                      end else if (self_can_see_dude) then begin                                 \
                                                         if ((hostile) or (gang_hostile)) then begin                             \
                                                            self_attack_dude;                                                    \
                                                         end                                                                     \
                                                      end else if (self_tile != local_var(LVAR_Home_Tile)) then begin            \
                                                         animate_move_to_tile(local_var(LVAR_Home_Tile));                        \
                                                      end else if (self_cur_rot != local_var(LVAR_Home_Rotation)) then begin     \
                                                         animate_rotation(local_var(LVAR_Home_Rotation));                        \
                                                      end                                                                        \
                                                   end

#define gang_member_push_proc                      if (self_tile == local_var(LVAR_Home_Tile)) then begin   \
                                                      script_overrides;                                     \
                                                   end

#define gang_member_map_enter                      if (self_gang == gang_1) then begin                                                  \
                                                      if (NAME == SCRIPT_DCTYLER) then gang_1_member_1 := self_obj;                     \
                                                      else if (NAME == SCRIPT_DCMARC) then gang_1_member_2 := self_obj;                 \
                                                      else if (gang_1_member_3 == 0) then gang_1_member_3 := self_obj;                  \
                                                      else if (gang_1_member_4 == 0) then gang_1_member_4 := self_obj;                  \
                                                      else if (gang_1_member_5 == 0) then gang_1_member_5 := self_obj;                  \
                                                   end else if (self_gang == gang_2) then begin                                         \
                                                      if (NAME == SCRIPT_DCLARA) then gang_2_member_1 := self_obj;                      \
                                                      else if (obj_pid(self_obj) == PID_GUN_GUARD_MALE) then gang_2_member_2 := self_obj;        \
                                                      else if (obj_pid(self_obj) == PID_MELEE_GUARD_MALE) then gang_2_member_3 := self_obj;      \
                                                      else if (obj_pid(self_obj) == PID_AGILE_GUARD_FEMALE) then gang_2_member_4 := self_obj;    \
                                                      else if (gang_2_member_5 == 0) then gang_2_member_5 := self_obj;                           \
                                                   end                                                                                           \
                                                   check_set_obj_visiblility(self_obj, false);                                          \
                                                   if (is_loading_game == false) then begin                                             \
                                                      if (cur_map_index == MAP_DEN_ENTRANCE) then begin                                 \
                                                         if ((gangwar(state_gangwar_1won)) or (gangwar(state_gangwar_2won))) then begin \
                                                            /*dest_gang_member;  */                                                     \
                                                            destroy_object(self_obj);                                                   \
                                                         end                                                                            \
                                                      end else if (self_gang == gang_1) then begin                                      \
                                                         if ((gangwar(state_gangwar_2won)) or (gang_1_dead)) then begin                 \
                                                            kill_gang_member(self_obj, self_gang)                                       \
                                                         end                                                                            \
                                                      end else if (self_gang == gang_2) then begin                                      \
                                                         if ((gangwar(state_gangwar_1won)) or (gang_2_dead)) then begin                 \
                                                            kill_gang_member(self_obj, self_gang)                                       \
                                                         end                                                                            \
                                                      end                                                                               \
                                                      if (map_first_run) then begin                                                     \
                                                         ndebug("map__first_run"); \
                                                         if ( (cur_map_index == MAP_DEN_BUSINESS) or (cur_map_index == MAP_DEN_ENTRANCE) ) then   \
                                                            ndebug("inc gang counter");                                              \
                                                            inc_gang_counter(self_gang);                                                \
                                                         critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_AI_PACKET,AI_TOUGH_GUARD);      \
                                                         if (self_gang == gang_1) then begin                                            \
                                                            critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_DEN_GANG_1);   \
                                                         end else if (self_gang == gang_2) then begin                                   \
                                                            critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_DEN_GANG_2);   \
                                                         end                                                                            \
                                                         if ((self_gang == gang_2) and (cur_map_index == MAP_DEN_BUSINESS)) then begin  \
                                                            check_set_obj_visiblility(self_obj, true);                                  \
                                                         end else begin                                                                 \
                                                            set_local_var(LVAR_Home_Tile, self_tile);                                   \
                                                            set_local_var(LVAR_Home_Rotation, self_cur_rot);                            \
                                                         end                                                                            \
                                                      end if ((gangwar(state_gangwar_in_fight))) then begin                             \
                                                         check_set_obj_visiblility(self_obj, false);                                    \
                                                         if (self_gang == gang_1) then begin                                            \
                                                            if (gang_trap(state_gang_trap_set)) then begin                              \
                                                               critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_PLAYER);    \
                                                            end else if ((global_var(self_gang) > (7 + (tyler_dead == false))) or ((NAME == SCRIPT_DCTYLER) and (cur_map_index == MAP_DEN_BUSINESS))) then begin   \
                                                               if (self_gang == gang_1) then begin                                      \
                                                                  dest_gang_member;                                                     \
                                                                  check_set_obj_visiblility(self_obj, true);                            \
                                                               end                                                                      \
                                                            end                                                                         \
                                                         end else if (self_gang == gang_2) then begin                                   \
                                                            if (gang_trap(state_gang_trap_no)) then begin                               \
                                                               critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_PLAYER);    \
                                                            end                                                                         \
                                                         end                                                                            \
                                                      end                                                                               \
                                                   end

#define check_take_home_tile(x)                    if (self_obj == gang_2_member_##x) then begin                                                            \
                                                      if (gang_1_member_##x != 0) then begin                                                                \
                                                         set_local_var(LVAR_Home_Tile, tile_num(gang_1_member_##x));                                        \
                                                         set_local_var(LVAR_Home_Rotation, has_trait(TRAIT_OBJECT, gang_1_member_##x, OBJECT_CUR_ROT));     \
                                                      end                                                                                                   \
                                                   end
#define gang_map_update_p_proc                     if (self_gang == gang_2) then begin                                        \
                                                      if (local_var(LVAR_Home_Tile) == 0) then begin                          \
                                                         check_take_home_tile(1)                                              \
                                                         else check_take_home_tile(2)                                         \
                                                         else check_take_home_tile(3)                                         \
                                                         else check_take_home_tile(4)                                         \
                                                         else check_take_home_tile(5)                                         \
                                                         if (local_var(LVAR_Home_Tile) == 0) then begin                       \
                                                            random_tile_in_box(22340, 22332, 24132, 23940);                   \
                                                            set_local_var(LVAR_Home_Tile, global_temp);                       \
                                                            set_local_var(LVAR_Home_Rotation, random(2,4));                   \
                                                         end                                                                  \
                                                      end                                                                     \
                                                      if (gang_2_member_5 == 0) then begin                                    \
                                                         gang_2_member_5 := gang_2_member_4;                                  \
                                                         gang_2_member_4 := 0;                                                \
                                                      end                                                                     \
                                                      if (gang_2_member_4 == 0) then begin                                    \
                                                         gang_2_member_4 := gang_2_member_3;                                  \
                                                         gang_2_member_3 := 0;                                                \
                                                      end                                                                     \
                                                      if (gang_2_member_3 == 0) then begin                                    \
                                                         gang_2_member_3 := gang_2_member_2;                                  \
                                                         gang_2_member_2 := 0;                                                \
                                                      end                                                                     \
                                                      if (gang_2_member_2 == 0) then begin                                    \
                                                         gang_2_member_2 := gang_2_member_1;                                  \
                                                         gang_2_member_1 := 0;                                                \
                                                      end                                                                     \
                                                   end else begin                                                             \
                                                      if (local_var(LVAR_Home_Tile) == 0) then begin                          \
                                                         set_local_var(LVAR_Home_Tile, self_tile);                            \
                                                      end                                                                     \
                                                      if (gang_1_member_5 == 0) then begin                                    \
                                                         gang_1_member_5 := gang_1_member_4;                                  \
                                                         gang_1_member_4 := 0;                                                \
                                                      end                                                                     \
                                                      if (gang_1_member_4 == 0) then begin                                    \
                                                         gang_1_member_4 := gang_1_member_3;                                  \
                                                         gang_1_member_3 := 0;                                                \
                                                      end                                                                     \
                                                      if (gang_1_member_3 == 0) then begin                                    \
                                                         gang_1_member_3 := gang_1_member_2;                                  \
                                                         gang_1_member_2 := 0;                                                \
                                                      end                                                                     \
                                                      if (gang_1_member_2 == 0) then begin                                    \
                                                         gang_1_member_2 := gang_1_member_1;                                  \
                                                         gang_1_member_1 := 0;                                                \
                                                      end                                                                     \
                                                   end
// gang war end

#define state_smitty_deliver_none                  (0)
#define state_smitty_deliver_in_progress           (1)
#define state_smitty_deliver_failed                (2)
#define state_smitty_deliver_finished              (3)
#define state_smitty_deliver_reward_given          (4)
#define smitty_deliver_time_up                     ((game_time > global_var(GVAR_SMITTY_DELIVER_TIME)) and (global_var(GVAR_SMITTY_DELIVER_TIME) != 0))
#define smitty_deliver_failed                      ((smitty_deliver(state_smitty_deliver_failed)) or ((smitty_deliver(state_smitty_deliver_in_progress)) and (smitty_deliver_time_up)))
#define smitty_deliver(x)                          (global_var(GVAR_DEN_SMITTY_DELIVER) == x)
#define set_smitty_deliver(x)                      if (x == state_smitty_deliver_finished) then begin                                               \
                                                      if (global_var(GVAR_DEN_SMITTY_DELIVER) < state_smitty_deliver_finished) then begin           \
                                                         den_display_mstr(1200);                                                                    \
                                                         give_xp(EXP_SMITTY_MEAL_GIVEN);                                                            \
                                                         inc_general_rep(REP_BONUS_DEN_GAVE_SMITTY_MEAL);                                           \
                                                      end                                                                                           \
                                                   end else if (x == state_smitty_deliver_in_progress) then begin                                   \
                                                      if (global_var(GVAR_SMITTY_DELIVER_TIME) == 0) then begin                                     \
                                                         set_global_var(GVAR_SMITTY_DELIVER_TIME, game_time + ONE_GAME_DAY);                        \
                                                      end                                                                                           \
                                                   end                                                                                              \
                                                   if (global_var(GVAR_DEN_SMITTY_DELIVER) < x) then set_global_var(GVAR_DEN_SMITTY_DELIVER, x)

#define state_see_vic_no                           (0)
#define state_see_vic_waiting                      (1)
#define state_see_vic_okay                         (2)
#define state_see_vic_never                        (3)
#define see_vic(x)                                 (global_var(GVAR_DEN_SEE_VIC) == x)
#define set_see_vic(x)                             if (x > global_var(GVAR_DEN_SEE_VIC)) then set_global_var(GVAR_DEN_SEE_VIC, x)

#define state_gang_d_day_no                        (0)
#define state_gang_d_day_over                      (-1)
#define gang_d_day_yes                             (global_var(GVAR_DEN_GANG_D_DAY) > state_gang_d_day_no)
#define start_gang_d_day_timer                     if (global_var(GVAR_DEN_GANG_D_DAY) == state_gang_d_day_no) then set_global_var(GVAR_DEN_GANG_D_DAY, game_time + ticks_til_hour(600) + (ONE_GAME_DAY * (game_time < 600)))
#define gang_d_day_timer_up                        (game_time > global_var(GVAR_DEN_GANG_D_DAY))
#define check_gang_d_day_timer                     if (gang_d_day_yes) then begin                                                              \
                                                      if (gang_d_day_timer_up) then begin                                                      \
                                                         set_global_var(GVAR_DEN_GANG_D_DAY, state_gang_d_day_over);                           \
                                                         if ((gangwar(state_gangwar_fight)) or (gangwar(state_gangwar_coward))) then begin     \
                                                            set_gangwar(state_gangwar_no_show);                                                \
                                                         end                                                                                   \
                                                         if (gang_trap(state_gang_trap_set)) then begin                                        \
                                                            set_gang_trap(state_gang_trap_noshow);                                             \
                                                         end                                                                                   \
                                                      end                                                                                      \
                                                   end

// slaves
#define slave_leash_length                         (10)
#define slave_is_primitive                         ((self_pid == PID_PRIMITIVE_VILLAGER_MALE) or (self_pid == PID_PRIMITIVE_VILLAGER_FEMALE))
#define slave_is_nomad                             (slave_is_primitive == false)
#define slave_was_party_member(x)                  ((x == PID_DAVIN) or (x == PID_MIRIA) or (x == PID_JOHN_MACRAE) or (x == PID_VIC) or (x == PID_MYRON) or (x == PID_SULIK))

// slave run
#define slave_score_good                           (7)
#define slave_score_average                        (4)
#define slave_score_bad                            (1)
#define calc_slaving_score                         (global_var(GVAR_SLAVES_COUNT) - (global_var(GVAR_SLAVERS_LOST) * 7))

// companions
#ifndef vic_is_dude_companion
#define vic_is_dude_companion                      (obj_can_see_obj(self_obj, Vic_Ptr))
#endif
#ifndef miria_is_dude_companion
#define miria_is_dude_companion                    (obj_can_see_obj(self_obj, Miria_Ptr))
#endif

// has items
#define dude_has_vic_water_flask                   (obj_is_carrying_obj_pid(dude_obj, PID_VIC_WATER_FLASK) > 0)
#define dude_has_vic_radio                         (obj_is_carrying_obj_pid(dude_obj, PID_VIC_RADIO) > 0)
#define dude_has_becky_book                        (obj_is_carrying_obj_pid(dude_obj, PID_BECKY_BOOK) > 0)
#define dude_has_smitty_meal                       (obj_is_carrying_obj_pid(dude_obj, PID_SMITTY_MEAL) > 0)
#define dude_has_car_repair_part                   (obj_is_carrying_obj_pid(dude_obj, PID_CAR_FUEL_CELL_CONTROLLER) > 0)
#define dude_has_car_upgrade_part                  (obj_is_carrying_obj_pid(dude_obj, PID_CAR_FUEL_INJECTION) > 0)

// car
#define player_has_car                             (global_var(GVAR_PLAYER_GOT_CAR))
#define set_car_upgrade_fuel_cell_regulator        set_global_var(GVAR_CAR_UPGRADE_FUEL_CELL_REGULATOR, true)

#define state_smitty_part_unknown                  (0)
#define state_smitty_part_known                    (1)
#define state_smitty_part_given                    (2)
#define smitty_part(x)                             (global_var(GVAR_DEN_SMITTY_PART) == x)
#define set_smitty_part(x)                         if (x == state_smitty_part_given) then begin       \
                                                      set_global_var(GVAR_PLAYER_GOT_CAR, true);      \
                                                   end                                                \
                                                   set_car_part_pip(car_part_pip_assigned);           \
                                                   if (global_var(GVAR_DEN_SMITTY_PART) < x) then set_global_var(GVAR_DEN_SMITTY_PART, x)

// local stuff for critters
#define becky_friends_dead                         (local_var(LVAR_BECKY_FRIENDS_DEAD))
#define inc_becky_friends_dead                     inc_local_var(LVAR_BECKY_FRIENDS_DEAD)

#define becky_drink                                (local_var(LVAR_BECKY_DRINKS))
#define inc_becky_drinks                           inc_local_var(LVAR_BECKY_DRINKS)

#define state_fred_no                                (0)
//#define state_fred_paid                            (1) //commented out by killap
//#define state_fred_covered                         (2) //commented out by killap
//#define state_fred_loan                            (3) //commented out by killap
#define fred(x)                                    (local_var(LVAR_DEN_FRED) == x)
#define set_fred(x)                                if (x > local_var(LVAR_DEN_FRED)) then set_local_var(LVAR_DEN_FRED, x)

#define fred_won                                   ((game_time >= local_var(LVAR_FRED_WIN_TIMER)) and (local_var(LVAR_FRED_WIN_TIMER) != 0))
#define start_fred_timer                           if (local_var(LVAR_FRED_WIN_TIMER) == 0) then set_local_var(LVAR_FRED_WIN_TIMER, game_time + (ONE_GAME_MONTH * random(3, 6)))

#define fred_money_not_set                         (global_var(GVAR_FRED_MONEY) == 0)
#define fred_money                                 (global_var(GVAR_FRED_MONEY))
#define set_fred_money(x)                          set_global_var(GVAR_FRED_MONEY, x)

#define vic_price_not_set                          (local_var(LVAR_VIC_PRICE) == 0)
#define vic_price                                  (local_var(LVAR_VIC_PRICE))
#define set_vic_price(x)                           set_local_var(LVAR_VIC_PRICE, x)

#define state_bb_note_no                           (0)
#define state_bb_note_seen                         (1)
#define state_bb_note_removed                      (2)
#define state_bb_note_done                         (3)
#define bb_note(x)                                 (local_var(LVAR_DEN_BB_NOTE) == x)
#define check_remove_time                          if (bb_note(state_bb_note_seen)) then begin                       \
                                                      if (game_time > local_var(LVAR_Remove_Post_time)) then begin   \
                                                         set_bb_note(state_bb_note_removed);                         \
                                                      end                                                            \
                                                   end
#define set_bb_note(x)                             if (local_var(LVAR_Remove_Post_time) == 0) then begin                         \
                                                      set_local_var(LVAR_Remove_Post_time, game_time + (2 * ONE_GAME_DAY));      \
                                                   end                                                                           \
                                                   if (x > local_var(LVAR_DEN_BB_NOTE)) then set_local_var(LVAR_DEN_BB_NOTE, x)

#define becky_morning                              ((game_time < local_var(LVAR_BECKY_MORNING)) and (local_var(LVAR_BECKY_MORNING) != 0))
#define set_becky_morning                          set_local_var(LVAR_BECKY_MORNING, game_time + ONE_GAME_DAY)

#define aidan_pissed                               ((game_time < local_var(LVAR_AIDAN_PISSED)) and (local_var(LVAR_AIDAN_PISSED) != 0))
#define set_aidan_pissed                           set_local_var(LVAR_AIDAN_PISSED, game_time + (30 *ONE_GAME_MINUTE))

#define state_metzger_ban_none                     (0)
#define state_metzger_ban_2low                     (1)
#define state_metzger_ban_2high                    (2)
#define metzger_ban(x)                             (local_var(LVAR_METZGER_BAN) == x)
#define set_metzger_ban(x)                         if (x > local_var(LVAR_METZGER_BAN)) then set_local_var(LVAR_METZGER_BAN, x)

#define CHECK_LEVEL \
   if not is_loading_game and (elevation(self_obj) != elevation(dude_obj)) then \
      move_to(self_obj, self_tile, elevation(dude_obj));

#endif // DEN_H
