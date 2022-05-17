#include "../include/mergeSortProblema.hpp"

MergeSortProblema::MergeSortProblema(std::vector<int> data) : Problema::Problema() {
  _data = data;
}

MergeSortProblema::~MergeSortProblema() {}

bool MergeSortProblema::esCasoMinimo() {
  if (_data.size() == 1) 
    return true;
  return false;
}

std::pair<Problema*, Problema*> MergeSortProblema::descomponer() {
  std::pair<Problema*, Problema*> subProblemas;
  int index = _data.size() / 2;
  std::vector<int> vec1;
  std::vector<int> vec2;
  for (int i = 0; i < index; i++) {
    vec1.push_back(_data[i]);
  }
  for (unsigned i = index; i < _data.size(); i++) {
    vec2.push_back(_data[i]);
  }
  subProblemas.first = new MergeSortProblema(vec1);
  subProblemas.second = new MergeSortProblema(vec2);
  return subProblemas;
}

void MergeSortProblema::solver(Solucion* sol) {
  std::vector<int> auxVec = ((MergeSortSolucion*)sol)->_data;
  auxVec.push_back(_data[0]);
  ((MergeSortSolucion*)sol)->setData(auxVec);
}