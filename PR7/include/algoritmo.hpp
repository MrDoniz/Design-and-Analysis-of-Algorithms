#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "solucion.hpp"

using namespace std;
#pragma once

class Algoritmo {
  public:
    pair<int, int> distanciaMinima(Instancia &problema, pair<int, int> &ruta_ij) {
      int coordi = ruta_ij.second;
      int distancia_minima = 999;
      int nodo_minimo = 0;
      vector<int>vectorVisitadosTemporales;
      for (int j = 1; j < problema.getNumeroClientes(); j++) {
        if (problema.getVisitado(j) == false) {
          if (problema.getDistancia(coordi, j) < distancia_minima && problema.getDistancia(coordi, j) != 0) {
            distancia_minima = problema.getDistancia(coordi, j);
            nodo_minimo = j;
            problema.visitar(nodo_minimo, true);
            vectorVisitadosTemporales.push_back(nodo_minimo);
          }
        }
      }
      for (unsigned i = 0; i < vectorVisitadosTemporales.size(); i++) {
        problema.visitar(vectorVisitadosTemporales[i], false);
      }
      problema.visitar(nodo_minimo, true);
      pair<int, int> salida(coordi, nodo_minimo);
      return salida;
    }

    pair<int, int> eleccionAleatoria(Instancia &problema, vector<pair<int, int>> &mejores_ij) {
      int elegido = rand() % mejores_ij.size();
      for (unsigned i = 0; i < mejores_ij.size(); i++) {
        problema.visitar(mejores_ij[i].second, false);
      }
      problema.visitar(mejores_ij[elegido].second, true);
      return mejores_ij[elegido];
    }

    void preProcesamiento(Instancia &problema) {
      numero_rutas_ = problema.getNumeroVehiculos();
      numeroClientes_ = problema.getNumeroClientes();
      ruta_ij.resize(numero_rutas_);
    }

    void almacenarResultado(Instancia &problema, Solucion &solucion) {
      solucion.reiniciar();
      solucion.almacenarAtributos(tiempo_, numero_rutas_, numeroClientes_);
      solucion.almacenarRuta(problema, ruta_ij);
      //cout << "test" << endl;
      //cout << "Coste: " << solucion.getCosteTotal() << endl;
      //solucion.mostrarRuta(problema);
    }
  protected:
    int tiempo_ = 0;
    int numero_rutas_;
    unsigned numeroClientes_;
    vector<vector<pair<int, int>>> ruta_ij;
};