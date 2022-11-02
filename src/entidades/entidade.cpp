#include "../../Includes/Entidades/entidade.hpp"

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

int entidades::Entidade::getX() {
    return x;
}

int entidades::Entidade::getY() {
    return y;
}

void entidades::Entidade::setX(const int novoX) {
    x = novoX;
}

void entidades::Entidade::setY(const int novoY) {
    y = novoY;
}
