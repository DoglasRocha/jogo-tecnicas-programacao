#include "../../../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
#include "../../../../Includes/Gerenciadores/gerenciador_grafico.hpp"
#include "../../../../Includes/listas/lista_circular.hpp"
#include <iostream>
#include <sstream>

using entidades::personagens::Narigudo;

Narigudo::Narigudo() :
entidades::personagens::Inimigo() {
    sentido = "ESQUERDA";

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
    ListaCircular<Texture>::Node *tmp;
    for (noAtual = listaTexturas.begin(); noAtual != listaTexturas.end(); noAtual = tmp) {
        tmp = noAtual->getNext();
        delete noAtual->getDado();
    }
    delete noAtual->getDado();
}

void Narigudo::processarEventos(Event evento) {
    
}

void Narigudo::colideX() {
    velX = velX == 1 ? -1 : 1;
    sentido = sentido == "ESQUERDA" ? "DIREITA" : "ESQUERDA";
    escalarSprite(-1, 1);
}
