/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\s109345                                          */
/*    Created:      Tue Sep 10 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "FrontV.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
competition      compy;
vex::controller Contra = vex::controller();
vex::motor tRM = vex::motor(vex::PORT1);  
vex::motor tLM = vex::motor(vex::PORT3);
vex::motor bRM = vex::motor(vex::PORT2);  
vex::motor bLM = vex::motor(vex::PORT4);
vex::motor clawL = vex::motor(vex::PORT7);
vex::motor clawR = vex::motor(vex::PORT8);
vex::motor clawH = vex::motor(vex::PORT10);
vex::motor stacker = vex::motor(vex::PORT11);
/*
vex::line top = vex::line(Brain.ThreeWirePort.H); // top sensor
vex::line righter = vex::line(Brain.ThreeWirePort.A); //right sensor
vex::bumper frontre = vex::bumper(Brain.ThreeWirePort.G);

https://help.vexcodingstudio.com/#pro/namespacevex/classvex_1_1encoder/rotation
*/



int blox = 1;
int turn = 1;
int counter = 0;
int tick;

// define your global instances of motors and other devices here lmao
char weird(int toggle){

char mother[20] = "tony spargetti";
return mother[toggle];
}


//raises and lowers the claws
void hClaw(double vel){
clawH.setVelocity(vel, vex::velocityUnits::pct);
        clawH.spin(vex::directionType::fwd);

}
//sets speed of claws
void goClaw(int vel){
clawL.setVelocity(vel, vex::velocityUnits::pct);
clawR.setVelocity(-vel, vex::velocityUnits::pct);
clawL.spin(vex::directionType::fwd);
clawR.spin(vex::directionType::fwd);
}


//sets the speed for all the motors (tells them to go)
void go(int l, int r){
  //tRM = top right motor
  tRM.setVelocity(r, vex::velocityUnits::pct);
  //tLM = top left motor
  tLM.setVelocity(l, vex::velocityUnits::pct);
  //bRM = bottom right motor
  bRM.setVelocity(r, vex::velocityUnits::pct);
  //bLM = bottom left motor
  bLM.setVelocity(l, vex::velocityUnits::pct);
}
//tells the robot to turn left
void turnR(double time, int vas){
   vas /= 3;
  go(vas,vas);
  tRM.spin(vex::directionType::fwd);
  tLM.spin(vex::directionType::fwd);
  bRM.spin(vex::directionType::fwd);
  bLM.spin(vex::directionType::fwd);
Brain.Screen.printAt( 10, 50, "turnR",counter++ );

vex::task::sleep(time*turn);
  
 
}
//tells the robot to turn right
void turnL(double time, int vas){
   vas /= 3;
 go(vas,vas);
tRM.spin(vex::directionType::rev);
  tLM.spin(vex::directionType::rev);
  bRM.spin(vex::directionType::rev);
  bLM.spin(vex::directionType::rev);
Brain.Screen.printAt( 10, 50, "turnL",counter++ );

vex::task::sleep(time*turn);
   

}
//tells the robot to go forward
void forWard(double time, int vas){
   vas /= 3;
 go(vas,vas);
  tRM.spin(vex::directionType::rev);
  tLM.spin(vex::directionType::fwd);
  bRM.spin(vex::directionType::rev);
  bLM.spin(vex::directionType::fwd);
//Brain.Screen.printAt( 10, 50, "forward     %d",counter,counter++ );

vex::task::sleep(time*blox);
     
  
}
//tells the motor to go in reverse
void reVarse(double time, int vas){
  vas /= 3;
  go(vas,vas);
 tRM.spin(vex::directionType::fwd);
  tLM.spin(vex::directionType::rev);
  bRM.spin(vex::directionType::fwd);
  bLM.spin(vex::directionType::rev);
Brain.Screen.printAt( 10, 50, "reverend",counter++ );

vex::task::sleep(time*blox);


}
void straL(double time, int vas){
vas /= 3;
  go(vas,vas);
  tRM.spin(vex::directionType::rev);
  tLM.spin(vex::directionType::rev);
  bRM.spin(vex::directionType::fwd);
  bLM.spin(vex::directionType::fwd);
Brain.Screen.printAt( 10, 50, "slide to the left",counter++ );

vex::task::sleep(time*blox);

}

