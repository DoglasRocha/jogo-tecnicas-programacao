#pragma once
#include "fase.hpp"
#include "../../Includes/Entidades/Personagens/Inimigos/minotauro.hpp"
#include "../../Includes/Entidades/projetil.hpp"

using namespace entidades;

using fases::Fase;

class Fase2 : public Fase
{
public:
    Fase2(GerenciadorColisoes *gC=nullptr,
          GerenciadorEventos *gE=nullptr,
          Jogador *ptrJogador=nullptr,
          Jogo *ptrJogo=nullptr,
          Jogador *ptrJogador2=nullptr);
    ~Fase2();
    void trocaEstado(int opcao=0);
    void criaMinotauro(int posX, int posY);
    void criaProjetil(Minotauro* ptrMino);
};
