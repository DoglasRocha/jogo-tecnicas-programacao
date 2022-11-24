#pragma once
#include "jogador.hpp"

using namespace entidades;

class Jogador2 : public personagens::Jogador{
    public:
    Jogador2();
    ~Jogador2();
    void desenhaBarraVida();
    void moverX();
    void processarEventos(sf::Event evento);
};