#include <vector>
#include <utility>
#include <iostream>

#include "problema.hpp"
#include "solucion.hpp"

using namespace std;
#pragma once

class Framework {
  public:
    Framework();
    virtual ~Framework();
    void divideyVenceras(Problema* p, Solucion* s);
    void divideyVencerasBusquedaBinaria(Problema* p, Solucion* s);
    string getRecurrencia(Problema* problema);
    int getNivel(){ return nivel; };
  private:
    int nivel = -1;
};