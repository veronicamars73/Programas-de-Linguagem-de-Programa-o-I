#include "Produto.hpp"

Produto::Produto(){
	
}

Produto::Produto(int codigo, std::string nome, std::string unidadeDeMedida, double preco, int qtd): 
codigo(codigo), nome(nome), unidadeDeMedida(unidadeDeMedida), preco(preco), qtd(qtd) {
}
 