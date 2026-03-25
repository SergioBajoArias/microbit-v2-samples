#ifndef SPRITE_H
#define SPRITE_H

const int TOP_LIMIT = 4;
const int BOTTOM_LIMIT = 0;
const int RIGHT_LIMIT = 4;
const int LEFT_LIMIT = 0;

class Sprite {
    private:
        long id;
        int x = -1;
        int y = -1;
    protected:
        void setX(int newX);
        void setY(int newY);
    public:
        bool operator == (const Sprite& s) const { return id == s.id; }
        bool operator != (const Sprite& s) const { return !operator==(s); }
        Sprite();
        int getX();
        int getY();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        bool isBottomLimit();
        bool isTopLimit();
        bool isRightLimit();
        bool isLeftLimit();
        bool hasCollided(const Sprite& s);
};

#endif // SPRITE_H