#include "Tests.h"

MicroBit uBit;

int main()
{
    uBit.init();

    // hello_world();
    // simon();
    // space_mission();
    gpio_test();

    microbit_panic( 999 );
}

