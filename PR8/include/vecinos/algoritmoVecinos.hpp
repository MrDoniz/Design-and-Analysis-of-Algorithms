#include "../solucion.hpp"

#include <vector>

using namespace std;
#pragma once

class AlgoritmoVecinos {
 public:
  virtual std::vector<Solucion> generarVecino(Solucion& solucion) = 0;
};