#include "Cliente.hpp"


Cliente::Cliente() {
}

void Cliente::setTempo_de_cadastro(int t){
	this->tempo_de_cadastro = t;
}
int Cliente::getTempo_de_cadastro(){
	return this->tempo_de_cadastro;
}
void Cliente::setDocumento(std::string s){
	this->documento = s;
}
std::string Cliente::getDocumento(){
	return this->documento;
}
void Cliente::setDescricao(std::string s){
    this->descricao = s;
}
std::string Cliente::getDescricao(){
	return this->descricao;
}