#include "../../../Includes/Entidades/Obstaculos/parede.hpp"
#include <SFML/Graphics.hpp>

using entidades::obstaculos::Parede;
using namespace sf;

Parede::Parede(int tamX, int tamY, int posX, int posY) :
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

void Parede::setEmpuxo(int novoEmpuxo) {

}

void Parede::interage(Personagem *ptrJogador){
    
}