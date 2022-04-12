#include "main.h"

// Controllers
Controller oleana(CONTROLLER_MASTER);
Controller archie(CONTROLLER_PARTNER);

// Pitcher
Motor pitcherOne(1, MOTOR_GEARSET_18, false);
Motor pitcherTwo(2, MOTOR_GEARSET_18, false);

// Catniss
Motor cLBM(21, MOTOR_GEARSET_18, false);
Motor cRBM(12, MOTOR_GEARSET_18, false);

// Roomba
Motor rLBM(14, MOTOR_GEARSET_18, false);
Motor rRBM(15, MOTOR_GEARSET_18, false);