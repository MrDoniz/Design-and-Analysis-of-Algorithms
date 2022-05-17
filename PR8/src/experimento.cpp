#include "../include/experimento.hpp"
#include "../include/algoritmos/voraz.hpp"
#include "../include/algoritmos/grasp.hpp"
#include "../include/algoritmos/ramaypoda.hpp"
#include "../include/estrategia.hpp"
//#include "timer.cpp"

#include <regex>
#include <iomanip>

using namespace std;

Experimento::Experimento(Problema problema, string nombre_algoritmo) {
  problema_ = problema;
  tipo_algoritmo_ = nombre_algoritmo;
}

int Experimento::getSizeSoluciones() const {
  return size_soluciones_;
}

float Experimento::getCPUtime() const {
  return cpu_time_;
}

Solucion Experimento::getSolucion() const {
  return solucion_;
}

Solucion& Experimento::getSolucion() {
  return solucion_;
}

string Experimento::getTipoAlgoritmo() const {
  return tipo_algoritmo_;
}

Problema Experimento::getProblema() const {
  return problema_;
}

void Experimento::voraz(int size_solucion) {
  clock_t start = clock();

  tipo_algoritmo_ = "voraz";
  size_soluciones_ = size_solucion;
  Estrategia estrategia(new Voraz(size_solucion));
  solucion_ = estrategia.run(problema_);

  cpu_time_ = (clock() - start) / (double)CLOCKS_PER_SEC;
}

void Experimento::grasp(int sizeSolucion,
                       AlgoritmoVecinos* algoritmo_vecinos, int size_rcl,
                       int max_iteraciones) {
  clock_t start = clock();

  tipo_algoritmo_ = "grasp";
  size_soluciones_ = sizeSolucion;
  max_iteraciones_ = max_iteraciones;
  rcl_size_ = size_rcl;
  Estrategia estrategia(new GRASP(sizeSolucion, algoritmo_vecinos, size_rcl, max_iteraciones));
  solucion_ = estrategia.run(problema_);

  cpu_time_ = (clock() - start) / (double)CLOCKS_PER_SEC;
}

void Experimento::ramaypoda(int size_solucion, Solucion solucion,
                              int expansion_estrategia) {
  clock_t start = clock();

  tipo_algoritmo_ = "branch_bound";
  size_soluciones_ = size_solucion;
  estrategia_expansion_ = expansion_estrategia;

  Estrategia estrategia( new Ramaypoda(size_solucion, solucion, expansion_estrategia));
  solucion_ = estrategia.run(problema_);

  cpu_time_ = (clock() - start) / (double)CLOCKS_PER_SEC;
}

ostream& Experimento::mostrarTabla(ostream& os) {
  string problema_nombre = getProblema().getFichero();
  problema_nombre = regex_replace(problema_nombre, regex("examples/"), "");

  os << "| " << problema_nombre << " | " << getProblema().getPuntosSize()
     << " | " << getProblema().getDimensionSize() << " | "
     << setw(3) << getSizeSoluciones() << " |";
  
    if (tipo_algoritmo_ == "grasp") {
    os << ' ' << setw(4) << max_iteraciones_ << " |   " << rcl_size_ << " |";
    }
    if (tipo_algoritmo_ == "branch_bound") {
      string nombre = estrategia_expansion_ == 0 ? "Nivel mínimo" : "Profunda";
      os << setw(14) << nombre << " |";
    }

  os << setw(10) << getSolucion().calcularObjetivoFunction();

  string puntos_id = "[";
  for (auto&& point : getSolucion().getListaPuntos()) {
    puntos_id += to_string(point.getId()) + " ";
  }
  puntos_id.pop_back();
  puntos_id += "]";

  os << " | " << setw(20) << puntos_id;

  os << " |" << setw(12) << getCPUtime() << "ms |\n";
  return os;
}

ostream& operator<<(ostream& os, const Experimento& experimento) {
  os << experimento.getTipoAlgoritmo() << "\n";
  os << "| Problema"
     << "                    "
     << "| n  "
     << "| K " 
     << "|  m  ";
  
  if (experimento.getTipoAlgoritmo()  == "grasp") {
    os << "| Iter | LRC ";
  }
  if (experimento.getTipoAlgoritmo()  == "branch_bound") {
    os << "|   Estrategia  ";
  }

  os << "| z"
     << "         ";
  os << "| S"
     << "                    ";
  os << "|      CPU      |\n";
  if (experimento.getTipoAlgoritmo()  == "voraz") {
    os << "|-----------------------------|----|---|-----|-----------|----------------------|---------------|";
  }
  if (experimento.getTipoAlgoritmo()  == "grasp") {
    os << "|-----------------------------|----|---|-----|------|-----|-----------|----------------------|---------------|";
  }
  if (experimento.getTipoAlgoritmo()  == "branch_bound") {
    os << "|-----------------------------|----|---|-----|---------------|-----------|----------------------|---------------|";
  }
  return os;
}