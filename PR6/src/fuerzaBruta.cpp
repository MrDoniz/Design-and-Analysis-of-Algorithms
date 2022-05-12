#include "../include/fuerzaBruta.hpp"

FuerzaBruta::FuerzaBruta() {}

FuerzaBruta::~FuerzaBruta() {}

Solucion FuerzaBruta::resolver(Problema problema, Solucion solucionInicial) {
  setSolucionActual(solucionInicial);
  vector<int> rutaInicial;
  rutaInicial.push_back(getCIUDAD_INICIAL());
  Solucion subSolucion(0, rutaInicial);
  resolverFuerzaBruta(problema, subSolucion);

  vector<int> ruta = solucionActual.getRuta();
  ruta.push_back(ruta.at(0));
  solucionActual.setRuta(ruta);

  return getSolucionActual();
}

void FuerzaBruta::resolverFuerzaBruta(Problema problema, Solucion subSolucion) {
  if (subSolucion.getRuta().size() == problema.getNumeroCiudades()) {
    subSolucion.incrementarDistancia(problema.getCoste(subSolucion.obtenerUltimaCiudad(), 0));
    if (subSolucion.getDistanciaMinima() < solucionActual.getDistanciaMinima()) {
      solucionActual.agregarCiudad(0);
      setSolucionActual(subSolucion);
    }
  } else {
    for (unsigned i = 0; i < problema.getNumeroCiudades(); i++) {
      if (!subSolucion.buscarEnRuta(i)) {
        int incremento = subSolucion.getDistanciaMinima() + problema.getCoste(subSolucion.obtenerUltimaCiudad(), i);
        vector<int> rutaIncrementada = subSolucion.getRuta();
        rutaIncrementada.push_back(i);
        Solucion solucionIncrementada(incremento, rutaIncrementada);
        resolverFuerzaBruta(problema, solucionIncrementada);
      }
    }
  }
}

Solucion FuerzaBruta::getSolucionActual() {
  return solucionActual;
}

void FuerzaBruta::setSolucionActual(Solucion solucionActual) {
  this->solucionActual = solucionActual;
}

int FuerzaBruta::getCIUDAD_INICIAL() {
  return ciudad_inicial;
}