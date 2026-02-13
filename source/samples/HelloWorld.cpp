#include "HelloWorld.h"
#include "MicroBit.h"


void displayHello() {
    while (1) { // loop for ever
        int rtn = uBit.display.scrollAsync("HELLO WORLD!");
        if (rtn == MICROBIT_OK) {
            uBit.serial.send("Display OK\n");
        } else if (rtn == MICROBIT_BUSY) {
            uBit.serial.send("Display Busy\n");
        } else { // error
            uBit.serial.send("Invalid param\n");
        }
        uBit.sleep(1000); // wait 1sec and loop to try and display again
    }
}

void hello_world() { 
  uBit.init(); 
  create_fiber(displayHello);
  release_fiber();
}