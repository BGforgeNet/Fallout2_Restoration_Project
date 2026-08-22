// Security robots specific commands, included after LVARs
// Uses SCRIPT_WCSECBOT for messages

#ifndef ROBOTS_H
#define ROBOTS_H

#define bot_mstr(x) message_str(SCRIPT_WCSECBOT, x)
#define bot_display_mstr(x) display_msg(bot_mstr(x))

procedure robot_self_arm (
  variable rocket_min = 2,
  variable rocket_max = 3,
  variable bullets_min = 1,
  variable bullets_max = 3,
  variable shells_min = 1,
  variable shells_max = 3
) begin
  variable Ammo1;
  variable Ammo2;
  variable Amount1;
  variable Amount2;
  variable Weapon1;
  variable Weapon2;

  if (local_var(LVAR_Initialized_Ammo) == 0) then begin
    set_local_var(LVAR_Initialized_Ammo,1);
    if (self_pid == PID_MISSILE_BOT) then begin
      if (random(0,1) == 1) then begin
        Ammo1:=create_object(PID_ROBO_ROCKET_AMMO,0,0);
        Amount1:=random(rocket_min,rocket_max);

        Weapon1:=create_object(PID_ROBO_ROCKET_LAUNCHER,0,0);

        set_local_var(LVAR_Ammo_Rocket,Amount1);
        set_local_var(LVAR_Ammo_5mm,-1);
        set_local_var(LVAR_Ammo_Shells,-1);
      end else begin
        Ammo1:=create_object(PID_5MM_AP,0,0);
        Amount1:=random(bullets_min,bullets_max);

        Weapon1:=create_object(PID_MINIGUN,0,0);

        set_local_var(LVAR_Ammo_Rocket,-1);
        set_local_var(LVAR_Ammo_5mm,Amount1);
        set_local_var(LVAR_Ammo_Shells,-1);
      end
      add_mult_objs_to_inven(self_obj,Ammo1,Amount1);
      add_mult_objs_to_inven(self_obj,Weapon1,1);
    end
    else if (self_pid == PID_TOUGH_MISSILE_BOT) then begin
      Ammo1:=create_object(PID_ROBO_ROCKET_AMMO,0,0);
      Ammo2:=create_object(PID_5MM_AP,0,0);

      Amount1:=random(rocket_min,rocket_max);
      Amount2:=random(bullets_min,bullets_max);

      Weapon1:=create_object(PID_MINIGUN,0,0);
      Weapon2:=create_object(PID_ROBO_ROCKET_LAUNCHER,0,0);

      add_mult_objs_to_inven(self_obj,Ammo1,Amount1);
      add_mult_objs_to_inven(self_obj,Ammo2,Amount2);
      add_mult_objs_to_inven(self_obj,Weapon1,1);
      add_mult_objs_to_inven(self_obj,Weapon2,1);

      set_local_var(LVAR_Ammo_Rocket,Amount1);
      set_local_var(LVAR_Ammo_5mm,Amount2);
      set_local_var(LVAR_Ammo_Shells,-1);
    end
    else if (self_pid == PID_ROBOBRAIN) then begin
      Ammo1:=create_object(PID_SHOTGUN_SHELLS,0,0);
      Amount1:=random(shells_min,shells_max);

      Weapon1:=create_object(PID_COMBAT_SHOTGUN,0,0);

      add_mult_objs_to_inven(self_obj,Ammo1,Amount1);
      add_mult_objs_to_inven(self_obj,Weapon1,1);

      set_local_var(LVAR_Ammo_Rocket,-1);
      set_local_var(LVAR_Ammo_5mm,-1);
      set_local_var(LVAR_Ammo_Shells,Amount1);
    end
  end
end

procedure robot_use_repair(variable bonus = 0) begin
  if (skill_success(dude_obj,SKILL_REPAIR, -40 + bonus)) then begin
    script_overrides;
    bot_display_mstr(150);
    if (local_var(LVAR_Gave_Exp) == 0) then begin
      set_local_var(LVAR_Gave_Exp,1);
      give_xp(EXP_DISABLE_ROBOT);
    end
    set_local_var(LVAR_Active,1);
  end else begin
    bot_display_mstr(151);
    critter_heal(self_obj,self_max_hits-self_cur_hits);
    if (local_var(LVAR_Gave_Exp) == 0) then begin
      set_local_var(LVAR_Gave_Exp,1);
      give_xp(EXP_REPAIR_NEG_40);
    end
  end
end

procedure robot_use_skill(variable bonus = 0) begin
  variable Skill = action_being_used;
  if (Skill == SKILL_REPAIR) then call robot_use_repair(0);
  if (Skill == SKILL_STEAL) then script_overrides;
end

procedure robot_use_obj begin
  variable Tool = obj_pid(obj_being_used_with);
  if Tool == PID_MULTI_TOOL then call robot_use_repair(20);
  if Tool == PID_SUPER_TOOL_KIT then call robot_use_repair(40);
end

#endif  // ROBOTS_H
