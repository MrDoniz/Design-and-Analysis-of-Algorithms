#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Instruccion{
  public:
    Instruccion(){}
    void set(string Instruccion);
    bool isHalt(void);
    void setOp(void);
    void reset(void);
    void keyword(void);
    void mostrarInstruccion(void);

  public:
    bool salto = false;
    string instruccion_;
    int numero;
    char simbolo;
    string operando_;
    
  private:
    int direccion;
    string opcode;
};