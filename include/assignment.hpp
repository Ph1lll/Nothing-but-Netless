#include "main.h"

// Controllers
Controller oleana(CONTROLLER_MASTER);
Controller archie(CONTROLLER_PARTNER);

// Drivetrain
Motor lMotor(10, MOTOR_GEARSET_18, false);
Motor rMotor(9, MOTOR_GEARSET_18, true);

// Flywheel
Motor  lFlywheel(1, MOTOR_GEARSET_18, false);
Motor  rFlywheel(2, MOTOR_GEARSET_18, true);
Motor  pullup(3, MOTOR_GEARSET_18, false);