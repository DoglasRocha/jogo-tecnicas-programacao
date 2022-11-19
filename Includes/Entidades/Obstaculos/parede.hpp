#pragma once
#include "obstaculo.hpp"
#include <SFML/Graphics.hpp>

namespace entidades::obstaculos {
    class Parede : public Obstaculo
    {
        public:
            Parede(const int tamX, const int tamY, const int posX, const int posY);
            ~Parede();
            void processarEventos(sf::Event evento);
            void setEmpuxo(const int novoEmpuxo);
            void interage(Personagem *ptrJogador);
};
}