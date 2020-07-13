PROG = banco
CC = g++
CPPFLAGS = -O0 -std=c++11 -g -I include
OBJS = main.o Conta.o

all: $(PROG)

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

Conta.o :  include/Conta.hpp
	$(CC) $(CPPFLAGS) -c src/Conta.cpp

clean:
	rm -f *.o
	rm $(PROG)
