#ifndef MELODY_H
#define MELODY_H

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