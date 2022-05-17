#include "problema.hpp"
#include "solucion.hpp"
#include "vecinos/algoritmoVecinos.hpp"

using namespace std;
#pragma once

class Experimento {
  public:
    Experimento(Problema problema, string nombre_algoritmo);
    ~Experimento() {}

    int getSizeSoluciones() const;
    float getCPUtime() const;
    Solucion getSolucion() const;
    Solucion& getSolucion();
    string getTipoAlgoritmo() const;
    Problema getProblema() const;

    void voraz(int size_solucion);
    void grasp(int size_solucion, AlgoritmoVecinos* algoritmo_vecinos,
              int size_rcl = 3, int max_iteraciones = 100);
    void ramaypoda(int size_solucion, Solucion solucion,
                      int estrategia_expansion = 0);

    ostream& mostrarTabla(ostream& os);
    void algoritmoExtraInfo(ostream& os) const;
    void headerExtraInfo(ostream& os) const;

    friend ostream& operator<<(std::ostream& os, const Experimento& experimento);
  private:
    string tipo_algoritmo_;
    Problema problema_;
    Solucion solucion_;
    int size_soluciones_;
    float cpu_time_;
    int max_iteraciones_;
    int rcl_size_;
    int estrategia_expansion_;
};