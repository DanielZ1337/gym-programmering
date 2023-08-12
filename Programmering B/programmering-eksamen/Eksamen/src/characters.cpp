#include "characters.h"

characters::characters()
{
    //ctor
}

characters::~characters()
{
    //dtor
}

player::player()
{
    //ctor
}

player::~player()
{
    delete this->hitboxPlayer;
    delete this->hitboxEnemy;
}

player::player(std::string file, float model_ratio, int x, int y, int& hitboxCount, float rotation, bool noHitbox)
{
    texture.loadFromFile(file);
    this->x = x;
    this->y = y;
    this->setTexture(texture);
    this->setScale(model_ratio,model_ratio);
    this->setPosition(x, y);
    this->setRotation(rotation);
    hitbox_car *temp = new hitbox_car(this->x, this->y);
    this->hitboxPlayer = temp;
    if(!noHitbox){
        hitboxCount += 1;
    }
}

void player::updatePlayer(int x, int y, int r)
{
    this->setPosition(x, y);
    this->x = x;
    this->y = y;
    this->setRotation(r);
}

hitbox_enemy::hitbox_enemy(int radius, int x, int y)
{
    this->setRadius(radius);
    this->setOutlineColor(sf::Color::Red);
    this->setPosition(x, y);
    this->x = x;
    this->y = y;
    this->radius = radius;
}

void hitbox_enemy::updateEnemy_hitbox(int x, int y)
{
    this->setPosition(x, y);
    this->x = x;
    this->y = y;
}

hitbox_car::hitbox_car(int x, int y)
{
    this->setSize(sf::Vector2f(100, 300));
    this->setPosition(x, y-200);
}

void hitbox_car::updateCar_hitbox(int x, int y)
{
    this->setPosition(x, y);
//    this->setRotation());
}

std::vector<player*> player::initEnemies(std::string enemyModel, float enemySizeRatio, std::vector<std::vector<int>> coords, int hitboxRadius, std::vector<std::vector<int>> hitBoxCoords, int& hitboxCount)
{
    std::vector<player*> temp = {};
    for(int i = 0; i < coords.size(); i++){
        player *newEnemy = new player(enemyModel, enemySizeRatio, coords[i][0], coords[i][1], hitboxCount);
        hitbox_enemy *tempHitbox = new hitbox_enemy(hitboxRadius, hitBoxCoords[i][0], hitBoxCoords[i][1]);
        newEnemy->hitboxEnemy = tempHitbox;
        temp.push_back(newEnemy);
    }
    return temp;
}
