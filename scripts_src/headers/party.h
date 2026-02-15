/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef PARTY_H
#define PARTY_H

/***************************************************************
    The following contain all of the Party information and
    commands for Fallout 2
***************************************************************/

#define FOLLOW_DISTANCE_CLOSE               (3)
#define FOLLOW_DISTANCE_MEDIUM              (6)
#define FOLLOW_DISTANCE_FAR                 (9)

#define obj_in_party(x)                     (party_member_obj(obj_pid(x)) != 0)
// Pointers to the Party Members
#define Vic_Ptr                             party_member_obj(PID_VIC)
#define Myron_Ptr                           party_member_obj(PID_MYRON)
#define Marcus_Ptr                          party_member_obj(PID_MARCUS)
#define MacRae_Ptr                          party_member_obj(PID_JOHN_MACRAE)
#define Sulik_Ptr                           party_member_obj(PID_SULIK)
#define Lenny_Ptr                           party_member_obj(PID_LENNY)
#define Cyberdog_Ptr                        party_member_obj(PID_CYBERDOG)
#define Doc_Ptr                             party_member_obj(PID_DOC)
#define Goris_Ptr                           party_member_obj(PID_GORIS)
#define Davin_Ptr                           party_member_obj(PID_DAVIN)
#define Miria_Ptr                           party_member_obj(PID_MIRIA)
#define Robobrain_Ptr                       party_member_obj(PID_BRAINBOT)
#define Trunk_Ptr                           party_member_obj(PID_CAR_TRUNK)
#define Dogmeat_Ptr                         party_member_obj(PID_DOGMEAT)
#define Pariah_Dog_Ptr                      party_member_obj(PID_PARIAH_DOG) // temp
#define K9_Ptr                              party_member_obj(PID_K9)
#define Robobrain_Human_Ptr                 party_member_obj(PID_ROBOBRAIN_HUMAN)
#define Robobrain_Abnormal_Ptr              party_member_obj(PID_ROBOBRAIN_ABNORMAL)
#define Robobrain_Chimp_Ptr                 party_member_obj(PID_ROBOBRAIN_CHIMP)
// temporary/invisible party members
#define Laddie_Ptr                          party_member_obj(PID_LADDIE)
#define Bess_Ptr                            party_member_obj(PID_BESS)
#define Chicken_Ptr                         party_member_obj(PID_CHICKEN)
#define Karl_Ptr                            party_member_obj(PID_KARL)
#define Jonny_Ptr                           party_member_obj(PID_JONNY)
#define Lloyd_Ptr                           party_member_obj(PID_LLOYD)
#define Kitsune_Ptr                         party_member_obj(PID_KITSUNE)
#define Dex_Ptr                             party_member_obj(PID_DEX)
#define Cat_Jules_Ptr                       party_member_obj(PID_CAT_JULES)


// Is this person in my party
#define Vic_In_Party                        (Vic_Ptr != 0)
#define Myron_In_Party                      (Myron_Ptr != 0)
#define Marcus_In_Party                     (Marcus_Ptr != 0)
#define MacRae_In_Party                     (MacRae_Ptr != 0)
#define Sulik_In_Party                      (Sulik_Ptr != 0)
#define Lenny_In_Party                      (Lenny_Ptr != 0)
#define Cyberdog_In_Party                   (Cyberdog_Ptr != 0)
#define Doc_In_Party                        (Doc_Ptr != 0)
#define Goris_In_Party                      (Goris_Ptr != 0)
#define Davin_In_Party                      (Davin_Ptr != 0)
#define Miria_In_Party                      (Miria_Ptr != 0)
#define Robobrain_In_Party                  (Robobrain_Ptr != 0)
#define Dogmeat_In_Party                    (Dogmeat_Ptr != 0)
#define Pariah_Dog_In_Party                 (Pariah_Dog_Ptr != 0)
#define K9_In_Party                         (K9_Ptr != 0)
#define Robobrain_Human_In_Party            (Robobrain_Human_Ptr != 0)
#define Robobrain_Abnormal_In_Party         (Robobrain_Abnormal_Ptr != 0)
#define Robobrain_Chimp_In_Party            (Robobrain_Chimp_Ptr != 0)
// temporary/invisible party members
#define Laddie_In_Party                     (Laddie_Ptr != 0)
#define Bess_In_Party                       (Bess_Ptr != 0)
#define Chicken_In_Party                    (Chicken_Ptr != 0)
#define Karl_In_Party                       (Karl_Ptr != 0)
#define Jonny_In_Party                      (Jonny_Ptr != 0)
#define Lloyd_In_Party                      (Lloyd_Ptr != 0)
#define Kitsune_In_Party                    (Kitsune_Ptr != 0)
#define Dex_In_Party                        (Dex_Ptr != 0)
#define Cat_Jules_In_Party                  (Cat_Jules_Ptr != 0)

// Party Size Information
#define party_size                          (party_member_count(DONT_LIST_HIDDEN_MEMBERS) - Laddie_In_Party - Bess_In_Party)
#define true_party_size                     (party_size - 1)
#define party_max_formula                   (floor(dude_charisma/2) + (has_trait(TRAIT_PERK,dude_obj,PERK_magnetic_personality_perk)))
#define dude_at_max_party_size              ((true_party_size >= (party_max_formula)) or (true_party_size >= 5))
#define party_size_male                     (Vic_In_Party+Myron_In_Party+Marcus_In_Party+MacRae_In_Party+Sulik_In_Party+Lenny_In_Party+Doc_In_Party+Goris_In_Party+Davin_In_Party+Dex_In_Party+Cat_Jules_In_Party)
#define party_size_female                   (Miria_In_Party+Kitsune_In_Party)
#define party_size_strange                  (Marcus_In_Party+Lenny_In_Party+Cyberdog_In_Party+Goris_In_Party+K9_In_Party+Robobrain_In_Party)
#define party_size_biped                    (party_size_male + party_size_female)

