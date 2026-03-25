#include "Sprite.h"

void Sprite::setX(int newX) {
    x = newX;
}

void Sprite::setY(int newY) {
    y = newY;
}

void Sprite::moveDown() {
    if(y > BOTTOM_LIMIT) {
        setY(y - 1);
    }
}

void Sprite::moveUp() {
    if(y < TOP_LIMIT) {
        setY(y + 1);
    }
}

void Sprite::moveLeft() {
    if(x > LEFT_LIMIT) {
        setX(x - 1);
    }
}

void Sprite::moveRight() {
    if(x < RIGHT_LIMIT) {
        setX(x + 1);
    }
}