// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveBase.h"

SubDriveBase::SubDriveBase()
{
  _vspxLeftDriveFollower.Follow(_vspxLeftDriveMain);
  _vspxRightDriveFollower.Follow(_vspxRightDriveMain);

  _vspxLeftDriveMain.SetInverted(true);
  _vspxLeftDriveFollower.SetInverted(true);
}

void SubDriveBase::drive(double speed, double rotation, bool squaredInputs)
{
  _diffDrive.ArcadeDrive(speed * frc::Preferences::GetDouble(FwdMultiplier, 1.0),
   -rotation * frc::Preferences::GetDouble(TurnMultiplier, 1.0), squaredInputs);
}

// This method will be called once per scheduler run
void SubDriveBase::Periodic() {}