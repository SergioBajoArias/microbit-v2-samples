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

void freeFall() {
    //Wait until we seem to be entering freefall.
    while (uBit.accelerometer.getGesture() != ACCELEROMETER_EVT_FREEFALL) {
        fiber_sleep(75);
    }

    uBit.serial.send("Free fall");
    uBit.display.scroll("BANZAI!");
}

void testLog() {
    uBit.log.setVisibility(true);
    uBit.log.setTimeStamp(TimeStampFormat::Seconds);

    //Only keep logging while we have space left.
    for (int i = 0; i < 6 * 60 || !uBit.log.isFull(); i++) {

        //Create a row with temperature data.
        uBit.log.beginRow();
        uBit.log.logData("Temperature", uBit.thermometer.getTemperature());
        uBit.log.endRow();

        //Wait a while.
        uBit.sleep(10 * 1000);
    }
}

void hello_world() { 
  uBit.init(); 
  create_fiber(displayHello);
  release_fiber();
}