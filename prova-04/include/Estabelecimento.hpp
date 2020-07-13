#ifndef W5N_Estabelecimento_H
#define W5N_Estabelecimento_H

#include <string>
#include <list> 
#include "Produto.hpp"

class Estabelecimento{
    public:
    std::string nome;
    std::list <Produto> produtos;

    Estabelecimento(std::string nome);
    Estabelecimento(std::string nome, std::list <Produto> produtos);
    void listar();
    int venda(int cod_p);
    void caixa();
    void record_estoque();
    void record_sales();
};

#endif