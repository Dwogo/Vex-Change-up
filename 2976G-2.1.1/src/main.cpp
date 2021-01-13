/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LFM                  motor         1               
// LBM                  motor         2               
// RFM                  motor         3               
// RBM                  motor         4               
// Controller1          controller                    
// IntakeB              motor         10              
// IntakeM              motor         9               
// Vision               vision        8               
// OutakeL              motor         11              
// OutakeR              motor         12              
// AUIN                 distance      5               
// Downer               line          E               
// Upper                line          F               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
bool RTeam = true;
bool Eject = false;
bool Blue;
bool Red;
bool Bat = false;
bool OH = false;
int TP = 0;
bool Right = false;
bool OuTK = true;
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
 //Teams
  // This code is to know if we are in the Blue Team
  if (Controller1.ButtonLeft.pressing()&& RTeam == true) {
    RTeam=false;
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.clearLine(1);
    Controller1.Screen.print("Blue Team");
    wait(0.3,seconds);
  } 
  // This code is to know if we are in the Red Team
  if (Controller1.ButtonLeft.pressing()&& RTeam == false) {
    RTeam=true;
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.clearLine(1);
    Controller1.Screen.print("Red Team");
    wait(0.3,seconds);
  }

 //Auto eject
  //Auto eject is on
  if (Controller1.ButtonUp.pressing() && Eject == false) {
    Eject = true;
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.clearLine(2);
    Controller1.Screen.print("Auto eject is on");
    wait(0.2,seconds);
  }
  //Auto eject is off
  if (Controller1.ButtonUp.pressing() && Eject == true) {
    Eject = false;
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.clearLine(2);
    Controller1.Screen.print("Auto eject is off");
    wait(0.2, seconds);
  }
  
 //What side of the home row are we in?
  //Right side
  if (Controller1.ButtonX.pressing() && Right == false) {
  Right = true;
  Controller1.Screen.print("Right Side");   
  }
  //Left side
  if (Controller1.ButtonX.pressing() && Right == true) {
  Right = false;
  Controller1.Screen.print("Left Side");   
  }
  
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

