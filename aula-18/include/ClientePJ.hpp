#ifndef W5N_CLIENTEPJ_H
#define W5N_CLIENTEPJ_H

#include <string>
#include "Cliente.hpp"

class ClientePJ : public Cliente{
    private:
    std::string responsavel;

	public:
    ClientePJ();
    ClientePJ(std::string responsavel);
    void setResponsavel(std::string responsavel);
    std::string getResponsavel();
};

#endif