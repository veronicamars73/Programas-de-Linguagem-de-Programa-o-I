#ifndef W5N_Fornecedor_H
#define W5N_Fornecedor_H

#include <string>
#include "Vector.hpp"
#include "ProdutoFornecedor.hpp"

class Fornecedor{
    public:
    std::string nome;
    Vector_Supermercado <ProdutoFornecedor> produtos;

    Fornecedor(std::string nome);
    void listarProdutos();
    int repassarProdutos(ProdutoFornecedor produtoRepassado);
    int venda_forn(int p_cod, int qtd);
    void registrar_venda_forn();
};

#endif