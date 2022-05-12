#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "nodo.hpp"

using namespace std;
#pragma once

class Instancia {
  public:
    Instancia(string nombreFichero);
    ~Instancia();
    void leerInstancia();
    int getNumeroClientes();
    int getNumeroVehiculos();
    int getDistancia(int i, int j);
    void visitar(int j, bool valor);
    bool todosVisitados();

    bool getVisitado(int j);
    vector<vector<Nodo>> getDistanciaTotal();
  private:
    string nombreFichero_;
    int n_clientes;
    int n_vehiculos;
    vector<vector<Nodo>> distancia;
    int visitados_ = 0;
    vector<pair <int, bool>> visitados;
};