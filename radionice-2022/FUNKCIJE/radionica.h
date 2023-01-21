#pragma once
#include "helper.h"


void RobotLine::radionica() {
  if (setup()) {
    armOpen();
  }


  followWallAll();

  if (followWallAll() == 1) {
    go(60, 60);
    delayMs(500);
    stop();
    end();
  }
if (followWallAll() == 2) {
  go(-90, 90);
  delayMs(500);
}
if (followWallAll() == 3) {
  go(90, -90);
  delayMs(500);
}
  
}
