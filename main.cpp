//
// Created by doglasrocha on 10/6/22.
//
#include <SFML/include/Graphics.hpp>
#include <iostream>
using namespace std;

int main(void)
{
    cout << "MORRA NARIGUDO" << endl;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/

    sf::Texture textura;
    if (!textura.loadFromFile("texturas/narigudo.png")) 
    {
        std::cout << "Não possivel carregar a textura." << std::endl;
        return 0;
    }

    sf::Sprite narigudo;
    sf::Sprite narigudo2;
    narigudo.setTexture(textura);
    narigudo2.setTexture(textura);
    narigudo.scale(sf::Vector2f(1,.5));
    narigudo2.scale(sf::Vector2f(.5,1));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::FloatRect BorderColl(0, 0, 1000, 1000);
        sf::Vector2f BlobPosition = narigudo.getPosition();
        bool CheckBorderColl = BorderColl.contains(BlobPosition);
        //if (CheckBorderColl)
        //{
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                narigudo.move(1, 0);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                narigudo.move(-1, 0);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                narigudo.move(0, -1);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                narigudo.move(0, 1);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                narigudo2.move(1, 0);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                narigudo2.move(-1, 0);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                narigudo2.move(0, -1);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                narigudo2.move(0, 1);
        //}

        window.clear();
        window.draw(narigudo);
        window.draw(narigudo2);
        // shape.move(1, 1);
        sf::sleep(sf::milliseconds(5));
        window.display();
    }

    return 0;
}
