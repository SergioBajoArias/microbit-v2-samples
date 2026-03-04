#include "Simon.h"
#include "MicroBit.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>
#include <unistd.h>
#include <string>

using namespace std;

const char * const a_emoji ="\
    255,000,000,000,000\n\
    255,000,000,000,000\n\
    255,000,000,000,000\n\
    255,000,000,000,000\n\
    255,000,000,000,000\n";

const char * const b_emoji ="\
    000,000,000,000,255\n\
    000,000,000,000,255\n\
    000,000,000,000,255\n\
    000,000,000,000,255\n\
    000,000,000,000,255\n";

const char * const ab_emoji ="\
    255,000,000,000,255\n\
    255,000,000,000,255\n\
    255,000,000,000,255\n\
    255,000,000,000,255\n\
    255,000,000,000,255\n";

const char * const tick_emoji ="\
    000,000,000,000,000\n\
    000,000,000,000,255\n\
    000,000,000,255,000\n\
    255,000,255,000,000\n\
    000,255,000,000,000\n";

const char * const cross_emoji ="\
    255,000,000,000,255\n\
    000,255,000,255,000\n\
    000,000,255,000,000\n\
    000,255,000,255,000\n\
    255,000,000,000,255\n";

MicroBitImage a_Image(a_emoji);
MicroBitImage b_Image(b_emoji);
MicroBitImage ab_Image(ab_emoji);
MicroBitImage tick_Image(tick_emoji);
MicroBitImage cross_Image(cross_emoji);

const int START_LEVEL = 4;
const int LEVEL_SIZE = 3;
int currentLevel = START_LEVEL;

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

std::list<SeqItems> generateRandomSequence() {
  std::list<SeqItems> sequence;
  for(int i = 0; i < currentLevel; i++) {
    sequence.push_back(generateRandom());
  }
  return sequence;
}

void printSequence(std::list<SeqItems>& sequence) {
  for(SeqItems seqItem : sequence) {
    switch(seqItem) {
      case A:   uBit.display.print(a_Image);
                break;
      case B:   uBit.display.print(b_Image);
                break;
      case AB:  uBit.display.print(ab_Image);
                break;
      default:  ;
    }
    uBit.sleep(1000);
    uBit.display.clear();
  }
}

void printGameOver(int score) {
  
}

std::list<SeqItems> getUserSequence() {
  std::list<SeqItems> userSequence;
  return userSequence;
}

void play_simon() {
  int score = 0;
  bool gameOver = false;

  while(!gameOver) {
    std::list<SeqItems> randomSequence = generateRandomSequence();
    printSequence(randomSequence);
    std::list<SeqItems> userSequence = getUserSequence();
    
    if(randomSequence == userSequence) {
      score++;
    } else {
      gameOver = true;
    }
    
    if(score % LEVEL_SIZE == 0) {
      currentLevel++;
    }
  }
  printGameOver(score);
}

void simon() { 
  uBit.init(); 
  std::srand(std::time({}));
  play_simon();
  release_fiber();
} 