#include <vector>
#include <utility>
#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <time.h>
#include <math.h>

#include "problema.hpp"
#include "solucion.hpp"

using namespace std;
#pragma once

class ProgramacionDinamica {
  public:
    ProgramacionDinamica();
    ~ProgramacionDinamica();

    Solucion resolverConProgramacionDinamica(Problema problema);
    void obtenerRuta(int comienzo, int set, vector<vector<int>> &tablaConLasRutas, Solucion solucion);
    int algoritmoDinamico(int comienzo, int set, vector<vector<int>> &tabla, vector<vector<int>> &tablaConLasRutas, Problema problema);
    int getNumeroCiudades();
    void setNumeroCiudades(int numeroCiudades);
    int getPosibilidades();
    void setPosibilidades(int posibilidades);
    int getCIUDAD_INICIAL();
  
  private:
    int numeroCiudades;
    int posibilidades;
    int ciudad_inicial = 0;
};