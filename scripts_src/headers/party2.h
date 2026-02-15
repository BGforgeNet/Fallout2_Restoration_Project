#ifndef PARTY2_H
#define PARTY2_H

// needs defines from define.h, so included late

procedure party_size_humans begin
   variable n := 0, type, who;
   foreach who in party_member_list_critters begin
      type := critter_kill_type(who);
      if type == KILL_TYPE_men_kills or type == KILL_TYPE_women_kills then n+=1;
   end
   return n;
end

/**
 * Returns True if any party **member** (excluding PC) is injured, False othewise.
 * @arg {bool} [only_organic=true] include only organic species
 * @ret {bool} injured
 */
procedure party_has_injured(variable only_organic = true) begin
   foreach (variable who in party_member_list_critters) begin
      if (who == dude_obj) then continue;
      if (only_organic) then begin
         variable pid;
         pid = obj_pid(who);
         if (pid == PID_CYBERDOG) or (pid == PID_K9) or (critter_kill_type(who) == KILL_TYPE_robot_kills) then continue;
      end
      if Is_Injured(who) then return true;
   end
   return false;
end

/**
 * Returns the count of injured party **members** (excluding PC)
 * @arg {bool} [only_organic=true] include only organic species
 * @ret {int} injured_count
 */
procedure party_injured_count(variable only_organic = true) begin
   variable count = 0;
   foreach (variable who in party_member_list_critters) begin
      if (who == dude_obj) then continue;
      if (only_organic) then begin
         variable pid;
         pid = obj_pid(who);
         if (pid == PID_CYBERDOG) or (pid == PID_K9) or (critter_kill_type(who) == KILL_TYPE_robot_kills) then continue;
      end
      if Is_Injured(who) then count += 1;
   end
   return count;
end

#endif // PARTY2_H
