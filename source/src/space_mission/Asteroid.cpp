#include "space_mission/Asteroid.h"
#include "Logger.h"
#include "Random.h"

Asteroid::Asteroid() : Sprite() {
    setX(getRandom(0, RIGHT_LIMIT));
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