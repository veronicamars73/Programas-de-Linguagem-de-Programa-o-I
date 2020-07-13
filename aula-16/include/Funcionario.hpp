#ifndef W5N_FUNCIONARIO_H
#define W5N_FUNCIONARIO_H

#include <string>

class Funcionario{
    private:
    std::string nome;
    std::string departamento;
    std::string dataAdmissao;
    double salario;

	public:
    Funcionario();
    Funcionario(std::string nome, std::string departamento, std::string dataAdmissao, double salario);

    void setNome(std::string nome);
    std::string getNome();
    void setDepartamento(std::string departamento);
    std::string getDepartamento();
    void setdataAdmissao(std::string dataAdmissao);
    std::string getdataAdmissao();
    void setSalario(double setSalario);
    double getSalario();
};

#endif