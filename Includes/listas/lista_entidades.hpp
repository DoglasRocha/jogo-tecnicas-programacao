//
// Created by doglasrocha on 11/4/22.
//

#ifndef JOGO_TECNICAS_PROGRAMACAO_LISTA_ENTIDADES_HPP
#define JOGO_TECNICAS_PROGRAMACAO_LISTA_ENTIDADES_HPP
#include "lista_circular.hpp"
#include "../Entidades/entidade.hpp"

namespace Listas {
    class ListaEntidades : public ListaCircular<entidades::Entidade> {
    public:
        ListaEntidades() :
        ListaCircular<entidades::Entidade>() {

        }

        ~ListaEntidades() {}

        void desenhaEntidades() {
            Node *node;
            for (node = head; node != tail; node = node->getNext()) {
                node->getDado()->desenhar();
            }
            node->getDado()->desenhar();
        }

        void limparLista() {
            std::cout << "aqui entra" << std::endl;
            Node *aux;
            for (aux = head; aux != tail; aux = aux->getNext()) {
                std::cout << "aqui" << std::endl;
                delete aux->getDado();
            }
            std::cout << "aqui final" << std::endl;
            delete aux->getDado();
        }
    };  
}

#endif //JOGO_TECNICAS_PROGRAMACAO_LISTA_ENTIDADES_HPP