// Health of Party Members
#define Is_Injured(Who)                     (get_critter_stat(Who, STAT_current_hp) < get_critter_stat(Who, STAT_max_hp))
#define Injured_How_Much(Who)               (get_critter_stat(Who, STAT_max_hp) - get_critter_stat(Who, STAT_current_hp))
#define Is_Crippled(Who)                    (critter_state(Who) BWAND (DAM_CRIP_LEG_LEFT BWOR DAM_CRIP_LEG_RIGHT BWOR DAM_CRIP_ARM_LEFT BWOR DAM_CRIP_ARM_RIGHT))
#define Is_Blind(Who)                       (critter_state(Who) BWAND DAM_BLIND)
//#define Is_Armed(Who)                       (((obj_item_subtype(critter_inven_obj(Who,INVEN_TYPE_RIGHT_HAND))) == item_type_weapon)       \
//                                            or ((obj_item_subtype(critter_inven_obj(Who,INVEN_TYPE_LEFT_HAND))) == item_type_weapon))
#define Is_Armed(Who)                       (((obj_item_subtype(critter_inven_obj(Who,INVEN_TYPE_RIGHT_HAND))) == item_type_weapon))

#define Party_Childkiller_Mask              (bit_2 BWOR bit_4 BWOR bit_6 BWOR bit_8 BWOR bit_10 BWOR bit_12 BWOR bit_14 BWOR    \
                                             bit_16 BWOR bit_18 BWOR bit_20 BWOR bit_22 BWOR bit_24 BWOR bit_26 BWOR bit_28     \
                                             BWOR bit_30 BWOR bit_32)

#define attempt_place_party_member(the_obj, the_tile, the_elev)            \
         if (the_obj != 0) then begin                                      \
            if (obj_is_visible_flag(the_obj)) then begin                   \
               critter_attempt_placement(the_obj, the_tile, the_elev);     \
            end                                                            \
         end
#define attempt_place_party(the_tile, the_elev)                                     \
         attempt_place_party_member(Vic_Ptr, the_tile, the_elev)                    \
         attempt_place_party_member(Myron_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Marcus_Ptr, the_tile, the_elev)                 \
         attempt_place_party_member(MacRae_Ptr, the_tile, the_elev)                 \
         attempt_place_party_member(Sulik_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Lenny_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Cyberdog_Ptr, the_tile, the_elev)               \
         attempt_place_party_member(Doc_Ptr, the_tile, the_elev)                    \
         attempt_place_party_member(Goris_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Davin_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Miria_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Robobrain_Ptr, the_tile, the_elev)              \
         attempt_place_party_member(Trunk_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Dogmeat_Ptr, the_tile, the_elev)                \
         attempt_place_party_member(Pariah_Dog_Ptr, the_tile, the_elev)             \
         attempt_place_party_member(K9_Ptr, the_tile, the_elev)                     \
         attempt_place_party_member(Robobrain_Human_Ptr, the_tile, the_elev)        \
         attempt_place_party_member(Robobrain_Abnormal_Ptr, the_tile, the_elev)     \
         attempt_place_party_member(Robobrain_Chimp_Ptr, the_tile, the_elev)        \
         attempt_place_party_member(Laddie_Ptr, the_tile, the_elev)                 \
         attempt_place_party_member(Bess_Ptr, the_tile, the_elev)                   \
         attempt_place_party_member(Chicken_Ptr, the_tile, the_elev)                \
         attempt_place_party_member(Karl_Ptr, the_tile, the_elev)                   \
         attempt_place_party_member(Jonny_Ptr, the_tile, the_elev)                  \
         attempt_place_party_member(Kitsune_Ptr, the_tile, the_elev)                \
         attempt_place_party_member(Dex_Ptr, the_tile, the_elev)                    \
         attempt_place_party_member(Cat_Jules_Ptr, the_tile, the_elev)              \
         attempt_place_party_member(Lloyd_Ptr, the_tile, the_elev)


//#define Party_Childkiller                   (global_var(GVAR_PARTY_CHILDKILLER) BWAND Party_Childkiller_Mask)

#define Childkiller_Vic                     ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_2) and (Vic_Ptr != 0))
#define Childkiller_Myron                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_4) and (Myron_Ptr != 0))
#define Childkiller_Marcus                  ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_6) and (Marcus_Ptr != 0))
#define Childkiller_MacRae                  ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_8) and (MacRae_Ptr != 0))
#define Childkiller_Sulik                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_10) and (Sulik_Ptr != 0))
#define Childkiller_Lenny                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_12) and (Lenny_Ptr != 0))
#define Childkiller_Cyberdog                ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_14) and (Cyberdog_Ptr != 0))
#define Childkiller_Doc                     ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_16) and (Doc_Ptr != 0))
#define Childkiller_Goris                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_18) and (Goris_Ptr != 0))
#define Childkiller_Davin                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_20) and (Davin_Ptr != 0))
#define Childkiller_Miria                   ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_22) and (Miria_Ptr != 0))
#define Childkiller_Laddie                  ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_24) and (Laddie_Ptr != 0))
#define Childkiller_Robobrain               ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_26) and (Robobrain_Ptr != 0))
#define Childkiller_Bess                    ((global_var(GVAR_PARTY_CHILDKILLER) BWAND bit_28) and (Bess_Ptr != 0))

