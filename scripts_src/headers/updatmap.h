/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef UPDATMAP_H
#define UPDATMAP_H

// Lighting Information
#define BRIGHT_LIGHT                    (100)
#define CAVERN_LIGHT                    (49)
#define DUSK_LIGHT                      (49)
#define ENCLAVE_LIGHT                   (60)
#define INDOOR_LIGHT                    (60)
#define BASEMENT_LIGHT                  (50)
#define MILITARY_BASE_LIGHTING          (50)

#define WINTER_MORNING                  (700)
#define SPRING_MORNING                  (600)
#define SUMMER_MORNING                  (500)
#define FALL_MORNING                    (600)

#define WINTER_EVENING                  (1700)
#define SPRING_EVENING                  (1800)
#define SUMMER_EVENING                  (1900)
#define FALL_EVENING                    (1800)

#define season_morning(when)            ((game_time_hour >= (when)) and (game_time_hour < (when + 100)))
#define season_day(sunrise,sunset)      ((game_time_hour >= (sunrise + 100)) and (game_time_hour < sunset))
#define season_evening(when)            ((game_time_hour >= (when)) and (game_time_hour < (when + 100)))

#define Spring_Lighting                 if (season_morning(SPRING_MORNING)) then                                \
                                            set_light_level((game_time_hour - SPRING_MORNING) + DUSK_LIGHT);    \
                                        else if (season_day(SPRING_MORNING,SPRING_EVENING)) then                \
                                            set_light_level(100);                                               \
                                        else if (season_evening(SPRING_EVENING)) then                           \
                                            set_light_level(BRIGHT_LIGHT - (game_time_hour - SPRING_EVENING));  \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT)

#define Summer_Lighting                 if (season_morning(SUMMER_MORNING)) then                                \
                                            set_light_level((game_time_hour - SUMMER_MORNING) + DUSK_LIGHT);    \
                                        else if (season_day(SUMMER_MORNING,SUMMER_EVENING)) then                \
                                            set_light_level(100);                                               \
                                        else if (season_evening(SUMMER_EVENING)) then                           \
                                            set_light_level(BRIGHT_LIGHT - (game_time_hour - SUMMER_EVENING));  \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT)

#define Fall_Lighting                   if (season_morning(FALL_MORNING)) then                                  \
                                            set_light_level((game_time_hour - FALL_MORNING) + DUSK_LIGHT);      \
                                        else if (season_day(FALL_MORNING,FALL_EVENING)) then                    \
                                            set_light_level(100);                                               \
                                        else if (season_evening(FALL_EVENING)) then                             \
                                            set_light_level(BRIGHT_LIGHT - (game_time_hour - FALL_EVENING));    \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT)

#define Winter_Lighting                 if (season_morning(WINTER_MORNING)) then                                \
                                            set_light_level((game_time_hour - WINTER_MORNING) + DUSK_LIGHT);    \
                                        else if (season_day(WINTER_MORNING,WINTER_EVENING)) then                \
                                            set_light_level(100);                                               \
                                        else if (season_evening(WINTER_EVENING)) then                           \
                                            set_light_level(BRIGHT_LIGHT - (game_time_hour - WINTER_EVENING));  \
                                        else                                                                    \
                                            set_light_level(DUSK_LIGHT)

#define Lighting                        if ((get_month >= 3) and (get_month < 5)) then                          \
                                            Spring_Lighting;                                                    \
                                        else if ((get_month >= 5) and (get_month < 9)) then                     \
                                            Summer_Lighting;                                                    \
                                        else if ((get_month >= 9) and (get_month < 11)) then                    \
                                            Fall_Lighting;                                                      \
                                        else                                                                    \
                                            Winter_Lighting

#define Darkness                        set_light_level(DUSK_LIGHT)

#define Cavern_Lighting                 set_light_level(CAVERN_LIGHT)

#define Full_Light                      set_light_level(BRIGHT_LIGHT)

#define Enclave_Lighting                set_light_level(ENCLAVE_LIGHT)

#define Indoor_Lighting                 set_light_level(INDOOR_LIGHT)

#define Basement_Lighting               set_light_level(BASEMENT_LIGHT)

#define Military_Base_Lighting          set_light_level(MILITARY_BASE_LIGHTING)

#define set_cur_exit                    wm_area_set_pos(AREA_RND_MOUNTAIN,worldmap_xpos,worldmap_ypos)

