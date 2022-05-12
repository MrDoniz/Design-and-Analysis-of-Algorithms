CC = g++
CFLAGS = -std=c++14 -g -Wall

F1 = main.cpp
F2 = problema.cpp
F3 = voraz.cpp
F4 = grasp.cpp
F5 = gvns.cpp
F6 = ruta.cpp
F7 = nodo.cpp

IDIR = include/
ODIR = src/
LDIR = lib/

PROGRAM = vrp

all: $(PROGRAM)
$(PROGRAM): $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) $(ODIR)$(F5) $(ODIR)$(F6) $(ODIR)$(F7)
	$(CC) $(CFLAGS) $(ODIR)$(F1) $(ODIR)$(F2) $(ODIR)$(F3) $(ODIR)$(F4) $(ODIR)$(F5) $(ODIR)$(F6) $(ODIR)$(F7) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)