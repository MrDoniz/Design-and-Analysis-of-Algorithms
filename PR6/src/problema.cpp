#include "../include/problema.hpp"

Problema::Problema(int numeroCiudades, vector<vector<int>> distancias){
  this->numeroCiudad = numeroCiudades;
  this->distancias = distancias;
}
Problema::~Problema(){
}

unsigned Problema::getNumeroCiudades(){
  return this->numeroCiudad;
}
int Problema::getCoste(int ciudadOrigen, int ciudadDestino){
  for (unsigned i = 0; i < distancias.size(); i++) {
    if (distancias[i][0] == ciudadOrigen && distancias[i][1] == ciudadDestino) {
      return distancias[i][2];
    }
  }
  return -1;
}
string Problema::toString(){
  string toS = "";
  toS += "Número de ciudades: " + to_string(this->numeroCiudad) + "\nDistancias:";
  int contador = 0;
  int j = 0;
  for(unsigned i = 0; i < this->distancias.size(); i++){
    j = 0;
    if (contador <= 0) {
      toS += "\nEstando en la ciudad [" + nombreCiudad(distancias[i][0]) + "]\n";
      contador = this->numeroCiudad - 1;
    }
    toS += "El coste para ir a la ciudad [" + nombreCiudad(this->distancias[i][j+1]) + "]: " + to_string(this->distancias[i][j+2]);
    toS += "\n";
    contador--;
  }
  return toS;
}

string Problema::nombreCiudad(int numero) {
  string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return letras.substr(numero, 1);
}

void Problema::setNumeroCiudades(int numeroCiudades){
  this->numeroCiudad = numeroCiudades;
}

vector<vector<int>> Problema::getDistancias() {
  return this->distancias;
}

void Problema::setDistancias(vector<vector<int>> distancias){
  this->distancias = distancias;
}