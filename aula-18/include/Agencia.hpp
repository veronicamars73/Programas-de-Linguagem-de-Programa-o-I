#ifndef W5N_AGENCIA_H
#define W5N_AGENCIA_H

#include <string>

class Agencia{
    public:
    int numero;
    std::string nome;

    Agencia();
    Agencia(std::string nome, int numero);
};

#endif