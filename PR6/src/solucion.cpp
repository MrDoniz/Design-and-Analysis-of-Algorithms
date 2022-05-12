#include "../include/solucion.hpp"

Solucion::Solucion(){
  this->distanciaMinima = 0;
  this->ruta = vector<int>();
}

Solucion::Solucion(int distanciaMinima, vector<int> ruta){
  this->distanciaMinima = distanciaMinima;
  this->ruta = ruta;
}

Solucion::~Solucion(){}

void Solucion::incrementarDistancia(int distancia){
  setDistanciaMinima(getDistanciaMinima() + distancia);
}

void Solucion::agregarCiudad(int ciudad){
  getRuta().push_back(ciudad);
}

int Solucion::obtenerUltimaCiudad(){
  return getRuta().back();
}

int Solucion::getDistanciaMinima(){
  return distanciaMinima;
}

void Solucion::setDistanciaMinima(int distanciaMinima){
  this->distanciaMinima = distanciaMinima;
}

vector<int> Solucion::getRuta(){
  return ruta;
}

bool Solucion::buscarEnRuta(int ciudad){
  for (unsigned i = 0; i < ruta.size(); i++){
    if (ruta.at(i) == ciudad){
      return true;
    }
  }
  return false;
}

void Solucion::setRuta(vector<int> ruta){
  this->ruta = ruta;
}

string numeroCiudad(int numero) {
  string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return letras.substr(numero, 1);
}

string Solucion::toString(){
  string toS = "";
  toS += "Distancia mínima: " + to_string(getDistanciaMinima());
  toS += "\nRuta: ";
  for (unsigned i = 0; i < getRuta().size(); i++) {
    if (i < getRuta().size() - 1) {
      toS += "Ciudad [" + numeroCiudad(getRuta().at(i)) + "]" + " -> ";
    } else {
      toS += "Ciudad [" + numeroCiudad(getRuta().at(i)) + "]"; 
    }
  }
  return toS;
}