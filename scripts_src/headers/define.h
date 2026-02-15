/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef DEFINE_H
#define DEFINE_H

//   This file holds all of the things that should be preprocessed.

// got to define this very first to be able to use everywhere
#define ndebug(message)    debug_msg(SCRIPT_REALNAME + ": " + message + "\n")

#include "global.h"
#include "itempid.h"
#include "scripts.h"
#include "teams.h"
#include "condtion.h"
//#include "reppoint.h"
#include "aipacket.h"
#include "exppoint.h"
#include "scenepid.h"
#include "maps.h"
#include "animcomd.h"
#include "critrpid.h"
#include "artfid.h"
#include "party.h"
#include "reaction.h"

#include "../sfall/sfall.h"

// script.h: Script Procedure Types //
#define no_proc           (0)
#define start_proc        (1)
#define spatial_proc      (2)
#define description_proc  (3)
#define pickup_proc       (4)
#define drop_proc         (5)
#define use_proc          (6)
#define use_obj_on_proc   (7)
#define use_skill_on_proc (8)
#define use_ad_on_proc    (9)
#define use_disad_on_proc (10)
#define talk_proc         (11)
#define critter_proc      (12)
#define combat_proc       (13)
#define damage_proc       (14)
#define map_enter_proc    (15)
#define map_exit_proc     (16)
#define create_proc       (17)
#define destroy_proc      (18)
#define barter_init_proc  (19)
#define barter_proc       (20)
#define look_at_proc      (21)
#define timed_event_proc  (22)
#define map_update_proc   (23)

// Map-Enter Proc subdefines
//   Warning: This one is only valid in map_enter proc right when run!
///#define map_first_run (fixed_param)
#define METARULE_TEST_FIRSTRUN    14
#define map_first_run metarule(METARULE_TEST_FIRSTRUN, 0)
#define METARULE_IS_LOADGAME      22
#define is_loading_game metarule(METARULE_IS_LOADGAME, 0)

// script.h: Script Combat Procedure SubTypes //
#define COMBAT_SUBTYPE_WEAPON_USED    (1)
#define COMBAT_SUBTYPE_HIT_SUCCEEDED  (2)
#define COMBAT_SUBTYPE_SEQUENCING     (3)
#define COMBAT_SUBTYPE_TURN           (4)
#define COMBAT_SUBTYPE_NONCOM_TURN    (5)

// ----------------------------------------------------------------------- //

// pc critter defines //
#define give_character_points(X)  give_exp_points(X)

// create_object defines //
#define create_object(X,Y,Z)    create_object_sid(X,Y,Z,-1)
//#define destroy_object(X)       destroy_mult_objs(X,1)
//#define add_obj_to_inven(X,Y)   add_mult_objs_to_inven(X,Y,1)
//#define rm_obj_from_inven(X,Y)  rm_mult_objs_from_inven(X,Y,1)

// combat defines //
#define attack(WHO)  attack_complex(WHO,0,1,0,0,30000,0,0)

// wield_obj defines //
#define wield_obj(WHAT)  wield_obj_critter(self_obj,WHAT)

#define gdialog_barter gdialog_mod_barter(0)

// Movie number defines //
// Commented out movies are done in the C-engine.  JLR
//#define INTERPLAY_LOGO_MOVIE_PC 0 //   "iplogo.mve",  // Interplay logo.
//#define INTRO_MOVIE             1 //   "intro.mve",   // Intro.
//#define ELDER_MOVIE             2 //   "elder.mve",
#define VSUIT_MOVIE             3 //   "vsuit.mve",
#define AFAILED_MOVIE           4 //   "afailed.mve",
#define ADESTROY_MOVIE          5 //   "adestroy.mve",
#define CAR_MOVIE               6 //   "car.mve",
#define CARTUCCI_MOVIE          7 //   "cartucci.mve",
#define DETHCLAW_MOVIE          8 //   "dethclaw.mve",
#define TANKER_MOVIE            9 //   "tanker.mve",
#define ENCLAVE_MOVIE          10 //   "enclave.mve",
#define DERRICK_MOVIE          11 //   "derrick.mve"

// float_msg defines //
#define FLOAT_MSG_WARNING    (-2)
#define FLOAT_MSG_SEQUENTIAL (-1)
#define FLOAT_MSG_NORMAL      (0)
#define FLOAT_MSG_BLACK       (1)
#define FLOAT_MSG_RED         (2)
#define FLOAT_MSG_GREEN       (3)
#define FLOAT_MSG_BLUE        (4)
#define FLOAT_MSG_PURPLE      (5)
#define FLOAT_MSG_NEAR_WHITE  (6)
#define FLOAT_MSG_LIGHT_RED   (7)
#define FLOAT_MSG_YELLOW      (8)
#define FLOAT_MSG_WHITE       (9)
#define FLOAT_MSG_GREY       (10)
#define FLOAT_MSG_DARK_GREY  (11)
#define FLOAT_MSG_LIGHT_GREY (12)
#define float_msg_clear(WHO)  float_msg(WHO,0,0)

