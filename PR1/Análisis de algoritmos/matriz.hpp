#include <iostream>
#pragma once

class Matriz{
  public:
    Matriz(int filas, int columnas, int opcion = 0) {
      filas_ = filas;
      columnas_ = columnas;
      v_ = new int*[filas_];
      for(int i=0; i<filas_; i++){
        v_[i]= new int[columnas_];
      }
      if (opcion == 0){
        rellenar_ceros();
      }else if (opcion == 1){
        rellenar_aleatorio();
      }
    }
    ~Matriz() {
      for(int i=0; i<filas_; i++){
        delete [] v_[i];
      }
      delete [] v_;
    }
    int posicion(int fila, int columna) {
      return v_[fila][columna];
    }
    void poner_valor(int fila, int columna, int valor) {
      v_[fila][columna] = valor;
    }
    void rellenar_aleatorio(void) {
      srand(time(NULL));
      for(int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++)
          v_[i][j]=rand() % 9;
      }
    }
    void rellenar_ceros(void) {
      for(int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++)
          v_[i][j]=0;
      }
    }
    void escribir(void) {
      for(int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++)
          std::cout << v_[i][j] << " ";
        std::cout << std::endl;
      }
    }
    int get_filas(void) {
      return filas_;
    }
    int get_columnas(void) {
      return columnas_;
    }

  private:
    int filas_;
    int columnas_;
    int **v_;
};
