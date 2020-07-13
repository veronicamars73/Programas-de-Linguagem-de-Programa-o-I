#ifndef W5N_CONTA_H
#define W5N_CONTA_H

#include <string>

class Conta{
    public:
    int numero;
    std::string titular;
    double saldo;

    Conta();
    Conta(int numero, double saldo, std::string titular);

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta& conta_recebe);
};

#endif
