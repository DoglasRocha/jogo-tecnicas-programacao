#include "../../../../Includes/Entidades/Personagens/Inimigos/inimigo.hpp"
#include "../../../../Includes/Entidades/Personagens/personagem.hpp"

using entidades::personagens::inimigos::Inimigo;

void Inimigo::setSprite(sf::Texture textura)
{
    sprite.setTexture(textura);
}

entidades::personagens::inimigos::Inimigo::Inimigo() :
entidades::personagens::Personagem() {

}

entidades::personagens::inimigos::Inimigo::~Inimigo() {

}
