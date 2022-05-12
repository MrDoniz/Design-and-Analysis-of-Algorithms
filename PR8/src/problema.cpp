#include "../include/problema.hpp"

#include <algorithm>
#include <cmath>
#include <sstream>

Problema::Problema(string fichero) {
  fichero_nombre_ = fichero;
  fichero_.open(fichero, std::fstream::in);
  analizarFichero();
}

Problema::Problema(const Problema& problema) {
  puntos_size_ = problema.puntos_size_;
  dimension_size_ = problema.dimension_size_;
  lista_puntos_ = problema.lista_puntos_;
  fichero_nombre_ = problema.fichero_nombre_;
}

string Problema::getFichero() const { return fichero_nombre_; }

int Problema::getPuntosSize() const { return puntos_size_; }

int Problema::getDimensionSize() const { return dimension_size_; }

vector<Punto> Problema::getListaPuntos() const { return lista_puntos_; }

Punto Problema::getPunto(int id) {
  for (auto&& punto : lista_puntos_) {
    if (punto.getId() == id) {
      return punto;
    }
  }
  return Punto(-1);
}

void Problema::analizarFichero() {
  parsePuntosSize();
  parseDimensionSize();
  parsePuntos();
}

void Problema::parsePuntosSize() {
  std::string line;
  getline(fichero_ >> std::ws, line);
  puntos_size_ = std::stoi(line);
}

void Problema::parseDimensionSize() {
  std::string line;
  getline(fichero_ >> std::ws, line);
  dimension_size_ = std::stoi(line);
}

void Problema ::parsePuntos() {
  std::string line;
  int punto_id = 0;
  while (getline(fichero_ >> std::ws, line)) {
    std::stringstream iss(line);
    string coordenada_valor;
    Punto punto(punto_id);
    while (iss >> coordenada_valor) {
      replace(coordenada_valor.begin(), coordenada_valor.end(), ',', '.');
      punto.addCoordenada(std::stof(coordenada_valor));
    }
    lista_puntos_.push_back(punto);
    punto_id++;
  }
}

vector<Punto> Problema::puntosSinProcesar(vector<Punto> puntosProcesados) {
  vector<Punto> puntosSinProcesar;
  copy_if(lista_puntos_.begin(), lista_puntos_.end(),
          back_inserter(puntosSinProcesar),
          [&puntosProcesados](Punto punto) {
            for (auto&& puntoProcesado : puntosProcesados) {
              if (punto.getId() == puntoProcesado.getId()) {
                return false;
              }
            }
            return true;
          });
  return puntosSinProcesar;
}

float Problema::calcularDistanciaEuclidean(Punto punto1, Punto punto2) const {
  float distancia = 0;
  int dimension_size = punto1.getCoordenadas().size();
  for (int i = 0; i < dimension_size; i++) {
    distancia += pow(punto1.getCoordenadas()[i] - punto2.getCoordenadas()[i], 2);
  }
  return sqrt(distancia);
}

Punto Problema::calcularCentro(vector<Punto> puntos) const {
  Punto centro;
  int dimension_size = puntos[0].getCoordenadas().size();
  for (int j = 0; j < dimension_size; j++) {
    float suma = 0;
    for (unsigned i = 0; i < puntos.size(); i++) {
      suma += puntos[i].getCoordenadas()[j];
    }
    centro.addCoordenada(suma / puntos.size());
  }
  return centro;
}

Problema& Problema::operator=(const Problema& problema) {
  puntos_size_ = problema.puntos_size_;
  dimension_size_ = problema.dimension_size_;
  lista_puntos_ = problema.lista_puntos_;
  fichero_nombre_ = problema.fichero_nombre_;
  return *this;
}

ostream& operator<<(ostream& os, const Problema& problema) {
  os << problema.puntos_size_ << "\n";
  os << problema.dimension_size_ << "\n";
  for (auto&& point : problema.lista_puntos_) {
    os << point;
  }
  return os;
}