void straR(double time, int vas){

  vas /= 3;
  
  go(vas,vas);
   tRM.spin(vex::directionType::fwd);
  tLM.spin(vex::directionType::fwd);
  bRM.spin(vex::directionType::rev);
  bLM.spin(vex::directionType::rev);
  
Brain.Screen.printAt( 10, 50, "slide to the right",counter++ );

vex::task::sleep(time*blox);
}

void lift(){
  clawL.setBrake(coast);
  clawR.setBrake(coast);
  goClaw(-20);
  reVarse(10,30);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          

void autonomunch(){
bool blue = false;
int tig = 1;
hClaw(50);
//forWard(1,100);
vex::task::sleep(1000);
//go(0,0);
//forWard(1,-100);
vex::task::sleep(1100);
//go(0,0);
hClaw(-50);

vex::task::sleep(1000);

clawH.setBrake(hold);
hClaw(0);
goClaw(60);
forWard(1,-100);
vex::task::sleep(600);
hClaw(-50);
vex::task::sleep(1000);
go(0,0);
hClaw(0);
clawH.setBrake(coast);
goClaw(69);
vex::task::sleep(200);
forWard(2460,200);
goClaw(0);
go(0,0);
if(blue){
turnL(1950,100);
}
else{
  turnR(1950,100);
}
forWard(2450,200);

go(0,0);
 clawL.setBrake(coast);
       clawR.setBrake(coast);
      
while ( stacker.rotation(rotationUnits::deg) > -1222){
  if(tig == 1){
    tig = 0;
stacker.setVelocity(70, vex::velocityUnits::pct);
       stacker.spin(vex::directionType::rev);

  }    
 Brain.Screen.printAt( 10, 50, "%d",stacker.rotation(rotationUnits::deg) ,counter++ );
}
vex::task::sleep(300);
//hope stack stays up
stacker.setVelocity(60, vex::velocityUnits::pct);
       stacker.spin(vex::directionType::fwd);

       vex::task::sleep(500);
        goClaw(-45);
reVarse(2000,150);
}





//funcion that runs the autonomous code
void autonomissy(void){
  //this determines if you are blue or red, if blue blue = true
  bool blue = false;
  int tig = 1;
hClaw(50);
vex::task::sleep(2000);
hClaw(-50);
vex::task::sleep(1000);

clawH.setBrake(hold);
hClaw(0);
goClaw(60);
vex::task::sleep(500);
hClaw(-50);
 
vex::task::sleep(1000);
hClaw(0);
clawH.setBrake(coast);
goClaw(40);
//pick up starter block
forWard(1650,80);

//pick up feild block #1
goClaw(0);
if(blue){
turnR(1050,100);
}
else{
turnL(1050,100);
}
goClaw(37);
forWard(1450,100);
//pick up feild block #2
if(blue){
turnR(550,100);
}
else{
  turnL(550,100);
}
 clawL.setBrake(coast);
       clawR.setBrake(coast);
       goClaw(0);
forWard(1920,100);

//vex::task::sleep(300);



//dock into goal area (hopefully)

//commense stacking
//IMPORTANT NEED TO DO TEST TO FIND THE PROPER ANGLE
go(0,0);
 clawL.setBrake(coast);
       clawR.setBrake(coast);
      
while ( stacker.rotation(rotationUnits::deg) > -1222){
  if(tig == 1){
    tig = 0;
stacker.setVelocity(80, vex::velocityUnits::pct);
       stacker.spin(vex::directionType::rev);

  }    
 Brain.Screen.printAt( 10, 50, "%d",stacker.rotation(rotationUnits::deg) ,counter++ );
}
vex::task::sleep(200);
//hope stack stays up
stacker.setVelocity(60, vex::velocityUnits::pct);
       stacker.spin(vex::directionType::fwd);

       vex::task::sleep(500);
        goClaw(-35);
reVarse(2000,90);
  

//maybe use the lift function here ?
}



void autonomoous(void){
 
  bool blue = false;
  Brain.Screen.printAt( 10, 50, "I want to cry",counter++ );
  forWard(500,40);
  go(0,0);
if(blue){
  straL(3000,70);
  straR(2000,75);
}
else{
  straR(3000,70);
  straL(2000,75);
}
go(0,0);
hClaw(50);
vex::task::sleep(1700);
hClaw(-50);
vex::task::sleep(1700);
hClaw(0);

}





//function that runs the driver control
void usercontrol(void){
bool bColor [3] = {false,false,false};
bool chck = false;
int  size [3] =  {0,0,0};
int domColor = 0;
int hold = 0;
int antistrip = 1;
int turbo = 1;
bool check = Contra.ButtonL1.pressing();
int toggleer = 0;
int dink =1;
bool squid = true;
int pepper = 1;
int st = 1;
int aStrip = 0;
int turbto = 0;
int slt = 1;
int hbuffer = 1;


  /*
  bool checkStart = Contra.ButtonY.pressing();
     //autonomous section
     if(!checkStart && toggleer ==0){
       autonomoous();
     }
     //driver controled section
     else{
       toggleer =1;
*/
clawH.resetRotation();
stacker.resetRotation();
  while(true){


  Brain.Screen.printAt( 10, 50, "slide to the left    %f",stacker.rotation(rotationUnits::deg),counter++ );
  if(Contra.ButtonX.pressing() &&turbto == 0){
    turbto = 1;
if( turbo == 1){
       turbo = 3;
       dink = 0;
      
     }
     else if (turbo == 3){

       turbo = 1;
       dink = 1;
     
     }
  }
  else if(Contra.ButtonX.pressing()){

  }
  else{
  turbto = 0;
  }

if(Contra.ButtonUp.pressing()){
stacker.setRotation(0,vex::rotationUnits::deg);
}


if(Contra.ButtonA.pressing() && slt == 1){
       slt = 0;
       if(pepper == 1){
       pepper = 3;
}
     
     else{
       pepper = 1;
       
       
     }
}
else if (Contra.ButtonA.pressing()){}
else{

  slt = 1;
}

     //contra test
     /*
     if(turbo == 3 && pepper == 3){
  Contra.Screen.print("salt and pepper");
     }
     else if(turbo == 3){
         Contra.Screen.print("turbo    ");
     }
     else if(pepper == 3){
         Contra.Screen.print("slowbo   ");
     }
     else{
         Contra.Screen.print("base     ");
     }
*/





     
     //autonomous test ?  AUTONOMOUS TEST


/*
     if(Contra.ButtonDown.pressing()){
bool blue = false;
  Brain.Screen.printAt( 10, 50, "I want to cry",counter++ );
  forWard(500,40);
  go(0,0);
if(blue){
  straL(6000,70);
  straR(2000,70);
}
else{
 straR(6000,70);
 straL(2000,70);
}
go(0,0);
hClaw(50);
vex::task::sleep(2000);
hClaw(-50);
vex::task::sleep(2000);
hClaw(0);

     }
*/
      //stacker tilter thing
      if(Contra.Axis2.value() > 20){
        //maybe do a thing every frame? iterate slowly? I donno, let's see it in action first.
      stacker.setVelocity((Contra.Axis2.value()/4), vex::velocityUnits::pct);
       stacker.spin(vex::directionType::fwd);
       clawL.setBrake(coast);
       clawR.setBrake(coast);
       Contra.Screen.print("%d", stacker.rotation(rotationUnits::deg));
}
      
      else if(Contra.Axis2.value() <20){
    stacker.setVelocity((Contra.Axis2.value()/4), vex::velocityUnits::pct);
      stacker.spin(vex::directionType::fwd);
       clawL.setBrake(coast);
        clawR.setBrake(coast);
        Contra.Screen.print("%d", stacker.rotation(rotationUnits::deg));
      }
      else{
        stacker.setVelocity(0, vex::velocityUnits::pct);

      }
       
      //claw spin code
if(Contra.ButtonR2.pressing()){
      goClaw(60/pepper);
      clawL.setBrake(vex::hold);
        clawR.setBrake(vex::hold);
    }
    else if(Contra.ButtonL2.pressing()){
      goClaw(-60/pepper);
    }
    else {
      goClaw(0);
    }

      //claw height code
      if(Contra.ButtonL1.pressing() && hbuffer == 1){
        hbuffer = 0;
        hClaw(-50);
       antistrip *=-1;
      }
      
      else if(Contra.ButtonR1.pressing()){
        
        hClaw(50);
        aStrip++;
      }
      else if(clawH.rotation(rotationUnits::deg) > 0 && antistrip < 1){
        
      hClaw(-50);
      aStrip--;
      }
      else if (clawH.rotation(rotationUnits::deg) <= 20){
        hClaw(0);
        antistrip = 1;
      }
      
      else{
        hClaw(0);
        clawH.setBrake(vex::hold);
        }

if(!Contra.ButtonL1.pressing()){
  hbuffer = 1;
}

    if(Contra.ButtonB.pressing()){
     squid = false;
    }
      else{
        squid = true;
      }
    
    if(Contra.ButtonY.pressing()){
      lift();
    }
    else{
      go(0,0);
    }

     if(abs(Contra.Axis4.value()) > 50 || abs(Contra.Axis3.value()) > 50){
       if(squid == true){

       
     if(Contra.Axis4.value() > 50){
       turnR(2,(Contra.Axis4.value()*turbo)/pepper);
     
     }
     else if(Contra.Axis4.value() < -50){
       turnL(2,abs((Contra.Axis4.value())*turbo)/pepper);
     }
       }
     else{
       if(Contra.Axis4.value() > 50){
          straR(2,abs((Contra.Axis4.value())*turbo)/pepper);
       }
       else if(Contra.Axis4.value() < -50){
         straL(2,abs((Contra.Axis4.value())*turbo)/pepper);
       }

     }
     
     if(Contra.Axis3.value() > 50){
       forWard(2,(Contra.Axis3.value()*turbo)/pepper);
     }
     else if(Contra.Axis3.value() < -50){
      reVarse(2, abs((Contra.Axis3.value())*turbo)/pepper);
     }
     }
     else if (Contra.ButtonY.pressing()){

     }
     else{
       go(0,0);
     }
     
     Brain.Screen.printAt( 10, 50, "%d       %d",turbo,hold,counter++ );


      if(squid != true){
if(Contra.Axis1.value() > 50){
       turnR(2,Contra.Axis1.value()*turbo);
     
     }
     else if(Contra.Axis1.value() < -50){
       turnL(2,abs(Contra.Axis1.value())*turbo);
     }

      }
     }
}






int main() {
//this compares all the colors, and says which color is the biggest
bool bColor [3] = {false,false,false};
bool chck = false;
int  size [3] =  {0,0,0};
int domColor = 0;
int hold = 0;

bool panic = true;

int turbo = 1;
bool check = Contra.ButtonL1.pressing();
int toggleer = 0;
int dink =1;
stacker.resetRotation();


if(panic){
compy.autonomous(autonomunch);
compy.drivercontrol(usercontrol);
}
else{
while(true){
   Brain.Screen.printAt( 10, 50, "                             %d",counter++ );
bool checkStart = Contra.ButtonY.pressing();
     //autonomous section
     if(!checkStart ){
        //Brain.Screen.printAt( 10, 50, "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",counter++ );
       autonomoous();
       toggleer = 1;
       if(Contra.ButtonB.pressing()){

       //  Brain.Screen.printAt( 10, 50, "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",counter++ );
       }
       Brain.Screen.printAt( 10, 50, "FIN AUTO JEFF",counter++ );
     }
     //driver controled section
     
        
     
     else{
        Brain.Screen.printAt( 10, 50, "start e manuel",counter++ );
usercontrol();

     }
         //claw spin direction
/* 



ACTUAL CODE   PLEASE PRESERVE


    if(Contra.ButtonR2.pressing()){
      goClaw(30);
    }
    else if(Contra.ButtonL2.pressing()){
      goClaw(-30);
    }
    else {
      goClaw(0);
    }


      //turbo mode
     if(Contra.ButtonX.pressing() && dink == 1){
       turbo = 3;
       dink = 0;
     }
     else if (Contra.ButtonX.pressing() && dink == 0){

       turbo = 1;
       dink = 1;
     }


      //stacker tilter thing
      if(Contra.Axis2.value() > 20){
        //maybe do a thing every frame? iterate slowly? I donno, let's see it in action first.
      stacker.setVelocity((Contra.Axis2.value() /6), vex::velocityUnits::pct);
       stacker.spin(vex::directionType::fwd);
}
      
      else if(Contra.Axis2.value() <20){
    stacker.setVelocity((Contra.Axis2.value()/6), vex::velocityUnits::pct);
      stacker.spin(vex::directionType::fwd);
      }
      else{
        stacker.setVelocity(0, vex::velocityUnits::pct);

      }


      //claw height code
      if(Contra.ButtonL1.pressing()){
        //claw up
        clawH.setVelocity(-60, vex::velocityUnits::pct);
        clawH.spin(vex::directionType::fwd);
      }
      else if(Contra.ButtonR1.pressing()){
        //claw down
        clawH.setVelocity(60, vex::velocityUnits::pct);
        clawH.spin(vex::directionType::fwd);
      }
      else{
        
        clawH.setVelocity(0.5, vex::velocityUnits::pct);
        
        
        
        
      }



END OF ACTUAL CODE PART ONE, NOT PART 2 THERE IS MORE CODE



*/








     /*temp testing
     if(Contra.ButtonL2.pressing()){
         tRM.setVelocity(0, vex::velocityUnits::pct);
          tRM.spin(vex::directionType::rev);
          hold = 1;
     }
     else{
       tRM.setVelocity(30*turbo, vex::velocityUnits::pct);
        tRM.spin(vex::directionType::rev);
        hold = 0;
     }
     */

     //Actual motor driving thingy



/*



ACUTAL CODE START MACH 2


     if(abs(Contra.Axis4.value()) > 50 || abs(Contra.Axis3.value()) > 50){
     if(Contra.Axis4.value() > 50){
       turnR(2,Contra.Axis4.value()*turbo);
     
     }
     else if(Contra.Axis4.value() < -50){
       turnL(2,abs(Contra.Axis4.value())*turbo);
     }
     if(Contra.Axis3.value() > 50){
       forWard(2,Contra.Axis3.value()*turbo);
     }
     else if(Contra.Axis3.value() < -50){
      reVarse(2, abs(Contra.Axis3.value())*turbo);
     }
     }
     else{
       go(0,0);
     }
     
     Brain.Screen.printAt( 10, 50, "%d       %d",turbo,hold,counter++ );


ACTUAL CODE END MACH 2


     */
     /*
    for(int i = 1;i <4;i++){
      bColor[i-1] = visioner.takeSnapshot(i);
size[i-1] = visioner.largestObject.width;
if(bColor[i-1]){
  chck = true;
}
if(domColor == 0){
domColor = size[i-1];
hold = i;
}
else if (domColor < size[i-1]){
domColor = size[i-1];
hold = i;
}

}
if(!chck ){
  hold = 0;
}
switch(hold){
case 1 :
Brain.Screen.printAt( 10, 50, "Orange",counter++ );
break;
case 2 :
Brain.Screen.printAt( 10, 50, "GREEEN",counter++ );
break;

case 3:
Brain.Screen.printAt( 10, 50, "Purple",counter++ );
break;
default:
Brain.Screen.printAt( 10, 50, "noooo",counter++ );
break;


}
domColor = 0;
chck = false;
hold = 0;
*/
  
    }
}

    
  
  /*
    int count = 0;
     char money[9] = "1";
    char mom[29] = "dick chaney";
   for(int i = 1; i <7;i++){
    money[i] = weird(i);
Brain.Screen.printAt( 10, 50, money, i );
 }
 int em =0;
 if(em ==1){
   */
   /*
 forWard(1900);
 turnL(3950);
 forWard(4000);
 turnR(3950);
 forWard(5000);
 turnL(2150);
 forWard(3000);
 turnR(2200);
 forWard(1500);
 turnL(3750);

  Brain.Screen.printAt( 10, 50, "rev ford",counter++ );
vex::task::sleep(3800);
 turnL(3850);
 forWard(5700);
 turnL(3850);
 forWard(1950);
 turnL(3800);
 forWard(5700);
 turnR(3800);
 forWard(1950);
 turnR(3800);
 forWard(11400);
 turnL(3800);                           
 forWard(1900);
 turnL(3800);
 forWard(11400);
*/
/*
 }
 else{
int ford = 1;
int LorR = 0;
int toggler = 0;
int linehit = 0;
int timeer = 0;
int stimeer = 0;
for(int i = 1; i < 1000000000000000; i++){
  while(top.value(analogUnits::pct) >55 && ford == 1){
reVarse(5,5);
Brain.Screen.printAt( 10, 50,"line Top: %d  R: %d" ,(const char)top.value(analogUnits::pct),(const char)righter.value(analogUnits::pct),counter++ );
 tick = 1;
 if(frontre){
  ford = 0;
   LorR = 1;
   stimeer = 1;
 }
}
Brain.Screen.printAt( 10, 50, "                     %d   timer %d" ,(const char)LorR, (const char) timeer, counter++ );
if(tick == 1){
go(0,0);
vex::task::sleep(5);

tick = 0;
}
if (linehit >0 && linehit <3){
  linehit++;
}
else if(linehit == 2){
  LorR = 0;
  linehit = 0;
}

if(top.value(analogUnits::pct) >55 && timeer > 85){
  ford = 1;
  timeer = 0;
  linehit++;
  stimeer = 0;
}

if(LorR == 1){
turnR(10,25);
Brain.Screen.printAt( 10, 50,"Right" ,(const char)top.value(analogUnits::pct),(const char)righter.value(analogUnits::pct),counter++ );
if(stimeer == 1){
  timeer++;
}
}
else{
turnL(10,25);
Brain.Screen.printAt( 10, 50,"Left" ,(const char)top.value(analogUnits::pct),(const char)righter.value(analogUnits::pct),counter++ );
if(stimeer == 1){
  timeer++;
}
}
}
*/
//else{
  //int toggle = 1;
//  while(toggle){
 //   if(top.value(analogUnits::pct) < 59){
//turnL(250);

    
//else{
 // toggle = 0;
//}
 // }
//}
  
//}
// }
  
/*
   vex::task::sleep(1000);
   turnR(1000);
      lMotor.setVelocity(0, vex::velocityUnits::pct);
  rMotor.setVelocity(0, vex::velocityUnits::pct);
   vex::task::sleep(1000);
   turnL(1000);
      lMotor.setVelocity(0, vex::velocityUnits::pct);
  rMotor.setVelocity(0, vex::velocityUnits::pct);
   vex::task::sleep(1000);
   lMotor.stop();
    rMotor.stop();
    */
}
