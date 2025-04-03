//various custom commands
#ifndef UPU_H
#define UPU_H

#define upu_ini "mods\\upu.ini"
#define sec_main "main"
#define upu_setting(section, setting) get_ini_setting(upu_ini + "|" + section + "|" + setting)
#define upu_string(section, setting) get_ini_string(upu_ini + "|" + section + "|" + setting)
#define upu_msetting(setting) get_ini_setting(upu_ini + "|" + sec_main + "|" + setting)
#define set_goris_derobing "goris_derobing_speed"
#define repeatable_brahmin_drive upu_setting("ncr", "repeatable_brahmin_drive")
#define wipe_inventory upu_setting("main", "wipe_inventory")

procedure check_filesystem_override begin
   variable fs_override := get_ini_setting("ddraw.ini|Misc|UseFileSystemOverride");
   if fs_override != 1 then begin
      ndebug("UseFileSystemOverride is disabled, enabling");
      set_ini_setting("ddraw.ini|Misc|UseFileSystemOverride", 1);
      float_msg(dude_obj, SCRIPT_REALNAME + ": filesystem override was disabled, some features failed to load. The setting is corrected. EXIT AND RE-LAUNCH THE GAME now.", FLOAT_MSG_WARNING);
      return false;
   end
   return true;
end

//force use item remotely
procedure create_and_use_itempid_on(variable target, variable itempid) begin
   variable item;
   item := create_object(itempid, tile_num(target), elevation(target));
   set_self(target);
   set_self(target);
   use_obj_on_obj(item, target);
   set_self(0);
end

procedure is_human(variable who) begin
   variable type;
   type := critter_kill_type(who);
   if type == KILL_TYPE_men_kills or type == KILL_TYPE_women_kills or type == KILL_TYPE_children_kills then return true;
   return false;
end

#define is_critter(obj)    (obj_type(obj) == OBJ_TYPE_CRITTER)

//a workaround for game_time going negative after 7 years
#define restock_fix \
   if ( (game_time < 0) and (local_var(LVAR_Restock_Time_Fix) == 0) ) then begin \
      set_local_var(LVAR_Restock_Time, game_time - 1); \
      set_local_var(LVAR_Restock_Time_Fix, 1); \
   end
// only used on tribe maps
#define restock_fix_map \
   if ( (game_time < 0) and (map_var(MVAR_Restock_Time_Fix) == 0)  ) then begin \
      set_map_var(MVAR_Restock_Time, game_time - 1); \
      set_map_var(MVAR_Restock_Time_Fix, 1); \
   end

#define CUR_AREA_MILITARY_BASE            (cur_town == AREA_MILITARY_BASE)

#define self_exists (self_pid != -1)
#define destroy_self destroy_object(self_obj)

procedure closest_party_member(variable obj) begin
   variable who, cur_distance, min_distance := -1, closest_who := false;
   // only dude
   if len_array(party_member_list_critters) == 1 then return false;

   foreach who in party_member_list_critters begin
      if who != dude_obj then begin
         cur_distance := tile_distance_objs(obj, who);
         if (min_distance == -1) or (cur_distance < min_distance) then begin
            min_distance := cur_distance;
            closest_who := who;
         end
      end
   end
   return closest_who;
end



/* Reputation */
#define dude_has_cult has_trait(TRAIT_PERK, dude_obj, PERK_cult_of_personality)

// effective reputation for critter reaction or lines (Reply). NOT for dude responses (NOption, etc).
// Evil_Critter is defined in talk_p_proc, while check_general_rep happens in other procedures too, so we build a separate array for them.
procedure self_is_evil begin
   variable evil_critters := [
      // grep -R "Evil_Critter:=1" scripts_src/ | awk -F ':' '{print $1}' | xargs grep "#define SCRIPT_REALNAME" | awk '{print $3}' | sort
      // Can't use SCRIPT_NAME because it's defined in (parentheses) and sfall array syntax won't have it.
      "bcdardog",
      "bcdargrd",
      "bcdarion",
      "bcgengrd",
      "bckarla",
      "bcphil",
      "dcslvgrt",
      "ecmstden",
      "ecmstnew",
      "fcbadpea",
      "fcdaveh",
      "fcelrind",
      "fcjuavki",
      "fclopan",
      "fcoz7",
      "fcoz9",
      "ncbismen",
      "ncdrgdlr",
      "ncmormen",
      "ncramire",
      "ncsalmen",
      "ocmatt",
      "qcfrank",
      "rchakes",
      "scbuster",
      "sclenny",
      "scmerk",
      "scmira",
      "scmrkgrd",
      "scoswald",
      "scrawpat",
      "scskeete",
      "scslvgrd",
      "scvortis"
   ];
   if is_in_array(SCRIPT_REALNAME, evil_critters) then return true;
   return false;
