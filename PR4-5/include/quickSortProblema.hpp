#include <vector>
#include <algorithm> 

#include "problema.hpp"
#include "quickSortSolucion.hpp"

using namespace std;
#pragma once

class QuickSortProblema : public Problema {
  public:
    QuickSortProblema(vector<int>);
    virtual ~QuickSortProblema();

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
    string a = "2";
    string b = "n/2";
    string c = "n";
};
