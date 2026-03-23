#include "SpaceMission.h"
#include <random>
#include <string>


const int TOP_LIMIT = 4;
const int BOTTOM_LIMIT = 0;
const int RIGHT_LIMIT = 4;
const int LEFT_LIMIT = 0;

class Sprite {
    public:
        int x;
        int y;

        void moveUp() {
            if(y < TOP_LIMIT) {
                y++;
            }
            
        }

        void moveDown() {
            if(y > BOTTOM_LIMIT) {
                y--;
            }
        }

        void moveLeft() {
            if(x > LEFT_LIMIT) {
                x--;
            }
        }

        void moveRight() {
            if(x < RIGHT_LIMIT) {
                x++;
            }
        }
};

class Spaceship : public Sprite {
    public:
        Spaceship() {
            y = BOTTOM_LIMIT;
            x = 2;
        }
};

class Asteroid : public Sprite {
    public:
        Asteroid() {
            y = TOP_LIMIT;
            x = std::rand() % RIGHT_LIMIT + 1;
        }
};

Spaceship spaceship;

static void log(std::string message) {
  uBit.serial.send(message.c_str());
}

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

    

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);
    release_fiber();

}