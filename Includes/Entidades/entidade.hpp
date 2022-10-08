#pragma once
#include "../base.hpp"

namespace entidades
{
    class Entidade : public Base
    {
        public:
            Entidade();
            ~Entidade();
            virtual void executar();
    };
}
