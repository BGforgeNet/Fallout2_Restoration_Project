/** @tra door.msg */
// Also used in containers: containr.msg

#ifndef DOORS_CONTAINERS_H
#define DOORS_CONTAINERS_H

/* Defines and Macros */
#ifndef Lockpick_Bonus
  #define Lockpick_Bonus                  (Lock_Bonus+20)
#endif
#ifndef Exd_Lockpick_Bonus
  #define Exd_Lockpick_Bonus              (Lock_Bonus+40)
#endif

/* Penalties for disarming the trap */
#ifndef Trap_Bonus
  #define Trap_Bonus                      (0)
#endif
#ifndef Trap_Set_Bonus
  #define Trap_Set_Bonus                  (Trap_Bonus-10)
#endif
/* Experience Points for Skills */
#ifndef Lockpick_Exp
  #if Lock_Bonus == 0
    #define Lockpick_Exp                    EXP_LOCKPICK_NORMAL
  #endif
  #if Lock_Bonus == (-10)
    #define Lockpick_Exp                    EXP_LOCKPICK_NEG_10
  #endif
  #if Lock_Bonus == (-20)
    #define Lockpick_Exp                    EXP_LOCKPICK_NEG_20
  #endif
  #if Lock_Bonus == (-30)
    #define Lockpick_Exp                    EXP_LOCKPICK_NEG_30
  #endif
  #if Lock_Bonus == (-40)
    #define Lockpick_Exp                    EXP_LOCKPICK_NEG_40
  #endif
  #if Lock_Bonus == (-50)
    #define Lockpick_Exp                    EXP_LOCKPICK_NEG_50
  #endif
  #if Lock_Bonus == (-60)
    #define Lockpick_Exp                    EXP_LOCKPICK_NEG_60
  #endif
  #if Lock_Bonus == (-70)
    #define Lockpick_Exp                    EXP_LOCKPICK_NEG_70
  #endif
  #if Lock_Bonus == (-80)
    #define Lockpick_Exp                    EXP_LOCKPICK_NEG_80
  #endif
  #if Lock_Bonus == (-90)
    #define Lockpick_Exp                    EXP_LOCKPICK_NEG_90
  #endif
#endif
#ifndef Traps_Exp
  #define Traps_Exp                       EXP_TRAPS_NORMAL
#endif

/* Penalties for forcing the door open using strength */
#ifndef Crowbar_Bonus
  #if DOOR_STATUS == STATE_METAL
    #define Crowbar_Bonus                   (-2)
  #else
    #define Crowbar_Bonus                   (0)
  #endif
#endif
#ifndef Crowbar_Strain
  #if DOOR_STATUS == STATE_METAL
    #define Crowbar_Strain                  (4)
  #else
    #define Crowbar_Strain                  (2)
  #endif
#endif

/* Max and Min damage for the trap */
#ifndef MIN_DAMAGE
  #define MIN_DAMAGE                      (10)
#endif
#ifndef MAX_DAMAGE
  #define MAX_DAMAGE                      (20)
#endif

// 3 and less is just not enough to work the crowbar
#define MIN_STRENGTH  4

/* Standard Script Procedures */
procedure look_at_p_proc;
procedure description_p_proc;
procedure use_skill_on_p_proc;
procedure use_obj_on_p_proc;
procedure damage_p_proc;
procedure map_enter_p_proc;
procedure map_update_p_proc;

/* Script Specific Procedure Calls */
procedure Look_Traps_And_Locks;
procedure Look_Traps;
procedure Look_Locks;
procedure Skill_Disarm_Traps;
procedure Disarm_Traps;
procedure Unlock_Lock;
procedure Lockpick_Lock;
procedure Lockpick_Door;
procedure Lock_Door;
procedure Set_Lock;
procedure Set_Lockpick_Lock;
procedure Set_Trap;
procedure Pry_Door;
procedure Damage_Critter;
procedure Super_Lockpick_Lock;
procedure Super_Set_Lockpick_Lock;
procedure trap_search_result(variable found_trap, variable who);
procedure real_explosion(variable explosive);
procedure roll_critical;
procedure map_enter_p_proc_vanilla;
/*****************************************************************
Local Variables which are saved. All Local Variables need to be
prepended by LVAR_
*****************************************************************/
#define LVAR_Locked                     (0)
#define LVAR_Trapped                    (1)
#define LVAR_Found_Trap                 (2)
#define LVAR_Set_Door_Status            (3)
#define LVAR_Explosion_Attempts         (4)
#define LVAR_Gave_Locks_XP              (5)
#define LVAR_Gave_Traps_XP              (6)

/*******************************************************************
Local variables which do not need to be saved between map changes.
*******************************************************************/
variable Locks_Roll;
variable Traps_Roll;

// display mstr, depending on who's the object
// needs "my_mstr"
#define pcnpc_display_line(who, pc_line, npc_line) \
  if (who == dude_obj) then begin \
    display_msg(my_mstr(pc_line)); \
  end else begin \
    display_msg(obj_name(who) + my_mstr(npc_line)); \
  end
