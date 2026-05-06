#ifndef STARWARSMELODY_H
#define STARWARSMELODY_H

#include "Melody.h"

class StarWarsMelody : public Melody {
    public:
        StarWarsMelody(MelodyStatus status);
        void play();
};

#endif // STARWARSMELODY_H