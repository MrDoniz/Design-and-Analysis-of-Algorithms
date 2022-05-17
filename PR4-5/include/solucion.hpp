#include <vector>
#include <utility>
#include <iostream>

using namespace std;
#pragma once

class Solucion {
  public:
    Solucion() {};
    virtual ~Solucion() {};

    virtual void resolver() {};
    virtual void mezcla(pair<Solucion*,Solucion*>) {};
    virtual Solucion* getInstance() = 0;
};
