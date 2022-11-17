#include "../Includes/jogo.hpp"
#include "../Includes/ente.hpp"
#include "../Includes/menu.hpp"
#include "../Includes/Fases/fase1.hpp"
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
}

void Jogo::irParaFase1() {
    if (estadoAntigo)
        delete estadoAntigo;
    estadoAntigo = estadoAtual;
    estadoAtual = new Fase1(gerenciadorColisoes, gerenciadorEventos, &cj, this);
}

void Jogo::irParaMenu() {
    if (estadoAntigo)
        delete estadoAntigo;
    estadoAntigo = estadoAtual;

    estadoAtual = new Menu(gerenciadorEventos, this);
}