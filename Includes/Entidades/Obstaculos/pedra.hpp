#pragma once
#include "obstaculo.hpp"


namespace entidades::obstaculos {
    class Pedra : public Obstaculo
    {
        private:
            float altura;

        public:
            Pedra();
            ~Pedra();
            float getAltura() const;    
    };
}