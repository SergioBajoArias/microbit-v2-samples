#ifndef MELODY_H
#define MELODY_H

#include <MicroBit.h>

enum MelodyStatus {
    PLAYING,
    STOPPED
};

class Melody {
    private:
        MelodyStatus status;
    public:
        Melody(MelodyStatus status);
        void play();
        int getCurrentVolume();
        void toggleStatus();
};

#endif // MELODY_H