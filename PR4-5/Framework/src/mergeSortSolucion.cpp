#include "../include/mergeSortSolucion.hpp"

MergeSortSolucion::MergeSortSolucion() : Solucion::Solucion() {}

MergeSortSolucion::~MergeSortSolucion() {}

void MergeSortSolucion::resolver() {
  for (unsigned i = 0; i < _data.size(); i++) {
    std::cout << _data[i] << " ";
  }
  std::cout << std::endl;
}

void MergeSortSolucion::mezcla(std::pair<Solucion*, Solucion*> subSoluciones) {
  std::vector<int> vec1 = (((MergeSortSolucion*)subSoluciones.first)) -> _data;
  std::vector<int> vec2 = (((MergeSortSolucion*)subSoluciones.second)) -> _data;
  int sizeVec1 = vec1.size();
  int sizeVec2 = vec2.size();
  int totalSize = sizeVec1 + sizeVec2;
  _data.resize(totalSize);
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < sizeVec1 && j < sizeVec2) {
    if (vec1[i] <= vec2[j]) {
      _data[k] = vec1[i];
      i++;
    } else {
      _data[k] = vec2[j];
      j++;
    }
    k++;
  }
  while (i < sizeVec1) {
    _data[k] = vec1[i];
    i++;
    k++;
  }
  while (j < sizeVec2) {
    _data[k] = vec2[j];
    j++;
    k++;
  }
}

Solucion* MergeSortSolucion::getInstance() {
  return new MergeSortSolucion();
}

void MergeSortSolucion::setData(std::vector<int> data) {
  _data = data;
}

std::vector<int> MergeSortSolucion::getData() {
  return _data;
}