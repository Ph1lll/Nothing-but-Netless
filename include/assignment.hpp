#include "main.h"

// Controllers
Controller oleana(CONTROLLER_MASTER);
Controller archie(CONTROLLER_PARTNER);

// Drivetrain
Motor lMotor(9, MOTOR_GEARSET_18, false);
Motor rMotor(10, MOTOR_GEARSET_18, true);

// Launcher
Motor lLaunch(11, MOTOR_GEARSET_18, true);
Motor rLaunch(20, MOTOR_GEARSET_18, false);
Motor pullup(12, MOTOR_GEARSET_18, false);