#include "../../Includes/Fases/fase.hpp"
#include "../../Includes/jogo.hpp"
#include "../../Includes/Entidades/Obstaculos/plataforma.hpp"
#include "../../Includes/Entidades/Obstaculos/parede.hpp"
#include "../../Includes/Entidades/Obstaculos/arbusto.hpp"
#include "../../Includes/Entidades/Obstaculos/fogo.hpp"
#include "../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
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
    listaDeEntidades.append(novaPlataforma);
    gerenciadorColisoes->addObstaculo(novaPlataforma);
}

void Fase::criaParede(int tamY, int posX, int posY) {
    Parede *novaParede = new Parede(32, tamY, posX, posY);
    listaDeEntidades.append(novaParede);
    gerenciadorColisoes->addObstaculo(novaParede);
}

void Fase::criaNarigudo(int posX, int posY) {
    Narigudo *novoNarigudo = new Narigudo(posX, posY - 50);
    listaDeEntidades.append(novoNarigudo);
    gerenciadorColisoes->addInimigo(novoNarigudo);
}

void Fase::criaArbusto(int posX, int posY) {
    Arbusto *novoArbusto = new Arbusto(posX, posY);
    listaDeEntidades.append(novoArbusto);
    gerenciadorColisoes->addObstaculo(novoArbusto);
}

void Fase::criaFogo(int posX, int posY) {
    Fogo *novoFogo = new Fogo(posX, posY);
    listaDeEntidades.append(novoFogo);
    gerenciadorColisoes->addObstaculo(novoFogo);
}

void Fase::criaPlataformaComAgregadosAleatorios(int tamX, int tamY, int posX, int posY,
    bool geraNarigudo, bool geraArbusto, bool geraFogo) 
{
    criaPlataforma(tamX, tamY, posX, posY);
    if (geraNarigudo && rand() % 2) {
        criaNarigudo(posX + (rand() % tamX), posY);
    }

    if (geraArbusto && rand() % 5) {
        criaArbusto(posX + (rand() % tamX), posY);
    }

    if (geraFogo && rand() % 2) {
        criaFogo(posX + (rand() % tamX), posY);
    }

}

void Fase::trocaEstado(int opcao)
{
    cout << "Teste" << endl;
    if(!(ptrJogador->getVivo())) ptrJogo->irParaMenu();
    else if (gerenciadorColisoes->getVetorInimigos().empty()) ptrJogo->irParaMenu();
}