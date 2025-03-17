// Generator version : v3.1
// DBC filename      : autonomous_module.dbc
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// DBC file version
#define VER_AUTONOMOUS_MAJ (0U)
#define VER_AUTONOMOUS_MIN (0U)

// include current dbc-driver compilation config
#include "autonomous-config.h"

#ifdef AUTONOMOUS_USE_DIAG_MONITORS
// This file must define:
// base monitor struct
#include "canmonitorutil.h"

#endif // AUTONOMOUS_USE_DIAG_MONITORS

// DLC maximum value which is used as the limit for frame's data buffer size.
// Client can set its own value (not sure why) in driver-config
// or can test it on some limit specified by application
// e.g.: static_assert(TESTDB_MAX_DLC_VALUE <= APPLICATION_FRAME_DATA_SIZE, "Max
// DLC value in the driver is too big")
#ifndef AUTONOMOUS_MAX_DLC_VALUE
// The value which was found out by generator (real max value)
#define AUTONOMOUS_MAX_DLC_VALUE 8U
#endif

// The limit is used for setting frame's data bytes
#define AUTONOMOUS_VALIDATE_DLC(msgDlc)                                        \
  (((msgDlc) <= (AUTONOMOUS_MAX_DLC_VALUE)) ? (msgDlc)                         \
                                            : (AUTONOMOUS_MAX_DLC_VALUE))

// Initial byte value to be filles in data bytes of the frame before pack
// signals User can define its own custom value in driver-config file
#ifndef AUTONOMOUS_INITIAL_BYTE_VALUE
#define AUTONOMOUS_INITIAL_BYTE_VALUE 0U
#endif

// def @LONGITUDINAL_COMMANDS_JOY CAN Message (1025 0x401)
#define LONGITUDINAL_COMMANDS_JOY_IDE (0U)
#define LONGITUDINAL_COMMANDS_JOY_DLC (8U)
#define LONGITUDINAL_COMMANDS_JOY_CANID (0x401U)
// signal: @set_gas_pedal_pos_ro
#define AUTONOMOUS_set_gas_pedal_pos_ro_CovFactor (0.01)
#define AUTONOMOUS_set_gas_pedal_pos_ro_toS(x)                                 \
  ((uint16_t)(((x) - (0.0)) / (0.01)))
#define AUTONOMOUS_set_gas_pedal_pos_ro_fromS(x) ((((x) * (0.01)) + (0.0)))
// signal: @set_brake_force_ro
#define AUTONOMOUS_set_brake_force_ro_CovFactor (32)
#define AUTONOMOUS_set_brake_force_ro_toS(x) ((uint16_t)((x) / (32)))
#define AUTONOMOUS_set_brake_force_ro_fromS(x) (((x) * (32)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // -
  uint16_t set_gas_pedal_pos_ro; //      Bits=16 Factor= 0.01 Unit:'%'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_gas_pedal_pos_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint16_t set_brake_force_ro; //      Bits=16 Factor= 32 Unit:'Newton'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint32_t set_brake_force_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#else

  // -
  uint16_t set_gas_pedal_pos_ro; //      Bits=16 Factor= 0.01 Unit:'%'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_gas_pedal_pos_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint16_t set_brake_force_ro; //      Bits=16 Factor= 32 Unit:'Newton'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint32_t set_brake_force_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} LONGITUDINAL_COMMANDS_JOY_t;

// def @VEHICLE_COMMANDS_JOY CAN Message (1026 0x402)
#define VEHICLE_COMMANDS_JOY_IDE (0U)
#define VEHICLE_COMMANDS_JOY_DLC (8U)
#define VEHICLE_COMMANDS_JOY_CANID (0x402U)

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // 0->Close, 1-> Right blinker, 2-> left blinker, 3-> hazardLight
  uint8_t blinker; //      Bits= 8 Unit:'-'

  // High Beam -> 0 off 1 on
  uint8_t headlight; //      Bits= 8 Unit:'-'

  // P-R-N-D (1-2-3-4)
  uint8_t gear; //      Bits= 8 Unit:'-'

  // 0-> manual 1-> autonomous (edge trigger)
  uint8_t mode; //      Bits= 8 Unit:'-'

  // 0-> Keep last state, 1-> release, 2->Pull
  uint8_t hand_brake; //      Bits= 8 Unit:'-'

#else

  // 0->Close, 1-> Right blinker, 2-> left blinker, 3-> hazardLight
  uint8_t blinker; //      Bits= 8 Unit:'-'

  // High Beam -> 0 off 1 on
  uint8_t headlight; //      Bits= 8 Unit:'-'

  // P-R-N-D (1-2-3-4)
  uint8_t gear; //      Bits= 8 Unit:'-'

  // 0-> manual 1-> autonomous (edge trigger)
  uint8_t mode; //      Bits= 8 Unit:'-'

  // 0-> Keep last state, 1-> release, 2->Pull
  uint8_t hand_brake; //      Bits= 8 Unit:'-'

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} VEHICLE_COMMANDS_JOY_t;

// def @FRONT_WHEEL_COMMANDS_JOY CAN Message (1027 0x403)
#define FRONT_WHEEL_COMMANDS_JOY_IDE (0U)
#define FRONT_WHEEL_COMMANDS_JOY_DLC (8U)
#define FRONT_WHEEL_COMMANDS_JOY_CANID (0x403U)
// signal: @set_steering_wheel_angle_ro
#define AUTONOMOUS_set_steering_wheel_angle_ro_CovFactor (0.02)
#define AUTONOMOUS_set_steering_wheel_angle_ro_toS(x)                          \
  ((int16_t)(((x) - (0.0)) / (0.02)))
