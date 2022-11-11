#include "../../Includes/Fases/fase.hpp"

using fases::Fase;
using namespace Gerenciadores;

Fase::Fase(Jogador *ptrJogador_) : Ente()
{
    ptrJogador = ptrJogador_;
}

Fase::~Fase() {}

void Fase::gerencia_colisoes()
{
	gerenciadorColisoes->executar();
}

void Fase::executar() {
    processaEventos();
    desenhar(gerenciadorGrafico);
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
