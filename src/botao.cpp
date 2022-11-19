#include "../Includes/botao.hpp"
#include <iostream>
using namespace std;

Botao::Botao() : 
    tamX(350),
    tamY(150)
{

}

Botao::Botao(const int posY, const string stringTextura) : Botao()
{
    x = 550;
    y = posY;
    shape = new RectangleShape(Vector2f(tamX,tamY));
    textura = new Texture();
    textura->loadFromFile(stringTextura);
    shape->setTexture(textura);
    shape->setOutlineColor(Color::White);
    shape->setPosition(x,y);
}

Botao::~Botao() 
{
    delete textura;
    delete shape;
}

void Botao::desenhar() 
{
    ptrGG->desenhaElemento(*shape);
}

Shape* Botao::getShape()
{
    return shape;
}

Drawable* Botao::getDraw() 
{
    return shape;
}

void Botao::executar()
{

}
    
void Botao::processarEventos(Event evento)
{

}

void Botao::setEmpuxo(const int novoEmpuxo)
{
    
}