// dialogue defines //
#define start_dialogue(X,Y)   start_gdialog(-1,X,Y,-1,-1)
// head_anim enums
//#define very_good_reaction  (0)
#define good_fidget         (1)
//#define good_to_neutral     (2)
//#define neutral_to_good     (3)
#define neutral_fidget      (4)
//#define neutral_to_bad      (5)
//#define bad_to_neutral      (6)
#define bad_fidget          (7)
//#define very_bad_reaction   (8)
//#define good_phonemes       (9)
//#define neutral_phonemes   (10)
//#define bad_phonemes       (11)

// Head defines //
#define HEAD_MARCUS         (1)     //marcus -- Party Member (found in Broken Hills)
#define HEAD_MYRON          (2)     //Myron -- Party Member (found in New Reno)
#define HEAD_ELDER          (3)     // Elder -- (found in Arroyo)
#define HEAD_LYNETTE        (4)     // Lynette -- fount in Vault City
#define HEAD_HAROLD         (5)     // HAROLD -- found in Gecko
#define HEAD_TANDI          (6)     //  Tandi -- Leader of the NCR
#define HEAD_COM_OFFICER    (7)     // Com Officer in Gecko
#define HEAD_SULIK          (8)     // Sulik -- Party Member (found in Klamath)
#define HEAD_PRESIDENT      (9)     // President of the Enclave
#define HEAD_HAKUNIN        (10)    // Hakunin -- Found in Arroyo
#define HEAD_BOSS           (11)
#define HEAD_DYING_HAKUNIN  (12)
/*
#define HEAD_OVERSEER    (1)  //ovrsr  -- vault
*/
// Head defines //
#define BACKGROUND1           (2)    // rstymetl
#define BACKGROUND_HUB        (3) //hub.frm
#define BACKGROUND_NECROPOLIS (4) //necro.frm
#define BACKGROUND_BHOOD      (5) //bhood.frm
#define BACKGROUND_MILITARYBS (6) //military.frm
#define BACKGROUND_JUNKTOWN   (7) //junktown.frm
#define BACKGROUND_CATHEDRAL  (8) //cath.frm
#define BACKGROUND_SHADY      (9) //shady.frm
#define BACKGROUND_VAULT     (10) //vault.frm
#define BACKGROUND_MASTER    (11) //master.frm
#define BACKGROUND_FOLLOWER  (12) //follow.frm
#define BACKGROUND_RAIDERS   (13) //raider.frm
   // Start of Fallout 2: Backgrounds
#define BACKGROUND_CAVE      (14) //cave0001.frm
#define BACKGROUND_ENCLAVE   (15) //enclave.frm
#define BACKGROUND_WASTELAND (16) //wastelnd.frm
#define BACKGROUND_BOSS      (17) // boss.frm
#define BACKGROUND_PRESIDENT (18)       // pres.frm
#define BACKGROUND_TENT      (19)       // tent.frm
#define BACKGROUND_ADOBE     (20)       // Adobe.frm
// Mood defines //
#define GOOD_REACTION    (49)
#define NEUTRAL_REACTION (50)
#define BAD_REACTION     (51)
//#define BAD_REACTION     (49)
//#define NEUTRAL_REACTION (50)
//#define GOOD_REACTION    (51)


// ----------------------------------------------------------------------- //
// ----------------------------------------------------------------------- //

#define IAN_MEMBER_PTR     party_member_obj(PID_IAN)
#define KATJA_MEMBER_PTR   party_member_obj(PID_KATJA)
#define TYCHO_MEMBER_PTR   party_member_obj(PID_TYCHO)
#define DOGMEAT_MEMBER_PTR party_member_obj(PID_DOGMEAT)
#define TANDI_MEMBER_PTR   party_member_obj(PID_TANDI)

// ----------------------------------------------------------------------- //
// ----------------------------------------------------------------------- //


// Trait defines //
#include "define_pre.h" // ReDefine needs this

