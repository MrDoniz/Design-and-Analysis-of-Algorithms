#include "algoritmoVecinos.hpp"

#include <algorithm>

using namespace std;
#pragma once

class IntercambioPunto : public AlgoritmoVecinos {
 public:
  vector<Solucion> generarVecino(Solucion& solucion, Problema &problema) {
    /*
    cout << "Puntos del problema: " << endl;
    for (auto& punto : problema.getListaPuntos()) {
      cout << punto << endl;
    }
    cout << "Solucion: " << endl;
    for (auto& punto : solucion.getListaPuntos()) {
      cout << punto << endl;
    }

    cout << "OTRO\n";
    */
    vector<Solucion> vecinos;
    Solucion solucion_actual = solucion;
    for (size_t i = 0; i < solucion_actual.getListaPuntos().size(); i++) {
      for (size_t j = i + 1; j < problema.getListaPuntos().size();
           j++) {
        if(solucion_actual.getListaPuntos()[i].getId() != problema.getListaPuntos()[j].getId()) {
          // cout << solucion_actual.getListaPuntos()[i].getId() << "NO" << problema.getListaPuntos()[j].getId() << endl;
          swap(solucion_actual.getListaPuntos()[i],
          problema.getListaPuntos()[j]);
          vecinos.push_back(solucion_actual);
        }
      }
    }
    /*
    //muestro el vector de vecinos
    cout << "VECINOS: " << endl;
    for (auto& vecino : vecinos) {
      cout << vecino << endl;
    }
    */
    return vecinos;
  }
};