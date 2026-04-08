#include "StarWarsMelody.h"
#include "Sound.h"

// https://www.upadounlimited.com/uploads/8/0/9/8/8098405/star-wars-theme-music-patterns-2-nov-2019-with-4-watermarks-3-you-cannot-see_1_orig.jpg

void playStarWarsMelody() {
    playSound(C, BEAT * 4);
    playSound(G, BEAT * 4);
}