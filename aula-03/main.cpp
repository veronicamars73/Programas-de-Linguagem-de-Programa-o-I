#include <iostream>
#include <string>
#include <fstream>

const std::string filename="arquivo.txt";

void bad_use(std::string program);
void writeinfile(std::string mensagem, std::ofstream &outfile);

int main(int argc, char *argv[]) {
	std::string mensagem;

	switch(argc) {
		case 2:
			if(std::string(argv[1]) != "add"){
				bad_use(argv[0]);
				return -1;
			}
			std::cout << "Digite a Mensagem: ";
			std::getline(std::cin, mensagem);
			break;
		case 3:
			if(std::string(argv[1]) != "add"){
				bad_use(argv[0]);
				return -1;
			}
			mensagem = argv[2];
			break;
		default:
			bad_use(argv[0]);
    		return -1;
	}

	std::ofstream record(filename,std::ios::app);
	if(record.fail()){
		std::cerr << "Erro ao abrir o arquivo" << std::endl;
		return -1;
	}
	writeinfile(mensagem, record);
	std::cout << "Mensagem " << mensagem << " Adicionada" << std::endl;
	record.close();
	return 0;
}


void bad_use(std::string program){
	std::cout << "Uso: " << program << " add <mensagem>" << std::endl;
}

void writeinfile(std::string mensagem, std::ofstream &outfile){
	outfile << mensagem << std::endl;
}