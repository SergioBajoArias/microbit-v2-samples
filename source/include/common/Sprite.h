#ifndef SPRITE_H
#define SPRITE_H

const int TOP_LIMIT = 4;
const int BOTTOM_LIMIT = 0;
const int RIGHT_LIMIT = 4;
const int LEFT_LIMIT = 0;

class Sprite {
    private:
        int x = -1;
        int y = -1;
    protected:
        void setX(int newX);
        void setY(int newY);
    public:
        int getX();
        int getY();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};

#endif // SPRITE_H