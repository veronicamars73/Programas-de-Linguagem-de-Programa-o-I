#include "Agencia.hpp"


Agencia::Agencia() : numero(0), nome("John Doe") {
}

Agencia::Agencia(std::string nome, int numero): nome(nome), numero(numero) {
}
