#ifndef CHARACTERS_H
#define CHARACTERS_H
#include "globals.h"

class characters : public sf::Sprite
{
    public:
        characters();
        virtual ~characters();

    protected:

    private:
};



class hitbox_enemy : public sf::CircleShape
{
    public:
        hitbox_enemy(int radius, int x, int y);
        void updateEnemy_hitbox(int x, int y);
        int x, y, radius = 0;
};

class hitbox_car : public sf::RectangleShape
{
    public:
        hitbox_car(int x, int y);
        void updateCar_hitbox(int x, int y);
};

class player : public characters
{
    public:
        player();
        player(std::string file, float model_ratio, int x, int y, int& hitboxCount, float rotation = 0, bool noHitbox = false);
        ~player();
        void updatePlayer(int x, int y, int r);
        std::vector<player*> initEnemies(std::string enemyModel, float enemySizeRatio, std::vector<std::vector<int>> coords, int hitboxRadius, std::vector<std::vector<int>> hitBoxCoords, int& hitboxCount);
        hitbox_enemy* hitboxEnemy;
        hitbox_car* hitboxPlayer;
        int x, y = 0;
        bool hit = false;
    private:
        sf::Texture texture;
};

class gangster : public characters
{
    public:
        gangster();
};

#endif // CHARACTERS_H
