#pragma once
#include "helper.h"


void RobotLine::radionica() {

  static int broj = 0;
  static int brzina = 0;
  static int a = 0;
  char simbol[10 + sizeof(char)];
  if (broj == 1) {
    while (!lineAny()) {
      go(10, 55);
      delayMs(700);
      if (lineAny()) {
        break;
        broj++;
      }
      go(65, 10);
      delayMs(750);
      if (lineAny()) {
        break;
        broj++;
      }
      noLoopWithoutThis();
      a++;
      if (a == 1) {
        broj++;
      }
    }
  }


  if (lineAny()) {

    if (broj == 0) {
      brzina = 0;
      if (line(0) and line(8) or line(1) and line(7)) {
        go(-90, 90);
        delayMs(500);
        broj++;
      }
    }

    if (broj == 1) {
      brzina = 0;
      if (line(0)) {
        go(90, -90);
        delayMs(500);
      }
    }
    if (broj == 2) {
      brzina = 1;
      if (line(7) and line(8)) {
        go(100, 100);
        delayMs(150);
        broj++;
      }
    }

    if (broj == 3) {
      brzina = 0;
      if (line(8) and line(0) or line(7) and line(1)) {
        go(-90, 90);
        delayMs(1000);
        broj++;
      }
    }
    if (broj == 4) {
      brzina = 0;
      if (line(0) or line(1)) {
        go(80, -40);
        delayMs(750);
        broj++;

      }
    }

    if (broj == 5) {
      brzina = 1;
      if (pitch() < -10){
        broj++;
      }
    }
    if (broj == 6){
      stop();
      delayMs(1000000);
    }

  }

  // kontrola brzine:
  if (brzina == 0) {
    if (broj == 2)
      objectOnLine(0);
    else
      lineSlow();
  }
  else if (brzina == 1) {
    if (broj == 2)
      objectOnLine(1);
    else
      lineFast();
  }

  // Ne mjenjati, služi za pretvorbu vrste varijable i ispis na 8x8 led
  sprintf(simbol, "%d", broj);
  display(simbol);
}
