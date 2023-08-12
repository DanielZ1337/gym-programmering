#ifndef USERINPUT_H
#define USERINPUT_H
#include "globals.h"
#include "characters.h"
#include "ammo.h"


class userInput
{
    public:
        userInput();
        virtual ~userInput();
        handleKeyPress(int playerX, int playerY, player& playerObj, std::vector<bullet*>& allBullets, sf::RenderWindow& window, data& dataObj, bool& gameLoop, std::vector<player*>& enemies);

    protected:

    private:
};

#endif // USERINPUT_H
