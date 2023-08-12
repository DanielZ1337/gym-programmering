#include "../include/physics.h"

physics::physics()
{
    //ctor
}

physics::~physics()
{
    //dtor
}

void physics::movement(int x, int y)
{
    this->moveX = x;
    this->moveY = y;
}

double physics::distFromCentrum(int hitboxX, int hitboxY, int radius, double bulletA, double bulletB)
{
    double top = std::abs((bulletA * hitboxX) + bulletB - hitboxY);
    double bottom = sqrt((bulletA*bulletA)+1);
    double total = top/bottom;
    return total;
}

void physics::makeLine(bullet* gunShot, line& newLine)
{
    newLine.a = float(gunShot->end.y - gunShot->start.y)/float(gunShot->end.x - gunShot->start.x);
    newLine.b = float(gunShot->start.y) - (newLine.a * gunShot->start.x);
}

bool physics::checkHit(bullet* gunShot, std::vector<player*>& enemies)
{
    line newLine;
    makeLine(gunShot, newLine);
    for(int i = 0; i < enemies.size(); i++){
        int adjustedX = std::abs(enemies[i]->hitboxEnemy->x - gunShot->start.x);
        int adjustedY = std::abs(enemies[i]->hitboxEnemy->y - gunShot->start.y);
        math::vector newVec(adjustedX, adjustedY);
        float len = newVec.getSize();
        //std::cout << len << "\t" << gunShot->length << std::endl;
        double dist = distFromCentrum(enemies[i]->hitboxEnemy->x, enemies[i]->hitboxEnemy->y, enemies[i]->hitboxEnemy->radius, newLine.a, newLine.b);
        if(dist <= enemies[i]->hitboxEnemy->radius && gunShot->length >= len){
            enemies[i]->hit = true;
        }
    }
}
