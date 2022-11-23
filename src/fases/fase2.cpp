#include "../../Includes/Fases/fase2.hpp"
#include "../../Includes/jogo.hpp"
#include "../../Includes/Entidades/Personagens/Inimigos/minotauro.hpp"
#include "../../Includes/Entidades/projetil.hpp"

using namespace entidades;

Fase2::Fase2(GerenciadorColisoes *gC,
             GerenciadorEventos *gE,
             Jogador *ptrJogador,
             Jogo *ptrJogo,
             Jogador *ptrJogador2) :
Fase(gC, gE, ptrJogador, ptrJogo, ptrJogador2) {

    int infoPlataformas[11][4] = {
        {1000, 50, 32, 950},
        {750, 50, 1000, 800},
        {1750, 50, 1750, 950},
        {200, 20, 400, 300},
        {300, 20, 270, 700},
        {400, 20, 800, 450},
        {500, 20, 1500, 600},
        {500, 20, 1500, 250},
        {400, 20, 2100, 325},
        {450, 20, 2800, 750},
        {350, 20, 2800, 450}
    };

    int infoParedes[4][3] = {
        {500, 0, 500}, 
        {200, 1000, 800},
        {200, 1750, 800},
        {500, 3500, 500}
    };

    listaDeEntidades.append(ptrJogador);

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
            true, false, true
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
    criaMinotauro(2500, 600);

    planoDeFundo = new BackgroundManager("medieval_castle/background.png");
}

Fase2::~Fase2() {

}

void Fase2::trocaEstado(int opcao) {
    if(!(ptrJogador->getVivo())) 
        ptrJogo->irParaMenu();
    else if (gerenciadorColisoes->getVetorInimigos().empty()) 
        ptrJogo->irParaMenu();
}

void Fase2::criaMinotauro(int posX, int posY) {
    Minotauro *novoMinotauro = new Minotauro(posX, posY - 50);
    if (novoMinotauro != nullptr)
        listaDeEntidades.append(novoMinotauro),
        gerenciadorColisoes->addInimigo(novoMinotauro);
        criaProjetil(novoMinotauro);
}

void Fase2::criaProjetil(Minotauro* ptrMino) {
    Projetil *novoProjetil = new Projetil(ptrMino);
    if (novoProjetil != nullptr)
        listaDeEntidades.append(novoProjetil),
        gerenciadorColisoes->setProjetil(novoProjetil);
}