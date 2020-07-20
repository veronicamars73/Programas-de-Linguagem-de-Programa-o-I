#include "Gerente.hpp"

Gerente::Gerente() {
}

Gerente::Gerente(std::string departamento): departamento(departamento) {
}

void Gerente::setDepartamento(std::string departamento){
	this->departamento = departamento;
}
std::string Gerente::getDepartamento(){
	return this->departamento;
}