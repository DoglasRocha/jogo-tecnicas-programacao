#include "../../../../Includes/Entidades/Personagens/Inimigos/inimigo.hpp"
#include "../../../../Includes/Entidades/Personagens/personagem.hpp"

using entidades::personagens::Inimigo;

void Inimigo::setSprite(sf::Texture textura)
{
    sprite.setTexture(textura);
}

entidades::personagens::Inimigo::Inimigo() :
entidades::personagens::Personagem(),
tempoAnimacao(sf::milliseconds(125)){

}

entidades::personagens::Inimigo::~Inimigo() {

}

void entidades::personagens::Inimigo::animar() {
    if (relogioAnimacao.getElapsedTime() >= tempoAnimacao) {
        noAtual = noAtual->getNext();
        sprite.setTexture(*(noAtual->getDado()));
        relogioAnimacao.restart();
    }
}

void entidades::personagens::Inimigo::resetAnimacao() {
    noAtual = listaTexturas.begin();
    sprite.setTexture(*(noAtual->getDado()));
}
