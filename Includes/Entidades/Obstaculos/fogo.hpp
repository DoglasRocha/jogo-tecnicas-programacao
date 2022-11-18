#pragma once
#include "obstaculo.hpp"

using entidades::obstaculos::Obstaculo;

class Fogo : public Obstaculo
{
    private:
        int intensidade;

    public:
        Fogo(const int posX, const int posY);
        ~Fogo();
        int getIntensidade() const;
        void processarEventos(sf::Event evento);
        void setEmpuxo(int novoEmpuxo);
        void interage(Personagem *ptrJogador);
};
