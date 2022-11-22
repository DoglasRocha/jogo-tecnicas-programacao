#pragma once
#include "jogador.hpp"

using namespace entidades;

class Jogador1 : public personagens::Jogador{
    public:
    Jogador1();
    ~Jogador1();
    void desenhaBarraVida();
    void processarEventos(sf::Event evento);
};