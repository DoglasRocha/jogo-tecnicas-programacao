#include "../Includes/botao.hpp"

Botao::Botao(int posY):tamX(350),tamY(150)
{
    x = 550;
    y = posY;
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