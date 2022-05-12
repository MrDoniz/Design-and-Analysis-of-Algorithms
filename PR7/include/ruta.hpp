#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "problema.hpp"
#include "nodo.hpp"

using namespace std;
#pragma once

class Ruta {
  public:
    Ruta(){};
    ~Ruta(){};
    void mostrar();
    void setRuta(int coste);
    int resultado();
  private:
    vector<int> ruta;
};