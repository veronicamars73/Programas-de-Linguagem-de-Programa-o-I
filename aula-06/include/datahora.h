#ifndef DATAHORA_H
#define DATAHORA_H
#include <iostream>
#include <ctime>
#include <string>

struct Date{
	int dia;
	int mes;
	int ano;
};
struct Time{
	int hora;
	int minuto;
	int segundo;
};

std::string format_current_date(const std::string& format);
std::string get_current_date();
std::string get_current_time();

#endif