/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef EXPPOINT_H
#define EXPPOINT_H

/************************************************************
   defines for the Experience Point awards in the game
   all defines for experience points need to be in the
   form of:
      EXP_seed
   If there are any modifies (such as using a skill), please
   add that to the name so that rewards and be adjusted
   accordingly by the designers
************************************************************/


/*-----------------9/16/97 7:45:M-------------------
 General Format for this file is:

 I. Experience for Skill Usage
    A. Lockpick
    B. Stealing
    C. Traps
    D. Gambling
    E. Speech
    F. Science
    G. Repair

 II. Experience Points for solving seeds

 III. Giving Experience Points
    A. Display Message string


 10/27/98 Added Karma awards -NBK

--------------------------------------------------*/


/*-----------------9/16/97 7:47:M-------------------
 Experience Points for Skill Usage
--------------------------------------------------*/

/****************************************
 Lockpick Experience Points
****************************************/
#define EXP_LOCKPICK_NORMAL                       (25)
#define EXP_LOCKPICK_NEG_10                       (35)
#define EXP_LOCKPICK_NEG_20                       (45)
#define EXP_LOCKPICK_NEG_30                       (55)
#define EXP_LOCKPICK_NEG_40                       (65)
#define EXP_LOCKPICK_NEG_50                       (75)
#define EXP_LOCKPICK_NEG_60                       (85)
#define EXP_LOCKPICK_NEG_70                       (95)
#define EXP_LOCKPICK_NEG_80                      (105)
#define EXP_LOCKPICK_NEG_90                      (115)

/****************************************
 Stealing Experience Points
****************************************/
#define EXP_STEALING_NORMAL                       (25)
#define EXP_STEALING_NEG_10                       (35)
#define EXP_STEALING_NEG_20                       (45)
#define EXP_STEALING_NEG_30                       (55)
#define EXP_STEALING_NEG_40                       (65)
#define EXP_STEALING_NEG_50                       (75)
#define EXP_STEALING_NEG_60                       (85)
#define EXP_STEALING_NEG_70                       (95)
#define EXP_STEALING_NEG_80                      (105)
#define EXP_STEALING_NEG_90                      (115)

/****************************************
 Traps Experience Points
****************************************/
#define EXP_TRAPS_NORMAL                          (25)
#define EXP_TRAPS_NEG_10                          (35)
#define EXP_TRAPS_NEG_20                          (45)
#define EXP_TRAPS_NEG_30                          (55)
#define EXP_TRAPS_NEG_40                          (65)
#define EXP_TRAPS_NEG_50                          (75)
#define EXP_TRAPS_NEG_60                          (85)
#define EXP_TRAPS_NEG_70                          (95)
#define EXP_TRAPS_NEG_80                         (105)
#define EXP_TRAPS_NEG_90                         (115)

/****************************************
 Gambling Experience Points
****************************************/
#define EXP_GAMBLING_NORMAL                       (25)
#define EXP_GAMBLING_NEG_10                       (35)
#define EXP_GAMBLING_NEG_20                       (45)
#define EXP_GAMBLING_NEG_30                       (55)
#define EXP_GAMBLING_NEG_40                       (65)
#define EXP_GAMBLING_NEG_50                       (75)
#define EXP_GAMBLING_NEG_60                       (85)
#define EXP_GAMBLING_NEG_70                       (95)
#define EXP_GAMBLING_NEG_80                      (105)
#define EXP_GAMBLING_NEG_90                      (115)

/****************************************
 Speach Experience Points
****************************************/
#define EXP_SPEECH_NORMAL                         (25)
#define EXP_SPEECH_NEG_10                         (35)
#define EXP_SPEECH_NEG_20                         (45)
#define EXP_SPEECH_NEG_30                         (55)
#define EXP_SPEECH_NEG_40                         (65)
#define EXP_SPEECH_NEG_50                         (75)
#define EXP_SPEECH_NEG_60                         (85)
#define EXP_SPEECH_NEG_70                         (95)
#define EXP_SPEECH_NEG_80                        (105)
#define EXP_SPEECH_NEG_90                        (115)

