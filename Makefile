CPP = g++
CPPFLAGS = -Wall

OBJS = main.o nacional.o estadual.o files.o

trabalho: $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJS)