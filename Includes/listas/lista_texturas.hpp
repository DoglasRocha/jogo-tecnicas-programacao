//
// Created by doglasrocha on 11/4/22.
//

#ifndef JOGO_TECNICAS_PROGRAMACAO_LISTA_TEXTURAS_HPP
#define JOGO_TECNICAS_PROGRAMACAO_LISTA_TEXTURAS_HPP
#include "lista_circular.hpp"
#include <SFML/Graphics.hpp>

namespace Listas {
    class ListaTexturas : public ListaCircular<sf::Texture> {
    public:
        ListaTexturas() :
        ListaCircular<sf::Texture>() {

        }

        ~ListaTexturas() {}
    };
}

#endif //JOGO_TECNICAS_PROGRAMACAO_LISTA_TEXTURAS_HPP
