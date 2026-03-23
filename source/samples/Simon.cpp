
#include "Simon.h"
#include "MicroBit.h"
#include <cstdlib>
#include <iostream>
#include <list>
#include <unistd.h>
#include <string>
#include <random>

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

enum Note {
    DO = 262,
    RE = 294,
    MI = 330,
    FA = 349,
    SOL = 392,
    LA = 440,
    SI = 494
};

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
const int BEAT = 500;
int score = 0;
int currentLevel = START_LEVEL;
Turns currentTurn = SIMON;
std::list<SeqItems> randomSequence;
std::list<SeqItems> userSequence;

std::random_device rd;  // a seed source for the random number engine
std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<int> distrib(0, NUMBER_OF_ITEMS - 1);

static Pin *pin = &uBit.audio.virtualOutputPin;
static uint8_t pitchVolume = 0xff;

static void analogPitch(int frequency) {
    if (frequency <= 0 || pitchVolume == 0) {
        pin->setAnalogValue(0);
    } else {
        // I don't understand the logic of this value.
        // It is much louder on the real pin.
        int v = 1 << (pitchVolume >> 5);
        // If you flip the order of these they crash on the real pin with E030.
        pin->setAnalogValue(v);
        pin->setAnalogPeriodUs(1000000/frequency);
    }
    if (BEAT > 0) {
        fiber_sleep(BEAT);
        pin->setAnalogValue(0);
        fiber_sleep(5);
    }
}

static void log(string message) {
  uBit.serial.send(message.c_str());
}

static void print(Note note, MicroBitImage image) {
  uBit.display.printAsync(image);
  analogPitch(note);
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
    int randomPosition = distrib(gen);
    return static_cast<SeqItems>(randomPosition);
}

static std::list<SeqItems> generateRandomSequence() {
  log("Creating random sequence\n");
  std::list<SeqItems> sequence;
  for(int i = 0; i < currentLevel; i++) {
    sequence.push_back(generateRandom());
  }
  log("Random sequence is ");
  for(SeqItems seqItem : sequence) {
    log(std::to_string(seqItem));
  }
  log("\n");
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
  log("Button A\n");
  if(currentTurn == PLAYER) {
    userSequence.push_back(A);
    printA();
  } else if (currentTurn == LEVEL_SELECTION) {
    currentLevel++;
    printCurrentLevel();
  }
}

static void onButtonB(MicroBitEvent) {
  log("Button B\n");
  if(currentTurn == PLAYER) {
    userSequence.push_back(B);
    printB();
  } else if (currentTurn == LEVEL_SELECTION) {
    currentLevel--;
    printCurrentLevel();
  }
}

static void onButtonAB(MicroBitEvent) {
  log("Button AB\n");
  if(currentTurn == PLAYER) {
    userSequence.push_back(AB);
    printAB();
  }
}

static void verifyAnswer() {
  log("Checking user's answer\n");
  if(randomSequence == userSequence) {
    log("Answer is correct\n");
    print("spring", tick_Image);
    score++;
  } else {
    log("Answer is wrong\n");
    print("sad", cross_Image);
    printGameOver();
    release_fiber();
  }
    
  if(score % LEVEL_SIZE == 0) {
    currentLevel++;
  }
}

static void makeSimonTurn() {
  log("Making Simon's turn\n");
  currentTurn = SIMON;
  randomSequence = generateRandomSequence();
  printSequence(randomSequence);
  uBit.display.print(smile_Image);
  userSequence.clear();
  currentTurn = PLAYER;
}

static void onButtonLogo(MicroBitEvent) {
  log("Button Logo\n");
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
  uBit.messageBus.listen(MICROBIT_ID_LOGO, MICROBIT_BUTTON_EVT_DOUBLE_CLICK, onButtonLogo);

  while(true) {
    uBit.sleep(1000);
  }

  release_fiber();
} 