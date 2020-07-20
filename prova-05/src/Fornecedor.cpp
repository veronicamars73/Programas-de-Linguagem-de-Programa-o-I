#include "Fornecedor.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list> 
#include <algorithm>
#include <iterator> 


Fornecedor::Fornecedor(std::string nome) : nome(nome) {
	std::ifstream archive("fornecedor.csv");
    if(archive.fail()){
        std::cerr << "File not avaliable!" << std::endl;
    }else{
    	std::string lineofFile;
    	while(!archive.eof()){
    		std::getline(archive, lineofFile);
    		std::stringstream ss( lineofFile );
    		std::vector<std::string> result;
    		std::string substr, nome_pf;
			while( ss.good() ) {
			    
			    getline( ss, substr, ',' );
			    
			    result.push_back(substr);
			}

			if("PRODUTO"==result[0] || lineofFile.size()==0){
				continue;
			}

			nome_pf = result[0];
			
			std::stringstream qtd_ss(result[1]);
			int qtd;
			qtd_ss >> qtd;

			ProdutoFornecedor p(nome_pf, qtd);

			this->produtos.push_back(p);
    	}
    }
}



void Fornecedor::listarProdutos(){
	std::cout << "Produtos:" << std::endl;
	std::cout << "PRODUTO,QUANTIDADE" << std::endl;
	for (int i = 0; i < this->produtos.size(); ++i) {
		std::cout << this->produtos.get_element(i).nome << ", " << this->produtos.get_element(i).qtd<< std::endl;
	}
}

int Fornecedor::repassarProdutos(ProdutoFornecedor produtoRepassado){

	std::string pr = produtoRepassado.nome;
	int test=-1;
	std::transform(pr.begin(), pr.end(),pr.begin(), ::toupper);
	for (int j = 0; j < this->produtos.size(); ++j) {
		std::string pl = this->produtos.get_element(j).nome;
		std::transform(pl.begin(), pl.end(),pl.begin(), ::toupper);
		if(pl == pr){
			test = j;
			break;
		}
	}
	if (test == -1){
		std::cout << produtoRepassado.nome << " não foi encontrado.\n";
		return 0;
	}else{
		if(venda_forn(test, produtoRepassado.qtd) == 1){
			std::cout << produtoRepassado.qtd << " unidades de " << produtoRepassado.nome << " foram compradas.\n";
			return 1;
		}else{
			std::cout << produtoRepassado.qtd << " unidades de " << produtoRepassado.nome << " não foram compradas por falta de unidades.\n";
			return 0;
		}
	}
}

int Fornecedor::venda_forn( int p_cod, int qtd){
	if (this->produtos.get_element(p_cod).qtd >= qtd) {
		ProdutoFornecedor p(produtos.get_element(p_cod));
		p.qtd -= qtd;
		this->produtos.to_change(p_cod,p);
		registrar_venda_forn();
		return 1;
	}
	return 0;
}

void Fornecedor::registrar_venda_forn(){
	std::ofstream record_estoque("fornecedor.csv");
	if(record_estoque.fail()){
		std::cerr << "File creation not avaliable." << std::endl;
	}else{
		record_estoque << "PRODUTO,QUANTIDADE" << std::endl;
		for (int i = 0; i < this->produtos.size(); ++i) {
			record_estoque << produtos.get_element(i).nome << ","<< produtos.get_element(i).qtd << "\n";
		}
	}
	record_estoque.close();
}

