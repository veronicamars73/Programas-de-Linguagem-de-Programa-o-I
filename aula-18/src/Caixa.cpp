#include "Caixa.hpp"

Caixa::Caixa() {
}

Caixa::Caixa(int numero_do_caixa): numero_do_caixa(numero_do_caixa) {
}

void Caixa::setNumero_do_caixa(int numero_do_caixa){
	this->numero_do_caixa = numero_do_caixa;
}
int Caixa::getNumero_do_caixa(){
	return this->numero_do_caixa;
}
