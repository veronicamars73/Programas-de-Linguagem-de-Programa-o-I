#include <iostream>
#include <string>

void bad_use(std::string &program){
	std::cout << "Uso: " << program << " add <mensagem>" << std::endl;
}

int main(int argc, char *argv[]) {
	std::string mensagem, comando;

	switch(argc) {
		case 2:
			comando = argv[1];
			if(comando != "add"){
				bad_use();
				return -1;
			}
			std::cout << "Digite a Mensagem: ";
			std::cin >> mensagem;
			break;
		case 3:
			comando = argv[1];
			if(comando != "add"){
				bad_use();
				return -1;
			}
			mensagem = argv[2];
			break;
		default:
			bad_use(argv[0]);
    		return -1;
	}
	std::cout << "Mensagem Adicionada" << std::endl;

	return 0;
}