#include <vector>
#include <algorithm>

#include "solucion.hpp"
#include "problema.hpp"

using namespace std;
#pragma once

class FuerzaBruta {
  public:
    FuerzaBruta();
    ~FuerzaBruta();
    
    Solucion resolver(Problema problema, Solucion subSolucion);
    
    void resolverFuerzaBruta(Problema problema, Solucion subSolucion);
    Solucion getSolucionActual();
    void setSolucionActual(Solucion solucionActual);
    int getCIUDAD_INICIAL();
    
  private:
    Solucion solucionActual;
    int ciudad_inicial = 0;
};