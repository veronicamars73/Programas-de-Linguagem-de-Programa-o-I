#include "Estabelecimento.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list> 
#include <iterator> 


Estabelecimento::Estabelecimento(std::string nome) : nome(nome) {
	std::ofstream ofs;
	ofs.open("caixa.csv", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	std::ifstream archive("estoque.csv");
    if(archive.fail()){
        std::cerr << "File not avaliable!" << std::endl;
    }else{
    	std::string lineofFile;
    	while(!archive.eof()){
    		std::getline(archive, lineofFile);
    		std::stringstream ss( lineofFile );
    		std::vector<std::string> result;
    		std::string substr;
			while( ss.good() ) {
			    
			    getline( ss, substr, ',' );
			    
			    result.push_back(substr);
			}

			if("COD"==result[0] || lineofFile.size()==0){
				continue;
			}

			std::string preco_s,inteira, centavos;
			double preco_r;
			inteira = result[3].substr(result[3].find(" ")+1);
			centavos = result[4].substr(0, result[4].find("\""));
			preco_s = inteira + "." + centavos;
			
			std::stringstream preco_ss(preco_s);
			preco_ss >> preco_r;

			std::stringstream cod_ss(result[0]);
			int cod;
			cod_ss >> cod;

			
			std::stringstream qtd_ss(result[5]);
			int qtd;
			qtd_ss >> qtd;

			Produto p(cod,result[1], result[2], preco_r, qtd);

			this->produtos.push_back(p);
    	}
    }
}

Estabelecimento::Estabelecimento(std::string nome, Vector_Supermercado <Produto> produtos):
nome(nome), produtos(produtos) {
}

void Estabelecimento::listar(){
	std::cout << "Produtos:" << std::endl;
	std::cout << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
	for (int i = 0; i < this->produtos.size(); ++i) {
		std::cout << this->produtos.get_element(i).codigo << ", " << this->produtos.get_element(i).nome << ", " << this->produtos.get_element(i).unidadeDeMedida << ", " << this->produtos.get_element(i).preco << ", "<< this->produtos.get_element(i).qtd<< std::endl;
	}
}

int Estabelecimento::venda(int cod_p){
	for (int i = 0; i < this->produtos.size(); ++i) {
		if(this->produtos.get_element(i).codigo==cod_p){
			Produto p(produtos.get_element(i));
			p.qtd -=1;
			this->produtos.to_change(i,p);
			std::ofstream record_venda("caixa.csv",std::ios::app);
			if(record_venda.fail()){
				std::cerr << "File creation not avaliable." << std::endl;
			}else{
				record_venda << this->produtos.get_element(i).codigo << "," << this->produtos.get_element(i).nome << "," << this->produtos.get_element(i).preco << ",1" << "\n";
			}
			record_venda.close();
			record_estoque();
			record_sales();
			return 0;
		}
	}
	std::cerr << "Produto não encontrado" << std::endl;
	return 1;
}

void Estabelecimento::record_sales(){
	std::ifstream archive("caixa.csv");
	std::string lineofFile;
	std::vector<std::string> lines;
	double total;
    if(archive.fail()){
        std::cerr << "File not avaliable!" << std::endl;
    }else{
    	while(!archive.eof()){
    		std::getline(archive, lineofFile);
    		std::stringstream ss( lineofFile );
    		std::vector<std::string> result;
    		std::string substr, aux;
    		while( ss.good() ) {
			    
			    getline( ss, substr, ',' );
			    
			    result.push_back(substr);
			}
			if (lineofFile.find("TOTAL") != std::string::npos || lineofFile.size()==0) {
			    continue;
			}
			int test=0;
			for (int i = 0; i < lines.size(); ++i){
				std::stringstream ss_l( lines[i] );
				std::vector<std::string> lines_att;
				while( ss_l.good() ) {
			    
				    getline( ss_l, substr, ',' );
				    
				    lines_att.push_back(substr);
				}

				if(result[0]==lines_att[0]){
					std::stringstream qtdi_ss(lines_att[3]);
					int qutd;
					qtdi_ss >> qutd;
					qutd += 1;
					lines_att[3]= std::to_string(qutd);
					lines[i] = lines_att[0]+","+lines_att[1]+","+lines_att[2]+","+lines_att[3];
					test = 1;
				}
			}
			if (test==0)
			{
				lines.push_back(lineofFile);
			}
			std::stringstream cod_ss(result[2]);
			double preco;
			cod_ss >> preco;
			int qtd;
			std::stringstream qtd_ss(result[3]);
			qtd_ss >> qtd;
			total = total+(preco*qtd);
    	}
    }
    archive.close();
    std::ofstream record_total("caixa.csv");
	if(record_total.fail()){
		std::cerr << "File creation not avaliable." << std::endl;
	}else{
		for (int i = 0; i < lines.size(); ++i){

			record_total << lines[i] << "\n";
		}
		record_total << "TOTAL: " << total << "\n";
	}
	record_total.close();
}

void Estabelecimento::caixa(){
	std::ifstream archive("caixa.csv");
	std::string lineofFile;
	std::cout << "COD,PRODUTO,PRECO" << std::endl;
    if(archive.fail()){
        std::cerr << "File not avaliable!" << std::endl;
    }else{
    	while(!archive.eof()){
    		std::getline(archive, lineofFile);
    		std::cout << lineofFile << std::endl;
    	}
    }
    archive.close();
}

void Estabelecimento::record_estoque(){
	//listar();
	std::ofstream record_estoque("estoque.csv");
	if(record_estoque.fail()){
		std::cerr << "File creation not avaliable." << std::endl;
	}else{
		record_estoque << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
		for (int i = 0; i != this->produtos.size(); ++i) {
			std::string s,t;
			s = std::to_string(this->produtos.get_element(i).preco);
			t = "\"R$ ";
			for(int i=0; i < s.size() ;i++){
				if(s[i]=='.'){
					t = t + ",";
					t = t + s[i+1] + s[i+2];
					break;
				}else{
					t = t + s[i];
				}
			}
			t = t + "\"";
			record_estoque << this->produtos.get_element(i).codigo << "," << this->produtos.get_element(i).nome << "," << this->produtos.get_element(i).unidadeDeMedida << "," << t << ","  << this->produtos.get_element(i).qtd<< std::endl;
		}
	}
	record_estoque.close();
}

void Estabelecimento::reabastecer(Fornecedor* f, ProdutoFornecedor p){
	std::string pr = p.nome;
	int test = -1;
	std::transform(pr.begin(), pr.end(),pr.begin(), ::toupper);
	for (int i = 0; i < this->produtos.size(); ++i){
		std::string np = this->produtos.get_element(i).nome;
		std::transform(np.begin(), np.end(),np.begin(), ::toupper);
		if(np == pr){
			test = i;
		}
	}
	if(test != -1){
		if((*f).repassarProdutos(p)==1){
			addProduto(test, p.qtd);
		}
	}else{
		std::cout << "Produto não existente no supermercado\n";
	}

}

void Estabelecimento::addProduto(int pos, int qtd){
	Produto p(produtos.get_element(pos));
	p.qtd += qtd;
	this->produtos.to_change(pos, p);
	record_estoque();
}