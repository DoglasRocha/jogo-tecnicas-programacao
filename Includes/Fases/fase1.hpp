#pragma once
#include "fase.hpp"

using fases::Fase;

class Fase1 : public Fase
{
private:
    int contArbusto = 0; 

public:
    Fase1(GerenciadorColisoes *gC=nullptr,
          GerenciadorEventos *gE=nullptr,
          Jogador *ptrJogador=nullptr,
          Jogo *ptrJogo=nullptr,
          Jogador *ptrJogador2=nullptr);
    ~Fase1();
    void trocaEstado(int opcao=0);
    void criaPlataformaComAgregadosAleatorios(int tamX, int tamY, int posX, int posY);
};