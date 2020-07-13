#ifndef W5N_APP_H
#define W5N_APP_H

#include "Diary.h"
#include "Message.h"


#include <string>

struct App
{
    Diary diary;

    App(const std::string& filename);
    int run(int argc, char* argv[]);
    
    void add();
    void add(const std::string message);
    Message* search();
    Message* search(const std::string looked);
    void list_messages();
    void print_message(Message message);
    void result_search(Message* pointer);
}; 
#endif