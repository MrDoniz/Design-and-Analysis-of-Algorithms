#include <vector>
#include <algorithm>

#include "solucion.hpp"

using namespace std;
#pragma once

class QuickSortSolucion : public Solucion {
  private:
    vector<int> _data;
    friend class QuickSortProblema;
  public:
    QuickSortSolucion();
    virtual ~QuickSortSolucion();

    void resolver();
    void mezcla(pair<Solucion*, Solucion*>);
    Solucion* getInstance();

    void setData(vector<int>);
    vector<int> getData();
};