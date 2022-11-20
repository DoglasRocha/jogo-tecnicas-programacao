#include "../../Includes/Fases/fase.hpp"
#include "../../Includes/jogo.hpp"
#include "../../Includes/Entidades/Obstaculos/plataforma.hpp"
#include "../../Includes/Entidades/Obstaculos/parede.hpp"
#include "../../Includes/Entidades/Obstaculos/arbusto.hpp"
#include "../../Includes/Entidades/Obstaculos/fogo.hpp"
#include "../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
#include "../../Includes/Entidades/Personagens/Inimigos/morcego.hpp"
#include <iostream>

using namespace entidades::obstaculos;
using namespace entidades::personagens;
using fases::Fase;
using namespace std;

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

Fase::~Fase() {
    delete planoDeFundo;
    gerenciadorColisoes->limparListas();
    listaDeEntidades.limparLista();
}

void Fase::gerencia_colisoes()
{
	gerenciadorColisoes->executar();
}

void Fase::executar() {
    gerencia_colisoes();
    processaEventos();
    trocaEstado();
    desenhar();
}

void Fase::desenhar() {
    planoDeFundo->desenhar();
    listaDeEntidades.desenhaEntidades();
    ptrJogador->desenhaBarraVida();
}

void Fase::processaEventos() {
    Event evento;
    while (gerenciadorEventos->getEvento(evento)) {

        if (evento.type == Event::Closed)
            ptrGG->fechaJanela();

        ptrJogador->processarEventos(evento);
    }
}

void Fase::criaPlataforma(int tamX, int tamY, int posX, int posY) {
    Plataforma *novaPlataforma = new Plataforma(tamX, tamY, posX, posY);
    if (novaPlataforma != nullptr)
        listaDeEntidades.append(novaPlataforma),
        gerenciadorColisoes->addObstaculo(novaPlataforma);
}

void Fase::criaParede(int tamY, int posX, int posY) {
    Parede *novaParede = new Parede(32, tamY, posX, posY);
    if (novaParede != nullptr)
        listaDeEntidades.append(novaParede),
        gerenciadorColisoes->addObstaculo(novaParede);
}

void Fase::criaNarigudo(int posX, int posY) {
    Narigudo *novoNarigudo = new Narigudo(posX, posY - 50);
    if (novoNarigudo != nullptr)
        listaDeEntidades.append(novoNarigudo),
        gerenciadorColisoes->addInimigo(novoNarigudo);
}

void Fase::criaArbusto(int posX, int posY) {
    Arbusto *novoArbusto = new Arbusto(posX, posY);
    if (novoArbusto != nullptr)
        listaDeEntidades.append(novoArbusto),
        gerenciadorColisoes->addObstaculo(novoArbusto);
}

void Fase::criaFogo(int posX, int posY) {
    Fogo *novoFogo = new Fogo(posX, posY);
    if (novoFogo != nullptr)
        listaDeEntidades.append(novoFogo),
        gerenciadorColisoes->addObstaculo(novoFogo);
}

void Fase::criaMorcego(int posX, int posY) {
    Morcego *novoMorcego = new Morcego(posX, posY);
    if (novoMorcego != nullptr)
        listaDeEntidades.append(novoMorcego),
        gerenciadorColisoes->addInimigo(novoMorcego);
}

void Fase::criaPlataformaComAgregadosAleatorios(int tamX, int tamY, int posX, int posY,
    bool geraNarigudo, bool geraArbusto, bool geraFogo) 
{
    criaPlataforma(tamX, tamY, posX, posY);
    if (geraNarigudo && rand() % 2) {
        criaNarigudo(posX + (rand() % (tamX - 100)), posY);
    }

    if (geraArbusto && rand() % 5) {
        criaArbusto(posX + (rand() % (tamX - 100)), posY);
    }

    if (geraFogo && rand() % 2) {
        criaFogo(posX + (rand() % (tamX - 100)), posY);
    }

}
