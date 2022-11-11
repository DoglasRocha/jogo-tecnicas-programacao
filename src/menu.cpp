#include "../Includes/menu.hpp"
#include <string>
#include <sstream>

Menu::Menu() : Ente()
{
    planoDeFundo = new BackgroundManager("fundo_botoes_menu/background.png");

    for(int i = 1; i < 5; i++)
    {
        if(i == 1) 
        {
            Plataforma *novoBotao = new Plataforma(350, 150, 525, 250);
            listaDeBotoes.append(novoBotao);
        }
        if(i == 2) 
        {
            Plataforma *novoBotao = new Plataforma(350, 150, 525, 425);
            listaDeBotoes.append(novoBotao);
        }
        if(i == 3) 
        {
            Plataforma *novoBotao = new Plataforma(350, 150, 525, 600);
            listaDeBotoes.append(novoBotao);
        }
        if(i == 4)
        {
            Plataforma *novoBotao = new Plataforma(350, 150, 525, 775);
            listaDeBotoes.append(novoBotao);
        }
    }

    // po ambrogi, era so fazer

    //listaDeBotoes.append(new Plataforma(..., ..., ..., .,,,))
    //listaDeBotoes.append(new Plataforma(..., ..., ..., .,,,))
    //listaDeBotoes.append(new Plataforma(..., ..., ..., .,,,))
    //listaDeBotoes.append(new Plataforma(..., ..., ..., .,,,))
    
    //nem precisava de for
}
        
Menu::~Menu()
{
    gerenciadorGrafico = nullptr;
    gerenciadorEventos = nullptr;
    planoDeFundo = nullptr;
}


void Menu::desenhar()
{
    planoDeFundo->desenhar();

    ListaEntidades::Node *node;
    for (node = listaDeBotoes.begin();
         node != listaDeBotoes.end();
         node = node->getNext()) {
        node->getDado()->desenhar();
    }
    node->getDado()->desenhar();
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
                
                case (Keyboard::Enter):
                    if(cont == 1); // Fase 1
                    if(cont == 2); // Fase 2
                    if(cont == 3); // Leaderboard
                    if(cont == 4) gerenciadorGrafico->fechaJanela();
            }
        }
    }
}

void Menu::executar()
{
    processaEventos();
    desenhar();
}

