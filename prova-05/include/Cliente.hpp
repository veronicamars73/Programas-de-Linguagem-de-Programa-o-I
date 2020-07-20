#ifndef W5N_CLIENTE_H
#define W5N_CLIENTE_H

#include <string>
#include "Vector.hpp"
#include "Produto.hpp"
#include "Estabelecimento.hpp"

class Cliente{
    public:
    int codigo;
    double saldo;
    Vector_Supermercado<std::string> sacola;

    static int qtd_clientes;

    Cliente();
    Cliente(double saldo);
    ~Cliente();
    void aumentaSaldo(double saldo_ad);
    int compra(std::string nome_produto, Estabelecimento* est);
    void verSacola();
    void registro();
};

#endif