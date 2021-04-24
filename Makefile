CPP = g++
CPPFLAGS = -Wall

CASOSOBJS = main.o nacional.o estadual.o files.o

trabalho: $(CASOSOBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(CASOSOBJS)

clean :
    rm edit main.o nacional.o estadual.o files.o