#include "../include/App.h"
#include "../include/Date.h"
#include "../include/Time.h"
#include "../include/Helpers.h"
#include "../include/Message.h"
#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        if (argc == 2)
        {
            list_messages();
        }else{
            show_usage(argv[0]);
        }
        
    } else if (action == "search") {
        Message* pointer;
        if (argc == 2) {
            pointer = search();
        } else {
            pointer = search(argv[2]);
        }
        result_search(pointer);
    } else {
        return show_usage(argv[0]);
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    
}

Message* App::search()
{
    std::string looked;
    std::cout << "Enter the text to be searched:" << std::endl;
    std::getline(std::cin, looked);

    return search(looked);
}

Message* App::search(const std::string looked)
{
    return diary.search(looked);
    
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.message_size; ++i) {
        Message message = diary.messages[i];
        print_message(message);
    }
}

void App::print_message(Message message)
{
    std::cout << "- " << message.date.get_date_string() << " " << message.time.get_time_string() << " " << message.content << std::endl;
}

void App::result_search(Message* pointer){
    if (pointer != nullptr){
        std::cout << "Term found at the " << pointer - diary.messages + 1 << "th message of the diary.\n";
        std::cout << "The message content is:" << std::endl;
        print_message(*pointer);
        return;
    }
    std::cout << "Term not found" << std::endl;
}