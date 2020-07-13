#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>

struct Diary
{
    Diary(const std::string& filename);

    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    void writemsginfile(std::string mensagem, std::ofstream &outfile);
	int dateExists(std::ifstream &infile);
	void readingfile(std::ifstream &infile);
	void writedateinfile(std::ofstream &outfile);
	void bad_use(std::string program);
}; 
#endif
