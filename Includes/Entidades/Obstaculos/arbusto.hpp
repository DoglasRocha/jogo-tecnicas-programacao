#pragma once
#include "obstaculo.hpp"

using entidades::obstaculos::Obstaculo;

class Arbusto : public Obstaculo
{
    private:
        float altura;

    public:
        Arbusto(const int posX, const int posY);
        ~Arbusto();
        float getAltura() const;
        void processarEventos(sf::Event evento);
        void setEmpuxo(int novoEmpuxo);  
        void interage(Personagem *ptrJogador);
};
