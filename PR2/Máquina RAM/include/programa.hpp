#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "cinta.hpp"
#include "memoria.hpp"
using namespace std;

class Programa{
  public:
    Programa(char* archivo);
    Programa(){}
    ~Programa(){}
    void mostrarInstruccion(void);
    void mostrarEtiqueta(void);
    string obtenerInstruccion(int posicion);
    int obtenerSiguienteSalto(string variable);

  private:
    vector<string> instruccion_;
    vector<pair<string,int>> etiqueta_;
    int contador_programa_;
};