end

// account for karma beacon
procedure beacon_rep begin
   variable rep := global_var(GVAR_PLAYER_REPUTATION);
   if has_trait(TRAIT_PERK, dude_obj, PERK_karma_beacon_perk) then rep := rep * 2;
   return rep;
end
// account for Evil_Critter, aligned with critter's good/evil. For good, more is better. For evil, less is better.
procedure cult_rep begin
   variable rep := beacon_rep;
   if dude_has_cult then begin
      rep := abs(rep);
      if self_is_evil then rep := -rep;
   end
   return rep;
end
// account for Evil_Critter, absolute "good" value. More is better.
procedure perceived_rep begin
   variable rep := beacon_rep;
   if self_is_evil then rep := -rep;
   if dude_has_cult then rep := abs(rep);
   return rep;
end
#define perceived_rep_positive (perceived_rep > 0)
#define perceived_rep_negative (perceived_rep < 0)


// call before restock
procedure move_quest_items begin
   if wipe_inventory != 1 then return 0;
   if map_first_run then return 0;
   variable tmp_box := create_object(PID_FOOTLOCKER_CLEAN_LEFT, 5, 0);
   variable pid;
   variable pids := [
      PID_ACCOUNT_BOOK,
      PID_ANNA_GOLD_LOCKET,
      PID_BECKY_BOOK,
      PID_BISHOPS_HOLODISK,
      PID_BLUE_PASS_KEY,
      //PID_CAR_FUEL_CELL,
      PID_CAR_FUEL_CELL_CONTROLLER,
      PID_CAR_FUEL_INJECTION,
      PID_CELL_DOOR_KEY,
      PID_COMPUTER_VOICE_MODULE,
      PID_CORNELIUS_GOLD_WATCH,
      PID_DAY_PASS,
      PID_DR_HENRY_PAPERS,
      //PID_ECON_HOLODISK,
      PID_ENLIGHTENED_ONE_LETTER,
      PID_EXCAVATOR_CHIP,
      PID_FAKE_CITIZENSHIP,
      PID_GECK,
      PID_GECKO_DATA_DISK,
      PID_GOLD_LOCKET,
      PID_HY_MAG_PART,
      PID_K9_MOTIVATOR,
      PID_LYNETTE_HOLO,
      PID_MOORE_BAD_BRIEFCASE,
      PID_MOORE_GOOD_BRIEFCASE,
      PID_NAV_COMPUTER_PARTS,
      PID_PLASMA_TRANSFORMER,
      PID_PRES_ACCESS_KEY,
      PID_PRESIDENTIAL_PASS,
      PID_RAMIREZ_BOX_CLOSED,
      PID_RAMIREZ_BOX_OPEN,
      PID_REACTOR_DATA_DISK,
      PID_RED_PASS_KEY,
      PID_RED_REACTOR_KEYCARD,
      PID_SMITTY_MEAL,
      PID_SPY_HOLO,
      PID_TANKER_FOB,
      PID_TRAPPER_TOWN_KEY,
      PID_V15_COMPUTER_PART,
      PID_VAULT_13_SHACK_KEY,
      PID_VERTIBIRD_PLANS,
      PID_VIC_RADIO,
      PID_VIC_WATER_FLASK,
      PID_WESTIN_HOLO,
      PID_YELLOW_PASS_KEY,
      PID_YELLOW_REACTOR_KEYCARD,

      // RPU
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
      PID_FAKE_HEART_PILLS
      // end RPU
   ];
   foreach pid in pids begin
      if (obj_is_carrying_obj_pid(self_obj, pid) > 0) then begin
         variable special_item := obj_carrying_pid_obj(self_obj, pid);
         rm_obj_from_inven(self_obj, special_item);
         add_obj_to_inven(tmp_box, special_item);
      end
   end
   variable trash_box := create_object(PID_FOOTLOCKER_CLEAN_LEFT, 0, 0);
   move_obj_inven_to_obj(self_obj, trash_box);
   destroy_object(trash_box);
   return tmp_box;
end
// call after restock
procedure restore_critical_items(variable tmp_box) begin
   if tmp_box == 0 then return;
   move_obj_inven_to_obj(tmp_box, self_obj);
   destroy_object(tmp_box);
end

#endif  // UPU_H
