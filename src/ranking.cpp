#include "../Includes/ranking.hpp"
#include "../Includes/jogo.hpp"
#include <string>
#include <fstream>
using namespace std;

Ranking::Ranking(GerenciadorEventos *gE, Jogo *ptrJogo)
{
    this->ptrJogo = ptrJogo;
    gerenciadorEventos = gE;
    planoDeFundo = new BackgroundManager("fundo_botoes_menu/background.png");

    try
    {
        ifstream file;
        file.open("ranking.txt");
        if(file) lerArquivo();
        else throw(ifstream::failure("Erro na abertura do arquivo"));
    }
    catch(ifstream::failure f)
    {
        ofstream file("ranking.txt");
        file.write("", 0);
    }
    
    font.loadFromFile("texturas/VCR_OSD_MONO.ttf");

    textoInput.setFont(font);
    textoInput.setCharacterSize(75);
    textoInput.setFillColor(sf::Color::White);
    textoInput.setOutlineColor(sf::Color::Black);
    textoInput.setOutlineThickness(10);
    textoInput.setPosition(Vector2f(100, 500));
    
    textoGameOver.setFont(font);
    textoGameOver.setCharacterSize(75);
    textoGameOver.setFillColor(sf::Color::White);
    textoGameOver.setOutlineColor(sf::Color::Black);
    textoGameOver.setOutlineThickness(10);
    textoGameOver.setPosition(Vector2f(100, 400));
    textoGameOver.setString("GAME OVER. Digite seu nome:");
}

Ranking::~Ranking()
{
    ptrJogo = nullptr;
    gerenciadorEventos = nullptr;
}

void Ranking::executar()
{
    desenhar();
    if(ptrJogo->getPontuacao()) salvarArquivo(ptrJogo->getPontuacao());
    escreveJogadores();
    processaEventos();
}

void Ranking::processaEventos()
{
    Event evento;
    while (gerenciadorEventos->getEvento(evento)) {
        if (evento.type == Event::Closed) ptrGG->fechaJanela();
        if (evento.type == Event::KeyPressed)
        {
            switch (evento.key.code)
            {
                case (Keyboard::Escape): 
                    trocaEstado();
                    break;
            }
        }
    }
}

void Ranking::desenhar()
{
    planoDeFundo->desenhar();
}

void Ranking::trocaEstado(int opcao)
{
    ptrJogo->irParaMenu();
}

void Ranking::lerArquivo()
{
    ifstream arq;
    arq.open("ranking.txt");

    infoJogador aux;

	while (!arq.eof()) {
		arq >> aux.nome >> aux.pontos;
		if (aux.pontos > 0) {
			listaRanking.push_back(aux);
		}
	}

	arq.close();
}

void Ranking::salvarArquivo(int pontos)
{
    ofstream arq;
    arq.open("ranking.txt", std::ofstream::trunc);
	if (!arq) {
		cout << "Erro ao abrir Arquivo." << endl;
	}

	infoJogador aux;
    
    Event evento;

    int flag = 0;

    while(flag == 0){
        ptrGG->limpaJanela();
        desenhar();
        ptrGG->desenhaElemento(textoInput);
        ptrGG->desenhaElemento(textoGameOver);
        while (gerenciadorEventos->getEvento(evento)) {
            if (evento.type == Event::Closed) ptrGG->fechaJanela();
            if(evento.type == Event::TextEntered){
                inputJogador += evento.text.unicode;
                textoInput.setString(inputJogador);
            }
            if (evento.type == Event::KeyPressed){
                    if(evento.key.code == Keyboard::Enter) {
                    flag = 1;
                }
            }
        }
        ptrGG->mostraElementos();
    }
	
    string auxInput = inputJogador.toAnsiString();
    aux.nome = auxInput;
	aux.pontos = pontos;

	listaRanking.push_back(aux);
	
	int i, j;
	for (i = 0; i < listaRanking.size() - 1; i++) {
		for (j = 0; j < listaRanking.size() - i - 1; j++) {
			if (listaRanking[j].pontos < listaRanking[j + 1].pontos) {
				swap(listaRanking[j], listaRanking[j + 1]);
			}
		}
	}

	if (listaRanking.size() > 10) {
		listaRanking.resize(10);
	}

	for (int i = 0; i < (listaRanking.size() - 1); i++) {
		arq << listaRanking[i].nome << ' ' << listaRanking[i].pontos << endl;
	}

    arq << listaRanking[listaRanking.size() - 1].nome << ' ' << listaRanking[listaRanking.size() - 1].pontos;

	arq.close();

    ptrJogo->resetaPontuacao();
}

void Ranking::escreveJogadores()
{
    vector<infoJogador>::iterator it;
    int cont = 1;
    for(it = listaRanking.begin(); it != listaRanking.end(); it++)
    {
        Text aux, aux2, divisor;
        aux.setString((*it).nome);
        aux2.setString(to_string((*it).pontos));
        divisor.setString(" - ");

        aux.setFont(font);
        aux.setCharacterSize(75);
        aux.setFillColor(sf::Color::White);
        aux.setOutlineColor(sf::Color::Black);
        aux.setOutlineThickness(10);
        aux.setPosition(Vector2f(200, 75 * cont));
        
        aux2.setFont(font);
        aux2.setCharacterSize(75);
        aux2.setFillColor(sf::Color::White);
        aux2.setOutlineColor(sf::Color::Black);
        aux2.setOutlineThickness(10);
        aux2.setPosition(Vector2f(1000, 75 * cont));

        divisor.setFont(font);
        divisor.setCharacterSize(75);
        divisor.setFillColor(sf::Color::White);
        divisor.setOutlineColor(sf::Color::Black);
        divisor.setOutlineThickness(10);
        divisor.setPosition(Vector2f(690, 75 * cont));

        ptrGG->desenhaElemento(aux);
        ptrGG->desenhaElemento(aux2);
        ptrGG->desenhaElemento(divisor);

        cont++;
    }
}