#include "../include/Diary.h"
#include "../include/Message.h"
#include "../include/Date.h"
#include "../include/Time.h"

Diary::Diary(const std::string& filename) : filename(filename), message_size(0),messages(nullptr){
	message_max = 10;
	messages = new Message[message_max];

}

void Diary::add(const std::string& message) {
    if (message_size>=message_max){
    	return;
    }
    Date dummy_date(4,5,2000);
    Time dummy_time(12,55,20);
    Message aux(message,dummy_date,dummy_time);
    messages[message_size] = aux;
    message_size = message_size + 1;
}

void Diary::write(){
    //delete[] messages;
}
