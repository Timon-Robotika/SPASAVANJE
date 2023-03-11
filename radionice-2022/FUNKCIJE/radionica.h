#pragma once
#include "helper.h"


void RobotLine::radionica() {
  static int broj = 0;
  static int a = 4;
  if (lineAny()) {


    if (broj < 2) {
      if (line(1) and line(7)) {
        go(-50, 50);
        delayMs(500);
        broj++;
      }
    }
    if (broj == 2) {
      if (line(7) and line(8)) {
        stop();
        delayMs(500);
        go(60, 60);
        delayMs(300);
        broj++;
      }
    }
    if (broj == 3) {
      if (line(8) and line(0)) {
        go(-90, 90);
        delayMs(1000);
        broj++;
      }
    }
    if (broj == 4) {
      if (line(0) or line(1)) {
        go(90, -90);
        delayMs(500);
        broj++;

      }
    }


    objectOnLine();

  }

}
