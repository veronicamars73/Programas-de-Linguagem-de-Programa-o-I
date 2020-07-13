#include <iostream>
#include "Carro.hpp"


using namespace std;

int main(){
    Carro c;
    c.tipo = "Sedan";
    c.numPortas = 4;
    c.placa = "XYZ-0102";

    cout << "Tipo do carro: " << c.tipo << endl;
    cout << "Quantidade de portas: " << c.numPortas << endl;
    cout << "Placa do carro: " << c.placa << endl;
    cout << "A cor do carro é: " << c.cor << endl;
    c.ligaCarro();
    c.acelera(50);
    cout << "A velocidade atual é: " << c.velocidade << "KM/H" << endl;
    c.freia (20);
    cout << "A velocidade atual é: " << c.velocidade << "KM/H" << endl;
    cout << "A quantidade de carros é " << Carro::qtd_carros << endl;
    Carro c2, c3;
    cout << "A quantidade de carros é " << Carro::qtd_carros << endl;
    return 0;
}
