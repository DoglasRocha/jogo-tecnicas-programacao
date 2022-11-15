#pragma once
#include "obstaculo.hpp"

using entidades::obstaculos::Obstaculo;

class Fogo : public Obstaculo
{
    private:
    /*static*/ int intensidade;

    public:
        Fogo(int posX, int posY);
        ~Fogo();
        /*static*/ int getIntensidade();
        void processarEventos(sf::Event evento);
        void setEmpuxo(int novoEmpuxo);
        void interage(Personagem *ptrJogador);
};
