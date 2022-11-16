#include "../../../Includes/Entidades/Obstaculos/obstaculo.hpp"

using entidades::obstaculos::Obstaculo;

Obstaculo::Obstaculo() {}

Obstaculo::Obstaculo(int tamX, int tamY) {
    shape = new RectangleShape(Vector2f(tamX, tamY));
    textura = new Texture();
}

Obstaculo::Obstaculo(int tamX, int tamY, int x, int y) :
Obstaculo(tamX, tamY) {
    this->tamX = tamX;
    this->tamY = tamY;
    this->x = x;
    this->y = y;

    shape->setPosition(x, y);
}

Obstaculo::~Obstaculo() {
    delete shape;
    delete textura;
}

int Obstaculo::getTamX() {
    return tamX;
}

void Obstaculo::setTamX(int novoTamX) {
    tamX = novoTamX;
}

int Obstaculo::getTamY() {
    return tamY;
}

void Obstaculo::setTamY(int novoTamY) {
    tamY = novoTamY;
}

Drawable *entidades::obstaculos::Obstaculo::getDraw() {
    return shape;
}

Shape *entidades::obstaculos::Obstaculo::getShape() {
    return shape;
}

void entidades::obstaculos::Obstaculo::desenhar() {
    ptrGG->desenhaElemento(*shape);
}

bool entidades::obstaculos::Obstaculo::getAtravessar(){
    return atravessavel;
}