#include "algoritmo.hpp"
#include "../vecinos/intercambioPunto.hpp"
using namespace std;
#pragma once

class GRASP : public Algoritmo {
  public:
    GRASP(int size_solucion, AlgoritmoVecinos *algoritmo_vecinos,
          int size_lrc = 3, int max_iteraciones = 100);
    virtual ~GRASP() {}

    Solucion ejecutar(Problema &problema);
    Solucion construccionAleatoriaCodiciosa(Problema &problema);
    std::vector<Punto> construirLRC(Problema &problema, Solucion &solution);
    Punto seleccionarCandidatoAleatorio(std::vector<Punto> lrc);
  private:
    AlgoritmoVecinos *algoritmo_vecinos_;
    unsigned size_solucion_;
    unsigned max_iteraciones_ = 100;
    unsigned size_lrc_ = 3;
};