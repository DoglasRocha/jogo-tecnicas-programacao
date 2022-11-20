#include "../../../../Includes/Entidades/Personagens/Inimigos/narigudo.hpp"
#include "../../../../Includes/Gerenciadores/gerenciador_grafico.hpp"
#include "../../../../Includes/listas/lista_circular.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

using entidades::personagens::Narigudo;

Narigudo::Narigudo() :
entidades::personagens::Inimigo(500) {
    pontos = 10;
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

Narigudo::Narigudo(const int x, const int y) :
Narigudo::Narigudo() {
    
    this->x = x, this->y = y;
    velX = -1;
    sprite.setPosition(x, y);
};

Narigudo::~Narigudo() {
}

void Narigudo::processarEventos(Event evento) {
    
}

void Narigudo::colideX() {
    velX = velX == 1 ? -1 : 1;
    sentido = sentido == "ESQUERDA" ? "DIREITA" : "ESQUERDA";
    escalarSprite(-1, 1);
}

int Narigudo::getAtaque() {
    if (relogioAtaque.getElapsedTime() >= tempoAtaque) {
        relogioAtaque.restart();
        return ataque + forcaEspirro;
    }

    return 0;
}

void Narigudo::lentidao(){

}

void Narigudo::queimar(){

}