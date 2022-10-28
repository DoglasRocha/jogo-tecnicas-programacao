#include <SFML/Graphics.hpp>
#include "../../Includes/Gerenciadores/gerenciador_grafico.hpp"

using Gerenciadores::GerenciadorGrafico;

GerenciadorGrafico::GerenciadorGrafico() :
window(VideoMode(1400, 1000), "Jogo")
{

}

GerenciadorGrafico::~GerenciadorGrafico() 
{
	delete instance;
}

GerenciadorGrafico *GerenciadorGrafico::getInstance()
{
	if (instance == nullptr)
		instance = new GerenciadorGrafico();

	return instance;
}

RenderWindow *GerenciadorGrafico::getWindow()
{
	return &window;
}
