#include "solucion.hpp"
#include "algoritmos/algoritmo.hpp"

using namespace std;
#pragma once

class Estrategia {
  public:
    Estrategia(Algoritmo* algoritmo) : algoritmo_(algoritmo) {};
    ~Estrategia() {}

    Solucion run(Problema problema) {return algoritmo_ -> ejecutar(problema);}
  private:
    Algoritmo* algoritmo_;
};