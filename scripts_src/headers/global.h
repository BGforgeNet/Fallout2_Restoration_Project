/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef _GLOBAL_H_DEFINED
#define _GLOBAL_H_DEFINED

/******************************************************************
   File Name: Global.h

   Purpose: This file contains defines for all of the global
            variables. This is an ordered list and needs to
            conform exactly to scripts list. All defines in here
            need to be prepended with GVAR_ as a naming
            convention.

   Created: November 11, 1997
******************************************************************/

/******************************************************************
 General format for this file is:

 I. Reputation Information
       A. General Reputation

 II. Town Information/Quest Information
       A. Arroyo
       B. Den
       C. Klamath
       D. Modoc
       E. Vault City
       F. Broken Hills
       G. Sierra Army Depot
       H. Gecko
       I. NCR
       J. Vault 13
       K. Vault 15
       L. San Francisco
       M. New Reno
       N. Military Base
       O. Caravans
       P. Random Encounters
       Q. Endgame Movies

 III. Misc.
       A. Addictions
       B. Karma Titles
       C. Misc.
       D. Town Reputations

 IV. State of Variables

******************************************************************/

// Reputation Information

#define GVAR_PLAYER_REPUTATION               (0)
#define GVAR_CHILDKILLER_REPUTATION          (1)
#define GVAR_CHAMPION_REPUTATION             (2)
#define GVAR_BERSERKER_REPUTATION            (3)
#define GVAR_BAD_MONSTER                     (4)
#define GVAR_GOOD_MONSTER                    (5)
#define GVAR_PLAYER_MARRIED                  (6)
#define GVAR_PLAYER_SEX_LEVEL                (194)
#define GVAR_PARTY_CHILDKILLER               (289)
#define GVAR_SEX_COUNTER                     (358)
#define GVAR_PLAYER_WAS_MARRIED              (449)

#define GVAR_MYSTERIOUS_STRANGER             (352)
#define GVAR_MYSTERIOUS_STRANGER_LEVEL       (353)

#define GVAR_IMPLANTS_KNOWN                  (384)

#define GVAR_SEXPERT                         (588)
#define GVAR_GIGALO                          (589)
#define GVAR_DUDE_VIRGIN                     (590)

// Arroyo Information

#define GVAR_KNOWLEDGE_HEALING_POWDER        (8)
#define GVAR_KILL_EVIL_PLANTS                (9)
#define GVAR_START_ARROYO_TRIAL              (10)
#define GVAR_ARROYO_SPEAR                    (183)
#define GVAR_ARROYO_DOG                      (191)
#define GVAR_DUMAR_STATUS                    (369)
#define GVAR_ARROYO_RETURN_GECK              (480)
#define GVAR_TALKED_TO_ELDER                 (531)
#define GVAR_FIND_VIC                        (619)

// The Den Information
#define GVAR_DEN_FLAG_1                      (445)
#define GVAR_DEN_FLAG_2                      (446)
#define GVAR_DEN_FLAG_3                      (447)

#define GVAR_REPUTATION_SLAVER               (11)
#define GVAR_REPUTATION_SLAVE_OWNER          (12)
#define GVAR_DEN_MOM_STATUS                  (13)
#define GVAR_EXILE_DEN                       (15)
#define GVAR_DEN_ANNA_STATUS                 (16)
#define GVAR_DEN_WAREHOUSE_ACCESS            (17)
#define GVAR_PLAYER_GOT_CAR                  (18)
#define GVAR_DEN_VIC_STATUS                  (19)
#define GVAR_DEN_MAGGIE_STILL                (20)
#define GVAR_CAME_FROM_BROKEN2               (29) //unused, now used for Lumpy in Broken Hills - killap
#define GVAR_SLAVE_RUN                       (30)
#define GVAR_SLAVES_COUNT                    (31)
#define GVAR_HOSTILE_SLAVE_COUNT             (125)
#define GVAR_MAGGIE_STATUS                   (32)
#define GVAR_SLAVES_LOST                     (33)
#define GVAR_SLAVERS_LOST                    (34)
#define GVAR_PIP_BOY_ANNA_DIARY              (35)
#define GVAR_FRANKIE_STATUS                  (36)
#define GVAR_DEN_SLAVER_WARNINGS             (287)
#define GVAR_DEN_SMITTY_PART                 (162)
#define GVAR_SLAVE_RUN_KILLED                (187)
#define GVAR_QUEST_MAGGIE_STILL              (101)
#define GVAR_DEN_CEASAR_STATUS               (298)
#define GVAR_DEN_BECKY_JOB                   (371) //Aka Rebecca
#define GVAR_DEN_FRED_STATUS                 (374)
#define GVAR_DEN_DEREK_STATUS                (375)
#define GVAR_DEN_ROBBY_STATUS                (376)
#define GVAR_DEN_HEATHER_STATUS              (378)
#define GVAR_DEN_SMITTY_DELIVER              (450)
#define GVAR_SMITTY_DELIVER_TIME             (451)
#define GVAR_DEN_VIC_KNOWN                   (452)
#define GVAR_CAR_UPGRADE_FUEL_CELL_REGULATOR (453)
#define GVAR_DEN_GANGWAR                     (454)
#define GVAR_DEN_SEE_VIC                     (457)
#define GVAR_FRED_MONEY                      (464)
#define GVAR_DEN_GANG_1_COUNT                (467)
#define GVAR_DEN_GANG_2_COUNT                (468)
#define GVAR_DEN_GANG_D_DAY                  (469)
#define GVAR_DEN_METZGER_GANG_KILL_TIMER     (470)
#define GVAR_DEN_GANG_TRAP                   (471)
#define GVAR_DEN_GANG_DOOR                   (472)
// quests
#define GVAR_QUEST_VIC_DEVICE                (100)
#define GVAR_DEN_CAR_PART_PIP                (550)
#define GVAR_DEN_ANNA_LOCKET_PIP             (551)
#define GVAR_DEN_FRED_NO                     (704) //killap's code
#define GVAR_DEN_FRED_PAID                   (705) //killap's code
#define GVAR_DEN_FRED_COVERED                (706) //killap's code
#define GVAR_DEN_FRED_LOAN                   (707) //killap's code


// Klamath Information

#define GVAR_TORR_HARMED                     (69)
#define GVAR_TORR_DEAD                       (70)
#define GVAR_TORR_MISSING                    (71)
#define GVAR_TORR_SEARCH_SUCCESS             (72)
#define GVAR_TRAPPER_RETURNED                (73)
//#define GVAR_DUNTONS_ANGRY                   (74) //this is unused - killap
#define GVAR_TORR_BRAHMIN_KILLED             (74) //moved here by killap
#define GVAR_RUSTLE_FAIL_VIOLENT             (75)
#define GVAR_RUSTLE_FAIL                     (76)
#define GVAR_RUSTLE_SUCCESS                  (77)
#define GVAR_TORR_GUARD_SUCCESS              (78)
#define GVAR_TORR_SEARCH_ACCEPT              (236)

#define GVAR_QUEST_RUSTLE_CATTLE             (102)
#define GVAR_RUSTLE_ACCEPT                   (179)
#define GVAR_RUSTLE_REFUSE                   (180)
#define GVAR_RUSTLE_REWARD                   (181)
#define GVAR_TORR_GUARD_STATUS               (182)
#define GVAR_RUSTLE_OVER                     (184)
#define GVAR_DUNTON_DEAD                     (188)
#define GVAR_SMILEY_STATUS                   (197)
#define GVAR_STILL_STATUS                    (198)
#define GVAR_STILL_FAILURE                   (199)
//#define GVAR_TORR_BRAHMIN_KILLED             (202)
#define GVAR_ENEMY_TORR                      (203)
#define GVAR_ENEMY_DUNTON                    (204)
#define GVAR_ENEMY_SMILEY                    (205)
#define GVAR_SULIK_FREE                      (235)
#define GVAR_QUEST_RAT_GOD                   (390)
#define GVAR_QUEST_RESCUE_TORR               (391)
#define GVAR_STILL_START                     (458)
#define GVAR_ARDIN_FREEDOM                   (460)
#define GVAR_CAN_ASK_ARDIN_ABOUT_SMILEY      (465)
#define GVAR_KLAMATH_GENERATOR               (601)
#define GVAR_BATH_HOUSE_REJECT               (603)
#define GVAR_KLAMATH_SCORPIONS_KILLED        (621)
#define GVAR_KLAMATH_SCORPIONS_TOTAL         (622)
#define GVAR_SCARE_DUNTONS                   (701)  //added by killap


// Navarro
// This flag indicates whether the player knows of the vertibirds/has the plans
// used by SAN FRANCISCO and NAVARRO
#define GVAR_WHIRLY                          (351)
#define GVAR_NAVARRO_BASE_ALERT              (511)
#define GVAR_NAVARRO_FOB                     (512)
#define GVAR_NAVARRO_K9                      (513)
#define GVAR_NAVARRO_POWER_CENTER            (514)
#define GVAR_NAVARRO_VERTIBIRDS              (515)
#define GVAR_NAVARRO_XARN                    (554)
#define GVAR_SCHREBER_DEAD                   (696) // Seraph's Code

// Modoc
#define GVAR_JONNY_STATE                     (113)
#define GVAR_JONNY_TILE                      (114)
#define GVAR_MODOC_BRAHMIN_ALIVE             (115)
#define GVAR_MODOC_DOGS_ALIVE                (116)
#define GVAR_MODOC_TOOL_FLAG                 (117)
#define GVAR_MODOC_SLAUGHTER_BESS_TIME       (118)
#define GVAR_KARL_STATE                      (119)
#define GVAR_MODOC_BODIES                    (120)
#define GVAR_MODOC_SLAUGHTER_FLAG            (121)
#define GVAR_MODOC_ROSE_FLAG                 (122)
#define GVAR_MODOC_TANNERY_FLAG              (123)
#define GVAR_MODOC_POST_FLAG                 (124)
#define GVAR_LADDIE_STATE                    (126)
#define GVAR_LADDIE_TILE                     (127)
#define GVAR_MODOC_JONNY_HOME                (128)
#define GVAR_MODOC_KARL_HOME                 (129) //comment out by killap - not needed
#define GVAR_MODOC_SPOKE_PROTECTOR           (130)
#define GVAR_MODOC_MESSAGE                   (131)
#define GVAR_MODOC_STAGE_TIMER               (290)
#define GVAR_MODOC_STAGE_STATE               (291)
#define GVAR_MODOC_KILL_ALL_BRAHMIN_TIME     (99)
#define GVAR_MODOC_GENERIC_FLAG_1            (297)
#define GVAR_MODOC_BRAHMIN_ESCAPED           (299)
#define GVAR_SLAG_CNT                        (310)
#define GVAR_MODOC_ENDINGS                   (388)
#define GVAR_MODOC_GENERIC_FLAG_2            (402)
#define GVAR_SLAUGHTER_SLAG_TIME             (403)
#define GVAR_MODOC_SHITTY_DEATH              (491)
#define GVAR_MODOC_GHOST_SEED_PIP            (631)
#define GVAR_MODOC_JONNY_PIP                 (693)
#define GVAR_NEW_RENO_FLAG_4                 (694)

// seed states
#define GVAR_MODOC_FAMILY_FEUD_SEED_ONE      (105)
#define GVAR_MODOC_FAMILY_FEUD_SEED_TWO      (106)
#define GVAR_MODOC_BRAHMIN_SEED              (107)
#define GVAR_MODOC_KARL_PIP                  (108) //killap comment out - not needed
#define GVAR_MODOC_KARL_SEED                 (109)
#define GVAR_MODOC_VERMIN_HUNTER_SEED        (110)
#define GVAR_MODOC_GHOST_FARM_SEED           (111)
#define GVAR_SLAG_ATTACK                     (112)

