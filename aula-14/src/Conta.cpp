#include "Conta.hpp"

#include "Cliente.hpp"
#include "Agencia.hpp"

Conta::Conta() : numero(1), saldo(0){
}

Conta::Conta(int numero, double saldo, Cliente titular, Agencia agenciaDaConta):
numero(numero), saldo(saldo), titular(titular), agenciaDaConta(agenciaDaConta) {
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
