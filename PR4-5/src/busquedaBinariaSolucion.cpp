#include "../include/busquedaBinariaSolucion.hpp"

BusquedaBinariaSolucion::~BusquedaBinariaSolucion() {}

void BusquedaBinariaSolucion::resolver() {
  if (_data[0] == _valor) {
    std::cout << "El valor " << _valor << " se encuentra en el vector" << std::endl;
  } else {
    std::cout << "El valor " << _valor << " no se encuentra en el vector" << std::endl;
  }
}

void BusquedaBinariaSolucion::mezcla(std::pair<Solucion*, Solucion*> subSoluciones) {
  vector<int> vec1 = (((BusquedaBinariaSolucion*)subSoluciones.first)) -> _data;
  _data = vec1;
}

Solucion* BusquedaBinariaSolucion::getInstance() {
  return new BusquedaBinariaSolucion(_valor);
}

void BusquedaBinariaSolucion::setData(std::vector<int> data) {
  _data = data;
}

std::vector<int> BusquedaBinariaSolucion::getData() {
  return _data;
}