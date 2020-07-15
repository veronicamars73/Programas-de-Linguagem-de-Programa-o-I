#include "Conta.hpp"
#include "Cliente.hpp"
#include "ClientePJ.hpp"
#include "Agencia.hpp"
#include "Fila.hpp"


#include <iostream>



int main(int argc, char* argv[]) {
    Agencia a1("Agencia 1", 2083);
    Agencia a2("Agencia 2", 2084);
    Cliente c1("092.127.434-44", "Jane Doe");
    Cliente c2("092.127.435-44", "Poor Jane Doe");
    Cliente c3("092.127.453-44", "john doe");
    Cliente c4("092.009.453-43", "another john doe");
    ClientePJ cj1("092.127.987-44", "Jane Doe Empresa");
    ClientePJ cj2("092.127.987-44", "Poor Jane Doe Empresa");
    ClientePJ cj3("092.127.987-44", "john doe Empresa");
    ClientePJ cj4("092.009.987-43", "another john doe Empresa");

    Conta conta_um(1233, 50000.00, c1, a1);
    Conta conta_dois(1345, 200.00, c2, a2);
    std::cout << "Conta de " << conta_um.titular.nome << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.nome << " " <<  conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_um.saca(10000.00);
    std::cout << "Conta de " << conta_um.titular.nome << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.nome << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_dois.saca(200.00);
    std::cout << "Conta de " << conta_um.titular.nome << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.nome << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_um.deposita(1000.00);
    std::cout << "Conta de " << conta_um.titular.nome << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.nome << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_dois.deposita(10.00);
    std::cout << "Conta de " << conta_um.titular.nome << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.nome << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_um.transfere(1000.00, conta_dois);
    std::cout << "Conta de " << conta_um.titular.nome << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.nome << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_dois.transfere(1010.00, conta_um);
    std::cout << "Conta de " << conta_um.titular.nome << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.nome << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    std::cout << "A quantidade de contas é " << Conta::qtd_contas << std::endl;

    Fila<Cliente> clientes(3);
    clientes.add(c1);
    clientes.add(c2);
    clientes.add(c3);
    clientes.add(c4);
    clientes.remove();
    clientes.remove();
    clientes.remove();
    clientes.remove();
    clientes.isEmpty();

    Fila<ClientePJ> clientesPJ(3);
    clientesPJ.add(cj1);
    clientesPJ.add(cj2);
    clientesPJ.add(cj3);
    clientesPJ.add(cj4);
    clientesPJ.remove();
    clientesPJ.remove();
    clientesPJ.remove();
    clientesPJ.remove();
    clientesPJ.isEmpty();
}
