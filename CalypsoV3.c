#pragma config(I2C_Usage, I2C1, i2cSensors)
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
  // Example: clearing encoders, setting servo positions, ...
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

task autonomous(){

/////////////// Auton 1 (Start against right wall) ///////////////

/*
motor[Lift2R]= -127;
motor[Lift2L]= -127;
motor[LiftR] = 127;
motor[LIFTR] = 127;
motor[LiftL] = 127;
motor[LIFTL] = 127;
motor[Mobile]= -127;
wait (0.5);
motor[Right] = 84.5;
motor[Left]  = 84.5;
wait (1.0);
motor[Lift2R]= 25;
motor[Lift2L]= 25;
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
motor[Mobile]= 0;
wait(1.0);
motor[Lift2R]= 127;
motor[Lift2L]= 127;
motor[Right] = 64.5;    // Change to switch arena sides
motor[Left]  = -64.5;   // Change to switch arena sides
motor[LiftR] = 127;
motor[LIFTR] = 127;
motor[LiftL] = 127;
motor[LIFTL] = 127;
wait(2.0);
motor[Right] = 127;
motor[Left ] = 127;
wait(1.0);
motor[Mobile]= 127;
motor[Right] = 127;
motor[Left]  = 127;
wait(1.5);
motor[LiftR] = 0;
motor[LIFTR] = 0;
motor[LiftL] = 0;
motor[LIFTL] = 0;
motor[Right] = -127;
motor[Left]  =  -127;
motor[Mobile]= -127;


/////////////// Auton 1 (Against right wall) ///////////////

/////////////// Auton 2 (Start against left wall) ///////////////

/*
motor[Lift2R]= -127;
motor[Lift2L]= -127;
motor[LiftR] = 127;
motor[LIFTR] = 127;
motor[LiftL] = 127;
motor[LIFTL] = 127;
motor[Right] = 64.5;
motor[Left]  = 64.5;
wait (1.0);
motor[Lift2R]= 25;
motor[Lift2L]= 25;
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
motor[Mobile]= 0;
wait(1.0);
motor[Lift2R]= 127;
motor[Lift2L]= 127;
motor[Right] = -64.5;
motor[Left]  = 64.5;
motor[LiftR] = 127;
motor[LIFTR] = 127;
motor[LiftL] = 127;
motor[LIFTL] = 127;
wait(2.0);
motor[Right] = 127;
motor[Left ] = 127;
wait(1.0);
motor[Mobile]= 127;
motor[Right] = 127;
motor[Left]  = 127;
wait(1.5);
motor[LiftR] = 0;
motor[LIFTR] = 0;
motor[LiftL] = 0;
motor[LIFTL] = 0;
motor[Right] = -127;
motor[Left] =  -127;
motor[Mobile] = -127;
*/

/////////////// Auton 2 (Against left wall) ///////////////

/////////////// Auton 3 (High Stack) ///////////////  (Start against which side??)

motor [Lift2R] =  -127;
motor [Lift2L] =  -127;
motor [LiftR]  =  127;
motor [LIFTR]  =  127;
motor [LiftL]  =  127;
motor [LIFTL]  =  127;
motor [Claw ]  =  127;
wait  (2.0);
motor [LiftR]  =  0;
motor [LiftL]  =  0;
motor [LIFTR]  =  0;
motor [LIFTL]  =  0;
motor [Lift2R] =  127;
motor [Lift2L] =  127;
wait  (0.5);
motor [Right]  =  127;
motor [Left ]  =  127;
wait  (2.0);
motor [Right]  =  0;
motor [Left]   =  0;
motor [Lift2R] = 15;
motor [Lift2L] = 156;
wait  (1.2);
motor [Lift2R] =  15;
motor [Lift2L] =  15;
motor [LIFTR]  = -127;
motor [LIFTL]  = -127;
motor [LIFTR]  = -127;
motor [LIFTL]  = -127;
wait (1.0);
motor [Claw]   =  -127;
wait (1.0);
motor [Claw]   =  0;
wait (0.5);
motor [Right]  = -64.5;
motor [Left ]  = -64.5;
wait (0.5);
motor [Right]  = 0;
motor [Left ]  = 0;
motor [LiftR]  = 0;
motor [LiftL]  = 0;
motor [LIFTR]  = 0;
motor [LIFTL]  = 0;
motor [Right]  = 0;
wait  (1.0);
motor [Left ]  = -127;
motor [Right]  = -127;
wait  (0.2);
motor [LiftR]  = 127;
motor [LiftL]  = 127;
motor [LIFTR]  = 127;
motor [LIFTL]  = 127;
motor [Mobile] = 127;
wait  (1.0);
motor [Mobile] = 0;
motor [LiftR]  = 0;
motor [LiftL]  = 0;
motor [LIFTR]  = 0;
// second part of the auton/////////
/*
motor [LIFTL]  = 0;
motor [Right]  = -64.5;
motor [Left ]  =  64.5;
wait  (2.0);
motor [Right]  =  0;
motor [Left ]  =  0;
wait  (0.5);
motor [Right]  =  127;
motor [Left ]  =  127;
wait  (2.0);
motor[Lift2R]= 25;
motor[Lift2L]= 25;
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
motor[Mobile]= 0;
wait(1.0);
motor[Lift2R]= 127;
motor[Lift2L]= 127;
motor[Right] = 64.5;    // Change to switch arena sides
motor[Left]  = -64.5;   // Change to switch arena sides
motor[LiftR] = 127;
motor[LIFTR] = 127;
motor[LiftL] = 127;
motor[LIFTL] = 127;
wait(2.0);
motor[Right] = 127;
motor[Left ] = 127;
wait(1.0);
motor[Mobile]= 127;
motor[Right] = 127;
motor[Left]  = 127;
wait(1.5);
motor[LiftR] = 0;
motor[LIFTR] = 0;
motor[LiftL] = 0;
motor[LIFTL] = 0;
motor[Right] = -127;
motor[Left] =  -127;
motor[Mobile] = -127;
*/
/////////////// Auton 3 (High Stack) ///////////////

}

