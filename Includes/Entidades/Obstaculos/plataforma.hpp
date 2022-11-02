//
// Created by doglasrocha on 11/1/22.
//

#ifndef JOGO_TECNICAS_PROGRAMACAO_PLATAFORMA_HPP
#define JOGO_TECNICAS_PROGRAMACAO_PLATAFORMA_HPP
#include "../entidade.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace entidades::obstaculos {
    class Plataforma : public Obstaculo {
        private:
            int tamX, tamY;
            Shape *shape;

        public:
            Plataforma(int tamX_, int tamY_, int posX, int posY);
            ~Plataforma();
            int getTamX();
            void setTamX(int novoTamX);
            int getTamY();
            void setTamY(int novoTamY);
            void desenhar(RenderWindow *window);
            void processarEventos(Event evento);
            void setEmpuxo(int novoEmpuxo);
        };
}

#endif //JOGO_TECNICAS_PROGRAMACAO_PLATAFORMA_HPP
