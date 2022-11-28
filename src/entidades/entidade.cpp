#include "../../Includes/Entidades/entidade.hpp"
#include <iostream>

using entidades::Entidade;

Entidade::Entidade()
{
    empuxo = x = y = 0;
}

Entidade::~Entidade()
{

}

void Entidade::executar()
{

}

int entidades::Entidade::getEmpuxo() const {
    return empuxo;
}

int entidades::Entidade::getX() const {
    return x;
}

int entidades::Entidade::getY() const {
    return y;
}

void entidades::Entidade::setX(const int novoX) {
    x = novoX;
}

void entidades::Entidade::setY(const int novoY) {
    y = novoY;
}

void entidades::Entidade::setVelX(const int novaVel) {
    velX = novaVel;
}

void entidades::Entidade::setVelY(const int novaVel) {
    velY = novaVel;
}

int entidades::Entidade::getVelX() const {
    return velX;
}

int entidades::Entidade::getVelY() const {
    return velY;
}
