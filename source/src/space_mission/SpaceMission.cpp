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
  log("Button A");
  hideSprite(spaceship);
  spaceship.moveLeft();
  showSprite(spaceship);
}

static void onButtonB(MicroBitEvent) {
  log("Button B");
  hideSprite(spaceship);
  spaceship.moveRight();
  showSprite(spaceship);
}

void space_mission() {
    uBit.init();

    hideSprite(spaceship);
    uBit.display.scroll("SPACE MISSION");
    showSprite(spaceship);

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);

    bool gameOver = false;
    int step = 1;
    while(!gameOver) {
        if(!asteroids.empty()) {
          log("Handling asteroids...");
          for(Asteroid& asteroid : asteroids) {
            log("Handling asteroid " + std::to_string(asteroid.getId()));
            log("Position is [" + std::to_string(asteroid.getX()) + "," + std::to_string(asteroid.getY()) + "]");
            hideSprite(asteroid);
            if(asteroid.isBottomLimit()) {
              log("Asteroid " + std::to_string(asteroid.getId()) + " is at the bottom. It will be removed");
              asteroids.pop_back();
              // delete &asteroid;
            } else {
              log("Moving down asteroid " + std::to_string(asteroid.getId()));
              asteroid.moveDown();
              showSprite(asteroid);
              if(spaceship.hasCollided(asteroid)) {
                log("Asteroid " + std::to_string(asteroid.getId()) + " crashed against the spaceship!");
                gameOver = true;
                break;
              };
            }
          }
        }

        if(!gameOver) {
          if(step %  2 == 0) {
            log("Adding a new asteroid to the collection");
            Asteroid asteroid;
            asteroids.push_front(asteroid);
            showSprite(asteroid);
          }
          
          int tempo = 1000 - (step * 3);
          uBit.sleep(tempo);
          log("Iteration " + std::to_string(step) + " finished");
          step++;
        }
        
    }
    
    uBit.display.clear();
    asteroids.clear();
    uBit.display.scroll("GAME OVER");

    release_fiber();

}