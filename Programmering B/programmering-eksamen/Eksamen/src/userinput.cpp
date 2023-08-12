#include "userinput.h"
#include "windows.h"
#include <time.h>
#include "physics.h"

userInput::userInput()
{
    //ctor
}

userInput::~userInput()
{
    //dtor
}

userInput::handleKeyPress(int playerX, int playerY, player& playerObj, std::vector<bullet*>& allBullets, sf::RenderWindow& window, data& dataObj, bool& gameLoop, std::vector<player*>& enemies)
{
    srand (std::time(0));
    physics physObj;
    tagPOINT cursor;
    sf::Vector2i winPos = window.getPosition();
    clock_t t = clock();
    clock_t shootingTimer = clock();
    int movementUpdateFreq = 4;
    int movementDist = 5;
    int shootingFreq = 110;

    while(gameLoop){
        if(dataObj.gate == WRITE){
            //std::cout << relMousePosX << "\t" << relMousePosY << std::endl;
            if(clock() - shootingTimer >= shootingFreq){
                if(GetKeyState(keyCodes["LEFT_MOUSE"]) & 0x8000){
                    GetCursorPos(&cursor);
                    int relMousePosX = cursor.x - winPos.x;
                    int relMousePosY = cursor.y - winPos.y - 30;
                    bullet *newBullet = new bullet(playerObj.x+80, playerObj.y-115, relMousePosX, relMousePosY);
                    allBullets.push_back(newBullet);
                    physObj.checkHit(newBullet, enemies);
                    shootingTimer = clock();
                    //std::cout << "Mouse pressed" << std::endl;
                }
            }

            if(clock() - t >= movementUpdateFreq){
                if(GetKeyState(keyCodes["W"]) & 0x8000 && playerObj.getPosition().y > playerObj.getLocalBounds().height-175){
                    playerY -= movementDist;
                }
                if(GetKeyState(keyCodes["A"]) & 0x8000 && playerObj.getPosition().x > 185){
                    playerX -= movementDist;
                }
                if(GetKeyState(keyCodes["S"]) & 0x8000 && playerObj.getPosition().y < 1050){
                    playerY += movementDist;
                }
                if(GetKeyState(keyCodes["D"]) & 0x8000 && playerObj.getPosition().x < playerObj.getLocalBounds().width-250){
                    playerX += movementDist;
                }


                t = clock();
                playerObj.updatePlayer(playerX, playerY, -90);
            }
            dataObj.gate = READ;
        }
    }
}
