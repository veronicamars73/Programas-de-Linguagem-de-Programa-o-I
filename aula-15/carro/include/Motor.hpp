#include <iostream>
#include <string>

class Motor{
    public:
    int potencia;
    std::string marca;

    Motor();
    Motor(double potencia, std::string marca);

    void partida();
};
