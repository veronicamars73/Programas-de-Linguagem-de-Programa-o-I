PROG = banco
CC = g++
CPPFLAGS = -O0 -std=c++11 -g -I include
OBJS = main.o Conta.o Cliente.o Agencia.o

all: $(PROG)

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

Conta.o :  include/Conta.hpp
	$(CC) $(CPPFLAGS) -c src/Conta.cpp

Cliente.o :  include/Cliente.hpp
	$(CC) $(CPPFLAGS) -c src/Cliente.cpp

Agencia.o :  include/Agencia.hpp
	$(CC) $(CPPFLAGS) -c src/Agencia.cpp

clean:
	rm -f *.o
	rm $(PROG)
