
#include "MicroBit.h"
#include "samples/Tests.h"

MicroBit uBit;

int main()
{
    uBit.init();

    // out_of_box_experience();
    // hello_world();
    simon();

    microbit_panic( 999 );
}

