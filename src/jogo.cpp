#include "../Includes/jogo.hpp"
#include "../Includes/ente.hpp"
#include "../Includes/menu.hpp"
#include "../Includes/menu_jogadores.hpp"
#include "../Includes/Fases/fase1.hpp"
#include "../Includes/Fases/fase2.hpp"
#include <cstdlib>
#include <ctime>

using namespace Gerenciadores;
using namespace entidades::personagens;
using namespace sf;
using namespace std;

GerenciadorGrafico *GerenciadorGrafico::instance = nullptr;
GerenciadorColisoes *GerenciadorColisoes::instance = nullptr;
GerenciadorEventos *GerenciadorEventos::instance = nullptr;
GerenciadorGrafico *Ente::ptrGG = nullptr;

Jogo::Jogo()
{
    srand(time(NULL));

	gerenciadorGrafico = GerenciadorGrafico::getInstance();
    gerenciadorColisoes = GerenciadorColisoes::getInstance();
    gerenciadorEventos = GerenciadorEventos::getInstance();
    gerenciadorEventos->setGerenciadorGrafico(gerenciadorGrafico);
    Ente::setGerenciadorGrafico(gerenciadorGrafico);
    gerenciadorColisoes->setJogador(&cj);
    gerenciadorColisoes->setJogador2(&smoke);
    estadoAtual = new Menu(gerenciadorEventos, this);
    estadoAntigo = nullptr;
    
    while (gerenciadorGrafico->verificaJanelaAberta())
    {
        gerenciadorGrafico->limpaJanela();
        estadoAtual->executar();
        sleep(milliseconds(20));
        gerenciadorGrafico->mostraElementos();
    }
}

Jogo::~Jogo() {
    GerenciadorEventos::deleteInstance();
    GerenciadorColisoes::deleteInstance();
    GerenciadorGrafico::deleteInstance();
    delete estadoAntigo;
    delete estadoAtual;
}

void Jogo::irParaFase1(bool coop) {
    cj.reset();
    smoke.reset();
    gerenciadorColisoes->limparListas();
    if (estadoAntigo) {
        delete estadoAntigo;
        estadoAntigo = nullptr;
    }
    estadoAntigo = estadoAtual;
    if(coop) estadoAtual = new Fase1(gerenciadorColisoes, gerenciadorEventos, &cj, this, &smoke);
    else estadoAtual = new Fase1(gerenciadorColisoes, gerenciadorEventos, &cj, this);
}

void Jogo::irParaFase2(bool coop) {
    cj.reset();
    smoke.reset();
    gerenciadorColisoes->limparListas();
    if (estadoAntigo) {
        delete estadoAntigo;
        estadoAntigo = nullptr;
    }
    estadoAntigo = estadoAtual;
    if(coop) estadoAtual = new Fase2(gerenciadorColisoes, gerenciadorEventos, &cj, this, &smoke);
    else estadoAtual = new Fase2(gerenciadorColisoes, gerenciadorEventos, &cj, this);
}

void Jogo::irParaMenu() {
    cj.reset();
    smoke.reset();
    gerenciadorColisoes->limparListas();
    if (estadoAntigo) {
        delete estadoAntigo;
        estadoAntigo = nullptr;
    }
    estadoAntigo = estadoAtual;
    estadoAtual = new Menu(gerenciadorEventos, this);
}

void Jogo::irParaMenuJogadores(int fase) {
    gerenciadorColisoes->limparListas();
    if (estadoAntigo) {
        delete estadoAntigo;
        estadoAntigo = nullptr;
    }
    estadoAntigo = estadoAtual;
    estadoAtual = new MenuJogadores(gerenciadorEventos, this, fase);
}