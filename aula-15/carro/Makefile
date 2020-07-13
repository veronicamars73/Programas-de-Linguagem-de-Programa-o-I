PROG = carro
CC = g++
CPPFLAGS = -O0 -std=c++11 -g -I include
OBJS = main.o Carro.o Motor.o

all: $(PROG)

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

Carro.o :  include/Carro.hpp
	$(CC) $(CPPFLAGS) -c src/Carro.cpp

Motor.o :  include/Motor.hpp
	$(CC) $(CPPFLAGS) -c src/Motor.cpp

clean:
	rm -f *.o
	rm $(PROG)
