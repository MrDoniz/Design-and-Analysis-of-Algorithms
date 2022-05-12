CC = g++
CFLAGS = -std=c++14 -g -Wall

F1 = main.cpp
F2 = ciudades.cpp
F3 = fuerzaBruta.cpp
F4 = programacionDinamica.cpp
F5 = voraz.cpp
F6 = problema.cpp
F7 = solucion.cpp
F8 = temporizador.cpp

IDIR = include/
ODIR = src/
LDIR = lib/

PROGRAM = tsp

all: $(PROGRAM)
$(PROGRAM): $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) $(ODIR)$(F5) $(ODIR)$(F6) $(ODIR)$(F7) $(ODIR)$(F8)
	$(CC) $(CFLAGS) $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) $(ODIR)$(F5) $(ODIR)$(F6) $(ODIR)$(F7) $(ODIR)$(F8) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)