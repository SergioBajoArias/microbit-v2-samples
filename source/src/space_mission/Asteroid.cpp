#include "space_mission/Asteroid.h"
#include "Logger.h"
#include <random>

Asteroid::Asteroid() : Sprite() {
    setX(std::rand() % (RIGHT_LIMIT + 1));
    setY(TOP_LIMIT);
    log("Created asteroid with id " + std::to_string(getId()) + " at position [" + std::to_string(getX()) + "," + std::to_string(getY()) + "]");
}

void Asteroid::moveUp() {
    // Do nothing
}

void Asteroid::moveLeft() {
    // Do nothing
}

void Asteroid::moveRight() {
    // Do nothing
}