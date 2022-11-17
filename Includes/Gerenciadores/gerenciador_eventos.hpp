//
// Created by doglasrocha on 11/6/22.
//

#ifndef JOGO_TECNICAS_PROGRAMACAO_GERENCIADOR_EVENTOS_HPP
#define JOGO_TECNICAS_PROGRAMACAO_GERENCIADOR_EVENTOS_HPP
#include "gerenciador_grafico.hpp"
#include <SFML/Graphics.hpp>

namespace Gerenciadores {
    class GerenciadorEventos {
    protected:
        GerenciadorGrafico *gG;
        static GerenciadorEventos *instance;
        GerenciadorEventos();

    public:
        ~GerenciadorEventos();
        static GerenciadorEventos *getInstance();
        static void deleteInstance();
        void setGerenciadorGrafico(GerenciadorGrafico *ptrGerenGraf);
        bool getEvento(sf::Event &evento);
    };
}

#endif //JOGO_TECNICAS_PROGRAMACAO_GERENCIADOR_EVENTOS_HPP
