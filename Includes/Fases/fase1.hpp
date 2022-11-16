#pragma once
#include "fase.hpp"

using fases::Fase;

class Fase1 : public Fase
{
public:
    Fase1(GerenciadorColisoes *gC=nullptr,
          GerenciadorEventos *gE=nullptr,
          Jogador *ptrJogador=nullptr,
          Jogo *ptrJogo=nullptr);
    ~Fase1();
    void trocaEstado(int opcao=0);
};