#define AUTONOMOUS_set_steering_wheel_angle_ro_fromS(x)                        \
  ((((x) * (0.02)) + (0.0)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // -
  int16_t
      set_steering_wheel_angle_ro; //  [-] Bits=16 Factor= 0.02 Unit:'degree'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_steering_wheel_angle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t set_steering_wheel_torque; //      Bits= 8 Unit:'-'

#else

  // -
  int16_t
      set_steering_wheel_angle_ro; //  [-] Bits=16 Factor= 0.02 Unit:'degree'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_steering_wheel_angle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t set_steering_wheel_torque; //      Bits= 8 Unit:'-'

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} FRONT_WHEEL_COMMANDS_JOY_t;

// def @VEHICLE_INFO CAN Message (502203409 0x1def0411)
#define VEHICLE_INFO_IDE (1U)
#define VEHICLE_INFO_DLC (8U)
#define VEHICLE_INFO_CANID (0x1def0411U)
// signal: @vehicle_velocity_ro
#define AUTONOMOUS_vehicle_velocity_ro_CovFactor (0.01)
#define AUTONOMOUS_vehicle_velocity_ro_toS(x)                                  \
  ((uint16_t)(((x) - (0.0)) / (0.01)))
#define AUTONOMOUS_vehicle_velocity_ro_fromS(x) ((((x) * (0.01)) + (0.0)))
// signal: @steering_wheel_angle_ro
#define AUTONOMOUS_steering_wheel_angle_ro_CovFactor (0.02)
#define AUTONOMOUS_steering_wheel_angle_ro_toS(x)                              \
  ((int16_t)(((x) - (0.0)) / (0.02)))
#define AUTONOMOUS_steering_wheel_angle_ro_fromS(x) ((((x) * (0.02)) + (0.0)))
// signal: @steering_wheel_speed_ro
#define AUTONOMOUS_steering_wheel_speed_ro_CovFactor (5)
#define AUTONOMOUS_steering_wheel_speed_ro_toS(x) ((int16_t)((x) / (5)))
#define AUTONOMOUS_steering_wheel_speed_ro_fromS(x) (((x) * (5)))
// signal: @steering_tire_angle_ro
#define AUTONOMOUS_steering_tire_angle_ro_CovFactor (0.00307)
#define AUTONOMOUS_steering_tire_angle_ro_toS(x)                               \
  ((int16_t)(((x) - (0.0)) / (0.00307)))
#define AUTONOMOUS_steering_tire_angle_ro_fromS(x) ((((x) * (0.00307)) + (0.0)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // -
  uint16_t vehicle_velocity_ro; //      Bits=16 Factor= 0.01 Unit:'km/h'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t vehicle_velocity_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  int16_t steering_wheel_angle_ro; //  [-] Bits=16 Factor= 0.02 Unit:'degree'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t steering_wheel_angle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  int16_t
      steering_wheel_speed_ro; //  [-] Bits=10 Factor= 5 Unit:'degree/second'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t steering_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Steering input by driver, torque
  int16_t steering_wheel_torque; //  [-] Bits=11 Unit:'CentiNewton/m'

  // actual tire angle of the vehicle
  int16_t steering_tire_angle_ro; //  [-] Bits=11 Factor= 0.00307 Unit:'radian'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t steering_tire_angle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#else

  // -
  uint16_t vehicle_velocity_ro; //      Bits=16 Factor= 0.01 Unit:'km/h'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t vehicle_velocity_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  int16_t steering_wheel_angle_ro; //  [-] Bits=16 Factor= 0.02 Unit:'degree'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t steering_wheel_angle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  int16_t
      steering_wheel_speed_ro; //  [-] Bits=10 Factor= 5 Unit:'degree/second'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t steering_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Steering input by driver, torque
  int16_t steering_wheel_torque; //  [-] Bits=11 Unit:'CentiNewton/m'

  // actual tire angle of the vehicle
  int16_t steering_tire_angle_ro; //  [-] Bits=11 Factor= 0.00307 Unit:'radian'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t steering_tire_angle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} VEHICLE_INFO_t;

// def @VEHICLE_SIGNAL_STATUS CAN Message (502203410 0x1def0412)
#define VEHICLE_SIGNAL_STATUS_IDE (1U)
#define VEHICLE_SIGNAL_STATUS_DLC (8U)
#define VEHICLE_SIGNAL_STATUS_CANID (0x1def0412U)

// Value tables for @blinker signal

#ifndef blinker_VEHICLE_SIGNAL_STATUS_CLOSE
#define blinker_VEHICLE_SIGNAL_STATUS_CLOSE (0)
#endif

#ifndef blinker_VEHICLE_SIGNAL_STATUS_RIGHT_BLINKER
#define blinker_VEHICLE_SIGNAL_STATUS_RIGHT_BLINKER (1)
#endif

#ifndef blinker_VEHICLE_SIGNAL_STATUS_LEFT_BLINKER
#define blinker_VEHICLE_SIGNAL_STATUS_LEFT_BLINKER (2)
#endif

#ifndef blinker_VEHICLE_SIGNAL_STATUS_HAZARD_LIGHT
#define blinker_VEHICLE_SIGNAL_STATUS_HAZARD_LIGHT (3)
#endif

// Value tables for @headlight signal

#ifndef headlight_VEHICLE_SIGNAL_STATUS_HIGHBEAM_OFF
#define headlight_VEHICLE_SIGNAL_STATUS_HIGHBEAM_OFF (0)
#endif

#ifndef headlight_VEHICLE_SIGNAL_STATUS_HIGHBEAM_ON
#define headlight_VEHICLE_SIGNAL_STATUS_HIGHBEAM_ON (1)
#endif

// Value tables for @gear signal

#ifndef gear_VEHICLE_SIGNAL_STATUS_P
#define gear_VEHICLE_SIGNAL_STATUS_P (1)
#endif

#ifndef gear_VEHICLE_SIGNAL_STATUS_R
#define gear_VEHICLE_SIGNAL_STATUS_R (2)
#endif

#ifndef gear_VEHICLE_SIGNAL_STATUS_N
#define gear_VEHICLE_SIGNAL_STATUS_N (3)
#endif

#ifndef gear_VEHICLE_SIGNAL_STATUS_D
#define gear_VEHICLE_SIGNAL_STATUS_D (4)
#endif

// Value tables for @target_gear_level signal

#ifndef target_gear_level_VEHICLE_SIGNAL_STATUS_P
#define target_gear_level_VEHICLE_SIGNAL_STATUS_P (5)
#endif

#ifndef target_gear_level_VEHICLE_SIGNAL_STATUS_R
#define target_gear_level_VEHICLE_SIGNAL_STATUS_R (6)
#endif

#ifndef target_gear_level_VEHICLE_SIGNAL_STATUS_N
#define target_gear_level_VEHICLE_SIGNAL_STATUS_N (7)
#endif

#ifndef target_gear_level_VEHICLE_SIGNAL_STATUS_D
#define target_gear_level_VEHICLE_SIGNAL_STATUS_D (8)
#endif

#ifndef target_gear_level_VEHICLE_SIGNAL_STATUS_S
#define target_gear_level_VEHICLE_SIGNAL_STATUS_S (9)
#endif

#ifndef target_gear_level_VEHICLE_SIGNAL_STATUS_E
#define target_gear_level_VEHICLE_SIGNAL_STATUS_E (10)
#endif

#ifndef target_gear_level_VEHICLE_SIGNAL_STATUS_T
#define target_gear_level_VEHICLE_SIGNAL_STATUS_T (14)
#endif

// Value tables for @hand_brake signal

#ifndef hand_brake_VEHICLE_SIGNAL_STATUS_RELEASED
#define hand_brake_VEHICLE_SIGNAL_STATUS_RELEASED (0)
#endif

#ifndef hand_brake_VEHICLE_SIGNAL_STATUS_ENGAGED
#define hand_brake_VEHICLE_SIGNAL_STATUS_ENGAGED (1)
#endif

#ifndef hand_brake_VEHICLE_SIGNAL_STATUS_RELEASING
#define hand_brake_VEHICLE_SIGNAL_STATUS_RELEASING (3)
#endif

// Value tables for @mode signal

#ifndef mode_VEHICLE_SIGNAL_STATUS_CONTROLLER_DRIVER
#define mode_VEHICLE_SIGNAL_STATUS_CONTROLLER_DRIVER (0)
#endif

#ifndef mode_VEHICLE_SIGNAL_STATUS_CONTROLLER_JOYSTICK
#define mode_VEHICLE_SIGNAL_STATUS_CONTROLLER_JOYSTICK (1)
#endif

#ifndef mode_VEHICLE_SIGNAL_STATUS_CONTROLLER_AUTONOMOUS
#define mode_VEHICLE_SIGNAL_STATUS_CONTROLLER_AUTONOMOUS (2)
#endif

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // Fuel level.
  uint8_t fuel; //      Bits= 8 Unit:'liter'

  // Blinker status.0->Close, 1-> Right blinker, 2-> left blinker, 3->
  // hazardLight
  //  0 : "CLOSE"
  //  1 : "RIGHT_BLINKER"
  //  2 : "LEFT_BLINKER"
  //  3 : "HAZARD_LIGHT"
  uint8_t blinker; //      Bits= 8 Unit:'-'

  // Headlight status.High Beam -> 0 off 1 on
  //  0 : "HIGHBEAM_OFF"
  //  1 : "HIGHBEAM_ON"
  uint8_t headlight; //      Bits= 8 Unit:'-'

  // Gear status. P-R-N-D (1-2-3-4)
  //  1 : "P"
  //  2 : "R"
  //  3 : "N"
  //  4 : "D"
  uint8_t gear; //      Bits= 8 Unit:'-'

  // 1. 2. 3. 4. 5. 6. and 7. Gear 8 reverse
  //  5 : "P"
  //  6 : "R"
  //  7 : "N"
  //  8 : "D"
  //  9 : "S"
  //  10 : "E"
  //  14 : "T"
  uint8_t target_gear_level; //      Bits= 8 Unit:'-'

  // Handbrake status. 0-> released, 1-> engaged, 3-> releasing
  //  0 : "RELEASED"
  //  1 : "ENGAGED"
  //  3 : "RELEASING"
  uint8_t hand_brake : 3; //      Bits= 3 Unit:'-'

  // current gatevcu mode .0-> driver 1->joystick 2-> autonomous
  //  0 : "CONTROLLER_DRIVER"
  //  1 : "CONTROLLER_JOYSTICK"
  //  2 : "CONTROLLER_AUTONOMOUS"
  uint8_t mode : 2; //      Bits= 2 Unit:'-'

#else

  // Fuel level.
  uint8_t fuel; //      Bits= 8 Unit:'liter'

  // Blinker status.0->Close, 1-> Right blinker, 2-> left blinker, 3->
  // hazardLight
  //  0 : "CLOSE"
  //  1 : "RIGHT_BLINKER"
  //  2 : "LEFT_BLINKER"
  //  3 : "HAZARD_LIGHT"
  uint8_t blinker; //      Bits= 8 Unit:'-'

  // Headlight status.High Beam -> 0 off 1 on
  //  0 : "HIGHBEAM_OFF"
  //  1 : "HIGHBEAM_ON"
  uint8_t headlight; //      Bits= 8 Unit:'-'

  // Gear status. P-R-N-D (1-2-3-4)
  //  1 : "P"
  //  2 : "R"
  //  3 : "N"
  //  4 : "D"
  uint8_t gear; //      Bits= 8 Unit:'-'

  // 1. 2. 3. 4. 5. 6. and 7. Gear 8 reverse
  //  5 : "P"
  //  6 : "R"
  //  7 : "N"
  //  8 : "D"
  //  9 : "S"
  //  10 : "E"
  //  14 : "T"
  uint8_t target_gear_level; //      Bits= 8 Unit:'-'

  // Handbrake status. 0-> released, 1-> engaged, 3-> releasing
  //  0 : "RELEASED"
  //  1 : "ENGAGED"
  //  3 : "RELEASING"
  uint8_t hand_brake; //      Bits= 3 Unit:'-'

  // current gatevcu mode .0-> driver 1->joystick 2-> autonomous
  //  0 : "CONTROLLER_DRIVER"
  //  1 : "CONTROLLER_JOYSTICK"
  //  2 : "CONTROLLER_AUTONOMOUS"
  uint8_t mode; //      Bits= 2 Unit:'-'

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} VEHICLE_SIGNAL_STATUS_t;

