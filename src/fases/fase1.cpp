//
// Created by doglasrocha on 11/4/22.
//

#include "../../Includes/Fases/fase1.hpp"
#include "../../Includes/jogo.hpp"

Fase1::Fase1(GerenciadorColisoes *gC,
             GerenciadorEventos *gE,
             Jogador *ptrJogador,
             Jogo *ptrJogo,
             Jogador *ptrJogador2) :
Fase(gC, gE, ptrJogador, ptrJogo, ptrJogador2) {

    int infoPlataformas[11][4] = {
        {1000, 50, 32, 950},
        {1500, 50, 1000, 800},
        {1000, 50, 2500, 950},
        {300, 20, 200, 800},
        {400, 20, 900, 450},
        {500, 20, 1500, 600},
        {500, 20, 1500, 250},
        {400, 20, 2100, 300},
        {600, 20, 2200, 550},
        {450, 20, 2800, 750},
        {350, 20, 2800, 450}
    };

    int infoParedes[4][3] = {
        {500, 0, 500}, 
        {200, 1000, 800},
        {200, 2500, 800},
        {500, 3500, 500}
    };

    for (int i = 0; i < 3; i++)
        criaPlataforma(
            infoPlataformas[i][0],
            infoPlataformas[i][1],
            infoPlataformas[i][2],
            infoPlataformas[i][3]
        );

    for (int i = 3; i < 11; i++) 
        criaPlataformaComAgregadosAleatorios(
            infoPlataformas[i][0],
            infoPlataformas[i][1],
            infoPlataformas[i][2],
            infoPlataformas[i][3],
            true, true, false
        );

    for (int i = 0; i < 4; i++)
        criaParede(
            infoParedes[i][0],
            infoParedes[i][1],
            infoParedes[i][2]
        );

    criaMorcego(100, 300);
    criaMorcego(1400, 600); 
    criaMorcego(3350, 600);

    planoDeFundo = new BackgroundManager("pixel_art_forest/Background.png");
}

Fase1::~Fase1() {

}

void Fase1::trocaEstado(int opcao) {
    if(!(ptrJogador->getVivo())) 
        ptrJogo->irParaMenu();
    else if (gerenciadorColisoes->getVetorInimigos().empty()){
        if (ptrJogador2) ptrJogo->irParaFase2(1);
        else ptrJogo->irParaFase2(1);
    }     
}