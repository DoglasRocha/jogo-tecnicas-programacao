#include "../../Includes/Gerenciadores/gerenciador_colisoes.hpp"
#include <iostream>

using namespace sf;

namespace Gerenciadores
{

    GerenciadorColisoes::GerenciadorColisoes():gravidade(1) {

    }

    GerenciadorColisoes *GerenciadorColisoes::getInstance() {
        if (instance == nullptr)
            instance = new GerenciadorColisoes();

        return instance;
    }

    GerenciadorColisoes *GerenciadorColisoes::addInimigo(Inimigo *ptrInimigo) {
        vetorInimigos.push_back(ptrInimigo);
        return instance;
    }

    GerenciadorColisoes *GerenciadorColisoes::addObstaculo(Obstaculo *ptrObstaculo) {
        listaObstaculos.push_back(ptrObstaculo);
        return instance;
    }

    GerenciadorColisoes::~GerenciadorColisoes() {
        delete instance;
    }

    void GerenciadorColisoes::aplicaGravidade(Personagem *personagem)
    {
        personagem->setVelY(personagem->getVelY() + gravidade + personagem->getEmpuxo());
        personagem->setEmpuxo(personagem->getEmpuxo() + gravidade);
    }

    void GerenciadorColisoes::executar() {
        // colisao com tela
        for (int i = 0; i < 2; i++) {
            FloatRect boundsPersonagem = vetorInimigos[i]->getSprite()->getGlobalBounds();
            int x = vetorInimigos[i]->getX() + vetorInimigos[i]->getVelX(),
            y = vetorInimigos[i]->getY() + vetorInimigos[i]->getVelY() + vetorInimigos[i]->getEmpuxo();

            if (y >= 0 &&
                (y + boundsPersonagem.height) <= TAM_TELA[1])
            {
                aplicaGravidade(vetorInimigos[i]);
                vetorInimigos[i]->moverY();
            }
            else
            {
                vetorInimigos[i]->setQtdPulos(0);
                vetorInimigos[i]->setVelY(0);
            }
            
            if (x >= 0 &&
                (x + boundsPersonagem.width) <= TAM_TELA[0])
                vetorInimigos[i]->moverX();
        }
    }
}