#define Party_Childkiller                   (Childkiller_Vic or Childkiller_Myron or Childkiller_Marcus or Childkiller_MacRae or  \
                                             Childkiller_Sulik or Childkiller_Lenny or Childkiller_Cyberdog or Childkiller_Doc or \
                                             Childkiller_Goris of Childkiller_Davin or Childkiller_Miria of Childkiller_Laddie or \
                                             Childkiller_Robobrain or Childkiller_Bess)

//#define inc_party_childkiller(who)          if () then

variable PartyHealingItem;

#define obj_heal_time(x)                     if (x > 0) then begin        \
                                                game_time_advance(x);     \
                                             end

#define obj_heal(who)                        if (obj_is_carrying_obj_pid(who,PID_SUPER_STIMPAK)) then begin                     \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                PartyHealingItem:=obj_carrying_pid_obj(who,PID_SUPER_STIMPAK);                  \
                                                use_obj_on_obj(PartyHealingItem,who);                                           \
                                                ndebug(obj_name(who)+" used super stimpak.");                                   \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_STIMPAK)) then begin                      \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_STIMPAK),who);                      \
                                                ndebug(obj_name(who)+" used stimpak.");                                         \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_HEALING_POWDER)) then begin               \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_HEALING_POWDER),who);               \
                                                ndebug(obj_name(who)+" used healing powder.");                                  \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_DOCTORS_BAG)) then begin                  \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_DOCTORS_BAG),who);                  \
                                                ndebug(obj_name(who)+" used doctor's bag kit.");                                \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_FIRST_AID_KIT)) then begin                \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_FIRST_AID_KIT),who);                \
                                                ndebug(obj_name(who)+" used First Aid kit.");                                   \
                                             end                                                                                \
                                             else if (has_skill(who,SKILL_DOCTOR) > has_skill(who,SKILL_FIRST_AID)) then begin  \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(ONE_GAME_HOUR)                                                 \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                if (is_success(roll_vs_skill(who,SKILL_DOCTOR,0))) then begin                   \
                                                    critter_heal(who,random(10,25));                                            \
                                                    ndebug(obj_name(who)+" healed some using doctor skill.");                   \
                                                end                                                                             \
                                             end                                                                                \
                                             else begin                                                                         \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(15*ONE_GAME_MINUTE)                                            \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                if (is_success(roll_vs_skill(who,SKILL_FIRST_AID,0))) then begin                \
                                                    critter_heal(who,random(5,15));                                             \
                                                    ndebug(obj_name(who)+" healed some using first aid skill.");                \
                                                end                                                                             \
                                             end

#define obj_heal_no_skill(who)               if (obj_is_carrying_obj_pid(who,PID_SUPER_STIMPAK)) then begin                     \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                PartyHealingItem:=obj_carrying_pid_obj(who,PID_SUPER_STIMPAK);                  \
                                                use_obj_on_obj(PartyHealingItem,who);                                           \
                                                ndebug(obj_name(who)+" used super stimpak.");                                   \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_STIMPAK)) then begin                      \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_STIMPAK),who);                      \
                                                ndebug(obj_name(who)+" used stimpak.");                                         \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_HEALING_POWDER)) then begin               \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_HEALING_POWDER),who);               \
                                                ndebug(obj_name(who)+" used healing powder.");                                  \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_DOCTORS_BAG)) then begin                  \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_DOCTORS_BAG),who);                  \
                                                ndebug(obj_name(who)+" used doctor's bag kit.");                                \
                                             end                                                                                \
                                             else if (obj_is_carrying_obj_pid(who,PID_FIRST_AID_KIT)) then begin                \
                                                if ((global_temp == 0) and (combat_is_initialized == false)) then begin         \
                                                   gfade_out(600);                                                              \
                                                   obj_heal_time(0)                                                             \
                                                   gfade_in(600);                                                               \
                                                end                                                                             \
                                                use_obj_on_obj(obj_carrying_pid_obj(who,PID_FIRST_AID_KIT),who);                \
                                                ndebug(obj_name(who)+" used First Aid kit.");                                   \
                                             end



//Hiding party members, by Chris Holland
//GVAR_PARTY_MEMBERS_HIDDEN

