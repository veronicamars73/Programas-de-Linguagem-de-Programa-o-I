#include "Conta.hpp"
#include "Cliente.hpp"
#include "Agencia.hpp"


#include <iostream>



int main(int argc, char* argv[]) {
    Agencia a1("Agencia 1", 2083);
    Agencia a2("Agencia 2", 2084);
    Cliente c1("092.127.434-44", "Jane Doe");
    Cliente c2("092.127.435-44", "Poor Jane Doe");
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
}
