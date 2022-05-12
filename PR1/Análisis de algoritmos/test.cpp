#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;
#include "interfaz.hpp"

double tiempo(clock_t inicio, clock_t final){
  return (double)(final-inicio)/CLOCKS_PER_SEC;
}

void calcular_tiempo(Matriz a, Matriz b){
  cout << endl <<  "Matriz: " << a.get_filas() << " x " << a.get_filas() << endl;
  Interfaz *pc1= new Interfaz(new EstrategiaFilas());
  clock_t inicio0 = clock();
  pc1 -> operacion(a,b);
  clock_t final0 = clock();
  cout << "Estrategia filas:" << endl 
       << "Tiempo de ejecución: " << tiempo(inicio0, final0) << " segundos" << endl;

  Interfaz *pc2= new Interfaz(new EstrategiaColumnas());
  clock_t inicio1 = clock();
  pc2 -> operacion(a,b);
  clock_t final1 = clock();
  cout << "Estrategia columnas:" << endl 
       << "Tiempo de ejecución: " << tiempo(inicio1, final1) << " segundos" << endl;
}

void analizar_tiempo(int valor){
  Matriz a1(valor,valor,1);
  Matriz b1(valor,valor,1);
  calcular_tiempo(a1,b1);
}

int main (void) {

  analizar_tiempo(50);
  analizar_tiempo(75);
  analizar_tiempo(80);
  analizar_tiempo(85);
  analizar_tiempo(90);
  analizar_tiempo(95);
  analizar_tiempo(100);
  analizar_tiempo(500);
  analizar_tiempo(1000);
  analizar_tiempo(1250);
  analizar_tiempo(1250);
  analizar_tiempo(1500);
  analizar_tiempo(1750);
  analizar_tiempo(2000);

  return 0;
}