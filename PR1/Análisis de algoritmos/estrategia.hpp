#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
#pragma once
#include "matriz.hpp"

double tiempo(clock_t inicio, clock_t final){
  return (double)(final-inicio)/CLOCKS_PER_SEC;
}

class Estrategia {
  public:
    virtual void multiplicar(Matriz &a, Matriz &b) = 0;
};

class EstrategiaFilas: public Estrategia {
  void multiplicar(Matriz &a, Matriz &b) {
    if(a.get_columnas() == b.get_filas()) {
      clock_t inicio0 = clock();
      int valor=0;
      Matriz c(a.get_filas(), b.get_columnas());
      for(int i = 0; i < a.get_filas(); i++){
        for(int j = 0; j < b.get_columnas(); j++){
          for(int k = 0; k < a.get_columnas(); k++)
            valor += a.posicion(i,k) * b.posicion(k,j);
          c.poner_valor(i,j, valor);
          valor = 0;
        }
      }
      //c.escribir();
      clock_t final0 = clock();
      cout << "Tiempo de ejecución: " << tiempo(inicio0, final0) << " segundos" << endl;
    } else {
      std::cout << "No se puede hacer el producto\n";
    }
  }
};

class EstrategiaColumnas: public Estrategia {
  void multiplicar(Matriz &a, Matriz &b) {
    if(a.get_columnas() == b.get_filas()){
      clock_t inicio0 = clock();
      int valor = 0;
      Matriz c(a.get_filas(), b.get_columnas());
      for(int i = 0; i < b.get_columnas(); i++){
        for(int j = 0; j < a.get_filas(); j++){
          for(int k = 0; k < a.get_columnas(); k++)
            valor += a.posicion(j,k) * b.posicion(k,i);
          c.poner_valor(j,i, valor);
          valor = 0;
        }
      }
      //c.escribir();
      clock_t final0 = clock();
      cout << "Tiempo de ejecución: " << tiempo(inicio0, final0) << " segundos" << endl;
    } else {
      std::cout << "No se puede hacer el producto\n";
    }
  }
};