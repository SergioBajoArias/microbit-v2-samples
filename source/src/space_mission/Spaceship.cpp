#include "space_mission/Spaceship.h"
#include "Logger.h"

Spaceship::Spaceship() : Sprite() {
    setX(2);
    setY(BOTTOM_LIMIT);
    log("Created spaceship with id " + std::to_string(getId()) + " at position [" + std::to_string(getX()) + "," + std::to_string(getY()) + "]");
}

void Spaceship::moveUp() {
    // Do nothing
}

void Spaceship::moveDown() {
    // Do nothing
}