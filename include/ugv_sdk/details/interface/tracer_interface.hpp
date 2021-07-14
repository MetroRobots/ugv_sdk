/*
 * tracer_interface.hpp
 *
 * Created on: Jul 08, 2021 09:36
 * Description:
 *
 * Copyright (c) 2021 Weston Robot Pte. Ltd.
 */

#ifndef TRACER_INTERFACE_HPP
#define TRACER_INTERFACE_HPP

#include <string>

#include "ugv_sdk/details/interface/agilex_message.h"

namespace westonrobot {
struct TracerState {
  // system state
  SystemStateMessage system_state;
  MotionStateMessage motion_state;
  LightStateMessage light_state;

  // actuator state
  // - for v2 robots only
  ActuatorHSStateMessage actuator_hs_state[4];
  ActuatorLSStateMessage actuator_ls_state[4];
  // - for v1 robots only
  ActuatorStateMessageV1 actuator_state[4];
};

struct TracerInterface {
  virtual ~TracerInterface() = default;

  virtual void SetMotionCommand(double linear_vel, double angular_vel) = 0;
  virtual void SetLightCommand(LightMode f_mode, uint8_t f_value) = 0;

  // get robot state
  virtual TracerState GetRobotState() = 0;
};
}  // namespace westonrobot

#endif /* TRACER_INTERFACE_HPP */
