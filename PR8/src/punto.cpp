#include "../include/punto.hpp"

#include <cmath>

using namespace std;

void Punto::addCoordenada(float valorCoordinada) {
  coordenadas_.push_back(valorCoordinada);
}

vector<float> Punto::getCoordenadas() const { return coordenadas_; }

int Punto::getId() const { return id_; }

void Punto::setId(int id) { id_ = id; }

float Punto::calcularDistanciaEuclidean(Punto primero, Punto segundo) const {
  float distancia = 0;
  unsigned dimension_size = primero.getCoordenadas().size();
  for (size_t i = 0; i < dimension_size; i++) {
    distancia += pow((primero.getCoordenadas()[i] - segundo.getCoordenadas()[i]), 2);
  }
  return sqrt(distancia);
}


ostream& operator<<(ostream& os, const Punto& punto) {
  os << "Id:" << punto.getId() << " | ";
  for (auto&& coordenada : punto.getCoordenadas()) {
    os << coordenada << " ";
  }
  os << "\n";
  return os;
}

Punto::Punto(int id) { id_ = id; }