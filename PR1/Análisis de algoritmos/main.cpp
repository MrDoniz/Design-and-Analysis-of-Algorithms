#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
#include "interfaz.hpp"



void calcular_tiempo(Matriz a, Matriz b){
  cout << endl <<  "Matriz: " << a.get_filas() << " x " << a.get_filas() << endl;
  Interfaz *pc1= new Interfaz(new EstrategiaFilas());
  pc1 -> operacion(a,b);
  cout << "Estrategia filas:" << endl;

  Interfaz *pc2= new Interfaz(new EstrategiaColumnas());
  pc2 -> operacion(a,b);
  cout << "Estrategia columnas:" << endl;
}

void test(int valor) {
  Matriz a1(valor,valor,1);
  Matriz b1(valor,valor,1);
  calcular_tiempo(a1,b1);
}

int main (void) {
  int valor;

  valor = 20;
  Matriz a1(valor,valor,1);
  Matriz b1(valor,valor,1);
  calcular_tiempo(a1,b1);

  valor = 40;
  Matriz a2(valor,valor,1);
  Matriz b2(valor,valor,1);
  calcular_tiempo(a2,b2);

  valor = 60;
  Matriz a3(valor,valor,1);
  Matriz b3(valor,valor,1);
  calcular_tiempo(a3,b3);

  valor = 80;
  Matriz a4(valor,valor,1);
  Matriz b4(valor,valor,1);
  calcular_tiempo(a4,b4);

  valor = 100;
  Matriz a5(valor,valor,1);
  Matriz b5(valor,valor,1);
  calcular_tiempo(a5,b5);

  valor = 120;
  Matriz a6(valor,valor,1);
  Matriz b6(valor,valor,1);
  calcular_tiempo(a6,b6);

  valor = 140;
  Matriz a7(valor,valor,1);
  Matriz b7(valor,valor,1);
  calcular_tiempo(a7,b7);

  valor = 160;
  Matriz a8(valor,valor,1);
  Matriz b8(valor,valor,1);
  calcular_tiempo(a8,b8);

  valor = 180;
  Matriz a9(valor,valor,1);
  Matriz b9(valor,valor,1);
  calcular_tiempo(a9,b9);

  valor = 200;
  Matriz a10(valor,valor,1);
  Matriz b10(valor,valor,1);
  calcular_tiempo(a10,b10);

  valor = 220;
  Matriz a11(valor,valor,1);
  Matriz b11(valor,valor,1);
  calcular_tiempo(a11,b11);

  valor = 240;
  Matriz a12(valor,valor,1);
  Matriz b12(valor,valor,1);
  calcular_tiempo(a12,b12);

  valor = 260;
  Matriz a13(valor,valor,1);
  Matriz b13(valor,valor,1);
  calcular_tiempo(a13,b13);

  valor = 280;
  Matriz a14(valor,valor,1);
  Matriz b14(valor,valor,1);
  calcular_tiempo(a14,b14);

  valor = 300;
  Matriz a15(valor,valor,1);
  Matriz b15(valor,valor,1);
  calcular_tiempo(a15,b15);

  valor = 320;
  Matriz a16(valor,valor,1);
  Matriz b16(valor,valor,1);
  calcular_tiempo(a16,b16);

  valor = 340;
  Matriz a17(valor,valor,1);
  Matriz b17(valor,valor,1);
  calcular_tiempo(a17,b17);

  valor = 360;
  Matriz a18(valor,valor,1);
  Matriz b18(valor,valor,1);
  calcular_tiempo(a18,b18);

  valor = 380;
  Matriz a19(valor,valor,1);
  Matriz b19(valor,valor,1);
  calcular_tiempo(a19,b19);

  valor = 400;
  Matriz a20(valor,valor,1);
  Matriz b20(valor,valor,1);
  calcular_tiempo(a20,b20);

  valor = 420;
  Matriz a21(valor,valor,1);
  Matriz b21(valor,valor,1);
  calcular_tiempo(a21,b21);

  valor = 440;
  Matriz a22(valor,valor,1);
  Matriz b22(valor,valor,1);
  calcular_tiempo(a22,b22);

  valor = 460;
  Matriz a23(valor,valor,1);
  Matriz b23(valor,valor,1);
  calcular_tiempo(a23,b23);

  valor = 480;
  Matriz a24(valor,valor,1);
  Matriz b24(valor,valor,1);
  calcular_tiempo(a24,b24);

  valor = 500;
  Matriz a25(valor,valor,1);
  Matriz b25(valor,valor,1);
  calcular_tiempo(a25,b25);
  

  return 0;
}