// Perk Trait Types
#define PERK_bonus_awareness      (0)
#define PERK_bonus_hth_attacks    (1)
#define PERK_bonus_hth_damage     (2)
#define PERK_bonus_move           (3)
#define PERK_bonus_ranged_damage  (4)
#define PERK_bonus_rate_of_fire   (5)
#define PERK_earlier_sequence     (6)
#define PERK_faster_healing       (7)
#define PERK_more_criticals       (8)
#define PERK_night_vision         (9)
#define PERK_presence            (10)
#define PERK_rad_resistance      (11)
#define PERK_toughness           (12)
#define PERK_strong_back         (13)
#define PERK_sharpshooter        (14)
#define PERK_silent_running      (15)
#define PERK_survivalist         (16)
#define PERK_master_trader       (17)
#define PERK_educated            (18)
#define PERK_healer              (19)
#define PERK_fortune_finder      (20)
#define PERK_better_criticals    (21)
#define PERK_empathy             (22)
#define PERK_slayer              (23)
#define PERK_sniper              (24)
#define PERK_silent_death        (25)
#define PERK_action_boy          (26)
///#define PERK_mental_block        (27)  -- Disabled FO2
#define PERK_lifegiver           (28)
#define PERK_dodger              (29)
#define PERK_snakeater           (30)
#define PERK_mr_fixit            (31)
#define PERK_medic               (32)
#define PERK_master_thief        (33)
#define PERK_speaker             (34)
#define PERK_heave_ho            (35)
///#define PERK_friendly_foe        (36)  -- Disabled FO2
#define PERK_pickpocket          (37)
#define PERK_ghost               (38)
#define PERK_cult_of_personality (39)
///#define PERK_scrounger           (40)  -- Disabled FO2
#define PERK_explorer            (41)
///#define PERK_flower_child        (42)  -- Disabled FO2
#define PERK_pathfinder          (43)
///#define PERK_animal_friend       (44)  -- Disabled FO2
#define PERK_scout               (45)
#define PERK_mysterious_stranger (46)
#define PERK_ranger              (47)
#define PERK_quick_pockets       (48)
#define PERK_smooth_talker       (49)
#define PERK_swift_learner       (50)
#define PERK_tag                 (51)
#define PERK_mutate              (52)
//#define PERK_add_nuka            // Do NOT USE!  Engine ONLY!
//#define PERK_add_buffout         // Do NOT USE!  Engine ONLY!
//#define PERK_add_mentats         // Do NOT USE!  Engine ONLY!
//#define PERK_add_psycho          // Do NOT USE!  Engine ONLY!
//#define PERK_add_radaway         // Do NOT USE!  Engine ONLY!
//#define PERK_weapon_long_range   // Do NOT USE!  Engine ONLY!
//#define PERK_weapon_accurate     // Do NOT USE!  Engine ONLY!
//#define PERK_weapon_penetrate    // Do NOT USE!  Engine ONLY!
//#define PERK_weapon_knockback    // Do NOT USE!  Engine ONLY!
//#define PERK_armor_powered       // Do NOT USE!  Engine ONLY!
//#define PERK_armor_combat        // Do NOT USE!  Engine ONLY!
// Note: Fallout 2: New Perks      // Do NOT USE!  Engine ONLY!
//#define PERK_weapon_scope_range  // Do NOT USE!  Engine ONLY!
//#define PERK_weapon_fast_reload  // Do NOT USE!  Engine ONLY!
//#define PERK_weapon_night_sight  // Do NOT USE!  Engine ONLY!
//#define PERK_weapon_flameboy     // Do NOT USE!  Engine ONLY!
//#define PERK_armor_advanced_1    // Do NOT USE!  Engine ONLY!
//#define PERK_armor_advanced_2    // Do NOT USE!  Engine ONLY!
//#define PERK_add_jet             // Do NOT USE!  Engine ONLY!
//#define PERK_add_tragic          // Do NOT USE!  Engine ONLY!
//#define PERK_armor_charisma      // Do NOT USE!  Engine ONLY!
#define PERK_gecko_skinning_perk            (73)
#define PERK_dermal_armor_perk              (74)
#define PERK_dermal_enhancement_perk        (75)
#define PERK_phoenix_armor_perk             (76)
#define PERK_phoenix_enhancement_perk       (77)
#define PERK_vault_city_inoculations_perk   (78)
#define PERK_adrenaline_rush_perk           (79)
#define PERK_cautious_nature_perk           (80)
#define PERK_comprehension_perk             (81)
#define PERK_demolition_expert_perk         (82)
#define PERK_gambler_perk                   (83)
#define PERK_gain_strength_perk             (84)
#define PERK_gain_perception_perk           (85)
#define PERK_gain_endurance_perk            (86)
#define PERK_gain_charisma_perk             (87)
#define PERK_gain_intelligence_perk         (88)
#define PERK_gain_agility_perk              (89)
#define PERK_gain_luck_perk                 (90)
#define PERK_harmless_perk                  (91)
#define PERK_here_and_now_perk              (92)
#define PERK_hth_evade_perk                 (93)
#define PERK_kama_sutra_perk                (94)
#define PERK_karma_beacon_perk              (95)
#define PERK_light_step_perk                (96)
#define PERK_living_anatomy_perk            (97)
#define PERK_magnetic_personality_perk      (98)
#define PERK_negotiator_perk                (99)
#define PERK_pack_rat_perk                 (100)
#define PERK_pyromaniac_perk               (101)
#define PERK_quick_recovery_perk           (102)
#define PERK_salesman_perk                 (103)
#define PERK_stonewall_perk                (104)
#define PERK_thief_perk                    (105)
#define PERK_weapon_handling_perk          (106)
#define PERK_vault_city_training_perk      (107)
#define PERK_alcohol_hp_bonus1_perk        (108)
#define PERK_alcohol_hp_bonus2_perk        (109)
#define PERK_alcohol_hp_neg1_perk          (110)
#define PERK_alcohol_hp_neg2_perk          (111)
#define PERK_autodoc_hp_bonus1_perk        (112)
#define PERK_autodoc_hp_bonus2_perk        (113)
#define PERK_autodoc_hp_neg1_perk          (114)
#define PERK_autodoc_hp_neg2_perk          (115)
#define PERK_expert_excrement_expediter_perk (116)
#define PERK_weapon_knockout_perk            (117)
#define PERK_jinxed_perk                     (118)

