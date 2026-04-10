#include "Sound.h"

Pin *pin = &uBit.audio.virtualOutputPin;
// Pin *pin = &uBit.io.P0;
uint8_t pitchVolume = 0xcc;

void playSound(int frequency) {
    playSound(frequency, BEAT);
}

void playSound(int frequency, int beat) {
    if (frequency <= 0 || pitchVolume == 0) {
        pin->setAnalogValue(0);
    } else {
        // I don't understand the logic of this value.
        // It is much louder on the real pin.
        int v = 1 << (pitchVolume >> 5);
        // If you flip the order of these they crash on the real pin with E030.
        pin->setAnalogValue(v);
        pin->setAnalogPeriodUs(1000000/frequency);
    }
    if (BEAT > 0) {
        fiber_sleep(beat);
        pin->setAnalogValue(0);
        fiber_sleep(5);
    }
}