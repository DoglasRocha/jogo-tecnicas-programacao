//
// Created by doglasrocha on 10/6/22.
//
#include <SFML/Graphics.hpp>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::FloatRect BorderColl(0, 0, 1000, 1000);
        sf::Vector2f BlobPosition = shape.getPosition();
        bool CheckBorderColl = BorderColl.contains(BlobPosition);
        if (CheckBorderColl)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                shape.move(1, 0);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                shape.move(-1, 0);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                shape.move(0, -1);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                shape.move(0, 1);
        }

        window.clear();
        window.draw(shape);
        // shape.move(1, 1);
        sf::sleep(sf::milliseconds(5));
        window.display();
    }

    return 0;
}
