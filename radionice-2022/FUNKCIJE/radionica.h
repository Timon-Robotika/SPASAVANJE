#pragma once
#include "helper.h"


void RobotLine::radionica() {

  //  definiraj varijable
  char simbol[10 + sizeof(char)];
  static uint32_t ms = 0;
  static int lijevo = 2;
  static int naprijed = 2;
  static int desno = 2;
  static int a = 1;

  // idi naprijed dok nisi na raskrzju
  lineSlow();

  // ako vidi raskrzje
  if (line(8) and line(0) or line(1) and line(7) and a > 4) {
    //skreni 90 stupnjeva
    go(-90, 90);
    delayMs(500);
    // nakon 2 sek provjeri jeli ima crte
    ms = millis();
    while (millis() - ms < 1800) {
      go(40, 40);
      if (!lineAny()) {
        if (a == 1)
          lijevo = 0;
        if (a == 2)
          naprijed = 0;
        if (a == 3)
          desno = 0;
      }
      else if (lineAny()) {
        if (a == 1)
          lijevo = 1;
        if (a == 2)
          naprijed = 1;
        if (a == 3)
          desno = 1;
      }
      noLoopWithoutThis();
    }

    // 1 sek displayaj varijablu (1 ili 0)
    stop();
    if (a == 4){
      lineSlow();
      if (line(8) and line(0) or line(7) and line(1)){
        go(60, 60);
        delayMs(1500);
        stop();
        delayMs(100000);
      }
    }
    if (a == 3) {
      sprintf(simbol, "%d", desno);
      display(simbol);
      delayMs(1000);
    }
    else if (a == 2) {
      sprintf(simbol, "%d", naprijed);
      display(simbol);
      delayMs(1000);
    }
    else if (a == 1) {
      sprintf(simbol, "%d", lijevo);
      display(simbol);
      delayMs(1000);
    }
    // vrati se nazad
    go(90, -90);
    delayMs(1000);
    go(40, 40);
    delayMs(600);
    a++;

  }

}