// def @MODULE_INFO CAN Message (502203411 0x1def0413)
#define MODULE_INFO_IDE (1U)
#define MODULE_INFO_DLC (8U)
#define MODULE_INFO_CANID (0x1def0413U)
// signal: @throttle_ro
#define AUTONOMOUS_throttle_ro_CovFactor (0.4)
#define AUTONOMOUS_throttle_ro_toS(x) ((uint8_t)(((x) - (0.0)) / (0.4)))
#define AUTONOMOUS_throttle_ro_fromS(x) ((((x) * (0.4)) + (0.0)))
// signal: @ESP_brake_pressure_ro
#define AUTONOMOUS_ESP_brake_pressure_ro_CovFactor (0.3)
#define AUTONOMOUS_ESP_brake_pressure_ro_toS(x)                                \
  ((uint16_t)(((x) - (-30.0)) / (0.3)))
#define AUTONOMOUS_ESP_brake_pressure_ro_fromS(x) ((((x) * (0.3)) + (-30.0)))
// signal: @steer_module_fb_current_ro
#define AUTONOMOUS_steer_module_fb_current_ro_CovFactor (10)
#define AUTONOMOUS_steer_module_fb_current_ro_toS(x) ((uint8_t)((x) / (10)))
#define AUTONOMOUS_steer_module_fb_current_ro_fromS(x) (((x) * (10)))
// signal: @brake_module_1_fb_current_ro
#define AUTONOMOUS_brake_module_1_fb_current_ro_CovFactor (10)
#define AUTONOMOUS_brake_module_1_fb_current_ro_toS(x) ((uint8_t)((x) / (10)))
#define AUTONOMOUS_brake_module_1_fb_current_ro_fromS(x) (((x) * (10)))
// signal: @brake_module_2_fb_current_ro
#define AUTONOMOUS_brake_module_2_fb_current_ro_CovFactor (10)
#define AUTONOMOUS_brake_module_2_fb_current_ro_toS(x) ((uint8_t)((x) / (10)))
#define AUTONOMOUS_brake_module_2_fb_current_ro_fromS(x) (((x) * (10)))
// signal: @gear_module_fb_current_ro
#define AUTONOMOUS_gear_module_fb_current_ro_CovFactor (10)
#define AUTONOMOUS_gear_module_fb_current_ro_toS(x) ((uint8_t)((x) / (10)))
#define AUTONOMOUS_gear_module_fb_current_ro_fromS(x) (((x) * (10)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // Indicates steering intervention.
  uint8_t steering_intervention : 1; //      Bits= 1 Unit:'-'

  // Indicates brake intervention.
  uint8_t brake_intervention : 1; //      Bits= 1 Unit:'-'

  //  Indicates accelerator pedal intervention.
  uint8_t acc_pedal_intervention : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t steer_module_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t brake_module_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t gear_module_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t steer_disconnected : 1; //      Bits= 1 Unit:'-'

  // High-Side Driver Activation Failure
  uint8_t str_001 : 1; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver
  uint8_t str_002 : 1; //      Bits= 1 Unit:'-'

  // Steering Angle Mismatch
  uint8_t str_003 : 1; //      Bits= 1 Unit:'-'

  // High-Side Driver - 1 Activation Failure
  uint8_t bm_001 : 1; //      Bits= 1 Unit:'-'

  // High-Side Driver - 2 Activation Failure
  uint8_t bm_002 : 1; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver - 1
  uint8_t bm_003 : 1; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver - 2
  uint8_t bm_004 : 1; //      Bits= 1 Unit:'-'

  // High-Side Driver  Activation Failure
  uint8_t gm_001 : 1; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver
  uint8_t gm_002 : 1; //      Bits= 1 Unit:'-'

  // Gear not work
  uint8_t gm_003 : 1; //      Bits= 1 Unit:'-'

  // Indicates that the user pressed the brake pedal.
  uint8_t driver_brake : 1; //      Bits= 1 Unit:'-'

  //  Throttle pedal position.
  uint8_t throttle_ro; //      Bits= 8 Factor= 0.4             Unit:'%'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t throttle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Brake pedal position.
  uint8_t brake; //      Bits= 8 Unit:'-'

  // Current brake pressure.
  uint16_t ESP_brake_pressure_ro; //      Bits=10 Offset= -30.0 Factor= 0.3
                                  //      Unit:'Unit_Bar'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ESP_brake_pressure_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t steer_module_fb_current_ro : 5; //      Bits= 5 Factor= 10 Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t steer_module_fb_current_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t brake_module_1_fb_current_ro : 5; //      Bits= 5 Factor= 10 Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t brake_module_1_fb_current_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t brake_module_2_fb_current_ro : 5; //      Bits= 5 Factor= 10 Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t brake_module_2_fb_current_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t gear_module_fb_current_ro : 5; //      Bits= 5 Factor= 10 Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t gear_module_fb_current_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#else

  // Indicates steering intervention.
  uint8_t steering_intervention; //      Bits= 1 Unit:'-'

  // Indicates brake intervention.
  uint8_t brake_intervention; //      Bits= 1 Unit:'-'

  //  Indicates accelerator pedal intervention.
  uint8_t acc_pedal_intervention; //      Bits= 1 Unit:'-'

  // -
  uint8_t steer_module_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t brake_module_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t gear_module_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t steer_disconnected; //      Bits= 1 Unit:'-'

  // High-Side Driver Activation Failure
  uint8_t str_001; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver
  uint8_t str_002; //      Bits= 1 Unit:'-'

  // Steering Angle Mismatch
  uint8_t str_003; //      Bits= 1 Unit:'-'

  // High-Side Driver - 1 Activation Failure
  uint8_t bm_001; //      Bits= 1 Unit:'-'

  // High-Side Driver - 2 Activation Failure
  uint8_t bm_002; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver - 1
  uint8_t bm_003; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver - 2
  uint8_t bm_004; //      Bits= 1 Unit:'-'

  // High-Side Driver  Activation Failure
  uint8_t gm_001; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver
  uint8_t gm_002; //      Bits= 1 Unit:'-'

  // Gear not work
  uint8_t gm_003; //      Bits= 1 Unit:'-'

  // Indicates that the user pressed the brake pedal.
  uint8_t driver_brake; //      Bits= 1 Unit:'-'

  //  Throttle pedal position.
  uint8_t throttle_ro; //      Bits= 8 Factor= 0.4             Unit:'%'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t throttle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Brake pedal position.
  uint8_t brake; //      Bits= 8 Unit:'-'

  // Current brake pressure.
  uint16_t ESP_brake_pressure_ro; //      Bits=10 Offset= -30.0 Factor= 0.3
                                  //      Unit:'Unit_Bar'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ESP_brake_pressure_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t steer_module_fb_current_ro; //      Bits= 5 Factor= 10 Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t steer_module_fb_current_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t brake_module_1_fb_current_ro; //      Bits= 5 Factor= 10 Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t brake_module_1_fb_current_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t brake_module_2_fb_current_ro; //      Bits= 5 Factor= 10 Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t brake_module_2_fb_current_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t gear_module_fb_current_ro; //      Bits= 5 Factor= 10 Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t gear_module_fb_current_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} MODULE_INFO_t;

// def @MOTOR_INFO CAN Message (502203412 0x1def0414)
#define MOTOR_INFO_IDE (1U)
#define MOTOR_INFO_DLC (8U)
#define MOTOR_INFO_CANID (0x1def0414U)
// signal: @motor_oil_temp_ro
#define AUTONOMOUS_motor_oil_temp_ro_CovFactor (1)
#define AUTONOMOUS_motor_oil_temp_ro_toS(x) ((uint8_t)((x) - (-60)))
#define AUTONOMOUS_motor_oil_temp_ro_fromS(x) (((x) + (-60)))
// signal: @motor_rpm_ro
#define AUTONOMOUS_motor_rpm_ro_CovFactor (0.25)
#define AUTONOMOUS_motor_rpm_ro_toS(x) ((uint16_t)(((x) - (0.0)) / (0.25)))
#define AUTONOMOUS_motor_rpm_ro_fromS(x) ((((x) * (0.25)) + (0.0)))
// signal: @motor_torque_setpoint_filtered_ro
#define AUTONOMOUS_motor_torque_setpoint_filtered_ro_CovFactor (1)
#define AUTONOMOUS_motor_torque_setpoint_filtered_ro_toS(x)                    \
  ((uint16_t)((x) - (-509)))
#define AUTONOMOUS_motor_torque_setpoint_filtered_ro_fromS(x) (((x) + (-509)))
// signal: @motor_torque_setpoint_raw_ro
#define AUTONOMOUS_motor_torque_setpoint_raw_ro_CovFactor (1)
#define AUTONOMOUS_motor_torque_setpoint_raw_ro_toS(x)                         \
  ((uint16_t)((x) - (-509)))
