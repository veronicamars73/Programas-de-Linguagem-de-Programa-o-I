#include <iostream>
#include <string>
#include <fstream>

const std::string filename="arquivo.txt";

void bad_use(std::string program);
void writeinfile(std::string mensagem, std::ofstream &outfile);
void readingfile(std::ifstream &infile);

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
		std::ofstream record(filename,std::ios::app);
		if(record.fail()){
			std::cerr << "Erro ao abrir o arquivo" << std::endl;
			return -1;
		}
		writeinfile(mensagem, record);
		std::cout << "Mensagem " << mensagem << " Adicionada" << std::endl;
		record.close();
	}else{
		std::ifstream archive(filename);
		if(archive.fail()){
			std::cerr << "Erro ao abrir o arquivo" << std::endl;
			return -1;
		}
		readingfile(archive);
		archive.close();
	}
	
	return 0;
}


void bad_use(std::string program){
	std::cout << "Uso: " << program << " add <mensagem> or " << program << " list " << std::endl;
}

void writeinfile(std::string mensagem, std::ofstream &outfile){
	outfile << mensagem << std::endl;
}

void readingfile(std::ifstream &infile){
	std::string lineofFile;
	int numberoflines=0;
	while(!infile.eof()){
		std::getline(infile, lineofFile);
		if(lineofFile.size()==0){
			continue;
		}
		numberoflines++;
		std::cout << numberoflines << "- "<< lineofFile << std::endl;
	}
}
