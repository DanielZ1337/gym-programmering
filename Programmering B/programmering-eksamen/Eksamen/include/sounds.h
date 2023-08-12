#ifndef SOUNDS_H
#define SOUNDS_H
#include <SFML/Audio.hpp>


class sounds : public sf::Sound
{
    public:
        sounds();
        void setupSound(std::string file, int vol = 50);
        virtual ~sounds();
        sf::SoundBuffer idle_buffer;

    protected:

    private:
};

#endif // SOUNDS_H
