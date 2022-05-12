#include "../problema.hpp"
#include "../solucion.hpp"

using namespace std;
#pragma once

class Algoritmo {
  public:
    virtual Solucion ejecutar(Problema &problema) = 0;
};