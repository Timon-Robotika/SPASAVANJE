#pragma once
#include "helper.h"


void RobotLine::radionica() {
  static int broj;
  static int brzina;
  static int a;
  int ms;

  if (setup()) {
    broj = 0;
    brzina = 0;
    a = 0;
    ms = 0;
  }


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
    go(80, 80);
    delayMs(500);
    broj++;
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
    brzina = 2;
    if (line(0) and line(8) or line(1) and line(7)) {
      go(100, 80);
      delayMs(500);
      broj++;
    }
  }
  if (broj == 8) {
    brzina = 0;
    if (line(0) and line(8) or line(1) and line(7)) {
      broj++;
    }
  }

  if (broj == 9) {
    brzina = 1;
    armOpen();
    if (frontRight() < 100 and frontRight() > 20)
      stop();
    delayMs(1000000);
  }




  // kontrola brzine:
  if (brzina == 0) {
    if (broj == 3)
      objectOnLine(0);
    else
      lineSlow();
  }
  else if (brzina == 1) {
    if (broj == 3)
      objectOnLine(1);
    else
      lineFast();
  }
  else if (brzina == 3)
    linePitch();



  sprintf(simbol, "%d", broj);
  display(simbol);


// POPRAVI IZBJEGAVANJE CUNJA, FAST LINE FOLLOWERA I "IDI NAPRIJED KAD JE PRAZNO"
}