/////////////// User Control ///////////////

task usercontrol()
{
   while (true){

  	int Clawopen    			= vexRT(Btn8R);
  	int Clawclose  				= vexRT(Btn8D);
  	int MobileUp   		    = vexRT(Btn7D);
  	int MobileDown			  = vexRT(Btn7L);
  	int Liftdown   				= vexRT(Btn5D);
  	int Liftup    				= vexRT(Btn5U);
  	int Lift2M     				= vexRT(Ch2);
 // int vertical          = vexRT(Btn6U);
  	int leftstickX;
  	int leftstickY;
  	int deadzone   				= 5;

/////////////// Arcade Drive ///////////////

  	if (abs(vexRT[Ch3]) > deadzone){
			leftstickY = vexRT[Ch3];
	 }
		else {
			leftstickY = 0;
	 }

		if (abs(vexRT[Ch4]) > deadzone){
			leftstickX = vexRT[Ch4];
	 }
		else {
			leftstickX =0 ;
	 }

		motor[Left] = leftstickY + leftstickX;
		motor[Right]= leftstickY - leftstickX;
/////////////// Arcade Drive ///////////////

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
/////////////// First Lift Movement ///////////////

/////////////// Second Lift Movement ///////////////

    if (Lift2M >=15){
      motor [Lift2L] = Lift2M;
      motor [Lift2R] = Lift2M;
    }
    else if (Lift2M <=-15){
      motor  [Lift2L] = Lift2M;
      motor  [Lift2R] = Lift2M;
    }
    else{
      motor [Lift2L] = 15;
      motor [Lift2R] = 15;
    }

/////////////// Second Lift Movement ///////////////

/////////////// Mysteries ///////////////
   /*
    if (vertical ==1){

    motor [Lift2R] = 32.25;
    motor [Lift2L] = 32.25;
    wait (0.25);
    motor [Lift2R] =0;
    motor [Lift2L] =0;
}

    if (vertical ==1){
      motor [Lift2R] =64.5;
      motor [Lift2L] =64.5;
      wait (0.5);
      motor [Lift2R] =0;
      motor [Lift2L] =0;
}   */

/////////////// Mysteries ///////////////

/////////////// Claw Control ///////////////

    if (Clawopen == 1)
      motor [Claw] = 127;

    else if (Clawclose == 1)
      motor [Claw] = -127;

    else{
      motor [Claw] = 0;
    }

/////////////// Claw Control ///////////////

/////////////// Mobile Goal ///////////////

 if (MobileUp == 1){
      motor [Mobile] = 127;
    }
    else if (MobileDown == 1){
      motor [Mobile] = -127;
    }
    else{
      motor [Mobile] = 0;
      motor [Mobile] = 0;
    }

/////////////// Mobile Goal ///////////////

   }
}
