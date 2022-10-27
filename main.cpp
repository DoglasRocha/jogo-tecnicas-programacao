//
// Created by doglasrocha on 10/6/22.
//
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/

    int frame = 1;
    sf::Texture textura1, textura2, textura3;
    sf::Texture texturaCJ;
    if (!textura1.loadFromFile("texturas/narigudo.png") ||
        !textura2.loadFromFile("texturas/narigudo2.png") ||
        !textura3.loadFromFile("texturas/narigudo3.png") ||
        !texturaCJ.loadFromFile("texturas/cj_gordo.png")
        ) 
    {
        std::cout << "Não possivel carregar a textura." << std::endl;
        return 0;
    }


    sf::Sprite narigudo;
    sf::Sprite CJ;
    sf::FloatRect BorderColl(0, 0, 1000, 1000);
    narigudo.setTexture(textura1);
    //narigudo.setTextureRect(IntRect(10, 10, 500, 500));
    CJ.setTexture(texturaCJ);
    //narigudo.scale(sf::Vector2f(1,.5));

    int velX = 0;
    int velY = 0;
    int velXC = 0;
    int velYC = 0;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case (Keyboard::D):
                        velX = 1;
                        break;

                    case (Keyboard::A):
                        velX = -1;
                        break;

                    case (Keyboard::W):
                        velY = -1;
                        break;

                    case (Keyboard::S):
                        velY = 1;
                        break;

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
                    case (Keyboard::D):
                        velX = 0;
                        break;

                    case (Keyboard::A):
                        velX = 0;
                        break;

                    case (Keyboard::W):
                        velY = 0;
                        break;

                    case (Keyboard::S):
                        velY = 0;
                        break;

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

        sf::FloatRect BlobPosition = narigudo.getGlobalBounds();
        sf::FloatRect CJBounds = CJ.getGlobalBounds();
        BlobPosition.left += velX;
        BlobPosition.top += velY;
        CJBounds.left += velXC;
        CJBounds.top += velYC;
        
        // if (BorderColl.intersects(BlobPosition))
        if (BlobPosition.top >= 0 && (BlobPosition.top + BlobPosition.height) <= 1000 
            && BlobPosition.left >= 0 && (BlobPosition.left + BlobPosition.width) <= 1000)
        {
            narigudo.move(velX, velY);
        }
        if (CJBounds.top >= 0 && (CJBounds.top + CJBounds.height) <= 1000 
            && CJBounds.left >= 0 && (CJBounds.left + CJBounds.width) <= 1000)
        {
            CJ.move(velXC, velYC);
        }

        window.clear();
        if (!(frame % 3))
            narigudo.setTexture(textura3);
        else if (!(frame % 2))
            narigudo.setTexture(textura2);
        else
            narigudo.setTexture(textura1);
        window.draw(narigudo);
        window.draw(CJ);
        sf::sleep(sf::milliseconds(5));
        window.display();
        frame++;
    }

    return 0;
}
