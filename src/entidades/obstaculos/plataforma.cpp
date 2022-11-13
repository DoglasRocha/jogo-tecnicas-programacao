//
// Created by doglasrocha on 11/1/22.
//

#include "../../../Includes/Entidades/Obstaculos/plataforma.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

entidades::obstaculos::Plataforma::Plataforma(int tamX, int tamY, int posX, int posY) :
Obstaculo(tamX, tamY, posX, posY) 
{
    empuxo = -1;

    textura->loadFromFile("texturas/cenario/plataforma.png");
    textura->setRepeated(true);

    shape->setTexture(textura);
    shape->setTextureRect({0, 0, tamX, 24});
}

entidades::obstaculos::Plataforma::~Plataforma() {
}

void entidades::obstaculos::Plataforma::processarEventos(Event evento) {

}

void entidades::obstaculos::Plataforma::setEmpuxo(int novoEmpuxo) {

}