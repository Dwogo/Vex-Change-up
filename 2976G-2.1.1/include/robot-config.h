using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor LFM;
extern motor LBM;
extern motor RFM;
extern motor RBM;
extern controller Controller1;
extern motor IntakeB;
extern motor IntakeM;
extern signature Vision__REDBALL;
extern signature Vision__BLUEBALL;
extern signature Vision__SIG_3;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;
extern motor OutakeL;
extern motor OutakeR;
extern distance AUIN;
extern line Downer;
extern line Upper;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );