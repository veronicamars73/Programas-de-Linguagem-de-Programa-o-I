#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

#include "../include/app.h"




int main(int argc, char *argv[]) {
	App aplicativo("diary.md");
    return aplicativo.run(argc, argv);
}