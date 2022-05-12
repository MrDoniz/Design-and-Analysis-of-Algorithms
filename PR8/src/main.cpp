#include <iostream>

#include "../include/argumentos.hpp"
#include "../include/experimento.hpp"
#include "../include/busquedalocal.hpp"
#include "../include/vecinos/intercambioPunto.hpp"
#include "../include/problema.hpp"

#include <vector>

using namespace std;

int main (int argc, char* argv[]) {
  Argumentos argumentos(argc, argv);
  string fichero = argumentos.getListaArgumentos()[1];
  Problema maxima_diversidad(fichero);

  // Voraz
  vector<int> size_solutions = {5, 4, 7};
  Experimento experimentoVoraz(maxima_diversidad, "voraz");
  cout << experimentoVoraz << endl;
  for (auto&& size_solution : size_solutions) {
    experimentoVoraz.voraz(size_solution);
    experimentoVoraz.mostrarTabla(cout);
  }
}