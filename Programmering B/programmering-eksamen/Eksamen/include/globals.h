#ifndef GLOBALS_H
#define GLOBALS_H
#include <iostream>
#include <vector>
#include <string>
#include <atomic>
#include <math.h>
#include <ctime>
#include "stdlib.h"
#include "vectormath.h"
#include <SFML/graphics.hpp>
#define READ (true)
#define WRITE (false)



static std::map<std::string, int> keyCodes
{
                 {"W", 0x57},
    {"A", 0x41}, {"S", 0x53}, {"D", 0x44},
    {"LEFT_MOUSE", 0x01}
};


class data{
    public:
        std::atomic<bool> gate{READ};
};


#endif
