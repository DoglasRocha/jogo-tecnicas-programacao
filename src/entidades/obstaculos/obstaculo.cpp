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

Shape *entidades::obstaculos::Obstaculo::getShape() {
    return shape;
}
