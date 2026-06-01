#include "Melody.h"
#include "Sound.h"
#include "common/Logger.h"

Melody::Melody(MelodyStatus status) {
    this->status = status;
    play();
}

int Melody::getCurrentVolume() {
    if(this->status == PLAYING) {
        return VOLUME_ON;
    } else {
        return VOLUME_OFF;
    }
}

void Melody::play() {
    
}

void Melody::toggleStatus() {
    if(status == PLAYING) {
        log("Stopping melody");
        this->status = STOPPED;
    } else if (status == STOPPED) {
        log("Resuming melody");
        this->status = PLAYING;
    }
}