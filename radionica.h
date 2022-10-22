#pragma once
#include "helper.h"
void RobotLine::radionica() {
 if ((line(0) || line(8)) && pitch() < -10)
   go(120, 120);
  else if (line(8))
    go(-90, 90);
  else if (line(0))
    go(90, -90);
  else if (line(1))
    go(70, -20);
  else if (line(2))
    go(60, 10);
  else if (line(3))
    go(50, 20);
  else if (line(5))
    go(20, 50);
  else if (line(6))
    go(10, 60);
  else if (line(7))
    go(-20, 70);
  else
    go(120, 120);
}
