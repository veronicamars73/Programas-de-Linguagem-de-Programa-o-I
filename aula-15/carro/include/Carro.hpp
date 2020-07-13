#include <string>
#include "Motor.hpp"


class Carro{
    public:
    std::string tipo;
    std::string placa;
    int numPortas;
    int velocidade;
    std::string cor;
    Motor motor;

    static int qtd_carros;

    Carro(std::string tipo, std::string placa, int numPortas, int velocidade, std::string cor, Motor motor);
    Carro();

    void acelera(int velocidade);
    void freia(int velocidade);
    void ligaCarro();
};
