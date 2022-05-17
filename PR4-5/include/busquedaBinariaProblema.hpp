#include <vector>
#include <algorithm>

#include "problema.hpp"
#include "busquedaBinariaSolucion.hpp"

using namespace std;
#pragma once

class BusquedaBinariaProblema : public Problema {
  public:
    BusquedaBinariaProblema(vector<int>, int);
    virtual ~BusquedaBinariaProblema();

    void solver(Solucion*);
    pair<Problema*, Problema*> descomponer();
    bool esCasoMinimo();

    void setData(vector<int>);
    vector<int> getData();

    vector<string> getRecurrencia() {
      return {a, b, c};
    }
  private:
    vector<int> _data;
    int _valor;
    string a = "2";
    string b = "n-1";
    string c = "1";
};