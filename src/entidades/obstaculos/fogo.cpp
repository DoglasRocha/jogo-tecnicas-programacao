#include "../../../Includes/Entidades/Obstaculos/fogo.hpp"

Fogo::Fogo(int posX, int posY)
{
    atravessavel = 1;
    intensidade++;
    tamX = 60;
    tamY = 1000;
    shape = new RectangleShape(Vector2f(tamX,tamY));
    textura = new Texture;
    textura->loadFromFile("texturas/fogo/fogo1.png");
    shape->setTexture(textura);
    shape->setPosition(posX,posY - tamY); 
}

Fogo::~Fogo()
{
    intensidade--;
}

int Fogo::getIntensidade()
{
    return intensidade;
}

void Fogo::processarEventos(sf::Event evento){

}

void Fogo::setEmpuxo(int novoEmpuxo){

}

void Fogo::interage(Personagem *ptrJogador){
    ptrJogador->queimar();
}