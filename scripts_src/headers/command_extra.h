// This file is for RP changes and additions to command.h.
// Its purpose is to keep actual command.h identical between UP and RP, easing maintenance.
// Non-command.h additions should go to rpu.h.

#ifndef COMMAND_EXTRA_H
#define COMMAND_EXTRA_H


procedure vault_boxer_style(variable enable) begin
  variable style_item_pid;
  if not dude_is_male then return;

  switch get_sfall_global_int("HApStyle") begin
    case LONG_HAIR: style_item_pid := PID_VAULT_BOXER_MALE_LONG_HAIR;
    case BALD_HAIR: style_item_pid := PID_VAULT_BOXER_MALE_BALD;
    case REG_HAIR: style_item_pid := PID_VAULT_BOXER_MALE_NORMAL;
    default: style_item_pid := PID_VAULT_BOXER_MALE_NORMAL; // just in case
  end
  if enable then begin
    if (obj_carrying_pid_obj(dude_obj,style_item_pid) == 0) then begin
      variable armor := create_object(style_item_pid,0,0);
      add_obj_to_inven(dude_obj,armor);
      wield_obj_critter(dude_obj, armor);
    end
  end else begin
    remove_armor(dude_obj)
    destroy_object(obj_carrying_pid_obj(dude_obj,style_item_pid));
  end
  refresh_pc_art;
end

procedure doVaultBoxerAppearance begin
  if vault_boxer_enabled and appearance_mod_enabled then begin
    set_global_var(GVAR_TMP_GLOBAL_VAR,1);
    call vault_boxer_style(true);
  end
end

procedure removeVaultBoxerAppearance begin
  variable enabled := rpu_msetting(set_vault_boxer);
  if vault_boxer_enabled and appearance_mod_enabled then begin
    set_global_var(GVAR_TMP_GLOBAL_VAR,0);
    call vault_boxer_style(false);
  end
end

#define is_alcohol(x) ( \
 (obj_pid(x) == PID_BEER) \
  or (obj_pid(x) == PID_BOOZE) \
  or (obj_pid(x) == PID_GAMMA_GULP_BEER) \
  or (obj_pid(x) == PID_ROENTGEN_RUM) \
  or (obj_pid(x) == PID_ROT_GUT) \
  or (obj_pid(x) == PID_ABBEY_BOOZE) \
)

#define protected_from_gas(x) ( \
 (obj_pid(get_armor(x)) == PID_POWERED_ARMOR) \
  or (obj_pid(get_armor(x)) == PID_HARDENED_POWER_ARMOR) \
  or (obj_pid(get_armor(x)) == PID_ADVANCED_POWER_ARMOR) \
  or (obj_pid(get_armor(x)) == PID_ADVANCED_POWER_ARMOR_MK2) \
  or (obj_pid(get_armor(x)) == PID_ENVIRONMENTAL_ARMOUR) \
  or ( (x == dude_obj) \
    and ( (obj_pid(dude_right_hand) == PID_GAS_MASK) \
          or (obj_pid(dude_left_hand) == PID_GAS_MASK) \
        ) \
  ) \
)

#endif  // COMMAND_EXTRA_H