#define AUTONOMOUS_motor_torque_setpoint_raw_ro_fromS(x) (((x) + (-509)))
// signal: @motor_torque_total_ro
#define AUTONOMOUS_motor_torque_total_ro_CovFactor (1)
#define AUTONOMOUS_motor_torque_total_ro_toS(x) ((uint16_t)((x) - (-509)))
#define AUTONOMOUS_motor_torque_total_ro_fromS(x) (((x) + (-509)))
// signal: @motor_coolant_temp_ro
#define AUTONOMOUS_motor_coolant_temp_ro_CovFactor (0.75)
#define AUTONOMOUS_motor_coolant_temp_ro_toS(x)                                \
  ((uint8_t)(((x) - (-48.0)) / (0.75)))
#define AUTONOMOUS_motor_coolant_temp_ro_fromS(x) ((((x) * (0.75)) + (-48.0)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // Motor oil temperature.
  uint8_t motor_oil_temp_ro; //      Bits= 8 Offset= -60                Unit:'C'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t motor_oil_temp_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Motor revolutions per minute.
  uint16_t motor_rpm_ro; //      Bits=16 Factor= 0.25            Unit:'rpm'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t motor_rpm_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint16_t
      motor_torque_setpoint_filtered_ro; //      Bits=10 Offset= -509 Unit:'N/m'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t motor_torque_setpoint_filtered_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint16_t motor_torque_setpoint_raw_ro; //      Bits=10 Offset= -509 Unit:'N/m'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t motor_torque_setpoint_raw_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Total motor torque.
  uint16_t motor_torque_total_ro; //      Bits=10 Offset= -509 Unit:'N/m'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t motor_torque_total_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Motor coolant temperature.
  uint8_t motor_coolant_temp_ro; //      Bits= 8 Offset= -48.0 Factor= 0.75
                                 //      Unit:'C'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t motor_coolant_temp_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#else

  // Motor oil temperature.
  uint8_t motor_oil_temp_ro; //      Bits= 8 Offset= -60                Unit:'C'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t motor_oil_temp_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Motor revolutions per minute.
  uint16_t motor_rpm_ro; //      Bits=16 Factor= 0.25            Unit:'rpm'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t motor_rpm_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint16_t
      motor_torque_setpoint_filtered_ro; //      Bits=10 Offset= -509 Unit:'N/m'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t motor_torque_setpoint_filtered_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint16_t motor_torque_setpoint_raw_ro; //      Bits=10 Offset= -509 Unit:'N/m'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t motor_torque_setpoint_raw_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Total motor torque.
  uint16_t motor_torque_total_ro; //      Bits=10 Offset= -509 Unit:'N/m'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  int16_t motor_torque_total_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Motor coolant temperature.
  uint8_t motor_coolant_temp_ro; //      Bits= 8 Offset= -48.0 Factor= 0.75
                                 //      Unit:'C'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t motor_coolant_temp_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} MOTOR_INFO_t;

// def @CONTROL_STATUS CAN Message (502203413 0x1def0415)
#define CONTROL_STATUS_IDE (1U)
#define CONTROL_STATUS_DLC (8U)
#define CONTROL_STATUS_CANID (0x1def0415U)

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // actual buzzer event
  uint8_t buzzer_event : 4; //      Bits= 4 Unit:'-'

  // vehicle ready to autonomous driving
  uint8_t ready2_autonomous_driving : 1; //      Bits= 1 Unit:'-'

  // vehicle is ready to driving
  uint8_t ready2_drive : 1; //      Bits= 1 Unit:'-'

  // auto hold activation status
  uint8_t auto_hold_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_status : 1; //      Bits= 1 Unit:'-'

  // active controller to the vehicle
  uint8_t controller : 2; //      Bits= 2 Unit:'-'

  // -
  uint8_t emergency_src_joy_module : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_autonomous_module : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_throttle_module : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_steer_module : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_brake_module : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_gear_module : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_autonomous_module_comm : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_vehicle_interface_comm : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_vehicle_can_comm : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_control_module : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_aux_1 : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_aux_2 : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_aux_3 : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_aux_4 : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t start_stop_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t pc_comm_status : 3; //      Bits= 3 Unit:'-'

  // -
  uint8_t vi_comm_status : 3; //      Bits= 3 Unit:'-'

  // -
  uint16_t vehicle_comm_status; //      Bits=10 Unit:'-'

  // Gatevcu-POWERIN_ERR
  uint8_t cm_008 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu-HSDIN_ERR
  uint8_t cm_009 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu-5v8_ERR
  uint8_t cm_010 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu-5v_ERR
  uint8_t cm_011 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu-SP0_ERR
  uint8_t cm_012 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu-SP1_ERR
  uint8_t cm_013 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu-SP2_ERR
  uint8_t cm_014 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu-SP3_ERR
  uint8_t cm_015 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu-SP4_ERR
  uint8_t cm_016 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu_TMP1_ERR
  uint8_t cm_017 : 1; //      Bits= 1 Unit:'-'

  // Gatevcu_TMP2_ERR
  uint8_t cm_018 : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_0_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_1_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_2_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_3_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_4_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_5_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_6_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_7_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_8_status : 1; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_9_status : 1; //      Bits= 1 Unit:'-'

#else

  // actual buzzer event
  uint8_t buzzer_event; //      Bits= 4 Unit:'-'

  // vehicle ready to autonomous driving
  uint8_t ready2_autonomous_driving; //      Bits= 1 Unit:'-'

  // vehicle is ready to driving
  uint8_t ready2_drive; //      Bits= 1 Unit:'-'

  // auto hold activation status
  uint8_t auto_hold_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_status; //      Bits= 1 Unit:'-'

  // active controller to the vehicle
  uint8_t controller; //      Bits= 2 Unit:'-'

  // -
  uint8_t emergency_src_joy_module; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_autonomous_module; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_throttle_module; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_steer_module; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_brake_module; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_gear_module; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_autonomous_module_; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_vehicle_interface_; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_vehicle_can_comm; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_control_module; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_aux_1; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_aux_2; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_aux_3; //      Bits= 1 Unit:'-'

  // -
  uint8_t emergency_src_aux_4; //      Bits= 1 Unit:'-'

  // -
  uint8_t start_stop_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t pc_comm_status; //      Bits= 3 Unit:'-'

  // -
  uint8_t vi_comm_status; //      Bits= 3 Unit:'-'

  // -
  uint16_t vehicle_comm_status; //      Bits=10 Unit:'-'

  // Gatevcu-POWERIN_ERR
  uint8_t cm_008; //      Bits= 1 Unit:'-'

  // Gatevcu-HSDIN_ERR
  uint8_t cm_009; //      Bits= 1 Unit:'-'

  // Gatevcu-5v8_ERR
  uint8_t cm_010; //      Bits= 1 Unit:'-'

  // Gatevcu-5v_ERR
  uint8_t cm_011; //      Bits= 1 Unit:'-'

  // Gatevcu-SP0_ERR
  uint8_t cm_012; //      Bits= 1 Unit:'-'

  // Gatevcu-SP1_ERR
  uint8_t cm_013; //      Bits= 1 Unit:'-'

  // Gatevcu-SP2_ERR
  uint8_t cm_014; //      Bits= 1 Unit:'-'

  // Gatevcu-SP3_ERR
  uint8_t cm_015; //      Bits= 1 Unit:'-'

  // Gatevcu-SP4_ERR
  uint8_t cm_016; //      Bits= 1 Unit:'-'

  // Gatevcu_TMP1_ERR
  uint8_t cm_017; //      Bits= 1 Unit:'-'

  // Gatevcu_TMP2_ERR
  uint8_t cm_018; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_0_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_1_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_2_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_3_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_4_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_5_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_6_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_7_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_8_status; //      Bits= 1 Unit:'-'

  // -
  uint8_t lsd_9_status; //      Bits= 1 Unit:'-'

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} CONTROL_STATUS_t;

// def @WHEEL_SPEEDS CAN Message (502203414 0x1def0416)
#define WHEEL_SPEEDS_IDE (1U)
#define WHEEL_SPEEDS_DLC (8U)
#define WHEEL_SPEEDS_CANID (0x1def0416U)
// signal: @esp_bl_wheel_speed_ro
#define AUTONOMOUS_esp_bl_wheel_speed_ro_CovFactor (0.0075)
#define AUTONOMOUS_esp_bl_wheel_speed_ro_toS(x)                                \
  ((uint16_t)(((x) - (0.0)) / (0.0075)))
#define AUTONOMOUS_esp_bl_wheel_speed_ro_fromS(x) ((((x) * (0.0075)) + (0.0)))
// signal: @esp_br_wheel_speed_ro
#define AUTONOMOUS_esp_br_wheel_speed_ro_CovFactor (0.0075)
#define AUTONOMOUS_esp_br_wheel_speed_ro_toS(x)                                \
  ((uint16_t)(((x) - (0.0)) / (0.0075)))
#define AUTONOMOUS_esp_br_wheel_speed_ro_fromS(x) ((((x) * (0.0075)) + (0.0)))
// signal: @esp_fl_wheel_speed_ro
#define AUTONOMOUS_esp_fl_wheel_speed_ro_CovFactor (0.0075)
#define AUTONOMOUS_esp_fl_wheel_speed_ro_toS(x)                                \
  ((uint16_t)(((x) - (0.0)) / (0.0075)))
