#include "solucion.hpp"
#include "problema.hpp"
#include "vecinos/algoritmoVecinos.hpp"

using namespace std;
#pragma once

class BusquedaLocal {
  public:
    BusquedaLocal(AlgoritmoVecinos* vecinos_algoritmo);
    ~BusquedaLocal() {}

    Solucion ejecutar(Solucion& solucion, Problema &problema);
  private:
    AlgoritmoVecinos* vecinos_algoritmo_;
};