#include "Melody.h"
#include "Sound.h"
#include "common/Logger.h"

Melody::Melody(MelodyStatus status) {
    this->status = status;
    if(status == PLAYING) {
        currentVolume = VOLUME_ON;
    } else {
        currentVolume = VOLUME_OFF;
    }
    create_fiber(play);
}

MelodyStatus Melody::getStatus() {
    return status;
}

void Melody::toggleStatus() {
    if(status == PLAYING) {
        log("Stopping melody");
        status = STOPPED;
        currentVolume = VOLUME_OFF;
    } else if (status == STOPPED) {
        log("Resuming melody");
        status = PLAYING;
        currentVolume = VOLUME_ON;
    }
}