#define AUTONOMOUS_esp_fl_wheel_speed_ro_fromS(x) ((((x) * (0.0075)) + (0.0)))
// signal: @esp_fr_wheel_speed_ro
#define AUTONOMOUS_esp_fr_wheel_speed_ro_CovFactor (0.0075)
#define AUTONOMOUS_esp_fr_wheel_speed_ro_toS(x)                                \
  ((uint16_t)(((x) - (0.0)) / (0.0075)))
#define AUTONOMOUS_esp_fr_wheel_speed_ro_fromS(x) ((((x) * (0.0075)) + (0.0)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // Rear left wheel speed.
  uint16_t esp_bl_wheel_speed_ro; //      Bits=16 Factor= 0.0075 Unit:'kmph'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_bl_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Rear right wheel speed.
  uint16_t esp_br_wheel_speed_ro; //      Bits=16 Factor= 0.0075 Unit:'kmph'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_br_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Front left wheel speed.
  uint16_t esp_fl_wheel_speed_ro; //      Bits=16 Factor= 0.0075 Unit:'kmph'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_fl_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Front right wheel speed.
  uint16_t esp_fr_wheel_speed_ro; //      Bits=16 Factor= 0.0075 Unit:'kmph'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_fr_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#else

  // Rear left wheel speed.
  uint16_t esp_bl_wheel_speed_ro; //      Bits=16 Factor= 0.0075 Unit:'kmph'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_bl_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Rear right wheel speed.
  uint16_t esp_br_wheel_speed_ro; //      Bits=16 Factor= 0.0075 Unit:'kmph'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_br_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Front left wheel speed.
  uint16_t esp_fl_wheel_speed_ro; //      Bits=16 Factor= 0.0075 Unit:'kmph'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_fl_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Front right wheel speed.
  uint16_t esp_fr_wheel_speed_ro; //      Bits=16 Factor= 0.0075 Unit:'kmph'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_fr_wheel_speed_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} WHEEL_SPEEDS_t;

// def @DYNAMIC_SENSOR_FRAME CAN Message (502203415 0x1def0417)
#define DYNAMIC_SENSOR_FRAME_IDE (1U)
#define DYNAMIC_SENSOR_FRAME_DLC (8U)
#define DYNAMIC_SENSOR_FRAME_CANID (0x1def0417U)
// signal: @esp_lateral_acceleration_ro
#define AUTONOMOUS_esp_lateral_acceleration_ro_CovFactor (0.01)
#define AUTONOMOUS_esp_lateral_acceleration_ro_toS(x)                          \
  ((uint8_t)(((x) - (-1.27)) / (0.01)))
#define AUTONOMOUS_esp_lateral_acceleration_ro_fromS(x)                        \
  ((((x) * (0.01)) + (-1.27)))
// signal: @esp_longitudinal_acceleration_ro
#define AUTONOMOUS_esp_longitudinal_acceleration_ro_CovFactor (0.03125)
#define AUTONOMOUS_esp_longitudinal_acceleration_ro_toS(x)                     \
  ((uint16_t)(((x) - (-16.0)) / (0.03125)))
#define AUTONOMOUS_esp_longitudinal_acceleration_ro_fromS(x)                   \
  ((((x) * (0.03125)) + (-16.0)))
// signal: @esp_yaw_rate_ro
#define AUTONOMOUS_esp_yaw_rate_ro_CovFactor (0.01)
#define AUTONOMOUS_esp_yaw_rate_ro_toS(x) ((int16_t)(((x) - (0.0)) / (0.01)))
#define AUTONOMOUS_esp_yaw_rate_ro_fromS(x) ((((x) * (0.01)) + (0.0)))
// signal: @vehicle_mass_ro
#define AUTONOMOUS_vehicle_mass_ro_CovFactor (32)
#define AUTONOMOUS_vehicle_mass_ro_toS(x) ((uint8_t)((x) / (32)))
#define AUTONOMOUS_vehicle_mass_ro_fromS(x) (((x) * (32)))
// signal: @pitch_ro
#define AUTONOMOUS_pitch_ro_CovFactor (0.8)
#define AUTONOMOUS_pitch_ro_toS(x) ((uint8_t)(((x) - (-101.6)) / (0.8)))
#define AUTONOMOUS_pitch_ro_fromS(x) ((((x) * (0.8)) + (-101.6)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // Lateral acceleration.
  uint8_t esp_lateral_acceleration_ro; //      Bits= 8 Offset= -1.27 Factor=
                                       //      0.01 Unit:'Unit_ForceOfGravi'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_lateral_acceleration_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Longitudinal acceleration.
  uint16_t
      esp_longitudinal_acceleration_ro; //      Bits=10 Offset= -16.0 Factor=
                                        //      0.03125
                                        //      Unit:'Unit_MeterPerSeconSquar'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_longitudinal_acceleration_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Yaw rate.
  int16_t esp_yaw_rate_ro; //  [-] Bits=16 Factor= 0.01
                           //  Unit:'Unit_DegreOfArcPerSecon'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_yaw_rate_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Vehicle mass.
  uint8_t vehicle_mass_ro; //      Bits= 8 Factor= 32 Unit:'Unit_KiloGram'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t vehicle_mass_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Vehicle pitch angle.
  uint8_t pitch_ro; //      Bits= 8 Offset= -101.6             Factor= 0.8
                    //      Unit:'Unit_PerCent'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t pitch_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#else

  // Lateral acceleration.
  uint8_t esp_lateral_acceleration_ro; //      Bits= 8 Offset= -1.27 Factor=
                                       //      0.01 Unit:'Unit_ForceOfGravi'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_lateral_acceleration_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Longitudinal acceleration.
  uint16_t
      esp_longitudinal_acceleration_ro; //      Bits=10 Offset= -16.0 Factor=
                                        //      0.03125
                                        //      Unit:'Unit_MeterPerSeconSquar'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_longitudinal_acceleration_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Yaw rate.
  int16_t esp_yaw_rate_ro; //  [-] Bits=16 Factor= 0.01
                           //  Unit:'Unit_DegreOfArcPerSecon'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t esp_yaw_rate_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Vehicle mass.
  uint8_t vehicle_mass_ro; //      Bits= 8 Factor= 32 Unit:'Unit_KiloGram'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  uint16_t vehicle_mass_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Vehicle pitch angle.
  uint8_t pitch_ro; //      Bits= 8 Offset= -101.6             Factor= 0.8
                    //      Unit:'Unit_PerCent'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t pitch_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} DYNAMIC_SENSOR_FRAME_t;

// def @CONTROL_MECHANISM_VOLTS CAN Message (502203416 0x1def0418)
#define CONTROL_MECHANISM_VOLTS_IDE (1U)
#define CONTROL_MECHANISM_VOLTS_DLC (8U)
#define CONTROL_MECHANISM_VOLTS_CANID (0x1def0418U)
// signal: @ecu_kl30_protectd_voltage_ro
#define AUTONOMOUS_ecu_kl30_protectd_voltage_ro_CovFactor (0.1)
#define AUTONOMOUS_ecu_kl30_protectd_voltage_ro_toS(x)                         \
  ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_ecu_kl30_protectd_voltage_ro_fromS(x)                       \
  ((((x) * (0.1)) + (0.0)))
// signal: @ecu_kl30_2_protectd_voltage_ro
#define AUTONOMOUS_ecu_kl30_2_protectd_voltage_ro_CovFactor (0.1)
#define AUTONOMOUS_ecu_kl30_2_protectd_voltage_ro_toS(x)                       \
  ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_ecu_kl30_2_protectd_voltage_ro_fromS(x)                     \
  ((((x) * (0.1)) + (0.0)))
// signal: @ecu_5v8_fb_voltage_ro
#define AUTONOMOUS_ecu_5v8_fb_voltage_ro_CovFactor (0.1)
#define AUTONOMOUS_ecu_5v8_fb_voltage_ro_toS(x)                                \
  ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_ecu_5v8_fb_voltage_ro_fromS(x) ((((x) * (0.1)) + (0.0)))
// signal: @ecu_5v_fb_voltage_ro
#define AUTONOMOUS_ecu_5v_fb_voltage_ro_CovFactor (0.1)
#define AUTONOMOUS_ecu_5v_fb_voltage_ro_toS(x)                                 \
  ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_ecu_5v_fb_voltage_ro_fromS(x) ((((x) * (0.1)) + (0.0)))
// signal: @ecu_5v_supply_0_voltage_ro
#define AUTONOMOUS_ecu_5v_supply_0_voltage_ro_CovFactor (0.1)
#define AUTONOMOUS_ecu_5v_supply_0_voltage_ro_toS(x)                           \
  ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_ecu_5v_supply_0_voltage_ro_fromS(x) ((((x) * (0.1)) + (0.0)))
// signal: @ecu_5v_supply_1_voltage_ro
#define AUTONOMOUS_ecu_5v_supply_1_voltage_ro_CovFactor (0.1)
#define AUTONOMOUS_ecu_5v_supply_1_voltage_ro_toS(x)                           \
  ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_ecu_5v_supply_1_voltage_ro_fromS(x) ((((x) * (0.1)) + (0.0)))
