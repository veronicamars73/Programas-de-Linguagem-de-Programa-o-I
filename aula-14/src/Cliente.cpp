#include "Cliente.hpp"


Cliente::Cliente() : cpf("00000000"), nome("John Doe") {
}

Cliente::Cliente(std::string nome, std::string cpf): cpf(cpf), nome(nome) {
}