/****************************************
 Science Experience Points
****************************************/
#define EXP_SCIENCE_NORMAL                        (35)
#define EXP_SCIENCE_NEG_10                        (45)
#define EXP_SCIENCE_NEG_20                        (55)
#define EXP_SCIENCE_NEG_30                        (65)
#define EXP_SCIENCE_NEG_40                        (75)
#define EXP_SCIENCE_NEG_50                        (85)
#define EXP_SCIENCE_NEG_60                        (95)
#define EXP_SCIENCE_NEG_70                       (105)
#define EXP_SCIENCE_NEG_80                       (115)
#define EXP_SCIENCE_NEG_90                       (125)

/****************************************
 Repair Experience Points
****************************************/
#define EXP_REPAIR_NORMAL                         (35)
#define EXP_REPAIR_NEG_10                         (45)
#define EXP_REPAIR_NEG_20                         (55)
#define EXP_REPAIR_NEG_30                         (65)
#define EXP_REPAIR_NEG_40                         (75)
#define EXP_REPAIR_NEG_50                         (85)
#define EXP_REPAIR_NEG_60                         (95)
#define EXP_REPAIR_NEG_70                        (105)
#define EXP_REPAIR_NEG_80                        (115)
#define EXP_REPAIR_NEG_90                        (125)


/*-----------------9/16/97 7:47:M-------------------
     Experience Points for Solving Seeds
--------------------------------------------------*/

// Arroyo Related experience points
#define EXP_KILL_EVIL_PLANTS                     (100)
#define EXP_FIX_WELL                             (100)
#define EXP_RETURN_SMOKE                         (100)
#define EXP_ARROYO_TEMPLE                        (300)
#define EXP_ARROYO_TEMPLE_TALK                   (300)
#define EXP_ARROYO_TEMPLE_SNEAK                  (300)
#define EXP_TALK_FLINT                            (50)

// Den related experience points
#define EXP_READ_ANNA_DIARY                      (100) // unused
#define EXP_BURY_ANNA_BONES                      (600)
#define EXP_VIC_TRADER_LEARNED                   (200)
#define EXP_SMITTY_MEAL_GIVEN                    (150)
#define EXP_FREE_SLAVES                         (1250)
#define EXP_CRATE_EXP                            (500)
#define EXP_GANG_BATTLE_OVER                    (1000)
#define EXP_FIND_STILL_FOR_FRANKIE               (400)
#define EXP_DESTROY_STILL_FOR_FRANKIE            (700)
#define EXP_CONVINCE_FRANKIE_TRADE               (900)
#define EXP_BREAK_SLAVE_RUN_CHERRY               (500)
#define EXP_REBECCA_COLLECT                      (200)
#define EXP_REBECCA_BOOK                         (300)
#define EXP_ANNA_LOCKET                          (250)
#define EXP_LEANNE_TOLD_STORY                    (350)
#define EXP_STACY_TOLD_STORY                     (200)
#define EXP_KILL_METZGER                        (1500)
#define EXP_GANG_BATTLE_BETRAY_LARA             (1100)
#define EXP_TALK_INTO_CRATES_SLAVER              (300)
#define EXP_TALK_INTO_CRATES_METZGER_KNOWN       (500)
#define EXP_TALK_INTO_CRATES_THREATEN            (700)
#define EXP_FIND_GANG_WEAKNESS                   (200)
#define EXP_PERMISSION_FROM_METZGER              (200)

// Klamath related experience points
#define EXP_KC_STILL_SUCCESS                     (100)
#define EXP_KC_SAVE_SMILEY                      (1000)
#define EXP_KC_GUARD_SUCCESS                     (250)
#define EXP_KC_RUSTLE_BRAHMIN                    (150)
#define EXP_KC_KILL_RAT_GOD                      (300)
#define EXP_KC_RESCUE_TORR                       (200)
#define EXP_KC_FIND_CAR_PART                     (200)
#define EXP_KC_FREE_SULIK                        (500)
#define EXP_KC_BETRAY_STILL                      (100)

// Gecko related experience points
#define EXP_REPAIR_REACTOR                      (4000)
#define EXP_ROBOT_REPAIR_BONUS                   (500)
#define EXP_FESTUS_REPAIR_BONUS                  (250)
#define EXP_DESTROY_REACTOR                     (2500)
#define EXP_CLEVER_DESTROY_BONUS                 (550)
#define EXP_OPTIMIZE_REACTOR                    (2500)
#define EXP_ECON_DISK_GIVEN                      (750)
#define EXP_SKEETER_PART_RECIEVED                (350)
#define EXP_SKEETER_REPAIR_KIT_GIVEN             (250)
#define EXP_ANKH_GIVEN                           (350)
#define EXP_ANKH_TAKEN                           (100)
#define EXP_ZOMAK_OPEN                            (50)
#define EXP_FOUND_WOODY                         (1000)

