#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <time.h>


#include "../include/framework.hpp"
#include "../include/mergeSortProblema.hpp"
#include "../include/mergeSortSolucion.hpp"
#include "../include/quickSortProblema.hpp"
#include "../include/quickSortSolucion.hpp"
#include "../include/mergeSortSolucion.hpp"
#include "../include/torresHanoiProblema.hpp"
#include "../include/torresHanoiSolucion.hpp"
#include "../include/busquedaBinariaProblema.hpp"
#include "../include/busquedaBinariaSolucion.hpp"

using namespace std;

vector<int> crearVector(int tamanio) {
  vector<int> vector;
  for(int i=0; i<tamanio; i++){
    vector.push_back(rand()%100);
  }
  return vector;
}

vector<vector<int>> generarInstancias() {
  cout << "¿Cuantas instancias quieres crear?: " << endl;
  int cantidadInstancias = 0;
  cin >> cantidadInstancias;
  vector<vector<int>> vectorInstancias;
  for (int i = 0; i < cantidadInstancias; i++) {
    cout << "Tamaño de la instancia: " << endl;
    int tamanio = 0;
    cin >> tamanio;
    vectorInstancias.push_back(crearVector(tamanio));
  }
  return vectorInstancias;
}

void calcularTiempoEjecucion(clock_t tiempoInicio) {
  clock_t tiempoFin = clock();
  double tiempoEjecucion = (double)(tiempoFin - tiempoInicio) / CLOCKS_PER_SEC;
  int segundos = (int)tiempoEjecucion;
  int milisegundos = (int)((tiempoEjecucion - segundos) * 1000);
  int microsegundos = (int)((tiempoEjecucion - segundos) * 1000000);
  int nanosegundos = (int)((tiempoEjecucion - segundos) * 1000000000);
  string salida = "";
  if (segundos != 0){
    salida += to_string(segundos) + " segundos, ";
  } 
  if (milisegundos != 0){
    salida += to_string(milisegundos) + " milisegundos, ";
  }
  if (microsegundos != 0){
    salida += to_string(microsegundos) + " microsegundos, ";
  }
  if (nanosegundos != 0){
    salida += to_string(nanosegundos) + " nanosegundos";
  }
  cout << salida << endl;
}

void ejecutarMergeSort(vector<int> vector, int modo = 1) {
  clock_t tiempoInicio = clock();
  //vector<int> vector = {6, 4, 1, 3, 5, 2, 8, 7};
  Problema* problemaMergeSort = new MergeSortProblema(vector);
  Solucion* solucionMergeSort = new MergeSortSolucion();
  Framework* frameworkMergeSort = new Framework();
  frameworkMergeSort -> divideyVenceras(problemaMergeSort, solucionMergeSort);
  cout << "\nResultado: MergeSort - " << vector.size() << endl;
  cout << frameworkMergeSort -> getRecurrencia(problemaMergeSort) << endl;
  if (modo == 1) {
    calcularTiempoEjecucion(tiempoInicio);
  } else if (modo == 2) {
    cout << "Instancia obtenida: " << endl;
    for (unsigned i = 0; i < vector.size(); i++) {
      cout << vector[i] << " ";
    }
    cout << endl;
    cout << "Solucion obtenida: " << endl;
    solucionMergeSort->resolver();
  }
  cout << "La profundidad máxima alcanzada fue: " << frameworkMergeSort->getNivel() << endl;
}

void ejecutarQuickSort(vector<int> vector, int modo = 1) {
  clock_t tiempoInicio = clock();
  Framework* frameworkQuickSort = new Framework();
  Problema* problemaQuickSort = new QuickSortProblema(vector);
  Solucion* solucionQuickSort = new QuickSortSolucion();
  frameworkQuickSort -> divideyVenceras(problemaQuickSort, solucionQuickSort);
  cout << "\nResultado: QuickSort - " << vector.size() << endl;
  cout << frameworkQuickSort -> getRecurrencia(problemaQuickSort) << endl;
  if (modo == 1) {
    calcularTiempoEjecucion(tiempoInicio);
  } else if (modo == 2) {
    cout << "Instancia obtenida: " << endl;
    for (unsigned i = 0; i < vector.size(); i++) {
      cout << vector[i] << " ";
    }
    cout << endl;
    cout << "Solucion obtenida: " << endl;
    solucionQuickSort->resolver();
  }
  cout << frameworkQuickSort->getNivel() << endl;
}

