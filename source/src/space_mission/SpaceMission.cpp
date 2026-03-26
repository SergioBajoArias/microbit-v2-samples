#include "SpaceMission.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "Logger.h"
#include <string>
#include <list>

Spaceship spaceship;
std::list<Asteroid> asteroids;

static void showSprite(Sprite sprite) {
  // log("Sprint position is [" + std::to_string(sprite.getX()) + "," + std::to_string(sprite.getY()) + "]");
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

    hideSprite(spaceship);
    uBit.display.scrollAsync("SPACE MISSION");
    showSprite(spaceship);

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);

    bool gameOver = false;
    int step = 0;
    while(!gameOver) {
        /*if(!asteroids.empty()) {
          for(Asteroid asteroid : asteroids) {
            hideSprite(asteroid);
            if(asteroid.isBottomLimit()) {
              asteroids.remove(asteroid);
              delete &asteroid;
            } else {
              asteroid.moveDown();
              showSprite(asteroid);
              if(spaceship.hasCollided(asteroid)) {
                gameOver = true;
                break;
              };
            }
          }
        }

        if(step % 3 == 0) {
          Asteroid asteroid;
          asteroids.push_front(asteroid);
          showSprite(asteroid);
          
          asteroids.remove(asteroid);
          delete &asteroid;
        }*/
        
        int tempo = 1000 - step;
        uBit.sleep(tempo);
    }

    release_fiber();

}