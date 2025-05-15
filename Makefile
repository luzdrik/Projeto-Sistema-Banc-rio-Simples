PROG = contas_bancarias
CC = g++
CPPFLAGS = -O0 -g -Wall -pedantic
LDFLAGS = 

OBJS = main.o

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)


main.o: main.cpp classes.h
	$(CC) $(CPPFLAGS) -c main.cpp


clean:
	rm -f core $(PROG) $(OBJS)
