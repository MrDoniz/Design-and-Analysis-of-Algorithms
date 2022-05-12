#include <iostream>
#include <iomanip>
#include "../include/cinta.hpp"
#include "../include/memoria.hpp"
#include "../include/programa.hpp"
#include "../include/instruccion.hpp"
#include "../include/ram.hpp"

using namespace std;

// Almacena en la instrucción el operando y operador.
// Si el operando es HALT termina la ejecución.
// De forma cíclica:
//   De lo contrario, almacena la instrucción en el simulador y lo ejecuta.
//   Si se ha activado el salto, lo realiza y calcula el contador de programa.
//   Obtiene la siguiente instrucción a ejecutar y aumenta el contador de instrucciones ejecutadas.
// Muestra la cinta resultante y la escribe en el fichero de salida.
void ejecutar (RAM &simulador, int contador_programa, Instruccion &instruccion, 
              Programa &programa, int contador, Memoria &memoria) {
  //simulador.mostrarEtiquetas();
  try {
    simulador.mostrarEntrada();
    instruccion.set(programa.obtenerInstruccion(contador_programa));
    while (!instruccion.isHalt()) {
      simulador.setInstruccion(instruccion);
      simulador.ejecutar();
      if (instruccion.salto) {
        if (simulador.siguienteInstruccion() != -1) {
          contador_programa = simulador.siguienteInstruccion() ;
        } else
          contador_programa++;
      } else
        contador_programa++;
      instruccion.set(programa.obtenerInstruccion(contador_programa));
      contador++;
    }
    simulador.mostrarSalida();
    cout << "Se han ejecutado " << contador + 1 << " instrucciones\n";
    simulador.escribirArchivo();
  }
  catch (string &e) {
    cout << e << "\n";
  }
}

int main(int argc, char *argv[]) {
  Programa programa(argv[1]);
  CintaEntrada entrada(argv[2]);
  CintaSalida salida(argv[3]);
  Memoria memoria;
  Instruccion instruccion;
  RAM simulador(memoria, programa, entrada, salida);
  programa.mostrarInstruccion();
  ejecutar(simulador, 0, instruccion, programa, 0, memoria);
}