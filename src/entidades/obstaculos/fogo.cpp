#include "../../../Includes/Entidades/Obstaculos/fogo.hpp"

Fogo::Fogo()
{
    intensidade++;
    tamX = 50;
    tamY = 50;
    shape = new RectangleShape(Vector2f(tamX,tamY));
    textura = new Texture;
    textura->loadFromFile("texturas"); 
}

Fogo::~Fogo()
{
    intensidade--;
}

int Fogo::getIntensidade()
{
    return intensidade;
}