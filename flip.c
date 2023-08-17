// ------ Libraries and Definitions ------
#include "simpletools.h"
#include "fdserial.h"

// ------ Global Variables and Objects ------
int status;
int ScanBtn;
int Lastscan;
fdserial *fdser14_15;

// ------ Function Declarations ------
void CheckAllPins();

// ------ Main Program ------
int main()
{
  fdser14_15 = fdserial_open(14, 15, 0b0000, 9600);
  status = 1;
  while (!(status == 0)) {
    status = (get_states(14, 14));
    pause(500);
  }
  ScanBtn = 0;
  Lastscan = 0;
  CheckAllPins();
  if (ScanBtn == 0) {
  }
  else {
    dprint(fdser14_15, "%s\r", ("ROW1A"));
    while(!fdserial_txEmpty(fdser14_15));
    pause(5);
    dprint(fdser14_15, "%b\r", ScanBtn);
    dprint(fdser14_15, "%s\r", ("\n"));
    while(!fdserial_txEmpty(fdser14_15));
    pause(5);
  }

  while(1) {
    pause(500);
    CheckAllPins();
    if (ScanBtn == Lastscan) {
    }
    else {
      if (ScanBtn == 0) {
        pause(200);
        dprint(fdser14_15, "%s\r", ("REMOVE1A\n"));
        while(!fdserial_txEmpty(fdser14_15));
        pause(5);
      }
      else {
        dprint(fdser14_15, "%s\r", ("ROW1A"));
        while(!fdserial_txEmpty(fdser14_15));
        pause(5);
        dprint(fdser14_15, "%b\r", ScanBtn);
        dprint(fdser14_15, "%s\r", ("\n"));
        while(!fdserial_txEmpty(fdser14_15));
        pause(5);
      }

      Lastscan = ScanBtn;
      ScanBtn = 0;
    }

  }

}

// ------ Functions ------
void CheckAllPins() {
  set_outputs(12, 0, 0b0000000000000);
  pause(500);
  if (input(0)) {
    ScanBtn = (ScanBtn + 4096);
  }

  if (input(1)) {
    ScanBtn = (ScanBtn + 2048);
  }

  if (input(2)) {
    ScanBtn = (ScanBtn + 1024);
  }

  if (input(3)) {
    ScanBtn = (ScanBtn + 512);
  }

  if (input(4)) {
    ScanBtn = (ScanBtn + 256);
  }

  if (input(5)) {
    ScanBtn = (ScanBtn + 128);
  }

  if (input(6)) {
    ScanBtn = (ScanBtn + 64);
  }

  if (input(7)) {
    ScanBtn = (ScanBtn + 32);
  }

  if (input(8)) {
    ScanBtn = (ScanBtn + 16);
  }

  if (input(9)) {
    ScanBtn = (ScanBtn + 8);
  }

  if (input(10)) {
    ScanBtn = (ScanBtn + 4);
  }

  if (input(11)) {
    ScanBtn = (ScanBtn + 2);
  }

  if (input(12)) {
    ScanBtn = (ScanBtn + 1);
  }

}
