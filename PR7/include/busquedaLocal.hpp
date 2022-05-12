#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "algoritmo.hpp"

using namespace std;
#pragma once

class BusquedaLocal : public Algoritmo {
  public:
  BusquedaLocal(int metodo) {
    metodoBusqueda = metodo;
  }

  Solucion ejecutar(Instancia &problema, Solucion &solucion) {
    generarVecinos(problema, solucion);
    Solucion mejorSolucion = solucion;
    //mejorSolucion.mostrarRuta(problema);
    for (unsigned vecino = 0; vecino < vecinos.size(); vecino++) {
      if (vecinos[vecino].getCosteTotal() < mejorSolucion.getCosteTotal()) {
        mejorSolucion = vecinos[vecino];
      }
    }
    //mejorSolucion.mostrarRuta(problema);
    return mejorSolucion;
  }

  void generarVecinos(Instancia &problema, Solucion &solucion) {
    switch (metodoBusqueda) {
      case 1:
        intraReinsercion(problema, solucion);
        break;
      case 2:
        interReinsercion(problema, solucion);
        break;
      case 3:
        intraCambio(problema, solucion);
        break;
      case 4:
        interCambio(problema, solucion);
        break;
        break;
      case 5:
        dosOpt(problema, solucion);
        break;
    }
  }

  void intraReinsercion(Instancia &problema, Solucion &solucionPrevia) {
    vecinos.clear();
    for(int ruta = 0; ruta < solucionPrevia.getNumeroRutas(); ruta++) {
      for(int pos1 = 1; pos1 < solucionPrevia.getNumeroClientes(ruta) - 1; pos1++) {
        for(int pos2 = pos1 + 1; pos2 < solucionPrevia.getNumeroClientes(ruta) - 2; pos2++) {
          Solucion solucionActual = solucionPrevia;
          pair<int, int> cliente1 = solucionPrevia.getRuta()[ruta][pos1];
          solucionActual.eliminar(cliente1, ruta, pos1, problema);
          solucionActual.reInsertar(cliente1, ruta, pos2, problema);
          solucionActual.actualizarCoste(problema);
          vecinos.push_back(solucionActual);
        }
      }
    }
  }

  void interReinsercion(Instancia &problema, Solucion &solucionPrevia) {
    vecinos.clear();
    Solucion solucionActual = solucionPrevia;
    for(int ruta1 = 0; ruta1 < solucionPrevia.getNumeroRutas(); ruta1++) {
      for(int ruta2 = 0; ruta2 < solucionPrevia.getNumeroRutas(); ruta2++) {
        if (ruta1  != ruta2) {
          for(int pos1 = 1; pos1 < solucionPrevia.getNumeroClientes(ruta1) - 1; pos1++) {
            for(int pos2 = pos1 + 1; pos2 < solucionPrevia.getNumeroClientes(ruta2) - 1; pos2++) {
              solucionActual = solucionPrevia;
              pair<int, int> cliente1 = solucionPrevia.getRuta()[ruta1][pos1];
              solucionActual.eliminar(cliente1, ruta1, pos1, problema);
              solucionActual.reInsertar(cliente1, ruta2, pos2, problema);
              solucionActual.actualizarCoste(problema);
              vecinos.push_back(solucionActual);
            }
          }
        }
      }
    }
  }

  void intraCambio(Instancia &problema, Solucion &solucionPrevia) {
    vecinos.clear();
    for(int ruta = 0; ruta < solucionPrevia.getNumeroRutas(); ruta++) {
      for(int pos1 = 2; pos1 < solucionPrevia.getNumeroClientes(ruta) - 1; pos1++) {
        for(int pos2 = pos1 + 1; pos2 < solucionPrevia.getNumeroClientes(ruta) - 1; pos2++) {
          Solucion solucionActual = solucionPrevia;
          pair<int, int> cliente1 = solucionPrevia.getRuta()[ruta][pos1];
          pair<int, int> cliente2 = solucionPrevia.getRuta()[ruta][pos2];
          //cout << "Cliente 1: " << cliente1.first << " pos 1: " << pos1 << " Cliente 2: " << cliente2.first << " pos 2: " << pos2 << endl;
          solucionActual.insertar(cliente2, ruta, pos1, problema);
          solucionActual.insertar(cliente1, ruta, pos2, problema);
          solucionActual.actualizarCoste(problema);
          vecinos.push_back(solucionActual);
        }
      }
    }
  }

  void interCambio(Instancia &problema, Solucion &solucionPrevia) {
    vecinos.clear();
    for(int ruta1 = 0; ruta1 < solucionPrevia.getNumeroRutas(); ruta1++) {
      for(int ruta2 = 0; ruta2 < solucionPrevia.getNumeroRutas(); ruta2++) {
        if (ruta1  != ruta2) {
          for(int pos1 = 1; pos1 < solucionPrevia.getNumeroClientes(ruta1) - 1; pos1++) {
            for(int pos2 = pos1 + 1; pos2 < solucionPrevia.getNumeroClientes(ruta2) - 1; pos2++) {
              Solucion solucionActual = solucionPrevia;
              pair<int, int> cliente1 = solucionPrevia.getRuta()[ruta1][pos1];
              pair<int, int> cliente2 = solucionPrevia.getRuta()[ruta2][pos2];
              solucionActual.insertar(cliente2, ruta1, pos1, problema);
              solucionActual.insertar(cliente1, ruta2, pos2, problema);
              solucionActual.actualizarCoste(problema);
              vecinos.push_back(solucionActual);
            }
          }
        }
      }
    }
  }

  void dosOpt(Instancia &problema, Solucion &solucionPrevia) {
    vecinos.clear();
    Solucion solucionActual = solucionPrevia;
    for(int ruta = 0; ruta < solucionPrevia.getNumeroRutas(); ruta++) {
      for(int pos1 = 1; pos1 < solucionPrevia.getNumeroClientes(ruta) - 1; pos1++) {
        for(int pos2 = pos1 + 1; pos2 < solucionPrevia.getNumeroClientes(ruta) - 1; pos2++) {
          // https://en.wikipedia.org/wiki/2-opt
        }
      }
    }
  }

  void setMetodoBusqueda(int metodo) {
    metodoBusqueda = metodo;
  }

  private:
    vector<Solucion> vecinos;
    int metodoBusqueda;
};