#pragma once
#include <SFML/Graphics.hpp>
#include "../Entidades/Personagens/personagem.hpp"

using namespace sf;
using entidades::personagens::Personagem;

namespace Gerenciadores {
    class GerenciadorColisoes {
    private:
        static GerenciadorColisoes *instance;
        const int TAM_TELA[2] = {1400, 1000}, gravidade;
        Personagem *personagens[2];

        GerenciadorColisoes();

    public:
        ~GerenciadorColisoes();
        static GerenciadorColisoes *getInstance();
        void setPersonagens(Personagem *ptrPersonagem1, Personagem *ptrPersonagem2);
        void aplicaGravidade(Personagem *personagem);
        void executar();
    };
}
