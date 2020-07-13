#ifndef W5N_EMPRESA_H
#define W5N_EMPRESA_H

#include <string>
#include <vector>
#include <iterator>
#include "Funcionario.hpp"

class Empresa{
    private:
    std::string nome;
    std::string cnpj;
    std::vector<Funcionario> funcionarios;

	public:
    Empresa();
    Empresa(std::string nome, std::string cnpj);

    void setNome(std::string nome);
    std::string getNome();
    void setCnpj(std::string cnpj);
    std::string getCnpj();
    void addFuncionario(Funcionario funcionario);
    std::vector<Funcionario> getFuncionarios();
    std::vector<Funcionario*> getByDepartamento(std::string);
};

#endif