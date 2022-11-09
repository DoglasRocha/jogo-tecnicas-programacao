#include "../Includes/jogo.hpp"
#include "../Includes/Entidades/Obstaculos/plataforma.hpp"

using namespace Gerenciadores;
using namespace entidades::personagens;
using namespace sf;
using namespace entidades::obstaculos;
GerenciadorGrafico *GerenciadorGrafico::instance = nullptr;
GerenciadorColisoes *GerenciadorColisoes::instance = nullptr;
GerenciadorEventos *GerenciadorEventos::instance = nullptr;

Jogo::Jogo()
{
	janela = GerenciadorGrafico::getGerenciadorGrafico();
    gerenciadorColisoes = GerenciadorColisoes::getInstance();
    gerenciadorEventos = GerenciadorEventos::getInstance();
    gerenciadorEventos->setGerenciadorGrafico(janela);
    gerenciadorColisoes->setJogador(&cj);
    Fase1 fase1(gerenciadorColisoes, janela, gerenciadorEventos, &cj);
    Menu menu(janela, gerenciadorEventos);
    
    while (janela->verificaJanelaAberta())
    {
        janela->limpaJanela();
        fase1.executar();
        fase1.gerencia_colisoes();
        sleep(milliseconds(20));
        janela->mostraElementos();
    }
}

Jogo::~Jogo() {

}
