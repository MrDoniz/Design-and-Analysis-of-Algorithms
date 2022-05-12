#include <iostream>
#include <vector>
#include "punto.hpp"

using namespace std;
#pragma once

class Solucion {
  public:
    Solucion() {}
    Solucion(vector<Punto> list_puntos);
    ~Solucion() {}

    void agregarPunto(Punto punto);
    vector<Punto> getListaPuntos() const;
    vector<Punto>& getListaPuntos();
    float calcularDistanciaEuclidean(Punto primero, Punto segundo) const;
    float calcularObjetivoFunction() const;
    friend ostream& operator<<(ostream& os, const Solucion& solucion);
  private:
    vector<Punto> lista_puntos_;
};