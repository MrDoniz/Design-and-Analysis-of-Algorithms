CC = g++
CFLAGS = -std=c++14 -g -Wall

F1 = main.cpp
F2 = cinta.cpp
F3 = instruccion.cpp
F4 = memoria.cpp
F5 = programa.cpp
F6 = ram.cpp

F2h = cinta.hpp
F3h = instruccion.hpp
F4h = memoria.hpp
F5h = programa.hpp
F6h = ram.hpp

IDIR = include/
ODIR = src/
LDIR = lib/

PROGRAM = simulador

all: $(PROGRAM)
$(PROGRAM): $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) $(ODIR)$(F5) $(ODIR)$(F6)
	$(CC) $(CFLAGS) $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) $(ODIR)$(F5) $(ODIR)$(F6) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)