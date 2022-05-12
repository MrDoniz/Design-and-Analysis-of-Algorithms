#include "../include/memoria.hpp"

// Crea una memoria de tamaño 10.
Memoria::Memoria(void) {
  banco_registros_.assign(REGISTRO_SIZE);
}

// Almacena el valor pasado como argumento en la posición de la memoria pasada como argumento.
void Memoria::storev2(int valor, int id_registro) {
  banco_registros_.push(id_registro, valor);
}

// Devuelve el valor de la posición de la memoria pasada como argumento.
int Memoria::load(int id_registro) {
  return banco_registros_[id_registro];
}

void Memoria::reset() {
  banco_registros_.clear();
  banco_registros_.assign(REGISTRO_SIZE);
}

void Memoria::mostrarMemoria(void) {
  if(debug > 1) {
    cout << "Memoria:\n";
    for (int i = 0; i < REGISTRO_SIZE; i++) {
      if (i != REGISTRO_SIZE - 1){
        banco_registros_.mostrarRegistro(i);
        cout << " | ";
      }
      if (i == REGISTRO_SIZE- 1)
        banco_registros_.mostrarRegistro(i);
    }
    cout << "\n\n";
  }
}