#ifndef W5N_CLIENTEPJ_H
#define W5N_CLIENTEPJ_H

#include <string>

class ClientePJ{
    public:
    std::string cnpj;
    std::string razao_social;

    ClientePJ();
    ClientePJ(std::string cnpj, std::string razao_social);
};

#endif