// Vault City Information
#define GVAR_VAULT_CITIZEN                   (79)
#define GVAR_VAULT_PLOW_PROBLEM              (80)
#define GVAR_VAULT_CITIZENSHIP               (81)
#define GVAR_VAULT_GECKO_PLANT               (82)
#define GVAR_VAULT_PLANT_STATUS              (83)
#define GVAR_VAULT_REDDING_PROBLEM           (84)
#define GVAR_VAULT_JET_QUEST                 (85)
#define GVAR_DAY_PASS_SHOWN                  (86)
#define GVAR_VAULT_CITIZEN_TEST              (87)
#define GVAR_VAULT_RAIDERS                   (88)
#define GVAR_VAULT_DELIVER_HOLODISK          (89)
#define GVAR_VAULT_FIND_THOMAS               (90)
#define GVAR_BUST_SKEEVE                     (103)
#define GVAR_VAULT_GET_LYNETTE_REWARD        (138)
#define GVAR_VAULT_GET_MCCLURE_PART          (139)
#define GVAR_VAULT_SERVANT                   (140)
#define GVAR_VAULT_VILLAGE                   (141)
#define GVAR_VAULT_MONSTER_COUNT             (144)
#define GVAR_SERVANT_RAID_DATE               (145)
#define GVAR_VAULT_BEEN_TO_RAIDERS           (148)
#define GVAR_MCCLURE_KNOWN                   (163)
#define GVAR_MOORE_STATE                     (320)
#define GVAR_MOORE_ACCEPT_DELIVERY           (321)
#define GVAR_MOORE_REFUSE_DELIVERY           (322)
// DONT USE GVAR_VAULT_JET_SOURCE!!! Use jet_source macros in NewReno.h
#define GVAR_VAULT_JET_SOURCE                (392)
#define GVAR_VAULT_CITY_VENT                 (400)
#define GVAR_VAULT_PIP                       (401)
#define GVAR_DR_TROY_STATUS                  (428)
#define GVAR_VAULT_LYNETTE_STATUS            (436)
#define GVAR_VC_MET_ED                       (463)
#define GVAR_VAULT_USED_TEACHING_SYSTEM      (466)
#define GVAR_VAULT_VAL_TOOLS                 (493)
#define GVAR_VAULT_BOOZE_SMUGGLING           (497)
#define GVAR_VAULT_STARK_RECON               (529)
#define GVAR_FINISHED_STARK_RECON            (540)
#define GVAR_VAULT_CITY_DESIGNER_NOTES       (541)
#define GVAR_DROP_PLAYER_BY_VAULT_8          (261) // was shared with GVAR_ENCLAVE_COM_LINE, separated into a new gvar

#define GVAR_PIPBOY_TOUR_GUIDE               (404)
#define GVAR_PIPBOY_CREDITS                  (405)

// Vault City Quest Info
#define GVAR_QUEST_VAULT_CITIZEN             (91)
#define GVAR_QUEST_PLOW_PROBLEM              (92)
#define GVAR_QUEST_GECKO_PLANT               (93)
#define GVAR_QUEST_REDDING_PROBLEM           (94)
#define GVAR_QUEST_JET_QUEST                 (95)
#define GVAR_QUEST_RAIDERS                   (96)
#define GVAR_QUEST_DELIVER_HOLODISK          (97)
#define GVAR_QUEST_FIND_THOMAS               (98)
#define GVAR_QUEST_VAULT_SERVANT             (142)
#define GVAR_QUEST_VAULT_VILLAGE             (143)
#define GVAR_QUEST_JOSHUA                    (459)

// Broken Hills Information
#define GVAR_BROKEN_HILLS_FRAUD              (147)
#define GVAR_BH_CHAD                         (300)
#define GVAR_BH_FTM                          (301) // Fight The Mutants? RP quest, mostly cut. Var used to tell Marcus about Dr. Henry's serum.
#define GVAR_BH_MINE                         (302)
#define GVAR_BH_JAIL                         (303)
#define GVAR_BH_CONSPIRACY                   (304)
#define GVAR_BH_MISSING                      (305)
#define GVAR_BH_MIGHTY_MAN                   (306)
#define GVAR_BH_MINING                       (307)
#define GVAR_BH_BOSS                         (324)
#define GVAR_BH_HENCH_COUNT                  (325)
#define GVAR_BH_MALE_NAMES_USED              (326)
#define GVAR_BH_FEMALE_NAMES_USED            (327)
#define GVAR_BH_HENCH_KILLED                 (328)
#define GVAR_BH_CHECKED                      (329)
#define GVAR_BH_CARAVAN                      (330)
#define GVAR_BH_RANK_KILLED                  (331)
#define GVAR_KNOW_DOC_HOLIDAY                (368)
#define GVAR_JAIL_BREAK                      (443)
#define GVAR_GIMP_FLAG                       (489)
#define GVAR_READ_FRANCIS_NOTE               (524)
#define GVAR_ENEMY_CONSPIRATORS              (525)
#define GVAR_MARCUS_DEAD                     (526)
#define GVAR_BH_POWER                        (542)
#define GVAR_BROKEN_HILLS_CARAVAN_POOCH_SCREW (562)
#define GVAR_CHAD_DEAD                       (563)
#define GVAR_ENEMY_BANK_GUARDS               (567)
#define GVAR_TYPHON_QUEST_STATUS             (598)

// Sierra Army Depot
#define GVAR_SIERRA_BASE_CONTAMINATION_TIMER (149)
#define GVAR_SIERRA_BASE_LEVEL_BREACH        (150) // used for spreading virus from level to level on timer
#define GVAR_SIERRA_BASE_ALERT               (151) // unused
#define GVAR_SIERRA_BASE_ENEMY               (152)
#define GVAR_SIERRA_BASE_POWER               (153)
#define GVAR_SIERRA_BASE_SECURITY            (154) // 1. Klaxons. 2. Secbots. 3. Secret doors. 4. wcdedbot activation.
#define GVAR_BRAIN_BOT_BRAIN                 (155)
#define GVAR_SIERRA_LOCKOUT                  (156)
#define GVAR_SIERRA_PASSWORD                 (157)
#define GVAR_HOLODISK_SIERRA_EVACUATION      (164)
#define GVAR_HOLODISK_SIERRA_MED_LOG         (165)
#define GVAR_HOLODISK_SIERRA_EXP_LOG         (166)
#define GVAR_SIERRA_GNN_HOLODISK             (520)
#define GVAR_SIERRA_MISSION_HOLODISK         (521)
#define GVAR_SKYNET                          (604)

// Gecko
#define GVAR_GECKO_ECON_DISK                 (158)
#define GVAR_GECKO_REQ_FORM                  (159)
#define GVAR_GECKO_SKEETER_PART              (160)
#define GVAR_GECKO_ANKH                      (161)
#define GVAR_GECKO_SKEETER_STATUS            (167)
#define GVAR_GECKO_COOLANT                   (239)
#define GVAR_GECKO_BRAIN_DEAD                (249)
#define GVAR_GECKO_BRAIN_FRIEND              (250)
#define GVAR_QUEST_SUPER_REPAIR_KIT          (393)
#define GVAR_QUEST_PLASMA_TRANSFORMER        (394)
#define GVAR_GECKO_MELTDOWN                  (395)
#define GVAR_QUEST_REPAIR_POWER_PLANT        (396)
#define GVAR_QUEST_OPTIMIZE_POWER_PLANT      (397)
#define GVAR_GECKO_TIMER_MELTDOWN            (430)
#define GVAR_GECKO_ASSIGNED                  (490)
#define GVAR_GECKO_WORKING_ON_PLANT          (581)
#define GVAR_PLANT_SCHEDULED_FOR_CHANGE      (583)
#define GVAR_ENCLAVE_COM_LINE                (584)
#define GVAR_GECKO_FIND_WOODY                (616)
#define GVAR_GECKO_DESCENDANT_KNOWN          (618)

// NCR
#define GVAR_NCR_TANDI_WORK                  (168)
#define GVAR_NCR_TANDI_JOB_ACCEPT            (169)
#define GVAR_NCR_BEAT_HOSS                   (170)
#define GVAR_NCR_SQUAT_DEAL                  (171)
#define GVAR_NCR_V15_DARION_DEAD             (172)
#define GVAR_NCR_V15_DARION_DEAL             (173)
#define GVAR_NCR_SPY_KNOWN                   (177)
#define GVAR_NCR_TANDI_WARN_CARLSON          (178)
#define GVAR_NCR_BRAHMIN_PROTECT             (185)
#define GVAR_NCR_DEATHCLAW_DEN               (186)
#define GVAR_NCR_CAR_JACKED                  (189)
#define GVAR_NCR_MERK_WORK                   (190)
#define GVAR_NCR_VORTIS_QUEST_STATE          (195)
#define GVAR_NCR_RANGERS_KNOWN               (196)
#define GVAR_NCR_SCMERK_HEREBEFORE           (206)
#define GVAR_NCR_SCMERK_HOSTILE              (207)
#define GVAR_NCR_SCMERK_PERSONAL_ENEMY       (208)
#define GVAR_NCR_SCMERK_STATUS               (209)
#define GVAR_NCR_SCMERK_SEED_STATUS          (210)
#define GVAR_NCR_LENNY_MET                   (211)
#define GVAR_NCR_ELRON_ADJUST                (212)
#define GVAR_NCR_FAKE_VAULT13_MAP            (213)
#define GVAR_NCR_FAKE_VAULT13_HOLODISK       (214)
#define GVAR_NCR_MIRA_STATE                  (217)
#define GVAR_NCR_ROPE_KNOWN                  (218)
#define GVAR_NCR_GTEGRD_ATTACK               (225)
#define GVAR_NCR_GATE_NIGHT                  (226)
#define GVAR_NCR_ENCLAVE_INFO                (227)
#define GVAR_NCR_WESTIN_SEED                 (228)
#define GVAR_NCR_DOROTHY_SEED                (229)
#define GVAR_NCR_POWER_ON                    (234)
#define GVAR_NCR_HENRY_HYPO                  (237)
#define GVAR_NCR_POWERPLANT                  (240)
#define GVAR_NCR_PLAYER_RANGER               (241)
#define GVAR_NCR_JACK_STATE                  (242)
#define GVAR_NCR_GENERIC_STATE               (243)
#define GVAR_NCR_SNUFF_BISHOP                (256)
#define GVAR_NCR_ELISE_SEED                  (262)
#define GVAR_NCR_FELIX_SEED                  (264)
#define GVAR_NCR_BISHOP_PRICE                (265)
#define GVAR_NCR_CATTLE_DRIVE                (266)
#define GVAR_NCR_CATTLE_TIME_MIN             (267)
#define GVAR_NCR_CATTLE_TIME_MAX             (268)
#define GVAR_NCR_GRANT_HOSTILE               (406)
#define GVAR_NCR_WFIELD_NOTIFY               (407)
#define GVAR_NCR_GEN_FLAGS                   (438)
#define GVAR_NCR_BRAHMN_QST                  (481)
#define GVAR_NCR_DRPAPR_QST                  (482)
#define GVAR_NCR_ELMBISHOP_QST               (483)
#define GVAR_NCR_LYNETTE_HOLO_QST            (484)
#define GVAR_NCR_ENLONE_LETTER_QST           (485)
#define GVAR_NCR_KILL_ELRON_QST              (486)
#define GVAR_NCR_BRAHMIN_QST                 (500)
#define GVAR_NCR_FREE_SLAVES_QST             (502)
#define GVAR_NCR_GUARDS_CHECK_OBJ            (566)
#define GVAR_NCR_SPY_HOLO_DOWNLOAD           (595)
#define GVAR_NCR_HISTORY_HOLO_DOWNLOAD       (596)
#define GVAR_NCR_WESTIN_HOLO_DOWNLOAD        (597)

