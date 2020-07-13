#include "Conta.hpp"

#include <iostream>


int main(int argc, char* argv[]) {
    Conta conta_um(1233, 50000.00, "Jane Doe");
    Conta conta_dois(1345, 200.00, "Poor Jane Doe");
    std::cout << "Conta de " << conta_um.titular << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_um.saca(10000.00);
    std::cout << "Conta de " << conta_um.titular << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_dois.saca(200.00);
    std::cout << "Conta de " << conta_um.titular << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_um.deposita(1000.00);
    std::cout << "Conta de " << conta_um.titular << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_dois.deposita(10.00);
    std::cout << "Conta de " << conta_um.titular << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_um.transfere(1000.00, conta_dois);
    std::cout << "Conta de " << conta_um.titular << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_dois.transfere(1010.00, conta_um);
    std::cout << "Conta de " << conta_um.titular << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
}
