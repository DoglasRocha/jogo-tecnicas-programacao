#include "../Includes/menu.hpp"
#include <string>
#include <sstream>

Menu::Menu(GerenciadorEventos *gE)
{
    gerenciadorEventos = gE;
    planoDeFundo = new BackgroundManager("fundo_botoes_menu/background.png");

    Plataforma *novoBotao = new Plataforma(350, 150, 525, 250);
    listaDeBotoes.append(novoBotao);

    novoBotao = new Plataforma(350, 150, 525, 425);
    listaDeBotoes.append(novoBotao);
  
    novoBotao = new Plataforma(350, 150, 525, 600);
    listaDeBotoes.append(novoBotao);

    novoBotao = new Plataforma(350, 150, 525, 775);
    listaDeBotoes.append(novoBotao);
}
        
Menu::~Menu()
{
    gerenciadorEventos = nullptr;
    planoDeFundo = nullptr;
}


void Menu::desenhar()
{
    planoDeFundo->desenhar();
    listaDeBotoes.desenhaEntidades();
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
        if (evento.type == Event::Closed) ptrGG->fechaJanela();
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
                
                case (Keyboard::Enter):
                    if(cont == 1); // Fase 1
                    if(cont == 2); // Fase 2
                    if(cont == 3); // Leaderboard
                    if(cont == 4) ptrGG->fechaJanela();
            }
        }
    }
}

void Menu::executar()
{
    processaEventos();
    desenhar();
}

