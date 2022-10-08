#pragma once
#include "../entidade.hpp"

namespace entidades::personagens
{
    class Personagem : public Entidade
    {
        private:
            int num_vidas;
    };
}
