#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include "MicroBit.h"

extern MicroBit uBit;

void log(std::string message);
void log(std::string message, bool addNewLine);

#endif // LOGGER_H