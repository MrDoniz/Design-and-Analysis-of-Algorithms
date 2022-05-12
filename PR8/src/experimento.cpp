#include "../include/experimento.hpp"
#include "../include/algoritmos/voraz.hpp"
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

void Experimento::voraz(int sizeSolucion) {
  clock_t start = clock();

  tipo_algoritmo_ = "voraz";
  size_soluciones_ = sizeSolucion;
  Estrategia estrategia(new Voraz(sizeSolucion));
  solucion_ = estrategia.run(problema_);

  cpu_time_ = (clock() - start) / (double)CLOCKS_PER_SEC;
}

ostream& Experimento::mostrarTabla(ostream& os) {
  string problema_nombre = getProblema().getFichero();
  problema_nombre = regex_replace(problema_nombre, regex("examples/"), "");

  os << "| " << problema_nombre << " | " << getProblema().getPuntosSize()
     << " | " << getProblema().getDimensionSize() << " | "
     << setw(3) << getSizeSoluciones() << " |";
  
  

  os << setw(10) << getSolucion().calcularObjetivoFunction();


  //recorro el bucle y guardo en una cadena los punto.getID
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
     << "                    ";
  os << "| n"
     << "  ";
  os << "| K"
     << " ";
  os << "| m"
     << "   ";
  os << "| z"
     << "         ";
  os << "| S"
     << "                    ";
  os << "|      CPU      |\n";
  os << "|-----------------------------|----|---|-----|-----------|----------------------|---------------|";
  return os;
}