#include "../include/instruccion.hpp"

// Recibe una cadena con el operando y el operador y lo separa en los dos atributos privados de la clase, instruccion y operando.
// Previamente llama a reset y posteriormente a setOp
void Instruccion::set(string instruccion) {
  reset();
  int posicion = instruccion.find(" ");
  instruccion_ = instruccion.substr(0, (instruccion.size() - (instruccion.size() - posicion)));
  operando_ = instruccion.substr(posicion + 1, instruccion.size() - posicion);
  setOp();
}

// Devuelve true si accede a un operando HALT el cual indica el fin del programa.
bool Instruccion::isHalt(void) {
  string halt = "halt";
  string HALT = "HALT";
  if (instruccion_ == halt || instruccion_ == HALT)
    return true;
  return false;
}

// Reseta todos los atributos de la clase.
void Instruccion::reset(void) {
  simbolo = 'n';
  salto = false;
  numero = -1;
  direccion = -1;
  instruccion_ = "";
  operando_ = "";
  opcode = "";
}

// Almacena en el atributo opcode el valor de la instrucción, en el caso necessario indica que es un salto.
// Dar un valor al opcode en base del operando.
// 3, 0, 1
void Instruccion::setOp(void) {
  keyword();
  if (isdigit(operando_[0])) {
    stringstream aux(operando_);
    aux >> numero;
    opcode += "0";
    opcode += operando_;
  } else if (operando_[0] == '=') {
    simbolo = operando_[0];
    stringstream aux(operando_.substr(1, operando_.size() - 1));
    aux >> numero;
    opcode += "1";
    opcode += operando_.substr(1, operando_.size() - 1);
  // Indica el registro contenido
  } else if (operando_[0] == '*') {
    simbolo = operando_[0];
    stringstream aux(operando_.substr(1, operando_.size() - 1));
    aux >> direccion;
    opcode += "2";
    opcode += operando_.substr(1, operando_.size() - 1);
  } else if (instruccion_ == "jump" || instruccion_ == "JUMP" ||
             instruccion_ == "jzero" || instruccion_ == "JZERO" ||
             instruccion_ == "jgtz" || instruccion_ == "JGTZ") {
    salto = true;
  }
}

// Almacena en el atributo opcode el valor de la instrucción según el operador.
void Instruccion::keyword(void) {
  if (instruccion_ == "load" || instruccion_ == "LOAD")
    opcode += "01";
  else if (instruccion_ == "store" || instruccion_ == "STORE")
    opcode += "02";
  else if (instruccion_ == "add" || instruccion_ == "ADD")
    opcode += "03";
  else if (instruccion_ == "sub" || instruccion_ == "SUB")
    opcode += "04";
  else if (instruccion_ == "mul" || instruccion_ == "MUL")
    opcode += "05";
  else if (instruccion_ == "div" || instruccion_ == "DIV")
    opcode += "06";
  else if (instruccion_ == "read" || instruccion_ == "READ")
    opcode += "07";
  else if (instruccion_ == "write" || instruccion_ == "WRITE")
    opcode += "08";
  else if (instruccion_ == "jump" || instruccion_ == "JUMP")
    opcode += "09";
  else if (instruccion_ == "jzero" || instruccion_ == "JZERO")
    opcode += "10";
  else if (instruccion_ == "jgtz" || instruccion_ == "JGTZ")
    opcode += "11";
  else if (instruccion_ == "halt" || instruccion_ == "HALT")
    opcode += "12";
  else
    opcode += "xx";
}

// Muestra por pantalla el contenido del vector de instrucciones.
void Instruccion::mostrarInstruccion(void) {
  cout << "Instruccion: " << instruccion_ << endl << endl;
}