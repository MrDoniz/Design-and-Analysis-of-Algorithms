#include "../include/ram.hpp"

// Construye el simulador de la máquina RAM
// Inicializando los valores de memoria y los diferentes archivos de entrada.
RAM::RAM(Memoria &memoria, Programa &programa, CintaEntrada &entrada, CintaSalida &salida) {
  memoria_ = memoria;
  programa_ = programa;
  entrada_ = entrada;
  salida_ = salida;
}

// Almacena la instrucción en el objeto de la clase.
void RAM::setInstruccion(Instruccion &instruccion) {
  instruccion_ = instruccion;
}

// Devuelve la siguiente instrucción a ejecutar.
int RAM::siguienteInstruccion(void) {
  return salto_;
}

// Llama al método de la clase Programa para mostrar las etiquetas del programa
// que se han introducido previamente a través del fichero de programa RAM.
void RAM::mostrarEtiquetas(void) {
  programa_.mostrarEtiqueta();
}

// Llama al método de la clase CintaEntrada para mostrar el contenido de la cinta
// que se han introducido previamente a través del fichero de cinta de entrada.
void RAM::mostrarEntrada(void) {
  entrada_.mostrar();
}

// Comprueba que instrucción se va a ejecutar y realiza la operación correspondiente con cada operando.
// El funcionamiento de cada operando.
void RAM::ejecutar(void) {
  // Almacena en la el valor de la cinta de entrada en la posición de la memoria de la instrucción.
  if (instruccion_.instruccion_ == "read"  || instruccion_.instruccion_ == "READ") {
    memoria_.store(instruccion_.numero, entrada_.leer());
  // 
  } else if (instruccion_.instruccion_ == "load"  || instruccion_.instruccion_ == "LOAD") {
    if (instruccion_.simbolo == '=') {
      memoria_.store(0, instruccion_.numero);
    } else {
      if (instruccion_.simbolo == '*') {
        memoria_.store(0, memoria_.load(memoria_.load(instruccion_.numero)));
      }
      memoria_.store(0, memoria_.load(instruccion_.numero));
    }

  } else if (instruccion_.instruccion_ == "store" || instruccion_.instruccion_ == "STORE") {
    if (instruccion_.simbolo == '=') {
      std::string e = "Instruccion ilegal";
      throw e;
    } else {
      if (instruccion_.simbolo == '*') {
        memoria_.store(memoria_.load(memoria_.load(instruccion_.numero)), memoria_.load(0));
      }
      memoria_.store(instruccion_.numero, memoria_.load(0));
    }

  } else if (instruccion_.instruccion_ == "write" || instruccion_.instruccion_ == "WRITE") {
    if (instruccion_.simbolo == '=') {
      salida_.escribir(instruccion_.numero);
    } else {
      if (instruccion_.numero == 0) {
        std::string e = "Instruccion ilegal";
        throw e;
      } else {
        if (instruccion_.simbolo == '*') {
          salida_.escribir(memoria_.load(memoria_.load(instruccion_.numero)));
        } else {
          salida_.escribir(memoria_.load(instruccion_.numero));
        }
      }
    }

  } else if (instruccion_.instruccion_ == "add"   || instruccion_.instruccion_ == "ADD") {
    if (instruccion_.simbolo == '=') {
      memoria_.store(0, memoria_.load(0) + instruccion_.numero);
    } else {
      if (instruccion_.simbolo == '*') {
        memoria_.store(0, memoria_.load(0) + memoria_.load(memoria_.load(instruccion_.numero)));
      } else {
        memoria_.store(0, memoria_.load(0) + memoria_.load(instruccion_.numero));
      }
    }

  } else if (instruccion_.instruccion_ == "sub"   || instruccion_.instruccion_ == "SUB") {
    if (instruccion_.simbolo == '=') {
      memoria_.store(0, memoria_.load(0) - instruccion_.numero);
    } else {
      if (instruccion_.simbolo == '*') {
        memoria_.store(0, memoria_.load(0) - memoria_.load(memoria_.load(instruccion_.numero)));
      } else {
        memoria_.store(0, memoria_.load(0) - memoria_.load(instruccion_.numero));
      }
    }

  } else if (instruccion_.instruccion_ == "mul"   || instruccion_.instruccion_ == "MUL") {
    if (instruccion_.simbolo == '=') {
      memoria_.store(0, memoria_.load(0) * instruccion_.numero);
    } else {
      if (instruccion_.simbolo == '*') {
        memoria_.store(0, memoria_.load(0) * memoria_.load(memoria_.load(instruccion_.numero)));
      } else {
        memoria_.store(0, memoria_.load(0) * memoria_.load(instruccion_.numero));
      }
    }

  } else if (instruccion_.instruccion_ == "div"   || instruccion_.instruccion_ == "DIV") {
    if (instruccion_.simbolo == '=') {
      if (instruccion_.numero == 0) {
        std::string e = "Division entre 0, ilegal";
        throw e;
      } else {
        memoria_.store(0, memoria_.load(0) / instruccion_.numero);
      }
    } else {
      if (instruccion_.simbolo == '*') {
        if (memoria_.load(memoria_.load(instruccion_.numero)) == 0) {
          std::string e = "Division entre 0, ilegal";
          throw e;
        } else {
          memoria_.store(0, memoria_.load(0) / memoria_.load(memoria_.load(instruccion_.numero)));
        }
      } else {
        if (memoria_.load(instruccion_.numero) == 0) {
          std::string e = "Division entre 0, ilegal";
          throw e;
        } else {
          memoria_.store(0, memoria_.load(0) * memoria_.load(instruccion_.numero));
        }
      }
    }

  } else if (instruccion_.instruccion_ == "jump"  || instruccion_.instruccion_ == "JUMP") {
    salto_ = programa_.obtenerSiguienteSalto(instruccion_.operando_);
  } else if (instruccion_.instruccion_ == "jzero" || instruccion_.instruccion_ == "JZERO") {
    if (memoria_.load(0) == 0) {
      salto_ = programa_.obtenerSiguienteSalto(instruccion_.operando_);
    } else {
      salto_ = -1;
    }

  } else if (instruccion_.instruccion_ == "jgtz"  || instruccion_.instruccion_ == "JGTZ") {
    if (memoria_.load(0) > 0) {
      salto_ = programa_.obtenerSiguienteSalto(instruccion_.operando_);
    } else {
      salto_ = -1;
    }
  } else {
    std::string e = "Instruccion no existe" + instruccion_.instruccion_;
    throw e;
  }
}

// Muestra por pantalla el contenido de la cinta resultante.
void RAM::mostrarSalida(void) {
  salida_.mostrar();
}

// Escribe en el fichero de salida la cinta resultante.
void RAM::escribirArchivo(void) {
  salida_.escribirArchivo();
}