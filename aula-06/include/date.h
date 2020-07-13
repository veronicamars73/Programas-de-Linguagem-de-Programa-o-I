#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>
#include <string>

struct Date{
	unsigned dia;
	unsigned mes;
	unsigned ano;

	void format_from_string(const std::string& format);
};

std::string get_current_date();
std::string get_current_time();

#endif