#include "../include/solucion.hpp"

#include <cmath>

Solucion::Solucion(vector<Punto> lista_puntos) {
  lista_puntos_ = lista_puntos;
}

vector<Punto> Solucion::getListaPuntos() const {
  return lista_puntos_;
}

vector<Punto>& Solucion::getListaPuntos() {
  return lista_puntos_;
}

void Solucion::agregarPunto(Punto punto) {
  lista_puntos_.push_back(punto);
}

float Solucion::calcularObjetivoFunction() const {
  float funcion_objetivo = 0;
  for (size_t i = 0; i < lista_puntos_.size(); i++) {
    for (size_t j = i + 1; j < lista_puntos_.size(); j++) {
      funcion_objetivo +=
          calcularDistanciaEuclidean(lista_puntos_[i], lista_puntos_[j]);
    }
  }
  return funcion_objetivo;
}

float Solucion::calcularDistanciaEuclidean(Punto primero, Punto segundo) const {
  float distancia = 0;
  unsigned dimension_size = primero.getCoordenadas().size();
  for (size_t i = 0; i < dimension_size; i++) {
    distancia += pow(primero.getCoordenadas()[i] - segundo.getCoordenadas()[i], 2);
  }
  return sqrt(distancia);
}

ostream& operator<<(ostream& os, const Solucion& solucion) {
  os << "ObjetivoFunction: " << solucion.calcularObjetivoFunction() << "\n";
  for (auto&& punto : solucion.getListaPuntos()) {
    os << punto;
  }
  os << "\n";
  return os;
}