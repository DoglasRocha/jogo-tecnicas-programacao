#include "../../../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
#include "../../../../Includes/Gerenciadores/gerenciador_grafico.hpp"

using entidades::personagens::inimigos::Narigudo;

Narigudo::Narigudo() :
entidades::personagens::inimigos::Inimigo() {
    frame = 0;
    sentido = "ESQUERDA";
    texturas[0].loadFromFile("texturas/narigudo.png");
    texturas[1].loadFromFile("texturas/narigudo2.png");
    texturas[2].loadFromFile("texturas/narigudo3.png");
    sprite.setTexture(texturas[frame % 3]);

    sprite.setPosition(200, 200);
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
};

Narigudo::~Narigudo() {}

void Narigudo::desenhar(RenderWindow *window) {
    window->draw(sprite);
    frame++;
    sprite.setTexture(texturas[frame % 3]);
}

Sprite *Narigudo::getSprite() {
    return &sprite;
}

std::string Narigudo::getSentido() {
    return sentido;
}

void Narigudo::setSentido(std::string novoSentido) {
    sentido = novoSentido;
}

void Narigudo::processarEventos(Event evento) {
    if (evento.type == Event::KeyPressed) {
        switch (evento.key.code)
        {
            case (Keyboard::D):
                if (sentido != "DIREITA") {
                    sprite.scale(-1.f, 1.f);
                    sentido = "DIREITA";
                }
                velX = 1;
                break;

            case (Keyboard::A):
                if (sentido != "ESQUERDA") {
                    sprite.scale(-1.f, 1.f);
                    sentido = "ESQUERDA";
                }
                velX = -1;
                break;

            case (Keyboard::W):
                velY = -1;
                break;

            case (Keyboard::S):
                velY = 1;
                break;
        }
    }

    else if (evento.type == Event::KeyReleased) {
        switch (evento.key.code)
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
        }
    }
}

void entidades::personagens::inimigos::Narigudo::mover() {
    sprite.move(velX, velY);
}
