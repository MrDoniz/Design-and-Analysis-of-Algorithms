#include "../include/algoritmos/voraz.hpp"

#include <algorithm>

using namespace std;

Voraz::Voraz(int sizeSolucion) : size_solucion_(sizeSolucion) {}

Solucion Voraz::ejecutar(Problema &problema) {
  vector<Punto> puntos = problema.getListaPuntos();
  Solucion solucion;
  Punto centro = problema.calcularCentro(puntos);
  do {
    Punto punto_mas_alejado = masAlejadoDelCentro(centro, puntos);
    solucion.agregarPunto(punto_mas_alejado);
    borrarPunto(punto_mas_alejado, puntos);
    
    centro = problema.calcularCentro(solucion.getListaPuntos());
  } while (solucion.getListaPuntos().size() < size_solucion_);
  return solucion;
}

Punto Voraz::masAlejadoDelCentro(Punto centro, vector<Punto> puntos) {
  Punto alejado;
  float max_distancia = 0;
  for (auto &&punto : puntos) {
    float distancia = centro.calcularDistanciaEuclidean(centro, punto);
    if (distancia > max_distancia) {
      max_distancia = distancia;
      alejado = punto;
    }
  }
  return alejado;
}

void Voraz::borrarPunto(Punto punto_a_borrar, vector<Punto> &puntos) {
  for (auto &&punto : puntos) {
    puntos.erase(remove_if(puntos.begin(), puntos.end(),
      [punto_a_borrar](Punto punto) {
        return punto.getId() == punto_a_borrar.getId();
      }),
    puntos.end());
  }
}


