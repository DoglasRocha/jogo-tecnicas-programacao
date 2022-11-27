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
        ifstream file("ranking.txt");
        if(file) lerArquivo();
        else throw(ifstream::failure("Erro na abertura do arquivo"));
    }
    catch(ifstream::failure f)
    {
        ofstream file("ranking.txt");
        file.write("", 0);
    }
    
    font.loadFromFile("texturas/VCR_OSD_MONO.ttf");
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
    arq.open("ranking.txt");
	if (!arq) {
		cout << "Erro ao abrir Arquivo." << endl;
	}

	infoJogador aux2;

	cout << "Digite nome do jogador:" << endl;
	cin >> aux2.nome;

	aux2.pontos = pontos;

	listaRanking.push_back(aux2);
	
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

	for (int i = 0; i < listaRanking.size(); i++) {
		arq << listaRanking[i].nome << ' ' << listaRanking[i].pontos << endl;
	}

	arq.close();

    ptrJogo->resetaPontuacao();
}

void Ranking::escreveJogadores()
{
    vector<infoJogador>::iterator it;
    for(it = listaRanking.begin(); it != listaRanking.end(); it++) cout << (*it).nome << " - " << (*it).pontos << endl;
}