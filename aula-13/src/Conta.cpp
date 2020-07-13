#include "Conta.hpp"


Conta::Conta() : numero(1), saldo(0), titular("John Doe") {
}

Conta::Conta(int numero, double saldo, std::string titular): numero(numero), saldo(saldo), titular(titular) {
}

void Conta::deposita(double valor) {
    this->saldo += valor;
}

void Conta::saca(double valor) {
    this->saldo -= valor;
}

void Conta::transfere(double valor, Conta& conta_recebe) {
	this->saldo -= valor;
    conta_recebe.saldo += valor;
}
