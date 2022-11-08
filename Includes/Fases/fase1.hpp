#pragma once
#include "fase.hpp"

using fases::Fase;

class Fase1 : public Fase
{
public:
    Fase1(GerenciadorColisoes *gC=nullptr,
          GerenciadorGrafico *gG=nullptr,
          GerenciadorEventos *gE=nullptr,
          Jogador *ptrJogador=nullptr);
    ~Fase1();
};