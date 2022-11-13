#pragma once
#include "obstaculo.hpp"

using entidades::obstaculos::Obstaculo;

class Arbusto : public Obstaculo
{
    private:
    float altura;

    public:
    Arbusto();
    ~Arbusto();
    float getAltura() const;    
};
