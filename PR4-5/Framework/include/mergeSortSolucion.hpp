#include <vector>
#include <algorithm>

#include "solucion.hpp"

using namespace std;
#pragma once

class MergeSortSolucion : public Solucion {
  private:
    vector<int> _data;
    friend class MergeSortProblema;
  public:
    MergeSortSolucion();
    virtual ~MergeSortSolucion();

    void resolver();
    void mezcla(pair<Solucion*, Solucion*>);
    Solucion* getInstance();

    void setData(vector<int>);
    vector<int> getData();
};