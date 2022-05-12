#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "registro.hpp"

class Memoria {
  public:
    Memoria(void);
    void store(int pos, int val){ storev2(val, pos);}
    void storev2(int valor, int id_registro = 0);
    int  load(int id_registro = 0);
    void reset();
    void mostrarMemoria(void);
  public:
    int debug;
    const int REGISTRO_SIZE = 10;
  private:
    Registro banco_registros_;
};