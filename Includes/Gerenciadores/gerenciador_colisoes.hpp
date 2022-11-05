#pragma once
#include <SFML/Graphics.hpp>
#include "../Entidades/Personagens/Inimigos/inimigo.hpp"
#include "../Entidades/Obstaculos/obstaculo.hpp"
#include "../Entidades/Personagens/jogador.hpp"

#include <vector>
#include <list>

using namespace sf;
using namespace entidades::personagens;
using entidades::obstaculos::Obstaculo;

namespace Gerenciadores {
    class GerenciadorColisoes {
    private:
        static GerenciadorColisoes *instance;
        const int TAM_TELA[2] = {1400, 1000}, gravidade;
        Jogador *jogador;
        std::vector<Personagem *> vetorInimigos;
        std::list<Obstaculo *> listaObstaculos;

        GerenciadorColisoes();

    public:
        ~GerenciadorColisoes();
        static GerenciadorColisoes *getInstance();
        GerenciadorColisoes *addInimigo(Personagem *ptrInimigo);
        GerenciadorColisoes *addObstaculo(Obstaculo *ptrObstaculo);
        void aplicaGravidade(Personagem *personagem);
        void executar();
        void mostraHitbox(int x, int y, int width, int height);
        void setJogador(Jogador *ptrJogador);
        void executaColisoesObstaculos(Personagem *ptrPersonagem);
    };
}
