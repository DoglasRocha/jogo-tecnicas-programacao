//
// Created by doglasrocha on 11/1/22.
//

#ifndef JOGO_TECNICAS_PROGRAMACAO_PLATAFORMA_HPP
#define JOGO_TECNICAS_PROGRAMACAO_PLATAFORMA_HPP
#include "obstaculo.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace entidades::obstaculos {
    class Plataforma : public Obstaculo {

        public:
            Plataforma(const int tamX, const int tamY, const int posX, const int posY);
            ~Plataforma();
            void processarEventos(Event evento);
            void setEmpuxo(const int novoEmpuxo);
            void interage(Personagem *ptrJogador);
        };
}

#endif //JOGO_TECNICAS_PROGRAMACAO_PLATAFORMA_HPP
