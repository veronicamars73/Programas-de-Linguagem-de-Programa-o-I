#include "../include/Diary.h"
#include "../include/Message.h"
#include "../include/Date.h"
#include "../include/Time.h"
#include "../include/Helpers.h"


Diary::Diary(const std::string& filename) : filename(filename), message_size(0), messages(nullptr) {
	message_max = 10;
	messages = new Message[message_max];

}

Diary::~Diary() {
    delete[] messages;
}

void Diary::add(const std::string& message) {
    if (message_size>=message_max){
    	return;
    }

    Date now_date(0,0,0);
    Time now_time(0,0,0);
    now_date.set_from_string_date(get_current_date());
    now_time.set_from_string_time(get_current_time());
    Message aux(message,now_date,now_time);
    messages[message_size] = aux;
    message_size = message_size + 1;
}

void Diary::write(){
    //delete[] messages;
}
