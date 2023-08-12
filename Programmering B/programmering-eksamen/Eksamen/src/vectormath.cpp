#include "vectormath.h"
#include "math.h"

math::vector::vector(int x, int y)
{
    this->x = x;
    this->y = y;
}

math::vector::~vector()
{
    //dtor
}

float math::vector::getSize()
{
    float temp = (this->x * this->x) + (this->y * this->y);
    float dist = sqrt(temp);
    this->length = dist;
    return dist;
}

math::vector math::vector::makeCross()
{
    math::vector crossVector(-this->y, this->x);
    return crossVector;
}

math::vector math::vector::makeUnit()
{
    float relation = 1.0/this->getSize();
    float unitX = relation * this->x;
    float unitY = relation * this->y;
    int x = floor(unitX + 4);
    int y = floor(unitY + 4);
    math::vector unitVector(x, y);
    return unitVector;
}
