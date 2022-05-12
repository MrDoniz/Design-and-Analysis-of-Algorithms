#include "../include/programacionDinamica.hpp"


ProgramacionDinamica::ProgramacionDinamica(){};

ProgramacionDinamica::~ProgramacionDinamica(){};

Solucion ProgramacionDinamica::resolverConProgramacionDinamica(Problema problema) {
  Solucion solucion;
  setNumeroCiudades(problema.getNumeroCiudades());
  setPosibilidades((int) pow(2, getNumeroCiudades()));
  vector<vector<int>> tabla(getNumeroCiudades(), vector<int>(getPosibilidades(), -1));
  vector<vector<int>> tablaConLasRutas(getNumeroCiudades(), vector<int>(getPosibilidades(), -1));
  for (int i = 0; i < getNumeroCiudades(); i++) {
    for (int j = 0; j < getPosibilidades(); j++) {
      tabla[i][j] = -1;
      tablaConLasRutas[i][j] = -1;
    }
  }
  for (int i = 0; i < getNumeroCiudades(); i++) {
    tabla[i][0] = problema.getCoste(i, getCIUDAD_INICIAL());
  }
  solucion.agregarCiudad(getCIUDAD_INICIAL());
  solucion.setDistanciaMinima(algoritmoDinamico(0, getPosibilidades() - 2, tabla, tablaConLasRutas, problema));
  obtenerRuta(getCIUDAD_INICIAL(), getPosibilidades() - 2, tablaConLasRutas, solucion);
  solucion.agregarCiudad(getCIUDAD_INICIAL());
  return solucion;
};

void ProgramacionDinamica::obtenerRuta(int comienzo, int set, vector<vector<int>> &tablaConLasRutas, Solucion solucion){
  if (tablaConLasRutas[comienzo][set] == -1)
    return;
  int x = tablaConLasRutas[comienzo][set];
  int mask = getPosibilidades() - 1 - (int)pow(2, x);
  int masked = set & mask;
  solucion.agregarCiudad(x);
  obtenerRuta(x, masked, tablaConLasRutas, solucion);
};

int ProgramacionDinamica::algoritmoDinamico(int comienzo, int set, vector<vector<int>> &tabla, vector<vector<int>> &tablaConLasRutas, Problema problema) {
  int mask, masked, resultado = -1, temporal;
  if (tabla[comienzo][set] != -1) {
    return tabla[comienzo][set];
  } else {
    for (int i = 0; i < getNumeroCiudades(); i++) {
      mask = getPosibilidades() -1 - (int) pow(2, i);
      masked = set & mask;
      if (masked != set) {
        temporal = problema.getCoste(comienzo, i) + algoritmoDinamico(i, masked, tabla, tablaConLasRutas, problema);
        if (resultado == -1 || resultado > temporal) {
          resultado = temporal;
          tablaConLasRutas[comienzo][set] = i;
        }
      }
    }
  }
  tabla[comienzo][set] = resultado;
  return resultado;
};

int ProgramacionDinamica::getNumeroCiudades(){
  return numeroCiudades;
};
void ProgramacionDinamica::setNumeroCiudades(int numeroCiudades){
  this->numeroCiudades = numeroCiudades;
};
int ProgramacionDinamica::getPosibilidades(){
  return posibilidades;
};
void ProgramacionDinamica::setPosibilidades(int posibilidades){
  this -> posibilidades = posibilidades;
};
int ProgramacionDinamica::getCIUDAD_INICIAL(){
  return ciudad_inicial;
};