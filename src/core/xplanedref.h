/*
 * File:   xplanedata.h
 * Author: Madison Treat <madison.treat@tamu.edu>
 *
 * Created on July 27, 2015, 01:30 PM
 *
 * These strings are defined for the XPlane 10.40+ Dataref requests via the RREF
 * UDP request.
 */

#ifndef XPLANEDREF_H
#define XPLANEDREF_H

//const char* XPDR_AC_TYPE = "";
const int MAX_NUM_AC_TAIL_NUMS = 40;
static const char* XPDR_AC_TAIL_NUM_X     = "sim/aircraft/view/acf_tailnum[__X__]";
static const char* XPDR_AC_TAIL_NUM_1     = "sim/aircraft/view/acf_tailnum[1]";
static const char* XPDR_AC_ENGINE_TYPE    = "sim/aircraft/prop/acf_en_type";

// Engines
const int MAX_NUM_ENGINES = 8;
static const char* XPDR_AC_NUM_ENGINES    = "sim/aircraft/engine/acf_num_engines";
/*
 * These engine values are of the form .../limits/[red|green|yellow]_[lo|hi]_[property]
 * and thus the __LT__ should be replaced with a color and "_lo" or "_hi".
 *    example: "green_lo"
 * The LimitType enum is a utility bit-masking enum for specifying the limit type.
 */
enum LimitType {
  NO_LIMIT       = 0, // Default is 0, so this can safely be used as an invalid limit
  LIMIT_LO       = 1 << 0, // 1
  LIMIT_HI       = 1 << 1, // 2
  // Bit-mask these colors with either LIMIT_HI or LIMIT_LO
  LIMIT_GREEN    = 1 << 2, // 4
  LIMIT_YELLOW   = 1 << 3, // 8
  LIMIT_RED      = 1 << 4,  // 16

  // These are the 6 different results that can be used as limits, as a short-hand to
  // avoid all the bitwise-or'ing
  LIMIT_G_LO     = LIMIT_GREEN  | LIMIT_LO,
  LIMIT_G_HI     = LIMIT_GREEN  | LIMIT_HI,
  LIMIT_Y_LO     = LIMIT_YELLOW | LIMIT_LO,
  LIMIT_Y_HI     = LIMIT_YELLOW | LIMIT_HI,
  LIMIT_R_LO     = LIMIT_RED    | LIMIT_LO,
  LIMIT_R_HI     = LIMIT_RED    | LIMIT_HI
};
static const char* XPDR_ENG_LIMIT_MP      = "sim/aircraft/limits/__LT___MP";
static const char* XPDR_ENG_LIMIT_FF      = "sim/aircraft/limits/__LT___FF";
static const char* XPDR_ENG_LIMIT_N1      = "sim/aircraft/limits/__LT___N1";
static const char* XPDR_ENG_LIMIT_N2      = "sim/aircraft/limits/__LT___N2";

static const char* XPDR_ENG_LIMIT_EPR     = "sim/aircraft/limits/__LT___EPR";
static const char* XPDR_ENG_LIMIT_EGT     = "sim/aircraft/limits/__LT___EGT";
static const char* XPDR_ENG_LIMIT_TRQ     = "sim/aircraft/limits/__LT___TRQ";
static const char* XPDR_ENG_LIMIT_ITT     = "sim/aircraft/limits/__LT___ITT";
static const char* XPDR_ENG_LIMIT_CHT     = "sim/aircraft/limits/__LT___CHT";

static const char* XPDR_ENG_LIMIT_OILP    = "sim/aircraft/limits/__LT___oilP";
static const char* XPDR_ENG_LIMIT_OILT    = "sim/aircraft/limits/__LT___oilT";
static const char* XPDR_ENG_LIMIT_FUELP   = "sim/aircraft/limits/__LT___fuelP";

// Radios
static const char* XPDR_RADIO_COM1_FREQ   = "sim/cockpit/radios/com1_freq_hz";
static const char* XPDR_RADIO_COM1_STDBY  = "sim/cockpit/radios/com1_stdby_freq_hz";
static const char* XPDR_RADIO_COM2_FREQ   = "sim/cockpit/radios/com2_freq_hz";
static const char* XPDR_RADIO_COM2_STDBY  = "sim/cockpit/radios/com2_stdby_freq_hz";

