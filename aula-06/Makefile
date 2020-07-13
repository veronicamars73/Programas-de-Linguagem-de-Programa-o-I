PROG = diary
CC = g++
CPPFLAGS = -O0 -std=c++11 -g -W -Wall -pedantic
OBJS = main.o msgs.o use.o datahora.o

$(PROG) : $(OBJS)
	$(CC)  $(OBJS)  -o $(PROG)

main.o :
	$(CC) $(CPPFLAGS) -c src/main.cpp

msgs.o : msgs.h
	$(CC) $(CPPFLAGS) -c src/msgs.cpp

datahora.o : datahora.h
	$(CC) $(CPPFLAGS) -c src/datahora.cpp

use.o : use.h
	$(CC) $(CPPFLAGS) -c src/use.cpp

clean:
	rm -f *.o
