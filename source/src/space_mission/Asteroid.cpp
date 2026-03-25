#include "space_mission/Asteroid.h"
#include "Logger.h"
#include <random>

Asteroid::Asteroid() : Sprite() {
    setX(std::rand() % RIGHT_LIMIT + 1);
    setY(TOP_LIMIT);
    log("Created asteroid");
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