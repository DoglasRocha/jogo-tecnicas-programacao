#pragma once
#include "obstaculo.hpp"

using entidades::obstaculos::Obstaculo;

class Fogo : public Obstaculo
{
    private:
    int intensidade;

    public:
    Fogo();
    ~Fogo();
    int getIntensidade();
};
