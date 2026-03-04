#include "Simon.h"
#include "MicroBit.h"
#include "stdlib.h"
#include "iostream"

enum SeqItems {
    A,
    B,
    AB,
    NUMBER_OF_ITEMS
};

SeqItems generateRandom() {
    int randomPosition = std::rand() % NUMBER_OF_ITEMS;
    return static_cast<SeqItems>(randomPosition);
}

void play_simon() { 
  // uBit.init(); 
  
    // std::cout << generateRandom();

  // release_fiber();
} 