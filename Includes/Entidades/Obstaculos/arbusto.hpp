#pragma once
#include "obstaculo.hpp"

using entidades::obstaculos::Obstaculo;

class Arbusto : public Obstaculo
{
    private:
        float altura;

    public:
        Arbusto(int posX, int posY);
        ~Arbusto();
        float getAltura();
        void processarEventos(sf::Event evento);
        void setEmpuxo(int novoEmpuxo);  
};
