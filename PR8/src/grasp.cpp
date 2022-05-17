#include "../include/algoritmos/grasp.hpp"
#include "../include/busquedalocal.hpp"
#include <algorithm>

GRASP::GRASP(int size_solucion, AlgoritmoVecinos *algoritmo_vecinos,
             int size_lrc, int max_iteraciones) {
  size_solucion_ = size_solucion;
  algoritmo_vecinos_ = algoritmo_vecinos;
  size_lrc_ = size_lrc;
  max_iteraciones_ = max_iteraciones;
}

Solucion GRASP::ejecutar(Problema &problema) {
  Solucion solucion;
  Solucion mejor_solucion = construccionAleatoriaCodiciosa(problema);
  BusquedaLocal busqueda_local(algoritmo_vecinos_);
  for (size_t i = 0; i < max_iteraciones_; i++) {
    solucion = construccionAleatoriaCodiciosa(problema);
    solucion = busqueda_local.ejecutar(solucion, problema);
    if (solucion.calcularObjetivoFunction() >
        mejor_solucion.calcularObjetivoFunction()) {
      mejor_solucion = solucion;
    }
  }
  return mejor_solucion;
}

Solucion GRASP::construccionAleatoriaCodiciosa(Problema &problema) {
  Solucion solucion;
  Punto punto_aleatorio = seleccionarCandidatoAleatorio(problema.getListaPuntos());
  solucion.agregarPunto(punto_aleatorio);

  while (solucion.getListaPuntos().size() < size_solucion_) {
    vector<Punto> lrc = construirLRC(problema, solucion);
    Punto candidato = seleccionarCandidatoAleatorio(lrc);
    solucion.agregarPunto(candidato);
  }
  return solucion;
}

vector<Punto> GRASP::construirLRC(Problema &problema, Solucion &solucion) {
  vector<Punto> candidatos = problema.puntosSinProcesar(solucion.getListaPuntos());
  int real_size_lrc = candidatos.size() < size_lrc_ ? candidatos.size() : size_lrc_;

  vector<pair<float, Punto>> lista_candidatos_ordenada;

  for (auto &&punto : candidatos) {
    solucion.agregarPunto(punto);
    float valor_func_obj = solucion.calcularObjetivoFunction();
    solucion.getListaPuntos().pop_back();

    int posicion_a_insertar = 0;
    for (auto &&objetive_function : lista_candidatos_ordenada) {
      if (valor_func_obj < objetive_function.first) {
        posicion_a_insertar++;
      }
    }
    lista_candidatos_ordenada.insert(
        lista_candidatos_ordenada.begin() + posicion_a_insertar,
        make_pair(valor_func_obj, punto));
  }

  vector<Punto> mejoresElementosLRC;
  for (int i = 0; i < real_size_lrc; i++) {
    mejoresElementosLRC.push_back(lista_candidatos_ordenada[i].second);
  }

  return mejoresElementosLRC;
}

Punto GRASP::seleccionarCandidatoAleatorio(vector<Punto> lrc) {
  int indice = 0;
  if (lrc.size()) {
    indice = rand() % lrc.size();
  }
  return lrc[indice];
}
