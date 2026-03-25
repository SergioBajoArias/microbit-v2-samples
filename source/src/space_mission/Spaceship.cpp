#include "space_mission/Spaceship.h"
#include "Logger.h"

Spaceship::Spaceship() : Sprite() {
    setX(2);
    setY(BOTTOM_LIMIT);
    log("Created spaceship");
}

void Spaceship::moveUp() {
    // Do nothing
}

void Spaceship::moveDown() {
    // Do nothing
}