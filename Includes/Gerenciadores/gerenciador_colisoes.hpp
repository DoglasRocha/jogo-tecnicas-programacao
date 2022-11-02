#pragma once
#include <SFML/Graphics.hpp>
#include "../Entidades/Personagens/Inimigo/inimigo.hpp"
#include "../Entidades/Obstaculos/obstaculo.hpp"

#include <vector>
#include <list>

using namespace sf;
using entidades::personagens::Inimigo;
using entidades::obstaculos::Obstaculo;

namespace Gerenciadores {
    class GerenciadorColisoes {
    private:
        static GerenciadorColisoes *instance;
        const int TAM_TELA[2] = {1400, 1000}, gravidade;
        std::vector<Inimigo *> vetorInimigos;
        std::list<Obstaculo *> listaObstaculos;

        GerenciadorColisoes();

    public:
        ~GerenciadorColisoes();
        static GerenciadorColisoes *getInstance();
        GerenciadorColisoes *addInimigo(Inimigo *ptrInimigo);
        GerenciadorColisoes *addObstaculo(Obstaculo *ptrObstaculo);
        void aplicaGravidade(Personagem *personagem);
        void executar();
    };
}
