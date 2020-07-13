#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <string>

struct Diary
{
    Diary(const std::string& filename);
    ~Diary();

    std::string filename;
    Message* messages;
    size_t message_size;
    size_t message_max;

    void add(const std::string& message);
    void write();
    Message* search(const std::string& message);
}; 
#endif
