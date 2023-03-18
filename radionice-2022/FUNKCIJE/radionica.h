#pragma once
#include "helper.h"


void RobotLine::radionica() {

  static int broj = 0;
  static int a = 4;
  char simbol[10 + sizeof(char)];
  while (!lineAny()) {
    go(20, 60);
    delayMs(500);
    if (lineAny()) {
      break;
    }
    go(60, 20);
    delayMs(500);
    if (lineAny()) {
      break;
    }
    noLoopWithoutThis();

  }
  if(lineAny()){
    if (broj == 2) {
      objectOnLine();
    }
    else {
      linePreciseFollow();

    }

    if (broj < 2) {
      if (line(1) and line(7)) {
        go(-50, 50);
        delayMs(500);
        broj++;
      }
    }
    if (broj == 2) {
      if (line(7) and line(8)) {
        go(100, 100);
        delayMs(100);
        broj++;
      }
    }
    if (broj == 3) {
      if (line(8) and line(0) or line(7) and line(1)) {
        go(-90, 90);
        delayMs(1000);
        broj++;
      }
    }
    if (broj == 4) {
      if (line(0) or line(1)) {
        go(80, -80);
        delayMs(500);
        go(80, 80);
        delayMs(100);
        broj++;

      }
    }
    if (broj == 5){
      // povecaj kad je pitch -10

      
    }
  }

  // Ne mjenjati, služi za pretvorbu vrste varijable i ispis na 8x8 led
  sprintf(simbol, "%d", broj);
  display(simbol);
}