// same, but uses ready mstrs
#define pcnpc_display_str(who, pc_mstr, npc_mstr) \
  if (who == dude_obj) then begin \
    display_msg(pc_mstr); \
  end else begin \
    display_msg(obj_name(who) + npc_mstr); \
  end


procedure trap_search_result(variable found_trap, variable who) begin
  if (found_trap == 0) then begin // can't see trap
    pcnpc_display_line(who, 195, 200)
  end else begin // found trap
    pcnpc_display_line(who, 198, 200)
  end
end

#define std_lockpick_inner_block \
if (Tool == PID_LOCKPICKS) then begin \
  script_overrides; \
  if (local_var(LVAR_Locked) == STATE_ACTIVE) then begin \
    call Lockpick_Lock; \
  end else begin \
    call Set_Lockpick_Lock; \
  end \
end \
else if (Tool == PID_EXP_LOCKPICK_SET) then begin \
  script_overrides; \
  if (local_var(LVAR_Locked) == STATE_ACTIVE) then begin \
    call Super_Lockpick_Lock; \
  end else begin \
    call Super_Set_Lockpick_Lock; \
  end \
end

#define std_lockpick_outer_block \
if (LOCK_STATUS == STATE_STANDARD_LOCK) then begin \
  std_lockpick_inner_block \
end

#define elec_lockpick_inner_block \
if (Tool == PID_ELECTRONIC_LOCKPICKS) then begin \
  script_overrides; \
  if (local_var(LVAR_Locked) == STATE_ACTIVE) then begin \
    call Lockpick_Lock; \
  end else begin \
    call Set_Lockpick_Lock; \
  end \
end \
else if (Tool == PID_ELEC_LOCKPICK_MKII) then begin \
  script_overrides; \
  if (local_var(LVAR_Locked) == STATE_ACTIVE) then begin \
    call Super_Lockpick_Lock; \
  end else begin \
    call Super_Set_Lockpick_Lock; \
  end \
end \

#define elec_lockpick_outer_block \
else if (LOCK_STATUS == STATE_ELECTRIC_LOCK) then begin \
  elec_lockpick_inner_block \
end

#define full_lockpick_block \
std_lockpick_outer_block \
elec_lockpick_outer_block

#define pry_block \
  if (Tool == PID_CROWBAR) then begin \
    script_overrides; \
    call Pry_Door; \
  end
#define trap_block \
  if ((Tool == PID_DYNAMITE) or (Tool == PID_PLASTIC_EXPLOSIVES)) then begin \
    script_overrides; \
    call Set_Trap; \
  end
#define pry_trap_block \
  pry_block \
  trap_block

/**************************************************************************************
Should the trap go off for any reason by critter influence, then this procedure will
be called to deal damage to the critter, display a message stating how much damage
was taken, and remove the trap.
**************************************************************************************/
#ifndef custom_Damage_Critter
  procedure Damage_Critter begin
    variable Trap_Damage;
    Trap_Damage:=random(MIN_DAMAGE,MAX_DAMAGE);
    reg_anim_clear(source_obj); // prevent "you were hit for no damage" from the next line when running through a closed door
    explosion(self_tile, self_elevation, 0); // just the animation
    pcnpc_display_str(source_obj, my_mstr(166)+Trap_Damage+my_mstr(167), my_mstr(168)+Trap_Damage+my_mstr(169))
    critter_heal(source_obj, -Trap_Damage);
    set_local_var(LVAR_Trapped, STATE_INACTIVE);
  end
#endif

/**
 * This procedure is used should the player try to pry the door open using a crowbar or some similar instrument.
 */
procedure roll_pry_success begin
  variable rnd = random(MIN_STRENGTH, 10);
  if (get_critter_stat(source_obj, STAT_st) + Crowbar_Bonus) > rnd then return true;
  return false;
end

// Sturdier doors and high strength provide higher chance to mangle the crowbar
// 4 STR char + wood door = 1% chance to destroy
// 5 STR char + metal container = 10% chance to destroy
// 10 STR char + metal container = 20% chance to destroy
procedure roll_pry_destroy_crowbar begin
  variable rnd = random(1, 100);
  variable str = get_critter_stat(source_obj, STAT_st);

  // Too weak to bend it
  if str < MIN_STRENGTH then return false;

  // Base Crowbar_Bonus = 0 (wood door). For metal doors, default is -2
  variable penalty = str * Crowbar_Bonus;
  if rnd + penalty <= 1 then return true;

  return false;
end

