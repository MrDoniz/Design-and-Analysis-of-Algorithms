#include <vector>
#include <utility>
#include <iostream>

#include "solucion.hpp"

using namespace std;
#pragma once

class Problema {
  public:
    Problema() {};
    virtual ~Problema() {};

    virtual bool esCasoMinimo() = 0;
    virtual pair<Problema*,Problema*> descomponer() = 0;
    virtual void solver(Solucion* s) {};
    
    virtual vector<string> getRecurrencia() = 0;
};
