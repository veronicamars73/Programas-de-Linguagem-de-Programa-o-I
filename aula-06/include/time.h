#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <ctime>
#include <string>

struct Time{
	unsigned hora;
	unsigned minuto;
	unsigned segundo;

	void format_from_string(const std::string& format);
};


std::string get_current_date();
std::string get_current_time();

#endif