#pragma once
#include <SFML/Graphics.hpp>
#include "../Entidades/Personagens/Inimigos/inimigo.hpp"
#include "../Entidades/Obstaculos/obstaculo.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/projetil.hpp"

#include <vector>
#include <list>

using namespace sf;
using namespace entidades;
using entidades::obstaculos::Obstaculo;

namespace Gerenciadores {
    class GerenciadorColisoes {
    private:
        static GerenciadorColisoes *instance;
        const int gravidade;
        Jogador *jogador;
        Jogador *jogador2;
        Projetil *ptrProjetil;
        std::vector<Inimigo *> vetorInimigos;
        std::list<Obstaculo *> listaObstaculos;

        GerenciadorColisoes();
        bool moveX, moveY;
        int sentido;

    public:
        ~GerenciadorColisoes();
        static GerenciadorColisoes *getInstance();
        static void deleteInstance();
        GerenciadorColisoes *addInimigo(Inimigo *ptrInimigo);
        GerenciadorColisoes *addObstaculo(Obstaculo *ptrObstaculo);
        void aplicaGravidade(Entidade *entidade);
        void executar();
        std::vector<Inimigo*> getVetorInimigos();
        void executarColisoesJogador(Jogador *ptrJogador);
        void mostraHitbox(int x, int y, int width, int height);
        void setJogador(Jogador *ptrJogador);
        void setJogador2(Jogador *ptrJogador);
        void setProjetil(Projetil *ptrProjetil_);
        void executaColisoesObstaculos(Personagem *ptrPersonagem);
        void executaColisaoJogadorComInimigo(Jogador *ptrJogador);
        void executaColisaoProjetilComEntidade();
        void limparListas();
    };
}
