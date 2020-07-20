#ifndef W5N_CLIENTEPF_H
#define W5N_CLIENTEPF_H

#include <string>
#include "Cliente.hpp"

class ClientePF : public Cliente{
    private:
    int idade;

    public:
    ClientePF();
    ClientePF(int idade);
    void setIdade(int idade);
    int getIdade();
};

#endif