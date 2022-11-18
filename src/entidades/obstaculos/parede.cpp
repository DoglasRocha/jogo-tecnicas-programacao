#include "../../../Includes/Entidades/Obstaculos/parede.hpp"
#include <SFML/Graphics.hpp>

using entidades::obstaculos::Parede;
using namespace sf;

Parede::Parede(const int tamX, const int tamY, const int posX, const int posY) :
Obstaculo(tamX, tamY, posX, posY) {
    empuxo = -1;

    textura->loadFromFile("texturas/cenario/parede.png");
    textura->setRepeated(true);

    shape->setTexture(textura);
    shape->setTextureRect({0, 0, 32, tamY});
}

Parede::~Parede() {
}

void Parede::processarEventos(sf::Event evento) {

}

void Parede::setEmpuxo(const int novoEmpuxo) {

}

void Parede::interage(Personagem *ptrJogador){
    
}