#include <iostream>

#include "../include/argumentos.hpp"
#include "../include/experimento.hpp"
#include "../include/busquedalocal.hpp"
#include "../include/vecinos/intercambioPunto.hpp"
#include "../include/problema.hpp"

#include <vector>

using namespace std;

void voraz (string fichero) {
  Problema maxima_diversidad(fichero);
  vector<int> solucion_size = {2, 3, 4, 5};
  Experimento experimento_voraz(maxima_diversidad, "voraz");
  cout << experimento_voraz << endl;
  for (auto&& size_solution : solucion_size) {
    experimento_voraz.voraz(size_solution);
    experimento_voraz.mostrarTabla(cout);
  }
  cout << "|-----------------------------------------------------------------------------------------------|\n";
}

void grasp (string fichero) {
  Problema maxima_diversidad(fichero);
  vector<int> solucion_size = {2, 3, 4, 5};
  vector<int> lrcs_size = {2, 3};
  Experimento experimento(maxima_diversidad, "grasp");
  cout << experimento << endl;
  for (auto&& size_solution : solucion_size) {
    for (auto&& lrc_size : lrcs_size) {
      experimento.grasp(size_solution, new IntercambioPunto(), lrc_size);
      experimento.mostrarTabla(cout);
    }
  }
  cout << "|------------------------------------------------------------------------------------------------------------|\n";
}

void ramaypoda (string fichero) {
  Problema maxima_diversidad(fichero);
  vector<int> solucion_size = {2, 3, 4, 5};
  Experimento experimento(maxima_diversidad, "branch_bound");
  Experimento experimento_voraz(maxima_diversidad, "greedy");
  cout << experimento << endl;
  for (auto&& size_solution : solucion_size) {
    experimento_voraz.voraz(size_solution);
    experimento.ramaypoda(size_solution, experimento_voraz.getSolucion(),
                            1);
    experimento.mostrarTabla(cout);
  }
  cout << "|---------------------------------------------------------------------------------------------------------------|\n";
}

int main (int argc, char* argv[]) {
  Argumentos argumentos(argc, argv);
  string fichero = argumentos.getListaArgumentos()[1];
  int opcion;
  do {
    cout << "\nIndica el algoritmo: " << endl;
    cout << "1. VORAZ" << endl;
    cout << "2. GRASP" << endl;
    cout << "3. RAMA Y PODA" << endl;
    cout << "4. SALIR" << endl;
    cin >> opcion;
    cout << endl;
    switch (opcion) {
      case 1:
        voraz(fichero);
        break;
      case 2:
        grasp(fichero);
        break;
      case 3:
        ramaypoda(fichero);
        break;
      case 4:
        cout << "Saliendo..." << endl;
        break;
      default:
        cout << "Opcion incorrecta" << endl << endl;
    }
  } while (opcion != 4);
  
}