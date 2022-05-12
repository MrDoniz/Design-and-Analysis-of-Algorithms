#include "../include/grasp.hpp"

void Grasp::ejecutar(Instancia problema, Solucion &solucion) {
  //elegirMetodoBusqueda();
  metodoBusqueda_ = 2;
  tiempo_ = clock();
  preProcesamiento(problema);
  while(!condicionDeParada(solucion)) {
    //cout << "Iteración: " << iteraciones_ << endl;
    faseConstructiva(problema);
    almacenarResultado(problema, solucion);
    postProcesamiento(problema, solucion);
    actualizar(problema);
  }
  tiempo_ = clock() - tiempo_;
  //cout << "Mejor coste: " << mejorCoste_ << " - Tiempo: " << tiempo_ << endl;
}

bool Grasp::condicionDeParada(Solucion &solucion) {
  iteraciones_++;
  if (iteraciones_ > 10) {
    return true;
  }
  return false;
}

void Grasp::faseConstructiva(Instancia &problema) {
  for (unsigned i = 0; i < numeroClientes_; i++) {
    problema.visitar(i, false);
  }
  for (unsigned i = 0; i < ruta_ij.size(); i++) {
    ruta_ij[i].clear();
  }
  vector<pair<int, int>> elegido;
  vector<pair<int, int>> mejores_ij;
  unsigned clientes = 1;
  elegido.resize(numero_rutas_);
  for (int ruta = 0; ruta < numero_rutas_; ruta++) {
    ruta_ij[ruta].push_back(make_pair(0, 0));
    elegido[ruta] = make_pair(0, 0);
    problema.visitar(elegido[ruta].second, true);
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
        mejores_ij.clear();
        int medida = problema.getNumeroClientes() - ruta_ij[ruta].size();
        if (medida > candidatos_) {
          for (int i = 0; i < 3; i++) {
            mejores_ij.push_back(distanciaMinima(problema, elegido[ruta]));
          }
        } else {
          for (int i = 0; i < medida; i++) {
            mejores_ij.push_back(distanciaMinima(problema, elegido[ruta]));
          }
        }
        elegido[ruta] = eleccionAleatoria(problema, mejores_ij);
        ruta_ij[ruta].push_back(elegido[ruta]);
        clientes ++;
        rutas[ruta]++;
      }
    }
  }
  for (int ruta = 0; ruta < numero_rutas_; ruta++) {
    ruta_ij[ruta].push_back(make_pair(elegido[ruta].second, 0));
  }
}

void Grasp::postProcesamiento(Instancia &problema, Solucion &solucion) {
  bool salir = false;
  Solucion mejorSolucion = solucion;
  while (!salir) {
  //for (int i = 0; i < 11; i++) {
    BusquedaLocal busquedaLocal(metodoBusqueda_);
    mejorLocal_ = busquedaLocal.ejecutar(problema, mejorSolucion);
    //cout << "Mejor local: " << mejorLocal_.getCosteTotal() << " < Entorno: " << mejorSolucion.getCosteTotal() << endl;
    if (mejorLocal_.getCosteTotal() >= mejorSolucion.getCosteTotal()) {
      if (mejorLocal_.getCosteTotal() < mejorCoste_) {
        mejorCoste_ = mejorLocal_.getCosteTotal();
      }
      salir = true;
    } else {
      mejorSolucion = mejorLocal_;
      mejorAmbiente = mejorSolucion;
    }
  }
}

void Grasp::actualizar(Instancia &problema) {}

void Grasp::elegirMetodoBusqueda() {
  int opcion;
  cout << "-------------------------" << endl;
  cout << "1) Intra-reinserción" << endl;
  cout << "2) Inter-reinserción" << endl;
  cout << "3) Intra-cambio" << endl;
  cout << "4) Inter-cambio" << endl;
  cout << "5) 2 opt" << endl;
  cout << "Seleccione método de búsqueda: ";
  cin >> opcion;
  cout << endl;
  if (opcion > 5 || opcion < 1) {
    metodoBusqueda_ = 1;
  }
  metodoBusqueda_ = opcion;
}