#include "../include/framework.hpp"

Framework::Framework() {}

Framework::~Framework() {}

void Framework::divideyVenceras(Problema* problema, Solucion* solucion){
  if (problema->esCasoMinimo()){
    problema->solver(solucion);
  }
  else{
    nivel++;
    pair<Problema*,Problema*> subProblemas;
    pair<Solucion*,Solucion*> subSoluciones;
    subProblemas = problema->descomponer();
    subSoluciones.first = solucion->getInstance();
    subSoluciones.second = solucion->getInstance();
    divideyVenceras(subProblemas.first, subSoluciones.first);
    divideyVenceras(subProblemas.second, subSoluciones.second);
    solucion->mezcla(subSoluciones);
  }
};

void Framework::divideyVencerasBusquedaBinaria(Problema* problema, Solucion* solucion){
  if (problema->esCasoMinimo()){
    problema->solver(solucion);
  }
  else{
    nivel++;
    pair<Problema*,Problema*> subProblemas;
    pair<Solucion*,Solucion*> subSoluciones;
    subProblemas = problema->descomponer();
    subSoluciones.first = solucion->getInstance();
    divideyVencerasBusquedaBinaria(subProblemas.first, subSoluciones.first);
    solucion->mezcla(subSoluciones);
  }
};

string Framework::getRecurrencia(Problema* problema) {
  string salida = "";
  salida += "T(n) <= ";
  salida += problema->getRecurrencia()[0];
  salida += "T(";
  salida += problema->getRecurrencia()[1];
  salida += ") + ";
  salida += problema->getRecurrencia()[2];
  return salida;
};
