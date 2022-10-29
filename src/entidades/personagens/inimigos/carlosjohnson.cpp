#include "../../../../Includes/Entidades/Personagens/Inimigos/carlosjohnson.hpp"

entidades::personagens::inimigos::CarlosJohnson::CarlosJohnson() :
entidades::personagens::inimigos::Inimigo() {
    sentido = "ESQUERDA";
    textura.loadFromFile("texturas/cj_gordo.png");
    sprite.setTexture(textura);

    sprite.setPosition(400, 400);
    setOriginToCenter();
}

entidades::personagens::inimigos::CarlosJohnson::~CarlosJohnson() {

}

void entidades::personagens::inimigos::CarlosJohnson::desenhar(RenderWindow *window) {
    window->draw(sprite);
}

void entidades::personagens::inimigos::CarlosJohnson::processarEventos(Event evento) {
    if (evento.type == Event::KeyPressed)
    {
        switch (evento.key.code)
        {
            case (Keyboard::Right):
                if (sentido != "DIREITA") {
                    sprite.scale(-1.f, 1);
                    sentido = "DIREITA";
                }
                velX = 1;
                break;

            case (Keyboard::Left):
                if (sentido != "ESQUERDA") {
                    sprite.scale(-1.f, 1);
                    sentido = "ESQUERDA";
                }
                velX = -1;
                break;

            case (Keyboard::Up):
                velY = -1;
                break;

            case (Keyboard::Down):
                velY = 1;
                break;
        }
    }

    if (evento.type == Event::KeyReleased)
    {
        switch (evento.key.code)
        {
            case (Keyboard::Right):
                velX = 0;
                break;

            case (Keyboard::Left):
                velX = 0;
                break;

            case (Keyboard::Up):
                velY = 0;
                break;

            case (Keyboard::Down):
                velY = 0;
                break;
        }
    }
}
