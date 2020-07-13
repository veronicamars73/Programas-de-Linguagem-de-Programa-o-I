#include "Funcionario.hpp"

Funcionario::Funcionario() {
}

Funcionario::Funcionario(std::string nome, std::string departamento, std::string dataAdmissao, double salario):
nome(nome), departamento(departamento), dataAdmissao(dataAdmissao), salario(salario) {

} 

void Funcionario::setNome(std::string nome){
	this->nome = nome;
}
std::string Funcionario::getNome(){
	return this->nome;
}

void Funcionario::setDepartamento(std::string departamento){
	this->departamento = departamento;
}
std::string Funcionario::getDepartamento(){
	return this->departamento;
}

void Funcionario::setdataAdmissao(std::string dataAdmissao){
	this->dataAdmissao = dataAdmissao;
}
std::string Funcionario::getdataAdmissao(){
	return this->dataAdmissao;
}

void Funcionario::setSalario(double salario){
	this->salario = salario;
}
double Funcionario::getSalario(){
	return this->salario;
}