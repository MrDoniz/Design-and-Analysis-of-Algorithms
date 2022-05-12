#include <fstream>
#include <iostream>
#include <vector>

#include "punto.hpp"

using namespace std;
#pragma once

class Problema  {
  public:
    Problema() {}
    Problema(string fichero);
    Problema(const Problema& problema);
    ~Problema() {}

    string getFichero() const;
    int getPuntosSize() const;
    int getDimensionSize() const;
    vector<Punto> getListaPuntos() const;
    Punto getPunto(int id);

    void analizarFichero();
    void parsePuntosSize();
    void parseDimensionSize();
    void parsePuntos();

    vector<Punto> puntosSinProcesar(vector<Punto> puntosProcesados);

    float calcularDistanciaEuclidean(Punto primero, Punto segundo) const;
    Punto calcularCentro(vector<Punto> puntos) const;

    Problema& operator=(const Problema& problema);

    friend std::ostream& operator<<(std::ostream& os, const Problema& problema);

  private:
    string fichero_nombre_;
    int puntos_size_;
    int dimension_size_;
    vector<Punto> lista_puntos_;
    ifstream fichero_;
};
