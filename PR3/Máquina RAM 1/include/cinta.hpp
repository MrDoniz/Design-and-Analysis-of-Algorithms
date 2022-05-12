#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Cinta{
  public:
    Cinta(){}
    ~Cinta(){}
    
  protected:
    vector<int> cinta_;
    int cabezal_ = 0;
    char* archivo_;
};

class CintaEntrada : public Cinta{
  public:
    CintaEntrada(char* archivo);  
    CintaEntrada(){}
    int  leer(void);
    void leerArchivo(void);
    void mostrar(void);
};

class CintaSalida : public Cinta{
  public:
    CintaSalida(char* f);
    CintaSalida(){}
    void escribir(int valor);
    void escribirArchivo(void);
    void mostrar(void);
};