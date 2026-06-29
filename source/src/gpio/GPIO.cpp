#include "GPIO.h"
#include "Image.h"

using namespace std;

void gpio_test() { 
    while(1) {
        if(uBit.io.P1.isTouched()) {
            uBit.display.print(HEART_IMAGE);
            uBit.audio.soundExpressions.play("sprint");
        }
    }
        
}