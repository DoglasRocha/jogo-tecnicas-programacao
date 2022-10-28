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
    sprite.move(velX, velY);
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
