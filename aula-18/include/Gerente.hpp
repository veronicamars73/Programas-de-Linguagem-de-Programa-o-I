#ifndef W5N_Gerente_H
#define W5N_Gerente_H

#include <string>
#include "Funcionario.hpp"

class Gerente : public Funcionario{
    private:
    std::string departamento;

    public:
    Gerente();
    Gerente( std::string departamento);
    void setDepartamento( std::string departamento);
    std::string getDepartamento();
};

#endif