// Navarro related experience points
#define EXP_XARN_FREED                          (1500)
#define EXP_XARN_JOIN                           (1500)
#define EXP_XARN_KILL                            (500)
#define EXP_SCHREBER_KILL                       (1000)
#define EXP_GET_CHRIS_INFO                      (1500)
#define EXP_STOP_CHRIS_RADIO                     (500)
#define EXP_K9_FIXED                            (3500)
#define EXP_RETRIEVE_FOB                        (3500)
#define EXP_RETRIEVE_PLANS                      (3500)

// Broken Hills related experience points
#define EXP_MIGHTY_SUCCESS                       (350)
#define EXP_PREACHED_TO_MANSON                   (300)
#define EXP_JAILBREAK_SUCCESS                   (1500)
#define EXP_PURIFIER_FIXED                      (1500)
#define EXP_PURIFIER_DESTROYED                  (1500)
#define EXP_CONSPIRACY_EXPOSED                  (2500)
#define EXP_BODIES_FOUND                         (500)
#define EXP_WIFE_FOUND                           (750)
#define EXP_CONFRONTED_FRANCIS                  (1000)
#define EXP_TOLD_DAN_ABOUT_WIFE                  (500)
#define EXP_FOUND_SECRET_MINE_AREA              (1000)
#define EXP_REFINED_ORE                          (500)
#define EXP_RETURNED_ORE_TO_CITY                (1250)
#define EXP_RETURNED_ORE_TO_CITY_FOR_CASH        (300)
#define EXP_SHOVELED_ALL_CRAP                    (500)
#define EXP_GAVE_ERIC_POWER                     (1000)
#define EXP_OPTIMIZED_POWER_GRID                (1500)
#define EXP_MARCUS_IN_PARTY                     (1000)
#define EXP_FOUND_LIZ_WEAPONS                    (750)
#define EXP_CHAD_EXPOSED                        (2000)
#define EXP_BUCK_ROGERS                          (500)
#define EXP_AGILITY_TEST_HIGH_INT                (500)
#define EXP_AGILITY_TEST_LOW_INT                 (500)
#define EXP_PERCEPTION_TEST_HIGH_INT             (500)
#define EXP_PERCEPTION_TEST_LOW_INT              (500)
#define EXP_INTELLIGENCE_TEST_HIGH_INT           (500)
#define EXP_INTELLIGENCE_TEST_LOW_INT            (500)
#define EXP_SULLIVAN_TAUGHT_MOVES                (150)
#define EXP_TYPHON_TOLD_TREASURE                (2000)
#define EXP_REPLANTED_SEYMOUR                   (1000)
#define EXP_FTM_EXPOSED                          (500)

// Modoc XP
#define EXP_SAVE_JONNY                          (2500)
#define EXP_SOLVE_FAMILY_FEUD_BEST              (1500)
#define EXP_SOLVE_FAMILY_FEUD_WORST              (500)
#define EXP_FINISH_BRAHMIN_SEED                  (250)
#define EXP_SOLVE_GHOST_FARM_BEST               (3500)
#define EXP_SOLVE_GHOST_FARM_REGULAR            (2000)
#define EXP_SOLVE_GHOST_FARM_BAD                 (700)
#define EXP_SOLVE_GHOST_FARM_WORST               (500)
#define EXP_MODOC_CLEAR_COUP_ROCKS               (100)
#define EXP_MODOC_KILL_ALL_RATS                  (300)
#define EXP_BLOW_UP_ROCKS                        (500)
#define EXP_HEAL_BESS                            (200)
#define EXP_SENT_KARL_HOME                       (500)

