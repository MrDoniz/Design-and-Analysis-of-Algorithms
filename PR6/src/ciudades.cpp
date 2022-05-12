#include "../include/ciudades.hpp"

Ciudades::Ciudades(string nombreFichero){
  nombreFichero = "instancias/" + nombreFichero;
  ifstream fichero(nombreFichero);
  string linea;
  getline(fichero, linea);
  analizarNumeroCiudades(linea);
  //Recorre el fichero, el resto de elementos son las distancias
  vector<char> ciudadesOrigen;
  vector<char> ciudadesDestino;
  vector<int> distancia;
  int i = 0;
  while(getline(fichero, linea)){
    ciudadesOrigen.push_back(linea[0]);
    ciudadesDestino.push_back(linea[2]);
    distancia.push_back(atoi(linea.substr(4).c_str()));
    i++;
  }
  vector<vector<int>> array;
  for(unsigned i = 0; i < ciudadesOrigen.size(); i++){
    vector<int> fila;
    fila.push_back(ciudadesOrigen[i] - 'A');
    fila.push_back(ciudadesDestino[i] - 'A');
    fila.push_back(distancia[i]);
    array.push_back(fila);
  }

  for(unsigned i = 0; i < ciudadesOrigen.size(); i++) {
    array[i][0] = ciudadesOrigen[i]- 'A';
    array[i][1] = ciudadesDestino[i] - 'A';
    array[i][2] = distancia[i];
  }

  analizarDistancias(array);
};
Ciudades::~Ciudades(){};

int Ciudades::getNumeroCiudades(){
  return numeroCiudades;
};

vector<vector<int>> Ciudades::getDistancias(){
  return distancias;
};

void Ciudades::mostrarDistancias(){
  for (unsigned i = 0; i < distancias.size(); i++) {
    cout << "Ciudad " << i << ": " << getDistancias()[i][0] << " " << getDistancias()[i][1] << endl;
  }
};

void Ciudades::analizarDistancias(vector<vector<int>> vectorOrdenado){
  for(int i = 0; i < numeroCiudades; i++){
    for(int j = 0; j < numeroCiudades; j++){
      if(i != j){
        vector<int> fila;
        fila.push_back(i);
        fila.push_back(j);
        for(unsigned k = 0; k < vectorOrdenado.size(); k++){
          if(vectorOrdenado[k][0] == i && vectorOrdenado[k][1] == j){
            fila.push_back(vectorOrdenado[k][2]);
          }
          if(vectorOrdenado[k][0] == j && vectorOrdenado[k][1] == i){
            fila.push_back(vectorOrdenado[k][2]);
          }
        }
        distancias.push_back(fila);
      }
    }
  }
};

void Ciudades::analizarNumeroCiudades(string linea) {
  setNumeroCiudades(atoi(linea.c_str()));
};
void Ciudades::setNumeroCiudades(int numeroCiudades){
  this->numeroCiudades = numeroCiudades;
};
void Ciudades::setDistancias(vector<vector<int>> distancias){
  this->distancias = distancias;
};