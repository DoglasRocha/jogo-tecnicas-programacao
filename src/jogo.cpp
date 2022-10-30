#include "../Includes/jogo.hpp"

using namespace Gerenciadores;
using namespace entidades::personagens::inimigos;
using namespace sf;
GerenciadorGrafico *GerenciadorGrafico::instance = nullptr;
GerenciadorColisoes *GerenciadorColisoes::instance = nullptr;

Jogo::Jogo()
{
	janela = GerenciadorGrafico::getInstance();
    gerenciadorColisoes = GerenciadorColisoes::getInstance();
    RenderWindow *window = janela->getWindow();

    Narigudo narigudo;
    CarlosJohnson cj;

    gerenciadorColisoes->setPersonagens(&narigudo, &cj);
    
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
        sleep(milliseconds(5));
        window->display();
    }
}

Jogo::~Jogo() {}
