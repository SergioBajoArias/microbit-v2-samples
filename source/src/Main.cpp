#include "Tests.h"

MicroBit uBit;

int main()
{
    uBit.init();

    // out_of_box_experience();
    // hello_world();
    simon();
    // space_mission();

    microbit_panic( 999 );
}

