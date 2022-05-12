#include "algoritmoVecinos.hpp"

#include <algorithm>

using namespace std;
#pragma once

class IntercambioPunto : public AlgoritmoVecinos {
 public:
  vector<Solucion> generarVecino(Solucion& solucion) {
    vector<Solucion> vecinos;
    Solucion solucion_actual = solucion;
    for (size_t i = 0; i < solucion_actual.getListaPuntos().size(); i++) {
      for (size_t j = i + 1; j < solucion_actual.getListaPuntos().size();
           j++) {
        swap(solucion_actual.getListaPuntos()[i],
                  solucion_actual.getListaPuntos()[j]);
        vecinos.push_back(solucion_actual);
      }
    }
    return vecinos;
  }
};