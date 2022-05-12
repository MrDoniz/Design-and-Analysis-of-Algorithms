#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Registro {
  public:
    Registro(){};
    void assign(int register_size);
    void  push(int id, int value);
    int operator[](int id);
    void clear();
    void mostrarRegistro(int id);
  private:
    map<int, int> banco_registros_;
    int register_size_;
};