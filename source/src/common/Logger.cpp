#include "Logger.h"

void log(std::string message) {
  uBit.serial.send(message.c_str());
  uBit.serial.send("\n");

}