#include "../Includes/menu_jogadores.hpp"
#include "../Includes/jogo.hpp"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

MenuJogadores::MenuJogadores(GerenciadorEventos *gE, Jogo *ptrJogo, int fase_)
{
    this->ptrJogo = ptrJogo;
    gerenciadorEventos = gE;
    planoDeFundo = new BackgroundManager("fundo_botoes_menu/background.png");

    Botao *novoBotao = new Botao(425,"texturas/fundo_botoes_menu/botao1p.png");
    listaDeBotoes.append(novoBotao);
  
    novoBotao = new Botao(600,"texturas/fundo_botoes_menu/botao2p.png");
    listaDeBotoes.append(novoBotao);

    fase = fase_;
}
        
MenuJogadores::~MenuJogadores()
{
    listaDeBotoes.limparLista();
    delete planoDeFundo;
}

void MenuJogadores::desenhar()
{
    planoDeFundo->desenhar();
    Botao *tempBotao;
    resetaBotoes();
    if(cont == 1)
    {
        tempBotao = dynamic_cast<Botao*>(listaDeBotoes.begin()->getDado());
        tempBotao->getShape()->setOutlineThickness(10);
    }
    if(cont == 2)
    {
        tempBotao = dynamic_cast<Botao*>(listaDeBotoes.end()->getDado());
        tempBotao->getShape()->setOutlineThickness(10);
    }
    listaDeBotoes.desenhaEntidades();
}

void MenuJogadores::resetaBotoes()
{
    Botao *tempBotao = dynamic_cast<Botao*>(listaDeBotoes.begin()->getDado());
    tempBotao->getShape()->setOutlineThickness(0);

    tempBotao = dynamic_cast<Botao*>(listaDeBotoes.end()->getDado());
    tempBotao->getShape()->setOutlineThickness(0);
}

void MenuJogadores::operator++()
{
    if(cont < 2) cont++;
    else cont = 1;
}

void MenuJogadores::operator--()
{
    if (cont > 1) cont--;
    else cont = 2;
}

void MenuJogadores::processaEventos()
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

void MenuJogadores::executar()
{
    desenhar();
    processaEventos();
}

void MenuJogadores::trocaEstado(int opcao) {
    switch (opcao) {
        case (1):
            if (fase == 1) ptrJogo->irParaFase1(false);
            else ptrJogo->irParaFase2(false);
            break;

        case (2):
            if (fase == 1) ptrJogo->irParaFase1(true);
            else ptrJogo->irParaFase2(true);
            break;
    }
}