#ifndef GUI_H
#define GUI_H
#include <SFML/graphics.hpp>

class GUI : public sf::RenderWindow
{
    public:
        GUI(int width = 512, int height = 512, std::string name = "PP");
        virtual ~GUI();
        int width, height = 0;

    protected:

    private:
};

#endif // GUI_H
