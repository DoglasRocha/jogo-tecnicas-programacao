#include <SFML/Graphics.hpp>
#include "../../Includes/Gerenciadores/gerenciador_grafico.hpp"

using Gerenciadores::GerenciadorGrafico;
using namespace sf;

GerenciadorGrafico::GerenciadorGrafico()
{
    window = new RenderWindow(VideoMode(1400, 1000), "Jogo");
}

GerenciadorGrafico::~GerenciadorGrafico() 
{
	delete instance;
    delete window;
}

GerenciadorGrafico *GerenciadorGrafico::getGerenciadorGrafico() {
    if (instance == nullptr)
		instance = new GerenciadorGrafico();

	return instance;
}

RenderWindow *GerenciadorGrafico::getWindow()
{
	return window;
}

const bool GerenciadorGrafico::verificaJanelaAberta() {
    return window->isOpen();
}

void GerenciadorGrafico::limpaJanela() {
    window->clear();
}

void GerenciadorGrafico::desenhaElemento(Drawable &drawable) {
    window->draw(drawable);
}

void GerenciadorGrafico::mostraElementos() {
    window->display();
}

void GerenciadorGrafico::fechaJanela() {
    window->close();
}

Vector2u Gerenciadores::GerenciadorGrafico::getTamanhoJanela() {
    return window->getSize();
}
