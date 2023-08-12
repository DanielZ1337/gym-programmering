#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "include/categories.h"
#include "include/menu.h"
//#include "char_button.h"
#include <Categories.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

sf::Text a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;

vector<string> str_alp = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

vector<sf::Text> text_alp = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

sf::Image img0,img1,img2,img3,img4,img5,img6,img7,img8;

vector<sf::Image> hang_img = {img0,img1,img2,img3,img4,img5,img6,img7,img8};

vector<string> img_file = {"0.bmp","1.bmp","2.bmp","3.bmp","4.bmp","5.bmp","6.bmp","7.bmp","8.bmp"};

int times;
vector<int> win_check;
bool winner,loser;

// Function to remove all spaces from a given string
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}


void load_img(sf::Image &imgnum, const sf::String &img_str)
{
    imgnum.loadFromFile(img_str);
}

void drawText(sf::Text &alphabet, const sf::String &str)
{
    alphabet.setString(str);
    alphabet.setCharacterSize(100*(sf::VideoMode::getDesktopMode().width*sf::VideoMode::getDesktopMode().height)/(1920*1080));
    alphabet.setFillColor(sf::Color::White);
}

void pos_alp()
{
    for (int p = 0; p < 26; p++)
    {
        for (int i = 0; i < 26; i++)
        {
            float alp_width = text_alp[i].getLocalBounds().width;
            text_alp[i].setPosition((sf::VideoMode::getDesktopMode().width-alp_width)/10+p,(sf::VideoMode::getDesktopMode().height)/1.25);
            p+=alp_width+20;
        }
    }
}


int main()
{
    sf::SoundBuffer welcome;
    // Load it from a file
    if (!welcome.loadFromFile("welcome.wav"))
    {
        return -1;
    }
    sf::Sound message_welcome;
    message_welcome.setBuffer(welcome);
    message_welcome.setVolume(100);
    message_welcome.play();

    sf::SoundBuffer death;
    // Load it from a file
    if (!death.loadFromFile("death.wav"))
    {
        return -1;
    }
    sf::Sound p_death;
    p_death.setBuffer(death);

    sf::SoundBuffer hover;
    // Load it from a file
    if (!hover.loadFromFile("winning.wav"))
    {
        return -1;
    }
    sf::Sound p_hover;
    p_hover.setBuffer(hover);


    sf::SoundBuffer heartbeat;
    // Load it from a file
    if (!heartbeat.loadFromFile("heartbeat.wav"))
    {
        return -1;
    }
    sf::Sound p_heartbeat;
    p_heartbeat.setBuffer(heartbeat);

    sf::SoundBuffer bone_crush;
    // Load it from a file
    if (!bone_crush.loadFromFile("bone_crush.wav"))
    {
        return -1;
    }
    sf::Sound p_bone_crush;
    p_bone_crush.setBuffer(bone_crush);

    sf::SoundBuffer blood_squirt;
    // Load it from a file
    if (!blood_squirt.loadFromFile("blood_squirt.wav"))
    {
        return -1;
    }
    sf::Sound p_blood_squirt;
    p_blood_squirt.setBuffer(blood_squirt);

    sf::SoundBuffer ambience;
    // Load it from a file
    if (!ambience.loadFromFile("ambience.wav"))
    {
        return -1;
    }
    sf::Sound p_ambience;
    p_ambience.setBuffer(ambience);

    sf::SoundBuffer buildup;
    // Load it from a file
    if (!buildup.loadFromFile("buildup.wav"))
    {
        return -1;
    }
    sf::Sound p_buildup;
    p_buildup.setBuffer(buildup);

    /*std::string s = "example string";
    std::replace( s.begin(), s.end(), ' ', '');
    cout << s;
    */


    cout << "For testing; Choose your word or sentence..." << endl;
    string str;
    std::getline(cin,str);
    cout << "What category?" << endl;
    string category;
    std::getline(cin,category);

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "HANGMAN", sf::Style::Fullscreen);

    p_ambience.setVolume(75);
    p_ambience.play();

    sf::Font font;
    if (!font.loadFromFile("GHOST WALKER FREE.ttf"))
    {
        // error...
    }

    for (int i = 0; i < 26; ++i)
    {
        text_alp[i].setFont(font);
        drawText(text_alp[i], str_alp[i]);
    }

    pos_alp();

    sf::Text winner_text;
    winner_text.setFont(font);

    sf::Text text;

// select the font
    text.setFont(font); // font is a sf::Font

// set the string to display
    text.setString(category);

// set the character size
    text.setCharacterSize(150); // in pixels, not points!

    float text_width = text.getLocalBounds().width;

    text.setPosition((sf::VideoMode::getDesktopMode().width-text_width)/2,20);

// set the color
    text.setFillColor(sf::Color::Red);