#ifndef custom_Pry_Door
  procedure Pry_Door begin
    variable pry_success;
    variable pry_strain;
    variable pry_destroy_crowbar;

    if not obj_is_locked(self_obj) then begin
      display_msg(my_mstr(601));
      return;
    end

    /** True if I am a container, False otherwise (door) */
    variable is_container = false;
    if (obj_type(self_obj) == OBJ_TYPE_ITEM) and (obj_item_subtype(self_obj) == item_type_container) then begin
      is_container = true;
    end
    // No prying open metal doors
    if (DOOR_STATUS == STATE_METAL) and (not is_container) then begin
      display_msg(my_mstr(500));
    end

    // crowbar destroy runs always, discouraging high STR characters from spamming it
    pry_destroy_crowbar = roll_pry_destroy_crowbar();
    if pry_destroy_crowbar then begin
      variable crowbar = get_item(source_obj, PID_CROWBAR);
      rm_obj_from_inven(source_obj, crowbar);
      destroy_object(crowbar);
      if (source_obj == dude_obj) then display_msg(my_mstr(620));
      else display_msg(obj_name(source_obj) + my_mstr(621));
      return;
    end

    pry_success = roll_pry_success();
    if pry_success then begin
      set_local_var(LVAR_Locked, STATE_INACTIVE);
      obj_unlock(self_obj);
      if (source_obj == dude_obj) then begin
        display_msg(my_mstr(176));
      end else begin
        display_msg(my_mstr(181));
      end
      return;
    end

    // failure: damage
    pry_strain = roll_critical();
    if pry_strain then begin
      critter_dmg(source_obj,Crowbar_Strain,(DMG_normal_dam BWOR DMG_BYPASS_ARMOR));

      if (source_obj == dude_obj) then begin
        if (Crowbar_Strain == 1) then begin
          display_msg(my_mstr(177));
        end
        else begin
          display_msg(my_mstr(178)+Crowbar_Strain+my_mstr(179));
        end
      end

      else begin
        if (is_male(source_obj)) then begin
          if (Crowbar_Strain == 1) then begin
            display_msg(my_mstr(182));
          end
          else begin
            display_msg(my_mstr(183)+Crowbar_Strain+my_mstr(184));
          end
        end

        else begin
          if (Crowbar_Strain == 1) then begin
            display_msg(my_mstr(186));
          end
          else begin
            display_msg(my_mstr(187)+Crowbar_Strain+my_mstr(188));
          end
        end
      end
    end

    // regular failure
    if not pry_strain then begin
      if (source_obj == dude_obj) then display_msg(my_mstr(180));
      else display_msg(my_mstr(185));
    end

  end
#endif

/**********************************************************************************
This is called when the player is using an object on the door. When the check is
made to find out what is being used, obj_pid(obj_being_used_with) will need to
be checked against a prototype.
**********************************************************************************/
#ifndef custom_use_obj_on_p_proc
  procedure use_obj_on_p_proc begin
    variable Tool;
    Tool:=obj_pid(obj_being_used_with);
    pry_trap_block
    full_lockpick_block
  end
#endif

#ifndef custom_start
  procedure start begin end
#endif

/***************************************************************************
This procedure will actively set the lock on the door and set all of
the coresponding varaibles for it.
***************************************************************************/
#ifndef custom_Lock_Door
  procedure Lock_Door begin
    if (is_success(Locks_Roll)) then begin
      set_local_var(LVAR_Locked, STATE_ACTIVE);                // Door is unlocked
      obj_lock(self_obj);                                      // engine unlock door
      pcnpc_display_line(source_obj, 189, 191)

      if (local_var(LVAR_Gave_Locks_XP) == 0) then begin
        set_local_var(LVAR_Gave_Locks_XP,1);
        give_xp(Lockpick_Exp);
      end
    end

    else begin
      if (source_obj == dude_obj) then begin
        display_msg(my_mstr(190));
      end

      else begin
        display_msg(obj_name(source_obj)+my_mstr(192));
      end
    end
  end
#endif

/***************************************************************************
This procedure will allow the source_obj to lock the door that he had
just unlocked.
***************************************************************************/
#ifndef custom_Unlock_Lock
  procedure Unlock_Lock begin
    Locks_Roll:=roll_vs_skill(source_obj,SKILL_LOCKPICK,Lock_Bonus);
    call Lockpick_Door;
  end
#endif
#ifndef custom_Lockpick_Lock
  procedure Lockpick_Lock begin
    Locks_Roll:=roll_vs_skill(source_obj,SKILL_LOCKPICK,Lockpick_Bonus);
    call Lockpick_Door;
  end
#endif
#ifndef custom_Set_Lock
  procedure Set_Lock begin
    Locks_Roll:=roll_vs_skill(source_obj,SKILL_LOCKPICK,Lock_Bonus);
    call Lock_Door;
  end
#endif
#ifndef custom_Set_Lockpick_Lock
  procedure Set_Lockpick_Lock begin
    Locks_Roll:=roll_vs_skill(source_obj,SKILL_LOCKPICK,Lockpick_Bonus);
    call Lock_Door;
  end
#endif
#ifndef custom_Super_Lockpick_Lock
  procedure Super_Lockpick_Lock begin
    Locks_Roll:=roll_vs_skill(source_obj,SKILL_LOCKPICK,Exd_Lockpick_Bonus);
    call Lockpick_Door();
  end
