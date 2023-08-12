#include "sounds.h"

sounds::sounds()
{
    //ctor
}

sounds::~sounds()
{
    //dtor
}

void sounds::setupSound(std::string file, int vol)
{
    this->idle_buffer.loadFromFile(file);
    this->setBuffer(idle_buffer);
    this->setVolume(vol);
}
