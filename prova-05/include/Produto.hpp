#ifndef W5N_Produto_H
#define W5N_Produto_H

#include <string>

class Produto{
    public:
    int codigo;
    std::string nome;
    std::string unidadeDeMedida;
    double preco;
    int qtd;

    Produto();
    Produto(int codigo, std::string nome, std::string unidadeDeMedida, double preco, int qtd);
};

#endif