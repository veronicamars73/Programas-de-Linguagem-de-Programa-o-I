#ifndef W5N_Seguranca_H
#define W5N_Seguranca_H

#include <string>
#include "Funcionario.hpp"

class Seguranca : public Funcionario{
    private:
    std::string patente;

    public:
    Seguranca();
    Seguranca( std::string patente);
    void setPatente( std::string patente);
    std::string getPatente();
};

#endif