//Vault 13
#define GVAR_VAULT13_CLEAR                   (176)
#define GVAR_VAULT13_FOUND_GECK              (233)
#define GVAR_V13_V15_DALIA_STATE             (288)
#define GVAR_GRUTHAR_DSTATUS                 (350)
#define GVAR_V13_STATUS_FLAGS                (429)
#define GVAR_V13_COMP_QST                    (487)
#define GVAR_V13_GORIS_QST                   (488)



//Vault 15
#define GVAR_V15_SEED_STATUS                 (293)
#define GVAR_V15_CRISSY_QUEST                (473)
#define GVAR_V15_KILL_DARION                 (474)
#define GVAR_V15_NCR_DEAL                    (475)
#define GVAR_V15_NCR_SPY                     (476)

//San Francisco
#define GVAR_SAN_FRAN_FLAGS                  (361)
#define GVAR_SAN_FRAN_SUB                    (362)
#define GVAR_SAN_FRAN_TANKER                 (363)
#define GVAR_SAN_FRAN_SHIHACKED              (364)
#define GVAR_SAN_FRAN_BADGER                 (365)
#define GVAR_SAN_FRAN_ELRON                  (366)
#define GVAR_SAN_FRAN_SPLEEN                 (367)
#define GVAR_SAN_FRAN_STRUGGLE               (426)
#define GVAR_SAN_FRAN_ELRON_WHIRLY           (427)
#define GVAR_SAN_FRAN_ARMOR                  (444)
#define GVAR_SAN_FRAN_SPLEEN_TIME            (448)
#define GVAR_SAN_FRAN_DAVE                   (462)
#define GVAR_SAN_FRAN_EG_NOTIFY              (477)
#define GVAR_SAN_FRAN_EG_A_OBJ               (478)
#define GVAR_ELRON_GUARDS                    (479)
#define GVAR_SAN_FRAN_SHI_WHIRLY             (519)
#define GVAR_ELRON_HOLODISK                  (522)
#define GVAR_SAN_FRAN_FUEL_TANK_QST          (532)
#define GVAR_SAN_FRAN_NAV_TANK_QST           (533)
#define GVAR_SAN_FRAN_FOB_TANK_QST           (534)
#define GVAR_SAN_FRAN_ELRON_GAS_QST          (535)
#define GVAR_SAN_FRAN_BADGER_GFRIEND_QST     (536)
#define GVAR_SAN_FRAN_LOPAN_KDRAGON_QST      (537)
#define GVAR_SAN_FRAN_DRAGON_KLOPAN_QST      (538)
#define GVAR_SAN_FRAN_ARMOR_QST              (539)
#define GVAR_SAN_FRAN_WONG_EAT_TIME          (553)
#define GVAR_SAN_FRAN_KILL_OZ9_QST           (555)
#define GVAR_SAN_FRAN_VERTI_STEAL_SHI_QST    (557)
#define GVAR_SAN_FRAN_VERTI_STEAL_ELE_QST    (558)
#define GVAR_SAN_FRAN_KILL_EMP_QST           (559)
#define GVAR_SAN_FRAN_VERTI_SHI_QST          (560)
#define GVAR_SAN_FRAN_VERTI_ELE_QST          (561)
#define GVAR_SAN_FRAN_JASHUA_STATUS          (564)
#define GVAR_SAN_FRAN_BOS_QUEST              (565)

//New Reno
#define GVAR_NEWRENO_SNUFF_WESTIN            (174)
#define GVAR_NEWRENO_SNUFF_CARLSON           (175)
#define GVAR_SALVATORE_FAMILY_COUNTER        (134)
#define GVAR_BISHOP_FAMILY_COUNTER           (135)
#define GVAR_MORDINO_FAMILY_COUNTER          (136)
#define GVAR_WRIGHT_FAMILY_COUNTER           (216)
#define GVAR_NEW_RENO_WARNING_TIMER          (219)
#define GVAR_NEW_RENO_MADE_MAN               (230)
#define GVAR_NEW_RENO_PRIZEFIGHTER           (231)
#define GVAR_NEW_RENO_PORN_STAR              (232)
#define GVAR_NEW_RENO_MCGEE_SEED             (246)
#define GVAR_NEW_RENO_MCGEE_KNOWN            (247)
#define GVAR_NEW_RENO_MCGEE_ATTACKED         (248)
#define GVAR_SALVATORE_WARNINGS              (251)
#define GVAR_BISHOP_WARNINGS                 (252)
#define GVAR_MORDINO_WARNINGS                (253)
#define GVAR_WRIGHT_WARNINGS                 (254)
#define GVAR_NEW_RENO_BISHOP                 (255)
#define GVAR_NEW_RENO_CARLSON_PRICE          (257)
#define GVAR_NEW_RENO_WESTIN_PRICE           (258)
#define GVAR_NEW_RENO_HAS_REP_PRIZEFIGHTER   (259)
#define GVAR_NEW_RENO_ANGELA                 (260)
#define GVAR_NEW_RENO_MRS_BISHOP             (263)
#define GVAR_NEW_RENO_MYRON                  (284)
#define GVAR_NEW_RENO_WRIGHT_FLAGS           (285)
#define GVAR_NEW_RENO_WRIGHT_MYSTERY         (286)
#define GVAR_NEW_RENO_SALVATORE_RESPECT      (311)
#define GVAR_NEW_RENO_TRACK_LLOYD            (312)
#define GVAR_NEW_RENO_GUARD_ASSIGNMENT       (313)
#define GVAR_NEW_RENO_FLAG_1                 (314)
#define GVAR_NEW_RENO_SALVATORE              (315)
#define GVAR_NEW_RENO_TRIBUTE                (316)
#define GVAR_NEW_RENO_SALVATORE_PISTOL       (317)
#define GVAR_NEW_RENO_ESCAPE                 (318)
#define GVAR_NEW_RENO_SAD                    (343)
#define GVAR_NEW_RENO_WRIGHT_STILL           (344)
#define GVAR_NEW_RENO_FLAG_2                 (345)
#define GVAR_NEW_RENO_WRIGHT_STILL_MISSION   (346)
#define GVAR_NEW_RENO_JULES_KITTY            (347)
#define GVAR_NEW_RENO_STOLEN_CAR             (348)
#define GVAR_NEW_RENO_JULES_ELDRIDGE         (349)
#define GVAR_NEW_RENO_DELIVERY               (354)
#define GVAR_NEW_RENO_EXTORTION_BROS         (355)
#define GVAR_NEW_RENO_ASSASSINATION          (356)
#define GVAR_NEW_RENO_LIL_JESUS_REFERS       (357)
#define GVAR_NEW_RENO_JET_SOURCE             (370)
#define GVAR_NEW_RENO_CAR_UPGRADE            (455)
#define GVAR_NEW_RENO_SUPER_CAR              (456)
#define GVAR_NEW_RENO_FLAG_3                 (495)
#define GVAR_MR_BISHOP_SAFE                  (496)
#define GVAR_NEW_RENO_KITTY_MAGAZINES        (501)
#define GVAR_NEW_RENO_STUART_DEAL            (503)
#define GVAR_NEW_RENO_FIGHT_LEVEL            (504)
#define GVAR_NEW_RENO_ROUND_NUMBER           (506)
#define GVAR_NEW_RENO_ROUND_TIME             (507)
#define GVAR_NEW_RENO_DUDE_SCORE             (508)
#define GVAR_NEW_RENO_BOXER_SCORE            (509)
#define GVAR_NEW_RENO_FIGHT_STATUS           (510)
#define GVAR_NEW_RENO_KILL_DADDY_WEAPON      (523)
#define GVAR_NEW_RENO_MRS_BISHOP_COMBINATION (530)
#define GVAR_NEW_RENO_SUSPECT_JJJ            (543)
#define GVAR_NEW_RENO_SUSPECT_JULES          (544)
#define GVAR_NEW_RENO_SUSPECT_LIL_JESUS      (545)
#define GVAR_NEW_RENO_SUSPECT_RENESCO        (546)
#define GVAR_NEW_RENO_WESTIN_SNUFF_PIP       (547)
#define GVAR_NEW_RENO_CARLSON_SNUFF_PIP      (548)
#define GVAR_NEW_RENO_ELDRIDGE_PISTOL_QUEST  (549)
#define GVAR_NEW_RENO_POISON_STILL_TIME      (552)
#define GVAR_NEW_RENO_ETHYL_MEETING_TIME     (556)
#define GVAR_NEW_RENO_GUARD_MESSAGE_TIMER    (579)
#define GVAR_MADE_MAN_SALVATORE              (591)
#define GVAR_MADE_MAN_BISHOP                 (592)
#define GVAR_MADE_MAN_MORDINO                (593)
#define GVAR_MADE_MAN_WRIGHT                 (594)

// Military Base
#define GVAR_MILITARY_BASE_FLAGS             (215)
#define GVAR_HOLODISK_MB_OUTSIDE             (220)
#define GVAR_HOLODISK_MB_LEVEL_1             (221)
#define GVAR_HOLODISK_MB_LEVEL_2             (222)
#define GVAR_HOLODISK_MB_LEVEL_3             (223)
#define GVAR_HOLODISK_MB_LEVEL_4             (224)


// Redding
#define GVAR_REDDING_WHORE_CUT               (292)
#define GVAR_REDDING_EXCAVATOR_CHIP          (332)
#define GVAR_REDDING_JET_LEVEL               (333)
#define GVAR_MAYOR_REDDING_STATUS            (334)
#define GVAR_REDDING_MARGE_STATUS            (335)
#define GVAR_REDDING_DAN_STATUS              (336)
#define GVAR_REDDING_JOHNSON_STATUS          (337)
#define GVAR_CATTLE_DRIVE_CARAVAN            (338)
#define GVAR_MEDICINE_CARAVAN                (339)
#define GVAR_JET_CARAVAN                     (340)
#define GVAR_GOLD_CARAVAN                    (341)
#define GVAR_REDDING_CARAVAN_STATUS          (342)
#define GVAR_BAR_BRAWL                       (380)
#define GVAR_WADE_STATUS                     (381)
#define GVAR_STANWELL_STATUS                 (382)
#define GVAR_SAVINELLI_STATUS                (383)
#define GVAR_FROG_MORTON                     (385)
#define GVAR_REDDING_MORTON_BROTHERS         (386)
#define GVAR_REDDING_SHERIFF                 (387)
#define GVAR_WANAMINGO_OCCUPADO              (389)
#define GVAR_DOC_JOHNSON_STATUS              (437)
#define GVAR_TOTAL_WANAMINGOS                (461)
#define GVAR_ENEMY_REDDING                   (492)
#define GVAR_STANWELL_PAYOUT                 (516)
#define GVAR_WADE_PAYOUT                     (517)
#define GVAR_SAVINE_PAYOUT                   (518)
#define GVAR_MORTON_GANG                     (580)
#define GVAR_WIDOW_ROONEY                    (702) //killap's code
#define GVAR_MINE_DEED                       (703) //killap's code

// Raiders
#define GVAR_RAIDERS_FLAGS                   (373)
#define GVAR_RAIDERS_COUNT                   (377)
#define GVAR_RAIDER_SECRET_ENTRANCE_KNOWN    (527)
#define GVAR_COMING_FROM_INSIDE_RAIDERS      (528)
#define GVAR_LEFT_CAR_AT_RAIDERS             (586)
#define GVAR_RAIDERS_CAR_ELEVATION           (587)
#define GVAR_RAIDERS_DEAD                    (600)

