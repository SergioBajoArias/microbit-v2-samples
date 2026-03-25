#include "SpaceMission.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "Logger.h"
#include <string>
#include <list>

Spaceship spaceship;
std::list<Asteroid> asteroids;

static void showSprite(Sprite sprite) {
  uBit.display.image.setPixelValue(sprite.getX(), sprite.getY(), 255);
}

static void hideSprite(Sprite sprite) {
  uBit.display.image.setPixelValue(sprite.getX(), sprite.getY(), 0);
}

static void onButtonA(MicroBitEvent) {
  log("Button A\n");
  hideSprite(spaceship);
  spaceship.moveLeft();
  showSprite(spaceship);
}

static void onButtonB(MicroBitEvent) {
  log("Button B\n");
  hideSprite(spaceship);
  spaceship.moveRight();
  showSprite(spaceship);
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