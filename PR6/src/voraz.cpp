#include "../include/voraz.hpp"

Voraz::Voraz() {}
Voraz::~Voraz() {}
  
Solucion Voraz::resolverVorazmente(Problema problema) {
  //Construimos el caso inicial de partida.
  Solucion solucion;
  vector<int> ruta;
  int distanciaTotal = 0;
  unsigned ciudadActual = getCIUDAD_INICIAL();
  ruta.push_back(ciudadActual);
  int mejorCandidato = ciudadActual;
  int distanciaMinima = 9999;
  // Recorremos vorazmente en busca del mejor candidato siempre.
  while (ruta.size() < problema.getNumeroCiudades()) {
    for (unsigned i = 0; i < problema.getNumeroCiudades(); i++) {
      if (i != ciudadActual && find(ruta.begin(), ruta.end(), i) == ruta.end()) {
        if (problema.getCoste(ciudadActual, i) < distanciaMinima) {
          distanciaMinima = problema.getCoste(ciudadActual, i);
          mejorCandidato = i;
        }
      }
    }
    // Actualiza los valores.
    ruta.push_back(mejorCandidato);
    distanciaTotal += distanciaMinima;
    ciudadActual = mejorCandidato;
    distanciaMinima = 9999;
  }

  // Cierra la ruta
  distanciaTotal += problema.getCoste(ruta.at(ruta.size() - 1), 0);
  ruta.push_back(ruta.at(0));
  
  // Construye la solución.
  solucion.setRuta(ruta);
  solucion.setDistanciaMinima(distanciaTotal);
  return solucion;
}

int Voraz::getCIUDAD_INICIAL() {
  return ciudad_inicial;
}