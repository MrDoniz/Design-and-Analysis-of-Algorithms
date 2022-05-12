#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "problema.hpp"
#include "ruta.hpp"
#include "algoritmo.hpp"
#include "solucion.hpp"

using namespace std;
#pragma once

class Voraz : public Algoritmo {
  public:
    Voraz(){};
    ~Voraz(){};
    void ejecutar(Instancia problema, Solucion solucion);
    void resolverVoraz(Instancia &problema);

};