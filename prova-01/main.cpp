#include <iostream>
#include <string>
#include <fstream>
#include <ctime>


const std::string filename="arquivo.md";


void bad_use(std::string program);
void writemsginfile(std::string mensagem, std::ofstream &outfile);
int dateExists(std::ifstream &infile);
void readingfile(std::ifstream &infile);
void writedateinfile(std::ofstream &outfile);
std::string format_current_date(const std::string& format);
std::string get_current_date();
std::string get_current_time();


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
		std::ifstream archive(filename);
		if(archive.is_open()){
			if(dateExists(archive)==-1){
			test=1;
			}
		}else{
			test=1;
		}
		archive.close();
		std::ofstream record(filename,std::ios::app);
		if(record.fail()){
			std::cerr << "Erro ao abrir o arquivo" << std::endl;
			return -1;
		}
		if(test){
			writedateinfile(record);
		}
		writemsginfile(mensagem, record);
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

int dateExists(std::ifstream &infile){
	std::string lineofFile;
	while(!infile.eof()){
		std::getline(infile, lineofFile);
		if (lineofFile=="# "+get_current_date()){
			return 1;
		}
	}
	return -1;
}

void writemsginfile(std::string mensagem, std::ofstream &outfile){
	outfile <<"- "<< get_current_time()<< " " << mensagem << std::endl;
}
void writedateinfile(std::ofstream &outfile){
	outfile <<"\n# "<< get_current_date() << std::endl;
	outfile << std::endl;
}

void readingfile(std::ifstream &infile){
	std::string lineofFile;
	while(!infile.eof()){
		std::getline(infile, lineofFile);
		if(lineofFile.size()==0){
			continue;
		}
		if(lineofFile[0]=='#'){
			continue;
		}
		std::cout << lineofFile << std::endl;
	}
}

std::string format_current_date(const std::string& format) {
	std::time_t time = std::time(nullptr);
	char result[1024];
	std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
	return std::string(result);
}
std::string get_current_date() {
	return format_current_date("%d/%m/%Y");
}
std::string get_current_time(){
	return format_current_date("%H:%M:%S");
}