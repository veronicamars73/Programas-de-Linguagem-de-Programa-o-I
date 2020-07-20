#include "Conta.hpp"
#include "Cliente.hpp"
#include "ClientePJ.hpp"
#include "ClientePF.hpp"
#include "Agencia.hpp"
#include "Fila.hpp"
#include "Gerente.hpp"
#include "Caixa.hpp"
#include "Seguranca.hpp"

#include <iostream>



int main(int argc, char* argv[]) {
    Agencia a1("Agencia 1", 2083);
    Agencia a2("Agencia 2", 2084);
    ClientePF c1(45);
    c1.setDocumento("092.127.434-44");
    c1.setDescricao("Jane Doe");
    ClientePF c2(40);
    c2.setDocumento("092.127.435-44");
    c2.setDescricao("Poor Jane Doe");
    ClientePF c3(35);
    c3.setDocumento("092.127.453-44");
    c3.setDescricao("john doe");
    ClientePF c4(17);
    c4.setDocumento("092.009.453-43");
    c4.setDescricao("another john doe");
    ClientePJ cj1("Jane Doe");
    cj1.setDocumento("092.127.987-44");
    cj1.setDescricao("Jane Doe Empresa");
    ClientePJ cj2("Poor Jane Doe");
    cj2.setDocumento("092.127.987-44");
    cj2.setDescricao("Poor Jane Doe Empresa");
    ClientePJ cj3("john doe");
    cj3.setDocumento("092.127.987-44");
    cj3.setDescricao("john doe Empresa");
    ClientePJ cj4("another john doe");
    cj4.setDocumento("092.009.987-43");
    cj4.setDescricao("another john doe Empresa");

    Conta conta_um(1233, 50000.00, c1, a1);
    Conta conta_dois(1345, 200.00, c2, a2);
    std::cout << "Conta de " << conta_um.titular.getDescricao() << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.getDescricao() << " " <<  conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_um.saca(10000.00);
    std::cout << "Conta de " << conta_um.titular.getDescricao() << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.getDescricao() << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_dois.saca(200.00);
    std::cout << "Conta de " << conta_um.titular.getDescricao() << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.getDescricao() << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_um.deposita(1000.00);
    std::cout << "Conta de " << conta_um.titular.getDescricao() << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.getDescricao() << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_dois.deposita(10.00);
    std::cout << "Conta de " << conta_um.titular.getDescricao() << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.getDescricao() << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_um.transfere(1000.00, conta_dois);
    std::cout << "Conta de " << conta_um.titular.getDescricao() << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.getDescricao() << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    conta_dois.transfere(1010.00, conta_um);
    std::cout << "Conta de " << conta_um.titular.getDescricao() << " " << conta_um.agenciaDaConta.nome << " " << conta_um.numero << ":" << conta_um.saldo << std::endl;
    std::cout << "Conta de " << conta_dois.titular.getDescricao() << " " << conta_dois.agenciaDaConta.nome << " " << conta_dois.numero << ":" << conta_dois.saldo << std::endl;
    std::cout << "A quantidade de contas é " << Conta::qtd_contas << std::endl;

    Fila<Cliente> clientes(3);
    clientes.add(c1);
    clientes.add(c2);
    clientes.add(c3);
    clientes.add(c4);
    clientes.remove();
    clientes.remove();
    clientes.remove();
    clientes.remove();
    clientes.isEmpty();

    Fila<ClientePJ> clientesPJ(3);
    clientesPJ.add(cj1);
    clientesPJ.add(cj2);
    clientesPJ.add(cj3);
    clientesPJ.add(cj4);
    clientesPJ.remove();
    clientesPJ.remove();
    clientesPJ.remove();
    clientesPJ.remove();
    clientesPJ.isEmpty();

    Gerente g("Compras");
    g.setNome("Roberto");
    g.setSexo("Masculino");
    g.setIdade(23);
    Seguranca s("Sargente");
    s.setNome("Eliana");
    s.setSexo("Feminino");
    s.setIdade(32);
    Caixa c(32);
    c.setNome("Elliot");
    c.setSexo("Masculino");
    c.setIdade(58);

    std::cout << g.getNome() << " " << g.getIdade() << " " << g.getSexo() << " " << g.getDepartamento() << std::endl;
    std::cout << s.getNome() << " " << s.getIdade() << " " << s.getSexo() << " " << s.getPatente() << std::endl;
    std::cout << c.getNome() << " " << c.getIdade() << " " << c.getSexo() << " " << c.getNumero_do_caixa() << std::endl;
}
