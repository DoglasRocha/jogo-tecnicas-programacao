//
// Created by doglasrocha on 11/4/22.
//

#include "../../Includes/Fases/fase1.hpp"
#include "../../Includes/Entidades/Obstaculos/plataforma.hpp"
#include "../../Includes/Entidades/Obstaculos/parede.hpp"
#include "../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"

using entidades::obstaculos::Plataforma;
using entidades::obstaculos::Parede;
using entidades::personagens::Narigudo;

Fase1::Fase1(GerenciadorColisoes *gC,
             GerenciadorEventos *gE,
             Jogador *ptrJogador) :
Fase(gC, gE, ptrJogador) {

    Plataforma *novaPlataforma;
    Narigudo *novoNarigudo;
    Parede *novaParede;

    int infoPlataformas[3][4] = {
            {1336, 50, 32, 950},
            {300, 20, 100, 750},
            {300, 20, 300, 550}
    };


    for (int i = 0; i < 3; i++) {
        novaPlataforma = new Plataforma(
                infoPlataformas[i][0],
                infoPlataformas[i][1],
                infoPlataformas[i][2],
                infoPlataformas[i][3]
        );

        novoNarigudo = new Narigudo(
            infoPlataformas[i][2] + 100,
            infoPlataformas[i][3] - 50);

        listaDeEntidades.
            append(novaPlataforma)->
            append(novoNarigudo);

        gerenciadorColisoes->
            addObstaculo(novaPlataforma)->
            addInimigo(novoNarigudo);
    }

    novaParede = new Parede(32, 1400, 0, 0);
    listaDeEntidades.append(novaParede);
    gerenciadorColisoes->addObstaculo(novaParede);

    novaParede = new Parede(32, 1400, 1368, 0);
    listaDeEntidades.append(novaParede);
    gerenciadorColisoes->addObstaculo(novaParede);

    listaDeEntidades.append(ptrJogador);
    planoDeFundo = new BackgroundManager("pixel_art_forest/Background.png");
}

Fase1::~Fase1() {
    delete planoDeFundo;
}