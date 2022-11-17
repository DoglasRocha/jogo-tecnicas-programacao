#include <SFML/Graphics.hpp>
#include "../../Includes/Gerenciadores/gerenciador_grafico.hpp"

using Gerenciadores::GerenciadorGrafico;
using namespace sf;

GerenciadorGrafico::GerenciadorGrafico()
{
    window = new RenderWindow(VideoMode(1400, 1000), "Jogo");
    window->setFramerateLimit(40);
    view = new View({700, 500}, {1400, 1000});
    window->setView(*view);
}

GerenciadorGrafico::~GerenciadorGrafico() 
{
	delete instance;
    delete window;
}

GerenciadorGrafico *GerenciadorGrafico::getInstance() {
    if (instance == nullptr)
		instance = new GerenciadorGrafico();

	return instance;
}

void GerenciadorGrafico::deleteInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
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

Vector2u GerenciadorGrafico::getTamanhoJanela() {
    return window->getSize();
}

void GerenciadorGrafico::centralizarJanela(int x) {
    view->setCenter(x, 500);   
    window->setView(*view); 
}

Vector2f GerenciadorGrafico::getCentroView() {
    return view->getCenter();
}