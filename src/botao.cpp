#include "../Includes/botao.hpp"

Botao::Botao() : 
    tamX(350),
    tamY(150)
{

}

Botao::Botao(int posY) : Botao()
{
    x = 550;
    y = posY;
}

Botao::~Botao() {
    
}

void Botao::desenhar() 
{
    ptrGG->desenhaElemento(*shape);
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

void Botao::setEmpuxo(int novoEmpuxo)
{
    
}