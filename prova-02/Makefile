PROG = supermercado
CC = g++
CPPFLAGS = -O0 -std=c++11 -g -I include
OBJS = main.o Cliente.o Estabelecimento.o Produto.o

all: $(PROG)

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

Estabelecimento.o :  include/Estabelecimento.hpp
	$(CC) $(CPPFLAGS) -c src/Estabelecimento.cpp

Produto.o :  include/Produto.hpp
	$(CC) $(CPPFLAGS) -c src/Produto.cpp

Cliente.o :  include/Cliente.hpp
	$(CC) $(CPPFLAGS) -c src/Cliente.cpp

clean:
	rm -f *.o
	rm $(PROG)
