#ifndef W5N_Estabelecimento_H
#define W5N_Estabelecimento_H

#include <string>
#include <vector>
#include "Vector.hpp" 
#include "Produto.hpp"
#include "ProdutoFornecedor.hpp"
#include "Fornecedor.hpp"

class Estabelecimento{
    public:
    std::string nome;
    Vector_Supermercado<Produto> produtos;

    Estabelecimento(std::string nome);
    Estabelecimento(std::string nome, Vector_Supermercado <Produto> produtos);
    void listar();
    int venda(int cod_p);
    void caixa();
    void record_estoque();
    void record_sales();
    void reabastecer(Fornecedor* f, ProdutoFornecedor p);
    void addProduto(int pos, int qtd);
};

#endif