// Object Trait Subtypes
#define OBJECT_AI_PACKET  (5)
#define OBJECT_TEAM_NUM   (6)
#define OBJECT_CUR_ROT    (10)
#define OBJECT_VISIBILITY (666)
#define OBJECT_CUR_WEIGHT (669)
#define obj_is_visible_flag(WHO)  has_trait(TRAIT_OBJECT,WHO,OBJECT_VISIBILITY)
// Trait Types
#define TRAIT_fast_metabolism  (0)
#define TRAIT_bruiser          (1)
#define TRAIT_small_frame      (2)
#define TRAIT_one_hander       (3)
#define TRAIT_finesse          (4)
#define TRAIT_kamikaze         (5)
#define TRAIT_heavy_handed     (6)
#define TRAIT_fast_shot        (7)
#define TRAIT_bloody_mess      (8)
#define TRAIT_jinxed           (9)
#define TRAIT_good_natured    (10)
#define TRAIT_drug_addict     (11)
#define TRAIT_drug_resistant  (12)
#define TRAIT_sex_appeal      (13)
#define TRAIT_skilled         (14)
#define TRAIT_gifted          (15)

// ----------------------------------------------------------------------- //
// ----------------------------------------------------------------------- //

// proto.h: stats //
// SPECIAL System stats
#define STAT_st              (0)
#define STAT_pe              (1)
#define STAT_en              (2)
#define STAT_ch              (3)
#define STAT_iq              (4)
#define STAT_ag              (5)
#define STAT_lu              (6)
#define STAT_max_hp          (7)
///  strength, perception, endurance, charisma, intelligence, agility,
///  luck,   // luck MUST be the last basic stat
// derived stats
#define STAT_max_move_points    (8)
#define STAT_ac                 (9)
///#define STAT_unarmed_dmg        (10)
#define STAT_unused             (10)
#define STAT_melee_dmg          (11)
#define STAT_carry_amt          (12)
#define STAT_sequence           (13)
#define STAT_heal_rate          (14)
#define STAT_crit_chance        (15)
#define STAT_better_crit        (16)
#define STAT_dmg_thresh         (17)
#define STAT_dmg_thresh_laser   (18)
#define STAT_dmg_thresh_fire    (19)
#define STAT_dmg_thresh_plasma  (20)
#define STAT_dmg_thresh_electrical (21)
#define STAT_dmg_thresh_emp        (22)
#define STAT_dmg_thresh_explosion  (23)
#define STAT_dmg_resist            (24)
#define STAT_dmg_resist_laser      (25)
#define STAT_dmg_resist_fire       (26)
#define STAT_dmg_resist_plasma     (27)
#define STAT_dmg_resist_electrical (28)
#define STAT_dmg_resist_emp        (29)
#define STAT_dmg_resist_explosion  (30)
#define STAT_rad_resist            (31)
#define STAT_poison_resist         (32)
// poison_resist MUST be the last derived stat
// nonderived stats
#define STAT_age                   (33)
#define STAT_gender                (34)
// gender MUST be the last nonderived stat
#define STAT_current_hp            (35)
#define STAT_current_poison        (36)
#define STAT_current_rad           (37)
#define STAT_real_max_stat         (38)
// extra stat-like values that are treated specially
#define STAT_max_stat  STAT_current_hp

#define PCSTAT_unspent_skill_points (0)
#define PCSTAT_level                (1)
#define PCSTAT_experience           (2)
#define PCSTAT_reputation           (3)
#define PCSTAT_karma                (4)
#define PCSTAT_max_pc_stat          (5)

// ----------------------------------------------------------------------- //
// ----------------------------------------------------------------------- //

// skill.h: Skill Equates //
// the following are skills for the SPECIAL system
#define SKILL_SMALL_GUNS                    (0)
#define SKILL_BIG_GUNS                      (1)
#define SKILL_ENERGY_WEAPONS                (2)
#define SKILL_UNARMED_COMBAT                (3)
#define SKILL_MELEE                         (4)
#define SKILL_THROWING                      (5)
#define SKILL_FIRST_AID                     (6)
#define SKILL_DOCTOR                        (7)
#define SKILL_SNEAK                         (8)
#define SKILL_LOCKPICK                      (9)
#define SKILL_STEAL                         (10)
#define SKILL_TRAPS                         (11)
#define SKILL_SCIENCE                       (12)
#define SKILL_REPAIR                        (13)
#define SKILL_SPEECH                        (14)
#define SKILL_BARTER                        (15)
#define SKILL_GAMBLING                      (16)
#define SKILL_OUTDOORSMAN                   (17)

#define CRITTER_SKILL_LEVEL(X,Y)  has_skill(X,Y)
#define critter_skill_level(X,Y)  has_skill(X,Y)

// ----------------------------------------------------------------------- //
// ----------------------------------------------------------------------- //

// reaction.h: Reaction Levels //
#define rl_disastrous (0)
#define rl_very_bad   (1)
#define rl_bad        (2)
#define rl_poor       (3)
#define rl_neutral    (4)
#define rl_good       (5)
#define rl_very_good  (6)
#define rl_excellent  (7)


// proto.h //
//#define LOAD_MAP_INDEX (32)

// proto.h //
#define GENDER_MALE   (0)
#define GENDER_FEMALE (1)


// critter_state States //
#define CRITTER_IS_NORMAL (0)
#define CRITTER_IS_DEAD   (1)
#define CRITTER_IS_PRONE  (2)

#define is_critter_dead(who)    (critter_state(who) bwand CRITTER_IS_DEAD)
#define is_critter_prone(who)   (critter_state(who) bwand CRITTER_IS_PRONE)


