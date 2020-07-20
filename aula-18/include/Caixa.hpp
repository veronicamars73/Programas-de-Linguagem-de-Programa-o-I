#ifndef W5N_Caixa_H
#define W5N_Caixa_H

#include <string>
#include "Funcionario.hpp"

class Caixa : public Funcionario{
    private:
    int numero_do_caixa;

    public:
    Caixa();
    Caixa(int numero_do_caixa);
    void setNumero_do_caixa(int idade);
    int getNumero_do_caixa();
};

#endif