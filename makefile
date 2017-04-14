CC = gcc
#CSTD = -std=c99
OPT = -O5
CWARN = -Wall -Wextra -pedantic -Werror 
#CWARN = -Wall -Werror 
CFLAGS = $(CWARN) $(OPT) $(CSTD)
#CLIBS = `pkg-config --libs --cflags LIBRERIASAQUI`
BINARY = Tarea1

all: main.o anagramas.o sintil.de.fn.o
	$(CC) -o $(BINARY) $^ $(CLIBS)
	
main.o: main.c
	$(CC) -c $< -o $@ $(CFLAGS)

sintil.de.fn.o: sintil.de.fn.c
	$(CC) -c $< -o $@ $(CFLAGS)
anagramas.o: anagramas.c
	$(CC) -c $< -o $@ $(CFLAGS)
#	$(CC) -c anagramas.c -o anagramas.o $(CFLAGS) 
debug: mainG.o anagramasG.o
	$(CC) -o $(BINARY) $^ $(CLIBS) -g
	
mainG.o: main.c
	$(CC) -c $< -o $@ $(CWARN) $(CSTD) -g

anagramasG.o: anagramas.c
	$(CC) -c $< -o $@ $(CWARN) $(CSTD) -g
	
clean:
	rm *.o *.gch $(BINARY) || true