#include "SpaceMission.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "Logger.h"
#include <string>
#include <list>

Spaceship spaceship;
std::list<Asteroid> asteroids;

static void onButtonA(MicroBitEvent) {
  log("Button A\n");
  spaceship.moveLeft();
}

static void onButtonB(MicroBitEvent) {
  log("Button B\n");
  spaceship.moveRight();
}

void space_mission() {
    uBit.init();
    uBit.display.scrollAsync("SPACE MISSION");

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);

    while(true) {
        uBit.sleep(1000);
    }

    release_fiber();

}