void autonomous(void) {
int Osit = 2;
bool AUINT = true;
/* RIGHT
   This is if the distance sensor senses
   that it is not against a wall
   or just on the right of the home row */
  if(Right == true) {
 //Slide to the left   
  RBM.spin(reverse,100,vex::pct);
  LBM.spin(fwd,100,vex::pct);
  LFM.spin(reverse,100,vex::pct);
  RFM.spin(fwd,100,vex::pct);
  wait(1,seconds);
  RFM.stop();
  LFM.stop();
  RBM.stop();
  LBM.stop();
 //Rotate right 
  RBM.spin(reverse,80,vex::pct);
  LBM.spin(fwd,80,vex::pct);
  RFM.spin(reverse,80,vex::pct);
  LFM.spin(fwd,80,vex::pct);
  wait(0.15,seconds);
  RFM.stop();
  LFM.stop();
  RBM.stop();
  LBM.stop();
 //Go Forward 
  RBM.spin(fwd,80,vex::pct);
  RFM.spin(fwd,80,vex::pct);
  LBM.spin(fwd,80,vex::pct);
  LFM.spin(fwd,80,vex::pct);
  wait(0.4,seconds);
  LBM.stop();
  RBM.stop();
  LFM.stop();
  RFM.stop();
 //Spin the Intakes 
  IntakeM.spin(fwd,100,vex::pct);
  IntakeB.spin(fwd,100,vex::pct);
  OutakeL.spin(fwd,100,vex::pct);
  OutakeR.spin(fwd,100,vex::pct);
   if (AUIN.objectDistance(mm) <= 50 && AUINT == true) {
     Osit -= 1;
     AUINT = false;
   } else if (AUIN.objectDistance(mm) >= 51) {
     AUINT = true;
   }
   if (Osit == 0) {
    OutakeL.stop();
    OutakeR.stop();
   }
  }

/* LEFT
  This is if the distance sensor senses
  that it is right next to a wall 
  or just on the left side of the home row*/
  if (Right == false) {
 //Side to the right   
  RBM.spin(fwd,85,vex::pct);
  LBM.spin(reverse,85,vex::pct);
  LFM.spin(fwd,100,vex::pct);
  RFM.spin(reverse,100,vex::pct);
  wait(1,seconds);
  RFM.stop();
  LFM.stop();
  RBM.stop();
  LBM.stop();
 //Rotate left 
  RFM.spin(fwd,80,vex::pct);
  LFM.spin(reverse,80,vex::pct);
  RBM.spin(fwd,80,vex::pct);
  LBM.spin(reverse,80,vex::pct);
  wait(0.15,seconds);
  RFM.stop();
  LFM.stop();
  RBM.stop();
  LBM.stop();
 //Go forward 
  RBM.spin(fwd,80,vex::pct);
  RFM.spin(fwd,80,vex::pct);
  LBM.spin(fwd,80,vex::pct);
  LFM.spin(fwd,80,vex::pct);
  wait(0.4,seconds);
  LBM.stop();
  RBM.stop();
  LFM.stop();
  RFM.stop();
 //Spin the intakes 
  IntakeM.spin(fwd,100,vex::pct);
  IntakeB.spin(fwd,100,vex::pct);
  OutakeL.spin(fwd,100,vex::pct);
  OutakeR.spin(fwd,100,vex::pct);
   if (AUIN.objectDistance(mm) <= 50 && AUINT == true) {
     Osit -= 1;
     AUINT = false;
   } else if (AUIN.objectDistance(mm) >= 51) {
     AUINT = true;
   }
   if (Osit == 0) {
    OutakeL.stop();
    OutakeR.stop();
   }
  }

  
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

void usercontrol(void) {
  // User control code here, inside the loop
  Controller1.Screen.clearScreen();
  while (1) {
   
   //Colour of the ball
     // Blue
      {
      Vision.takeSnapshot(Vision__BLUEBALL);
      if (Vision.objectCount>= 1) {
        Blue = true;        
      } else {
        Blue = false;
      }
      }
     // Red (Soon)
      {
      
      if (Vision.objectCount>=1) {
        Red = true;
      } else {
        Red = false;
      }
      }
      
   //Temp warning
       bool MT = false;
       int TempT = 80;

     //LBM
       if (LBM.temperature(percent) >= TempT) {
         if (MT == false){
         Controller1.Screen.clearLine(3);
         Controller1.Screen.setCursor(3,1);        
         Controller1.Screen.print("LBM is overheating");
         Bat = false;
         }
         TP += 1;

       } else if (LBM.temperature(percent) < TempT) {
         TP -= 1;
       }
     //LFM
       if (LFM.temperature(percent) >= TempT - 5) {
         if (MT == false){
         Controller1.Screen.clearLine(3);
         Controller1.Screen.setCursor(3,1);        
         Controller1.Screen.print("LFM is overheating");
         Bat = false;
         } 
         TP += 1;
       } else if (LFM.temperature(percent) < TempT - 5) {
         TP -= 1;
       }
     //RBM
       if (RBM.temperature(percent) >= TempT) {
         if (MT == false){
         Controller1.Screen.clearLine(3);
         Controller1.Screen.setCursor(3,1);       
         Controller1.Screen.print("RFM is overheating");
         Bat = false;
         }
         TP += 1;
       } else if (RBM.temperature(percent) < TempT - 5) {
         TP -= 1;
       }
     //RFM
       if (RFM.temperature(percent) >= TempT) {
         if (MT == false){
         Controller1.Screen.clearLine(3); 
         Controller1.Screen.setCursor(3,1);       
         Controller1.Screen.print("RBM is overheating");
         Bat = false;
         }
         TP += 1;        
       } else if (TP > 0 && RFM.temperature(percent) < TempT - 5) {
         TP -= 1;
       }
     //IntakeM
       if (IntakeM.temperature(percent) >= TempT) {
         if (MT == false){
         Controller1.Screen.clearLine(3);
         Controller1.Screen.setCursor(3,1);       
         Controller1.Screen.print("IntakeM is overheating");
         Bat = false;
         }
         TP += 1;
       } else if (IntakeM.temperature(percent) < TempT - 5) {
         TP -= 1;
       }
     //IntakeB
       if (IntakeB.temperature(percent) >= TempT) {
         if (MT == false){
         Controller1.Screen.clearLine(3);
         Controller1.Screen.setCursor(3,1);        
         Controller1.Screen.print("IntakeB is overheating");
         Bat = false;
         }
         TP += +1;
       } else if (IntakeB.temperature(percent) < TempT) {
         TP -= -1;   
       }
     //LBM
       if (LBM.temperature(percent) >= TempT) {
         if (MT == false){
         Controller1.Screen.clearLine(3);
         Controller1.Screen.setCursor(3,1);        
         Controller1.Screen.print("LBM is overheating");
         Bat = false;
         }
         TP += 1;

       } else if (LBM.temperature(percent) < TempT) {
         TP -= 1;
       }
     //Multiple Motors are over heating
       if (TP>1) {
        MT = true;
        Controller1.Screen.clearScreen();
        Controller1.Screen.setCursor(1,1);
        Controller1.Screen.print("Multiple Motors are");
        Controller1.Screen.setCursor(2,1);
        Controller1.Screen.print("Overheating");
        Controller1.rumble(rumblePulse);
       } else {
         MT = false;
       }



   //Driving

      //Variables for the Bot's driving 
      float Pwr = Controller1.Axis3.position(vex::pct);
      float Turn = Controller1.Axis1.position(vex::pct);
      float Side = Controller1.Axis4.position(vex::pct); 
      

      //Code for Bot's movement;
      LFM.spin(fwd, Pwr+Turn+Side,vex::pct);
      RFM.spin(fwd, Pwr-Turn-Side,vex::pct);
      LBM.spin(fwd, Pwr+Turn-Side,vex::pct);
      RBM.spin(fwd, Pwr-Turn+Side,vex::pct);

    
   //Intake
      //Code for the opposing teams ball to be spitted out
      if (RTeam == true && Blue == true && Eject == true) {
        IntakeB.spin(reverse,100,vex::pct);
        IntakeM.spin(fwd,100,vex::pct);
      } else if (RTeam == false && Red == true && Eject == true) {
        IntakeB.spin(reverse,100,vex::pct);
        IntakeM.spin(fwd,100,vex::pct);
       ////////////////////////////////////
    // If you want Outakes here is the code
      ////////////////////////////////////////////////////////////////// 
      } else if (Controller1.ButtonR2.pressing() && OuTK == true) {
        IntakeM.spin(fwd,100,vex::pct);
        IntakeB.spin(fwd,100,vex::pct);
        OutakeL.spin(fwd,100,vex::pct);
        OutakeR.spin(fwd,100,vex::pct);
      } else if (Controller1.ButtonR1.pressing() && OuTK == true) {
        IntakeM.spin(reverse,100,vex::pct);
        IntakeB.spin(reverse,100,vex::pct);
        OutakeL.spin(reverse,100,vex::pct);
        OutakeR.spin(reverse,100,vex::pct);
      } else if (Controller1.ButtonL1.pressing()  && OuTK == true) {
        IntakeB.spin(reverse,100,vex::pct);
        IntakeM.spin(fwd,100,vex::pct);
        OutakeL.spin(fwd,100,vex::pct);
        OutakeR.spin(fwd,100,vex::pct);
       ////////////////////////////////////
    // If you don't want Outakes here is the code
       //////////////////////////////////////////////////////////////////  
      } else if (Controller1.ButtonR2.pressing() && OuTK == false) {
        IntakeM.spin(fwd,100,vex::pct);
        IntakeB.spin(fwd,100,vex::pct);
      } else if (Controller1.ButtonR1.pressing() && OuTK == false) {
        IntakeM.spin(reverse,100,vex::pct);
        IntakeB.spin(reverse,100,vex::pct);
      } else if (Controller1.ButtonL1.pressing()  && OuTK == false) {
        IntakeB.spin(reverse,100,vex::pct);
        IntakeM.spin(fwd,100,vex::pct);
      } else {
        IntakeM.stop();
        IntakeB.stop();
        OutakeL.stop();
        OutakeR.stop();
      }


   //Teams
     // This code is to know if we are in the Blue Team
     if (Controller1.ButtonLeft.pressing()&& RTeam == true) {
     RTeam=false;
     Controller1.Screen.setCursor(1,1);
     Controller1.Screen.clearLine();
     Controller1.Screen.print("Blue Team");
     wait(0.3,seconds);
     } 
     // This code is to know if we are in the Red Team
     if (Controller1.ButtonLeft.pressing()&& RTeam == false) {
     RTeam=true;
     Controller1.Screen.setCursor(1,1);
     Controller1.Screen.clearLine();
     Controller1.Screen.print("Red Team");
     wait(0.3,seconds);
     }

   //Auto eject
    //Auto eject is on
    if (Controller1.ButtonUp.pressing() && Eject == false) {
    Eject = true;
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.clearLine(2);
    Controller1.Screen.print("Auto eject is on ");
    wait(0.2,seconds);
    }
    //Auto eject is off
    if (Controller1.ButtonUp.pressing() && Eject == true) {
    Eject = false;
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.clearLine(2);
    Controller1.Screen.print("Auto eject is off");
    wait(0.2, seconds);
    }

   //Outakes
    //Outakes is on
    if (Controller1.ButtonRight.pressing() && OuTK == false) {
    OuTK = true;
    Controller1.Screen.setCursor(3,1);
    Controller1.Screen.clearLine(3);
    Controller1.Screen.print("Outakes are on ");
    wait(0.2,seconds);
    }
    //Outakes is off
    if (Controller1.ButtonRight.pressing() && OuTK == true) {
    OuTK = false;
    Controller1.Screen.setCursor(3,1);
    Controller1.Screen.clearLine(3);
    Controller1.Screen.print("Outakes are off");
    wait(0.2, seconds);
    }

   
   //What side of the home row are we in?
     //Right side
     if (Controller1.ButtonX.pressing() && Right == false) {
     Right = true;
     Controller1.Screen.setCursor(3,1);
     Controller1.Screen.clearLine(3);
     Controller1.Screen.print("Right Side");
     wait(0.15,seconds);   
     }
     //Left side
     if (Controller1.ButtonX.pressing() && Right == true) {
     Right = false;
     Controller1.Screen.setCursor(3,1);
     Controller1.Screen.clearLine(3);
     Controller1.Screen.print("Left Side");   
     wait(0.15,seconds); 
     }

   //Autonomous
    if (Controller1.ButtonY.pressing()) {
     autonomous();
    }

  }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}