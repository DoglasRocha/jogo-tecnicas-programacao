#pragma once

class Base
{
    protected:
        int id;

    public:
        Base();
        virtual ~Base();
        virtual void executar();
        void desenhar();
};
