#pragma once
class Jogo;

class Estado {
    protected:
        Jogo *ptrJogo;

    public:
        Estado(Jogo *ptrJogo=nullptr);
        ~Estado();
        virtual void trocaEstado(int opcao=0) = 0;
        virtual void executar() = 0;
};