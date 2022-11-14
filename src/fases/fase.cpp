#include "../../Includes/Fases/fase.hpp"
#include "../../Includes/jogo.hpp"

using fases::Fase;

Fase::Fase(GerenciadorColisoes *gC,
           GerenciadorEventos *gE,
           Jogador *ptrJogador_,
           Jogo *ptrJogo) :
           Estado(ptrJogo)
{
    gerenciadorColisoes = gC;
    gerenciadorEventos = gE;
    ptrJogador = ptrJogador_;
}

Fase::~Fase() {}

void Fase::gerencia_colisoes()
{
	gerenciadorColisoes->executar();
}

void Fase::executar() {
    gerencia_colisoes();
    processaEventos();
    desenhar();
}

void fases::Fase::desenhar() {
    planoDeFundo->desenhar();
    listaDeEntidades.desenhaEntidades();
}

void fases::Fase::processaEventos() {
    Event evento;
    while (gerenciadorEventos->getEvento(evento)) {

        if (evento.type == Event::Closed)
            ptrGG->fechaJanela();

        ptrJogador->processarEventos(evento);
    }
}