// inventory Equates //
#define INVEN_TYPE_WORN        (0)
#define INVEN_TYPE_RIGHT_HAND  (1)
#define INVEN_TYPE_LEFT_HAND   (2)

#define INVEN_TYPE_INV_COUNT   (-2)
#define inven_count(WHO)       critter_inven_obj(WHO, INVEN_TYPE_INV_COUNT)


// ----------------------------------------------------------------------- //
// ----------------------------------------------------------------------- //

/* proto_data data_member Equates */

/*   Item subtypes */
#define item_type_armor        (0)
#define item_type_container    (1)
#define item_type_drug         (2)
#define item_type_weapon       (3)
#define item_type_ammo         (4)
#define item_type_misc_item    (5)
#define item_type_key_item     (6)


/*   Item data_members   */
#define it_pid              (0)
#define it_name             (1)
#define it_description      (2)
#define it_fid              (3)
#define it_light_distance   (4)
#define it_light_intensity  (5)
#define it_flags            (6)
#define it_flags_ext        (7)
#define it_sid              (8)
#define it_type             (9)
#define it_data            (10)
#define it_material        (11)
#define it_size            (12)
#define it_weight          (13)
#define it_cost            (14)
#define it_inv_fid         (15)
#define it_weapon_range   (555)

/*   Critter data_members   */
#define cr_pid              (0)
#define cr_name             (1)
#define cr_description      (2)
#define cr_fid              (3)
#define cr_light_distance   (4)
#define cr_light_intensity  (5)
#define cr_flags            (6)
#define cr_flags_ext        (7)
#define cr_sid              (8)
#define cr_data             (9)
#define cr_head_fid        (10)
#define cr_body_type       (11)

// cr_body_type values:
#define CR_BODY_BIPED      0
#define CR_BODY_QUADRUPED  1
#define CR_BODY_ROBOTIC    2


/*   Scenery data_members   */
#define sc_pid              (0)
#define sc_name             (1)
#define sc_description      (2)
#define sc_fid              (3)
#define sc_light_distance   (4)
#define sc_light_intensity  (5)
#define sc_flags            (6)
#define sc_flags_ext        (7)
#define sc_sid              (8)
#define sc_type             (9)
#define sc_data            (10)
#define sc_material        (11)

/*   Wall data_members   */
#define wa_pid              (0)
#define wa_name             (1)
#define wa_description      (2)
#define wa_fid              (3)
#define wa_light_distance   (4)
#define wa_light_intensity  (5)
#define wa_flags            (6)
#define wa_flags_ext        (7)
#define wa_sid              (8)
#define wa_material         (9)

/*   Tile data_members   */
  // NONE

/*   Misc data_members   */
#define mi_pid              (0)
#define mi_name             (1)
#define mi_description      (2)
#define mi_fid              (3)
#define mi_light_distance   (4)
#define mi_light_intensity  (5)
#define mi_flags            (6)
#define mi_flags_ext        (7)


// ----------------------------------------------------------------------- //
// ----------------------------------------------------------------------- //

/* Combat Flags */
#define DAM_KNOCKED_OUT        1
#define DAM_KNOCKED_DOWN       2
#define DAM_CRIP_LEG_LEFT      4
#define DAM_CRIP_LEG_RIGHT     8
#define DAM_CRIP_ARM_LEFT     16
#define DAM_CRIP_ARM_RIGHT    32
#define DAM_BLIND             64
#define DAM_DEAD             128
#define DAM_HIT              256
#define DAM_CRITICAL         512  // could be a critical hit or critical miss
#define DAM_ON_FIRE         1024
#define DAM_BYPASS          2048
#define DAM_EXPLODE         4096
#define DAM_DESTROY         8192
#define DAM_DROP           16384
#define DAM_LOSE_TURN      32768
#define DAM_HIT_SELF       65536
#define DAM_LOSE_AMMO     131072
#define DAM_DUD           262144
#define DAM_HURT_SELF     524288
#define DAM_RANDOM_HIT   1048576
#define DAM_CRIP_RANDOM  2097152
#define DAM_BACKWASH     4194304

// Fallout 2:
#define DAM_PERFORM_REVERSE  8388608
#define critter_uninjure(WHO, FLAGS)  critter_injure(WHO, (FLAGS BWOR DAM_PERFORM_REVERSE))

#define DMG_normal_dam   0
#define DMG_laser        1
#define DMG_fire         2
#define DMG_plasma       3
#define DMG_electrical   4
#define DMG_emp          5
#define DMG_explosion    6
// These are BWOR'd into the above damage type
#define DMG_BYPASS_ARMOR  (256)
#define DMG_NOANIMATE     (512)

//#define critter_damage(WHO,AMT)  critter_dmg(WHO,AMT,(DMG_normal_dam BWOR DMG_NOANIMATE))
#define critter_damage(WHO,AMT)  critter_dmg(WHO,AMT,DMG_normal_dam)

/* Kill Critter Equates */
#define KILL_DONT_LEAVE_BODY  (0)
#define KILL_LEAVE_BODY       (1)
#define KILL_LEAVE_NV_BODY    (2)