// Enclave
#define GVAR_ENCLAVE_POWER_PLANT             (431)
#define GVAR_ENCLAVE_GRANITE_JOINED          (432)
#define GVAR_ENCLAVE_ALARM                   (433)
#define GVAR_ENCLAVE_POISON_TIMER            (434)
#define GVAR_ENCLAVE_REACTOR                 (435)
#define GVAR_ENCLAVE_COMPUTER                (440)
#define GVAR_ENCLAVE_MARTIN                  (441)
#define GVAR_ENCLAVE_ELDER                   (442)
#define GVAR_ENCLAVE_COUNTDOWN               (498)
#define GVAR_ENCLAVE_FRANK_DEAD              (499)
#define GVAR_ENCLAVE_TURRET_GUARD            (568)
#define GVAR_ENCLAVE_TURRET_DETENTION        (569)
#define GVAR_ENCLAVE_TURRET_SCIENCE          (570)
#define GVAR_ENCLAVE_TURRET_PRESIDENT        (571)
#define GVAR_ENCLAVE_TURRET_MAIN             (572)
#define GVAR_HOLODISK_ENCLAVE_SECURITY       (573)
#define GVAR_HOLODISK_ENCLAVE_STATE          (574)
#define GVAR_HOLODISK_ENCLAVE_WORD           (575)
#define GVAR_HOLODISK_ENCLAVE_CHEMICAL       (576)
#define GVAR_HOLODISK_ENCLAVE_ATOMIC         (577)
#define GVAR_ENCLAVE_TURRET_HELP_PLAYER      (578)
#define GVAR_ENCLAVE_ENEMY_GUARD             (623)
#define GVAR_ENCLAVE_ENEMY_PRESIDENT         (624)
#define GVAR_ENCLAVE_ENEMY_TRAPS             (625)
#define GVAR_ENCLAVE_ENEMY_REACTOR           (626)
#define GVAR_ENCLAVE_ENEMY_DETENTION         (627)

// Caravans for Cities
#define GVAR_CARAVAN_STATUS                  (269)
#define GVAR_CARAVAN_START                   (270)
#define GVAR_CARAVAN_END                     (271)
#define GVAR_CARAVAN_DRIVERS                 (272)
#define GVAR_CARAVAN_GUARDS                  (273)
#define GVAR_CARAVAN_CARTS                   (274)
#define GVAR_CARAVAN_ENCOUNTERS              (275)
#define GVAR_CARAVAN_BRAHMIN                 (276)
#define GVAR_CARAVAN_MASTERS                 (277)
#define GVAR_CARAVAN_DRIVERS_TOTAL           (278)
#define GVAR_CARAVAN_GUARDS_TOTAL            (279)
#define GVAR_CARAVAN_CARTS_TOTAL             (280)
#define GVAR_CARAVAN_BRAHMIN_TOTAL           (281)
#define GVAR_CARAVAN_MASTERS_TOTAL           (282)
#define GVAR_CARAVAN_ENCOUNTERS_TOTAL        (283)

// Random Encounters
#define GVAR_HOLY_GRENADE                   (372)
#define GVAR_RND_KAGA_STATE                 (399) //Look for macros below
#define GVAR_ENTERED_GUARDIAN               (602)

// Addictions
#define GVAR_NUKA_COLA_ADDICT               (21)
#define GVAR_BUFF_OUT_ADDICT                (22)
#define GVAR_MENTATS_ADDICT                 (23)
#define GVAR_PSYCHO_ADDICT                  (24)
#define GVAR_RADAWAY_ADDICT                 (25)
#define GVAR_ALCOHOL_ADDICT                 (26)
#define GVAR_ADDICT_TRAGIC                  (295)
#define GVAR_ADDICT_JET                     (296)

// City Enemy
#define GVAR_ENEMY_ARROYO                   (7)
#define GVAR_ENEMY_DEN                      (14)
#define GVAR_ENEMY_KLAMATH                  (68)
#define GVAR_ENEMY_VAULT_VILLAGE            (146)
#define GVAR_ENEMY_VAULT_CITY               (137)
#define GVAR_ENEMY_GECKO                    (238)
#define GVAR_ENEMY_BROKEN_HILLS             (309)
#define GVAR_ENEMY_VAULT_COURTYARD          (505)

// Karma Titles
#define GVAR_KARMA_HOLY_WARRIOR             (37)
#define GVAR_KARMA_GUARDIAN_OF_THE_WASTES   (38)
#define GVAR_KARMA_SHIELD_OF_HOPE           (39)
#define GVAR_KARMA_DEFENDER                 (40)
#define GVAR_KARMA_WANDERER                 (41)
#define GVAR_KARMA_BETRAYER                 (42)
#define GVAR_KARMA_SWORD_OF_DESPAIR         (43)
#define GVAR_KARMA_SCOURGE_OF_THE_WASTES    (44)
#define GVAR_KARMA_DEMON_SPAWN              (45)

// Misc.
#define GVAR_LOAD_MAP_INDEX                 (27)
#define GVAR_RUNNING_BURNING_GUY            (28)
#define GVAR_MAP_EXIT_TILE                  (46)
#define GVAR_MAP_NEXT_TILE                  (67)
#define GVAR_DUDE_STOMACH                   (104)
#define GVAR_MUTATE                         (132)
#define GVAR_MUTATE_WHEN                    (133)
#define GVAR_HAVE_MUTATED                   (192)
#define GVAR_MUTATE_STAGE                   (193)
#define GVAR_GRAVE_FLAGS_1                  (200)
#define GVAR_GRAVE_FLAGS_2                  (201)
#define GVAR_GRAVE_FLAGS_3                  (202)
#define GVAR_8_BALL_TOILET_SECRET           (245) //was shared with GVAR_NCR_GENERIC_STATE, taking an unused gvar for this
#define GVAR_8_BALL_TRASH_SECRET            (244)
#define GVAR_8_BALL_VAULT_TERMINAL          (599)
#define GVAR_GRAVES_UNEARTHED               (319)
#define GVAR_SUPER_CAR                      (379)
#define GVAR_PARTY_NO_FOLLOW                (398)
#define GVAR_CAR_BLOWER                     (439)
#define GVAR_FALLOUT_2                      (494)
#define GVAR_VIGNETTE_SEQUENCE              (582)
#define GVAR_GAVE_GECK_EXP                  (629)
#define GVAR_DUDE_START_SEQ_1               (630)
#define GVAR_PARTY_MEMBERS_HIDDEN           (632)
#define GVAR_PATCH_INVAIDITATOR             (695)


//Random Encounter
#define GVAR_SPECIAL_ENCOUNTER_FLAGS        (323)
#define GVAR_RND_SALES_NAME                 (359)
#define GVAR_RND_SALES_ENCOUNTER            (360)

// Special Random Encounters
#define GVAR_SPECIAL_ENCOUNTER_BRIDGE       (605)
#define GVAR_SPECIAL_ENCOUNTER_HOLY2        (606)
#define GVAR_SPECIAL_ENCOUNTER_TOXIC        (607)
#define GVAR_SPECIAL_ENCOUNTER_PARIAH       (608)
#define GVAR_SPECIAL_ENCOUNTER_BRAHMIN      (609)
#define GVAR_SPECIAL_ENCOUNTER_WHALE        (610)
#define GVAR_SPECIAL_ENCOUNTER_HEAD         (611)
#define GVAR_SPECIAL_ENCOUNTER_SHUTTLE      (612)
#define GVAR_SPECIAL_ENCOUNTER_GUARDIAN     (613)
#define GVAR_SPECIAL_ENCOUNTER_HOLY1        (614)
#define GVAR_SPECIAL_ENCOUNTER_WOODSMAN     (615)
#define GVAR_SPECIAL_ENCOUNTER_CAFE         (617)
#define GVAR_SPECIAL_ENCOUNTER_UNWASHED     (620)


// Endgame Movie Stills
#define GVAR_ENDGAME_MOVIE_ARROYO           (408)
#define GVAR_ENDGAME_MOVIE_MODOC            (409)
#define GVAR_ENDGAME_MOVIE_DEN              (410)
#define GVAR_ENDGAME_MOVIE_VAULT_CITY       (411)
#define GVAR_ENDGAME_MOVIE_RENO             (412)
#define GVAR_ENDGAME_MOVIE_RENO_ADD1        (413)
#define GVAR_ENDGAME_MOVIE_RENO_ADD2        (414)
#define GVAR_ENDGAME_MOVIE_RENO_ADD3        (415)
#define GVAR_ENDGAME_MOVIE_RENO_ADD4        (416)
#define GVAR_ENDGAME_MOVIE_GECKO            (417)
#define GVAR_ENDGAME_MOVIE_REDDING          (418)
#define GVAR_ENDGAME_MOVIE_BROKEN_HILLS     (419)
#define GVAR_ENDGAME_MOVIE_NCR              (420)
#define GVAR_ENDGAME_MOVIE_VAULT_15         (421)
#define GVAR_ENDGAME_MOVIE_VAULT_13         (422)
#define GVAR_ENDGAME_MOVIE_SAN_FRAN_SHI     (423)
#define GVAR_ENDGAME_MOVIE_SAN_FRAN_ELRON   (424)
#define GVAR_ENDGAME_MOVIE_SAN_FRAN_PUNKS   (425)
// Begin Seraph's Code
#define GVAR_ENDGAME_MOVIE_PRES_RICH        (697)
#define GVAR_ENDGAME_MOVIE_MARCUS           (698)
#define GVAR_ENDGAME_MOVIE_HAROLD           (699)
#define GVAR_ENDGAME_MOVIE_ELDER            (700)
// End Seraph's Code

// Town Reps
#define GVAR_TOWN_REP_ARROYO                (47)
#define GVAR_TOWN_REP_KLAMATH               (48)
#define GVAR_TOWN_REP_THE_DEN               (49)
#define GVAR_TOWN_REP_VAULT_CITY            (50)
#define GVAR_TOWN_REP_GECKO                 (51)
#define GVAR_TOWN_REP_MODOC                 (52)
#define GVAR_TOWN_REP_SIERRA_BASE           (53)
#define GVAR_TOWN_REP_BROKEN_HILLS          (54)
#define GVAR_TOWN_REP_NEW_RENO              (55)
#define GVAR_TOWN_REP_REDDING               (56)
#define GVAR_TOWN_REP_NCR                   (57)
#define GVAR_TOWN_REP_BURIED_VAULT          (58)
#define GVAR_TOWN_REP_VAULT_13              (59)
#define GVAR_TOWN_REP_COLUSA                (60)
#define GVAR_TOWN_REP_SAN_FRANCISCO         (61)
#define GVAR_TOWN_REP_ENCLAVE               (62)
#define GVAR_TOWN_REP_ABBEY                 (63)
#define GVAR_TOWN_REP_EPA                   (64)
#define GVAR_TOWN_REP_PRIMITIVE_TRIBE       (65)
#define GVAR_TOWN_REP_RAIDERS               (66)
#define GVAR_TOWN_REP_VAULT_15              (294)
#define GVAR_TOWN_REP_GHOST_FARM            (308)
#define GVAR_TOWN_REP_NAVARRO               (628)


