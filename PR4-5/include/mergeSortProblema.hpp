#include <vector>
#include <algorithm>

#include "problema.hpp"
#include "mergeSortSolucion.hpp"

using namespace std;
#pragma once

class MergeSortProblema : public Problema {
  public:
    MergeSortProblema(vector<int>);
    virtual ~MergeSortProblema();

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