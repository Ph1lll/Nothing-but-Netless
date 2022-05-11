#include "assignment.hpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button()
{
	static bool pressed = false;
	pressed = !pressed;
	if (pressed)
	{
		pros::lcd::set_text(2, "I was pressed!");
	}
	else
	{
		pros::lcd::clear_line(2);
	}
}

void left_button()
{
	static bool pressed = false;
	pressed = !pressed;
	if (pressed)
	{
		pros::lcd::set_text(3, "Hey watch it");
	}
	else
	{
		pros::lcd::clear_line(3);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	pros::lcd::register_btn1_cb(on_center_button);
	pros::lcd::register_btn0_cb(left_button);

	if (oleana.is_connected())
	{
		pros::lcd::set_text(6, "Oleana: Connected");
	}
	else
	{
		pros::lcd::set_text(6, "Oleana: Disconnected");
	}
	if (archie.is_connected())
	{
		pros::lcd::set_text(7, "Archie: Connected");
	}
	else
	{
		pros::lcd::set_text(7, "Archie: Disconnected");
	}
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

void autonomous() {}

void opcontrol()
{
	while (1)
	{

	// Moving the drivetrain
	lMotor.move(oleana.get_analog(ANALOG_LEFT_Y) + oleana.get_analog(ANALOG_RIGHT_X));
	rMotor.move(oleana.get_analog(ANALOG_LEFT_Y) - oleana.get_analog(ANALOG_RIGHT_X));
	
	// Flywheel
	if (oleana.get_digital(DIGITAL_R2)) {
		lFlywheel.move(127);
		rFlywheel.move(127);
		pullup.move(127);
	} else {
		lFlywheel.move(0);
		rFlywheel.move(0);
		pullup.move(0);
	}
}
