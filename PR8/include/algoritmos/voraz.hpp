#include "algoritmo.hpp"
using namespace std;
#pragma once

class Voraz : public Algoritmo {
  public:
    Voraz(int size_solucion);
    Solucion ejecutar(Problema &problema);
    Punto masAlejadoDelCentro(Punto centro, vector<Punto> puntos);
    void borrarPunto(Punto punto_a_borrar, vector<Punto> &puntos);
  private:
    unsigned size_solucion_;
};