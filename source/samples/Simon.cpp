#include "Simon.h"
#include "MicroBit.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <list>
#include <unistd.h>
#include <string>

using namespace std;

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