/*vex-vision-config:begin*/
#include "v5.h"
#include "v5_vcs.h"
vex::vision::signature ORANGER = vex::vision::signature (1, 6929, 8727, 7828, -2247, -1441, -1844, 2.5, 0);
vex::vision::signature GREENER = vex::vision::signature (2, -7969, -5121, -6546, -4767, -2161, -3464, 2.5, 0);
vex::vision::signature PURPLER = vex::vision::signature (3, 755, 1983, 1368, 6229, 9473, 7852, 3, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision visioner = vex::vision (vex::PORT5, 50, ORANGER, GREENER, PURPLER, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/