/*

#define set_p_hidden_flag_obj(x, the_ptr, the_bit)                   \
         if (x == the_ptr) then begin                                \
            set_gvar_bit_on(GVAR_PARTY_MEMBERS_HIDDEN, the_bit);     \
         end
#define set_p_hidden_flag(x)                                                                    \
         set_p_hidden_flag_obj(x, Vic_Ptr, hidden_vic_bit)                                      \
         else set_p_hidden_flag_obj(x, Myron_Ptr, hidden_myron_bit)                             \
         else set_p_hidden_flag_obj(x, Marcus_Ptr, hidden_marcus_bit)                           \
         else set_p_hidden_flag_obj(x, MacRae_Ptr, hidden_macrae_bit)                           \
         else set_p_hidden_flag_obj(x, Sulik_Ptr, hidden_sulik_bit)                             \
         else set_p_hidden_flag_obj(x, Lenny_Ptr, hidden_lenny_bit)                             \
         else set_p_hidden_flag_obj(x, Cyberdog_Ptr, hidden_cyberdog_bit)                       \
         else set_p_hidden_flag_obj(x, Doc_Ptr, hidden_doc_bit)                                 \
         else set_p_hidden_flag_obj(x, Goris_Ptr, hidden_goris_bit)                             \
         else set_p_hidden_flag_obj(x, Davin_Ptr, hidden_davin_bit)                             \
         else set_p_hidden_flag_obj(x, Miria_Ptr, hidden_miria_bit)                             \
         else set_p_hidden_flag_obj(x, Robobrain_Ptr, hidden_robobrain_bit)                     \
         else set_p_hidden_flag_obj(x, Dogmeat_Ptr, hidden_dogmeat_bit)                         \
         else set_p_hidden_flag_obj(x, Pariah_Dog_Ptr, hidden_pariah_dog_bit)                   \
         else set_p_hidden_flag_obj(x, K9_Ptr, hidden_k9_bit)                                   \
         else set_p_hidden_flag_obj(x, Robobrain_Human_Ptr, hidden_robobrain_human_bit)         \
         else set_p_hidden_flag_obj(x, Robobrain_Abnormal_Ptr, hidden_robobrain_abnormal_bit)   \
         else set_p_hidden_flag_obj(x, Robobrain_Chimp_Ptr, hidden_robobrain_chimp_bit)

#define unset_p_hidden_flag_obj(x, the_ptr, the_bit)                    \
         if (x == the_ptr) then begin                                   \
            set_gvar_bit_off(GVAR_PARTY_MEMBERS_HIDDEN, the_bit);       \
         end
#define unset_p_hidden_flag(x)                                                                     \
         unset_p_hidden_flag_obj(x, Vic_Ptr, hidden_vic_bit)                                       \
         else unset_p_hidden_flag_obj(x, Myron_Ptr, hidden_myron_bit)                              \
         else unset_p_hidden_flag_obj(x, Marcus_Ptr, hidden_marcus_bit)                            \
         else unset_p_hidden_flag_obj(x, MacRae_Ptr, hidden_macrae_bit)                            \
         else unset_p_hidden_flag_obj(x, Sulik_Ptr, hidden_sulik_bit)                              \
         else unset_p_hidden_flag_obj(x, Lenny_Ptr, hidden_lenny_bit)                              \
         else unset_p_hidden_flag_obj(x, Cyberdog_Ptr, hidden_cyberdog_bit)                        \
         else unset_p_hidden_flag_obj(x, Doc_Ptr, hidden_doc_bit)                                  \
         else unset_p_hidden_flag_obj(x, Goris_Ptr, hidden_goris_bit)                              \
         else unset_p_hidden_flag_obj(x, Davin_Ptr, hidden_davin_bit)                              \
         else unset_p_hidden_flag_obj(x, Miria_Ptr, hidden_miria_bit)                              \
         else unset_p_hidden_flag_obj(x, Robobrain_Ptr, hidden_robobrain_bit)                      \
         else unset_p_hidden_flag_obj(x, Dogmeat_Ptr, hidden_dogmeat_bit)                          \
         else unset_p_hidden_flag_obj(x, Pariah_Dog_Ptr, hidden_pariah_dog_bit)                    \
         else unset_p_hidden_flag_obj(x, K9_Ptr, hidden_k9_bit)                                    \
         else unset_p_hidden_flag_obj(x, Robobrain_Human_Ptr, hidden_robobrain_human_bit)          \
         else unset_p_hidden_flag_obj(x, Robobrain_Abnormal_Ptr, hidden_robobrain_abnormal_bit)    \
         else unset_p_hidden_flag_obj(x, Robobrain_Chimp_Ptr, hidden_robobrain_chimp_bit)

variable tmp_hidden;

#define party_member_hide(x)                                                                 \
   if (x) then begin                                                                         \
      if (obj_is_visible_flag(x)) then begin                                                 \
         set_p_hidden_flag(x)                                                                \
         set_obj_visibility(x, 1);                                                           \
      end else begin                                                                         \
         ndebug("PARTY.H:::: no party member hidden because they already are invisible");    \
      end                                                                                    \
   end

#define party_member_unhide(x)                                                            \
   if (x) then begin                                                                      \
      if (obj_is_visible_flag(x) == 0) then begin                                         \
         get_p_hidden_flag(x, tmp_hidden)                                                 \
         if (tmp_hidden) then begin                                                       \
            unset_p_hidden_flag(x)                                                        \
            set_obj_visibility(x, 0);                                                     \
         end else begin                                                                   \
            ndebug("PARTY.H:::: party member wasn't hidden by my macro");                 \
         end                                                                              \
      end else begin                                                                      \
         unset_p_hidden_flag(x)                                                           \
         ndebug("PARTY.H:::: party member wasn't hidden.. clearing my state");            \
      end                                                                                 \
   end

*/
#define get_p_hidden_flag_obj(x, the_ptr, the_bit, the_var)             \
         if (x == the_ptr) then begin                                   \
            the_var := gvar_bit(GVAR_PARTY_MEMBERS_HIDDEN, the_bit);    \
         end
