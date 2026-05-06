#include "StarWarsMelody.h"
#include "Sound.h"

// https://www.upadounlimited.com/uploads/8/0/9/8/8098405/star-wars-theme-music-patterns-2-nov-2019-with-4-watermarks-3-you-cannot-see_1_orig.jpg

void playBlock1(int currentVolume, bool ending) {
    playSound(C, BEAT * 8, currentVolume);
    playSound(G, BEAT * 8, currentVolume);

    for(int i = 0; i < 2; i++) {
        playSound(F, BEAT * 2, currentVolume);
        playSound(E, BEAT * 2, currentVolume);
        playSound(D, BEAT * 2, currentVolume);
        playSound(C5, BEAT * 8, currentVolume);
        playSound(G, BEAT * 4, currentVolume);
    }

    if(ending) {
        playSound(C5, BEAT, currentVolume);
        playSound(C5, BEAT, currentVolume);
        playSound(B, BEAT, currentVolume);
        playSound(C5, BEAT * 3, currentVolume);
        playSound(C, BEAT * 2, currentVolume);
        playSound(C, BEAT * 2, currentVolume);
        fiber_sleep(BEAT * 2);
        playSound(C, BEAT * 2, currentVolume);
        playSound(C, BEAT * 2, currentVolume);
    } else {
        playSound(F, BEAT * 2, currentVolume);
        playSound(E, BEAT * 2, currentVolume);
        playSound(F, BEAT * 2, currentVolume);
        playSound(D, BEAT * 12, currentVolume);
    }
    
}

void playBlock2(int currentVolume) {
    playSound(A, BEAT * 6, currentVolume);
    playSound(A, BEAT * 2, currentVolume);
    playSound(F, BEAT * 2, currentVolume);
    playSound(E, BEAT * 2, currentVolume);
    playSound(D, BEAT * 2, currentVolume);
    playSound(C, BEAT * 2, currentVolume);

    playSound(C, BEAT, currentVolume);
    playSound(D, BEAT, currentVolume);
    playSound(E, BEAT, currentVolume);
    playSound(D, BEAT * 2, currentVolume);
    playSound(A, BEAT * 2, currentVolume);
    playSound(B, BEAT * 4, currentVolume);
    playSound(G, BEAT * 2, currentVolume);
    playSound(G, BEAT * 2, currentVolume);

    playSound(A, BEAT * 6, currentVolume);
    playSound(A, BEAT * 2, currentVolume);
    playSound(F, BEAT * 2, currentVolume);
    playSound(E, BEAT * 2, currentVolume);
    playSound(D, BEAT * 2, currentVolume);
    playSound(C, BEAT * 2, currentVolume);

    playSound(G, BEAT * 4, currentVolume);
    playSound(D, BEAT * 8, currentVolume);
    playSound(G, BEAT * 4, currentVolume);
}

void playBlock3(int currentVolume)
{
    playSound(A, BEAT * 6, currentVolume);
    playSound(A, BEAT * 2, currentVolume);
    playSound(F, BEAT * 2, currentVolume);
    playSound(E, BEAT * 2, currentVolume);
    playSound(D, BEAT * 2, currentVolume);
    playSound(C, BEAT * 2, currentVolume);

    playSound(C, BEAT, currentVolume);
    playSound(D, BEAT, currentVolume);
    playSound(E, BEAT, currentVolume);
    playSound(D, BEAT * 2, currentVolume);
    playSound(A, BEAT * 2, currentVolume);
    playSound(B, BEAT * 4, currentVolume);
    playSound(G, BEAT * 2, currentVolume);
    playSound(G, BEAT * 2, currentVolume);

    playSound(C5, BEAT * 4, currentVolume);
    playSound(G, BEAT * 4, currentVolume);
    playSound(F, BEAT * 4, currentVolume);
    playSound(D, BEAT * 2, currentVolume);
    playSound(C, BEAT * 2, currentVolume);

    playSound(G, BEAT * 16, currentVolume);
}

StarWarsMelody::StarWarsMelody(MelodyStatus status) : Melody(status) {
    
}

void StarWarsMelody::play() {
    while(1) {
        for(int i = 0; i < 2; i++) {
            playBlock1(getCurrentVolume(), false);
        }

        playBlock2(getCurrentVolume());
        playBlock3(getCurrentVolume());
        playBlock1(getCurrentVolume(), false);
        playBlock1(getCurrentVolume(), true);

        fiber_sleep(1000);
    }
}


