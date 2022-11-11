#pragma once
#include "ente.hpp"
#include "Gerenciadores/gerenciador_grafico.hpp"
#include "Gerenciadores/gerenciador_eventos.hpp"
#include "background_manager.hpp"
#include "Entidades/Obstaculos/plataforma.hpp"
#include "listas/lista_entidades.hpp"

using namespace Gerenciadores;
using namespace entidades::obstaculos;
using namespace Listas;

class Menu : public Ente
{
    private:
        int cont = 1;
        ListaEntidades listaDeBotoes;

    public:
        Menu();
        ~Menu();
        void executar();
        void processaEventos();
        void desenhar(GerenciadorGrafico *gG);
        void operator++();
        void operator--();
};
