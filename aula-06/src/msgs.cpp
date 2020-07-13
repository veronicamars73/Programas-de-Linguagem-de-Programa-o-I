#include "msgs.h"
#include "datahora.h"



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
	Message msg;
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