// Car Information
//        City Car is At                Tile Num For Car
#define CAR_ARROYO_HEX                      (27312)
#define CAR_DENBUS1_HEX                     (11687)
#define CAR_DENBUS2_HEX                     (29103)
#define CAR_UNCLAIMED_HEX                   (24548)  // When you don't have the car
#define CAR_KLAMATH_HEX                     (25669)
#define CAR_MODOC_HEX                       (24531)
#define CAR_VAULT_CITY_HEX                  (28899)
#define CAR_GECKO_HEX                       (25516)  // edit by killap - was 25709
#define CAR_BROKEN_HILLS_HEX                (17752)
#define CAR_NEW_RENO1_HEX                   (25321)
#define CAR_NEW_RENO2_HEX                   (9509)
#define CAR_NEW_RENO3_HEX                   (30894)
#define CAR_NEW_RENO4_HEX                   (16068)
#define CAR_NEW_RENO_CHOP_SHOP_HEX          (18699)
#define CAR_SIERRA_ARMY_BASE_HEX            (28699)
#define CAR_VAULT_15_HEX                    (26932)
#define CAR_VAULT_15_DEAL_HEX               (29718)
#define CAR_NCR_HEX                         (23078)
#define CAR_VAULT_13_HEX                    (26354)
#define CAR_MILITARY_BASE_HEX               (22146)
#define CAR_REDDING_HEX                     (18650)
#define CAR_SAN_FRANCISCO_HEX               (31699)
#define CAR_NAVARRO_HEX                     (27686)

#define CAR_THE_ENCLAVE_HEX                 (20100)
#define CAR_ABBEY_HEX                       (23520)
#define CAR_PRIMITIVE_TRIBE_HEX             (29487)
#define CAR_EPA_HEX                         (30104)

#define CAR_GHOST_TOWN_HEX                  (23951)
#define CAR_ARROYO_DESTROYED_HEX            (27312)
#define CAR_KLAMATH_TOXIC_CAVES_HEX         (18340)  // edit by killap - was 18341
#define CAR_DEN_SLAVE_RUN_HEX               (26514)
#define CAR_RAIDERS_CAMP_HEX_NORMAL         (25304)
#define CAR_RAIDERS_CAMP_HEX_SECRET         (24089)  // edit by killap - was 21298
#define CAR_GOLGATHA_HEX                    (22500)
#define CAR_CARAVAN_HEX                     (21307)
#define CAR_CAR_OUTTA_GAS_HEX               (19100)
#define CAR_RENO_STABLES_HEX                (26506)

#define CAR_RANDOM_DESERT_HEX               (20106)
#define CAR_RANDOM_COAST_HEX                (20106)
#define CAR_RANDOM_MOUNTAIN_HEX             (18909)

#define CAR_RND_DESERT1_HEX                 (19096)
#define CAR_RND_DESERT2_HEX                 (19094)
#define CAR_RND_DESERT3_HEX                 (18894)
#define CAR_RND_DESERT4_HEX                 (19718)
#define CAR_RND_DESERT5_HEX                 (24112)
#define CAR_RND_DESERT6_HEX                 (18914)
#define CAR_RND_DESERT7_HEX                 (24525)
#define CAR_RND_DESERT8_HEX                 (17890)
#define CAR_RND_DESERT9_HEX                 (22880)
#define CAR_RND_DESERT10_HEX                (22880)
#define CAR_RND_DESERT11_HEX                (20692)
#define CAR_RND_DESERT12_HEX                (21308)
#define CAR_RND_DESERT13_HEX                (17261)
//#define CAR_RND_DESERT13_HEX                (17896)

#define CAR_RND_MOUNTAIN1_HEX               (18881)  // edit by killap - was 17875
#define CAR_RND_MOUNTAIN2_HEX               (18276)  // edit by killap - was 17876
#define CAR_RND_MOUNTAIN3_HEX               (19478)
#define CAR_RND_MOUNTAIN4_HEX               (19099)
#define CAR_RND_MOUNTAIN5_HEX               (20877)  // edit by killap - was 20678
#define CAR_RND_MOUNTAIN6_HEX               (20073)

#define CAR_RND_CAVE1_HEX                   (26508)
#define CAR_RND_CAVE2_HEX                   (24706)
#define CAR_RND_CAVE3_HEX                   (24915)
#define CAR_RND_CAVE4_HEX                   (27512)
#define CAR_RND_CAVE5_HEX                   (26292)
#define CAR_RND_CAVE6_HEX                   (21681)
#define CAR_RND_CAVE7_HEX                   (19078)

#define CAR_RND_CITY1_HEX                   (12693)
#define CAR_RND_CITY2_HEX                   (9898)
#define CAR_RND_CITY3_HEX                   (23542)
#define CAR_RND_CITY4_HEX                   (28089)
#define CAR_RND_CITY5_HEX                   (20464)
#define CAR_RND_CITY6_HEX                   (29496)
#define CAR_RND_CITY7_HEX                   (19535)
#define CAR_RND_CITY8_HEX                   (21702)

#define CAR_RND_COAST1_HEX                  (18086)
#define CAR_RND_COAST2_HEX                  (19089)
#define CAR_RND_COAST3_HEX                  (19279)
#define CAR_RND_COAST4_HEX                  (19278)
#define CAR_RND_COAST5_HEX                  (23500)
#define CAR_RND_COAST6_HEX                  (22291)
#define CAR_RND_COAST7_HEX                  (16518)
#define CAR_RND_COAST8_HEX                  (23718)
#define CAR_RND_COAST9_HEX                  (21107)
#define CAR_RND_COAST10_HEX                 (17919)
#define CAR_RND_COAST11_HEX                 (20079)
#define CAR_RND_COAST12_HEX                 (25515)

