#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <fstream>
#include <string>
#include "date.h"
#include "time.h"

struct Message{
	Date data;
	Time horario;
	std::string texto;
};


#endif