// --RESERVED GLOBAL VARS--
// DO NOT USE UNTIL AFTER FALLOUT 2 SHIPS.
// -RWH2
#define GVAR_CAR_PLACED_TILE                (633)
#define GVAR_RESERVED_VAR1                  (634)
#define GVAR_RESERVED_VAR2                  (635)
#define GVAR_RESERVED_VAR3                  (636)
#define GVAR_RESERVED_VAR4                  (637)
#define GVAR_RESERVED_VAR5                  (638)
#define GVAR_RESERVED_VAR6                  (639)
#define GVAR_RESERVED_VAR7                  (640)
#define GVAR_RESERVED_VAR8                  (641)
#define GVAR_RESERVED_VAR9                  (642)
#define GVAR_RESERVED_VAR10                 (643)
#define GVAR_RESERVED_VAR11                 (644)
#define GVAR_RESERVED_VAR12                 (645)
#define GVAR_RESERVED_VAR13                 (646)
#define GVAR_RESERVED_VAR14                 (647)
#define GVAR_RESERVED_VAR15                 (648)
#define GVAR_RESERVED_VAR16                 (649)
#define GVAR_RESERVED_VAR17                 (650)
#define GVAR_RESERVED_VAR18                 (651)
#define GVAR_RESERVED_VAR19                 (652)
#define GVAR_RESERVED_VAR20                 (653)
#define GVAR_RESERVED_VAR21                 (654)
#define GVAR_RESERVED_VAR22                 (655)
#define GVAR_RESERVED_VAR23                 (656)
#define GVAR_RESERVED_VAR24                 (657)
#define GVAR_RESERVED_VAR25                 (658)
#define GVAR_RESERVED_VAR26                 (659)
#define GVAR_RESERVED_VAR27                 (660)
#define GVAR_RESERVED_VAR28                 (661)
#define GVAR_RESERVED_VAR29                 (662)
#define GVAR_RESERVED_VAR30                 (663)
#define GVAR_RESERVED_VAR31                 (664)
#define GVAR_RESERVED_VAR32                 (665)
#define GVAR_RESERVED_VAR33                 (666)
#define GVAR_RESERVED_VAR34                 (667)
#define GVAR_RESERVED_VAR35                 (668)
#define GVAR_RESERVED_VAR36                 (669)
#define GVAR_RESERVED_VAR37                 (670)
#define GVAR_RESERVED_VAR38                 (671)
#define GVAR_RESERVED_VAR39                 (672)
#define GVAR_RESERVED_VAR40                 (673)
#define GVAR_RESERVED_VAR41                 (674)
#define GVAR_RESERVED_VAR42                 (675)
#define GVAR_RESERVED_VAR43                 (676)
#define GVAR_RESERVED_VAR44                 (677)
#define GVAR_RESERVED_VAR45                 (678)
#define GVAR_RESERVED_VAR46                 (679)
#define GVAR_RESERVED_VAR47                 (680)
#define GVAR_RESERVED_VAR48                 (681)
#define GVAR_RESERVED_VAR49                 (682)
#define GVAR_RESERVED_VAR50                 (683)
#define GVAR_RESERVED_VAR51                 (684)
#define GVAR_RESERVED_VAR52                 (685)
#define GVAR_RESERVED_VAR53                 (686)
#define GVAR_RESERVED_VAR54                 (687)
#define GVAR_RESERVED_VAR55                 (688)
#define GVAR_RESERVED_VAR56                 (689)
#define GVAR_RESERVED_VAR57                 (690)
#define GVAR_RESERVED_VAR58                 (691)
#define GVAR_RESERVED_VAR59                 (692)


// Abbey - killap
#define GVAR_ABBEY_BEAST                          (708)
#define GVAR_ABBEY_PART                           (709)
#define GVAR_ABBEY_PUMP                           (710)
#define GVAR_ABBEY_GRAVES                         (711)
#define GVAR_ABBEY_TULLY                          (712)

//Primitive Tribe
#define GVAR_TRIBE_WEAPONS                        (713)
#define GVAR_ENEMY_PRIMITIVE_TRIBE                (714)
#define GVAR_FIXTRIBE_WELL                        (715)
#define GVAR_SULIK_SISTER                         (716)
#define GVAR_TRIBE_GHOST                          (717)
#define GVAR_SULIK_DEAD                           (718)
#define GVAR_FIND_SULIK                           (719)
#define GVAR_MISSING_WARRIOR                      (720)

//Slavers Camp/Rangers' Safe House
#define GVAR_WIPED_OUT_SLAVER_CAMP                (721)
#define GVAR_WIPED_OUT_RANGER_SAFE_HOUSES         (722)

//Vault Experiment Info
#define GVAR_VAULT_EXPERIMENTS                    (723)

//Chad skimming quest
#define GVAR_CHAD_EVIDENCE_TIP                    (724)
#define GVAR_SAINT_NICK_LINE                      (725)

// Abbey cont.
#define GVAR_ABBEY_KNOWLEDGE_EPA                  (726)
#define GVAR_ABBEY_KNOWLEDGE                      (727)

#define GVAR_DEN_ORPHANAGE                        (728)
#define GVAR_DEN_ORPHANAGE_BUILD_TIME             (729)

//Gecko Enclave Encounter
#define GVAR_ENCLAVE_SENT                         (730)

//Abbey cont.
#define GVAR_ABBEY_BOOZE                          (731)
#define GVAR_ABBEY_LIGHTER                        (732)

//Tribe cont.
#define GVAR_TRIBE_FIREWOOD                       (733)

//Klamath
#define GVAR_KLAMATH_FIND_RUSTLERS                (734)

//Town reps
#define GVAR_TOWN_REP_SLAVER_CAMP                 (735)
#define GVAR_TOWN_REP_HUBOLOGIST_STASH            (736)
#define GVAR_TOWN_REP_VAULT_VILLAGE               (737)

//EPA
#define GVAR_FOUND_EPILEPSY_CURE                  (738)
#define GVAR_FIX_HOLOGRAM00000                    (739)
#define GVAR_FIX_VOICECOMP                        (740)
#define GVAR_VAULT_VILLAGE_FLAGS                  (741)
#define GVAR_ELECTRIC_CHAIR                       (742)
#define GVAR_EPADOOR_LOCK                         (743)
#define GVAR_PLANT_QUEST                          (744)
#define GVAR_KILL_EPAPLANTS                       (745)
#define GVAR_EPAVOICE_DOOR                        (746)
#define GVAR_KILL_HOLOGRAMS                       (747)
#define GVAR_OPEN_SECURITYDOORS                   (748)
#define GVAR_MADE_DRUGS                           (749)
#define GVAR_EPADOOR_OPEN                         (750)
#define GVAR_EPA_RANDOMDRUGS                      (751)
#define GVAR_EPALIGHTING_GEN                      (752)
#define GVAR_EPADOCTOR_ATTACKED                   (753)
#define GVAR_FREE_EPASLAVES                       (754)
#define GVAR_EPA_SERVICE_ELEVATOR                 (755)
#define GVAR_TOASTER_SLOTMACHINES                 (756)
#define GVAR_MAGNETIC_FIELD                       (757)
#define GVAR_PASSWORD_KNOWN                       (758)
#define GVAR_FETCH_GECKOPELTS                     (759)
#define GVAR_LOWER_EPAFIELDS                      (760)
#define GVAR_DYNAMITE_SETTING                     (761)
#define GVAR_DYNAMITE_TRIGGER                     (762)
#define GVAR_FIX_STATICINGHOLOGRAM                (763)
#define GVAR_FOOD_QUEST_VAULT_VILLAGE             (764)
#define GVAR_CAME_ON_VERTIBIRD                    (765)
#define GVAR_COLLECT_WIDGET_FOR_EPA_DOCTOR        (766)
#define GVAR_NCR_ATTACK_SLAVER_CAMP               (767)
#define GVAR_RND_ENCOUNTER_FLAGS                  (768)
#define GVAR_REDDING_GENPES_COUNT                 (769)
#define GVAR_TMP_GLOBAL_VAR                       (770)
#define GVAR_V15_DOC_FREE                         (771)
#define GVAR_EASTER_EGG_ENCOUNTER                 (772)
#define GVAR_PLAYER_SMOKER                        (773)
#define GVAR_MERCHANT_MEETING                     (774)
#define GVAR_TEST_SOLAR_SCORCHER                  (775)
#define GVAR_ABBEY_FORMAT_DATABASES               (776)
#define GVAR_ABBEY_ESCORT_BROTHER_JASON           (777)
#define GVAR_NEED_ERSI                            (778)
#define GVAR_CHAR_MOD                             (779)
#define GVAR_CAR_OUTTA_POWER_FIX                  (780)
#define GVAR_TRIBE_SHAMAN_HERBS                   (781)
#define GVAR_SHI_FIND_DR_SHENG                    (782)
#define GVAR_SHI_DELIVER_SEEDS_TO_DR_SHENG        (783)
#define GVAR_SHI_DELIVER_SEED_SAMPLE_TO_DR_WONG   (784)
#define GVAR_SHI_ELIMINATE_DR_SHENG               (785)
#define GVAR_SHI_ELIMINATE_DR_WONG                (786)
#define GVAR_MET_SEYMOUR                          (787)
#define GVAR_WOOZ_STATUS                          (788)
#define GVAR_CLEAR_OUT_DR_SHENG_LAB               (789)
#define GVAR_WESTIN_HEART_TROUBLE                 (790)

/******************************************************************
    Variable States
******************************************************************/

#define KNOWLEDGE_NONE                      (0)
#define KNOWLEDGE_LEARNING                  (1)
#define KNOWLEDGE_OBTAINED                  (2)

#define QUEST_NONE                          (0)
#define QUEST_KNOWN                         (1)
#define QUEST_DECLINED                      (2)
#define QUEST_INACTIVE                      (3)
#define QUEST_ACCEPTED                      (4)
#define QUEST_PAST_PART_1                   (5)
#define QUEST_PAST_PART_2                   (6)
#define QUEST_COMPLETED                     (7)
#define QUEST_DEFAULT_SOLVE                 (8)

#define PERSON_KNOWN                        bit_1
#define PERSN_ATTACKED                      bit_2
#define PERSON_KILLED                       bit_3
#define PERSON_ASSASSINATED                 bit_4
#define PERSON_IN_PARTY                     bit_5
#define PERSON_SPOKEN_TO                    bit_6
#define PERSON_SPOKEN_TO_SPECIAL            bit_7
#define PERSON_SPECIAL                      bit_8
#define PERSON_SPECIAL_2                    bit_9
#define PERSON_DEAD                         bit_10
#define PERSON_WARNED                       bit_11
#define PERSON_SEX                          bit_12

//GVAR_JAIL_BREAK (BROKEN HILLS)
#define JB_IN_PROGRESS                      (1)
#define JB_SUCCESSFUL                       (2)
#define JB_OVER                             (3)

//GVAR_NAVARRO_BASE_ALERT (NAVARRO)
#define NAVARRO_SECURITY_OFF                (0)
#define NAVARRO_SECURITY_ON                 (1)

//GVAR_NAVARRO_FOB (NAVARRO)
#define NAVARRO_NEED_FOB                    (1)
#define NAVARRO_HAVE_FOB                    (2)

//GVAR_NAVARRO_K9 (NAVARRO)
#define NAVARRO_K9_NEED_PART                (1)
#define NAVARRO_K9_HAVE_PART                (2)
#define NAVARRO_K9_FIXED                    (3)

//GVAR_NAVARRO_XARN (NAVARRO)
#define NAVARRO_XARN_KNOW_ABOUT             (1)
#define NAVARRO_XARN_FINISHED               (2)

//GVAR_NAVARRO_POWER_CENTER (NAVARRO)
#define NAVARRO_POWER_CENTER_DESTROYED      (1)

//GVAR_NAVARRO_VERTIBIRDS (NAVARRO)
#define NAVARRO_VERTIBIRDS_DESTROYED        (1)

