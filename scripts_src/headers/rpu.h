// RP-specific additions go here
#ifndef RPU_H
#define RPU_H

#define rpu_ini "mods\\rpu.ini"
#define sec_main "main"
#define rpu_setting(section, setting) get_ini_setting(rpu_ini + "|" + section + "|" + setting)
#define rpu_string(section, setting) get_ini_string(rpu_ini + "|" + section + "|" + setting)
#define rpu_msetting(setting) get_ini_setting(rpu_ini + "|" + sec_main + "|" + setting)

#define set_marcus_armor "marcus_armor"
#define set_dogmeat_armor "dogmeat_armor"
#define set_smoking "smoking"
#define set_lenny_look "lenny_new_look"
#define set_vault_boxer "vault_boxer"
#define set_cassidy_head "cassidy_head"

#define appearance_mod_enabled get_ini_setting("ddraw.ini|Misc|EnableHeroAppearanceMod")
#define vault_boxer_enabled rpu_msetting(set_vault_boxer)

procedure is_lockpick_elec(variable item) begin
  switch (obj_pid(item)) begin
    case PID_ELECTRONIC_LOCKPICKS: return true;
    case PID_ELEC_LOCKPICK_MKII: return true;
    default: return false;
  end
end
procedure is_lockpick_mech(variable item) begin
  switch (obj_pid(item)) begin
    case PID_LOCKPICKS: return true;
    case PID_EXP_LOCKPICK_SET: return true;
    default: return false;
  end
end
procedure is_lockpick(variable item) begin
  if is_lockpick_mech(item) then return true;
  if is_lockpick_elec(item) then return true;
  return false;
end

#endif  // RPU_H


// rpu define.h extras
#ifndef RPU_DEFINE_H
#define RPU_DEFINE_H
// heads
#define HEAD_DYING_HAKUNIN_NIGHT    (14)
// backgrounds
#define BACKGROUND_WASTELAND_NIGHT  (21)       //wasteln2.frm
#define BACKGROUND_MAINTENANCE      (22)       //epa1.frm
#define BACKGROUND_VAULT2	          (23)       //epa2.frm
#define BACKGROUND_SAN_FRAN_SUB	    (24)       //shisub.frm
/* Script MetaRules */
#define METARULE_TEST_FIRSTRUN      14

// appearance mod
#define MASH_CRITTER_LIST_SIZE 		  151
// races
#define WHITE_RACE					        0
#define BLACK_RACE					        1
// styles
#define REG_HAIR                    0
#define LONG_HAIR                   1
#define BALD_HAIR                   2

// NPC critter fid offset. Add this to the fids (artfid) when using obj_art_fid
#define NPC_ARTFID_WEAPON_OFFSET	4096
#endif // RPU_DEFINE_H

