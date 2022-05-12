#include "../include/ruta.hpp"

void Ruta::mostrar() {
  cout << "Ruta: ";
  for (unsigned i = 0; i < ruta.size(); i++) {
    cout << ruta[i] << " ";
  }
  cout << endl;
}

void Ruta::setRuta(int coste) {
  ruta.push_back(coste);
}

int Ruta::resultado(){
  int suma = 0;
  for (unsigned i = 0; i < ruta.size(); i++) {
    suma += ruta[i];
  }
  return suma;
}