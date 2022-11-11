#include "../../../Includes/Entidades/Obstaculos/obstaculo.hpp"

using entidades::obstaculos::Obstaculo;

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
    gerenciadorGrafico->desenhaElemento(*shape);
}
