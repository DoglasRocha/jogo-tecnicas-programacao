#include "../../Includes/Fases/fase.hpp"

using fases::Fase;
using namespace Gerenciadores;

Fase::Fase(Jogador *ptrJogador_) : Ente::Ente(GerenciadorGrafico *gG,GerenciadorEventos *gE, GerenciadorColisoes *gC)
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
    desenhar();
}

void fases::Fase::desenhar() {
    planoDeFundo->desenhar();

    ListaEntidades::Node *node;
    for (node = listaDeEntidades.begin();
         node != listaDeEntidades.end();
         node = node->getNext()) {
        node->getDado()->desenhar();
    }
    node->getDado()->desenhar();
}

void fases::Fase::processaEventos() {
    Event evento;
    while (gerenciadorEventos->getEvento(evento)) {

        if (evento.type == Event::Closed)
            gerenciadorGrafico->fechaJanela();

        ptrJogador->processarEventos(evento);
    }
}
