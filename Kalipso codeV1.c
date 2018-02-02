#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           Claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           Right,         tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           LiftR,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LIftR,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Lift2L,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Lift2R,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LiftL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Left,          tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port10,          Mobile,        tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define abs(X) ((X < 0) ? -1 * X : X)
#define M_PI acos(-1.0)

float wheelRadiusCM = 10.16;

//define functions
int getStraightGoal(float cm);
int getRotationGoal(float deg);
void moveArm(float deg, int armSpeed);

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
	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

task autonomous()
{
	motor[LiftL]= 127;
	motor[LiftR]= 127;
	wait(1);
	motor[LiftL]= 0;
	motor[LiftR]= 0;
//The lift moves up 1 second

	motor[Mobile]= 127;
	wait(0.5);
//Mobile goal goes forward
	motor[Mobile]= 0;
//Mobile goal stops

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(125))
	{
		motor[Left]= 85;
		motor[Right]= 85;
	}
	motor[Left]= 0;
	motor[Right]= 0;
//Robot goes forward to collect the mobile goal

	motor[LiftL]= -127;
	motor[LiftR]= -127;
	wait (1);
//The lift moves down 1 second
 	motor[LiftL]= 0;
	motor[LiftR]= 0;
//The lift stops

	motor[Claw]= 127;
	wait(1.5);
	motor[Lift1_L]= 127;
	motor[Lift1_R]= 127;
	wait(1.5);
//The lift moves up 1.5 seconds
 	motor[Lift1_L]= 0;
	motor[Lift1_R]= 0;
	motor[Claw]= 0;
//The lift stops

	motor[InstaL]= -127;
	motor[InstaR]= -127;
	wait(0.5);
//Mobile goal goes backward
	motor[InstaL]=0;
	motor[InstaR]=0;
//Mobile goal stops

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(122))
	{
		motor[Left]= -127;
		motor[Right]= -127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
// The robot goes  backward from collecting the mobile goal

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getRotationGoal(265))
	{
		motor[Left]= -127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
// The robot turns 265 degrees

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(45))
	{
		motor[Left]= 127;
		motor[Right]= 127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
// Robot goes forward for a little bit

	motor[InstaL]= 127;
	motor[InstaR]= 127;
	wait(0.5);
//Mobile goal goes forward
	motor[InstaL]= 0;
	motor[InstaR]= 0;
//Mobile goal stops

	resetMotorEncoder(Left);
	resetMotorEncoder(Right);
	while(abs(getMotorEncoder(Right)) < getStraightGoal(50))
	{
		motor[Left]= -127;
		motor[Right]= -127;
	}
	motor[Left]= 0;
	motor[Right]= 0;
// The robot backs away

	motor[Claw]= 0;
// Claw stops
}

task usercontrol()
{
  while (true)
  {
  	int Clawopen   = vexRT(Btn8R);
  	int Clawclose  = vexRT(Btn8D);
  	int Mobileup   = vexRT(Btn7L);
  	int MobileDown = vexRT(Btn7D);
  	int Lift2M     = vexRT(Ch2);
  	int Liftdown   = vexRT(Btn5D);
  	int Liftup     = vexRT(Btn5U);
  	int leftstickX;
  	int leftstickY;
  	int deadzone   = 5;

/////////// Arcade Drive////////////////////////
  	if(abs(vexRT[Ch3]) >deadzone){
			leftstickY = vexRT[Ch3];
		}
		else{
			leftstickY = 0;
		}

		if(abs(vexRT[Ch4]) > deadzone){
			leftstickX = vexRT[Ch4];
		}
		else{
			leftstickX =0 ;
		}

		motor[Left] = leftstickY + leftstickX;
		motor[Right]= leftstickY - leftstickX;
/////////// Arcade Drive///////////////////////

//////// First Lift Movement///////////////////
		if (Liftup == 1){
			motor [LiftR] = 127;
			motor [LiftL] = 127;
			}
		else if (Liftdown  == 1) {
			motor [LiftR] = -127;
			motor [LiftL] = -127;
			}
			else {
				motor[LiftR] = 0;
				motor[LiftL] = 0;
			}
//////// First Lift Movement///////////////////

//////// Second Lift Movement//////////////////
		if (lift2M >=15){
			motor [Lift2L] = lift2M;
			motor [Lift2R] = lift2M;
		}
		else if (lift2M <=-15){
			motor  [Lift2L] = lift2M;
			motor  [Lift2R] = lift2M;
		}
		else{
			motor [Lift2L] = 0;
			motor [Lift2R] = 0;
		}
//////// Second Lift Movement//////////////////

//////// Claw Control/////////////////////////
		if (Clawopen == 1)
			motor [Claw] = 127;

		else if (Clawclose == 1)
			motor [Claw] = -127;

		else{
			motor [Claw] = 0;
		}
//////// Claw Control/////////////////////////

//////// Mobile Goal/////////////////////////
		if(Mobileup == 1){
			motor [Mobile] = 127;
		}
		else if (Mobiledown == 1){
			motor [Mobile] = -127;
		}
		else{
			motor [Mobile] = 0;
			motor [Mobile] = 0;
//////// Mobile Goal/////////////////////////
		}
  }
}

//////////////////// FUNCTIONS////////////////////////////
int getStraightGoal(float cm) {
		return 392*(cm/(wheelRadiusCM*M_PI));
}

int getRotationGoal(float deg) {
		return 392*(deg/102.9);
}

void moveArm(float deg, int armSpeed) {
	armSpeed = abs(armSpeed);
	if(deg < SensorValue[Lift1_R]) {
		while(SensorValue[Lift1_R] <= deg) {
			motor[Lift1_R] = motor[Lift1_L] = armSpeed;
		}
	} else {
		while(SensorValue[Lift1_R] >= deg) {
			motor[Lift1_R] = motor[Lift1_L] = -armSpeed;
		}
	}
}
//////////////////// END FUNCTIONS////////////////////
