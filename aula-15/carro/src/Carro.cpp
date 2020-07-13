#include "Carro.hpp"

int Carro::qtd_carros;

Carro::Carro():  tipo("Sedan"), placa("1233-XYZ"), numPortas(4), velocidade(80), cor("Vermelho"), motor(){
	qtd_carros = qtd_carros + 1;
}

Carro::Carro(std::string tipo, std::string placa, int numPortas, int velocidade, std::string cor, Motor motor):
tipo(tipo), placa(placa), numPortas(numPortas), velocidade(velocidade), cor(cor), motor(motor){
	qtd_carros = qtd_carros + 1;
}

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}

void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}

void Carro::ligaCarro(){
    motor.partida();
}
