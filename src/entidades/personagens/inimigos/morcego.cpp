#include "../../../../Includes/Entidades/Personagens/Inimigos/morcego.hpp"

entidades::personagens::Morcego::Morcego() :
entidades::personagens::Inimigo() {
    sentido = "ESQUERDA";
    num_vidas = 40;
    ataque = 10;
    forcaAsas = rand() % 5;
    velY = 1;

    carregarTexturas("Sprites/morcego/morcego", 0, 3);
    noAtual = listaTexturas.begin();
    sprite.setTexture(*(noAtual->getDado()));
    x = y = 400;
    setOriginToCenter();
    escalarSprite(2, 2);

}

entidades::personagens::Morcego::Morcego(int x, int y) :
Morcego() {
    this->x = x, this->y = y;
    velY = -1;
    sprite.setPosition(x, y);
}

entidades::personagens::Morcego::~Morcego() {
    ListaTexturas::Node *tmp;
    for (noAtual = listaTexturas.begin(); noAtual != listaTexturas.end(); noAtual = tmp) {
        tmp = noAtual->getNext();
        delete noAtual->getDado();
    }
    delete noAtual->getDado();
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
    return ataque + forcaAsas;
}

void entidades::personagens::Morcego::lentidao(){

}

void entidades::personagens::Morcego::queimar(){

}

void entidades::personagens::Morcego::moverY() {
    if (y < 100)
        velY = 1, empuxo = 0;
    
    animar();
    sprite.move(0.f, (float)velY);
    y += velY;
}

void entidades::personagens::Morcego::setEmpuxo(int novoEmpuxo) {
    
}