#define get_p_hidden_flag(x, hidden)                                                                     \
          get_p_hidden_flag_obj(x, Vic_Ptr, hidden_vic_bit, hidden)                                      \
          else get_p_hidden_flag_obj(x, Myron_Ptr, hidden_myron_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Marcus_Ptr, hidden_marcus_bit, hidden)                           \
          else get_p_hidden_flag_obj(x, MacRae_Ptr, hidden_macrae_bit, hidden)                           \
          else get_p_hidden_flag_obj(x, Sulik_Ptr, hidden_sulik_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Lenny_Ptr, hidden_lenny_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Cyberdog_Ptr, hidden_cyberdog_bit, hidden)                       \
          else get_p_hidden_flag_obj(x, Doc_Ptr, hidden_doc_bit, hidden)                                 \
          else get_p_hidden_flag_obj(x, Goris_Ptr, hidden_goris_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Davin_Ptr, hidden_davin_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Miria_Ptr, hidden_miria_bit, hidden)                             \
          else get_p_hidden_flag_obj(x, Robobrain_Ptr, hidden_robobrain_bit, hidden)                     \
          else get_p_hidden_flag_obj(x, Dogmeat_Ptr, hidden_dogmeat_bit, hidden)                         \
          else get_p_hidden_flag_obj(x, Pariah_Dog_Ptr, hidden_pariah_dog_bit, hidden)                   \
          else get_p_hidden_flag_obj(x, K9_Ptr, hidden_k9_bit, hidden)                                   \
          else get_p_hidden_flag_obj(x, Robobrain_Human_Ptr, hidden_robobrain_human_bit, hidden)         \
          else get_p_hidden_flag_obj(x, Robobrain_Abnormal_Ptr, hidden_robobrain_abnormal_bit, hidden)   \
          else get_p_hidden_flag_obj(x, Robobrain_Chimp_Ptr, hidden_robobrain_chimp_bit, hidden)         \
          else get_p_hidden_flag_obj(x, Kitsune_Ptr, hidden_kitsune_bit, hidden)                         \
          else get_p_hidden_flag_obj(x, Dex_Ptr, hidden_dex_bit, hidden)                                 \
          else get_p_hidden_flag_obj(x, Cat_Jules_Ptr, hidden_cat_jules_bit, hidden)

#define party_member_hidden(x, result)                                           \
   if (x) then begin                                                             \
      if (obj_is_visible_flag(x) == 0) then begin                                \
         get_p_hidden_flag(x, result)                                            \
         if (result) then begin                                                  \
            result := 1;                                                         \
         end else begin                                                          \
            result := 0;                                                         \
            ndebug("PARTY.H:::: party member hidden but not my my macro.. ");    \
         end                                                                     \
      end                                                                        \
   end

#define hidden_vic_bit                       bit_1
#define hidden_myron_bit                     bit_2
#define hidden_marcus_bit                    bit_3
#define hidden_macrae_bit                    bit_4
#define hidden_sulik_bit                     bit_5
#define hidden_lenny_bit                     bit_6
#define hidden_cyberdog_bit                  bit_7
#define hidden_doc_bit                       bit_8
#define hidden_goris_bit                     bit_9
#define hidden_davin_bit                     bit_10
#define hidden_miria_bit                     bit_11
#define hidden_robobrain_bit                 bit_12
#define hidden_dogmeat_bit                   bit_13
#define hidden_pariah_dog_bit                bit_14
#define hidden_k9_bit                        bit_15
#define hidden_robobrain_human_bit           bit_16
#define hidden_robobrain_abnormal_bit        bit_17
#define hidden_robobrain_chimp_bit           bit_18
#define hidden_kitsune_bit                   bit_19
#define hidden_dex_bit                       bit_20
#define hidden_cat_jules_bit                 bit_21
#define all_hidden_bit                       bit_22

#define party_bit_hidden(x)                  (gvar_bit(GVAR_PARTY_MEMBERS_HIDDEN, x))

#define all_party_hidden                     party_bit_hidden(all_hidden_bit)
#define set_party_bit_hidden(x, member)      set_gvar_bit_on(GVAR_PARTY_MEMBERS_HIDDEN, x); set_obj_visibility(member, 1)
#define party_member_hide(the_obj, the_bit)                                                        \
         if (the_obj) then begin                                                                   \
            if (obj_is_visible_flag(the_obj)) then begin                                           \
               ndebug("set party member hidden: " + obj_name(the_obj));                            \
               set_party_bit_hidden(the_bit, the_obj);                                             \
            end else begin                                                                         \
               ndebug("PARTY.H:::: no party member hidden because they already are invisible");    \
            end                                                                                    \
         end
#define party_member_hide_all                                                       \
         set_gvar_bit_on(GVAR_PARTY_MEMBERS_HIDDEN, all_hidden_bit);                \
         party_member_hide(Vic_Ptr, hidden_vic_bit)                                 \
         party_member_hide(Myron_Ptr, hidden_myron_bit)                             \
         party_member_hide(Marcus_Ptr, hidden_marcus_bit)                           \
         party_member_hide(MacRae_Ptr, hidden_macrae_bit)                           \
         party_member_hide(Sulik_Ptr, hidden_sulik_bit)                             \
         party_member_hide(Lenny_Ptr, hidden_lenny_bit)                             \
         party_member_hide(Cyberdog_Ptr, hidden_cyberdog_bit)                       \
         party_member_hide(Doc_Ptr, hidden_doc_bit)                                 \
         party_member_hide(Goris_Ptr, hidden_goris_bit)                             \
         party_member_hide(Davin_Ptr, hidden_davin_bit)                             \
         party_member_hide(Miria_Ptr, hidden_miria_bit)                             \
         party_member_hide(Robobrain_Ptr, hidden_robobrain_bit)                     \
         party_member_hide(Dogmeat_Ptr, hidden_dogmeat_bit)                         \
         party_member_hide(Pariah_Dog_Ptr, hidden_pariah_dog_bit)                   \
         party_member_hide(K9_Ptr, hidden_k9_bit)                                   \
         party_member_hide(Robobrain_Human_Ptr, hidden_robobrain_human_bit)         \
         party_member_hide(Robobrain_Abnormal_Ptr, hidden_robobrain_abnormal_bit)   \
         party_member_hide(Robobrain_Chimp_Ptr, hidden_robobrain_chimp_bit)         \
         party_member_hide(Kitsune_Ptr, hidden_kitsune_bit)                         \
         party_member_hide(Dex_Ptr, hidden_dex_bit)                                 \
         party_member_hide(Cat_Jules_Ptr, hidden_cat_jules_bit)

