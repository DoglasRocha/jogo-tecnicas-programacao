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

    Texture *textura = new Texture();
    textura->loadFromFile("texturas/cenario/plataforma.png");
    textura->setRepeated(true);

    shape = new RectangleShape(Vector2f(tamX, tamY));
    shape->setTexture(textura);
    shape->setTextureRect({0, 0, tamX, 24});
    shape->setPosition(x, y);
}

entidades::obstaculos::Plataforma::~Plataforma() {
    delete shape;
}

void entidades::obstaculos::Plataforma::processarEventos(Event evento) {

}

void entidades::obstaculos::Plataforma::setEmpuxo(int novoEmpuxo) {

}