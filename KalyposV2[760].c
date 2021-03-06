#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    liftPot,        sensorPotentiometer)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           Claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           Right,         tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           LiftR,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LIFTR,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Lift2L,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Lift2R,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LIFTL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Left,          tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port10,          Mobile,        tmotorVex393_HBridge, openLoop)
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

//conversion of degrees for potentiometers
/*void potent(int deg)
{
	deg = deg*265/4095;
}
*/
void pre_auton(){
  bStopTasksBetweenModes = true;
}

task autonomous(){

motor [Lift2R] = -127;
motor [Lift2L] = -127;
wait (1.0);
motor [Lift2R] =0;
motor [Lift2L] =0;
/*
motor[LiftR] = 127;
motor[LIFTR] = 127;
motor[LiftL] = 127;
motor[LIFTL] = 127;
motor[Right] = 64.5;
motor[Left]  = 64.5;
wait (1.0);
motor[LiftR] = 0;
motor[LIFTR] = 0;
motor[LiftL] = 0;
motor[LIFTL] = 0;
motor[Mobile]= 127;
wait (1.5);
motor[Mobile]= 0;
motor[Right] = 0;
motor[Left]  = 0;
wait (1.0);
motor[Mobile] = -127;
wait(1.0);
motor[LiftR] = -127;
motor[LIFTR] = -127;
motor[LiftL] = -127;
motor[LIFTL] = -127;
wait(1.0);
motor[Right] = -127;
motor[Left]  = -127;
wait(1.0);
motor[Right] = 0;
motor[Left ] = 0;
*/


}

task usercontrol()
{
  while (true)
  {
		int Clawopen   = vexRT(Btn8R);
    int Clawclose  = vexRT(Btn8D);
    int MobileUp   = vexRT(Btn7D);
    int MobileDown = vexRT(Btn7L);
    int Lift2M     = vexRT(Ch2);
    int Liftdown   = vexRT(Btn5D);
    int Liftup     = vexRT(Btn5U);
    int vertical   = vexRT(Btn6U);
    int leftstickX;
    int leftstickY;
    int deadzone   = 5;


/////////////// Arcade Drive ///////////////

  	if(abs(vexRT[Ch3]) >deadzone)
			leftstickY = vexRT[Ch3];

		else
			leftstickY = 0;

		if(abs(vexRT[Ch4]) > deadzone)
			leftstickX = vexRT[Ch4];

		else
			leftstickX =0 ;

		motor[Left] = leftstickY + leftstickX;
		motor[Right]= leftstickY - leftstickX;

/////////////// First Lift Movement ///////////////

		if (Liftup == 1){
			motor [LiftR] = 127;
			motor [LiftL] = 127;
			motor [LIFTR] = 127;
			motor [LIFTL] = 127;
		}
		else if (Liftdown  == 1){
			motor [LiftR] = -127;
			motor [LiftL] = -127;
			motor [LIFTR] = -127;
			motor [LIFTL] = -127;
		}
		else {
				motor[LiftR] = 10;
				motor[LiftL] = -10;
			  motor [LIFTR] = -10;
			  motor [LIFTL] = 10;
		}

/////////////// Second Lift In Ch2 ///////////////

		if (Lift2M >=15){
      motor [Lift2L] = Lift2M;
      motor [Lift2R] = Lift2M;
	  }
    	else if (Lift2M <=-15){
      motor  [Lift2L] = Lift2M;
      motor  [Lift2R] = Lift2M;
		}
    	else{
      motor [Lift2L] = 0;
      motor [Lift2R] = 0;
		}

/////////////// Claw Control ///////////////

		if (Clawopen == 1)
			motor [Claw] = 127;

		else if (Clawclose == 1)
			motor [Claw] = -127;

		else
			motor [Claw] = 0;

/////////////// Second lift ///////////////

		if (vertical==1){
			motor [Lift2R] =127;
			motor [Lift2L] =127;
			wait(0.5);
			motor [Lift2R] =-15;
			motor [Lift2L] =-15;
		}

/////////////// Mobile Goal ///////////////

		if(MobileUp == 1)
			motor [Mobile] = 127;

		else if (MobileDown == 1)
			motor [Mobile] = -127;

		else
			motor [Mobile] = 0;

 }
}