#define all_party_unhidden                   (all_party_hidden == false)
#define set_party_bit_unhidden(x, member)    ndebug("unhiding party member "+obj_name(member)); set_gvar_bit_off(GVAR_PARTY_MEMBERS_HIDDEN, x); set_obj_visibility(member, 0)
#define party_member_unhide(the_obj, the_bit)                                                   \
         if (the_obj) then begin                                                                \
            if (obj_is_visible_flag(the_obj) == 0) then begin                                   \
               if (party_bit_hidden(the_bit)) then begin                                        \
                  set_party_bit_unhidden(the_bit, the_obj);                                     \
               end else begin                                                                   \
                  ndebug("PARTY.H:::: party member wasn't hidden by my macro");                 \
               end                                                                              \
            end else begin                                                                      \
               set_party_bit_unhidden(the_bit, the_obj);                                        \
               ndebug("PARTY.H:::: party member wasn't hidden.. clearing my state");            \
            end                                                                                 \
         end
#define party_member_unhide_all                                                        \
         set_gvar_bit_off(GVAR_PARTY_MEMBERS_HIDDEN, all_hidden_bit);                  \
         party_member_unhide(Vic_Ptr, hidden_vic_bit)                                  \
         party_member_unhide(Myron_Ptr, hidden_myron_bit)                              \
         party_member_unhide(Marcus_Ptr, hidden_marcus_bit)                            \
         party_member_unhide(MacRae_Ptr, hidden_macrae_bit)                            \
         party_member_unhide(Sulik_Ptr, hidden_sulik_bit)                              \
         party_member_unhide(Lenny_Ptr, hidden_lenny_bit)                              \
         party_member_unhide(Cyberdog_Ptr, hidden_cyberdog_bit)                        \
         party_member_unhide(Doc_Ptr, hidden_doc_bit)                                  \
         party_member_unhide(Goris_Ptr, hidden_goris_bit)                              \
         party_member_unhide(Davin_Ptr, hidden_davin_bit)                              \
         party_member_unhide(Miria_Ptr, hidden_miria_bit)                              \
         party_member_unhide(Robobrain_Ptr, hidden_robobrain_bit)                      \
         party_member_unhide(Dogmeat_Ptr, hidden_dogmeat_bit)                          \
         party_member_unhide(Pariah_Dog_Ptr, hidden_pariah_dog_bit)                    \
         party_member_unhide(K9_Ptr, hidden_k9_bit)                                    \
         party_member_unhide(Robobrain_Human_Ptr, hidden_robobrain_human_bit)          \
         party_member_unhide(Robobrain_Abnormal_Ptr, hidden_robobrain_abnormal_bit)    \
         party_member_unhide(Robobrain_Chimp_Ptr, hidden_robobrain_chimp_bit)          \
         party_member_unhide(Kitsune_Ptr, hidden_kitsune_bit)                          \
         party_member_unhide(Dex_Ptr, hidden_dex_bit)                                  \
         party_member_unhide(Cat_Jules_Ptr, hidden_cat_jules_bit)
//End hiding party members


// Default
// party member health states
#define party_healed_max                     (self_cur_hits == self_max_hits)
#define party_healed_good                    (((self_cur_hits * 100)/self_max_hits) >= 90)
#define party_healed_hurt                    (((self_cur_hits * 100)/self_max_hits) >= 70)
#define party_healed_bad                     (((self_cur_hits * 100)/self_max_hits) < 70)

// Generic Options for party members
#define def_heal_msg                         g_mstr(10001)
#define def_wait_msg                         g_mstr(10002)
#define def_unarm_msg                        g_mstr(10003)
#define def_close_msg                        g_mstr(10004)
#ifndef def_med_msg
  #define def_med_msg                        g_mstr(10005)
#endif
#ifndef def_far_msg
  #define def_far_msg                        g_mstr(10006)
#endif
#define def_end_msg                          g_mstr(10007)
#ifndef def_follow_msg
  #define def_follow_msg                     g_mstr(10008)
#endif
#define def_gear_msg                         g_mstr(10009)
#define def_ignore_follow_msg                g_mstr(10010)
#define def_ignore_gear_msg                  g_mstr(10011)
#define def_armor_msg                        g_mstr(10012)
#define def_weapon_use_msg                   g_mstr(10013)
#define def_nowait_msg                       g_mstr(10100)
#define def_stupid_msg                       g_mstr(random(300, 303))

