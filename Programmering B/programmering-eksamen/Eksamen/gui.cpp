#include "gui.h"

GUI::GUI(int width, int height, std::string name)
{
    this->width = width;
    this->height = height;
    this->name = name;
    this->mode = sf::VideoMode(width, height);
    this->title = name;
}

GUI::~GUI()
{
    //dtor
}
