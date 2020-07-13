#ifndef W5N_TIME_H
#define W5N_TIME_H

#include <string>

struct Time
{
    unsigned hour;
    unsigned minute;
    unsigned second;

    Time(unsigned hour, unsigned minute, unsigned second);

    Time();

    void set_from_string_time(const std::string& time);
}; 
#endif