#define DEF_PARTY_HEAL_NODE                  Node1001
#define DEF_PARTY_WAIT_NODE                  Node1002
#define DEF_UNARM_NODE                       Node1003
#define DEF_FOLLOW_CLOSE_NODE                Node1004
#define DEF_FOLLOW_MEDIUM_NODE               Node1005
#define DEF_FOLLOW_FAR_NODE                  Node1006
#define DEF_PARTY_FOLLOW_NODE                Node1007
#define DEF_PARTY_GEAR_NODE                  Node1008
#define DEF_REMOVE_ARMOR_NODE                Node1009
#define DEF_WEAPON_USE_NODE                  Node1010
#define DEF_PARTY_NOWAIT_NODE                Node1100
#define DEF_PARTY_END_NODE                   Node999
#define DEF_PARTY_STUPID_NODE                Node999
#define party_member_options(heal_msg, follow_msg, gear_msg, wait_msg, nowait_msg, end_msg, stupid_msg)  \
                                             if (party_is_waiting == false) then begin                   \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) == 0) then begin     \
                                                   set_follow_medium;                                    \
                                                end                                                      \
                                                if (heal_msg != 0) then begin                            \
                                                   if (self_cur_hits < self_max_hits) then begin         \
                                                      NOption(heal_msg, DEF_PARTY_HEAL_NODE, 004);       \
                                                   end                                                   \
                                                end                                                      \
                                                if (follow_msg != 0) then begin                          \
                                                   NOption(follow_msg, DEF_PARTY_FOLLOW_NODE, 004);      \
                                                end                                                      \
                                                if (gear_msg != 0) then begin                            \
                                                   NOption(gear_msg, DEF_PARTY_GEAR_NODE, 004);          \
                                                end                                                      \
                                                if (wait_msg != 0) then begin                            \
                                                   NOption(wait_msg, DEF_PARTY_WAIT_NODE, 004);          \
                                                end                                                      \
                                             end else if (nowait_msg != 0) then begin                    \
                                                NOption(nowait_msg, DEF_PARTY_NOWAIT_NODE, 004);         \
                                             end                                                         \
                                             if (end_msg != 0) then begin                                \
                                                NOption(end_msg, DEF_PARTY_END_NODE, 004);               \
                                             end                                                         \
                                             if (stupid_msg != 0) then begin                             \
                                                NOption(stupid_msg, DEF_PARTY_STUPID_NODE, -003);        \
                                             end                                                         \
                                             ndebug("USED PARTY MEMBER OPTIONS")
// this goes into node 1007
#define party_follow_options(close_msg, med_msg, far_msg, follow_ignore_msg)                                                  \
                                             if (close_msg != 0) then begin                                                   \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) != FOLLOW_DISTANCE_CLOSE) then begin      \
                                                   NOption(close_msg, DEF_FOLLOW_CLOSE_NODE, 004);                            \
                                                end                                                                           \
                                             end                                                                              \
                                             if (med_msg != 0) then begin                                                     \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) != FOLLOW_DISTANCE_MEDIUM) then begin     \
                                                   NOption(med_msg, DEF_FOLLOW_MEDIUM_NODE, 004);                             \
                                                end                                                                           \
                                             end                                                                              \
                                             if (far_msg != 0) then begin                                                     \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) != FOLLOW_DISTANCE_FAR) then begin        \
                                                   NOption(far_msg, DEF_FOLLOW_FAR_NODE, 004);                                \
                                                end                                                                           \
                                             end                                                                              \
                                             if (follow_ignore_msg != 0) then begin                                           \
                                                NOption(follow_ignore_msg, PARTY_NODE_X, 004);                                \
                                             end                                                                              \
                                             ndebug("USED PARTY FOLLOW OPTIONS")

// this goes into node 1008
#define party_gear_options(weapon_use_msg, unarm_msg, armor_msg, gear_ignore_msg)                     \
                                             if (weapon_use_msg != 0) then begin                      \
                                                NOption(weapon_use_msg, DEF_WEAPON_USE_NODE, 004);    \
                                             end                                                      \
                                             if (unarm_msg != 0) then begin                           \
                                                if (self_is_armed) then begin                         \
                                                   NOption(unarm_msg, DEF_UNARM_NODE, 004);           \
                                                end                                                   \
                                             end                                                      \
                                             if (armor_msg != 0) then begin                           \
                                                if (self_wearing_armor) then begin                    \
                                                   NOption(armor_msg, DEF_REMOVE_ARMOR_NODE, 004);    \
                                                end                                                   \
                                             end                                                      \
                                             if (gear_ignore_msg != 0) then begin                     \
                                                NOption(gear_ignore_msg, PARTY_NODE_X, 004);          \
                                             end                                                      \
                                             ndebug("USED PARTY GEAR OPTIONS")

#define party_member_default_options         party_member_options(def_heal_msg, def_follow_msg, def_gear_msg, def_wait_msg, def_nowait_msg, def_end_msg, def_stupid_msg)
#define party_member_def_follow_options      party_follow_options(def_close_msg, def_med_msg, def_far_msg, def_ignore_follow_msg)
#define party_member_def_gear_options        party_gear_options(def_weapon_use_msg, def_unarm_msg, def_armor_msg, def_ignore_gear_msg)

// party member follow macros
#define party_no_follow_on                   set_global_var(GVAR_PARTY_NO_FOLLOW, 1)
#define party_no_follow_off                  set_global_var(GVAR_PARTY_NO_FOLLOW, 0)
#define party_no_follow                      (global_var(GVAR_PARTY_NO_FOLLOW) != 0)

#define set_follow_close                     set_local_var(LVAR_FOLLOW_DISTANCE, FOLLOW_DISTANCE_CLOSE)
#define set_follow_medium                    set_local_var(LVAR_FOLLOW_DISTANCE, FOLLOW_DISTANCE_MEDIUM)
#define set_follow_far                       set_local_var(LVAR_FOLLOW_DISTANCE, FOLLOW_DISTANCE_FAR)
#define party_member_follow_dude             if ((party_is_waiting == false) and (party_no_follow == false)) then begin                \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) == 0) then begin                                   \
                                                   set_follow_medium;                                                                  \
                                                end                                                                                    \
                                                party_follow_dude_point(((3*local_var(LVAR_FOLLOW_DISTANCE))/2), local_var(LVAR_FOLLOW_DISTANCE))  \
                                             end