// rpu items
#ifndef RPU_ITEMPID_H
#define RPU_ITEMPID_H
#define PID_BUCKET                          (534)  // added by killap - expansion pack (Primitive Tribe)
#define PID_FISH                            (535)  // added by killap - expansion pack (Primitive Tribe)
#define PID_FISH2                           (536)  // added by killap - expansion pack (Primitive Tribe)
#define PID_ABBEY_MISSING_BOOK              (537)  // added by killap - expansion pack (Abbey)
#define PID_ABBEY_TECHMANUAL1               (538)  // added by killap - expansion pack (Abbey)
#define PID_ABBEY_TECHMANUAL2               (539)  // added by killap - expansion pack (Abbey)
#define PID_ABBEY_TECHMANUAL3               (540)  // added by killap - expansion pack (Abbey)
#define PID_CHINESE_ARMY_MANUAL             (541)  // added by killap - expansion pack (Abbey)
#define PID_ABBEY_BOOZE                     (542)  // added by killap - expansion pack (Abbey)
#define PID_ANNA_DIARY                      (543)  // added by killap - expansion pack (Den)
#define PID_EPA_BOTANY_HOLODISK             (544)  // added by killap - expansion pack (EPA)
#define EXPIRED_GECK                        (545)  // added by killap - expansion pack (Hub Stash)
#define PID_OLD_COIN                        (546)  // added by killap - expansion pack (Hub Stash)
#define PID_OLD_WATCH                       (547)  // added by killap - expansion pack (Hub Stash)
#define PID_CIGARETTE                       (548)  // added by killap - expansion pack (Hub Stash)
#define PID_GAS_MASK                        (549)  // added by killap - expansion pack (EPA)
#define PID_TOASTER                         (550)  // epa cont
#define PID_EPA_SYRINGE                     (551)
#define PID_DOG_FOOD                        (552)
#define PID_BUG_SPRAY                       (553)
#define PID_ENVIRONMENTAL_ARMOUR            (554)
#define PID_EPA_PAMPHLET                    (555)
#define PID_DRUGS                           (556)
#define PID_SECURITY_ROOMS_KEY_CARD         (557)
#define PID_RACK                            (558)
#define PID_EPA_KEYS                        (559)
#define PID_RANDOM_CHEMICALS                (560)
#define PID_ARROYO_SEEDS                    (561)
#define PID_PLANT_SPRAY                     (562)
#define PID_RADIO_DYNAMITE                  (563)
#define PID_RADIO_DYNAMITE_TRIGGER          (564)
#define PID_PAPER                           (565)
#define PID_EXPERIMENTAL_SEEDS              (566)
#define PID_DRILL                           (567)
#define PID_ACTIVE_RADIO_DYNAMITE           (568)
#define PID_POP_ROCKS                       (569)
#define PID_SHAMPOO                         (570)
#define PID_K9_KEVLAR                       (571)
#define PID_HUMAN_EAR                       (572)
#define PID_ERSI                            (573)
#define PID_LIGHTSABER_GREEN                (574)
#define PID_BLASTER                         (575)
#define PID_LIGHTSABER_RED                  (576)
#define PID_BIG_VENT                        (577)
#define PID_SUB_LOCKER1                     (578)
#define PID_SUB_LOCKER2                     (579)
#define PID_SHI_SUB_CODE_CHART              (580)
#define PID_DEAD_TRIBAL1                    (581)
#define PID_DEAD_TRIBAL2                    (582)
#define PID_EPA_SPORE_SPIKE                 (583)
#define PID_DEAD_VAULT_DWELLER1             (584)
#define PID_DEAD_VAULT_DWELLER2             (585)
#define PID_DEAD_TRIBAL3                    (586)
#define PID_DEAD_TRIBAL4                    (587)
#define PID_K9_KEVLAR_WEARABLE              (588)
#define PID_MUTANT_ARMOR                    (589)
#define PID_MUTANT_ARMOR_WEARABLE           (590)
#define PID_SMALL_SCORPION_TAIL             (591)
#define PID_DR_SHENG_PLANT_SEED             (592)
#define PID_VAULT_BOXER_MALE_NORMAL         (593)
#define PID_VAULT_BOXER_MALE_LONG_HAIR      (594)
#define PID_VAULT_BOXER_MALE_BALD           (595)
#define PID_FAKE_HEART_PILLS                (596)
#endif // RPU_ITEMPID_H


#ifndef RPU_COMMANDS_H
#define RPU_COMMANDS_H

procedure get_critical_items_list_rpu begin
  variable appendList := [
    // repurposed vanilla items
    PID_MOTIVATOR,           // Abbey
    PID_HEART_PILLS,         // Cassidy & Abbey
    // RP added
    PID_BUCKET,              // Umbra tribe
    PID_ABBEY_MISSING_BOOK,  // Abbey
    PID_EPA_BOTANY_HOLODISK, // Abbey
    PID_EXPERIMENTAL_SEEDS,  // SanFran/Dr.Sheng
    PID_ERSI,                // EPA companion
    PID_DR_SHENG_PLANT_SEED, // SanFran/Dr.Sheng
    PID_FAKE_HEART_PILLS     // Westin assassination
  ];
  // Combine two lists
  variable fullList := get_critical_items_list;
  variable upuListCount := len_array(fullList);
  resize_array(fullList, upuListCount + len_array(appendList));
  foreach (variable i: pid in appendList) begin
    fullList[upuListCount + i] := pid;
  end
  return fullList;
end

#undef move_critical_items_call
#define move_critical_items_call         move_critical_items_internal(get_critical_items_list_rpu)

#endif // RPU_COMMANDS_H
