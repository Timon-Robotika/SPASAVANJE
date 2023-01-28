#pragma once
#include "helper.h"


void RobotLine::radionica() {
  if (setup()) {
    armOpen();
  }

if (lineAny()) {
    go(60, 60);
    delayMs(500);
    stop();
    delayMs(1000);
    end();
    delayMs(1000);
  }
  
  followWallAll();
  
 

}
