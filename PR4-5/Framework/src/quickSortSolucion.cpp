#include "../include/quickSortSolucion.hpp"

QuickSortSolucion::QuickSortSolucion() : Solucion::Solucion() {}

QuickSortSolucion::~QuickSortSolucion() {}

void QuickSortSolucion::resolver() {
  for (unsigned i = 0; i < _data.size(); i++) {
    std::cout << _data[i] << " ";
  }
  std::cout << std::endl;
}

void QuickSortSolucion::mezcla(std::pair<Solucion*, Solucion*> subSoluciones) {
  std::vector<int> vec1 = (((QuickSortSolucion*)subSoluciones.first)) -> _data;
  std::vector<int> vec2 = (((QuickSortSolucion*)subSoluciones.second)) -> _data;
  // imprimir tamaño del vector
  for (unsigned i = 0; i < vec1.size(); i++) {
    _data.push_back(vec1[i]);
  }
  for (unsigned i = 0; i < vec2.size(); i++) {
    _data.push_back(vec2[i]);
  }
}

Solucion* QuickSortSolucion::getInstance() {
  return new QuickSortSolucion();
}

void QuickSortSolucion::setData(std::vector<int> data) {
  _data = data;
}

std::vector<int> QuickSortSolucion::getData() {
  return _data;
}