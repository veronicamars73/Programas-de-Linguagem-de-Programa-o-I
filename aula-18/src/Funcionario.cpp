#include "Funcionario.hpp"


Funcionario::Funcionario() {
}

void Funcionario::setIdade(int t){
	this->idade = t;
}
int Funcionario::getIdade(){
	return this->idade;
}
void Funcionario::setNome(std::string s){
	this->nome = s;
}
std::string Funcionario::getNome(){
	return this->nome;
}
void Funcionario::setSexo(std::string s){
    this->sexo = s;
}
std::string Funcionario::getSexo(){
	return this->sexo;
}