#pragma once
#include "obstaculo.hpp"

using entidades::obstaculos::Obstaculo;

class Fogo : public Obstaculo
{
    private:
    /*static*/ int intensidade;

    public:
    Fogo();
    ~Fogo();
    /*static*/ int getIntensidade();
};
