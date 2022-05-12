#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "problema.hpp"
#include "ruta.hpp"
#include "algoritmo.hpp"
#include "solucion.hpp"
#include "grasp.hpp"
#include "busquedaLocal.hpp"

using namespace std;
#pragma once

class Gvns : public Algoritmo {
  public:
    Gvns(){};
    ~Gvns(){};
    
    void ejecutar(Instancia problema, Solucion solucion) {
      tiempo_ = clock();
      solucionArranque_ = generarSolucionArranque(problema);
      Solucion mejorSolucion = solucionArranque_;
      Solucion finalSolucion = solucionArranque_;
      Solucion solucion1 = mejorSolucion;
      Solucion solucion2 = mejorSolucion;
      int iteracion = 0;
      do {
        unsigned k = 1;
        do {
          k++;
          solucion1 = sacudida(problema, mejorSolucion, k);
          solucion2 = VND(problema, solucion1);
          if (solucion2.getCosteTotal() < mejorSolucion.getCosteTotal()) {
            mejorSolucion = solucion2;
            k = 1;
          } else {
            k++;
          }
        } while(k <= kmax_);
        if (mejorSolucion.getCosteTotal() < finalSolucion.getCosteTotal()) {
          finalSolucion = mejorSolucion;
          if (criterioParada_ == true) {
            iteracion = 0;
          }
        } else {
          if (criterioParada_ == true) {
            iteracion++;
          }
        }
        if (criterioParada_ == false) {
          iteracion++;
        }
        mejorSolucion = generarSolucionArranque(problema);
        iteracion++;
      } while(iteracion < iteraciones_);
      tiempo_ = clock() - tiempo_;
      //finalSolucion.mostrarRuta(problema);
      cout << "Coste total: " << finalSolucion.getCosteTotal() << " - Tiempo: " << tiempo_ << endl;
    };

    Solucion generarSolucionArranque(Instancia &problema) {
      Grasp grasp;
      Solucion solucionGrasp;
      grasp.ejecutar(problema, solucionGrasp);
      return solucionGrasp;
    };

    Solucion sacudida(Instancia &problema, Solucion &solucion, unsigned &k) {
      // interReinsercion
      Solucion solucionActual = solucion;
      vector<vector<pair<int, int>>> ruta =  solucionActual.getRuta();
      unsigned pos1 = 0;
      unsigned pos2 = 0;
      do {
        pos1 = (rand() % solucionActual.getRuta()[0].size());
        pos2 = (rand() % solucionActual.getRuta()[1].size());
      } while (pos1 == pos2);
      pair<int, int> cliente1 = solucionActual.getRuta()[0][pos1];
      solucionActual.eliminar(cliente1, 0, pos1, problema);
      solucionActual.reInsertar(cliente1, 1, pos2, problema);
      solucionActual.actualizarCoste(problema);
      return solucionActual;
    };

    // Modificación de la función VND
    Solucion VND(Instancia &problema, Solucion &solucion) {
      Solucion solucionLocal = solucion;
      if (metodo) {
        for (unsigned i = 0; i < 5; i++) {
          BusquedaLocal busquedaLocal(i);
          solucionLocal = busquedaLocal.ejecutar(problema, solucionLocal);
        }
      } else {
        for (unsigned i = 4; i > 0; i--) {
          BusquedaLocal busquedaLocal(i);
          solucionLocal = busquedaLocal.ejecutar(problema, solucionLocal);
        }
      }
      return solucionLocal;
    };

  private:
    Solucion solucionArranque_;
    unsigned kmax_ = 3;
    int iteraciones_ = 100;
    bool ansioso = false;
    bool criterioParada_ = false;
    bool metodo = false;

};