#include "Cliente.hpp"
#include <algorithm>
#include <iostream>
#include <list> 
#include <iterator> 
#include <fstream>

int Cliente::qtd_clientes;

Cliente::Cliente() : codigo(qtd_clientes), saldo(100.00) {
	qtd_clientes = qtd_clientes + 1;
}

Cliente::Cliente(double saldo): codigo(qtd_clientes), saldo(saldo) {
	qtd_clientes = qtd_clientes + 1;
}

Cliente::~Cliente() {
	registro();
}

void Cliente::aumentaSaldo(double saldo_ad) {
	this->saldo += saldo_ad;
}

int Cliente::compra(std::string nome_produto, Estabelecimento* est){
	std::transform(nome_produto.begin(), nome_produto.end(),nome_produto.begin(), ::toupper);
	std::list<Produto>::iterator it;
	for (it = (*est).produtos.begin(); it != (*est).produtos.end(); ++it) {
		std::string nome_test = (*it).nome;
		std::transform(nome_test.begin(), nome_test.end(),nome_test.begin(), ::toupper);
		//boost::to_upper(nome_test);
		if (nome_test == nome_produto){
			if(this->saldo > (*it).preco){
				if((*it).qtd < 1){
					std::cerr << "Estoque insuficiente\n";
					return 1;
				}
				this->saldo -= (*it).preco;
				(*est).venda((*it).codigo);
				this->sacola.push_back((*it).nome);
				std::cout << "Compra realizada com sucesso\n";
				return 0;
			}else{
				std::cerr << "Saldo insuficiente\n";
				return 1;
			}
		}
	}
	std::cerr << "Produto não encontrado\n";
	return 1;
	
}
void Cliente::verSacola(){
	std::cout << "Produtos na sacola:\n";
	for (int i = 0; i < this->sacola.size(); ++i) {
		std::cout << sacola[i] << std::endl;
	}
    
}
void Cliente::registro(){
	std::string s, codigo_s;
	codigo_s = std::to_string(this->codigo);
	s = "Cliente_"+codigo_s+".txt";
	std::ofstream record_sacola(s);
	if(record_sacola.fail()){
		std::cerr << "File creation not avaliable." << std::endl;
	}else{
		record_sacola << "Produtos na sacola:\n";
		for (int i = 0; i < this->sacola.size(); ++i) {
			record_sacola << sacola[i] << std::endl;
		}
	}
	record_sacola.close();
}