#endif
#ifndef custom_Super_Set_Lockpick_Lock
  procedure Super_Set_Lockpick_Lock begin
    Locks_Roll:=roll_vs_skill(source_obj,SKILL_LOCKPICK,Exd_Lockpick_Bonus);
    call Lock_Door;
  end
#endif

/***************************************************************************
This procedure will check against the roll_vs_lockpick to see if the
source_object will unlock the door and display the appropriate messages
***************************************************************************/
#ifndef custom_Lockpick_Door
  procedure Lockpick_Door begin
    if (is_success(Locks_Roll)) then begin
      set_local_var(LVAR_Locked, STATE_INACTIVE);              // Door is unlocked
      obj_unlock(self_obj);                                    // engine unlock door

      if (source_obj == dude_obj) then begin
        display_msg(my_mstr(170));
      end

      else begin
        display_msg(obj_name(source_obj)+my_mstr(173));
      end

      if (local_var(LVAR_Gave_Locks_XP) == 0) then begin
        set_local_var(LVAR_Gave_Locks_XP,1);
        give_xp(Lockpick_Exp);
      end
    end

    else if (is_critical(Locks_Roll)) then begin
      jam_lock(self_obj);

      if (source_obj == dude_obj) then begin
        display_msg(my_mstr(171));
      end

      else begin
        display_msg(obj_name(source_obj)+my_mstr(174));
      end
    end

    else begin
      if (source_obj == dude_obj) then begin
        display_msg(my_mstr(172));
      end

      else begin
        display_msg(obj_name(source_obj)+my_mstr(175));
      end
    end
  end
#endif

/***************************************************************************
This procedure will do a skill check vs traps to determine if the player
or NPC finds the trap. If the trap is found, then it will check to see if
the player or NPC set off the trap or disarms it.
***************************************************************************/
#ifndef custom_Disarm_Traps
  procedure Disarm_Traps begin
    if (is_success(Traps_Roll)) then begin
      if (local_var(LVAR_Found_Trap) == 0) then begin
        set_local_var(LVAR_Found_Trap,1);
        if (source_obj == dude_obj) then begin
          display_msg(my_mstr(194));
        end

        else begin
          display_msg(my_mstr(199));
        end

        if (local_var(LVAR_Gave_Traps_XP) == 0) then begin
          set_local_var(LVAR_Gave_Traps_XP,1);
          give_xp(Traps_Exp);
        end
      end

      else begin
        set_local_var(LVAR_Trapped,STATE_INACTIVE);
        if (source_obj == dude_obj) then begin
          display_msg(my_mstr(196));
        end

        else begin
          display_msg(obj_name(source_obj)+my_mstr(201));
        end
      end
    end

    else if (is_critical(Traps_Roll)) then begin
      call Damage_Critter;
    end
    else call trap_search_result(LVAR_Found_Trap, source_obj);
  end
#endif

// explosion that uses real item stats
procedure real_explosion(variable explosive) begin
  variable dmg = get_explosion_damage(obj_pid(explosive));
  pcnpc_display_line(source_obj, 610, 611)
  explosion(source_tile, self_elevation, random(dmg[0], dmg[1]));
end

/*********************************************************************************
This procedure will allow the player to set traps on doors behind him. The door
will need to be closed, as all traps are set to go off if the door is openned.
*********************************************************************************/
#ifndef custom_Set_Trap
  procedure Set_Trap begin
    variable Explosive;
    variable Removal_Counter;

    /* Trap_Roll is a global variable to this script, defined at the beginning
    of the script. */
    Traps_Roll:=roll_vs_skill(source_obj,SKILL_TRAPS,Trap_Set_Bonus);

    Explosive:=obj_being_used_with;

    if (obj_is_open(self_obj)) then begin
      script_overrides;
      if (source_obj == dude_obj) then begin
        display_msg(my_mstr(206));
      end

      else begin
        display_msg(obj_name(source_obj)+my_mstr(207));
      end
    end
    else begin
      script_overrides;
      Removal_Counter:=rm_mult_objs_from_inven(source_obj,Explosive,1);

      reg_anim_clear(dude_obj);
      reg_anim_begin();
        reg_anim_animate(dude_obj,ANIM_magic_hands_middle,-1);
      reg_anim_end();

      if (is_success(Traps_Roll)) then begin
        destroy_object(Explosive);
        set_local_var(LVAR_Trapped,STATE_ACTIVE);
        if (source_obj == dude_obj) then begin
          display_msg(my_mstr(208));
        end
        else begin
          display_msg(obj_name(source_obj)+my_mstr(210));
        end
      end

      else if (is_critical(Traps_Roll)) then begin // crit fail, explode
        call real_explosion(Explosive);
      end else begin
        if (source_obj == dude_obj) then begin
          display_msg(my_mstr(209));
        end

        else begin
          display_msg(obj_name(source_obj)+my_mstr(211));
        end
      end
    end
  end
#endif