// signal: @ecu_5v_supply_2_voltage_ro
#define AUTONOMOUS_ecu_5v_supply_2_voltage_ro_CovFactor (0.1)
#define AUTONOMOUS_ecu_5v_supply_2_voltage_ro_toS(x)                           \
  ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_ecu_5v_supply_2_voltage_ro_fromS(x) ((((x) * (0.1)) + (0.0)))
// signal: @ecu_5v_supply_3_voltage_ro
#define AUTONOMOUS_ecu_5v_supply_3_voltage_ro_CovFactor (0.1)
#define AUTONOMOUS_ecu_5v_supply_3_voltage_ro_toS(x)                           \
  ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_ecu_5v_supply_3_voltage_ro_fromS(x) ((((x) * (0.1)) + (0.0)))
// signal: @ecu_5v_supply_4_voltage_ro
#define AUTONOMOUS_ecu_5v_supply_4_voltage_ro_CovFactor (0.1)
#define AUTONOMOUS_ecu_5v_supply_4_voltage_ro_toS(x)                           \
  ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_ecu_5v_supply_4_voltage_ro_fromS(x) ((((x) * (0.1)) + (0.0)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // -
  uint8_t ecu_kl30_protectd_voltage_ro; //      Bits= 8 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_kl30_protectd_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_kl30_2_protectd_voltage_ro; //      Bits= 8 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_kl30_2_protectd_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v8_fb_voltage_ro : 6; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v8_fb_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_fb_voltage_ro : 6; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_fb_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_0_voltage_ro : 6; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_0_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_1_voltage_ro : 6; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_1_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_2_voltage_ro : 6; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_2_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_3_voltage_ro : 6; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_3_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_4_voltage_ro : 6; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_4_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t reserved : 6; //      Bits= 6 Unit:'-'

#else

  // -
  uint8_t ecu_kl30_protectd_voltage_ro; //      Bits= 8 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_kl30_protectd_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_kl30_2_protectd_voltage_ro; //      Bits= 8 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_kl30_2_protectd_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v8_fb_voltage_ro; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v8_fb_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_fb_voltage_ro; //      Bits= 6 Factor= 0.1             Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_fb_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_0_voltage_ro; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_0_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_1_voltage_ro; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_1_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_2_voltage_ro; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_2_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_3_voltage_ro; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_3_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t ecu_5v_supply_4_voltage_ro; //      Bits= 6 Factor= 0.1 Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t ecu_5v_supply_4_voltage_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t reserved; //      Bits= 6 Unit:'-'

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} CONTROL_MECHANISM_VOLTS_t;

// def @CONTROL_MECHANISM_TEMPS CAN Message (502203417 0x1def0419)
#define CONTROL_MECHANISM_TEMPS_IDE (1U)
#define CONTROL_MECHANISM_TEMPS_DLC (8U)
#define CONTROL_MECHANISM_TEMPS_CANID (0x1def0419U)

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // PCB temperature 0.
  int8_t pcb_temp_0; //  [-] Bits= 8 Unit:'celcius'

  // PCB temperature 1.
  int8_t pcb_temp_1; //  [-] Bits= 8 Unit:'celcius'

  // -
  uint64_t reserved; //      Bits=48 Unit:'-'

#else

  // PCB temperature 0.
  int8_t pcb_temp_0; //  [-] Bits= 8 Unit:'celcius'

  // PCB temperature 1.
  int8_t pcb_temp_1; //  [-] Bits= 8 Unit:'celcius'

  // -
  uint64_t reserved; //      Bits=48 Unit:'-'

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} CONTROL_MECHANISM_TEMPS_t;

// def @THROTTLE_MODULE_STATUS CAN Message (502203424 0x1def0420)
#define THROTTLE_MODULE_STATUS_IDE (1U)
#define THROTTLE_MODULE_STATUS_DLC (8U)
#define THROTTLE_MODULE_STATUS_CANID (0x1def0420U)

// Value tables for @status signal

#ifndef status_THROTTLE_MODULE_STATUS_DEACTIVE
#define status_THROTTLE_MODULE_STATUS_DEACTIVE (0)
#endif

#ifndef status_THROTTLE_MODULE_STATUS_ACTIVE
#define status_THROTTLE_MODULE_STATUS_ACTIVE (1)
#endif

// signal: @dac_voltage_1_ro
#define AUTONOMOUS_dac_voltage_1_ro_CovFactor (0.1)
#define AUTONOMOUS_dac_voltage_1_ro_toS(x) ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_dac_voltage_1_ro_fromS(x) ((((x) * (0.1)) + (0.0)))
// signal: @dac_voltage_2_ro
#define AUTONOMOUS_dac_voltage_2_ro_CovFactor (0.1)
#define AUTONOMOUS_dac_voltage_2_ro_toS(x) ((uint8_t)(((x) - (0.0)) / (0.1)))
#define AUTONOMOUS_dac_voltage_2_ro_fromS(x) ((((x) * (0.1)) + (0.0)))
// signal: @pedal_voltage_1_ro
#define AUTONOMOUS_pedal_voltage_1_ro_CovFactor (0.02)
#define AUTONOMOUS_pedal_voltage_1_ro_toS(x) ((uint8_t)(((x) - (0.0)) / (0.02)))
#define AUTONOMOUS_pedal_voltage_1_ro_fromS(x) ((((x) * (0.02)) + (0.0)))
// signal: @pedal_voltage_2_ro
#define AUTONOMOUS_pedal_voltage_2_ro_CovFactor (0.02)
#define AUTONOMOUS_pedal_voltage_2_ro_toS(x) ((uint8_t)(((x) - (0.0)) / (0.02)))
#define AUTONOMOUS_pedal_voltage_2_ro_fromS(x) ((((x) * (0.02)) + (0.0)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // Indicates whether the module is active.
  //  0 : "DEACTIVE"
  //  1 : "ACTIVE"
  uint8_t status : 1; //      Bits= 1 Unit:'-'

  // Throttle Signal Mismatch
  uint8_t thr_001 : 1; //      Bits= 1 Unit:'-'

  // Throttle Not Responding
  uint8_t thr_002 : 1; //      Bits= 1 Unit:'-'

  // High-Side Driver Activation Failure
  uint8_t thr_003 : 1; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver
  uint8_t thr_004 : 1; //      Bits= 1 Unit:'-'

  // Gas pedal Mismatch
  uint8_t thr_005 : 1; //      Bits= 1 Unit:'-'

  // Reserved space for future use.
  uint8_t reserved : 2; //      Bits= 2 Unit:'-'

  // Represents the target throttle position.
  uint8_t target_throttle; //      Bits= 8 Unit:'-'

  // Represents the current throttle position.
  uint8_t current_throttle; //      Bits= 8 Unit:'-'

  // Digital-to-analog converter voltage 1.
  uint8_t dac_voltage_1_ro; //      Bits= 8 Factor= 0.1             Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t dac_voltage_1_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Digital-to-analog converter voltage 2.
  uint8_t dac_voltage_2_ro; //      Bits= 8 Factor= 0.1             Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t dac_voltage_2_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Feedback current.
  uint8_t fb_current; //      Bits= 8 Unit:'-'

  // -
  uint8_t pedal_voltage_1_ro; //      Bits= 8 Factor= 0.02            Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t pedal_voltage_1_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t pedal_voltage_2_ro; //      Bits= 8 Factor= 0.02            Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t pedal_voltage_2_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#else

  // Indicates whether the module is active.
  //  0 : "DEACTIVE"
  //  1 : "ACTIVE"
  uint8_t status; //      Bits= 1 Unit:'-'

  // Throttle Signal Mismatch
  uint8_t thr_001; //      Bits= 1 Unit:'-'

  // Throttle Not Responding
  uint8_t thr_002; //      Bits= 1 Unit:'-'

  // High-Side Driver Activation Failure
  uint8_t thr_003; //      Bits= 1 Unit:'-'

  // Overcurrent in High-Side Driver
  uint8_t thr_004; //      Bits= 1 Unit:'-'

  // Gas pedal Mismatch
  uint8_t thr_005; //      Bits= 1 Unit:'-'

  // Reserved space for future use.
  uint8_t reserved; //      Bits= 2 Unit:'-'

  // Represents the target throttle position.
  uint8_t target_throttle; //      Bits= 8 Unit:'-'

  // Represents the current throttle position.
  uint8_t current_throttle; //      Bits= 8 Unit:'-'

  // Digital-to-analog converter voltage 1.
  uint8_t dac_voltage_1_ro; //      Bits= 8 Factor= 0.1             Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t dac_voltage_1_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Digital-to-analog converter voltage 2.
  uint8_t dac_voltage_2_ro; //      Bits= 8 Factor= 0.1             Unit:'V'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t dac_voltage_2_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Feedback current.
  uint8_t fb_current; //      Bits= 8 Unit:'-'

  // -
  uint8_t pedal_voltage_1_ro; //      Bits= 8 Factor= 0.02            Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t pedal_voltage_1_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  uint8_t pedal_voltage_2_ro; //      Bits= 8 Factor= 0.02            Unit:'-'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t pedal_voltage_2_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} THROTTLE_MODULE_STATUS_t;

