//
// Created by doglasrocha on 11/4/22.
//

#include "../../Includes/Fases/fase1.hpp"
#include "../../Includes/Entidades/Obstaculos/plataforma.hpp"

using entidades::obstaculos::Plataforma;

Fase1::Fase1(GerenciadorColisoes *gC,
             GerenciadorGrafico *gG,
             GerenciadorEventos *gE,
             Jogador *ptrJogador) :
Fase(gC, gG, gE, ptrJogador) {
    int infoPlataformas[6][4] = {
            {1400, 50, 0, 950},
            {50, 1400, 0, 0},
            {50, 1400, 1350, 0},
            {300, 20, 100, 750},
            {300, 20, 300, 550}
    };

    for (int i = 0; i < 5; i++) {
        Plataforma *novaPlataforma = new Plataforma(
                infoPlataformas[i][0],
                infoPlataformas[i][1],
                infoPlataformas[i][2],
                infoPlataformas[i][3]
        );
        listaDeEntidades.append(novaPlataforma);
        gerenciadorColisoes->addObstaculo(novaPlataforma);
    }
    listaDeEntidades.append(ptrJogador);
    planoDeFundo = new BackgroundManager("pixel_art_forest/Background.png",
                                         gerenciadorGrafico);
}

Fase1::~Fase1() {
    delete planoDeFundo;
}

void Fase1::executar() {
    processaEventos();
    desenhar(gerenciadorGrafico);
}
