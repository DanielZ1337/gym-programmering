#include <SFML/Window.hpp>
#include <SFML/graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> choices = {"Afvigelse"};
float mean(const std::vector<float>& v);
sf::CircleShape makePoint(int x, float y);


int main()
{
    std::ifstream file("fysik_data.csv");

    std::string title1, title2, str;
    file >> title1 >> str;
    //std::cout << title1;
    //std::cout << str;
    file >> title2 >> str;
    //std::cout << title2;
    //std::cout << str;

    float time, temp;
    char comma;
    std::vector<float> times, temps;
    while (file >> time >> comma >> temp)
    {
        times.push_back(time);
        temps.push_back(temp);
    }

    std::cout << "Gennemsnit: " << mean(times) << ", " << mean(temps) << std::endl;

    std::cout << "Valgmuligheder:\n";
    for(int i = 0; i < choices.size();i++){
        std::cout << choices[i] << std::endl;
    }
    std::string choice;

    /*std::cin >> choice;
    if (choice == "afvigelse"){

    }*/

    sf::RenderWindow window(sf::VideoMode(800, 600), "Datapunkter", sf::Style::Close);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i=0; i < times.size();i ++){
         window.draw(makePoint(times[i],temps[i]));
        }
        window.display();
    }

    return 0;
}

float mean(const std::vector<float>& v)
{
    float sum = 0;
    for(size_t k = 0; k < v.size(); k++) sum += v[k];
    return sum / v.size();
}

sf::CircleShape makePoint(int x, float y){
    sf::CircleShape circle;
circle.setRadius(5);
circle.setOutlineColor(sf::Color::Red);
circle.setOutlineThickness(1);
circle.setPosition(x, -y+600);
return circle;
}
