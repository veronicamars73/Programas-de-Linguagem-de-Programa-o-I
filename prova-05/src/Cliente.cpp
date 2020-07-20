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
	for (int i = 0; i != (*est).produtos.size(); ++i) {
		std::string nome_test = (*est).produtos.get_element(i).nome;
		std::transform(nome_test.begin(), nome_test.end(),nome_test.begin(), ::toupper);
		//boost::to_upper(nome_test);
		if (nome_test == nome_produto){
			if(this->saldo > (*est).produtos.get_element(i).preco){
				if((*est).produtos.get_element(i).qtd < 1){
					std::cerr << "Estoque insuficiente\n";
					return 1;
				}
				this->saldo -= (*est).produtos.get_element(i).preco;
				(*est).venda((*est).produtos.get_element(i).codigo);
				this->sacola.push_back((*est).produtos.get_element(i).nome);
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
		std::cout << sacola.get_element(i) << std::endl;
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
			record_sacola << sacola.get_element(i) << std::endl;
		}
	}
	record_sacola.close();
}