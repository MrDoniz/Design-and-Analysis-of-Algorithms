#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "problema.hpp"
#include "voraz.hpp"
#include "algoritmo.hpp"
#include "solucion.hpp"
#include "busquedaLocal.hpp"

using namespace std;
#pragma once

class Grasp : public Algoritmo {
  public:
    Grasp(){};
    ~Grasp(){};
    void ejecutar(Instancia problema, Solucion &solucion);
    void faseConstructiva(Instancia &problema);
    void postProcesamiento(Instancia &problema, Solucion &solucion);
    void actualizar(Instancia &problema);
    bool condicionDeParada(Solucion &solucion);
    void salir(Solucion &solucion);

    Solucion getSolucion(){
      return mejorAmbiente;
    };

    void elegirMetodoBusqueda();
  private:
    int candidatos_ = 5;
    int iteraciones_ = 0;
    int metodoBusqueda_ = 1;
    Solucion mejorLocal_;
    bool salir_ = false;
    int mejorCoste_ = 9999;
    Solucion mejorAmbiente;
};