#ifndef W5N_CONTA_H
#define W5N_CONTA_H

#include <string>
#include "Cliente.hpp"
#include "Agencia.hpp"

class Conta{
    public:
    int numero;
    Cliente titular;
    Agencia agenciaDaConta;
    double saldo;

    Conta();
    Conta(int numero, double saldo, Cliente titular, Agencia agenciaDaConta);

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta& conta_recebe);
};

#endif