static const char* XPDR_RADIO_NAV1_FREQ   = "sim/cockpit/radios/nav1_freq_hz";
static const char* XPDR_RADIO_NAV1_STDBY  = "sim/cockpit/radios/nav1_stdby_freq_hz";
static const char* XPDR_RADIO_NAV2_FREQ   = "sim/cockpit/radios/nav2_freq_hz";
static const char* XPDR_RADIO_NAV2_STDBY  = "sim/cockpit/radios/nav2_stdby_freq_hz";

// Fuel and Tanks
const int MAX_NUM_FUEL_TANKS = 9;
static const char* XPDR_CP_FUEL_QTY_X     = "sim/cockpit2/fuel/fuel_quantity[__X__]";
static const char* XPDR_CP_FUEL_QTY_0     = "sim/cockpit2/fuel/fuel_quantity[0]";
static const char* XPDR_CP_FUEL_QTY_1     = "sim/cockpit2/fuel/fuel_quantity[1]";
static const char* XPDR_CP_FUEL_QTY_2     = "sim/cockpit2/fuel/fuel_quantity[2]";
static const char* XPDR_CP_FUEL_QTY_3     = "sim/cockpit2/fuel/fuel_quantity[3]";
static const char* XPDR_CP_FUEL_QTY_4     = "sim/cockpit2/fuel/fuel_quantity[4]";
static const char* XPDR_CP_FUEL_QTY_5     = "sim/cockpit2/fuel/fuel_quantity[5]";
static const char* XPDR_CP_FUEL_QTY_6     = "sim/cockpit2/fuel/fuel_quantity[6]";
static const char* XPDR_CP_FUEL_QTY_7     = "sim/cockpit2/fuel/fuel_quantity[7]";
static const char* XPDR_CP_FUEL_QTY_8     = "sim/cockpit2/fuel/fuel_quantity[8]";

// Current fuel weight (kgs)
static const char* XPDR_FUEL_WEIGHT       = "sim/flightmodel/weight/m_fuel_total";
// Aircraft total fuel capacity (lbs?)
static const char* XPDR_FUEL_WEIGHT_TOT   = "sim/aircraft/weight/acf_m_fuel_tot";

// Timer
// static const char* XPDR_CP_TIMER_RUNNING = "sim/cockpit2/clock_timer/timer_running";
static const char* XPDR_CP_TIMER_RUNNING  = "sim/time/timer_is_running_sec";
static const char* XPDR_CP_TIMER_ELAPSED  = "sim/time/timer_elapsed_time_sec";

// Landing Gear
const int MAX_NUM_LANDING_GEARS = 10;
static const char* XPDR_GEAR_HANDLE_STATUS= "sim/cockpit/switches/gear_handle_status";
static const char* XPDR_GEAR_RETRACTABLE  = "sim/aircraft/gear/acf_gear_retract";
static const char* XPDR_GEAR_DEPLOY_X     = "sim/aircraft/parts/acf_gear_deploy[__X__]";
static const char* XPDR_GEAR_DEPLOY_0     = "sim/aircraft/parts/acf_gear_deploy[0]";
static const char* XPDR_GEAR_DEPLOY_1     = "sim/aircraft/parts/acf_gear_deploy[1]";
static const char* XPDR_GEAR_DEPLOY_2     = "sim/aircraft/parts/acf_gear_deploy[2]";
static const char* XPDR_GEAR_DEPLOY_3     = "sim/aircraft/parts/acf_gear_deploy[3]";
static const char* XPDR_GEAR_DEPLOY_4     = "sim/aircraft/parts/acf_gear_deploy[4]";
static const char* XPDR_GEAR_DEPLOY_5     = "sim/aircraft/parts/acf_gear_deploy[5]";
static const char* XPDR_GEAR_DEPLOY_6     = "sim/aircraft/parts/acf_gear_deploy[6]";
static const char* XPDR_GEAR_DEPLOY_7     = "sim/aircraft/parts/acf_gear_deploy[7]";
static const char* XPDR_GEAR_DEPLOY_8     = "sim/aircraft/parts/acf_gear_deploy[8]";
static const char* XPDR_GEAR_DEPLOY_9     = "sim/aircraft/parts/acf_gear_deploy[9]";

