#include "StarWarsMelody.h"
#include "Sound.h"

// https://www.upadounlimited.com/uploads/8/0/9/8/8098405/star-wars-theme-music-patterns-2-nov-2019-with-4-watermarks-3-you-cannot-see_1_orig.jpg

void playStarWarsMelody() {
    while(1) {
        for(int i = 0; i < 2; i++) {
            playSound(C, BEAT * 8);
            playSound(G, BEAT * 8);

            for(int i = 0; i < 2; i++) {
                playSound(F, BEAT * 2);
                playSound(E, BEAT * 2);
                playSound(D, BEAT * 2);
                playSound(C5, BEAT * 8);
                playSound(G, BEAT * 4);
            }

            playSound(F, BEAT * 2);
            playSound(E, BEAT * 2);
            playSound(F, BEAT * 2);
            playSound(D, BEAT * 12);
        }
    }
}