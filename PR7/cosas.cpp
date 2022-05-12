int Voraz::buscarColumna(Instancia &problema) {
  int i = distancia_minima_[0];
  int j = distancia_minima_[1];
  int aux = 999;
  int jmenor = 0;
  for (jmenor = 1; jmenor < problema.getNumeroClientes(); jmenor++) {
    if (problema.getDistancia(i, jmenor) < aux) {
        j = jmenor;
        aux = problema.getDistancia(i, jmenor);
    }
  }
  return j;
}

int Voraz::buscarFila(Instancia &problema) {
  int i = distancia_minima_[0];
  int j = distancia_minima_[1];
  int aux = 999;
  int imenor = 0;
  for (imenor = 1; imenor < problema.getNumeroClientes(); imenor++) {
    if (problema.getDistancia(imenor, j) < aux) {
      i = imenor;
      aux = problema.getDistancia(imenor, j);
    }
  }
  return i;
}

void Voraz::distanciaMinima(Instancia &problema) {
  int columna = buscarColumna(problema);
  int fila = buscarFila(problema);
  if (problema.getDistancia(fila, 0) < problema.getDistancia(0, columna)) {
    distancia_minima_[0] = fila;
    distancia_minima_[1] = distancia_minima_[1];
  } else {
    distancia_minima_[0] = distancia_minima_[0];
    distancia_minima_[1] = columna;
  }
  problema.visitar(distancia_minima_[0], distancia_minima_[1]);
}







