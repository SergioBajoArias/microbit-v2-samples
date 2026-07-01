#include "GPIO.h"
#include "Random.h"

using namespace std;

const int MAX_SCORE = 10;

const char * const HEART_EMOJI ="\
    000,255,000,255,000\n\
    255,255,255,255,255\n\
    255,255,255,255,255\n\
    000,255,255,255,000\n\
    000,000,255,000,000\n";

const char * const LEFT_ARROW_EMOJI ="\
    000,000,255,000,000\n\
    000,255,000,000,000\n\
    255,255,255,255,255\n\
    000,255,000,000,000\n\
    000,000,255,000,000\n";

const char * const RIGHT_ARROW_EMOJI ="\
    000,000,255,000,000\n\
    000,000,000,255,000\n\
    255,255,255,255,255\n\
    000,000,000,255,000\n\
    000,000,255,000,000\n";

const MicroBitImage HEART_IMAGE(HEART_EMOJI);
const MicroBitImage LEFT_ARROW_IMAGE(LEFT_ARROW_EMOJI);
const MicroBitImage RIGHT_ARROW_IMAGE(RIGHT_ARROW_EMOJI);

void check_answer(int& score, bool requesting, MicroBitImage arrow, bool& pressed) {
    if(requesting) {
        score++;
        uBit.audio.soundExpressions.play("sprint");
    } else {
        score--;
        uBit.audio.soundExpressions.play("sad");
    }
    uBit.display.print(arrow);
    pressed = true;
}

void wait_random() {
    int sleepingTime = getRandom(2000, 10000);

    fiber_sleep(sleepingTime);

    release_fiber();
}

void gpio_test() { 
    uBit.init();
    uBit.display.scrollAsync("REACTION GAME");
    int score1 = 0;
    int score2 = 0;
    bool requesting = false;

    while(score1 < MAX_SCORE && score2 < MAX_SCORE) {
        bool pressed = false;

        create_fiber(wait_random);

        while(pressed) {
            if(uBit.io.P1.isTouched()) {
                check_answer(score1, requesting, LEFT_ARROW_IMAGE, pressed);
            }
            if(uBit.io.P2.isTouched()) {
                check_answer(score2, requesting, RIGHT_ARROW_IMAGE, pressed);
            }
        }
    }

    release_fiber();
}