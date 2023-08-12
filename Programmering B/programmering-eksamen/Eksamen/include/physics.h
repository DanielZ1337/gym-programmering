#ifndef PHYSICS_H
#define PHYSICS_H
#include "globals.h"
#include "ammo.h"
#include "characters.h"


class physics
{
    public:
        physics();
        virtual ~physics();
        void movement(int x, int y);
        int moveX, moveY = 0;
        struct line{
            double a;
            double b;
        };
        bool checkHit(bullet* gunShot, std::vector<player*>& enemies);


    protected:

    private:
        void makeLine(bullet* gunShot, line& newLine);
        double distFromCentrum(int hitboxX, int hitboxY, int radius, double bulletA, double bulletB);
};
#endif // PHYSICS_H
