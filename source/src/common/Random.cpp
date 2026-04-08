#include "common/Random.h"
#include <random>

std::random_device rd;  // a seed source for the random number engine
std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()

int getRandom(int minRange, int maxRange) {
    std::uniform_int_distribution<int> distrib(minRange, maxRange);
    return distrib(gen);
}