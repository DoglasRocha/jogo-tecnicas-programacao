#include "../Includes/jogo.hpp"
#include "../Includes/Entidades/Obstaculos/plataforma.hpp"
#include "../Includes/ente.hpp"

using namespace Gerenciadores;
using namespace entidades::personagens;
using namespace sf;
using namespace entidades::obstaculos;
GerenciadorGrafico *GerenciadorGrafico::instance = nullptr;
GerenciadorColisoes *GerenciadorColisoes::instance = nullptr;
GerenciadorEventos *GerenciadorEventos::instance = nullptr;
GerenciadorGrafico *Ente::ptrGG = nullptr;

Jogo::Jogo()
{
	gerenciadorGrafico = GerenciadorGrafico::getInstance();
    gerenciadorColisoes = GerenciadorColisoes::getInstance();
    gerenciadorEventos = GerenciadorEventos::getInstance();
    gerenciadorEventos->setGerenciadorGrafico(gerenciadorGrafico);
    Ente::setGerenciadorGrafico(gerenciadorGrafico);
    gerenciadorColisoes->setJogador(&cj);
    Fase1 fase1(gerenciadorColisoes, gerenciadorEventos, &cj);
    Menu menu(gerenciadorEventos);
    
    while (gerenciadorGrafico->verificaJanelaAberta())
    {
        gerenciadorGrafico->limpaJanela();
        fase1.executar();
        fase1.gerencia_colisoes();
        sleep(milliseconds(20));
        gerenciadorGrafico->mostraElementos();
    }
}

Jogo::~Jogo() {

}
