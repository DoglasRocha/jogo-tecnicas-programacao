#pragma once
#include "fase.hpp"

using fases::Fase;

class Fase2 : public Fase
{
public:
    Fase2(GerenciadorColisoes *gC=nullptr,
          GerenciadorEventos *gE=nullptr,
          Jogador *ptrJogador=nullptr,
          Jogo *ptrJogo=nullptr);
    ~Fase2();
    void trocaEstado(int opcao=0);
};
