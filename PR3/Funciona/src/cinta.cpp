#include "../include/cinta.hpp"

// Lee el fichero de entrada y almacena en un vector de enteros los valores de la cinta.
CintaEntrada::CintaEntrada(char* archivo) {
  cinta_.resize(10);
  fstream fichero;
  fichero.open(archivo);
  int aux;
  int i = 0;
  if (fichero.is_open()) {
    while (!fichero.eof()) {
      fichero >> aux;
      cinta_[i] = aux;
      i++;
    }
  } else {
    cout << "Error de apertura\n";
  }
  fichero.close();
}

// Almacena el el fichero de salida y crea una cinta de tamaño 10 y con valores -1 en todos sus elementos
CintaSalida::CintaSalida(char* archivo) {
  archivo_ = archivo;
  cinta_.resize(10, -1);
}

// Muestra por pantalla el contenido de la cinta de entrada 
// almacenada previamente en el constructor de la clase.
void CintaEntrada::mostrar(void) {
  cout << "Cinta entrada:\n";
  for (unsigned i = 0; i < cinta_.size(); i++) {
    if (i != cinta_.size() - 1)
      cout << i << ": " << cinta_[i] << " | ";
    if (i == cinta_.size() - 1)
      cout << i << ": " << cinta_[i];
  }
  cout << "\n\n";
}

// Muestra por pantalla el contenido de la cinta de salida 
// almacenada previamente al finalizar el simulador.
void CintaSalida::mostrar(void) {
  cout << "Cinta salida:\n";
  for (unsigned i = 0; i < cinta_.size(); i++) {
    if (i != cinta_.size() - 1)
      cout << i << ": " << cinta_[i] << " | ";
    if (i == cinta_.size() - 1)
      cout << i << ": " << cinta_[i];
  }
  cout << "\n\n";
}

// Devuelve el valor de la posición de la cinta en la que se encuentra el cabezal.
int CintaEntrada::leer(void) {
  cabezal_++;
  return cinta_[cabezal_ - 1];
}

// Escribe el valor pasado como argumento en la la posición de la cinta en la que se encuentra el cabezal.
void CintaSalida::escribir(int valor) {
  cinta_[cabezal_] = valor;
  cabezal_++;
}

// Escribe en el fichero de salida el resultado obtenido al finalizar el simulador en la cinta resultante.
void CintaSalida::escribirArchivo(void) {
  fstream fichero;
  fichero.open(archivo_, fstream::out);
  unsigned i = 0;
  if (fichero.is_open()) {
    while (i < cinta_.size()) {
      fichero << cinta_[i];
      fichero << "\n";
      i++;
    }
  } else {
    cout << "Error de apertura\n";
  }
  fichero.close();
}