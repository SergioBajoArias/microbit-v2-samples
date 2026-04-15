#include "Melody.h"

Melody::Melody(MelodyStatus status) {
    this->status = status;
}

void Melody::play() {
    
}

MelodyStatus Melody::getStatus() {
    return status;
}

void Melody::toggleStatus() {
    if(status == PLAYING) {
        status = STOPPED;
    } else if (status == STOPPED) {
        status = PLAYING;
    }
}