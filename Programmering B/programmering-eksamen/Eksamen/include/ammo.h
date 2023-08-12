#ifndef AMMO_H
#define AMMO_H
#include "globals.h"

class bullet : public sf::ConvexShape
{
    public:
        bullet(int x1, int y1, int x2, int y2);
        sf::Vector2i start, end;
        int x, y, angle, recoilAngle = 0;
        int recoilRange = 9;
        double length = 0;
};


#endif // AMMO_H