// Vault City XP
#define EXP_PASSED_VAULT_TEST                   (1000)
#define EXP_FOUND_REDDING_ADDICTED_TO_JET        (600)
#define EXP_FREED_TRADE_WITH_REDDING            (2500)
#define EXP_JET_SOURCE_HINTED_AT                 (500)
#define EXP_JET_SOURCE_DISCOVERED                (750)
#define EXP_JET_ANTIDOTE_INFO                   (2000)
#define EXP_SEARCH_MED_DATABASE                  (500)
#define EXP_ALOCATION_COMPUTER                 (20000)
#define EXP_FIXED_VENT                           (100)
#define EXP_FINISHED_RAIDERS                    (1000)
#define EXP_RENO_RAIDER_CONNECTION              (1000)
#define EXP_NCR_RAIDER_CONNECTION               (2500)
#define EXP_EXILED_MOORE                         (500)
#define EXP_DIAGNOSED_CHARLIE                    (100)
#define EXP_CURED_CHARLIE                        (100)
#define EXP_AUTODOC_REPAIRED                     (100)
#define EXP_BOOTLEG_DELIVERED                    (250)
#define EXP_ED_REMEMBERED                        (500)
#define EXP_GAVE_TOOLS_TO_VAL                    (250)
#define EXP_RECONCILED_VIC_AND_VAL               (250)
#define EXP_CURTIS_REWARD                        (100)
#define EXP_TOLD_MCCLURE_ADDICTION               (250)
#define EXP_GAVE_LYNETTE_HOLODISK               (1500)
#define EXP_GAVE_LYNETTE_HOLODISK_CAPTAIN       (2500)
#define EXP_SPERM_DONOR_SMART                    (500)
#define EXP_SPERM_DONOR_NORMAL                   (250)
#define EXP_SPERM_DONOR_STUPID                    (50)
#define EXP_PHYLLIS_STERILITY_CHECK              (300)
#define EXP_PHYLLIS_GO_OUTSIDE                   (300)
#define EXP_PHYLLIS_DATE                         (100)
#define EXP_VAULT_PULLED_RANK                    (500)
#define EXP_VAULT_GECKO_RECON                    (350)
#define EXP_VAULT_NCR_RECON                      (750)
#define EXP_CASSIDY_IN_PARTY                     (300)
#define EXP_BARKUS_RELEASED_JOSHUA               (500)
#define EXP_PLOW_FOR_SMITHS                      (250)

// Sierra Army Depot
#define EXP_DISABLE_ROBOT                        (200)
#define EXP_DISABLE_FIELDS_LEVEL_1               (200)
#define EXP_DISABLE_FIELDS_LEVEL_2               (320)
#define EXP_DISABLE_FIELDS_LEVEL_3               (440)
#define EXP_DISABLE_FIELDS_LEVEL_4               (560)
#define EXP_HACK_SIERRA_COMPUTER_1B              (250)
#define EXP_HACK_SIERRA_COMP_2A_SECURITY         (500)
#define EXP_HACK_SIERRA_COMP_2A_ALARM            (550)
#define EXP_HACK_SIERRA_COMP_2C_REPAIR           (200)
#define EXP_DISABLE_FORCE_FIELD                   (50)
#define EXP_HACK_SIERRA_COMP_2B_SHOCK            (200)
#define EXP_HACK_SIERRA_COMP_2B_FIELD            (200)
#define EXP_EXTRACT_ORGAN                        (500)

