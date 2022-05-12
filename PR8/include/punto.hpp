#include <iostream>
#include <vector>

using namespace std;
#pragma once

class Punto  {
  public:
    Punto() {}
    Punto(int id);
    ~Punto() {}

    void addCoordenada(float valorCoordinada);
    vector<float> getCoordenadas() const;

    int getId() const;
    void setId(int id);

    float calcularDistanciaEuclidean(Punto primero, Punto segundo) const;
    friend std::ostream& operator<<(std::ostream& os, const Punto& punto);

  private:
    int id_;
    vector<float> coordenadas_;
};