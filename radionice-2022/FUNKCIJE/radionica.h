#pragma once
#include "helper.h"


void RobotLine::radionica() {
  /*
    static int broj = 0;
    static int brzina = 0;
    static int a = 0;
    char simbol[10 + sizeof(char)];


    if (broj == 0) {
      brzina = 0;
      if (line(0) and line(8) or line(1) and line(7)) {
        go(-40, 80);
        delayMs(750);
        broj++;
      }
    }

    if (broj == 1) {
      brzina = 0;
      if (line(0)) {
        go(80, -40);
        delayMs(750);
        broj++;
      }
    }
    if (broj == 2) {
      while (!lineAny()) {
        go(10, 60);
        delayMs(700);
        if (lineAny()) {
          break;
          broj++;
        }


        go(60, 10);
        delayMs(750);
        if (lineAny()) {
          break;
          broj++;
        }


        go(60, 10);
        delayMs(750);
        if (lineAny()) {
          break;
          broj++;
        }


        go(10, 60);
        delayMs(700);
        if (lineAny()) {
          break;
          broj++;
        }
        noLoopWithoutThis();

      }
    }
    if (broj == 3) {
      brzina = 1;
      if (line(7) and line(8)) {
        go(90, 90);
        delayMs(150);
        broj++;
      }
    }

    if (broj == 4) {
      brzina = 0;
      if (line(8) and line(0) or line(7) and line(1)) {
        go(-90, 90);
        delayMs(1000);
        broj++;
      }
    }
    if (broj == 5) {
      brzina = 0;
      if (line(0) or line(1)) {
        go(80, -40);
        delayMs(750);
        broj++;

      }
    }

    if (broj == 6) {
      brzina = 1;
      if (pitch() < -10) {
        broj++;
      }
    }
    if (broj == 7) {
      brzina = 1;
      if (line(0) and line(8) or line(1) and line(7)) {
        go(100, 80);
        delayMs(500);
        broj++;
      }
    }
    if (broj == 8) {
      brzina = 0;
      if (pitch() < 10) {
        broj++;
      }
    }

    if (broj == 8) {
      brzina = 0;
    }




    // kontrola brzine:
    if (brzina == 0) {
      if (broj == 3)
        objectOnLine(0);
      else
        lineSlow();
    }
    else if (brzina == 1) {
      if (broj == 2)
        objectOnLine(3);
      else
        lineFast();
    }




    // Ne mjenjati, služi za pretvorbu vrste varijable i ispis na 8x8 led
    sprintf(simbol, "%d", broj);
    display(simbol);
  */

  int ms = millis();

  while (millis() - ms > 2000) {
    go(60, 60);
    if (line(8) and line(0)) {
      break;
    }

  }
}