// Flaps
//static const char* XPDR_FLAP_DEPLOY       = "sim/flightmodel2/controls/flap_handle_deploy_ratio";
static const char* XPDR_FLAP_DEPLOY       = "sim/flightmodel2/controls/flap1_deploy_ratio";
//static const char* XPDR_FLAP_DEPLOY       = "sim/flightmodel/controls/flaprat";
static const char* XPDR_FLAP_HANDLE_DEPLOY= "sim/cockpit2/controls/flap_ratio";
//static const char* XPDR_FLAP1_DEPLOY      = "sim/flightmodel2/controls/flap1_deploy_ratio";
//static const char* XPDR_FLAP2_DEPLOY      = "sim/flightmodel2/controls/flap2_deploy_ratio";

// Multiplayer
static const int MAX_NUM_PLANES = 19; // range: [1,19]; we are plane 0, making 20
// NOTE: the format is "plane1_psi", hence the 2 "_", X, then 3 "_"
static const char* XPDR_PLANE_X_HEADING   = "sim/multiplayer/position/plane__X___psi";
static const char* XPDR_PLANE_X_SPEED_X   = "sim/multiplayer/position/plane__X___v_x";
static const char* XPDR_PLANE_X_SPEED_Y   = "sim/multiplayer/position/plane__X___v_y";
static const char* XPDR_PLANE_X_SPEED_Z   = "sim/multiplayer/position/plane__X___v_z";

// Miscellaneous
static const char* XPDR_TIME_PAUSED       = "sim/time/paused"; // READ ONLY
static const char* XPDR_OP_PAUSE_TOGGLE   = "sim/operation/pause_toggle"; // for un/pausing

// Flight Mechanics for Derived AOA/Sideslip
/*
static const char* XPDR_U                 = "sim/flightmodel/position/indicated_airspeed";
static const char* XPDR_ALPHA             = "sim/flightmodel/position/alpha";
static const char* XPDR_Q                 = "sim/flightmodel/position/Q";
static const char* XPDR_THETA             = "sim/flightmodel/position/theta";
static const char* XPDR_BETA              = "sim/flightmodel/position/beta";
// OpenGL coordinate system velocities
static const char* XPDR_GL_VX             = "sim/flightmodel/position/local_vx";
static const char* XPDR_GL_VY             = "sim/flightmodel/position/local_vy";
static const char* XPDR_GL_VZ             = "sim/flightmodel/position/local_vz";
// OpenGL coordinate system accelerations
static const char* XPDR_GL_AX             = "sim/flightmodel/position/local_ax";
static const char* XPDR_GL_AY             = "sim/flightmodel/position/local_ay";
static const char* XPDR_GL_AZ             = "sim/flightmodel/position/local_az";
// quaternion to convert OpenGL coordinates to Aircraft coordinates
static const char* XPDR_GL2AC_Q           = "sim/flightmodel/position/q";
// */

// Weapons
// boolean: 0/1; these work
static const char* XPDR_WEP_ARM_GUNS      = "sim/cockpit/weapons/guns_armed";
static const char* XPDR_WEP_ARM_BOMBS     = "sim/cockpit/weapons/bombs_armed";
static const char* XPDR_WEP_ARM_ROCKETS   = "sim/cockpit/weapons/rockets_armed";
static const char* XPDR_WEP_ARM_MISSILES  = "sim/cockpit/weapons/missiles_armed";

static const char* XPDR_WEP_TARGET_INDEX  = "sim/cockpit/weapons/plane_target_index";

// Miscellaneous
static const char* XPDR_ALPHA             = "sim/flightmodel/position/alpha";
static const char* XPDR_BETA              = "sim/flightmodel/position/beta";
static const char* XPDR_VSCL_ALPHA_D      = "vscl/cpd/alpha_derived";
static const char* XPDR_VSCL_BETA_D       = "vscl/cpd/beta_derived";

/*
static const char* XPDR_ = "sim/";
// */

#endif