// New Reno
#define EXP_REPAIR_MCGEE_SLOT_MACHINE_BEST       (100)
#define EXP_REPAIR_MCGEE_SLOT_MACHINE_GOOD        (50)
#define EXP_DELIVER_BRIEFCASE                    (500)
#define EXP_GOT_MARJORIE_BADGE                   (500)
#define EXP_ASSASSINATE_SALVATORE               (2000)
#define EXP_NIKKI_LLOYD_SOLVE                    (500)
#define EXP_NIKKI_BRIBED_SOLVE                   (250)
#define EXP_MYSTERY_SOLVED                      (2000)
#define EXP_DISARM_WRIGHT_SAFE                   (100)
#define EXP_ELDRIDGE_LASER                       (500)
#define EXP_ASSASSINATE_SALVATORE_ASSIGNED      (1000)
#define EXP_KILL_SALVATORE_ASSIGNED              (750)
#define EXP_CONVINCE_MYRON_OF_CURE              (2000)
#define EXP_MYRON_JOINS_PARTY                    (750)
#define EXP_NEW_RENO_RECOVER_CAR                 (750)
#define EXP_NEW_RENO_RECOVER_CAR_BISHOP_BONUS    (750)
#define EXP_NEW_RENO_BISHOP_BATTERIES_BONUS      (750)
#define EXP_NEW_RENO_WHORE_FOR_MYRON             (500)
#define EXP_NEW_RENO_MRS_B_SAFE_COMPARTMENT      (250)
#define EXP_NEW_RENO_PRITCHARD_GRAVE             (500)
#define EXP_NEW_RENO_DELIVER_PACKAGE             (500)
#define EXP_NEW_RENO_KITTY_MAGAZINES            (1000)
#define EXP_NEW_RENO_BRAHMIN_ASS                 (250)
#define EXP_NEW_RENO_PORN_STAR                  (1500)
#define EXP_NEW_RENO_MRS_BISHOP_WIN             (1000)
#define EXP_NEW_RENO_RICHARD_POISONED            (500)
#define EXP_NEW_RENO_EMPTY_JET_CANISTER          (500)
#define EXP_NEW_RENO_USE_DERMAL                  (500)
#define EXP_NEW_RENO_USE_MEDICAL                 (500)
#define EXP_NEW_RENO_DESTROY_STILL               (500)
#define EXP_NEW_RENO_EXPOSE_RENESCO             (1000)
#define EXP_NEW_RENO_CODY_LEADS                  (500)
#define EXP_NEW_RENO_BAD_SOLVE_MYSTERY           (500)
#define EXP_NEW_RENO_MADE_MAN_WRIGHT            (1000)
#define EXP_NEW_RENO_COR_BRO_EXTORTION           (500)
#define EXP_NEW_RENO_MORDINO_MADE_MAN           (1000)
#define EXP_NEW_RENO_ASSASSINATE_WESTIN         (2000)
#define EXP_NEW_RENO_WHACK_CARLSON              (2500)
#define EXP_NEW_RENO_BISHOP_MADE_MAN            (1000)
#define EXP_NEW_RENO_LLOYD_SITUATION_DONE        (500)
#define EXP_NEW_RENO_COLLECT_TRIBUTE             (750)
#define EXP_NEW_RENO_MADE_MAN_SALVATORE         (1000)
#define EXP_NEW_RENO_WHACK_SALVATORE             (500)
#define EXP_NEW_RENO_ASSASSINATE_BIG_JESUS      (1000)
#define EXP_NEW_RENO_SECRET_TRANS_GUARD         (1000)
#define EXP_NEW_RENO_BOXER_LEVEL_1               (500)
#define EXP_NEW_RENO_BOXER_LEVEL_2               (750)
#define EXP_NEW_RENO_BOXER_LEVEL_3              (1000)
#define EXP_NEW_RENO_BOXER_LEVEL_4              (2500)
#define EXP_NEW_RENO_MRS_WRIGHT_DESTROY_STILL    (500)
#define EXP_NEW_RENO_WITNESS_TRANSACTION        (1500)

//NCR
#define EXP_BECAME_RANGER                       (3000)
#define EXP_DID_DEATHCLAW_MISSION               (1000)
#define EXP_DELIVER_LYNETTE_HOLO                (2000)
#define EXP_FOUND_SPY                           (4000)
#define EXP_TALK_JACK_OUT                       (6000)
#define EXP_SOLVED_V15                          (5000)
#define EXP_DELIVERED_OZ9_LETTER                 (500)
#define EXP_MIRA_JACK_DEAD                      (2000)
#define EXP_MERK_HUB_DEAD                       (2000)
#define EXP_MERK_GET_PAPERS                     (1000)
#define EXP_DOCHENRY_MUTA_TEST                  (1000)

//Vault 15
#define EXP_SAVED_GIRL_ALIVE                    (2500)
#define EXP_SAVED_GIRL_DEAD                      (500)
#define EXP_FIXED_GENERATOR                     (3000)
#define EXP_KILED_DARION                        (6000)

//Vault 13
#define EXP_FIX_COMPUTER                        (5000)
#define EXP_FOUND_V13                           (2000)
#define EXP_GOT_GECK                            (4000)

// Redding
#define EXP_CURED_FANNIE                        (1000) // Seraph's Code
#define EXP_WHORE_CUT                           (1250)
#define EXP_EXCAVATOR_CHIP                      (2500)
#define EXP_EVICTED_ROONEY                      (1000)
#define EXP_HELPED_ROONEY                       (1500)
#define EXP_DELIVERED_DAN_CHIP                  (2500)
#define EXP_STOP_BAR_BRAWL                      (1500)
#define EXP_REDDING_PROBLEM                     (2500)
#define EXP_SELL_MINE_DEED                      (1000)
#define EXP_CLEAR_WANAMINGO_MINE                (3500)
#define EXP_CLEAR_FROG_MORTON_GANG              (3000)

