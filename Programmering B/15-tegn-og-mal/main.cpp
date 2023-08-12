#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    int n;

    sf::RectangleShape rec1(sf::Vector2f(n, n));
    sf::RectangleShape rec2(sf::Vector2f(n, n));
    sf::RectangleShape rec3(sf::Vector2f(n, n));
    sf::RectangleShape rec4(sf::Vector2f(n, n));
    sf::RectangleShape rec5(sf::Vector2f(n, n));
    sf::RectangleShape rec6(sf::Vector2f(n, n));
    sf::RectangleShape rec7(sf::Vector2f(n, n));
    sf::RectangleShape rec8(sf::Vector2f(n, n));
    sf::RectangleShape rec9(sf::Vector2f(n, n));

    sf::CircleShape shape(150.f);
    sf::CircleShape shape2(10.f);
    sf::RectangleShape lmao(sf::Vector2f(120.f, 50.f));
    sf::ConvexShape fuck;
    fuck.setPointCount(3);
    fuck.setPoint(0, sf::Vector2f(150.f, 99.f));
    fuck.setPoint(1, sf::Vector2f(200.f, 150.f));
    fuck.setPoint(2, sf::Vector2f(250.f, 99.f));

    fuck.setOutlineThickness(5);
    fuck.setOutlineColor(sf::Color(252,28,255));

    lmao.setOutlineThickness(5);
    lmao.setOutlineColor(sf::Color(252,28,255));

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color::Red),
        sf::Vertex(sf::Vector2f(0.f, 50.f),sf::Color::Red)
    };

    sf::Vertex line_1[] =
    {
        sf::Vertex(sf::Vector2f(0.f, 50.f),sf::Color::Red),
        sf::Vertex(sf::Vector2f(120.f, 50.f),sf::Color::Red)
    };

    sf::Vertex line_2[] =
    {
        sf::Vertex(sf::Vector2f(120.f, 50.f),sf::Color::Red),
        sf::Vertex(sf::Vector2f(120.f, 0.f),sf::Color::Red)
    };

    sf::Vertex line_3[] =
    {
        sf::Vertex(sf::Vector2f(150.f, 99.f),sf::Color::Blue),
        sf::Vertex(sf::Vector2f(200.f, 150.f),sf::Color::Blue)
    };

    sf::Vertex line_4[] =
    {
        sf::Vertex(sf::Vector2f(200.f, 150.f),sf::Color::Blue),
        sf::Vertex(sf::Vector2f(250.f, 99.f),sf::Color::Blue),
    };

    sf::Vertex line_5[] =
    {
        sf::Vertex(sf::Vector2f(250.f, 99.f),sf::Color::Blue),
        sf::Vertex(sf::Vector2f(150.f, 99.f),sf::Color::Blue)
    };

    shape.setFillColor(sf::Color::Green);
    rec9.setFillColor(sf::Color::White);

    std::cin >> n;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML shapes", sf::Style::Default, settings);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.draw(lmao);
        window.draw(fuck);
        window.draw(line, 2, sf::Lines);
        window.draw(line_1, 2, sf::Lines);
        window.draw(line_2, 2, sf::Lines);
        window.draw(line_3, 2, sf::Lines);
        window.draw(line_4, 2, sf::Lines);
        window.draw(line_5, 2, sf::Lines);*/
        window.clear();
        window.draw(rec1);
        window.draw(rec2);
        window.draw(rec3);
        window.draw(rec4);
        window.draw(rec5);
        window.draw(rec6);
        window.draw(rec7);
        window.draw(rec8);
        window.draw(rec9);
        window.display();
    }

    return 0;
}


