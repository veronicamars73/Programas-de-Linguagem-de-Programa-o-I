#ifndef W5N_Funcionario_H
#define W5N_Funcionario_H

#include <string>

class Funcionario{
    protected:
    int idade;
    std::string nome; // CPF ou CNPJ
    std::string sexo; // Nome ou razão social

	public:
    Funcionario();

    void setIdade(int t);
    int getIdade();
    void setNome(std::string s);
    std::string getNome();
    void setSexo(std::string s);
    std::string getSexo();
};

#endif