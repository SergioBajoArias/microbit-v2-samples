#include "Sprite.h"
#include <random>

Sprite::Sprite() {
    id = std::rand();
}

void Sprite::setX(int newX) {
    x = newX;
}

void Sprite::setY(int newY) {
    y = newY;
}

int Sprite::getX() {
    return x;
}

int Sprite::getY() {
    return y;
}

void Sprite::moveDown() {
    if(!isBottomLimit()) {
        setY(y - 1);
    }
}

void Sprite::moveUp() {
    if(!isTopLimit()) {
        setY(y + 1);
    }
}

void Sprite::moveLeft() {
    if(!isLeftLimit()) {
        setX(x - 1);
    }
}

void Sprite::moveRight() {
    if(!isRightLimit()) {
        setX(x + 1);
    }
}

bool Sprite::isBottomLimit() {
    return y == BOTTOM_LIMIT;
}

bool Sprite::isTopLimit() {
    return y == TOP_LIMIT;
}

bool Sprite::isRightLimit() {
    return x == RIGHT_LIMIT;
}

bool Sprite::isLeftLimit() {
    return x == LEFT_LIMIT;
}

bool Sprite::hasCollided(const Sprite& s) {
    return x == s.x && y == s.y;
}