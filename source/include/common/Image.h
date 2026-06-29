#ifndef IMAGE_H
#define IMAGE_H

#include <MicroBit.h>

const char * const SMILE_EMOJI ="\
    000,000,000,000,000\n\
    000,255,000,255,000\n\
    000,000,000,000,000\n\
    000,255,000,255,000\n\
    000,000,255,000,000\n";

const char * const A_EMOJI ="\
    000,000,000,000,000\n\
    255,000,000,000,000\n\
    255,000,000,000,000\n\
    255,000,000,000,000\n\
    000,000,000,000,000\n";

const char * const B_EMOJI ="\
    000,000,000,000,000\n\
    000,000,000,000,255\n\
    000,000,000,000,255\n\
    000,000,000,000,255\n\
    000,000,000,000,000\n";

const char * const AB_EMOJI ="\
    000,000,000,000,000\n\
    255,000,000,000,255\n\
    255,000,000,000,255\n\
    255,000,000,000,255\n\
    000,000,000,000,000\n";

const char * const TICK_EMOJI ="\
    000,000,000,000,000\n\
    000,000,000,000,255\n\
    000,000,000,255,000\n\
    255,000,255,000,000\n\
    000,255,000,000,000\n";

const char * const CROSS_EMOJI ="\
    255,000,000,000,255\n\
    000,255,000,255,000\n\
    000,000,255,000,000\n\
    000,255,000,255,000\n\
    255,000,000,000,255\n";

const char * const HEART_EMOJI ="\
    000,255,000,255,000\n\
    255,255,255,255,255\n\
    255,255,255,255,255\n\
    000,255,255,255,000\n\
    000,000,255,000,000\n";

const MicroBitImage HEART_IMAGE(HEART_EMOJI);
const MicroBitImage A_IMAGE(A_EMOJI);
const MicroBitImage B_IMAGE(B_EMOJI);
const MicroBitImage AB_IMAGE(AB_EMOJI);
const MicroBitImage TICK_IMAGE(TICK_EMOJI);
const MicroBitImage CROSS_IMAGE(CROSS_EMOJI);
const MicroBitImage SMILE_IMAGE(SMILE_EMOJI);

#endif // IMAGE_H