/* Script MetaRules */
#define METARULE_SIGNAL_END_GAME  13
#define signal_end_game   metarule(METARULE_SIGNAL_END_GAME, 0)
#define METARULE_ELEVATOR         15
#define elevator(X)       metarule(METARULE_ELEVATOR, X)
#define ELEV_BOS1    (0)  // Brotherhood of Steel main elevator; EL_BOS 1-2-3-4
#define ELEV_BOS2    (1)  // Brotherhood of Steel surface elevator; EL_BOS2 G-1
#define ELEV_MASTR1  (2)  // Master's upper-level elevator; EL_MAST1 1-2-3
#define ELEV_MASTR2  (3)  // Master's lower-level elevator; EL_MAST2 3-4
#define ELEV_MILB1   (4)  // Military Base upper-level elevator; EL_MIL1 1-2-3
#define ELEV_MILB2   (5)  // Military Base lower-level elevator; EL_MIL2 3-4
#define ELEV_GLOW1   (6)  // Glow Elevator upper; EL_MIL1 1-2-3
#define ELEV_GLOW2   (7)  // Glow elevator lower; ELMIL3 3-4-6
#define ELEV_VAULT   (8)  // Vault13 elevator; EL_VAULT 1-2-3
#define ELEV_NECVLT  (9)  // Necropolis elevator; EL_VAULT 1-2-3
#define ELEV_SIERRA1 (10) // Sierra Elev 1 (1-2-3)
#define ELEV_SIERRA2 (11) // Sierra Elev 2 (3-4)
#define ELEV_SIERRAS (12) // Sierra Service Elev (1-2-3-4)

#define METARULE_PARTY_COUNT      16
#define party_member_count(X)    metarule(METARULE_PARTY_COUNT, X)
#define DONT_LIST_HIDDEN_MEMBERS (0)
#define LIST_HIDDEN_MEMBERS      (1)
#define METARULE_AREA_KNOWN    17
#define town_known(X)            metarule(METARULE_AREA_KNOWN, X)
#define METARULE_WHO_ON_DRUGS  18
#define drug_influence(WHO)      metarule(METARULE_WHO_ON_DRUGS, WHO)
#define METARULE_MAP_KNOWN     19
#define map_is_known(X)          metarule(METARULE_MAP_KNOWN, X)
//#define DEFINE_METARULE_IS_LOADGAME  22
#define METARULE_CAR_CURRENT_TOWN  30
#define METARULE_GIVE_CAR_TO_PARTY 31
#define METARULE_GIVE_CAR_GAS      32
#define car_current_town         metarule(METARULE_CAR_CURRENT_TOWN, 0)
#define car_give_to_party        metarule(METARULE_GIVE_CAR_TO_PARTY, 0)
#define car_give_gas(AMOUNT)     metarule(METARULE_GIVE_CAR_GAS, AMOUNT)
#define METARULE_SKILL_CHECK_TAG   40
#define is_skill_tagged(SKILL)   metarule(METARULE_SKILL_CHECK_TAG, SKILL)
#define METARULE_DROP_ALL_INVEN    42
#define obj_drop_everything(WHO) metarule(METARULE_DROP_ALL_INVEN, WHO)
#define METARULE_INVEN_UNWIELD_WHO 43
#define inven_unwield(WHO)       metarule(METARULE_INVEN_UNWIELD_WHO, WHO)
#define METARULE_GET_WORLDMAP_XPOS 44
#define worldmap_xpos            metarule(METARULE_GET_WORLDMAP_XPOS, 0)
#define METARULE_GET_WORLDMAP_YPOS 45
#define worldmap_ypos            metarule(METARULE_GET_WORLDMAP_YPOS, 0)
#define METARULE_CURRENT_TOWN      46
#define cur_town                 metarule(METARULE_CURRENT_TOWN, 0)
#define METARULE_LANGUAGE_FILTER   47
#define language_filter_is_on    metarule(METARULE_LANGUAGE_FILTER, 0)
#define METARULE_VIOLENCE_FILTER   48
#define violence_filter_setting  metarule(METARULE_VIOLENCE_FILTER, 0)
#define VLNCLVL_NONE    0  //  Violence Level settings.
#define VLNCLVL_MIN     1
#define VLNCLVL_NORMAL  2
#define VLNCLVL_MAX     3
#define METARULE_W_DAMAGE_TYPE     49
#define weapon_dmg_type(WEAP)    metarule(METARULE_W_DAMAGE_TYPE, WEAP)
#define METARULE_CRITTER_BARTERS   50
#define critter_can_barter(WHO) metarule(METARULE_CRITTER_BARTERS, WHO)
#define METARULE_CRITTER_KILL_TYPE 51
#define critter_kill_type(WHO)  metarule(METARULE_CRITTER_KILL_TYPE, WHO)
#define KILL_TYPE_men_kills            0
#define KILL_TYPE_women_kills          1
#define KILL_TYPE_children_kills       2
#define KILL_TYPE_super_mutant_kills   3
#define KILL_TYPE_ghoul_kills          4
#define KILL_TYPE_brahmin_kills        5
#define KILL_TYPE_radscorpion_kills    6
#define KILL_TYPE_rat_kills            7
#define KILL_TYPE_floater_kills        8
#define KILL_TYPE_centaur_kills        9
#define KILL_TYPE_robot_kills         10
#define KILL_TYPE_dog_kills           11
#define KILL_TYPE_manti_kills         12
#define KILL_TYPE_deathclaw_kills     13
#define KILL_TYPE_plant_kills         14
#define KILL_TYPE_gecko_kills         15
#define KILL_TYPE_alien_kills         16
#define KILL_TYPE_giant_ant_kills     17
#define DEFINE_METARULE_SET_CAR_CARRY_AMOUNT 52
#define set_car_carry_amount(VALUE)   metarule(DEFINE_METARULE_SET_CAR_CARRY_AMOUNT, VALUE)
#define DEFINE_METARULE_GET_CAR_CARRY_AMOUNT 53
#define car_carry_amount   metarule(DEFINE_METARULE_GET_CAR_CARRY_AMOUNT, 0)
// Script MetaRule3's
#define METARULE3_CLR_FIXED_TIMED_EVENTS  100
#define rm_fixed_timer_event(WHO,FIXED_VAL) metarule3(METARULE3_CLR_FIXED_TIMED_EVENTS,WHO,FIXED_VAL,0)
#define METARULE3_MARK_SUBTILE            101
#define mark_world_subtile_visited(XPOS,YPOS,RADIUS) metarule3(METARULE3_MARK_SUBTILE,XPOS,YPOS,RADIUS)
///#define METARULE3_SET_WM_MUSIC            102
///#define set_worldmap_music(MAPIDX,MUSICNAME)  metarule3(METARULE3_SET_WM_MUSIC,MAPIDX,MUSICNAME,0)
#define METARULE3_GET_KILL_COUNT    103
#define player_kill_count(TYPE)    metarule3(METARULE3_GET_KILL_COUNT,TYPE,0,0)
// Off/On states for mark_map_entrance_state
#define OFFSTATE 0
#define ONSTATE  1
#define METARULE3_MARK_MAP_ENTRANCE 104
#define mark_map_entrance_state(MAPIDX,STATE)  metarule3(METARULE3_MARK_MAP_ENTRANCE,MAPIDX,STATE,-1)
#define mark_map_entrance_elev_state(MAPIDX,ELEV,STATE)  metarule3(METARULE3_MARK_MAP_ENTRANCE,MAPIDX,STATE,ELEV)
// wmSubTileVisitInfo Types:
#define UNKNOWNTILETYPE 0
#define KNOWNTILETYPE   1
#define VISITEDTILETYPE 2
#define METARULE3_WM_SUBTILE_STATE  105
#define wm_get_subtile_state(XPOS,YPOS)        metarule3(METARULE3_WM_SUBTILE_STATE,XPOS,YPOS,0)

