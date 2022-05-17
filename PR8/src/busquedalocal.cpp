#include "../include/busquedalocal.hpp"

BusquedaLocal::BusquedaLocal(AlgoritmoVecinos* vecinos_algoritmo) {
  vecinos_algoritmo_ = vecinos_algoritmo;
}

Solucion BusquedaLocal::ejecutar(Solucion& solucion, Problema &problema) {
  Solucion mejor_solucion = solucion;
  do {
    solucion = mejor_solucion;
    std::vector<Solucion> vecinos =
        vecinos_algoritmo_->generarVecino(solucion, problema);
    for (auto&& vecino : vecinos) {
      if (vecino.calcularObjetivoFunction() >
          mejor_solucion.calcularObjetivoFunction()) {
        mejor_solucion = vecino;
      }
    }

  } while (mejor_solucion.calcularObjetivoFunction() !=
           solucion.calcularObjetivoFunction());
  return mejor_solucion;
}
