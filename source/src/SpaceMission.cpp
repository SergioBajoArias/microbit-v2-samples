#include "SpaceMission.h"
#include "Logger.h"
#include <random>
#include <string>
#include <list>

const int TOP_LIMIT = 4;
const int BOTTOM_LIMIT = 0;
const int RIGHT_LIMIT = 4;
const int LEFT_LIMIT = 0;

void hideSprite(int x, int y) {
    uBit.display.image.setPixelValue(x, y, 0);
}

void showSprite(int x, int y) {
    uBit.display.image.setPixelValue(x, y, 255);
}

class Sprite {
    private:
        int x = -1;
        int y = -1;

    public:
        void setX(int newX) {
            hideSprite(x,y);
            x = newX;
            showSprite(x,y);
        }

        void setY(int newY) {
            hideSprite(x,y);
            y = newY;
            showSprite(x,y);
        }

        void moveUp() {
            if(y < TOP_LIMIT) {
                setY(y + 1);
            }
        }

        void moveDown() {
            if(y > BOTTOM_LIMIT) {
                setY(y - 1);
            }
        }

        void moveLeft() {
            if(x > LEFT_LIMIT) {
                setX(x - 1);
            }
        }

        void moveRight() {
            if(x < RIGHT_LIMIT) {
                setX(x + 1);
            }
        }
};

class Spaceship : public Sprite {
    public:
        Spaceship() {
            setX(2);
            setY(BOTTOM_LIMIT);
        }
};

class Asteroid : public Sprite {
    public:
        Asteroid() {
            setX(std::rand() % RIGHT_LIMIT + 1);
            setY(TOP_LIMIT);
        }
};

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