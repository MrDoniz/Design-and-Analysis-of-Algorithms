#include "../include/quickSortProblema.hpp"

QuickSortProblema::QuickSortProblema(std::vector<int> data) : Problema::Problema() {
  _data = data;
}

QuickSortProblema::~QuickSortProblema() {}

bool QuickSortProblema::esCasoMinimo() {
  if (_data.size() == 1 ) 
    return true;
  return false;
}

std::pair<Problema*, Problema*> QuickSortProblema::descomponer() {
  std::pair<Problema*, Problema*> subProblemas;
  int i = 0; // izq
  int j = _data.size() - 1;
  int pivote = _data[i];
  int aux;
  do {
    while ((_data[i] < pivote)) {
      i++;
    }
    while ((pivote < _data[j])) {
      j--;
    }
    if (i <= j) {
      aux = _data[i];
      _data[i] = _data[j];
      _data[j] = aux;
      i++; j--;
    }
  } while (i <= j);
  std::vector<int> vec1(_data.begin(), _data.begin() + ((i + j)/2 + 1));
  std::vector<int> vec2(_data.begin() + ((i + j) / 2 + 1), _data.end());
  subProblemas.first = new QuickSortProblema(vec1);
  subProblemas.second = new QuickSortProblema(vec2);
  return subProblemas;
}

void QuickSortProblema::solver(Solucion* sol) {
  // algorithm
  std::vector<int> auxVec = ((QuickSortSolucion*)sol)->_data;
  auxVec.push_back(_data[0]);
  // set value
  ((QuickSortSolucion*)sol)->setData(auxVec);
}