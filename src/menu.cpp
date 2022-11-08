#include "../Includes/menu.hpp"

Menu::Menu(GerenciadorGrafico *gG, GerenciadorEventos *gE)
{
    gerenciadorGrafico = gG;
    gerenciadorEventos = gE;
    planoDeFundo = new BackgroundManager("pixel_art_forest/Background.png", gerenciadorGrafico);
}
        
Menu::~Menu()
{
    gerenciadorGrafico = nullptr;
    gerenciadorEventos = nullptr;
    planoDeFundo = nullptr;
}


void Menu::desenhar(GerenciadorGrafico *gG)
{
    planoDeFundo->desenhar(gerenciadorGrafico);
}

void Menu::operator++()
{
    if(cont < 4) cont++;
    else cont = 1;
}

void Menu::operator--()
{
    if (cont > 1) cont--;
    else cont = 4;
}

void Menu::processaEventos()
{
    Event evento;
    while (gerenciadorEventos->getEvento(evento)) {
        if (evento.type == Event::Closed) gerenciadorGrafico->fechaJanela();
        if (evento.type == Event::KeyPressed)
        {
            switch (evento.key.code)
            {
                case (Keyboard::Up): 
                    this->operator--();
                    break;

                case (Keyboard::Down): 
                    this->operator++();
                    break;
            }
        }
    }
}

void Menu::executar()
{
    processaEventos();
    desenhar(gerenciadorGrafico);
}

