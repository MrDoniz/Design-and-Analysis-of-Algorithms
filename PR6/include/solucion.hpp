#include <vector>
#include <utility>
#include <iostream>
#include <string.h>

using namespace std;
#pragma once

class Solucion {
  public:
    Solucion();
    Solucion(int distanciaMinima, vector<int> ruta);
    ~Solucion();

    void incrementarDistancia(int distancia);
    void agregarCiudad(int ciudad);
    int obtenerUltimaCiudad();
    int getDistanciaMinima();
    void setDistanciaMinima(int distanciaMinima);
    vector<int> getRuta();
    void setRuta(vector<int> ruta);
    string toString();
    bool buscarEnRuta( int ciudad);

  private:
    int distanciaMinima;
    vector<int> ruta;
};
