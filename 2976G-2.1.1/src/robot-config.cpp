#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LFM = motor(PORT1, ratio18_1, true);
motor LBM = motor(PORT2, ratio18_1, false);
motor RFM = motor(PORT3, ratio18_1, false);
motor RBM = motor(PORT4, ratio18_1, true);
controller Controller1 = controller(primary);
motor IntakeB = motor(PORT10, ratio6_1, true);
motor IntakeM = motor(PORT9, ratio6_1, true);
/*vex-vision-config:begin*/
signature Vision__BLUEBALL = signature (2, -3837, -2989, -3414, 8555, 10803, 9678, 1, 0);
signature Vision__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
vision Vision = vision (PORT8, 50, Vision__BLUEBALL, Vision__SIG_3, Vision__SIG_4);
/*vex-vision-config:end*/
motor OutakeL = motor(PORT11, ratio36_1, false);
motor OutakeR = motor(PORT12, ratio36_1, true);
distance AUIN = distance(PORT5);
line Downer = line(Brain.ThreeWirePort.E);
line Upper = line(Brain.ThreeWirePort.F);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}