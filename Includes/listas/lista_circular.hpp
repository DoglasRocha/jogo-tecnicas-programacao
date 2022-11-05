//
// Created by doglasrocha on 10/28/22.
//

#ifndef JOGO_TECNICAS_PROGRAMACAO_LISTA_CIRCULAR_HPP
#define JOGO_TECNICAS_PROGRAMACAO_LISTA_CIRCULAR_HPP
#include <iostream>

namespace Listas {

    template <class T>
    class ListaCircular {

    public:
        class Node {
        private:
            Node *next;
            T *dado;

        public:
            Node(T *dado_=nullptr) {
                dado = dado_;
            }

            ~Node() {}

            void setNext(Node *next_) {
                next = next_;
            }

            Node *getNext() {
                return next;
            }

            void setDado(T *dado_) {
                dado = dado_;
            }

            T *getDado() {
                return dado;
            }

            Node *operator++() {
                return next;
            }
        };

    protected:
        Node *head, *tail;
        int length;

    public:
        ListaCircular() {
            head = tail = nullptr;
            length = 0;
        }

        ~ListaCircular() {
            Node *tmp;
            for (Node *aux = head; aux != tail; aux = tmp) {
                tmp = aux->getNext();
                delete aux;
            }

            delete tmp;
        }

        Node *begin() {
            return head;
        }

        Node *end() {
            return tail->getNext();
        }

        ListaCircular<T> *append(T *dado_) {
            Node *node = new Node(dado_);
            if (length == 0) {
                head = tail = node;
                head->setNext(node);
                tail->setNext(node);
                length++;
                return this;
            }

            node->setNext(tail->getNext());
            tail->setNext(node);
            tail = node;
            length++;
            return this;
        }
    };
}

#endif //JOGO_TECNICAS_PROGRAMACAO_LISTA_CIRCULAR_HPP
