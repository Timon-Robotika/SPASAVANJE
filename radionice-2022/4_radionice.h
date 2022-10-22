#pragma once
#include "helper.h"
void RobotLine::radionica() {
 static int broj = 0;
 char simbol[10 + sizeof(char)];

// ZADATAK: napravite if naredbu da se robot zaustavi nakon što se vrati na početak
if (broj >= 5){
   stop(), end();
} 
if (front() < 120){
   go(-90, 90);
   delayMs(500);
   broj++;
 }
 if (rightFront() > 120)
   go(80, 20);
 else
   go(20, 80);

 sprintf(simbol,"%d", broj);
 display(simbol);
}