//GVAR_PLANT_SCHEDULED_FOR_CHANGE (GECKO)
#define SCHEDULED_FOR_DESTRUCTION           (1)
#define SCHEDULED_FOR_REPAIRS               (2)

//GVAR_QUEST_DESTROY_POWER_PLANT (GECKO)
#define DESTROY_POWER_PLANT_ACCEPT          (1)
#define DESTROY_POWER_PLANT_SUCCESS         (2)

//GVAR_GECKO_REACTOR_SECURITY (GECKO)
#define GECKO_SECURITY_OFF                  (0)
#define GECKO_SECURITY_ON                   (1)

//GVAR_QUEST_REPAIR_POWER_PLANT (GECKO)
#define REPAIR_POWER_PLANT_ACCEPT           (1)
#define REPAIR_POWER_PLANT_SUCCESS          (2)

//GVAR_QUEST_OPTIMIZE_POWER_PLANT (GECKO)
#define OPTIMIZE_POWER_PLANT_ACCEPT         (1)
#define OPTIMIZE_POWER_PLANT_SUCCESS        (2)

//GVAR_QUEST_PLASMA_TRANSFORMER (GECKO)
#define PLASMA_TRANSFORMER_ACCEPT           (1)
#define PLASMA_TRANSFORMER_SUCCESS          (2)

//GVAR_QUEST_SUPER_REPAIR_KIT (GECKO)
#define SUPER_REPAIR_KIT_ACCEPT             (1)
#define SUPER_REPAIR_KIT_SUCCESS            (2)

//GVAR_GECKO_FIND_WOODY (GECKO)
#define WOODY_UNKNOWN                       (0)
#define WOODY_ACCEPTED                      (1)
#define WOODY_REFUSED                       (2)
#define WOODY_FOUND                         (3)
#define WOODY_REWARDED                      (4)

//GVAR_QUEST_RESCUE_TORR (KLAMATH)
#define TORR_RESCUE_ACCEPT                  (1)
#define TORR_RESCUE_SUCCESS                 (2)

//GVAR_QUEST_RAT_GOD (KLAMATH)
#define RAT_GOD_ACCEPT                      (1)
#define RAT_GOD_SUCCESS                     (2)

//GVAR_QUEST_RUSTLE_CATTLE (KLAMATH)
#define RUSTLE_ACCEPT                       (1)
#define RUSTLE_SUCCESS                      (2)
#define RUSTLE_FAIL                         (3)

//GVAR_TORR_GUARD_STATUS (KLAMATH)
#define TORR_GUARD_ACCEPT                   (1)
#define TORR_GUARD_SUCCESS                  (2)
#define TORR_GUARD_FAIL                     (3)

//GVAR_KLAMATH_FIND_RUSTLERS -added by killap
#define FIND_RUSTLERS_ACCEPT                (1)
#define FIND_RUSTLERS_SUCCESS               (2)

//GVAR_SMILEY_STATUS (KLAMATH)
#define SMILEY_QUEST_ACCEPTED               (1)
#define SMILEY_RETURNED                     (2)
#define SMILEY_IS_HERE                      (3)
#define SMILEY_DEAD                         (4)

// GVAR_STIL_STATUS (KLAMATH)
#define STILL_ACCEPT                        (1)
#define STILL_SUCCESS                       (2)
#define STILL_FAILURE                       (3)
#define STILL_BETRAY                        (4)
#define STILL_REWARDED                      (5)
#define STILL_CANCEL                        (6)

// GVAR_START_ARROYO_TRIAL
#define TRIAL_NONE                          (0)
#define TRIAL_FIGHT                         (1)
#define TRIAL_TALK                          (2)
#define TRIAL_SNEAK                         (3)

#define SLAVE_RUN_NONE                      (0)
#define SLAVE_RUN_STARTED                   (1)
#define SLAVE_RUN_ABONDONED                 (2)
#define SLAVE_RUN_FINISHED                  (3)

#define CITIZEN_FALSE                       (0)
#define CITIZEN_TRUE                        (1)

#define CITIZEN_SKEEVE_GIVEN_FAKE           (1)
#define CITIZEN_KNOWN_FAKE                  (2)
#define CITIZEN_GUARD_BELIEVE_FAKE          (3)
#define CITIZEN_REAL_CITIZEN                (4)
#define CITIZEN_CAPTAIN_GUARD               (5)
#define CITIZEN_KICKED_OUT                  (6)

#define PLOW_PLAYER_KNOWS                   (1)
#define PLOW_WIFE_TALKED                    (2)
#define PLOW_HELP_CASH                      (3)
#define PLOW_HELP_FREE                      (4)
#define PLOW_NEED_REWARD                    (5)
#define PLOW_FIXED                          (6)
#define PLOW_SCREW_SMITH                    (7)

#define PLANT_PROBLEM_KNOWN                 (1)
#define PLANT_ACCEPTED_QUEST                (2)
#define PLANT_DECLINED_QUEST                (3)
#define PLANT_PROBLEM_UNDERSTOOD            (4)
#define PLANT_NEED_PART                     (5)
#define PLANT_RANDAL_GIVE                   (6)
#define PLANT_HAS_PART                      (7)
#define PLANT_DESTROYED                     (8)
#define PLANT_REPAIRED                      (9)
#define PLANT_GHOULS_DEAD                   (10)
#define PLANT_TURNED_OFF                    (11)
#define PLANT_FIXED_PLUS_KNOWN              (12)
#define PLANT_REACTOR_DATA_RECEIVED         (12)
#define PLANT_REACTOR_DATA_ANALYZED         (13)
#define PLANT_REACTOR_DATA_GIVEN            (14)
#define PLANT_OPTIMIZED                     (15)
#define PLANT_FIXED_PLUS                    (15)

#define JET_DECLINED_JOB                    (1)
#define JET_WILL_GET                        (2)
#define JET_GIVEN_JET                       (3)
#define JET_ANTIDOTE_FOUND                  (4)
#define JET_BLACKMAIL_ON                    (5)
#define JET_BLACKMAIL_OVER                  (6)

#define VENT_KNOWN                          (1)
#define VENT_REPAIRED                       (2)

#define ED_UNKNOWN                          (0)
#define ED_KNOWN                            (1)

#define BOOTLEG_UNKNOWN                     (0)
#define BOOTLEG_ASSIGNED                    (1)
#define BOOTLEG_DELIVERED                   (2)

#define RECON_UNKNOWN                       (0)
#define RECON_GECKO_ASSIGNED                (1)
#define RECON_GECKO_DONE                    (2)
#define RECON_NCR_ASSIGNED                  (3)
#define RECON_NCR_DONE                      (4)

// GVAR_VAULT_PIP
#define PIP_FOUND                           (1)
#define PIP_DOWNLOAD                        (2)
#define PIP_REWARD                          (3)
#define PIP_DONE                            (4)

#define REDDING_PROBLEM_NONE                (0)
#define REDDING_PROBLEM_KNOW_EXISTS         (1)
#define REDDING_PROBLEM_KNOW_JET            (2)
#define REDDING_PROBLEM_DELIVERED_ANTIDOTE  (3)
#define REDDING_PROBLEM_DONE                (4)

#define SKEEVE_BUSTED                       (1)

#define REWARD_NONE                         (0)
#define REWARD_OFFERED                      (1)
#define REWARD_OBTAINED                     (2)

//not using these...
//#define SERVANT_REFUSED                     (1)
//#define SERVANT_PISSED                      (2)
//#define SERVANT_MAP_VISITED                 (3)
//#define SERVANT_NO_GUNS                     (4)
//#define SERVANT_NOT_READY                   (5)
//#define SERVANT_FINISHED                    (6)


#define SERVANT_TIME_EXTENDED               (1)
#define SERVANT_BRAIN_AGREEMENT             (2)
#define SERVANT_FINISHED_VIOLENT            (3)
#define SERVANT_FINISHED_DIPLOMATIC         (4)
#define SERVANT_TURNED_IN_HARRY             (5)

#define SERVANT_QUEST_ACCEPTED              (1)
#define SERVANT_QUEST_REFUSED               (2)
#define SERVANT_QUEST_CHANGED_MIND          (3)
#define SERVANT_QUEST_FINISHED              (4)


#define GAVE_INFO                           (1)
#define GAVE_AMULET                         (2)

#define VILLAGE_KNOWN                       (1)
#define VILLAGE_SCREWED                     (2)
#define VILLAGE_STAGE_ONE                   (4)
#define VILLAGE_STAGE_TWO                   (5)
#define VILLAGE_FINISHED                    (6)

#define VILLAGE_QUEST_GET_GUNS              (1)
#define VILLAGE_QUEST_JOE_SPOKE             (2)
#define VILLAGE_QUEST_GOT_GUNS              (3)
#define VILLAGE_QUEST_DELIVERED_GUNS        (4)
#define VILLAGE_QUEST_SPEAK_WITH_COUNCIL    (5)
#define VILLAGE_QUEST_FINISHED_DIPLOMATIC   (6)
#define VILLAGE_QUEST_NEED_FOOD             (7)
#define VILLAGE_QUEST_DELIVERED_FOOD        (8)

#define MOORE_NONE                          (0)
#define MOORE_KNOWN                         (1)
#define MOORE_EXILED                        (2)
#define MOORE_DEAD                          (3)

#define ACCEPT_DELIVERY_ASSIGNED            (1)
#define ACCEPT_DELIVERY_HAPPY               (2)
#define ACCEPT_DELIVERY_DEATH               (3)
#define ACCEPT_DELIVERY_FAILED              (4) // attacked Bishop

#define HOLODISK_ACCEPTED                   (1)
#define HOLODISK_DECLINED                   (2)
#define HOLODISK_DELIVERED                  (3)
#define HOLODISK_DONE                       (4)

// GVAR_DR_TROY_STATUS
#define TROY_EXILED                         (1)
#define TROY_DEAD                           (2)

#define FIND_THOMAS_KNOWN                   (1)
#define FIND_THOMAS_ACCEPTED                (2)
#define FIND_THOMAS_DECLINED                (3)
#define FIND_THOMAS_FOUND                   (4)

// GVAR_VAULT_JET_SOURCE
// DONT USE THESE!!! Use jet_source macros in NewReno.h
#define JET_SOURCE_HINTED_AT                (1)
#define JET_SOURCE_DISCOVERED               (2)
#define JET_SOURCE_CURE_KNOWN               (3)
#define JET_SOURCE_CURE_MADE                (4)

#define JOSHUA_UNKNOWN                      (0)
#define JOSHUA_ASSIGNED                     (1)
#define JOSHUA_FREED                        (2)
#define JOSHUA_REWARDED                     (3)

#define VAL_TOOLS_UNKNOWN                   (0)
#define VAL_TOOLS_ASSIGNED                  (1)
#define VAL_TOOLS_DONE                      (2)

#define RAIDERS_PROBLEM_KNOWN               (1)
#define RAIDERS_ACCEPTED_QUEST              (2)
#define RAIDERS_DECLINED_QUEST              (3)
#define RAIDERS_FOUND                       (4)
#define RAIDERS_PLANS_KNOWN_RENO            (5)
#define RAIDERS_PLANS_KNOWN_NCR             (6)
#define RAIDERS_GIVE_REWARD                 (7)
#define RAIDERS_DONE                        (8)

#define FRAUD_CHAD_SUSPICIOUS               (1)
#define FRAUD_KNOWS_SCAM                    (2)

#define BREACH_NONE                         (0)
#define BREACH_LEVEL_4                      (1)
#define BREACH_LEVEL_3                      (2)
#define BREACH_LEVEL_2                      (3)
#define BREACH_LEVEL_1                      (4)

