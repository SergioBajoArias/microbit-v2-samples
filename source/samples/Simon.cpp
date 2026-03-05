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

enum Turns {
  PLAYER,
  SIMON
};

enum SeqItems {
    A,
    B,
    AB,
    NUMBER_OF_ITEMS
};

const int START_LEVEL = 4;
const int LEVEL_SIZE = 3;
int score = 0;
int currentLevel = START_LEVEL;
bool gameOver = false;
Turns currentTurn = SIMON;
std::list<SeqItems> randomSequence;
std::list<SeqItems> userSequence;

void printA() {
  uBit.display.print(a_Image);
}

void printB() {
  uBit.display.print(b_Image);
}

void printAB() {
  uBit.display.print(ab_Image);
}

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
      case A:   printA();
                break;
      case B:   printB();
                break;
      case AB:  printAB();
                break;
      default:  ;
    }
    uBit.sleep(1000);
    uBit.display.clear();
  }
}

void printGameOver() {
  uBit.display.print("GAME OVER. SCORE " + score);
}

void onButtonA(MicroBitEvent) {
  if(currentTurn == PLAYER) {
    userSequence.push_back(A);
    printA();
  }
}

void onButtonB(MicroBitEvent) {
  if(currentTurn == PLAYER) {
    userSequence.push_back(B);
    printB();
  }
}

void onButtonAB(MicroBitEvent) {
  if(currentTurn == PLAYER) {
    userSequence.push_back(AB);
    printAB();
  }
}

void verifyAnswer() {
  if(randomSequence == userSequence) {
    uBit.display.print(tick_Image);
    score++;
  } else {
    uBit.display.print(cross_Image);
    gameOver = true;
    printGameOver();
  }
    
  if(score % LEVEL_SIZE == 0) {
    currentLevel++;
  }
}

void makeSimonTurn() {
  currentTurn = SIMON;
  randomSequence = generateRandomSequence();
  printSequence(randomSequence);
  currentTurn = PLAYER;
}

void onButtonLogo(MicroBitEvent) {
  if(currentTurn == PLAYER) {
    verifyAnswer();
  }
  
  makeSimonTurn();
}

std::list<SeqItems> getUserSequence() {
  std::list<SeqItems> userSequence;
  return userSequence;
}

void simon() { 
  uBit.init(); 
  std::srand(std::time({}));
  uBit.display.printAsync("SIMON");

  uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
  uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);
  uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_CLICK, onButtonAB);
  uBit.messageBus.listen(MICROBIT_ID_LOGO, MICROBIT_BUTTON_EVT_DOWN, onButtonLogo);   

  while(!gameOver) {

  }
  release_fiber();
} 