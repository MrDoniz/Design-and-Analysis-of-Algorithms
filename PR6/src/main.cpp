#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <time.h>
#include<dirent.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#include "../include/ciudades.hpp"
#include "../include/fuerzaBruta.hpp"
#include "../include/problema.hpp"
#include "../include/programacionDinamica.hpp"
#include "../include/solucion.hpp"
#include "../include/temporizador.hpp"
#include "../include/voraz.hpp"

using namespace std;

string calcularTiempoEjecucion(clock_t tiempoInicio) {
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
  return salida;
}

double calcularTiempoEjecucionEnMs(clock_t tiempoInicio) {
  clock_t tiempoFin = clock();
  double tiempoEjecucion = (double)(tiempoFin - tiempoInicio) / CLOCKS_PER_SEC;
  double milisegundos = (tiempoEjecucion * 1000);
  return milisegundos;
}

string nombreCiudad(int numero) {
  string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return letras.substr(numero, 1);
}

void generadorDeInstancias() {
  cout << "¿Cuantos nodos quieres?" << endl;
  int cantidadNodos = 0;
  cin >> cantidadNodos;
  vector<string> caminos;
  for (int i = 0; i < cantidadNodos; i++) {
    for (int j = 0; j < cantidadNodos; j++) {
      if (i != j && i < j) {
        int valor = rand() % 15 + 1;
        string camino = nombreCiudad(i) + " " + nombreCiudad(j) + " " + to_string(valor);
        caminos.push_back(camino);
      }
    }
  }
  string instancia = to_string(cantidadNodos) + "\n";
  for (unsigned i = 0; i < caminos.size(); i++) {
    instancia += caminos.at(i) + "\n";
  }
  cout << instancia << endl;
  cout << "¿Deseas guardar la instancia? (s/n)" << endl;
  char respuesta;
  cin >> respuesta;
  if (respuesta == 's') {
    ofstream archivo;
    archivo.open("instancias/" + to_string(cantidadNodos) + "node.txt");
    archivo << instancia;
    archivo.close();
  }
}

string generarFila(string nombreArchivo, vector<double> &mediaFila) {
  Ciudades ciudades(nombreArchivo);
  Problema tsp(ciudades.getNumeroCiudades(), ciudades.getDistancias());
  Solucion solucion;
  Voraz voraz;
  FuerzaBruta fuerzaBruta;
  ProgramacionDinamica dinamica;
  clock_t tiempoInicio;
  string salida = "";
  
  tiempoInicio = clock();
  solucion = voraz.resolverVorazmente(tsp);
  double vorazT = calcularTiempoEjecucionEnMs(tiempoInicio);
  string vorazS = to_string(solucion.getDistanciaMinima());
  string vorazTS = to_string(vorazT);
  
  tiempoInicio = clock();
  solucion = fuerzaBruta.resolver(tsp, solucion);
  double fuerzaT = calcularTiempoEjecucionEnMs(tiempoInicio);
  string fuerzaS = to_string(solucion.getDistanciaMinima());
  string fuerzaTS = to_string(fuerzaT);

  tiempoInicio = clock();
  solucion = dinamica.resolverConProgramacionDinamica(tsp);
  double dinamicaT = calcularTiempoEjecucionEnMs(tiempoInicio);
  string dinamicaS = to_string(solucion.getDistanciaMinima());
  string dinamicaTS = to_string(dinamicaT);

  mediaFila.at(0) += vorazT;
  mediaFila.at(1) += fuerzaT;
  mediaFila.at(2) += dinamicaT;

  salida = nombreArchivo + " " + vorazS + " " + vorazTS + " "
                               + fuerzaS + " " + fuerzaTS + " "
                               + dinamicaS + " " + dinamicaTS;
  return salida;
}

void ejecutarInstancias(){
  cout << "Instancia | Valor Voraz | Tiempo Voraz | Valor Fuerza Bruta | Tiempo Fuerza Bruta | Valor Prog. Dinámica | Tiempo Prog. Dinámica" << endl;
  DIR *dir;
  vector<double> mediaFila;
  mediaFila.resize(3);
  for (unsigned i = 0; i < mediaFila.size(); i++) {
    mediaFila.at(i) = 0;
  }
  int numeroArchivos = 0;
  struct dirent *ent;
  if ((dir = opendir ("instancias")) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      string nombreArchivo = ent->d_name;
      if (nombreArchivo.find(".txt") != string::npos) {
        numeroArchivos++;
        cout << generarFila(nombreArchivo, mediaFila) << endl;
      }
    }
    closedir (dir);
    // imprime los valores de media
    cout << "Media | ";
    for (unsigned i = 0; i < mediaFila.size(); i++) {
      mediaFila.at(i) /= numeroArchivos;
      cout << mediaFila.at(i) << " ";
    }
    cout << endl;
  } else {
    perror ("");
  }
}

int main(int argc, char* argv[]) {
  int opcion = 0;
  while (opcion != 3) {
    cout << "¿Quieres entrar al generador de instancias?" << endl;
    cout << "1. Generador de instancias" << endl;
    cout << "2. Ejecutar instancias" << endl;
    cout << "3. Salir" << endl;
    cin >> opcion;
    if (opcion == 1) {
      generadorDeInstancias();
    } else if (opcion == 2) {
      ejecutarInstancias();
    }
  }
  return 0;
};
