#include "../../Includes/Gerenciadores/gerenciador_colisoes.hpp"

using namespace sf;

namespace Gerenciadores
{

    GerenciadorColisoes::GerenciadorColisoes() {
        personagens[0] = personagens[1] = nullptr;
    }

    GerenciadorColisoes *GerenciadorColisoes::getInstance() {
        if (instance == nullptr)
            instance = new GerenciadorColisoes();

        return instance;
    }

    void GerenciadorColisoes::setPersonagens(Personagem *ptrPersonagem1, Personagem *ptrPersonagem2) {
        personagens[0] = ptrPersonagem1,
        personagens[1] = ptrPersonagem2;
    }

    GerenciadorColisoes::~GerenciadorColisoes() {
        delete instance;
    }

    void GerenciadorColisoes::executar() {
        // colisao com tela
        for (int i = 0; i < 2; i++) {
            FloatRect boundsPersonagem = personagens[i]->getSprite()->getGlobalBounds();
            boundsPersonagem.left += personagens[i]->getVelX();
            boundsPersonagem.top += personagens[i]->getVelY();

            if (boundsPersonagem.top >= 0 &&
                (boundsPersonagem.top + boundsPersonagem.height) <= TAM_TELA[1]) personagens[i]->moverY();
            
            if (boundsPersonagem.left >= 0 &&
                (boundsPersonagem.left + boundsPersonagem.width) <= TAM_TELA[0]) personagens[i]->moverX();
        }
    }
}
