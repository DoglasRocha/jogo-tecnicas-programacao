#include "../../../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
#include "../../../../Includes/Gerenciadores/gerenciador_grafico.hpp"

using entidades::personagens::inimigos::Narigudo;

Narigudo::Narigudo() {
    frame = velX = velY = 0;
    sentido = "ESQUERDA";
    texturas[0].loadFromFile("texturas/narigudo.png");
    texturas[1].loadFromFile("texturas/narigudo2.png");
    texturas[2].loadFromFile("texturas/narigudo3.png");
    sprite.setTexture(texturas[frame % 3]);
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setPosition(200, 200);
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
};

Narigudo::~Narigudo() {}

void Narigudo::desenhar(RenderWindow *window) {
    window->draw(sprite);
    frame++;
    sprite.setTexture(texturas[frame % 3]);
}

void Narigudo::mover() {
    sprite.move(velX, velY);
}

void Narigudo::setVelX(int novaVel) {
    velX = novaVel;
}

void Narigudo::setVelY(int novaVel) {
    velY = novaVel;
}

int Narigudo::getVelX()
{
    return velX;
}

int Narigudo::getVelY() {
    return velY;
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
