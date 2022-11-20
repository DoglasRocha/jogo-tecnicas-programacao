#include "../../../../Includes/Entidades/Personagens/Inimigos/morcego.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

entidades::personagens::Morcego::Morcego() :
entidades::personagens::Inimigo(2000) {
    pontos = 50;
    sentido = "ESQUERDA";
    num_vidas = 40;
    ataque = 20;
    forcaAsas = rand() % 5;
    velY = 1;

    carregarTexturas("Sprites/morcego/morcego", 0, 3);
    noAtual = listaTexturas.begin();
    sprite.setTexture(*(noAtual->getDado()));
    x = y = 400;
    setOriginToCenter();
    escalarSprite(3, 3);

}

entidades::personagens::Morcego::Morcego(const int x, const int y) :
Morcego() {
    this->x = x, this->y = y;
    velY = -1;
    sprite.setPosition(x, y);
}

entidades::personagens::Morcego::~Morcego() {
}

void entidades::personagens::Morcego::processarEventos(Event evento) {

}

void entidades::personagens::Morcego::colideX() {

}

void  entidades::personagens::Morcego::colideY() {
    velY = 0;
    if (!empuxo)
        empuxo = -2;
    else
        empuxo = 0;
}

int  entidades::personagens::Morcego::getAtaque() {
    if (relogioAtaque.getElapsedTime() >= tempoAtaque) {
        relogioAtaque.restart();
        return ataque + forcaAsas;
    }

    return 0;
}

void entidades::personagens::Morcego::lentidao(){

}

void entidades::personagens::Morcego::queimar(){

}

void entidades::personagens::Morcego::moverY() {
    if (y < 100)
        velY = 1, empuxo = 0;
    
    animar();

    if (velY <= -8)
        velY = -8;

    if (velY >= 8)
        velY = 8;

    sprite.move(0.f, (float)velY);
    y += velY;
}

void entidades::personagens::Morcego::setEmpuxo(const int novoEmpuxo) {
    
}
