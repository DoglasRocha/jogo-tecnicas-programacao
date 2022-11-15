//
// Created by doglasrocha on 11/4/22.
//

#include "../../Includes/Fases/fase1.hpp"
#include "../../Includes/Entidades/Obstaculos/plataforma.hpp"
#include "../../Includes/Entidades/Obstaculos/parede.hpp"
#include "../../Includes/Entidades/Obstaculos/arbusto.hpp"
#include "../../Includes/Entidades/Obstaculos/fogo.hpp"
#include "../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"

using entidades::obstaculos::Plataforma;
using entidades::obstaculos::Parede;
using entidades::personagens::Narigudo;

Fase1::Fase1(GerenciadorColisoes *gC,
             GerenciadorEventos *gE,
             Jogador *ptrJogador,
             Jogo *ptrJogo) :
Fase(gC, gE, ptrJogador, ptrJogo) {

    Plataforma *novaPlataforma;
    Narigudo *novoNarigudo;
    Parede *novaParede;
    Arbusto *novoArbusto;
    Fogo *novoFogo;

    int infoPlataformas[8][4] = {
            {2400, 50, 32, 950},
            {300, 20, 100, 750},
            {300, 20, 300, 550},
            {450, 20, 1200, 750},
            {150, 20, 975, 450},
            {300, 20, 1750, 800},
            {450, 20, 1900, 575},
            {150, 20, 2250, 400}
    };

    listaDeEntidades.append(ptrJogador);

    for (int i = 0; i < 8; i++) {
        novaPlataforma = new Plataforma(
                infoPlataformas[i][0],
                infoPlataformas[i][1],
                infoPlataformas[i][2],
                infoPlataformas[i][3]
        );

        novoNarigudo = new Narigudo(
            infoPlataformas[i][2] + 160,
            infoPlataformas[i][3] - 50);
        
        novoArbusto = new Arbusto(
            infoPlataformas[i][2] + 20,
            infoPlataformas[i][3]);

        novoFogo = new Fogo(
            infoPlataformas[i][2] + 150,
            infoPlataformas[i][3]);

        listaDeEntidades.
            append(novaPlataforma)->
            append(novoNarigudo)->
            append(novoArbusto)->
            append(novoFogo);

        gerenciadorColisoes->
            addObstaculo(novaPlataforma)->
            addInimigo(novoNarigudo)->
            addObstaculo(novoArbusto)->
            addObstaculo(novoFogo);
    }

    novaParede = new Parede(32, 1400, 0, 0);
    listaDeEntidades.append(novaParede);
    gerenciadorColisoes->addObstaculo(novaParede);

    novaParede = new Parede(32, 1400, 2400, 0);
    listaDeEntidades.append(novaParede);
    gerenciadorColisoes->addObstaculo(novaParede);

    planoDeFundo = new BackgroundManager("pixel_art_forest/Background.png");
}

Fase1::~Fase1() {
    delete planoDeFundo;
}