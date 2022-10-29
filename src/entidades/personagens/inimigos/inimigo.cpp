#include "../../../../Includes/Entidades/Personagens/Inimigos/inimigo.hpp"
#include "../../../../Includes/Entidades/Personagens/personagem.hpp"

using entidades::personagens::inimigos::Inimigo;

void Inimigo::setSprite(sf::Texture textura)
{
    sprite.setTexture(textura);
}

entidades::personagens::inimigos::Inimigo::Inimigo() :
entidades::personagens::Personagem(),
tempoAnimacao(sf::milliseconds(125)){

}

entidades::personagens::inimigos::Inimigo::~Inimigo() {

}

void entidades::personagens::inimigos::Inimigo::animar() {
    if (relogioAnimacao.getElapsedTime() >= tempoAnimacao) {
        noAtual = noAtual->getNext();
        sprite.setTexture(*(noAtual->getDado()));
        relogioAnimacao.restart();
    }
}

void entidades::personagens::inimigos::Inimigo::resetAnimacao() {
    noAtual = listaTexturas.begin();
    sprite.setTexture(*(noAtual->getDado()));
}
