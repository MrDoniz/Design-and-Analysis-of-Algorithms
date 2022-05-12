#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
#pragma once

class Nodo {
  public:
    Nodo() {};
    ~Nodo() {};

    int getValor() {
      return valor_;
    };

    void setVisitado(bool valor) {
      visitado = valor;
    };

    bool getVisitado() {
      return visitado;
    };

    void setValor(int valor) {
      valor_ = valor;
      visitado = false;
    };

  private:
    int valor_;
    bool visitado;
};