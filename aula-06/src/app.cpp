#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

#include "msgs.h"
#include "datahora.h"
#include "use.h"




int main(int argc, char *argv[]) {
	std::string mensagem;

	switch(argc) {
		case 2:
			if(std::string(argv[1]) == "add"){
				std::cout << "Digite a Mensagem: ";
				std::getline(std::cin, mensagem);
			}else{
				if(std::string(argv[1]) != "list"){
					bad_use(argv[0]);
					return -1;
				}
			}
			break;
		case 3:
			if(std::string(argv[1]) == "add"){
				mensagem=argv[2];
			}else{
				if(std::string(argv[1]) != "list"){
					bad_use(argv[0]);
					return -1;
				}
			}
			break;
		default:
			bad_use(argv[0]);
    		return -1;
	}
	if(std::string(argv[1]) == "add"){
		int test=0;
		std::ifstream archive("arquivo.md");
		if(archive.is_open()){
			if(dateExists(archive)==-1){
			test=1;
			}
		}else{
			test=1;
		}
		archive.close();
		std::ofstream record("arquivo.md",std::ios::app);
		if(record.fail()){
			std::cerr << "Erro ao abrir o arquivo" << std::endl;
			return -1;
		}
		if(test){
			writedateinfile(record);
		}
		Mesage
		writemsginfile(mensagem, record);
		std::cout << "Mensagem " << mensagem << " Adicionada" << std::endl;
		record.close();
	}else{
		std::ifstream archive("arquivo.md");
		if(archive.fail()){
			std::cerr << "Erro ao abrir o arquivo" << std::endl;
			return -1;
		}
		readingfile(archive);
		archive.close();
	}
	
	return 0;
}