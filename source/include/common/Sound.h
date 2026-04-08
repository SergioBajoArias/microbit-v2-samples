#ifndef SOUND_H
#define SOUND_H

#include "MicroBit.h"

extern MicroBit uBit;

enum Note {
    DO = 262,
    RE = 294,
    MI = 330,
    FA = 349,
    SOL = 392,
    LA = 440,
    SI = 494
};

void playSound(int frequency);

#endif // SOUND_H