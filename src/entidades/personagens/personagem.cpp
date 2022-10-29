#include "../../../Includes/Entidades/Personagens/personagem.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

entidades::personagens::Personagem::Personagem() {
    velX = velY = 0;
}

entidades::personagens::Personagem::~Personagem() {

}

void entidades::personagens::Personagem::mover() {
    sprite.move((float)velX, (float)velY);
}

void entidades::personagens::Personagem::setVelX(int novaVel) {
    velX = novaVel;
}

void entidades::personagens::Personagem::setVelY(int novaVel) {
    velY = novaVel;
}

int entidades::personagens::Personagem::getVelX() {
    return velX;
}

int entidades::personagens::Personagem::getVelY() {
    return velY;
}

Sprite *entidades::personagens::Personagem::getSprite() {
    return &sprite;
}

std::string entidades::personagens::Personagem::getSentido() {
    return sentido;
}

void entidades::personagens::Personagem::setSentido(std::string novoSentido) {
    sentido = novoSentido;
}

void entidades::personagens::Personagem::setOriginToCenter() {
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
}
