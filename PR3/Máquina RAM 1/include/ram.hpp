#pragma once
#include <iostream>
#include "memoria.hpp"
#include "instruccion.hpp"
#include "programa.hpp"
#include "cinta.hpp"
using namespace std;

class RAM{
  public:
    RAM (Memoria &memoria, Programa &programa, CintaEntrada &entrada, CintaSalida &salida, int &debug);
    void setInstruccion(Instruccion &instruccion);
    void ejecutar(void);
    int  siguienteInstruccion(void);
    void mostrarSalida(void);
    void mostrarEntrada(void);
    void mostrarEtiquetas(void);
    void escribirArchivo(void);

  public:
    int debug;
    CintaEntrada entrada_;
    CintaSalida salida_;

  private:
    Memoria memoria_;
    Instruccion instruccion_;
    Programa programa_;
    int salto_ = -1;
};