#ifndef W5N_CLIENTE_H
#define W5N_CLIENTE_H

#include <string>

class Cliente{
    public:
    std::string cpf;
    std::string nome;

    Cliente();
    Cliente(std::string cpf, std::string nome);
};

#endif