// Begin <objptr> tile_get_next_critter(tile, elevation, lastCritter)
//CMH
//Note these defines are really messey.
#define METARULE3_TILE_GET_NEXT_CRITTER     (106)
#define tile_get_next_critter(tile, elevation, lastCritter) metarule3(METARULE3_TILE_GET_NEXT_CRITTER, tile, elevation, lastCritter)
//CMH
// End

#define METARULE3_ART_SET_BASE_FID_NUM      (107)
#define art_change_fid_num(WHO, NUM)           metarule3(METARULE3_ART_SET_BASE_FID_NUM,WHO,NUM,0)

#define METARULE3_TILE_SET_CENTER           (108)
#define tile_set_center(tileNum)             metarule3(METARULE3_TILE_SET_CENTER,tileNum,0,0)

#define METARULE3_CHEM_USE_LEVEL            (109)
#define chem_use_level(WHO)                  metarule3(METARULE3_CHEM_USE_LEVEL,WHO,0,0)

#define METARULE3_CAR_OUT_OF_FUEL           (110)
#define car_out_of_fuel                      metarule3(METARULE3_CAR_OUT_OF_FUEL,0,0,0)

#define METARULE3_MAP_GET_LOAD_AREA         (111)
#define map_get_load_area                    metarule3(METARULE3_MAP_GET_LOAD_AREA,0,0,0)

// Used with mark_area_known
#define MARK_TYPE_TOWN  (0)
#define MARK_TYPE_MAP   (1)
// wmAreaVisitStateInfo;
#define MARK_STATE_UNKNOWN (0)
#define MARK_STATE_KNOWN   (1)
#define MARK_STATE_VISITED (2)
#define MARK_STATE_INVISIBLE (-66)


// Inven Cmd defines //
#define INVEN_CMD_INDEX_PTR  (13)
#define inven_ptr(WHO,WHERE)     inven_cmds(WHO,INVEN_CMD_INDEX_PTR,WHERE)

/* GSound Values */
// gsound_character_types
#define snd_human    (0)
#define snd_monster  (1)

// gsound_character_extra
#define snd_unused     (0)
#define snd_knock_down (1)
#define snd_pass_out   (2)
#define snd_die        (3)
#define snd_contact    (4)

// gsound_sfx_action
#define snd_active     (0)
#define snd_passive    (1)

// gsound_sfx_weapon_action_type
#define snd_weapon_ready        (0)
#define snd_weapon_attack       (1)
#define snd_weapon_out          (2)
#define snd_weapon_ammo_flying  (3)
#define snd_weapon_hitting      (4)

// gsound_sfx_scenery_action
#define snd_open      (0)
#define snd_close     (1)
#define snd_locked    (2)
#define snd_unlocked  (3)
#define snd_used      (4)