// party member team macros
#ifndef set_default_party_follow
  #define set_default_party_follow           set_follow_medium
#endif
#define store_party_team                     if (self_team != TEAM_PLAYER) then begin                 \
                                                set_local_var(LVAR_TEAM, self_team);                  \
                                             end
#define party_add_self                       if (is_critter_dead(self_obj) == false) then begin                            \
                                                if (local_var(LVAR_FOLLOW_DISTANCE) == 0) then begin                       \
                                                   set_default_party_follow;                                               \
                                                end                                                                        \
                                                set_local_var(LVAR_WAITING, 0);                                            \
                                                store_party_team                                                           \
                                                critter_add_trait(self_obj, TRAIT_OBJECT, OBJECT_TEAM_NUM, TEAM_PLAYER);   \
                                                party_add(self_obj);                                                       \
                                             end                                                                           \
                                             ndebug("join party: " + self_name)
#define party_remove_self                    party_remove(self_obj)

// party member abandons party macros
#define abandoned_party                      (local_var(LVAR_TEAM) == -1)
#define set_self_abandon_party               if (obj_in_party(self_obj)) then begin                                                \
                                                ndebug("abandon party: " + self_name);                                             \
                                                party_remove_self;                                                                 \
                                             end                                                                                   \
                                             if ((self_pid == PID_MIRIA) or (self_pid == PID_DAVIN)) then begin                    \
                                                set_dude_was_married;                                                              \
                                             end                                                                                   \
                                             if ((local_var(LVAR_TEAM) != -1) and (self_team == false)) then begin                 \
                                                 critter_add_trait(self_obj, TRAIT_OBJECT, OBJECT_TEAM_NUM, local_var(LVAR_TEAM)); \
                                                 set_local_var(LVAR_TEAM, -1);                                                     \
                                             end                                                                                   \
                                             ndebug("" + obj_name(self_obj) + " has abandoned the party")

// party member waiting macros
#define party_is_waiting                     (local_var(LVAR_WAITING) != 0)
#define set_party_waiting                    set_local_var(LVAR_WAITING, game_time);      \
                                             party_remove_self
#define end_party_waiting                    set_local_var(LVAR_WAITING, 0);              \
                                             party_add_self


/***************************************************************************************
   This is to check to see if there are any party members within range of the door
   so it doesn't close.
****************************************************************************************/

/* How far do party members have to be from the door before it closes */
#define PARTY_CLOSE_DIST                (5)

#define CHECKMEMBERNEARDOOR(inparty, obj)                                           \
         if (inparty) then begin                                                    \
            if (tile_distance_objs(self_obj, obj) <= PARTY_CLOSE_DIST) then begin   \
               return 1;                                                            \
            end                                                                     \
         end

procedure checkPartyMembersNearDoor begin
   CHECKMEMBERNEARDOOR(Vic_In_Party, Vic_Ptr)
   CHECKMEMBERNEARDOOR(Myron_In_Party, Myron_Ptr)
   CHECKMEMBERNEARDOOR(Marcus_In_Party, Marcus_Ptr)
   CHECKMEMBERNEARDOOR(MacRae_In_Party, MacRae_Ptr)
   CHECKMEMBERNEARDOOR(Sulik_In_Party, Sulik_Ptr)
   CHECKMEMBERNEARDOOR(Lenny_In_Party, Lenny_Ptr)
   CHECKMEMBERNEARDOOR(Cyberdog_In_Party, Cyberdog_Ptr)
   CHECKMEMBERNEARDOOR(Doc_In_Party, Doc_Ptr)
   CHECKMEMBERNEARDOOR(Goris_In_Party, Goris_Ptr)
   CHECKMEMBERNEARDOOR(Davin_In_Party, Davin_Ptr)
   CHECKMEMBERNEARDOOR(Miria_In_Party, Miria_Ptr)
   CHECKMEMBERNEARDOOR(Robobrain_In_Party, Robobrain_Ptr)
   CHECKMEMBERNEARDOOR(Laddie_In_Party, Laddie_Ptr)
   CHECKMEMBERNEARDOOR(Bess_In_Party, Bess_Ptr)
   CHECKMEMBERNEARDOOR(Chicken_In_Party, Chicken_Ptr)
   CHECKMEMBERNEARDOOR(Karl_In_Party, Karl_Ptr)
   CHECKMEMBERNEARDOOR(Jonny_In_Party, Jonny_Ptr)
   CHECKMEMBERNEARDOOR(Lloyd_In_Party, Lloyd_Ptr)
   CHECKMEMBERNEARDOOR(Dogmeat_In_Party, Dogmeat_Ptr)
   CHECKMEMBERNEARDOOR(Pariah_Dog_In_Party, Pariah_Dog_Ptr)
   CHECKMEMBERNEARDOOR(Kitsune_In_Party, Kitsune_Ptr)
   CHECKMEMBERNEARDOOR(Dex_In_Party, Dex_Ptr)
   CHECKMEMBERNEARDOOR(Cat_Jules_In_Party, Cat_Jules_Ptr)
   return 0;
end

#define party_member_map_enter                        if (cur_map_index == MAP_MODOC_BEDNBREAKFAST or cur_map_index == MAP_THE_SQUAT_A or cur_map_index == MAP_THE_SQUAT_B) then \
                                                         if ((self_elevation != dude_elevation) and (party_is_waiting)) then move_to(self_obj, self_tile, dude_elevation)

#endif // PARTY_H
