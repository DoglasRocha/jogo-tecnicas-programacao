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
    //Plataforma plataforma(1400, 100, 0, 900);

    Narigudo narigudo;
    CarlosJohnson cj;

    gerenciadorColisoes->addInimigo(&narigudo);
    gerenciadorColisoes->addInimigo(&cj);
    
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
        janela->desenhaElemento(*cj.getSprite());
        janela->desenhaElemento(*narigudo.getSprite());
        //plataforma.desenhar(window);
        sleep(milliseconds(20));
        janela->mostraElementos();
    }
}

Jogo::~Jogo() {}
