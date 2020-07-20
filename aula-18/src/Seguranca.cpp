#include "Seguranca.hpp"

Seguranca::Seguranca() {
}

Seguranca::Seguranca(std::string patente): patente(patente) {
}

void Seguranca::setPatente(std::string patente){
	this->patente = patente;
}
std::string Seguranca::getPatente(){
	return this->patente;
}