#include <vector>
#include <algorithm>

#include "solucion.hpp"

using namespace std;
#pragma once

class BusquedaBinariaSolucion : public Solucion {
  public:
    BusquedaBinariaSolucion(int valor) : Solucion::Solucion() {
      _valor = valor;
    }
    virtual ~BusquedaBinariaSolucion();

    void resolver();
    void mezcla(pair<Solucion*, Solucion*>);
    Solucion* getInstance();

    void setData(vector<int>);
    vector<int> getData();
  private:
    vector<int> _data;
    friend class BusquedaBinariaProblema;
    int _valor;
};