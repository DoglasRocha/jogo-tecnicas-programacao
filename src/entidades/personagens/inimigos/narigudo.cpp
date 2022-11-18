#include "../../../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
#include "../../../../Includes/Gerenciadores/gerenciador_grafico.hpp"
#include "../../../../Includes/listas/lista_circular.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

using entidades::personagens::Narigudo;

Narigudo::Narigudo() :
entidades::personagens::Inimigo() {
    sentido = "ESQUERDA";
    num_vidas = 20;
    ataque = 5;
    forcaEspirro = rand() % 5;

    carregarTexturas("Sprites/narigudo/narigudo", 1, 3);
    noAtual = listaTexturas.begin();
    sprite.setTexture(*(noAtual->getDado()));
    x = y = 200;
    setOriginToCenter();
    escalarSprite(.25, .25);
};

Narigudo::Narigudo(int x, int y) :
Narigudo::Narigudo() {
    
    this->x = x, this->y = y;
    velX = -1;
    sprite.setPosition(x, y);
};

Narigudo::~Narigudo() {
    // ListaTexturas::Node *tmp;
    // for (noAtual = listaTexturas.begin(); noAtual != listaTexturas.end(); noAtual = tmp) {
    //     tmp = noAtual->getNext();
    //     delete noAtual->getDado();
    // }
    // delete noAtual->getDado();
}

void Narigudo::processarEventos(Event evento) {
    
}

void Narigudo::colideX() {
    velX = velX == 1 ? -1 : 1;
    sentido = sentido == "ESQUERDA" ? "DIREITA" : "ESQUERDA";
    escalarSprite(-1, 1);
}

int Narigudo::getAtaque() {
    return ataque + forcaEspirro;
}

void Narigudo::lentidao(){

}

void Narigudo::queimar(){

}