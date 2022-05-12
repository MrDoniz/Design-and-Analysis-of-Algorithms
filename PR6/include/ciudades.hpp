#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>  
#include <cstring>

using namespace std;
#pragma once

class Ciudades {
  public:
    Ciudades(string nombreFichero);
    ~Ciudades();

    int getNumeroCiudades();
    vector<vector<int>> getDistancias();
    void mostrarDistancias();
    void analizarDistancias(vector<vector<int>> vectorOrdenado);
    void analizarNumeroCiudades(string linea);
    void setNumeroCiudades(int numeroCiudades);
    void setDistancias(vector<vector<int>> distancias);

  private:
    int numeroCiudades;
    vector<vector<int>> distancias;


};