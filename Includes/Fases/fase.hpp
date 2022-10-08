#include "../base.hpp"

namespace fases
{
    class Fase : public Base
    {
        public:
            Fase();
            ~Fase();
            virtual void executar();
            void gerencia_colisoes();
    };
}
