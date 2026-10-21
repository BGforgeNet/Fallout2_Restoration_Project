/*
	Copyright 1998-2003 Interplay Entertainment Corp.  All rights reserved.
*/

#ifndef CARAVAN_H
#define CARAVAN_H

/**********************************************************
   All thing great and important to know about Caravans
   for travel on the world map and beyond
**********************************************************/


// Set States for the Caravan
#define set_caravan_status(x)               set_global_var(GVAR_CARAVAN_STATUS,x)
#define set_caravan_start(x)                set_global_var(GVAR_CARAVAN_START,x)
#define set_caravan_end(x)                  set_global_var(GVAR_CARAVAN_END,x)

#define set_caravan_masters(x)              set_global_var(GVAR_CARAVAN_MASTERS_TOTAL,x);               \
                                            set_global_var(GVAR_CARAVAN_MASTERS,x)
#define set_caravan_drivers(x)              set_global_var(GVAR_CARAVAN_DRIVERS_TOTAL,x);               \
                                            set_global_var(GVAR_CARAVAN_DRIVERS,x)
#define set_caravan_guards(x)               set_global_var(GVAR_CARAVAN_GUARDS_TOTAL,x);                \
                                            set_global_var(GVAR_CARAVAN_GUARDS,x)
#define set_caravan_brahmin(x)              set_global_var(GVAR_CARAVAN_BRAHMIN_TOTAL,x);               \
                                            set_global_var(GVAR_CARAVAN_BRAHMIN,x)
#define set_caravan_carts(x)                set_global_var(GVAR_CARAVAN_CARTS_TOTAL,x);                 \
                                            set_global_var(GVAR_CARAVAN_CARTS,x)
#define set_caravan_encounters(x)           set_global_var(GVAR_CARAVAN_ENCOUNTERS_TOTAL,x);            \
                                            set_global_var(GVAR_CARAVAN_ENCOUNTERS,x)

// Current Counts for the Caravan
#define caravan_masters_left                global_var(GVAR_CARAVAN_MASTERS)
#define caravan_drivers_left                global_var(GVAR_CARAVAN_DRIVERS)
#define caravan_guards_left                 global_var(GVAR_CARAVAN_GUARDS)
#define caravan_brahmin_left                global_var(GVAR_CARAVAN_BRAHMIN)
#define caravan_carts_left                  global_var(GVAR_CARAVAN_CARTS)
#define encounters_left                     global_var(GVAR_CARAVAN_ENCOUNTERS)
#define caravan_status                      global_var(GVAR_CARAVAN_STATUS)

#define caravan_total_masters               global_var(GVAR_CARAVAN_MASTERS_TOTAL)
#define caravan_total_drivers               global_var(GVAR_CARAVAN_DRIVERS_TOTAL)
#define caravan_total_guards                global_var(GVAR_CARAVAN_GUARDS_TOTAL)
#define caravan_total_brahmin               global_var(GVAR_CARAVAN_BRAHMIN_TOTAL)
#define caravan_total_carts                 global_var(GVAR_CARAVAN_CARTS_TOTAL)

// Set Lost/Destroyed States for Caravan
#define rm_caravan_masters(x)               set_global_var(GVAR_CARAVAN_MASTERS,global_var(GVAR_CARAVAN_MASTERS) - x)
#define rm_caravan_drivers(x)               set_global_var(GVAR_CARAVAN_DRIVERS,global_var(GVAR_CARAVAN_DRIVERS) - x)
#define rm_caravan_guards(x)                set_global_var(GVAR_CARAVAN_GUARDS,global_var(GVAR_CARAVAN_GUARDS) - x)
#define rm_caravan_brahmin(x)               set_global_var(GVAR_CARAVAN_BRAHMIN,global_var(GVAR_CARAVAN_BRAHMIN) - x)
#define rm_caravan_carts(x)                 set_global_var(GVAR_CARAVAN_CARTS,global_var(GVAR_CARAVAN_CARTS) - x)

// Check Killed/Lost States
#define caravan_masters_killed              (global_var(GVAR_CARAVAN_MASTERS_TOTAL) - global_var(GVAR_CARAVAN_MASTERS))
#define caravan_drivers_killed              (global_var(GVAR_CARAVAN_DRIVERS_TOTAL) - global_var(GVAR_CARAVAN_DRIVERS))
#define caravan_guards_killed               (global_var(GVAR_CARAVAN_GUARDS_TOTAL) - global_var(GVAR_CARAVAN_GUARDS))
#define caravan_brahmin_killed              (global_var(GVAR_CARAVAN_BRAHMIN_TOTAL) - global_var(GVAR_CARAVAN_BRAHMIN))
#define caravan_carts_lost                  (global_var(GVAR_CARAVAN_CARTS_TOTAL) - global_var(GVAR_CARAVAN_CARTS))

// Encounter Information
#define made_encounter                      set_global_var(GVAR_CARAVAN_ENCOUNTERS,global_var(GVAR_CARAVAN_ENCOUNTERS) - 1)
#define total_encounters                    global_var(GVAR_CARAVAN_ENCOUNTERS_TOTAL)
#define caravan_start                       global_var(GVAR_CARAVAN_START)
#define caravan_end                         global_var(GVAR_CARAVAN_END)

procedure too_many_carts begin
    if caravan_carts_left == 0 then return false;
    if caravan_brahmin_left == 0 then return true;
    if caravan_carts_left > ((caravan_brahmin_left/2) + (caravan_brahmin_left % 2)) then return true;
    return false;
end

/**
 * Rolls a new trip's crew: one master, 2-4 guards, 1-3 carts with two brahmin and a driver each.
 * Every trip sets all counters, even one without encounters, because the payout reads them and they are shared
 * between caravan lines.
 */
procedure roll_caravan_crew begin
    variable carts := random(1, 3);
    set_caravan_masters(1);
    set_caravan_guards(random(2, 4));
    set_caravan_carts(carts);
    set_caravan_brahmin(2 * carts);
    set_caravan_drivers(carts);
end

#define give_money(who,amount)              if (dude_fortune_finder) then                               \
                                                item_caps_adjust(who,2*(amount));                       \
                                            else                                                        \
                                                item_caps_adjust(who,(amount))

#endif // CARAVAN_H
