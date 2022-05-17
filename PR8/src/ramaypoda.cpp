#include "../include/algoritmos/ramaypoda.hpp"
#include <algorithm>


Ramaypoda::Ramaypoda(int size_solucion, Solucion solucion_inicial,
                         int expansion_strategy) {
  size_solucion_ = size_solucion;
  solucion_inicial_ = solucion_inicial;
  limite_inferior_ = solucion_inicial.calcularObjetivoFunction();
}

Solucion Ramaypoda::ejecutar(Problema &problema) {
  Solucion mejor_solucion;
  generarPrimerNivelArbol(problema, problema.getPuntosSize());
  vector<int> nodos_activos;
  for (size_t i = 0; i < arbol_.size(); i++) {
    nodos_activos.push_back(i);
  }
  while (nodos_activos.size()) {
    podar(nodos_activos);
    int nodo_posicion = nodo_expandido_minimo();
    if (nodo_posicion != -1) {
      expandirNodo(nodo_posicion, nodos_activos, problema);
      for (auto &&nodo : arbol_) {
        if (nodo.getSolucion().getListaPuntos().size() == size_solucion_) {
          nodo.setIsSolucion(true);

          Solucion solucion = nodo.getSolucion();
          if (esMayorIgual(solucion.calcularObjetivoFunction(),
                               limite_inferior_)) {
            limite_inferior_ = solucion.calcularObjetivoFunction();
            mejor_solucion = solucion;
          }
        }
      }
    } else {
      break;
    }
  }
  return mejor_solucion;
}

void Ramaypoda::generarPrimerNivelArbol(Problema &problema, int total_nodos) {
  for (size_t i = 0; i < (total_nodos - (size_solucion_ - 1)); i++) {
    vector<Punto> lista_puntos = {problema.getPunto(i)};
    Nodo nodo(0, calcularLimiteSuperior(problema, lista_puntos));
    nodo.setSolucion(Solucion(lista_puntos));
    arbol_.push_back(nodo);
  }
}

void Ramaypoda::podar(vector<int> &nodos_activos) {
  int index = 0;
  for (auto &&nodo : arbol_) {
    if (nodo.getValor() + nodo.getLimiteSuperior() < limite_inferior_) {
      nodo.setIsPodado(true);
      if (find(nodos_activos.begin(), nodos_activos.end(), index) !=
          nodos_activos.end()) {
        nodos_activos.erase(
            find(nodos_activos.begin(), nodos_activos.end(), index));
      }
    }
    index++;
  }
}

void Ramaypoda::expandirNodo(int nodo_posicion, vector<int> &nodos_activos,
                              Problema &problema) {
  arbol_[nodo_posicion].setIsPodado(true);
  nodos_activos.erase(
      find(nodos_activos.begin(), nodos_activos.end(), nodo_posicion));
  int nivel_profundo_actual =
      arbol_[nodo_posicion].getSolucion().getListaPuntos().size();
  int ultimo_punto =
      arbol_[nodo_posicion].getSolucion().getListaPuntos().back().getId() + 1;
  int numero_de_puntos = problema.getPuntosSize();
  Solucion partial_solucion = arbol_[nodo_posicion].getSolucion();

  for (size_t i = ultimo_punto;
       i < (numero_de_puntos - (size_solucion_ - nivel_profundo_actual)); i++) {
    Solucion solucion = partial_solucion;
    solucion.agregarPunto(problema.getPunto(i));
    float nodo_value = solucion.calcularObjetivoFunction();
    Nodo nodo(nodo_value,
              calcularLimiteSuperior(problema, solucion.getListaPuntos()));
    nodo.setSolucion(solucion);
    arbol_.push_back(nodo);
    nodos_activos.push_back(arbol_.size() - 1);
  }
}

float Ramaypoda::calcularLimiteSuperior(Problema &problema,
                                         vector<Punto> puntos_procesados) {
  vector<Punto> puntos_sin_procesar =
      problema.puntosSinProcesar(puntos_procesados);

  vector<float> limite_superior_2;
  vector<float> limite_superior_3;

  for (auto &&punto : puntos_procesados) {
    for (auto &&punto_sin_procesar : puntos_sin_procesar) {
      float distancia = problema.calcularDistanciaEuclidean(punto, punto_sin_procesar);
      int posicion = 0;
      for (unsigned k = 0; k < limite_superior_2.size(); k++) {
        if (distancia < limite_superior_2[k]) {
          posicion++;
        }
      }
      limite_superior_2.insert(limite_superior_2.begin() + posicion, distancia);
    }
  }
  float limite_superior_2_value = valorLimiteSuperior(puntos_procesados.size(), limite_superior_2, 2);
  for (unsigned i = 0; i < puntos_sin_procesar.size(); i++) {
    for (unsigned j = i + 1; j < puntos_sin_procesar.size(); j++) {
      float distancia = problema.calcularDistanciaEuclidean(
          puntos_sin_procesar[i], puntos_sin_procesar[j]);
      int posicion = 0;
      for (unsigned k = 0; k < limite_superior_3.size(); k++) {
        if (distancia < limite_superior_3[k]) {
          posicion++;
        }
      }
      limite_superior_3.insert(limite_superior_3.begin() + posicion, distancia);
    }
  }

  float limite_superior_3_value = valorLimiteSuperior(puntos_procesados.size(), limite_superior_3, 3);
  return limite_superior_2_value + limite_superior_3_value;
}

float Ramaypoda::valorLimiteSuperior(int puntos_procesados_size, vector<float> limite_superior, int numero_de_limite_superior) {
  float limite_superior_value = 0;
  if (numero_de_limite_superior == 2) {
    int size = puntos_procesados_size * (size_solucion_ - puntos_procesados_size);
    for (int i = 0; i < size; i++) {
      limite_superior_value += limite_superior[i];
    }
  } else if (numero_de_limite_superior == 3) {
    int size = 0;
    for (int i = size_solucion_ - puntos_procesados_size - 1; i > 0; i--) {
      size += i;
    }
    for (int i = 0; i < size; i++) {
      limite_superior_value += limite_superior[i];
    }
  }
  return limite_superior_value;
}

int Ramaypoda::nodo_expandido_minimo() {
  int nodo_posicion = -1;
  if (estrategia_de_expansion_ == estrategia_minimo_nivel_) {
    float min_distancia = numeric_limits<float>::max();
    int index = 0;
    for (auto &&nodo : arbol_) {
      if (!nodo.getIsPodado() && !nodo.getIsExpandido() &&
          !nodo.getIsSolucion()) {
        float distancia = nodo.getLimiteSuperior();
        if (distancia < min_distancia) {
          min_distancia = distancia;
          nodo_posicion = index;
        }
      }
      index++;
    }
  } else if (estrategia_de_expansion_ == estrategia_profunda_) {
    int max_deep_level = -1;
    int index = 0;
    for (auto &&nodo : arbol_) {
      if (!nodo.getIsPodado() && !nodo.getIsExpandido() &&
          !nodo.getIsSolucion()) {
        int deep_level = nodo.getSolucion().getListaPuntos().size();
        if (deep_level > max_deep_level) {
          max_deep_level = deep_level;
          nodo_posicion = index;
        }
      }
      index++;
    }
  }
  return nodo_posicion;
}

bool Ramaypoda::esMayorIgual(float num, float other_num) {
  return (num - other_num) >= -0.001;
}
