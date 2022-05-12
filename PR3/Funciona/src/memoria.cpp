#include "../include/memoria.hpp"

// Crea una memoria de tamaño 10.
Memoria::Memoria(void) {
  memoria_.resize(10);
}

// Almacena el valor pasado como argumento en la posición de la memoria pasada como argumento.
void Memoria::store(int posicion, int valor) {
  memoria_[posicion] = valor;
}

// Devuelve el valor de la posición de la memoria pasada como argumento.
int Memoria::load(int posicion) {
  return memoria_[posicion];
}

// Muestra por pantalla el contenido del vector de memoria.
void Memoria::mostrarMemoria(void) {
  cout << "Memoria: \n";
  for (unsigned i = 0; i < memoria_.size(); i++) {
    if (i != memoria_.size() - 1)
      cout << i << ":" << memoria_[i] << " | ";
    if (i == memoria_.size() - 1)
      cout << i << ":" << memoria_[i];
  }
  cout << "\n\n";
}