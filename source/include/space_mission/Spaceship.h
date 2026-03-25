#include "Sprite.h"

#ifndef SPACESHIP_H
#define SPACESHIP_H

class Spaceship : public Sprite {
    public:
        Spaceship();
        void moveUp();
        void moveDown();
};

#endif // SPACESHIP_H