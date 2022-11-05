#pragma once

class Ente
{
    protected:
        int id;

    public:
        Ente();
        virtual ~Ente();
        virtual void executar();
        void desenhar();
};