/*********************************************************************************
This procedure will do a standard Traps roll to see if the player can
find and remove traps from the door.
*********************************************************************************/
#ifndef custom_Skill_Disarm_Traps
  procedure Skill_Disarm_Traps begin
    /* Trap_Roll is a global variable to this script, defined at the beginning
    of the script. */
    Traps_Roll:=roll_vs_skill(source_obj,SKILL_TRAPS,Trap_Bonus);
    call Disarm_Traps;
  end
#endif

/*********************************************************************************
This is the set of conditions for when you look at a locked door, based on your
lockpick skill and perception to notice the lock.
*********************************************************************************/
#ifndef custom_Look_Locks
  procedure Look_Locks begin
    variable Perception_Roll;
    variable Locks_Check;

    Perception_Roll = roll_vs_stat(dude_obj, STAT_pe, 0);
    Locks_Check:=roll_vs_skill(dude_obj,SKILL_LOCKPICK,0);

    if (is_success(Perception_Roll)) then begin
      if is_critical(Perception_Roll) then begin
        if (is_success(Locks_Check)) then begin
          if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(114));
          end                                              // Critical Success (Locks)

          else begin
            display_msg(my_mstr(115));
          end                                              // Regular Success (Locks)
        end

        else if (is_critical(Locks_Check)) then begin
          display_msg(my_mstr(116));
        end                                                  // Critical Failure (Locks)

        else begin
          display_msg(my_mstr(117));
        end                                                  // Regular Failure (Locks)
      end                                                      // Critical Success (Stat_Pe)

      else begin
        if (is_success(Locks_Check)) then begin
          if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(130));
          end                                              // Critical Success (Locks)

          else begin
            display_msg(my_mstr(131));
          end                                              // Regular Success (Locks)
        end

        else if (is_critical(Locks_Check)) then begin
          display_msg(my_mstr(132));
        end                                                  // Critical Failure (Locks)

        else begin
          display_msg(my_mstr(133));
        end                                                  // Regular Failure (Locks)
      end                                                      // Regular Success (Stat_pe)
    end

    else if is_critical(Perception_Roll) then begin
      if (is_success(Locks_Check)) then begin
        if (is_critical(Locks_Check)) then begin
          display_msg(my_mstr(146));
        end                                                  // Critical Success (Locks)

        else begin
          display_msg(my_mstr(147));
        end                                                  // Regular Success (Locks)
      end

      else if (is_critical(Locks_Check)) then begin
        display_msg(my_mstr(148));
      end                                                      // Critical Failure (Locks)

      else begin
        display_msg(my_mstr(149));
      end                                                      // Regular Failure (Locks)
    end                                                          // Critical Failure (Stat_pe)

    else begin
      if (is_success(Locks_Check)) then begin
        if (is_critical(Locks_Check)) then begin
          display_msg(my_mstr(162));
        end                                                  // Critical Success (Locks)

        else begin
          display_msg(my_mstr(163));
        end                                                  // Regular Success (Locks)
      end

      else if (is_critical(Locks_Check)) then begin
        display_msg(my_mstr(164));
      end                                                      // Critical Failure (Locks)

      else begin
        display_msg(my_mstr(165));
      end                                                      // Regular Failure (Locks)
    end                                                          // Regular Failure (Stat_Pe)
  end
#endif

/**********************************************************************************
This is the set of conditions for when you look at a trapped door, based on your
traps skill and perception to notice the trap.
**********************************************************************************/
#ifndef custom_Look_Traps
  procedure Look_Traps begin
    variable Perception_Roll;
    variable Traps_Check;

    Perception_Roll = roll_vs_stat(dude_obj, STAT_pe, 0);
    Traps_Check:=roll_vs_skill(dude_obj,SKILL_TRAPS,0);

    if (is_success(Perception_Roll)) then begin
      if is_critical(Perception_Roll) then begin
        if (is_success(Traps_Check)) then begin
          if (is_critical(Traps_Check)) then begin
            display_msg(my_mstr(104));
          end                                              // Critical Success (traps)

          else begin
            display_msg(my_mstr(108));
          end                                              // Regular Success (Traps)
        end

        else if (is_critical(Traps_Check)) then begin
          display_msg(my_mstr(112));
        end                                                  // Critical Failure (Traps)

        else begin
          display_msg(my_mstr(116));
        end                                                  // Regular Failure (Traps)
      end                                                      // Critical Success (Stat_Pe)

      else begin
        if (is_success(Traps_Check)) then begin
          if (is_critical(Traps_Check)) then begin
            display_msg(my_mstr(120));
          end                                              // Critical Success (traps)

          else begin
            display_msg(my_mstr(124));
          end                                              // Regular Success (Traps)
        end

        else if (is_critical(Traps_Check)) then begin
          display_msg(my_mstr(128));
        end                                                  // Critical Failure (Traps)

        else begin
          display_msg(my_mstr(132));
        end                                                  // Regular Failure (Traps)
      end                                                      // Regular Success (Stat_pe)
    end

    else if is_critical(Perception_Roll) then begin
      if (is_success(Traps_Check)) then begin
        if (is_critical(Traps_Check)) then begin
          display_msg(my_mstr(136));
        end                                                  // Critical Success (traps)

        else begin
          display_msg(my_mstr(140));
        end                                                  // Regular Success (Traps)
      end

      else if (is_critical(Traps_Check)) then begin
        display_msg(my_mstr(144));
      end                                                      // Critical Failure (Traps)

      else begin
        display_msg(my_mstr(148));
      end                                                      // Regular Failure (Traps)
    end                                                          // Critical Failure (Stat_pe)

    else begin
      if (is_success(Traps_Check)) then begin
        if (is_critical(Traps_Check)) then begin
          display_msg(my_mstr(152));
        end                                                  // Critical Success (traps)

        else begin
          display_msg(my_mstr(156));
        end                                                  // Regular Success (Traps)
      end

      else if (is_critical(Traps_Check)) then begin
        display_msg(my_mstr(160));
      end                                                      // Critical Failure (Traps)

      else begin
        display_msg(my_mstr(164));
      end                                                      // Regular Failure (Traps)
    end                                                          // Regular Failure (Stat_Pe)

  end
