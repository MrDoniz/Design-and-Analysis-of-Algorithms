#include "../include/busquedaBinariaProblema.hpp"

BusquedaBinariaProblema::BusquedaBinariaProblema(std::vector<int> data, int valor) : Problema::Problema() {
  _data = data;
  _valor = valor;
}

BusquedaBinariaProblema::~BusquedaBinariaProblema() {}

bool BusquedaBinariaProblema::esCasoMinimo() {
  if (_data.size() == 1) {
    return true;
  }
  return false;
}

pair<Problema*, Problema*> BusquedaBinariaProblema::descomponer() {
  pair<Problema*, Problema*> subProblems;
  int inicio = 0;
  int fin = _data.size() - 1;
  int medio = (inicio + fin) / 2;
  int i = 0;
  int j = _data.size() - 1;
  vector<int> vec1(_data.begin(), _data.begin() + ((i + j)/2 + 1));
  vector<int> vec2(_data.begin() + ((i + j) / 2 + 1), _data.end());

  if (_data[medio] >= _valor) {
    subProblems.first = new BusquedaBinariaProblema(vec1, _valor);
  } else {
    subProblems.first = new BusquedaBinariaProblema(vec2, _valor);
  }
  return subProblems;
}

void BusquedaBinariaProblema::solver(Solucion* sol) {
  vector<int> auxVec = ((BusquedaBinariaSolucion*)sol) -> _data;
  auxVec.push_back(_data[0]);
  ((BusquedaBinariaSolucion*)sol)->setData(auxVec);
}