// Raiders
#define EXP_DISARM_RAIDERS_SAFE                   (50)
#define EXP_CRACKED_SAFE                         (500)
#define EXP_RAIDERS_FOUND                        (500)
#define EXP_RAIDERS_DESTROYED                   (2000)

//Random Encounters
#define EXP_DEAD_ROBE_MAN                        (500)
#define EXP_BROKE_WATER_CHIP                    (1000)

// Enclave
#define EXP_GRANITE_JOINED                      (1500)
#define EXP_POISON_ENCLAVE                      (5000)
#define EXP_DESTROY_REACTOR_COMPUTER           (10000)
#define EXP_DESTROY_REACTOR_TALK               (12500)
#define EXP_FINDING_GECK                        (5000)
#define EXP_PASSING_PUZZLE_ROOM                 (2500)
#define EXP_CUTTING_POWER_CABLE                 (1000)
#define EXP_TURN_OFF_TURRETS                    (1000)
#define EXP_TURN_TURRET_AGAINST_END_BOSS        (2500)

// Military Base
#define EXP_MILITARY_BASE_FIX_GENERATOR         (1500)
#define EXP_MILITARY_BASE_OPEN_ENTERANCE        (5000)

//San Fran
#define EXP_SAVE_GIRL_ALIVE                     (5000)
#define EXP_DRAGON_CHALLENGE_NO_MISSION         (2000)
#define EXP_DRAGON_CHALLENGE_MISSION            (3000)
#define EXP_DRAGON_BEAT_TEST                    (8000)
#define EXP_LOPAN_CHALLENGE_NO_MISSION          (2000)
#define EXP_LOPAN_CHALLENGE_MISSION             (3000)
#define EXP_LOPAN_BEAT_TEST                     (8000)
#define EXP_ELRON_FUEL_ELRON_SHIP               (6000)
#define EXP_ELRON_KILL_BADGER                   (3000)
#define EXP_ELRON_KILL_EMPEROR                  (5000)
#define EXP_ELRON_GET_VERTIBIRD                 (5000)
#define EXP_SHI_HACK_KNOWN                      (3000)
#define EXP_SHI_HACK_UNKNOWN                    (7000)
#define EXP_SHI_KILL_OZ9                        (5000)
#define EXP_SHI_VERTIBIRD                       (5000)
#define EXP_SPLEEN_DEADWONG                     (3000)
#define EXP_SPLEEN_FOUND                        (2000)
#define EXP_SPLEEN_REINSTERTED                  (3000)
#define EXP_TANKER_FOB                          (2000)
#define EXP_TANKER_FUEL_DAVE_EL                 (3000)
#define EXP_TANKER_FUEL_DAVE_SHI                (5000)
#define EXP_TANKER_GO                          (15000)
#define EXP_TANKER_FIX_NAV                      (2000)
#define EXP_BOS_QUEST                          (20000)
#define EXP_ARMOR                               (5000)
#define EXP_SAN_FRAN_GAS                        (5000)

#define EXP_KILL_DR_SHENG_REWARD                (1000)
#define EXP_KILL_DR_SHENG_NO_REWARD             (3000)
#define EXP_DELIVER_SEEDS_TO_DR_SHENG           (1000)
#define EXP_KILL_DR_WONG                        (1000)
#define EXP_DELIVER_SEED_SAMPLE_TO_DR_WONG       (200)

//Tribe
#define EXP_TRIBE_WEAPONS                       (300)
#define EXP_TRIBE_WELL_GOOD                     (400)
#define EXP_TRIBE_WELL_BAD                      (200)
#define EXP_TRIBE_GHOSTPROBLEM                  (500)
#define EXP_FIND_HUNTERS                        (600)
#define EXP_SULIK_SISTER                        (300)
#define EXP_TRIBE_MERCHANT_MEETING_NORMAL       (500)
#define EXP_TRIBE_MERCHANT_MEETING_BAD          (300)
#define EXP_TRIBE_MERCHANT_MEETING_GOOD         (600)

/***************************************************
     Giving Experience Points
***************************************************/

/***************************************
 Give the experience points and display
 a message informing the player how many
 points he received.
***************************************/
#define calc_actual_xp_gain(x)                  (x + ((x * (5 * dude_perk(PERK_swift_learner))) / 100))
#define give_xp(x)                              give_exp_points(x); \
                                                display_msg(g_mstr(100) + calc_actual_xp_gain(x) + g_mstr(101))

#endif // EXPPOINT_H