#endif

/*************************************************************************************
This is the set of conditions for when you look at a locked and trapped door, based
on your lockpick and traps skills and perception to notice things.
*************************************************************************************/
#ifndef custom_Look_Traps_And_Locks
  procedure Look_Traps_And_Locks begin
    variable Perception_Roll;
    variable Traps_Check;
    variable Locks_Check;

    Perception_Roll = roll_vs_stat(dude_obj, STAT_pe, 0);
    Traps_Check:=roll_vs_skill(dude_obj,SKILL_TRAPS,0);
    Locks_Check:=roll_vs_skill(dude_obj,SKILL_LOCKPICK,0);

    if (is_success(Perception_Roll)) then begin

      /*************************************************************************************************/

      /* Critical Success of a Perception Check  (Start)*/

      if is_critical(Perception_Roll) then begin

        if (is_success(Traps_Check)) then begin
          set_local_var(LVAR_Found_Trap,1);                // player has found the trap

          /* Critical Success of a Traps Check  (Start)*/

          if (is_critical(Traps_Check)) then begin

            if (is_success(Locks_Check)) then begin
              if (is_critical(Locks_Check)) then begin
                display_msg(my_mstr(102));
              end                                      // critical success (Locks)

              else begin
                display_msg(my_mstr(103));
              end                                      // regular success (Locks)
            end

            else if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(104));
            end                                          // critical Failure (Locks)

            else begin
              display_msg(my_mstr(105));
            end                                          // end of regular failure (Locks)
          end                                              // critical success (Traps)

          /* Success of a Traps Check  (Start)*/

          else begin
            if (is_success(Locks_Check)) then begin
              if (is_critical(Locks_Check)) then begin
                display_msg(my_mstr(106));
              end                                      // critical success (Locks)

              else begin
                display_msg(my_mstr(107));
              end                                      // regular success (Locks)
            end

            else if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(108));
            end                                          // critical Failure (Locks)

            else begin
              display_msg(my_mstr(109));
            end                                          // end of regular failure (Locks)
          end                                              // regular success (Traps)
        end

        /* Critical Failure of a Traps Check  (Start)*/

        else if (is_critical(Traps_Check)) then begin
          if (is_success(Locks_Check)) then begin
            if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(110));
            end                                          // critical success (Locks)

            else begin
              display_msg(my_mstr(111));
            end                                          // regular success (Locks)
          end

          else if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(112));
          end                                              // critical Failure (Locks)

          else begin
            display_msg(my_mstr(113));
          end                                              // end of regular failure (Locks)
        end                                                   // critical Failure (Traps)

        /* Failure of a Traps Check  (Start)*/

        else begin
          if (is_success(Locks_Check)) then begin
            if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(114));
            end                                          // critical success (Locks)

            else begin
              display_msg(my_mstr(115));
            end                                          // regular success (Locks)
          end

          else if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(116));
          end                                              // critical Failure (Locks)

          else begin
            display_msg(my_mstr(117));
          end                                              // end of regular failure (Locks)
        end                                                  // regular failure (Traps)
      end                                                      // critical success (Stat_Pe)

      /* Critical Success of a Perception Check  (Finish)*/

      /*************************************************************************************************/

      /* Success of a Perception Check  (Start)*/

      else begin
        if (is_success(Traps_Check)) then begin
          set_local_var(LVAR_Found_Trap,1);                // player has found the trap

          /* Critical Success of a Traps Check  (Start)*/

          if (is_critical(Traps_Check)) then begin

            if (is_success(Locks_Check)) then begin
              if (is_critical(Locks_Check)) then begin
                display_msg(my_mstr(118));
              end                                      // critical success (Locks)

              else begin
                display_msg(my_mstr(119));
              end                                      // regular success (Locks)
            end

            else if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(120));
            end                                          // critical Failure (Locks)

            else begin
              display_msg(my_mstr(121));
            end                                          // end of regular failure (Locks)
          end                                              // critical success (Traps)

          /* Success of a Traps Check  (Start)*/

          else begin
            if (is_success(Locks_Check)) then begin
              if (is_critical(Locks_Check)) then begin
                display_msg(my_mstr(122));
              end                                      // critical success (Locks)

              else begin
                display_msg(my_mstr(123));
              end                                      // regular success (Locks)
            end

            else if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(124));
            end                                          // critical Failure (Locks)

            else begin
              display_msg(my_mstr(125));
            end                                          // end of regular failure (Locks)
          end                                              // regular success (Traps)
        end

        /* Critical Failure of a Traps Check  (Start)*/

        else if (is_critical(Traps_Check)) then begin
          if (is_success(Locks_Check)) then begin
            if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(126));
            end                                          // critical success (Locks)

            else begin
              display_msg(my_mstr(127));
            end                                          // regular success (Locks)
          end

          else if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(128));
          end                                              // critical Failure (Locks)

          else begin
            display_msg(my_mstr(129));
          end                                              // end of regular failure (Locks)
        end                                                  // critical Failure (Traps)

        /* Failure of a Traps Check  (Start)*/

        else begin
          if (is_success(Locks_Check)) then begin
            if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(130));
            end                                          // critical success (Locks)

            else begin
              display_msg(my_mstr(131));
            end                                          // regular success (Locks)
          end

          else if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(132));
          end                                              // critical Failure (Locks)

          else begin
            display_msg(my_mstr(133));
          end                                              // end of regular failure (Locks)
        end                                                  // regular failure (Traps)
      end                                                      // regular success (Stat_pe)
    end

    /* Success of a Perception Check  (Finish)*/

    /*************************************************************************************************/

    /* Critical Failure of a Perception Check  (Start)*/

    else if is_critical(Perception_Roll) then begin
      if (is_success(Traps_Check)) then begin
        set_local_var(LVAR_Found_Trap,1);                    // player has found the trap

        /* Critical Success of a Traps Check  (Start)*/

        if (is_critical(Traps_Check)) then begin

          if (is_success(Locks_Check)) then begin
            if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(134));
            end                                          // critical success (Locks)

            else begin
              display_msg(my_mstr(135));
            end                                          // regular success (Locks)
          end

          else if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(136));
          end                                              // critical Failure (Locks)

          else begin
            display_msg(my_mstr(137));
          end                                              // end of regular failure (Locks)
        end                                                  // critical success (Traps)

        /* Success of a Traps Check  (Start)*/

        else begin
          if (is_success(Locks_Check)) then begin
            if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(138));
            end                                          // critical success (Locks)

            else begin
              display_msg(my_mstr(139));
            end                                          // regular success (Locks)
          end

          else if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(140));
          end                                              // critical Failure (Locks)

          else begin
            display_msg(my_mstr(141));
          end                                              // end of regular failure (Locks)
        end                                                  // regular success (Traps)
      end

      /* Critical Failure of a Traps Check  (Start)*/

      else if (is_critical(Traps_Check)) then begin
        if (is_success(Locks_Check)) then begin
          if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(142));
          end                                              // critical success (Locks)

          else begin
            display_msg(my_mstr(143));
          end                                              // regular success (Locks)
        end

        else if (is_critical(Locks_Check)) then begin
          display_msg(my_mstr(144));
        end                                                  // critical Failure (Locks)

        else begin
          display_msg(my_mstr(145));
        end                                                  // end of regular failure (Locks)
      end                                                      // critical Failure (Traps)

      /* Failure of a Traps Check  (Start)*/

      else begin
        if (is_success(Locks_Check)) then begin
          if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(146));
          end                                              // critical success (Locks)

          else begin
            display_msg(my_mstr(147));
          end                                              // regular success (Locks)
        end

        else if (is_critical(Locks_Check)) then begin
          display_msg(my_mstr(148));
        end                                                  // critical Failure (Locks)

        else begin
          display_msg(my_mstr(149));
        end                                                  // end of regular failure (Locks)
      end                                                      // regular failure (Traps)
    end                                                          // Critical Failure (Stat_pe)

    /* Critical Failure of a Perception Check  (Finish)*/

    /*************************************************************************************************/

    /* Failure of a Perception Check  (Start)*/

    else begin
      if (is_success(Traps_Check)) then begin
        set_local_var(LVAR_Found_Trap,1);                    // player has found the trap

        /* Critical Success of a Traps Check  (Start)*/

        if (is_critical(Traps_Check)) then begin

          if (is_success(Locks_Check)) then begin
            if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(150));
            end                                          // critical success (Locks)

            else begin
              display_msg(my_mstr(151));
            end                                          // regular success (Locks)
          end

          else if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(152));
          end                                              // critical Failure (Locks)

          else begin
            display_msg(my_mstr(153));
          end                                              // end of regular failure (Locks)
        end                                                  // critical success (Traps)

        /* Success of a Traps Check  (Start)*/

        else begin
          if (is_success(Locks_Check)) then begin
            if (is_critical(Locks_Check)) then begin
              display_msg(my_mstr(154));
            end                                          // critical success (Locks)

            else begin
              display_msg(my_mstr(155));
            end                                          // regular success (Locks)
          end

          else if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(156));
          end                                              // critical Failure (Locks)

          else begin
            display_msg(my_mstr(157));
          end                                              // end of regular failure (Locks)
        end                                                  // regular success (Traps)
      end

      /* Critical Failure of a Traps Check  (Start)*/

      else if (is_critical(Traps_Check)) then begin
        if (is_success(Locks_Check)) then begin
          if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(158));
          end                                              // critical success (Locks)

          else begin
            display_msg(my_mstr(159));
          end                                              // regular success (Locks)
        end

        else if (is_critical(Locks_Check)) then begin
          display_msg(my_mstr(160));
        end                                                  // critical Failure (Locks)

        else begin
          display_msg(my_mstr(161));
        end                                                  // end of regular failure (Locks)
      end                                                      // critical Failure (Traps)

      /* Failure of a Traps Check  (Start)*/

      else begin
        if (is_success(Locks_Check)) then begin
          if (is_critical(Locks_Check)) then begin
            display_msg(my_mstr(162));
          end                                              // critical success (Locks)

          else begin
            display_msg(my_mstr(163));
          end                                              // regular success (Locks)
        end

        else if (is_critical(Locks_Check)) then begin
          display_msg(my_mstr(164));
        end                                                  // critical Failure (Locks)

        else begin
          display_msg(my_mstr(165));
        end                                                  // end of regular failure (Locks)
      end                                                      // regular failure (Traps)
    end                                                          // Regular Failure (Stat_pe)

    /* Failure of a Perception Check  (Finish)*/

  end
