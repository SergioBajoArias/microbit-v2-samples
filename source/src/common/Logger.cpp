#include "common/Logger.h"

void log(std::string message) {
  log(message, true);
}

void log(std::string message, bool addNewLine) {
  uBit.serial.send(message.c_str());
  if(addNewLine) {
    uBit.serial.send("\n");
  } 
}