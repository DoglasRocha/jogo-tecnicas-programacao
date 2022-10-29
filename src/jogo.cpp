#include "../Includes/jogo.hpp"
#include "../Includes/menu.hpp"
#include "../Includes/Gerenciadores/gerenciador_colisoes.hpp"
#include "../Includes/Gerenciadores/gerenciador_grafico.hpp"
#include "../Includes/Entidades/Obstaculos/obstaculoA.hpp"
#include "../Includes/Entidades/Obstaculos/obstaculoB.hpp"
#include "../Includes/Entidades/Personagens/jogador.hpp"
#include "../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
#include "../Includes/Entidades/Personagens/Inimigos/carlosjohnson.hpp"
#include "../Includes/Fases/fase1.hpp"
#include "../Includes/Fases/fase2.hpp"
#include <iostream>

using namespace Gerenciadores;
using namespace entidades::personagens::inimigos;
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
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            narigudo.processarEventos(event);
            cj.processarEventos(event);
        }

        gerenciadorColisoes->executar();
        /*sf::FloatRect BlobPosition = narigudo.getSprite()->getGlobalBounds();
        sf::FloatRect CJBounds = cj.getSprite()->getGlobalBounds();
        BlobPosition.left += narigudo.getVelX();
        BlobPosition.top += narigudo.getVelY();
        CJBounds.left += cj.getVelX();
        CJBounds.top += cj.getVelY();

        if (BlobPosition.top >= 0 && (BlobPosition.top + BlobPosition.height) <= 1400
            && BlobPosition.left >= 0 && (BlobPosition.left + BlobPosition.width) <= 1400)
        {
            narigudo.mover();
        }
        if (CJBounds.top >= 0 && (CJBounds.top + CJBounds.height) <= 1400
            && CJBounds.left >= 0 && (CJBounds.left + CJBounds.width) <= 1400)
        {
            cj.mover();
        }*/

        window->clear();
        narigudo.desenhar(window);
        cj.desenhar(window);
        sf::sleep(sf::milliseconds(5));
        window->display();
    }
}

Jogo::~Jogo() {}