// hit_mode
#define hit_left_weapon_primary    (0)
#define hit_left_weapon_secondary  (1)
#define hit_right_weapon_primary   (2)
#define hit_right_weapon_secondary (3)
#define hit_punch                  (4)
#define hit_kick                   (5)
#define hit_left_weapon_reload     (6)
#define hit_right_weapon_reload    (7)

/* Extra */

#define fadeout(X) gfade_out(X)
#define fadein(X)  gfade_in(X)
#define fdout gfade_out(1) //time param is not used anyway
#define fdin  gfade_in(1)

/* Time Information  (in Ticks) */

#define ONE_GAME_SECOND             (10)
#define ONE_GAME_MINUTE             (60*ONE_GAME_SECOND)
#define ONE_GAME_HOUR               (60*ONE_GAME_MINUTE)
#define ONE_GAME_DAY                (24*ONE_GAME_HOUR)
#define ONE_GAME_WEEK               (7*ONE_GAME_DAY)
#define ONE_GAME_MONTH              (30*ONE_GAME_DAY)

/* bits */
#define bit_1                       (1)
#define bit_2                       (2)
#define bit_3                       (4)
#define bit_4                       (8)
#define bit_5                       (0x10)
#define bit_6                       (0x20)
#define bit_7                       (0x40)
#define bit_8                       (0x80)
#define bit_9                       (0x100)
#define bit_10                      (0x200)
#define bit_11                      (0x400)
#define bit_12                      (0x800)
#define bit_13                      (0x1000)
#define bit_14                      (0x2000)
#define bit_15                      (0x4000)
#define bit_16                      (0x8000)
#define bit_17                      (0x10000)
#define bit_18                      (0x20000)
#define bit_19                      (0x40000)
#define bit_20                      (0x80000)
#define bit_21                      (0x100000)
#define bit_22                      (0x200000)
#define bit_23                      (0x400000)
#define bit_24                      (0x800000)
#define bit_25                      (0x1000000)
#define bit_26                      (0x2000000)
#define bit_27                      (0x4000000)
#define bit_28                      (0x8000000)
#define bit_29                      (0x10000000)
#define bit_30                      (0x20000000)
#define bit_31                      (0x40000000)
#define bit_32                      (0x80000000)
#define bit_ALL                     (0xFFFFFFFF)

/* macros for pickup_p_proc responses. */
#define REACTION_TG   1
#define REACTION_G    2
#define REACTION_TC   3
#define REACTION_C    4

#define R_CALL_THROUGH     1
#define R_NOCALL_THROUGH  -1

#ifndef PICKUP_THRESH
#define PICKUP_THRESH      1
#endif

#ifndef CALL_PICKUP
#define CALL_PICKUP        R_NOCALL_THROUGH
#endif

#ifndef NPC_REACTION_VAR
#define NPC_REACTION_VAR          (-1)
#endif

#ifdef  NPC_REACTION_TYPE


    // Tough Guard Architype   == 1
    // Guard Architype         == 2
    // Tough Citizen Architype == 3
    // Citizen Architype       == 4
#define caught_pickpocket       if (NPC_REACTION_TYPE == REACTION_TG) then begin          \
                                    attack(source_obj);                                   \
                                end                                                       \
                                else if (NPC_REACTION_TYPE == REACTION_G) then begin      \
                                    float_msg(self_obj, message_str(SCRIPT_GENERIC,random(3325,3329)), FLOAT_MSG_NORMAL);     \
                                    if (NPC_REACTION_VAR > -1) then begin                 \
                                        if (local_var(NPC_REACTION_VAR) >= PICKUP_THRESH) then begin  \
                                            attack(source_obj);                           \
                                        end                                               \
                                        set_local_var(NPC_REACTION_VAR,local_var(NPC_REACTION_VAR)+1);                  \
                                    end                                                   \
                                end                                                       \
                                else if (NPC_REACTION_TYPE == REACTION_TC) then begin     \
                                    float_msg(self_obj, message_str(SCRIPT_GENERIC,random(3050,3064)), FLOAT_MSG_NORMAL);     \
                                    if (NPC_REACTION_VAR > -1) then begin                 \
                                        if (local_var(NPC_REACTION_VAR) >= PICKUP_THRESH) then begin  \
                                            attack(source_obj);                           \
                                        end                                               \
                                        set_local_var(NPC_REACTION_VAR,local_var(NPC_REACTION_VAR)+1);                  \
                                    end                                                   \
                                end                                                       \
                                else if (NPC_REACTION_TYPE == REACTION_C) then begin      \
                                    animate_run_to_tile(tile_num_in_direction(tile_num(self_obj), rotation_to_tile(tile_num(source_obj),tile_num(self_obj)), random(8,14)));  \
                                end
// global pickups
procedure old_pickup_p_proc;
procedure pickup_p_proc begin
   if (source_obj == dude_obj) then begin
      caught_pickpocket
   end
   if (CALL_PICKUP == R_CALL_THROUGH) then begin
      call old_pickup_p_proc;
   end
end
#define pickup_p_proc           old_pickup_p_proc

#endif


//Misc commands
#define obj_get_rot(obj)  (has_trait(TRAIT_OBJECT, obj, OBJECT_CUR_ROT))

//late includes go here
#include "upu.h"
#include "rpu.h"
#include "party2.h"

#endif // DEFINE_H
