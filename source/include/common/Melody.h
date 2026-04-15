#ifndef MELODY_H
#define MELODY_H

#include <MicroBit.h>

enum MelodyStatus {
    PLAYING,
    STOPPED
};

class Melody {
    protected:
        MelodyStatus status;
    public:
        Melody(MelodyStatus status);
        void play();
        MelodyStatus getStatus();
        void toggleStatus();
};

#endif // MELODY_H