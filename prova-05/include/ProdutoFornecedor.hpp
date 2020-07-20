#ifndef W5N_ProdutoFornecedor_H
#define W5N_ProdutoFornecedor_H

#include <string>

class ProdutoFornecedor{
    public:
    std::string nome;
    int qtd;

    ProdutoFornecedor();
    ProdutoFornecedor(std::string nome, int qtd);
};

#endif