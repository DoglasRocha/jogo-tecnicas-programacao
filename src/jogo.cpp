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

Jogo::Jogo()
{
	janela = GerenciadorGrafico::getInstance();
    RenderWindow *window = janela->getWindow();

    Narigudo narigudo;

    sf::Texture texturaCJ;
    if (!texturaCJ.loadFromFile("texturas/cj_gordo.png"))
    {
        std::cout << "Não possivel carregar a textura." << std::endl;
    }

    sf::Sprite CJ;
    sf::FloatRect BorderColl(0, 0, 1000, 1000);
    CJ.setTexture(texturaCJ);
    //narigudo.scale(sf::Vector2f(1,.5));

    int velXC = 0;
    int velYC = 0;
    
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            narigudo.processarEventos(event);
            if (event.type == Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case (Keyboard::Right):
                        velXC = 1;
                        break;

                    case (Keyboard::Left):
                        velXC = -1;
                        break;

                    case (Keyboard::Up):
                        velYC = -1;
                        break;

                    case (Keyboard::Down):
                        velYC = 1;
                        break;
                }
            }

            if (event.type == Event::KeyReleased)
            {
                switch (event.key.code)
                {
                    case (Keyboard::Right):
                        velXC = 0;
                        break;

                    case (Keyboard::Left):
                        velXC = 0;
                        break;

                    case (Keyboard::Up):
                        velYC = 0;
                        break;

                    case (Keyboard::Down):
                        velYC = 0;
                        break;
                }
            }
        }

        sf::FloatRect BlobPosition = narigudo.getSprite()->getGlobalBounds();
        sf::FloatRect CJBounds = CJ.getGlobalBounds();
        BlobPosition.left += narigudo.getVelX();
        BlobPosition.top += narigudo.getVelY();
        CJBounds.left += velXC;
        CJBounds.top += velYC;
        
        // if (BorderColl.intersects(BlobPosition))
        if (BlobPosition.top >= 0 && (BlobPosition.top + BlobPosition.height) <= 1000 
            && BlobPosition.left >= 0 && (BlobPosition.left + BlobPosition.width) <= 1000)
        {
            narigudo.mover();
        }
        if (CJBounds.top >= 0 && (CJBounds.top + CJBounds.height) <= 1000 
            && CJBounds.left >= 0 && (CJBounds.left + CJBounds.width) <= 1000)
        {
            CJ.move(velXC, velYC);
        }

        window->clear();
        narigudo.desenhar(window);
        window->draw(CJ);
        sf::sleep(sf::milliseconds(5));
        window->display();
    }
}

Jogo::~Jogo() {}
