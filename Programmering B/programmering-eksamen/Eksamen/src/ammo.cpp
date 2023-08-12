#include "ammo.h"


bullet::bullet(int x1, int y1, int x2, int y2)
{
    int recoil = rand() % this->recoilRange;
    int side = rand() % 2;

    if(side == 0){
        recoil = -recoil;
    }

    int xTemp = x2 - x1;
    int yTemp = y2 - y1;
    float recoilRadian = (recoil * PI)/180;
    int x = xTemp * cos(recoilRadian) - yTemp * sin(recoilRadian);
    int y = xTemp * sin(recoilRadian) + yTemp * cos(recoilRadian);

    this->recoilAngle = recoil;
    this->start = sf::Vector2i{x1, y1};
    this->end = sf::Vector2i{x + x1, y + y1};
    math::vector gunshot(x, y);
    this->length = gunshot.getSize();
    math::vector crossVec = gunshot.makeCross();
    math::vector unitVec = crossVec.makeUnit();
    this->setPointCount(4);
    this->setPoint(0, sf::Vector2f(x1, y1));
    this->setPoint(1, sf::Vector2f(gunshot.x + x1, gunshot.y + y1));
    this->setPoint(2, sf::Vector2f(gunshot.x + x1 + unitVec.x, gunshot.y + y1 + unitVec.y));
    this->setPoint(3, sf::Vector2f(x1 + unitVec.x , y1 + unitVec.y));
}
