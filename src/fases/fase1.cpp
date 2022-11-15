//
// Created by doglasrocha on 11/4/22.
//

#include "../../Includes/Fases/fase1.hpp"

Fase1::Fase1(GerenciadorColisoes *gC,
             GerenciadorEventos *gE,
             Jogador *ptrJogador,
             Jogo *ptrJogo) :
Fase(gC, gE, ptrJogador, ptrJogo) {

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

    criaPlataforma(
        infoPlataformas[0][0],
        infoPlataformas[0][1],
        infoPlataformas[0][2],
        infoPlataformas[0][3]
    );
    for (int i = 1; i < 8; i++) {
        criaPlataformaComAgregadosAleatorios(
            infoPlataformas[i][0],
            infoPlataformas[i][1],
            infoPlataformas[i][2],
            infoPlataformas[i][3]
        );
    }

    criaParede(500, 0, 0);
    criaParede(500, 2400, 0);

    planoDeFundo = new BackgroundManager("pixel_art_forest/Background.png");
}

Fase1::~Fase1() {
    delete planoDeFundo;
}