#pragma once
#include "obstaculo.hpp"
#include <SFML/Graphics.hpp>

namespace entidades::obstaculos {
    class Parede : public Obstaculo
    {
        public:
            Parede(int tamX, int tamY, int posX, int posY);
            ~Parede();
            void processarEventos(sf::Event evento);
            void setEmpuxo(int novoEmpuxo);
};
}