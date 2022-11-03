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
	janela = GerenciadorGrafico::getInstance();
    gerenciadorColisoes = GerenciadorColisoes::getInstance();
    RenderWindow *window = janela->getWindow();
    //Plataforma plataforma(1400, 100, 0, 900);

    Narigudo narigudo;
    CarlosJohnson cj;

    gerenciadorColisoes->addInimigo(&narigudo);
    gerenciadorColisoes->addInimigo(&cj);
    
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();

            narigudo.processarEventos(event);
            cj.processarEventos(event);
        }

        gerenciadorColisoes->executar();

        window->clear();
        narigudo.desenhar(window);
        cj.desenhar(window);
        //plataforma.desenhar(window);
        sleep(milliseconds(20));
        window->display();
    }
}

Jogo::~Jogo() {}
