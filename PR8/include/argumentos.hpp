#include <fstream>
#include <iostream>
#include <vector>
#include <getopt.h>

using namespace std;
#pragma once

class Argumentos {
  public:
    Argumentos(int argc, char *argv[]);
    ~Argumentos() {}
    vector<string> getListaArgumentos();
    string getNombreAlgoritmo();
    void setNombreAlgoritmo(string nombre_algoritmo);
    void usage();
  private:
    vector<string> lista_argumentos_;
    string nombre_algoritmo_;
};