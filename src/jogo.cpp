#include "../Includes/jogo.hpp"
#include "../Includes/Entidades/Obstaculos/plataforma.hpp"

using namespace Gerenciadores;
using namespace entidades::personagens;
using namespace sf;
using namespace entidades::obstaculos;
GerenciadorGrafico *GerenciadorGrafico::instance = nullptr;
GerenciadorColisoes *GerenciadorColisoes::instance = nullptr;

Jogo::Jogo()
{
	janela = GerenciadorGrafico::getGerenciadorGrafico();
    gerenciadorColisoes = GerenciadorColisoes::getInstance();
    gerenciadorColisoes->setJogador(&cj);
    Plataforma plataforma(1400, 100, 0, 900);
    Plataforma plataforma1(100, 1400, 0, 0);
    Plataforma plataforma2(100, 1400, 1300, 0);
    Plataforma plataforma3(1400, 100, 0, 0);

    gerenciadorColisoes->addInimigo(&narigudo);
    gerenciadorColisoes->addObstaculo(&plataforma);
    gerenciadorColisoes->addObstaculo(&plataforma1);
    gerenciadorColisoes->addObstaculo(&plataforma2);
    gerenciadorColisoes->addObstaculo(&plataforma3);
    
    while (janela->verificaJanelaAberta())
    {
        Event event;
        while (janela->getWindow()->pollEvent(event))
        {
            if (event.type == Event::Closed)
                janela->fechaJanela();

            narigudo.processarEventos(event);
            cj.processarEventos(event);
        }

        janela->limpaJanela();
        gerenciadorColisoes->executar();
        janela->desenhaElemento(*plataforma.getShape());
        janela->desenhaElemento(*plataforma1.getShape());
        janela->desenhaElemento(*plataforma2.getShape());
        janela->desenhaElemento(*plataforma3.getShape());
        janela->desenhaElemento(*cj.getSprite());
        janela->desenhaElemento(*narigudo.getSprite());
        sleep(milliseconds(20));
        janela->mostraElementos();
    }
}

Jogo::~Jogo() {
}
