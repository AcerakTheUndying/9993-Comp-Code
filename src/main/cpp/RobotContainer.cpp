// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "commands/CmdDriveRobot.h"
#include <frc2/command/button/Trigger.h>
#include "subsystems/SubDriveBase.h"
#include "subsystems/SubCubeShooter.h"
#include "commands/GamePieceCommands.h"

RobotContainer::RobotContainer() {
  SubDriveBase::GetInstance().SetDefaultCommand(CmdDriveRobot(&_driverController));
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  using namespace frc2::cmd;
  _driverController.RightBumper().WhileTrue(cmd::ShootCube());
  _driverController.LeftBumper().WhileTrue(cmd::PickupCube());
  _driverController.X().WhileTrue(cmd::StopShooting());

}

/*frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}*/