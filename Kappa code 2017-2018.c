#pragma config(Motor,  port1,           MobileR,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           Lift1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Lift2R,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Lift2L,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Left,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           Right,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          MobileL,       tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing
  // encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{

	// code that goes againt left wall

 motor [Lift2R] = -127;
 	motor [Lift2L] = -127;
  wait (1.2);
  motor [Lift2R] = 0;
  motor [Lift2L] = 0;
	// flip lift away from mobile goal
  motor [MobileR] = -65.5;
	motor [MobileL] = -64.5;
	wait (1.9);
	motor [MobileR] = 0;
	motor [MobileL] = 0;
	// lower mobile goal
  motor [Left] = 127;
  motor [Right] = 127;
  wait (2.8);
  motor [Left] = 0;
  motor [Right] = 0;
  // move forwards towards goal (mobile goal facing away home)
	motor [MobileR] = 64.5;
	motor [MobileL] = 64.5;
	wait (2.0);
	motor [MobileR] = 0;
	motor [MobileL] = 0;
	// raise mobile goal with goal in it
	motor [Left] = -127;
	motor [Right] = -127;
	wait (2.8);
	motor [Left] = 0;
	motor [Right] = 0;
	// move back to home with cone on mobile goal
	motor [Right] = 127;
	motor [Left] = -127;
	wait (1.2);
	motor [Right] = 0;
	motor [Left] = 0;
	// turn robot left (mobile goal against wall)
	motor [Right] = 127;
	motor [Left]  = 127;
	wait (1.0);
	motor [Right] = 0;
	motor [Left]  = 0;
	// move mobile goal forwards into scoring zone
	motor [MobileR] = -127;
	motor [MobileL] = -127;
	// lift mobile goal down
	wait (0.3);
	//
	motor [Left] = -127;
	motor [Right] = -127;
	wait (1.0);
	motor [Left] = 0;
	motor [Right] = 0;
	// Move back away from scoring zone

 ///// code that goes against the right wall
  /*
 	motor [Lift2R] = -127;
 	motor [Lift2L] = -127;
  wait (1.2);
  motor [Lift2R] = 0;
  motor [Lift2L] = 0;
	// flip lift away from mobile goal
  motor [MobileR] = -65.5;
	motor [MobileL] = -64.5;
	wait (1.9);
	motor [MobileR] = 0;
	motor [MobileL] = 0;
	// lower mobile goal
  motor [Left] = 127;
  motor [Right] = 127;
  wait (2.8);
  motor [Left] = 0;
  motor [Right] = 0;
  // move forwards towards  goal (mobile goal facing away home)
	motor [MobileR] = 64.5;
	motor [MobileL] = 64.5;
	wait (2.0);
	motor [MobileR] = 0;
	motor [MobileL] = 0;
	// raise mobile goal with goal in it
	motor [Left] = -127;
	motor [Right] = -127;
	wait (2.8);
	motor [Left] = 0;
	motor [Right] = 0;
	// move back to home with cone on mobile goLift2
	motor [Right] = -127;
	motor [Left] = 127;
	wait (1.2);
	motor [Right] = 0;
	motor [Left] = 0;
	// turn robot left (mobile goal into wall)
	motor [Right] = 127;
	motor [Left]  = 127;
	wait (1.2);
	motor [Right] = 0;
	motor [Left]  = 0;
	// move towards home facing mobile goal
	motor [MobileR] = -127;
	motor [MobileL] = -127;
	wait (1.9);
	motor [MobileR] = 0;
	motor [MobileL] = 0;
	// lower mobile goal
	motor [Left] = -127;
	motor [Right] = -127;
	wait (1.0);
	motor [Left] = 0;
	motor [Right] = 0;
	// Move back
	*/


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop
  while (true)
  {
  	//int leftside=vexRT(Ch3);
		//int rightside=vexRT(Ch2);
		int liftup=vexRT(Btn6U);
		int liftdown=vexRT(Btn6D);
		int clawopen=vexRT(Btn8R);
		int clawclose=vexRT(Btn8D);
		//int liftup2=vexRT(Btn5U);
		//int liftdown2=vexRT(Btn5D);
		int mobileup=vexRT(Btn7L);
		int mobiledown=vexRT(Btn7D);
		int lift2M = vexRT (Ch2);
		int leftstickX;
		int leftstickY;
		int deadzone = 5;

		if(abs(vexRT[Ch3]) >deadzone)
		{
			leftstickY = vexRT[Ch3];
		}
		else
		{
			leftstickY = 0;
		}

		if(abs(vexRT[Ch4]) >deadzone)
		{
			leftstickX = vexRT[Ch4];
		}
		else
		{
			leftstickX =0 ;
		}


		motor[Left] = leftstickY + leftstickX;

		motor[Right]= leftstickY - leftstickX;


		if (lift2M >=15)
		{
			motor [Lift2L] = lift2M;
			motor [Lift2R] = lift2M;
		}
		else if (Lift2M <=-15)
		{
			motor  [Lift2L] = lift2M;
			motor  [Lift2R] = lift2M;
		}
		else {
			motor [Lift2L] = 0;
			motor [Lift2R] = 0;
		}
		/*
		//Drive train
		/if (leftside >=10)
		{motor [Left] =leftside;
		}
		else if (leftside <=-10)
		{motor [Left] = leftside;
		}
		else
		{motor [Left] =0;
		}

		if (rightside >=10)
		{
		motor [Right] =rightside;
		}
		else if (rightside <=-10)
		{
		motor [Right] =rightside;
		}
		else
		motor [lift2M]= 0;


		*/

		//{motor [Right] =0;}
		// Lift

		if (liftup == 1) {
			motor [Lift1] = 127;
		}// this is for the lift to go up
		else if (liftdown == 1) {
			motor [Lift1] = -127;
		}//this is lift to go down
		else {
			motor [Lift1] = 0;
		}// this is so the lift doesn't move if there's nothing
		/* if (liftup2 == 1){
		motor [Lift2] = 127;
		}
		else if (liftdown2 == 1){
		motor [Lift2] = -127;
		}
		else
		motor [Lift2]= 0;

		*///	Claw control
		if (clawopen == 1)
			motor [Claw] = 127; //opening the claw

		else if (clawclose == 1)
			motor [Claw] = -127; // closing in the claw
		else{
			motor [Claw] = 0;
		}// no claw movement

		if(mobileup == 1){
			motor [MobileR] = 127;
			motor [MobileL] = 127;
		}
		else if (mobiledown == 1){
			motor [MobileR] = -127;
			motor [MobileL] = -127;
		}
		else{
			motor [MobileR] = 0;
			motor [MobileL] = 0;
		}
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
    UserControlCodePlaceholderForTesting();
  }
}
