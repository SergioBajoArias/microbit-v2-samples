#include "Sprite.h"

#ifndef ASTEROID_H
#define ASTEROID_H

class Asteroid : public Sprite {
    public:
        Asteroid();
        void moveUp();
        void moveLeft();
        void moveRight();
};

#endif // ASTEROID_H