
#include "Simon.h"
#include "MicroBit.h"
#include "Logger.h"
#include "Random.h"
#include "Sound.h"
#include <cstdlib>
#include <iostream>
#include <list>
#include <unistd.h>
#include <string>

using namespace std;

const char * const smile_emoji ="\
    000,000,000,000,000\n\
    000,255,000,255,000\n\
    000,000,000,000,000\n\
    000,255,000,255,000\n\
    000,000,255,000,000\n";

const char * const a_emoji ="\
    000,000,000,000,000\n\
    255,000,000,000,000\n\
    255,000,000,000,000\n\
    255,000,000,000,000\n\
    000,000,000,000,000\n";

const char * const b_emoji ="\
    000,000,000,000,000\n\
    000,000,000,000,255\n\
    000,000,000,000,255\n\
    000,000,000,000,255\n\
    000,000,000,000,000\n";

const char * const ab_emoji ="\
    000,000,000,000,000\n\
    255,000,000,000,255\n\
    255,000,000,000,255\n\
    255,000,000,000,255\n\
    000,000,000,000,000\n";

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
MicroBitImage smile_Image(smile_emoji);

enum Turns {
  PLAYER,
  SIMON,
  LEVEL_SELECTION
};

enum SeqItems {
    A,
    B,
    AB,
    NUMBER_OF_ITEMS
};

const int START_LEVEL = 3;
const int LEVEL_SIZE = 2;
const int MIN_LEVEL = START_LEVEL;
const int MAX_LEVEL = 9;
int score = 0;
int currentLevel = START_LEVEL;
Turns currentTurn = LEVEL_SELECTION;
std::list<SeqItems> randomSequence;
std::list<SeqItems> userSequence;

static void print(Note note, MicroBitImage image) {
  uBit.display.printAsync(image);
  playSound(note);
}

static void print(ManagedString sound, MicroBitImage image) {
  uBit.display.print(image);
  uBit.audio.soundExpressions.play(sound);
}

static void printA() {
  print(DO, a_Image);
}

static void printB() {
  print(FA, b_Image);
}

static void printAB() {
  print(SI, ab_Image);
}

static SeqItems generateRandom() {
    int randomPosition = getRandom(0, NUMBER_OF_ITEMS);
    return static_cast<SeqItems>(randomPosition);
}

static std::list<SeqItems> generateRandomSequence() {
  log("Creating random sequence");
  std::list<SeqItems> sequence;
  for(int i = 0; i < currentLevel; i++) {
    sequence.push_back(generateRandom());
  }
  log("Random sequence is ");
  for(SeqItems seqItem : sequence) {
    log(std::to_string(seqItem), false);
  }
  return sequence;
}

static void printSequence(std::list<SeqItems>& sequence) {
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

static void printGameOver() {
  ManagedString gameOver = "GAME OVER. SCORE ";
  ManagedString scoreMs = ManagedString(score);

  uBit.display.clear();
  uBit.display.scroll(gameOver + scoreMs);
}

static void printCurrentLevel() {
  uBit.display.print(currentLevel);
}

static void onButtonA(MicroBitEvent) {
  log("Button A");
  if(currentTurn == PLAYER) {
    userSequence.push_back(A);
    printA();
  } else if (currentTurn == LEVEL_SELECTION && currentLevel >= MIN_LEVEL) {
    currentLevel--;
    printCurrentLevel();
  }
}

static void onButtonB(MicroBitEvent) {
  log("Button B");
  if(currentTurn == PLAYER) {
    userSequence.push_back(B);
    printB();
  } else if (currentTurn == LEVEL_SELECTION && currentLevel <= MAX_LEVEL) {
    currentLevel++;
    printCurrentLevel();
  }
}

static void onButtonAB(MicroBitEvent) {
  log("Button AB");
  if(currentTurn == PLAYER) {
    userSequence.push_back(AB);
    printAB();
  }
}

static void verifyAnswer() {
  log("Checking user's answer");
  if(randomSequence == userSequence) {
    log("Answer is correct");
    print("spring", tick_Image);
    score++;
  } else {
    log("Answer is wrong");
    print("sad", cross_Image);
    printGameOver();
    release_fiber();
  }
    
  if(score % LEVEL_SIZE == 0) {
    currentLevel++;
  }
}

static void makeSimonTurn() {
  log("Making Simon's turn");
  currentTurn = SIMON;
  randomSequence = generateRandomSequence();
  printSequence(randomSequence);
  uBit.display.print(smile_Image);
  userSequence.clear();
  currentTurn = PLAYER;
}

static void onButtonLogo(MicroBitEvent) {
  log("Button Logo");
  if(currentTurn == PLAYER) {
    verifyAnswer();
  }
  
  makeSimonTurn();
}

void simon() { 
  uBit.init();   
  uBit.display.scrollAsync("SIMON");
  printCurrentLevel();

  uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
  uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);
  uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_CLICK, onButtonAB);
  uBit.messageBus.listen(MICROBIT_ID_LOGO, MICROBIT_BUTTON_EVT_LONG_CLICK, onButtonLogo);

  while(true) {
    uBit.sleep(1000);
  }

  release_fiber();
} 