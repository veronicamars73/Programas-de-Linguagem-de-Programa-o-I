PROG = empresa
CC = g++
CPPFLAGS = -O0 -std=c++11 -g -I include
OBJS = main.o Funcionario.o Empresa.o 

all: $(PROG)

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

Funcionario.o :  include/Funcionario.hpp
	$(CC) $(CPPFLAGS) -c src/Funcionario.cpp

Empresa.o :  include/Empresa.hpp
	$(CC) $(CPPFLAGS) -c src/Empresa.cpp

clean:
	rm -f *.o
	rm $(PROG)
