#include "Funcionario.hpp"
#include "Empresa.hpp"

Empresa::Empresa() {
}

Empresa::Empresa(std::string nome, std::string cnpj): nome(nome), cnpj(cnpj) {

} 

void Empresa::setNome(std::string nome){
	this->nome = nome;
}
std::string Empresa::getNome(){
	return this->nome;
}

void Empresa::setCnpj(std::string cnpj){
	this->cnpj = cnpj;
}
std::string Empresa::getCnpj(){
	return this->cnpj;
}

void Empresa::addFuncionario(Funcionario funcionario){
	this->funcionarios.push_back(funcionario);
}
std::vector<Funcionario> Empresa::getFuncionarios(){
	return this->funcionarios;
}

std::vector<Funcionario*> Empresa::getByDepartamento(std::string dep){
	std::vector<Funcionario*> funcionarios_dep;
	for (int i = 0; i < this->funcionarios.size(); ++i) {
		if(dep == this->funcionarios[i].getDepartamento()){
			funcionarios_dep.push_back(&funcionarios[i]);
		}
	}

	return funcionarios_dep;
}