#define SIERRA_ALERT_OFF                    (0)
#define SIERRA_ALERT_ON                     (1)

#define SIERRA_PASSOWRD_UNKNOWN             (0)
#define SIERRA_PASSWORD_KNOWN               (1)

#define SIERRA_SECURITY_OFF                 (0)
#define SIERRA_SECURITY_ON                  (1)

#define BRAIN_NONE                          (0)
#define BRAIN_ABNORMAL                      (1)
#define BRAIN_CHIMP                         (2)
#define BRAIN_HUMAN                         (3)
#define BRAIN_CYBERNETIC                    (4)

#define SIERRA_LOCKOUT_FALSE                (0)
#define SIERRA_LOCKOUT_TRUE                 (1)

#define ECON_DISK_GET_DISK                  (1)
#define ECON_DISK_RECEIVED                  (2)
#define ECON_DISK_GIVEN                     (3)

#define REQ_FORM_STOLEN                     (1)
#define REQ_FORM_GIVEN                      (2)
#define REQ_FORM_JEREMY                     (3)

#define SKEETER_ASKED                       (1)
#define SKEETER_RECEIVED                    (2)

#define FESTUS_CHICKEN                      (1)
#define FESTUS_USE_PART                     (2)
#define FESTUS_CONVINCE                     (3)
#define FESTUS_MORE_CONVINCE                (4)

#define ANKH_GIVEN                          (1)
#define ANKH_TAKEN                          (2)
#define ANKH_KNOWN                          (3)

#define MCCLURE_UNKNOWN                     (0)
#define MCCLURE_KNOWN                       (1)
#define MCCLURE_CONVINCED                   (2)
#define MCCLURE_APPROVAL                    (3)

#define DOWNLOAD_HOLODISK                   (1)

#define SPEAR_GET_POWDER                    (1)
#define SPEAR_GET_FLINT                     (2)
#define SPEAR_FINISHED                      (3)

/**
 * Nagor-Smoke quest accepted
 */
#define DOG_ACCEPTED                        (1)
/**
 * Smoke found in wilderness and has joined PC
 */
#define DOG_RETURNED                        (2)
/**
 * PC told Nagor to go after Smoke himself
 */
#define DOG_RUN_OFF                         (3)
/**
 * Smoke died
 */
#define DOG_DEAD                            (4)
/**
 * Smoke returned to Nagor, quest completed
 */
#define DOG_FINISHED_GOOD                   (5)
/**
 * Smoke is dead, PC told Nagor, quest failed
 */
#define DOG_FINISHED_BAD                    (6)

#define CHAD_SUSPICIOUS                     (1)
#define CHAD_RUMOR_GECKO                    (2)
#define CHAD_RUMOR_BROKENHILLS              (3)
#define CHAD_CONFIRMED_GECKO                (4)
#define CHAD_CONFIRMED_BROKENHILLS          (5)
#define CHAD_CONFIRMED                      (6)
#define CHAD_ARRESTED                       (7)
#define CHAD_KILLED                         (8)
#define CHAD_FLED                           (9)

#define FTM_ENLISTED                        (3)
#define FTM_EXPOSED                         (5)

#define MINE_KNOWN                          (1)
#define MINE_OFFERED                        (2)
#define MINE_REWARD_CASH                    (3)
#define MINE_REWARD_FREE                    (4)
#define MINE_HAS_PARTS_CASH                 (5)
#define MINE_HAS_PARTS_FREE                 (6)
#define MINE_FIXED_CASH                     (7)
#define MINE_FIXED_FREE                     (8)
#define MINE_REWARDED                       (9)

#define JAIL_QUESTIONED                     (1)
#define JAIL_REJECTED                       (2)
#define JAIL_ENLISTED                       (3)
#define JAIL_STEALTH                        (4)
#define JAIL_FORCE                          (5)
#define JAIL_CHARISMA                       (6)
#define JAIL_DOUBLECROSS                    (7)
#define JAIL_COINCIDENTAL                   (8)

#define CONSPIRACY_BEGUN                    (1)
#define CONSPIRACY_QUESTIONED               (2)
#define CONSPIRACY_REJECTED                 (3)
#define CONSPIRACY_ACCEPTED                 (4)
#define CONSPIRACY_SUCCESSFUL               (5)
#define CONSPIRACY_FAILED                   (6)
#define CONSPIRACY_BROKEN_DOUBLECROSS       (7)
#define CONSPIRACY_BROKEN_HERO              (8)

#define MISSING_BEGUN                       (1)
#define MISSING_ACCEPT_CASH                 (2)
#define MISSING_ACCEPT_FREE                 (3)
#define MISSING_REJECT                      (4)
#define MISSING_TUNNELS_CASH                (5)
#define MISSING_TUNNELS_FREE                (6)
#define MISSING_DISCOVERED_CASH             (7)
#define MISSING_DISCOVERED_FREE             (8)
#define MISSING_FINISHED_CASH               (9)
#define MISSING_FINISHED_FREE               (10)
#define MISSING_REWARDED                    (11)

#define MIGHTY_MAN_KNOWN                    (1)
#define MIGHTY_MAN_CHALLENGED               (2)
#define MIGHTY_MAN_ACCEPTED                 (3)
#define MIGHTY_MAN_REJECTED                 (4)
#define MIGHTY_MAN_WON                      (5)
#define MIGHTY_MAN_LOST                     (6)

#define MINING_DISCOVERED                   (1)
#define MINING_SOLD                         (2)
#define MINING_RETURNED                     (3)

#define POWER_UNKNOWN                       (0)
#define POWER_KNOWN                         (1)
#define POWER_REJECTED                      (2)
#define POWER_ACCEPTED                      (3)
#define POWER_TALKED_WITH_BRIAN             (4)
#define POWER_TALKED_WITH_ERIC              (5)
#define POWER_DONE                          (6)

#define TYPHON_UNKNOWN                      (0)
#define TYPHON_GET_MAGAZINE                 (1)
#define TYPHON_GAVE_MAGAZINE                (2)
#define TYPHON_GET_BLOW_UP_DOLL             (3)
#define TYPHON_GAVE_BLOW_UP_DOLL            (4)
#define TYPHON_GET_ROTGUT                   (5)
#define TYPHON_TREASURE_TOLD                (6)
#define TYPHON_TREASURE_DOWN_WELL           (7)
#define TYPHON_TREASURE_FOUND               (8)

#define GECK_NO_QUEST                       (0)
#define GECK_ON_QUEST                       (1)
#define GECK_FOUND_GECK                     (2)
#define GECK_RETURNED_GECK                  (3)

// Caravan States
// GVAR_CARAVAN_STATUS
#define CARAVAN_STATUS_NONE                 (0)
#define CARAVAN_STATUS_WAITING              (1)
#define CARAVAN_STATUS_ON_JOB               (2)
#define CARAVAN_STATUS_SUCCESS              (3)
#define CARAVAN_STATUS_PARTIAL_SUCCESS      (4)
#define CARAVAN_STATUS_FAILED               (5)
#define CARAVAN_STATUS_TOTAL_FAILED         (6)
#define CARAVAN_STATUS_THEFT                (7)
#define CARAVAN_STATUS_ABANDONED            (8)

// GVAR_CARAVAN_START
// GVAR_CARAVAN_END
#define CARAVAN_NONE                        (0)
#define CARAVAN_REDDING                     (1)
#define CARAVAN_VAULT_CITY                  (2)
#define CARAVAN_NEW_RENO                    (3)
#define CARAVAN_NCR                         (4)
#define CARAVAN_THE_DEN                     (5)
#define CARAVAN_BROKEN_HILLS                (6)
#define CARAVAN_GECKO                       (7)
#define CARAVAN_SAN_FRANCISCO               (8)
#define CARAVAN_MODOC                       (9)
#define CARAVAN_KLAMATH                     (10)
#define CARAVAN_ARROYO                      (11)
#define CARAVAN_PRIMITIVE_TRIBE             (12)

// Redding Whore_Cut seed
#define WHORE_CUT_NONE                      (0)
#define WHORE_CUT_CUT                       (1)
#define WHORE_CUT_LET_GO                    (2)
#define WHORE_CUT_JAILED                    (3)
#define WHORE_CUT_KILLED                    (4)

// Redding Excavator Chip
#define CHIP_NONE                           (0)
#define CHIP_KNOWN                          (1)
#define CHIP_DELIVERED_MARGE                (2)
#define CHIP_DELIVERED_DAN                  (3)

// Redding Jet Level
#define JET_LOW                             (0)
#define JET_HIGH                            (1)
#define JET_ALL                             (2)
#define JET_ON_CURE                         (3)
#define JET_CURED                           (4)

// Redding Mayor Status
#define MAYOR_DEAD                          (1)
#define MARGE_DEAD                          (1)
#define DAN_DEAD                            (1)
#define JOHNSON_DEAD                        (1)

// WANAMINGO
#define WANAMINGO_WANAMINGO                 (0)
#define WANAMINGO_MORTON                    (1)
#define WANAMINGO_CLEARED_OUT               (2)

//CLEAR OUT MINE
#define DEED_ACCEPTED                       (1) //killap's code
#define CLEARED_MINE                        (2) //killap's code

//WIDOW ROONEY
#define WIDOW_JOB_ACCEPTED                  (1) //killap's code

// GVAR_BAR_BRAWL
#define BRAWL_JOB_ACCEPTED                  (1)
#define BRAWL_TALKED_BETTE                  (2) // Seraph's Code
#define BRAWL_TALKED_CAMINT                 (3) // Seraph's Code
#define BRAWL_NEITHER_JAILED                (4)
#define BRAWL_MORNINGSTAR_JAILED            (5)
#define BRAWL_KOKOWEEF_JAILED               (6)
#define BRAWL_BOTH_JAILED                   (7)
#define BRAWL_KILLED                        (8)
#define BRAWL_TALKED_BOTH                   (9) // Seraph's Code

// Frog Morton
#define FROG_JOB_ACCEPTED                   (1)
#define FROG_KNOWN                          (2)
#define FROG_DEAD                           (3)

// Morton brothers
#define MORTON_TOAD_HUNTING                 (1)
#define MORTON_TOAD_DEAD                    (2)
#define MORTON_NEWT_HUNTING                 (3)
#define MORTON_NEWT_DEAD                    (4)
#define MORTON_SNAKE_HUNTING                (5)
#define MORTON_SNAKE_DEAD                   (6)

// Redding Sheriff
#define SHERIFF_TURNED_DOWN                 (1)
#define SHERIFF_AGREED                      (2)
#define SHERIFF_FINISHED                    (3)

// Redding Caravans
#define REDDING_CARAVAN_NONE                (0)
#define REDDING_CARAVAN_AGREED              (1)
#define REDDING_CARAVAN_NOT_READY_YET       (2)
#define REDDING_CARAVAN_ABANDONED           (3)
#define REDDING_CARAVAN_ON_CARAVAN          (4)
#define REDDING_CARAVAN_TOTAL_FAILURE       (5)
#define REDDING_CARAVAN_FAILURE             (6)
#define REDDING_CARAVAN_AVERAGE_SUCCESS     (7)
#define REDDING_CARAVAN_COMPLETE_SUCCESS    (8)
#define REDDING_CARAVAN_THEFT               (9)

// NAVARRO
#define WHIRLY_NULL                         (0)
#define WHIRLY_BEGIN                        (1)
#define WHIRLY_PLANS                        (2)

// GVAR_ENCLAVE_POWER_PLANT
#define PLANT_KNOWN                         (1)

