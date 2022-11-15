#include "../../../Includes/Entidades/Obstaculos/arbusto.hpp"

Arbusto::Arbusto(int posX, int posY)
{
    atravessavel = 1;
    altura = (float(rand())/RAND_MAX) + 1;
    tamX = 100;
    tamY = 50 * altura;
    shape = new RectangleShape(Vector2f(tamX,tamY));
    textura = new Texture;
    textura->loadFromFile("texturas/pixel_art_forest/PNG/Background layers/arbusto.png");
    shape->setTexture(textura);
    shape->setPosition(posX,posY - tamY);
}

Arbusto::~Arbusto(){
    textura = nullptr;
    shape = nullptr;
}

float Arbusto::getAltura()
{
    return altura;
}

void Arbusto::processarEventos(sf::Event evento){

}

void Arbusto::setEmpuxo(int novoEmpuxo){

}

void Arbusto::interage(Personagem *ptrJogador){
    ptrJogador->lentidao();
}