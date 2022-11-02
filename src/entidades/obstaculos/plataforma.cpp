//
// Created by doglasrocha on 11/1/22.
//

#include "../../../Includes/Entidades/Obstaculos/plataforma.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

entidades::obstaculos::Plataforma::Plataforma(int tamX_, int tamY_, int posX, int posY) {
    tamX = tamX_;
    tamY = tamY_;
    x = posX;
    y = posY;
    empuxo = -1;

    shape = new RectangleShape(Vector2f(tamX, tamY));
    shape->setFillColor(Color::Red);
    shape->setPosition(x, y);
}

entidades::obstaculos::Plataforma::~Plataforma() {
    delete shape;
}

int entidades::obstaculos::Plataforma::getTamX() {
    return tamX;
}

void entidades::obstaculos::Plataforma::setTamX(int novoTamX) {
    tamX = novoTamX;
}

int entidades::obstaculos::Plataforma::getTamY() {
    return tamY;
}

void entidades::obstaculos::Plataforma::setTamY(int novoTamY) {
    tamY = novoTamY;
}

void entidades::obstaculos::Plataforma::desenhar(RenderWindow *window) {
    window->draw(*shape);
}

void entidades::obstaculos::Plataforma::processarEventos(Event evento) {

}

void entidades::obstaculos::Plataforma::setEmpuxo(int novoEmpuxo) {

}