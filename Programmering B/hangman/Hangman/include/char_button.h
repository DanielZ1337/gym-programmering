#ifndef CHAR_BUTTON_H
#define CHAR_BUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class char_button : public sf::Text, public sf::String, public sf::Color
{
public:
    textbox();
    virtual ~char_button();

protected:

private:
};

#endif // CHAR_BUTTON_H
