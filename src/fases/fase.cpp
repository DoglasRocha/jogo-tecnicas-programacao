#include "../../Includes/Fases/fase.hpp"

using fases::Fase;

Fase::Fase(GerenciadorColisoes *gC,
           GerenciadorGrafico *gG,
           GerenciadorEventos *gE,
           Jogador *ptrJogador_)
{
    gerenciadorColisoes = gC;
    gerenciadorGrafico = gG;
    gerenciadorEventos = gE;
    ptrJogador = ptrJogador_;
}

Fase::~Fase() {}

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

void fases::Fase::processaEventos() {
    Event evento;
    while (gerenciadorEventos->getEvento(evento)) {

        if (evento.type == Event::Closed)
            gerenciadorGrafico->fechaJanela();

        ptrJogador->processarEventos(evento);
    }
}
