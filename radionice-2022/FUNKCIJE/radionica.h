#pragma once
#include "helper.h"


void RobotLine::radionica() {
  static int broj = 0;
  if (lineAny()) {


  if (broj < 2) {
    if (line(1) and line(7)) {
      go(-50, 50);
      delayMs(500);
      broj++;
    }
    if (broj > 1) {
      if (line(8) and line(0)) {
        go(-90, 90);
        delayMs(1000);
      }
      else if (line(7) or line(8)) {
        go(60, 60);
        delayMs(200);
      }
      else if (line(0) or line(1)) {
        go(90, -90);
        delayMs(500);

      }
    }

  }
objectOnLine();

}
else{
  go(60, 60);
}
}