// def @LONGITUDINAL_COMMANDS CAN Message (502247424 0x1defb000)
#define LONGITUDINAL_COMMANDS_IDE (1U)
#define LONGITUDINAL_COMMANDS_DLC (8U)
#define LONGITUDINAL_COMMANDS_CANID (0x1defb000U)
// signal: @set_velocity_ro
#define AUTONOMOUS_set_velocity_ro_CovFactor (0.001)
#define AUTONOMOUS_set_velocity_ro_toS(x) ((int32_t)(((x) - (0.0)) / (0.001)))
#define AUTONOMOUS_set_velocity_ro_fromS(x) ((((x) * (0.001)) + (0.0)))
// signal: @set_limit_velocity_ro
#define AUTONOMOUS_set_limit_velocity_ro_CovFactor (0.001)
#define AUTONOMOUS_set_limit_velocity_ro_toS(x)                                \
  ((int32_t)(((x) - (0.0)) / (0.001)))
#define AUTONOMOUS_set_limit_velocity_ro_fromS(x) ((((x) * (0.001)) + (0.0)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  //  Sets the vehicle speed.
  int32_t set_velocity_ro; //  [-] Bits=32 Factor= 0.001           Unit:'m/s'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_velocity_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Defines the speed limit. Users can change continuously this limit.
  int32_t set_limit_velocity_ro; //  [-] Bits=32 Factor= 0.001 Unit:'m/s'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_limit_velocity_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#else

  //  Sets the vehicle speed.
  int32_t set_velocity_ro; //  [-] Bits=32 Factor= 0.001           Unit:'m/s'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_velocity_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // Defines the speed limit. Users can change continuously this limit.
  int32_t set_limit_velocity_ro; //  [-] Bits=32 Factor= 0.001 Unit:'m/s'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_limit_velocity_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} LONGITUDINAL_COMMANDS_t;

// def @VEHICLE_COMMANDS CAN Message (502247425 0x1defb001)
#define VEHICLE_COMMANDS_IDE (1U)
#define VEHICLE_COMMANDS_DLC (8U)
#define VEHICLE_COMMANDS_CANID (0x1defb001U)

// Value tables for @blinker signal

#ifndef blinker_VEHICLE_COMMANDS_NO_BLINKER
#define blinker_VEHICLE_COMMANDS_NO_BLINKER (0)
#endif

#ifndef blinker_VEHICLE_COMMANDS_BLINKER_LEFT
#define blinker_VEHICLE_COMMANDS_BLINKER_LEFT (1)
#endif

#ifndef blinker_VEHICLE_COMMANDS_BLINKER_RIGHT
#define blinker_VEHICLE_COMMANDS_BLINKER_RIGHT (2)
#endif

#ifndef blinker_VEHICLE_COMMANDS_BLINKER_HAZARD
#define blinker_VEHICLE_COMMANDS_BLINKER_HAZARD (3)
#endif

// Value tables for @headlgiht signal

#ifndef headlgiht_VEHICLE_COMMANDS_NO_HEADLIGHT
#define headlgiht_VEHICLE_COMMANDS_NO_HEADLIGHT (0)
#endif

#ifndef headlgiht_VEHICLE_COMMANDS_HEADLIGHT_LOW
#define headlgiht_VEHICLE_COMMANDS_HEADLIGHT_LOW (1)
#endif

#ifndef headlgiht_VEHICLE_COMMANDS_HEADLIGHT_HIGH
#define headlgiht_VEHICLE_COMMANDS_HEADLIGHT_HIGH (2)
#endif

// Value tables for @gear signal

#ifndef gear_VEHICLE_COMMANDS_P
#define gear_VEHICLE_COMMANDS_P (0)
#endif

#ifndef gear_VEHICLE_COMMANDS_R
#define gear_VEHICLE_COMMANDS_R (1)
#endif

#ifndef gear_VEHICLE_COMMANDS_N
#define gear_VEHICLE_COMMANDS_N (2)
#endif

#ifndef gear_VEHICLE_COMMANDS_D
#define gear_VEHICLE_COMMANDS_D (3)
#endif

// Value tables for @hand_brake signal

#ifndef hand_brake_VEHICLE_COMMANDS_HANDBRAKE_PRESS
#define hand_brake_VEHICLE_COMMANDS_HANDBRAKE_PRESS (0)
#endif

#ifndef hand_brake_VEHICLE_COMMANDS_HANDBRAKE_RELEASE
#define hand_brake_VEHICLE_COMMANDS_HANDBRAKE_RELEASE (1)
#endif

// Value tables for @emergency_request signal

#ifndef emergency_request_VEHICLE_COMMANDS_NO_EMERGENCY
#define emergency_request_VEHICLE_COMMANDS_NO_EMERGENCY (0)
#endif

#ifndef emergency_request_VEHICLE_COMMANDS_EMERGENCY
#define emergency_request_VEHICLE_COMMANDS_EMERGENCY (1)
#endif

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // Controls whether the vehicle is in autonomous mode or not.
  uint8_t set_autonomous : 1; //      Bits= 1 Unit:'-'

  // Controls the blinkers
  //  0 : "NO_BLINKER"
  //  1 : "BLINKER_LEFT"
  //  2 : "BLINKER_RIGHT"
  //  3 : "BLINKER_HAZARD"
  uint8_t blinker; //      Bits= 8 Unit:'-'

  // Controls the headlight status (low/high beams).
  //  0 : "NO_HEADLIGHT"
  //  1 : "HEADLIGHT_LOW"
  //  2 : "HEADLIGHT_HIGH"
  uint8_t headlgiht; //      Bits= 8 Unit:'-'

  // Set gear position.Gear changes when speed arrives at 0.
  //  0 : "P"
  //  1 : "R"
  //  2 : "N"
  //  3 : "D"
  uint8_t gear; //      Bits= 8 Unit:'-'

  // Set handbrake. It is not working now.
  //  0 : "HANDBRAKE_PRESS"
  //  1 : "HANDBRAKE_RELEASE"
  uint8_t hand_brake; //      Bits= 8 Unit:'-'

  // Set emergency braking.
  //  0 : "NO_EMERGENCY"
  //  1 : "EMERGENCY"
  uint8_t emergency_request; //      Bits= 8 Unit:'-'

  // Reserved space for future use.
  //
  //
  uint32_t reserved; //      Bits=24 Unit:'-'

#else

  // Controls whether the vehicle is in autonomous mode or not.
  uint8_t set_autonomous; //      Bits= 1 Unit:'-'

  // Controls the blinkers
  //  0 : "NO_BLINKER"
  //  1 : "BLINKER_LEFT"
  //  2 : "BLINKER_RIGHT"
  //  3 : "BLINKER_HAZARD"
  uint8_t blinker; //      Bits= 8 Unit:'-'

  // Controls the headlight status (low/high beams).
  //  0 : "NO_HEADLIGHT"
  //  1 : "HEADLIGHT_LOW"
  //  2 : "HEADLIGHT_HIGH"
  uint8_t headlgiht; //      Bits= 8 Unit:'-'

  // Set gear position.Gear changes when speed arrives at 0.
  //  0 : "P"
  //  1 : "R"
  //  2 : "N"
  //  3 : "D"
  uint8_t gear; //      Bits= 8 Unit:'-'

  // Set handbrake. It is not working now.
  //  0 : "HANDBRAKE_PRESS"
  //  1 : "HANDBRAKE_RELEASE"
  uint8_t hand_brake; //      Bits= 8 Unit:'-'

  // Set emergency braking.
  //  0 : "NO_EMERGENCY"
  //  1 : "EMERGENCY"
  uint8_t emergency_request; //      Bits= 8 Unit:'-'

  // Reserved space for future use.
  //
  //
  uint32_t reserved; //      Bits=24 Unit:'-'

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} VEHICLE_COMMANDS_t;

// def @FRONT_WHEEL_COMMANDS CAN Message (502247426 0x1defb002)
#define FRONT_WHEEL_COMMANDS_IDE (1U)
#define FRONT_WHEEL_COMMANDS_DLC (8U)
#define FRONT_WHEEL_COMMANDS_CANID (0x1defb002U)
// signal: @set_front_wheel_tire_angle_ro
#define AUTONOMOUS_set_front_wheel_tire_angle_ro_CovFactor (0.00001)
#define AUTONOMOUS_set_front_wheel_tire_angle_ro_toS(x)                        \
  ((int32_t)(((x) - (0.0)) / (0.00001)))
#define AUTONOMOUS_set_front_wheel_tire_angle_ro_fromS(x)                      \
  ((((x) * (0.00001)) + (0.0)))
// signal: @set_front_wheel_angle_rate_ro
#define AUTONOMOUS_set_front_wheel_angle_rate_ro_CovFactor (0.00001)
#define AUTONOMOUS_set_front_wheel_angle_rate_ro_toS(x)                        \
  ((int32_t)(((x) - (0.0)) / (0.00001)))
