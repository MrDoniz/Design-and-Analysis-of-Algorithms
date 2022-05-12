#include <vector>
#include <utility>
#include <iostream>

#include "solucion.hpp"

using namespace std;
#pragma once

class Problema {
  public:
    Problema(int numeroCiudades, vector<vector<int>> distancias);
    ~Problema();

    unsigned getNumeroCiudades();
    int getCoste(int ciudadOrigen, int ciudadDestino);
    string toString();
    
  private:
    string nombreCiudad(int numero);
    void setNumeroCiudades(int numeroCiudades);
    vector<vector<int>> getDistancias();
    void setDistancias(vector<vector<int>> distancias);

    int numeroCiudad;
    vector<vector<int>> distancias;
};
