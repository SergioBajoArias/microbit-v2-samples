#include "StarWarsMelody.h"
#include "Sound.h"

// https://www.upadounlimited.com/uploads/8/0/9/8/8098405/star-wars-theme-music-patterns-2-nov-2019-with-4-watermarks-3-you-cannot-see_1_orig.jpg

void playBlock1(bool ending) {
    playSound(C, BEAT * 8);
    playSound(G, BEAT * 8);

    for(int i = 0; i < 2; i++) {
        playSound(F, BEAT * 2);
        playSound(E, BEAT * 2);
        playSound(D, BEAT * 2);
        playSound(C5, BEAT * 8);
        playSound(G, BEAT * 4);
    }

    if(ending) {
        playSound(C5, BEAT);
        playSound(C5, BEAT);
        playSound(B, BEAT);
        playSound(C5, BEAT * 3);
        playSound(C, BEAT * 2);
        playSound(C, BEAT * 2);
        fiber_sleep(BEAT * 2);
        playSound(C, BEAT * 2);
        playSound(C, BEAT * 2);
    } else {
        playSound(F, BEAT * 2);
        playSound(E, BEAT * 2);
        playSound(F, BEAT * 2);
        playSound(D, BEAT * 12);
    }
    
}

void playBlock2() {
    playSound(A, BEAT * 6);
    playSound(A, BEAT * 2);
    playSound(F, BEAT * 2);
    playSound(E, BEAT * 2);
    playSound(D, BEAT * 2);
    playSound(C, BEAT * 2);

    playSound(C, BEAT);
    playSound(D, BEAT);
    playSound(E, BEAT);
    playSound(D, BEAT * 2);
    playSound(A, BEAT * 2);
    playSound(B, BEAT * 4);
    playSound(G, BEAT * 2);
    playSound(G, BEAT * 2);

    playSound(A, BEAT * 6);
    playSound(A, BEAT * 2);
    playSound(F, BEAT * 2);
    playSound(E, BEAT * 2);
    playSound(D, BEAT * 2);
    playSound(C, BEAT * 2);

    playSound(G, BEAT * 4);
    playSound(D, BEAT * 8);
    playSound(G, BEAT * 4);
}

void playBlock3()
{
    playSound(A, BEAT * 6);
    playSound(A, BEAT * 2);
    playSound(F, BEAT * 2);
    playSound(E, BEAT * 2);
    playSound(D, BEAT * 2);
    playSound(C, BEAT * 2);

    playSound(C, BEAT);
    playSound(D, BEAT);
    playSound(E, BEAT);
    playSound(D, BEAT * 2);
    playSound(A, BEAT * 2);
    playSound(B, BEAT * 4);
    playSound(G, BEAT * 2);
    playSound(G, BEAT * 2);

    playSound(C5, BEAT * 4);
    playSound(G, BEAT * 4);
    playSound(F, BEAT * 4);
    playSound(D, BEAT * 2);
    playSound(C, BEAT * 2);

    playSound(G, BEAT * 16);
}

StarWarsMelody::StarWarsMelody(MelodyStatus status) : Melody(status) {
    
}

void StarWarsMelody::play() {
    while(1) {
        for(int i = 0; i < 2; i++) {
            playBlock1(false);
        }

        playBlock2();
        playBlock3();
        playBlock1(false);
        playBlock1(true);

        fiber_sleep(1000);
    }
}


