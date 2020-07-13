#include "Empresa.hpp"
#include "Funcionario.hpp"

#include <iostream>
#include <string>
#include <vector>
int main(int argc, char* argv[]) {
    std::string nome, cnpj, depa;
    std::vector<Funcionario*> f_dep;
    int num_func;
    std::cout << "Digite o nome da Empresa: ";
    getline(std::cin, nome);
    std::cout << "Digite o cnpj da Empresa: ";
    std::cin >> cnpj;
    Empresa emp(nome, cnpj);
    std::cout << "Digite o número de funcionários que desejas cadastrar: ";
    std::cin >> num_func;
    for (int i = 0; i < num_func; ++i) {
        std::string nome_f, dep, data;
        double sal;
        std::cin.ignore();
        std::cout << "Digite o nome do Funcionário: ";
        getline(std::cin, nome_f);
        std::cout << "Digite o nome do Departamento: ";
        getline(std::cin, dep);
        std::cout << "Digite a data de admissão: ";
        std::cin >> data;
        std::cout << "Digite o salário do Funcionário: ";
        std::cin >> sal;

        Funcionario f(nome_f, dep, data, sal);
        emp.addFuncionario(f);
    }
    std::cin.ignore();
    std::cout << "Digite o Departamento de funcionários que receberá um aumento: ";
    getline(std::cin, depa);

    f_dep = emp.getByDepartamento(depa);
    std::vector<Funcionario*>::iterator iter;
    std::cout << "Salário anterior:\n";
    for(iter = f_dep.begin(); iter != f_dep.end(); iter++) {
        std::cout << (*iter)->getNome() << (*iter)->getSalario() << std::endl;
    }
    for(iter = f_dep.begin(); iter != f_dep.end(); iter++) {
        (*iter)->setSalario((*iter)->getSalario()*1.10);
    }
    std::cout << "Salário antual:\n";
    for(iter = f_dep.begin(); iter != f_dep.end(); iter++) {
        std::cout << (*iter)->getNome() << (*iter)->getSalario() << std::endl;
    }
}