#endif

/**
 * Standard door/container map_enter_p_proc, full body split for easy reuse in customized scripts
 */
procedure map_enter_p_proc_vanilla begin
  /* Don't change state when player is already on the map */
  if is_loading_game then return;

  /* Set up the state vars when the player first enters the map */
  if (local_var(LVAR_Set_Door_Status) == 0) then begin
    set_local_var(LVAR_Set_Door_Status, 1);
    set_local_var(LVAR_Locked, LOCKED_STATUS);
    set_local_var(LVAR_Trapped, TRAPPED_STATUS);
  end

  /* Set up the state when the player enters the map */
  if (local_var(LVAR_Locked) == STATE_ACTIVE) then begin
    call close_and_lock_self;
  end else begin
    obj_unlock(self_obj);
  end
end

/***************************************************************************************
Whenever the map is first entered, this procedure will be called. The main purpose of
this procedure is to lock the door from the outset, rather than having to worry about
it through Mapper. After the door has been unlocked, it will remain as such, unless
the player locks it once more.
***************************************************************************************/
#ifndef custom_map_enter_p_proc
  procedure map_enter_p_proc begin
    call map_enter_p_proc_vanilla;
  end
#endif

/**************************************************************************************
This procedure gets called roughly every 30 seconds of real time. It is used to make
sure that the door does not lock on it's own and that the player will be able to get
through once he has unlocked the door. Once more, this is so that locking and
unlocking do not need to be done in Mapper.
**************************************************************************************/
#ifndef custom_map_update_p_proc
  procedure map_update_p_proc begin
    if (local_var(LVAR_Locked) == STATE_ACTIVE) then begin
      obj_lock(self_obj);
    end

    else begin
      obj_unlock(self_obj);
    end
  end