// set the text style
    text.setStyle(sf::Text::Bold);

    // Load a sprite to display

    sf::Texture hangman_texture;
    if (!hangman_texture.loadFromFile("0.bmp"))
        return EXIT_FAILURE;
    sf::Sprite hangman(hangman_texture);
    float hangman_width = hangman.getLocalBounds().width;

    hangman.setPosition((sf::VideoMode::getDesktopMode().width-hangman_width)/2,150);

    // Start the game loop
    while (app.isOpen())
    {

        sf::Vector2f Mouse = app.mapPixelToCoords(sf::Mouse::getPosition(app));
        //cout << "Mouse.x = " << Mouse.x << ", Mouse.y = " << Mouse.y << std::endl;

        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            for(int i = 0; i < 26; i++)
            {
                if (text_alp[i].getGlobalBounds().contains(Mouse) == true)
                {
                    p_hover.setVolume(10);
                    p_hover.play();
                    text_alp[i].setFillColor(sf::Color::Red);
                }
                else if (text_alp[i].getGlobalBounds().contains(Mouse) == false)
                {
                    text_alp[i].setFillColor(sf::Color::White);
                }
            }


            for(int l = 0; l < 26; l++)
            {
                if (text_alp[l].getGlobalBounds().contains(Mouse) && app.hasFocus() == 1)
                {
                    static int i_1 = 1;
                    if (i_1 < 9 && winner != true)
                    {
                        if (event.key.code == sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {

                            switch (i_1)
                            {
                            case 1:
                                p_heartbeat.setVolume(2);
                                p_heartbeat.play();
                                p_heartbeat.setLoop(true);
                            case 2:
                                p_heartbeat.setVolume(16);
                                break;
                            case 3:
                                p_heartbeat.setVolume(32);
                                break;
                            case 4:
                                p_heartbeat.setVolume(48);
                                break;
                            case 5:
                                p_heartbeat.setVolume(64);
                                break;
                            case 6:
                                p_heartbeat.setVolume(80);
                                break;
                            case 7:
                                p_heartbeat.setVolume(95);
                                break;
                            case 8:
                                p_heartbeat.setVolume(100);
                                break;
                            default:
                                p_heartbeat.setVolume(0);
                                p_heartbeat.stop();
                                break;
                            }

                            string sub; // str is string to search, sub is the substring to search for

                            str = removeSpaces(str);

                            sub = str_alp[l];

                            int tolower ( int c_str);
                            std::for_each(str.begin(), str.end(), [](char & c_str)
                            {
                                c_str = ::tolower(c_str);
                            });

                            times = 0;

                            vector<size_t> positions; // holds all the positions that sub occurs within str
                            size_t pos = str.find(sub, 0);
                            while(pos != string::npos)
                            {
                                positions.push_back(pos);
                                pos = str.find(sub,pos+1);
                                times++;
                            }

                            if(str.find(" ",0))
                            {
                                cout << "space";
                            }

                            if(times == 0 && winner != true)
                            {
                                load_img(hang_img[i_1],img_file[i_1]);
                                hangman_texture.update(hang_img[i_1]);
                                i_1++;
                                text_alp[l].setCharacterSize(0);
                                text_alp[l].setString("");
                                cout << "WRONG! " << endl;
                                if(i_1 == 9)
                                {
                                    p_death.setVolume(100);
                                    p_death.play();
                                    p_heartbeat.stop();
                                    p_blood_squirt.play();
                                    p_bone_crush.play();
                                    loser = true;
                                    p_buildup.play();
                                }
                            }

                            else
                            {
                                for (auto i = positions.begin(); i != positions.end(); ++i)
                                {
                                    win_check.push_back(*i);
                                }
                                times = 0;
                                text_alp[l].setCharacterSize(0);
                                text_alp[l].setString("");
                                cout << "CORRECT! " << endl;
                                if(win_check.size() == str.size() && winner != true)
                                {
                                    cout << "Winner";
                                    winner = true;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            // Closes window : escape
            if (event.key.code == sf::Keyboard::Escape)
            {
                app.close();
            }

        }
        //Set max framerate
        app.setFramerateLimit(144);

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(hangman);
        app.draw(text);

        //draws the alphabet
        for (int i = 0; i < 26; ++i)
        {
            app.draw(text_alp[i]);
        };

        //print underscores for the text
        /*for (int i = 0; i < str.size(); ++i)
        {
            ;
        };*/

        if(winner == true)
        {
            drawText(winner_text,"Winner");
            winner_text.setCharacterSize(450);
            float width_winner = winner_text.getLocalBounds().width;
            float height_winner = winner_text.getLocalBounds().height;
            winner_text.setLetterSpacing(2);
            winner_text.setOutlineColor(sf::Color::Red);
            winner_text.setOutlineThickness(2);
            winner_text.setPosition((sf::VideoMode::getDesktopMode().width-width_winner)/2,(sf::VideoMode::getDesktopMode().height-height_winner)/3);
            app.draw(winner_text);
        }

        if(loser == true)
        {
            drawText(winner_text,"Loser");
            winner_text.setCharacterSize(450);
            float width_winner = winner_text.getLocalBounds().width;
            float height_winner = winner_text.getLocalBounds().height;
            winner_text.setLetterSpacing(2);
            winner_text.setOutlineColor(sf::Color::Red);
            winner_text.setOutlineThickness(2);
            winner_text.setFillColor(sf::Color::Red);
            winner_text.setPosition((sf::VideoMode::getDesktopMode().width-width_winner)/2,(sf::VideoMode::getDesktopMode().height-height_winner)/3);
            app.draw(winner_text);
        }

        // Update the window
        app.display();
    }

    //return EXIT_SUCCESS;
}
