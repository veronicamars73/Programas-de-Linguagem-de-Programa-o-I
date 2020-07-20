PROG = banco
CC = g++
CPPFLAGS = -O0 -std=c++11 -g -I include
OBJS = main.o Conta.o Cliente.o Agencia.o ClientePJ.o ClientePF.o Gerente.o Funcionario.o Caixa.o Seguranca.o

all: $(PROG)

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

Conta.o :  include/Conta.hpp
	$(CC) $(CPPFLAGS) -c src/Conta.cpp

Cliente.o :  include/Cliente.hpp
	$(CC) $(CPPFLAGS) -c src/Cliente.cpp

ClientePJ.o :  include/ClientePJ.hpp
	$(CC) $(CPPFLAGS) -c src/ClientePJ.cpp

ClientePF.o :  include/ClientePF.hpp
	$(CC) $(CPPFLAGS) -c src/ClientePF.cpp

Funcionario.o :  include/Funcionario.hpp
	$(CC) $(CPPFLAGS) -c src/Funcionario.cpp

Gerente.o :  include/Gerente.hpp
	$(CC) $(CPPFLAGS) -c src/Gerente.cpp

Caixa.o :  include/Caixa.hpp
	$(CC) $(CPPFLAGS) -c src/Caixa.cpp

Seguranca.o :  include/Seguranca.hpp
	$(CC) $(CPPFLAGS) -c src/Seguranca.cpp

Agencia.o :  include/Agencia.hpp
	$(CC) $(CPPFLAGS) -c src/Agencia.cpp

clean:
	rm -f *.o
	rm $(PROG)
