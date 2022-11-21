#include "../../../../Includes/Entidades/Personagens/Inimigos/minotauro.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

entidades::personagens::Minotauro::Minotauro() :
entidades::personagens::Inimigo(2000) {
    pontos = 250;
    sentido = "DIREITA";
    num_vidas = 120;
    ataque = 35;
    desgasteChifres = (rand() % 2) + 1;

    carregarTexturas("Sprites/minotauro/minotauro", 0, 4);
    noAtual = listaTexturas.begin();
    sprite.setTexture(*(noAtual->getDado()));
    x = y = 400;
    setOriginToCenter();
    escalarSprite(5, 5);
    velX = 3;
}

entidades::personagens::Minotauro::Minotauro(const int x, const int y) :
Minotauro() {
    this->x = x, this->y = y;
    velY = -1;
    sprite.setPosition(x, y);
}

entidades::personagens::Minotauro::~Minotauro() {
}

void entidades::personagens::Minotauro::processarEventos(Event evento) {

}

void entidades::personagens::Minotauro::colideX() {
    velX = velX == 3 ? -3 : 3;
    sentido = sentido == "ESQUERDA" ? "DIREITA" : "ESQUERDA";
    escalarSprite(-1, 1);
}

void entidades::personagens::Minotauro::moverX() {
    sprite.move(velX,0);
    x += velX;
}

int  entidades::personagens::Minotauro::getAtaque() {
    return ataque / desgasteChifres;
}

void entidades::personagens::Minotauro::lentidao(){

}

void entidades::personagens::Minotauro::queimar(){

}

void entidades::personagens::Minotauro::setEmpuxo(const int novoEmpuxo) {
    
}