CC = g++
CFLAGS = -std=c++14 -g -Wall

F1 = main.cpp
F2 = framework.cpp
F3 = mergeSortSolucion.cpp
F4 = mergeSortProblema.cpp
F5 = quickSortSolucion.cpp
F6 = quickSortProblema.cpp
F4 = mergeSortProblema.cpp
F7 = problema.cpp
F8 = solucion.cpp
F9 = torresHanoiSolucion.cpp
F10 = torresHanoiProblema.cpp
F11 = busquedaBinariaSolucion.cpp
F12 = busquedaBinariaProblema.cpp

IDIR = include/
ODIR = src/
LDIR = lib/

PROGRAM = framework

all: $(PROGRAM)
$(PROGRAM): $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) $(ODIR)$(F5) $(ODIR)$(F6) $(ODIR)$(F7) $(ODIR)$(F8) $(ODIR)$(F9) $(ODIR)$(F10) $(ODIR)$(F11) $(ODIR)$(F12)
	$(CC) $(CFLAGS) $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) $(ODIR)$(F5) $(ODIR)$(F6) $(ODIR)$(F7) $(ODIR)$(F8) $(ODIR)$(F9) $(ODIR)$(F10) $(ODIR)$(F11) $(ODIR)$(F12) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)