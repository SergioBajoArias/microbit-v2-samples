#include "space_mission/Asteroid.h"
#include <random>

Asteroid::Asteroid() {
    setX(std::rand() % RIGHT_LIMIT + 1);
    setY(TOP_LIMIT);
}