#define CAR_RND_WHALE_HEX                   (23109)
#define CAR_RND_WOODSMAN_HEX                (18724)
//#define CAR_RND_BIG_HEAD_HEX                (24316)
#define CAR_RND_VILLAGERS_HEX               (19095)
#define CAR_RND_SHUTTLE_HEX                 (20702)
#define CAR_RND_BRIDGE_HEX                  (18095)
#define CAR_RND_CAFE_HEX                    (23903)
#define CAR_RND_HOLY1_HEX                   (21936)
#define CAR_RND_HOLY2_HEX                   (20880)
#define CAR_RND_FOREVER_HEX                 (18904)
#define CAR_RND_TOXIC_HEX                   (22101)
#define CAR_RND_MAD_BRAHMIN_HEX             (18889)
#define CAR_RND_PARIAH_HEX                  (23125)
#define CAR_RND_BHEAD_HEX                   (22726)
#define CAR_RND_BESS_HEX                    (27318)

#define CAR_GAMMOVIE_HEX                    (25523)


//Slaver Camp
#define CAR_SLAVER_CAMP_HEX                 (22480)

//Hubologist Stash
#define HUBOLOGIST_STASH_HEX                (27732)

//Gecko Enclave Encounter
#define GECKO_ENCLAVE_HEX                   (25326)

//Vault Village
#define CAR_VAULT_VILLAGE_HEX               (27525)

//Kaga Encounters

//Ranger Safe houses
#define CAR_RNGR_SAFE_HOUSE2                (21894)

//RP Easter Egg Map
#define CAR_RP_EASTER_EGG_HEX               (23311)

//Dr. Sheng Hideout
#define CAR_SAN_FRANCISCO_DR_SHENG_HEX      (17535)


//        City Car is At               Elevation For Car
#define CAR_ARROYO_ELEV                     (0)
#define CAR_DEN_ELEV                        (0)
#define CAR_KLAMATH_ELEV                    (0)
#define CAR_MODOC_ELEV                      (0)
#define CAR_VAULT_CITY_ELEV                 (0)
#define CAR_GECKO_ELEV                      (0)
#define CAR_RAIDERS_CAMP_ELEV_NORMAL        (0)
#define CAR_RAIDERS_CAMP_ELEV_SECRET        (1)
#define CAR_BROKEN_HILLS_ELEV               (0)
#define CAR_NEW_RENO_ELEV                   (0)
#define CAR_SIERRA_ARMY_BASE_ELEV           (0)
#define CAR_VAULT_15_ELEV                   (0)
#define CAR_VAULT_15_DEAL_ELEV              (1)
#define CAR_NCR_ELEV                        (0)
#define CAR_VAULT_13_ELEV                   (0)
#define CAR_MILITARY_BASE_ELEV              (0)
#define CAR_REDDING_ELEV                    (0)
#define CAR_SAN_FRANCISCO_ELEV              (0)
#define CAR_NAVARRO_ELEV                    (0)
#define CAR_THE_ENCLAVE_ELEV                (0)
#define CAR_ABBEY_ELEV                      (0)
#define CAR_PRIMITIVE_TRIBE_ELEV            (0)
#define CAR_EPA_ELEV                        (0)
#define CAR_GHOST_TOWN_ELEV                 (0)
#define CAR_CAR_OUTTA_GAS_ELEV              (0)
#define CAR_ARROYO_DESTROYED_ELEV           (0)
#define CAR_KLAMATH_TOXIC_CAVES_ELEV        (0)
#define CAR_RANDOM_DESERT_ELEV              (0)
#define CAR_RANDOM_COAST_ELEV               (0)
#define CAR_RANDOM_MOUNTAIN_ELEV            (0)
#define CAR_UNCLAIMED_ELEV                  (0)
#define CAR_GOLGATHA_ELEV                   (0)
#define CAR_RENO_STABLES_ELEV               (0)
#define CAR_GAMMOVIE_ELEV                   (0)
#define CAR_RND_TOXIC_ELEV                  (0)
#define CAR_RND_WOODSMAN_ELEV               (0)
#define CAR_RND_WHALE_ELEV                  (0)
#define CAR_RND_VILLAGERS_ELEV              (0)
#define CAR_RND_SHUTTLE_ELEV                (0)
#define CAR_RND_PARIAH_ELEV                 (0)
#define CAR_RND_BHEAD_ELEV                  (0)
#define CAR_RND_CAFE_ELEV                   (0)
#define CAR_SLAVER_CAMP_ELEV                (0)
#define CAR_RP_EASTER_EGG_ELEV              (0)
#define CAR_SAN_FRANCISCO_DR_SHENG_ELEV     (0)

#endif // UPDATMAP_H
