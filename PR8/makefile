CC = g++
CFLAGS = -std=c++14 -g -Wall

F1 = src/main.cpp

F2 = src/nodo.cpp
F3 = src/punto.cpp
F4 = src/problema.cpp
F5 = src/solucion.cpp

F6 = src/argumentos.cpp
F7 = src/experimento.cpp

F8  = src/voraz.cpp
F9 = src/busquedalocal.cpp
F10 = src/grasp.cpp
F11 = src/ramaypoda.cpp

PROGRAM = ryp

all: $(PROGRAM)
$(PROGRAM): $(F1) $(F2) $(F3) $(F4) $(F5) $(F6) $(F7) $(F8) $(F9) $(F10) $(F11)
	$(CC) $(CFLAGS) $(F1) $(F2) $(F3) $(F4) $(F5) $(F6) $(F7) $(F8) $(F9) $(F10) $(F11) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)