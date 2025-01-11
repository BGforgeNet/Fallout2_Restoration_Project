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

/**
 * True if any of addiction GVARs is set, false otherwise.
 */
procedure dude_is_addicted() begin
  if global_var(GVAR_ADDICT_JET)
    or global_var(GVAR_NUKA_COLA_ADDICT)
    or global_var(GVAR_BUFF_OUT_ADDICT)
    or global_var(GVAR_MENTATS_ADDICT)
    or global_var(GVAR_PSYCHO_ADDICT)
    or global_var(GVAR_RADAWAY_ADDICT)
    or global_var(GVAR_ALCOHOL_ADDICT)
    or global_var(GVAR_ADDICT_TRAGIC)
  then return true;
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
