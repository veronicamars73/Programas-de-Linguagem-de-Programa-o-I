#include "ClientePF.hpp"


ClientePF::ClientePF() {
}

ClientePF::ClientePF(int idade): idade(idade) {
}

void ClientePF::setIdade(int idade){
	this->idade = idade;
}

int ClientePF::getIdade(){
	return this->idade;
}