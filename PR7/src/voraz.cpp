#include "../include/voraz.hpp"

void Voraz::ejecutar(Instancia problema, Solucion solucion) {
  tiempo_ = clock();
  preProcesamiento(problema);
  resolverVoraz(problema);
  tiempo_ = clock() - tiempo_;
  
  // Sumo los costes de la ruta
  int sumo = 0;
  for (unsigned i = 0; i < ruta_ij.size(); i++) {
    for (unsigned j = 0; j < ruta_ij[i].size(); j++) {
      sumo  += problema.getDistancia(ruta_ij[i][j].first, ruta_ij[i][j].second);
    }
  }
  cout << tiempo_ << " " << sumo << endl;
  almacenarResultado(problema, solucion);
}

void Voraz::resolverVoraz(Instancia &problema) {
  vector<pair<int, int>> ultimo;
  ultimo.resize(numero_rutas_);
  unsigned clientes = 1;
  for (int ruta = 0; ruta < numero_rutas_; ruta++) {
    ruta_ij[ruta].push_back(make_pair(0, 0));
    ultimo[ruta] = make_pair(0, 0);
    problema.visitar(ultimo[ruta].second, true);
  }
  unsigned N = numeroClientes_;
  unsigned K = numero_rutas_;
  unsigned formula = (N / K) + (N * 0.1);
  vector<unsigned> rutas;
  rutas.resize(K);
  for (unsigned i = 0; i < K; i++) {
    rutas[i] = 0;
  }
  while (clientes < numeroClientes_) {
    for (int ruta = 0; ruta < numero_rutas_; ruta++) {
      if(rutas[ruta] < formula) {
        clientes ++;
        ultimo[ruta] = distanciaMinima(problema, ultimo[ruta]);
        ruta_ij[ruta].push_back(ultimo[ruta]);
        rutas[ruta] ++;
      }
    }
  }
  for (int ruta = 0; ruta < numero_rutas_; ruta++) {
    ruta_ij[ruta].push_back(make_pair(ultimo[ruta].second, 0));
  }
}