#endif

/**********************************************************************************
Should the player try using a skill on the door, here are where the skill rolls
will be made. The ones which need to be in here are: Lockpick and Traps. Science
and Repair can be added to this list to give more information about the door.
**********************************************************************************/
#ifndef custom_use_skill_on_p_proc
  procedure use_skill_on_p_proc begin
    variable Skill_Used;

    Skill_Used:=action_being_used;

    if (Skill_Used == SKILL_LOCKPICK) then begin
      script_overrides; //added by killap
      if (local_var(LVAR_Locked) == STATE_ACTIVE) then begin
        call Unlock_Lock;
      end
      else begin
        call Set_Lock;
      end
    end                                                          // End of Skill_Lockpick

    else if (Skill_Used == SKILL_TRAPS) then begin
      script_overrides; //added by killap
      if (local_var(LVAR_Trapped) == STATE_ACTIVE) then begin
        call Skill_Disarm_Traps;
      end
      else begin
        if (source_obj == dude_obj) then begin
          display_msg(my_mstr(195));
        end

        else begin
          display_msg(obj_name(source_obj)+my_mstr(200));
        end
      end
    end                                                          // End of Skill_Traps
  end
#endif

// Unbiased critical, used for prying with Crowbar.
procedure roll_critical begin
  variable rnd = random(1,20);
  if rnd == 20 then return true;
  return false;
end

#endif // DOORS_CONTAINERS_H
