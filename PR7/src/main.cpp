#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <time.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/grasp.hpp"
#include "../include/gvns.hpp"
#include "../include/problema.hpp"
#include "../include/voraz.hpp"
#include "../include/solucion.hpp"

using namespace std;

// Lee los archivos del directorio instancias, y los guarda en un vector y muestra el nombre de los ficheros por pantalla
vector<string> cargarInstancias() {
  DIR *dir;
  struct dirent *ent;
  vector<string> instancias;
  if ((dir = opendir ("instancias")) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
        instancias.push_back(ent->d_name);
      }
    }
    closedir (dir);
  } else {
    perror ("");
  }
  return instancias;
}

//Muestra un menu por pantalla para que el usuario seleccione la instancia que desea resolver. Si no es de 1 a 3 cierra la ejecución
Instancia seleccionarInstancias(vector<string> instancias) {
  unsigned opcion;
  cout << "--------------------------" << endl;
  for (unsigned i = 0; i < instancias.size(); i++) {
    cout << i+1 << ") " << instancias[i] << endl;
  }
  cout << "Seleccione una instancia: ";
  cin >> opcion;
  if (opcion < 1 || opcion > instancias.size()) {
    cout << endl;
    cout << "Opcion no valida" << endl;
    exit(0);
  }
  Instancia problema(instancias[opcion-1]);
  cout << endl;
  return problema;
}

int seleccionarAlgoritmo() {
  int opcion;
  cout << "-------------------------" << endl;
  cout << "1) Algoritmo voraz" << endl;
  cout << "2) GRASP" << endl;
  cout << "3) GVNS" << endl;
  cout << "4) Salir" << endl;
  cout << "Seleccione un algoritmo: ";
  cin >> opcion;
  if (opcion == 4) {
    cout << endl;
    cout << "Saliendo..." << endl;
    exit(0);
  }
  if (opcion < 1 || opcion > 4) {
    cout << endl;
    cout << "Opcion no valida" << endl;
    exit(0);
  }
  cout << endl;
  return opcion;
}
string procesarAlgoritmo(int opcion, Instancia problema) {
  string resultado = "";
  Voraz voraz;
  Solucion solucionVoraz;
  Grasp grasp;
  Solucion solucionGrasp;
  Gvns gvns;
  Solucion solucionGvns;
  switch (opcion) {
    case 1:
      voraz.ejecutar(problema, solucionVoraz);
      break;
    case 2:
      grasp.ejecutar(problema, solucionGrasp);
      break;
    case 3:
      gvns.ejecutar(problema, solucionGvns);
      break;
  }
  return resultado;
}

int main(int argc, char* argv[]) {
  string cadena;
  int algoritmo;
  vector<string> instancias = cargarInstancias();
  Instancia problema = seleccionarInstancias(instancias);
  while(true){
    algoritmo = seleccionarAlgoritmo();
    cadena = procesarAlgoritmo(algoritmo, problema);
    cout << cadena;
  }
  return 0;
};
