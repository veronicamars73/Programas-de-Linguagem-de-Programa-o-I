#include "Motor.hpp"


Motor::Motor() : potencia(1), marca("Honda"){
}

Motor::Motor(double potencia, std::string marca): potencia(potencia), marca(marca) {
} 


void Motor::partida(){
    std::cout << "Carro ligado" << std::endl;
}