void ejecutarBusquedaBinaria(vector<int> vector, int valor, int modo = 1) {
  sort(vector.begin(), vector.end());
  clock_t tiempoInicio = clock();
  Framework* frameworkBusquedaBinaria = new Framework();
  Problema* problemaBusquedaBinaria = new BusquedaBinariaProblema(vector, valor);
  Solucion* solucionBusquedaBinaria = new BusquedaBinariaSolucion(valor);
  frameworkBusquedaBinaria -> divideyVencerasBusquedaBinaria(problemaBusquedaBinaria, solucionBusquedaBinaria);
  cout << "\nResultado: BusquedaBinaria - " << vector.size() << endl;
  cout << frameworkBusquedaBinaria -> getRecurrencia(problemaBusquedaBinaria) << endl;
  if (modo == 1) {
    calcularTiempoEjecucion(tiempoInicio);
  } else if (modo == 2) {
    /*
    cout << "Instancia obtenida: " << endl;
    for (unsigned i = 0; i < vector.size(); i++) {
      cout << vector[i] << " ";
    }
    */
    cout << endl;
    cout << "Solucion obtenida: " << endl;
    solucionBusquedaBinaria->resolver();
  }
  cout << frameworkBusquedaBinaria ->getNivel() << endl;
}

void ejecutarTorresHanoi(int valor, int modo = 1) {
  clock_t tiempoInicio = clock();
  Framework* frameworkTorresHanoi = new Framework();
  Problema* problemaTorresHanoi = new TorresHanoiProblema(valor);
  Solucion* solucionTorresHanoi = new TorresHanoiSolucion();
  frameworkTorresHanoi -> divideyVenceras(problemaTorresHanoi, solucionTorresHanoi);
  cout << "\nResultado: TorresHanoi" << endl;
  cout << frameworkTorresHanoi -> getRecurrencia(problemaTorresHanoi) << endl;
  if (modo == 1) {
    calcularTiempoEjecucion(tiempoInicio);
  } else if (modo == 2) {
    cout << "Instancia obtenida: " << endl;
    cout << endl;
    cout << "Solucion obtenida: " << endl;
    solucionTorresHanoi->resolver();
  }
}

int main(int argc, char* argv[]) {
  int modo = 0;
  int valor = 0;
  while (modo != 1 && modo != 2) {
    cout << "Modo de ejecucion: " << endl;
    cout << "1. Modo normal" << endl;
    cout << "2. Modo debug" << endl;
    cin >> modo;
  }
  if (modo == 1) {
    int algoritmo = 0;
    while (algoritmo != 1 && algoritmo != 2 && algoritmo != 3 && algoritmo != 4) {
      cout << "\nAlgoritmo: " << endl;
      cout << "1. MergeSort" << endl;
      cout << "2. QuickSort" << endl;
      cout << "3. BusquedaBinaria" << endl;
      cout << "4. TorresHanoi" << endl;
      cin >> algoritmo;
    }
    vector<vector<int>> vectorInstancias = generarInstancias();
    switch (algoritmo) {
      case 1:
        for (unsigned i = 0; i < vectorInstancias.size(); i++) {
          ejecutarMergeSort(vectorInstancias[i], modo);
        }
        break;
      case 2:
        for (unsigned i = 0; i < vectorInstancias.size(); i++) {
          ejecutarQuickSort(vectorInstancias[i], modo);
        }
        break;
      case 3:
        valor = 0;
        while (valor < 1) {
          cout << "Valor a buscar: ";
          cin >> valor;
        }
        for (unsigned i = 0; i < vectorInstancias.size(); i++) {
          ejecutarBusquedaBinaria(vectorInstancias[i], valor, modo);
        }
        break;
      case 4:
      valor = 0;
        while (valor < 1) {
          cout << "Número de torres: ";
          cin >> valor;
        }
        ejecutarTorresHanoi(valor);
        ejecutarTorresHanoi(valor);
        ejecutarTorresHanoi(valor);
        break;
    }
  } else if (modo == 2) {
    int algoritmo = 0;
    while (algoritmo != 1 && algoritmo != 2 && algoritmo != 3 && algoritmo != 4) {
      cout << "\nAlgoritmo: " << endl;
      cout << "1. MergeSort" << endl;
      cout << "2. QuickSort" << endl;
      cout << "3. BusquedaBinaria" << endl;
      cout << "4. TorresHanoi" << endl;
      cin >> algoritmo;
    }
    int tamanio = 0;
    while (tamanio < 1) {
      cout << "Tamaño de instancia: ";
      cin >> tamanio;
    }
    vector<int> vector = crearVector(tamanio);
    switch (algoritmo) {
      case 1:
        ejecutarMergeSort(vector, 2);
        break;
      case 2:
        ejecutarQuickSort(vector, 2);
        break;
      case 3:
        cout << "Instancia obtenida: " << endl;
        for (unsigned i = 0; i < vector.size(); i++) {
          cout << vector[i] << " ";
        }
        valor = 0;
        while (valor < 1) {
          cout << "\nValor a buscar: ";
          cin >> valor;
        }
        ejecutarBusquedaBinaria(vector, valor, 2);
        break;
      case 4:
        valor = 0;
        while (valor < 1) {
          cout << "Número de torres: ";
          cin >> valor;
        }
        ejecutarTorresHanoi(tamanio, valor);
        break;
    }
  }
  cout << "\n\n";
};
