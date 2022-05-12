CC = g++
CFLAGS = -std=c++14 -g -Wall

F1 = main.cpp
F2 = estrategia.hpp
F2 = matriz.hpp
F2 = interfaz.hpp

IDIR = 
ODIR = 
LDIR =

PROGRAM = analisis

all: $(PROGRAM)
$(PROGRAM): $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4)
	$(CC) $(CFLAGS) $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)