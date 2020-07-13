#include "Estabelecimento.hpp"
#include "Cliente.hpp"


#include <iostream>
#include <string>



int main(int argc, char* argv[]) {
    Estabelecimento est("Supermercado");
    int shopping, op;
    double saldo_c, saldo_ad;
    std::string prod_nome;
    do{
        std::cout << "Qual o saldo do cliente?" << std::endl;
        std::cin >> saldo_c;
        Cliente c(saldo_c);
        do{
            std::cout << "------------------" << std::endl;
            std::cout << "| Menu de Opções |" << std::endl;
            std::cout << "------------------" << std::endl;
            std::cout << "1- Listar produtos no estoque" << std::endl;
            std::cout << "2- Aumentar saldo" << std::endl;
            std::cout << "3- Realizar compra" << std::endl;
            std::cout << "4- Verificar sacola" << std::endl;
            std::cout << "0- Sair" << std::endl;
            std::cin >> op;
            switch(op){
                case 1:
                    est.listar();
                    break;
                case 2:
                    std::cout << "Digite o saldo a ser adicionado" << std::endl;
                    std::cin >> saldo_ad;
                    c.aumentaSaldo(saldo_ad);
                    break;
                case 3:
                    std::cin.ignore();
                    std::cout << "Digite o nome do produto: " ;
                    getline(std::cin,prod_nome);
                    c.compra(prod_nome, &est);
                    break;
                case 4:
                    c.verSacola();
                    break;
                case 0:
                    std::cout << "Bye!" << std::endl;
                    break;
                default:
                    std::cout << "Opção Inválida" << std::endl;
                    break;
            }
        }while(op!=0);
        std::cout << "Digite 1 para a criação de outro cliente" << std::endl;
        std::cin >> shopping;
    }while(shopping==1);
}
