#ifndef W5N_DATE_H
#define W5N_DATE_H

#include <string>

struct Date
{
    unsigned year;
    unsigned month;
    unsigned day;

    Date(unsigned year, unsigned month, unsigned day);

    Date();

    void set_from_string_date(const std::string& date);
}; 
#endif
