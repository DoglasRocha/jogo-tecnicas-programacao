//
// Created by doglasrocha on 11/6/22.
//
#include "../../Includes/Gerenciadores/gerenciador_eventos.hpp"

Gerenciadores::GerenciadorEventos::GerenciadorEventos() {
    gG = nullptr;
}

Gerenciadores::GerenciadorEventos::~GerenciadorEventos() {

}

bool Gerenciadores::GerenciadorEventos::getEvento(Event &evento) {
    return gG->getWindow()->pollEvent(evento);
}

Gerenciadores::GerenciadorEventos *Gerenciadores::GerenciadorEventos::getInstance() {
    if (instance == nullptr)
        instance = new GerenciadorEventos();

    return instance;
}

void Gerenciadores::GerenciadorEventos::deleteInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

void Gerenciadores::GerenciadorEventos::setGerenciadorGrafico(Gerenciadores::GerenciadorGrafico *ptrGerenGraf) {
    gG = ptrGerenGraf;
}