// GVAR_ENCLAVE_ALARM
#define ALARM_REACTOR                       (1)
#define ALARM_TOXIN                         (2)
#define ALARM_INTRUDER                      (3)
#define ALARM_SIREN                         (4)

// GVAR_ENCLAVE_REACTOR
#define ENCLAVE_REACTOR_ON                  (0)
#define ENCLAVE_REACTOR_OFF                 (1)

// GVAR_ENCLAVE_COMPUTER
#define COMPUTER_DESTROYED                  (1)

// Turret States
#define TURRET_NORMAL                       (0)
#define TURRET_ALERT                        (1)
#define TURRET_MAINTENANCE                  (2)

// Primitive Tribe
#define MERCHANT_START                      (1)
#define MERCHANT_BOUGHT_TRICKED             (2)
#define MERCHANT_NO_DEAL                    (3)
#define MERCHANT_BOUGHT_DISCOUNT            (4)
#define MERCHANT_REALIZE_FAKE               (5)
#define MERCHANT_DONE                       (6)
#define MERCHANT_DONE_BAD                   (7)

// San Fran

// Find sheng
#define PLANT_QUEST_DRSHENG_KNOW            (1)
#define PLANT_QUEST_FIND_DRSHENG            (2)
#define PLANT_QUEST_FOUND_DRSHENG           (3)
#define PLANT_QUEST_DR_WONG_INFORMED        (4)

// Sheng get seeds
#define PLANT_QUEST_GET_SEEDS_FOR_DRSHENG       (1)
#define PLANT_QUEST_DELIVERED_SEEDS_TO_DRSHENG  (2)

// Sheng delivered seeds
#define PLANT_QUEST_RETURN_TO_DRWONG                    (1)
#define PLANT_QUEST_RETURN_TO_DRWONG_KNOW_SEED_TRUTH    (2)
#define PLANT_QUEST_DELIVERED_SEED_SAMPLE               (3)
#define PLANT_QUEST_DELIVERED_SEED_SAMPLE_DESTROYED     (4)

// Sheng kill wong
#define PLANT_QUEST_KILL_DRWONG             (1)
#define PLANT_QUEST_KILLED_DRWONG           (2)

// Wong kill sheng
#define PLANT_QUEST_KIL_DRSHENG             (1)
#define PLANT_QUEST_KILLED_DRSHENG          (2)


// Character Modifications
#define GENDER                              (1)
#define RACE                                (2)
#define HAIR                                (3)

// SHI SUB - GVAR_SHI_SUB
#define SHI_SUB_KNOWN                   (1)
#define SHI_SUB_ALONE                   (2)
#define SHI_SUB_HAS_PASSWORD            (3)
#define SHI_SUB_WITH_CREW               (4)
#define SHI_SUB_DISABLED                (5)


// ABBEY - GVAR_ABBEY_PUMP
#define PUMP_BROKEN                   (0)
#define PUMP_QUEST_GIVEN              (1)
#define PUMP_FOUND_PROBLEM            (2)
#define PUMP_GET_PART                 (3)
#define PUMP_FIXED                    (4)
#define PUMP_REPORTED                 (5)

//GVAR_VIGNETTE_SEQUENCE States
#define SEQ_1                           (bit_1)
#define SEQ_2                           (bit_2)
#define SEQ_3                           (bit_3)

#define SEQ_1_DONE                      (bit_17)
#define SEQ_2_DONE                      (bit_18)
#define SEQ_3_DONE                      (bit_19)

#define WOOZ_TALKED                     (bit_1)
#define WOOZ_DEAD                       (bit_2)

#define ON_VAULT13_SEQ        set_gvar_bit_on(GVAR_VIGNETTE_SEQUENCE, SEQ_1)
#define VAULT13_SEQ           (gvar_bit(GVAR_VIGNETTE_SEQUENCE, SEQ_1))
#define ON_VAULT13_SEQ_DONE   set_gvar_bit_on(GVAR_VIGNETTE_SEQUENCE, SEQ_1_DONE)
#define VAULT13_SEQ_DONE      (gvar_bit(GVAR_VIGNETTE_SEQUENCE, SEQ_1_DONE))

#define ON_RND_YOUNG_SEQ      set_gvar_bit_on(GVAR_VIGNETTE_SEQUENCE, SEQ_2)
#define RND_YOUNG_SEQ         (gvar_bit(GVAR_VIGNETTE_SEQUENCE, SEQ_2))
#define ON_RND_YOURG_SEQ_DONE set_gvar_bit_on(GVAR_VIGNETTE_SEQUENCE, SEQ_2_DONE)
#define RND_YOUNG_SEQ_DONE    (gvar_bit(GVAR_VIGNETTE_SEQUENCE, SEQ_2_DONE))

#define ON_BOS_SEQ            set_gvar_bit_on(GVAR_VIGNETTE_SEQUENCE, SEQ_3)
#define BOS_SEQ               (gvar_bit(GVAR_VIGNETTE_SEQUENCE, SEQ_3))
#define ON_BOS_SEQ_DONE       set_gvar_bit_on(GVAR_VIGNETTE_SEQUENCE, SEQ_3_DONE)
#define BOS_SEQ_DONE          (gvar_bit(GVAR_VIGNETTE_SEQUENCE, SEQ_3_DONE))

/******************************************************************
      SPECIAL MACROS FOR SETTING SHARED FLAGS
 ******************************************************************/
// NEW RENO / NCR WESTIN
#define WESTIN_ACCEPT_SNUFF      bit_1
#define WESTIN_DEAD              bit_2
#define WESTIN_CANCEL_SNUFF      bit_3
#define WESTIN_DRUGS_KNOWN       bit_4
#define WESTIN_FAIL              bit_5
#define WESTIN_COMPLETE          bit_6
#define WESTIN_SNUFF_KNOWN       bit_7
#define WESTIN_KNOWN             bit_8
#define WESTIN_LENNY_TALKED      bit_9
#define WESTIN_DOC_JUB_TALKED    bit_10
#define WESTIN_PILLS_KNOW        bit_11
#define WESTIN_RENESCO_PISSED    bit_12
#define WESTIN_HEART_PILLS_DEATH bit_13
#define get_westin_flag(x)       (gvar_bit(GVAR_NEWRENO_SNUFF_WESTIN, x))
#define set_westin_flag(x)       set_gvar_bit_on(GVAR_NEWRENO_SNUFF_WESTIN, x)
#define know_westin              (get_westin_flag(WESTIN_KNOWN))
#define set_know_westin          set_westin_flag(WESTIN_KNOWN)
#define westin_dead              (get_westin_flag(WESTIN_DEAD))

// NEW RENO / NCR CARLSON

#define CARLSON_ACCEPT_SNUFF     bit_1
#define CARLSON_DEAD             bit_2
#define CARLSON_SECURITY_DUTY    bit_3
#define CARLSON_CANCEL_SNUFF     bit_4
#define CARLSON_COMPLETE         bit_5
#define CARLSON_FAIL             bit_6
#define CARLSON_GATE_CLOSED      bit_7
#define get_carlson_flag(x)      (gvar_bit(GVAR_NEWRENO_SNUFF_CARLSON, x))
#define set_carlson_flag(x)      set_gvar_bit_on(GVAR_NEWRENO_SNUFF_CARLSON, x)
#define carlson_dead             (get_carlson_flag(CARLSON_DEAD))

// NEW RENO / NCR BISHOP
#define BISHOP_ACCEPT_SNUFF     bit_1
#define BISHOP_DEAD             bit_2
#define BISHIP_ASSASSINATED     bit_3
#define BISHOP_CANCEL_SNUFF     bit_4
#define BISHOP_COMPLETE         bit_5
#define get_bishop_flag(x)      (global_var(GVAR_NCR_SNUFF_BISHOP) bwand x)
#define set_bishop_flag(x)      set_global_var(GVAR_NCR_SNUFF_BISHOP, global_var(GVAR_NCR_SNUFF_BISHOP) bwor x)

// Mysterious Stranger Flags
#define STRANGER_DEAD           bit_1
#define STRANGER_GENDER         bit_2
#define STRANGER_FEMALE         bit_3
#define get_stranger_flag(x)    (global_var(GVAR_MYSTERIOUS_STRANGER) bwand x)
#define set_stranger_flag(x)    set_global_var(GVAR_MYSTERIOUS_STRANGER, global_var(GVAR_MYSTERIOUS_STRANGER) bwor x)

/******************************************************************/



/********************************************************************
*******************   Game time Limits   ****************************
********************************************************************/

#ifndef TIME_LIMIT_1
#define TIME_LIMIT_1                        (90)
#endif
#ifndef TIME_LIMIT_2
#define TIME_LIMIT_2                        (180)
#endif
#ifndef TIME_LIMIT_3
#define TIME_LIMIT_3                        (270)
#endif
#ifndef TIME_LIMIT_4
#define TIME_LIMIT_4                        (360)
#endif

#define reached_tl_1                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_1)
#define reached_tl_2                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_2)
#define reached_tl_3                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_3)
#define reached_tl_4                        (GAME_TIME_IN_DAYS >= TIME_LIMIT_4)

//Kaga macros Rob the only one you probably care about is the dead macro
#define KAGA_BG   bit_1
#define KAGA_1    bit_2   //Encounter 1 with kaga
#define KAGA_2    bit_3
#define KAGA_3    bit_4
#define KAGA_4    bit_5
#define KAGA_5    bit_6
#define KAGA_MET  bit_7
#define KAGA_DEAD bit_8

#define set_kaga_1     set_global_var(GVAR_RND_KAGA_STATE, global_var(GVAR_RND_KAGA_STATE) bwor KAGA_1)
#define set_kaga_2     set_global_var(GVAR_RND_KAGA_STATE, global_var(GVAR_RND_KAGA_STATE) bwor KAGA_2)
#define set_kaga_3     set_global_var(GVAR_RND_KAGA_STATE, global_var(GVAR_RND_KAGA_STATE) bwor KAGA_3)
#define set_kaga_4     set_global_var(GVAR_RND_KAGA_STATE, global_var(GVAR_RND_KAGA_STATE) bwor KAGA_4)
#define set_kaga_5     set_global_var(GVAR_RND_KAGA_STATE, global_var(GVAR_RND_KAGA_STATE) bwor KAGA_5)
#define set_kaga_dead  set_global_var(GVAR_RND_KAGA_STATE, global_var(GVAR_RND_KAGA_STATE) bwor KAGA_DEAD)
#define set_kaga_met   set_global_var(GVAR_RND_KAGA_STATE, global_var(GVAR_RND_KAGA_STATE) bwor KAGA_MET)
#define set_kaga_bg    set_global_var(GVAR_RND_KAGA_STATE, global_var(GVAR_RND_KAGA_STATE) bwor KAGA_BG)

#define kaga_1     (global_var(GVAR_RND_KAGA_STATE) bwand KAGA_1)
#define kaga_2     (global_var(GVAR_RND_KAGA_STATE) bwand KAGA_2)
#define kaga_3     (global_var(GVAR_RND_KAGA_STATE) bwand KAGA_3)
#define kaga_4     (global_var(GVAR_RND_KAGA_STATE) bwand KAGA_4)
#define kaga_5     (global_var(GVAR_RND_KAGA_STATE) bwand KAGA_5)
#define kaga_dead  (global_var(GVAR_RND_KAGA_STATE) bwand KAGA_DEAD)
#define kaga_met   (global_var(GVAR_RND_KAGA_STATE) bwand KAGA_MET)
#define kaga_bg    (global_var(GVAR_RND_KAGA_STATE) bwand KAGA_BG)

#endif // _GLOBAL_H_DEFINED2 O0)  (1O9 )_ _ LI ( DW1O  (
