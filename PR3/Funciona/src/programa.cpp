#include "../include/programa.hpp"

// Lee el fichero con el programa RAM, 
// Si una línea empieza por #, se trata de un comentario y por ende no se carga en la máquina RAM.
// Si se encuentra con :, se trata de una etiqueta y por ende guarda en un vector de pares la etiqueta y el número de instrucciones de la etiqueta aneterior.
// Si se encuentra con HALT, se trata de una instrucción que indica que el programa ha terminado.
// Si se encuentra con una instrucción, se trata de una instrucción y por ende se guarda en un vector de instrucciones concatenenado el operador y el operando.
Programa::Programa(char* archivo) {
  fstream fichero;
  fichero.open(archivo);
  string aux;
  string aux2;
  if (fichero.is_open()) {
    while (!fichero.eof()) {
      fichero >> aux;
      if (aux == "#") {
        while (fichero.peek() != '\n') {
          fichero >> aux;
        }
      } else {
        if (aux.back() == ':') {
          aux.pop_back();
          std::pair<std::string, int> etiqueta(aux, instruccion_.size());
          etiqueta_.push_back(etiqueta);
        } else {
          if (aux == "HALT" || aux == "halt") {
            instruccion_.push_back(aux);
          } else {
            aux2 = aux;
            aux2 += " ";
            fichero >> aux;
            aux2 += aux;
            instruccion_.push_back(aux2);
          }
        }
      }
    }
  } else {
    cout << "Error de apertura\n";
  }
  fichero.close();
}

// Muestra por pantalla el contenido del vector de instrucciones.
void Programa::mostrarInstruccion(void) {
  cout << "Instrucciones: \n";
  for (unsigned i = 0; i < instruccion_.size(); i++) {
    if (i != instruccion_.size() - 1)
      cout << i << ":" << instruccion_[i] << " | ";
    if (i == instruccion_.size() - 1)
      cout << i << ":" << instruccion_[i];
  }
  cout << "\n\n";
}

// Muestra por pantalla las etiquetas del programa que se han introducido previamente
// a través del fichero de programa RAM.
void Programa::mostrarEtiqueta(void) {
  cout << "Etiquetas: \n";
  for (unsigned i = 0; i < etiqueta_.size(); i++) {
    if (i != etiqueta_.size() - 1)
      std::cout << etiqueta_[i].first << ":" << etiqueta_[i].second << " | ";
    if (i == etiqueta_.size() - 1)
      std::cout << etiqueta_[i].first << ":" << etiqueta_[i].second;
  }
  std::cout << "\n\n";
}

// Devuelve la instrucción que se encuentra en la posición indicada por parámetro.
std::string Programa::obtenerInstruccion(int posicion) {
  return instruccion_[posicion];
}

// Devuelve la posición de la siguiente instrucción a ejecutar.
int Programa::obtenerSiguienteSalto(string aux) {
  for (unsigned i = 0; i < etiqueta_.size(); i++)
    if (etiqueta_[i].first == aux)
      return etiqueta_[i].second;
  return 0;
}