#define AUTONOMOUS_set_front_wheel_angle_rate_ro_fromS(x)                      \
  ((((x) * (0.00001)) + (0.0)))

typedef struct {
#ifdef AUTONOMOUS_USE_BITS_SIGNAL

  // -
  int32_t
      set_front_wheel_tire_angle_ro; //  [-] Bits=32 Factor= 0.00001 Unit:'rad'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_front_wheel_tire_angle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  int32_t set_front_wheel_angle_rate_ro; //  [-] Bits=32 Factor= 0.00001
                                         //  Unit:'rad/s'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_front_wheel_angle_rate_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#else

  // -
  int32_t
      set_front_wheel_tire_angle_ro; //  [-] Bits=32 Factor= 0.00001 Unit:'rad'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_front_wheel_tire_angle_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

  // -
  int32_t set_front_wheel_angle_rate_ro; //  [-] Bits=32 Factor= 0.00001
                                         //  Unit:'rad/s'

#ifdef AUTONOMOUS_USE_SIGFLOAT
  sigfloat_t set_front_wheel_angle_rate_phys;
#endif // AUTONOMOUS_USE_SIGFLOAT

#endif // AUTONOMOUS_USE_BITS_SIGNAL

#ifdef AUTONOMOUS_USE_DIAG_MONITORS

  FrameMonitor_t mon1;

#endif // AUTONOMOUS_USE_DIAG_MONITORS

} FRONT_WHEEL_COMMANDS_t;

// Function signatures

uint32_t
Unpack_LONGITUDINAL_COMMANDS_JOY_autonomous(LONGITUDINAL_COMMANDS_JOY_t *_m,
                                            const uint8_t *_d, uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t
Pack_LONGITUDINAL_COMMANDS_JOY_autonomous(LONGITUDINAL_COMMANDS_JOY_t *_m,
                                          __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_LONGITUDINAL_COMMANDS_JOY_autonomous(
    LONGITUDINAL_COMMANDS_JOY_t *_m, uint8_t *_d, uint8_t *_len, uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_VEHICLE_COMMANDS_JOY_autonomous(VEHICLE_COMMANDS_JOY_t *_m,
                                                const uint8_t *_d,
                                                uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_VEHICLE_COMMANDS_JOY_autonomous(VEHICLE_COMMANDS_JOY_t *_m,
                                              __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_VEHICLE_COMMANDS_JOY_autonomous(VEHICLE_COMMANDS_JOY_t *_m,
                                              uint8_t *_d, uint8_t *_len,
                                              uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t
Unpack_FRONT_WHEEL_COMMANDS_JOY_autonomous(FRONT_WHEEL_COMMANDS_JOY_t *_m,
                                           const uint8_t *_d, uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t
Pack_FRONT_WHEEL_COMMANDS_JOY_autonomous(FRONT_WHEEL_COMMANDS_JOY_t *_m,
                                         __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_FRONT_WHEEL_COMMANDS_JOY_autonomous(
    FRONT_WHEEL_COMMANDS_JOY_t *_m, uint8_t *_d, uint8_t *_len, uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_VEHICLE_INFO_autonomous(VEHICLE_INFO_t *_m, const uint8_t *_d,
                                        uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_VEHICLE_INFO_autonomous(VEHICLE_INFO_t *_m,
                                      __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_VEHICLE_INFO_autonomous(VEHICLE_INFO_t *_m, uint8_t *_d,
                                      uint8_t *_len, uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_VEHICLE_SIGNAL_STATUS_autonomous(VEHICLE_SIGNAL_STATUS_t *_m,
                                                 const uint8_t *_d,
                                                 uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_VEHICLE_SIGNAL_STATUS_autonomous(VEHICLE_SIGNAL_STATUS_t *_m,
                                               __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_VEHICLE_SIGNAL_STATUS_autonomous(VEHICLE_SIGNAL_STATUS_t *_m,
                                               uint8_t *_d, uint8_t *_len,
                                               uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_MODULE_INFO_autonomous(MODULE_INFO_t *_m, const uint8_t *_d,
                                       uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_MODULE_INFO_autonomous(MODULE_INFO_t *_m,
                                     __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_MODULE_INFO_autonomous(MODULE_INFO_t *_m, uint8_t *_d,
                                     uint8_t *_len, uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_MOTOR_INFO_autonomous(MOTOR_INFO_t *_m, const uint8_t *_d,
                                      uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_MOTOR_INFO_autonomous(MOTOR_INFO_t *_m,
                                    __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_MOTOR_INFO_autonomous(MOTOR_INFO_t *_m, uint8_t *_d,
                                    uint8_t *_len, uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_CONTROL_STATUS_autonomous(CONTROL_STATUS_t *_m,
                                          const uint8_t *_d, uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_CONTROL_STATUS_autonomous(CONTROL_STATUS_t *_m,
                                        __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_CONTROL_STATUS_autonomous(CONTROL_STATUS_t *_m, uint8_t *_d,
                                        uint8_t *_len, uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_WHEEL_SPEEDS_autonomous(WHEEL_SPEEDS_t *_m, const uint8_t *_d,
                                        uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_WHEEL_SPEEDS_autonomous(WHEEL_SPEEDS_t *_m,
                                      __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_WHEEL_SPEEDS_autonomous(WHEEL_SPEEDS_t *_m, uint8_t *_d,
                                      uint8_t *_len, uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_DYNAMIC_SENSOR_FRAME_autonomous(DYNAMIC_SENSOR_FRAME_t *_m,
                                                const uint8_t *_d,
                                                uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_DYNAMIC_SENSOR_FRAME_autonomous(DYNAMIC_SENSOR_FRAME_t *_m,
                                              __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_DYNAMIC_SENSOR_FRAME_autonomous(DYNAMIC_SENSOR_FRAME_t *_m,
                                              uint8_t *_d, uint8_t *_len,
                                              uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t
Unpack_CONTROL_MECHANISM_VOLTS_autonomous(CONTROL_MECHANISM_VOLTS_t *_m,
                                          const uint8_t *_d, uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t
Pack_CONTROL_MECHANISM_VOLTS_autonomous(CONTROL_MECHANISM_VOLTS_t *_m,
                                        __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_CONTROL_MECHANISM_VOLTS_autonomous(CONTROL_MECHANISM_VOLTS_t *_m,
                                                 uint8_t *_d, uint8_t *_len,
                                                 uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t
Unpack_CONTROL_MECHANISM_TEMPS_autonomous(CONTROL_MECHANISM_TEMPS_t *_m,
                                          const uint8_t *_d, uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t
Pack_CONTROL_MECHANISM_TEMPS_autonomous(CONTROL_MECHANISM_TEMPS_t *_m,
                                        __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_CONTROL_MECHANISM_TEMPS_autonomous(CONTROL_MECHANISM_TEMPS_t *_m,
                                                 uint8_t *_d, uint8_t *_len,
                                                 uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_THROTTLE_MODULE_STATUS_autonomous(THROTTLE_MODULE_STATUS_t *_m,
                                                  const uint8_t *_d,
                                                  uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_THROTTLE_MODULE_STATUS_autonomous(THROTTLE_MODULE_STATUS_t *_m,
                                                __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_THROTTLE_MODULE_STATUS_autonomous(THROTTLE_MODULE_STATUS_t *_m,
                                                uint8_t *_d, uint8_t *_len,
                                                uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_LONGITUDINAL_COMMANDS_autonomous(LONGITUDINAL_COMMANDS_t *_m,
                                                 const uint8_t *_d,
                                                 uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_LONGITUDINAL_COMMANDS_autonomous(LONGITUDINAL_COMMANDS_t *_m,
                                               __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_LONGITUDINAL_COMMANDS_autonomous(LONGITUDINAL_COMMANDS_t *_m,
                                               uint8_t *_d, uint8_t *_len,
                                               uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_VEHICLE_COMMANDS_autonomous(VEHICLE_COMMANDS_t *_m,
                                            const uint8_t *_d, uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_VEHICLE_COMMANDS_autonomous(VEHICLE_COMMANDS_t *_m,
                                          __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_VEHICLE_COMMANDS_autonomous(VEHICLE_COMMANDS_t *_m, uint8_t *_d,
                                          uint8_t *_len, uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

uint32_t Unpack_FRONT_WHEEL_COMMANDS_autonomous(FRONT_WHEEL_COMMANDS_t *_m,
                                                const uint8_t *_d,
                                                uint8_t dlc_);
#ifdef AUTONOMOUS_USE_CANSTRUCT
uint32_t Pack_FRONT_WHEEL_COMMANDS_autonomous(FRONT_WHEEL_COMMANDS_t *_m,
                                              __CoderDbcCanFrame_t__ *cframe);
#else
uint32_t Pack_FRONT_WHEEL_COMMANDS_autonomous(FRONT_WHEEL_COMMANDS_t *_m,
                                              uint8_t *_d, uint8_t *_len,
                                              uint8_t *_ide);
#endif // AUTONOMOUS_USE_CANSTRUCT

#ifdef __cplusplus
}
#endif
