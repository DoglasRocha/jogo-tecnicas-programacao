#include "../Includes/menu.hpp"
#include "../Includes/jogo.hpp"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

Menu::Menu(GerenciadorEventos *gE, Jogo *ptrJogo)
{
    this->ptrJogo = ptrJogo;
    gerenciadorEventos = gE;
    planoDeFundo = new BackgroundManager("fundo_botoes_menu/background.png");

    Botao *novoBotao = new Botao(250,"texturas/fundo_botoes_menu/botao1.png");
    listaDeBotoes.append(novoBotao);

    novoBotao = new Botao(425,"texturas/fundo_botoes_menu/botao2.png");
    listaDeBotoes.append(novoBotao);
  
    novoBotao = new Botao(600,"texturas/fundo_botoes_menu/botao3.png");
    listaDeBotoes.append(novoBotao);

    novoBotao = new Botao(775,"texturas/fundo_botoes_menu/botao4.png");
    listaDeBotoes.append(novoBotao);

    font.loadFromFile("texturas/VCR_OSD_MONO.ttf");

    titulo.setFont(font);
    titulo.setString("Johnson Adventures++");
    titulo.setCharacterSize(100);
    titulo.setFillColor(sf::Color::White);
    titulo.setOutlineColor(sf::Color::Black);
    titulo.setOutlineThickness(10);
    titulo.setPosition(Vector2f(100, 75));
}
        
Menu::~Menu()
{
    listaDeBotoes.limparLista();
    delete planoDeFundo;
}

void Menu::desenhar()
{
    planoDeFundo->desenhar();
    ptrGG->desenhaElemento(titulo);
    Botao *tempBotao;
    resetaBotoes();
    if(cont == 1)
    {
        tempBotao = dynamic_cast<Botao*>(listaDeBotoes.begin()->getDado());
        tempBotao->getShape()->setOutlineThickness(10);
    }
    if(cont == 2)
    {
        tempBotao = dynamic_cast<Botao*>(listaDeBotoes.begin()->getNext()->getDado());
        tempBotao->getShape()->setOutlineThickness(10);
    }
    if(cont == 3)
    {
        tempBotao = dynamic_cast<Botao*>(listaDeBotoes.begin()->getNext()->getNext()->getDado());
        tempBotao->getShape()->setOutlineThickness(10);
    }
    if(cont == 4)
    {
        tempBotao = dynamic_cast<Botao*>(listaDeBotoes.end()->getDado());
        tempBotao->getShape()->setOutlineThickness(10);
    }
    listaDeBotoes.desenhaEntidades();
}

void Menu::resetaBotoes()
{
    Botao *tempBotao = dynamic_cast<Botao*>(listaDeBotoes.begin()->getDado());
    tempBotao->getShape()->setOutlineThickness(0);

    tempBotao = dynamic_cast<Botao*>(listaDeBotoes.begin()->getNext()->getDado());
    tempBotao->getShape()->setOutlineThickness(0);
    
    tempBotao = dynamic_cast<Botao*>(listaDeBotoes.begin()->getNext()->getNext()->getDado());
    tempBotao->getShape()->setOutlineThickness(0);

    tempBotao = dynamic_cast<Botao*>(listaDeBotoes.end()->getDado());
    tempBotao->getShape()->setOutlineThickness(0);
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
                
                case (Keyboard::Return):
                    trocaEstado(cont);
                    break;
            }
        }
    }
}

void Menu::executar()
{
    desenhar();
    processaEventos();
}

void Menu::trocaEstado(int opcao) {
    switch (opcao) {
        case (1):
            ptrJogo->irParaMenuJogadores(1);
            break;

        case (2):
            ptrJogo->irParaMenuJogadores(2);
            break;

        case (3):
            ptrJogo->irParaRanking();
            break;

        case (4):
            ptrGG->fechaJanela();
    }
}