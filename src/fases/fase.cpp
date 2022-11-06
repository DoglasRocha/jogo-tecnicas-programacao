#include "../../Includes/Fases/fase.hpp"

using fases::Fase;

Fase::Fase(GerenciadorColisoes *gC,
           GerenciadorGrafico *gG,
           Jogador *ptrJogador_)
{
    gerenciadorColisoes = gC;
    gerenciadorGrafico = gG;
    ptrJogador = ptrJogador_;
}

Fase::~Fase()
{

}

void Fase::gerencia_colisoes()
{
	gerenciadorColisoes->executar();
}

void fases::Fase::executar() {

}

void fases::Fase::desenhar(GerenciadorGrafico *gG) {
    planoDeFundo->desenhar(gerenciadorGrafico);

    ListaEntidades::Node *node;
    for (node = listaDeEntidades.begin();
         node != listaDeEntidades.end();
         node = node->getNext()) {
        node->getDado()->desenhar(gerenciadorGrafico);
    }
    node->getDado()->desenhar(gerenciadorGrafico);
}
