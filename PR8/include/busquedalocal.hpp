#include "solucion.hpp"
#include "vecinos/algoritmoVecinos.hpp"

using namespace std;
#pragma once

class BusquedaLocal {
  public:
    BusquedaLocal(AlgoritmoVecinos* vecinos_algoritmo);
    ~BusquedaLocal() {}

    Solucion ejecutar(Solucion& solucion);
  private:
    AlgoritmoVecinos* vecinos_algoritmo_;
};