#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "problema.hpp"
class Instancia;

using namespace std;
#pragma once

class Solucion {
  public:
    Solucion(){};
    ~Solucion(){};
    void almacenarAtributos(int tiempo, int numero_rutas, int numeroClientes) {
      tiempo_ = tiempo;
      numero_rutas_ = numero_rutas;
      numeroClientes_ = numeroClientes;
    }
    void almacenarRuta(Instancia problema, vector<vector<pair<int, int>>> ruta_ij) {
      ruta_ij_ = ruta_ij;
      vectorCostes_.resize(numero_rutas_);
      for (unsigned ruta = 0; ruta < ruta_ij_.size(); ruta++) {
        for (unsigned cliente = 0; cliente < ruta_ij_[ruta].size(); cliente++) {
          int coste = problema.getDistancia(ruta_ij_[ruta][cliente].first, ruta_ij_[ruta][cliente].second);
          costeTotal_ += coste;
          vectorCostes_[ruta].push_back(coste);
        }
      }
    }
    int getCosteTotal() {
      return costeTotal_;
    }
    int getTiempo() {
      return tiempo_;
    }
    void actualizarCoste(Instancia &problema) {
      costeTotal_ = 0;
      vectorCostes_.resize(numero_rutas_);
      for (unsigned ruta = 0; ruta < ruta_ij_.size(); ruta++) {
        for (unsigned cliente = 0; cliente < ruta_ij_[ruta].size(); cliente++) {
          int coste = problema.getDistancia(ruta_ij_[ruta][cliente].first, ruta_ij_[ruta][cliente].second);
          costeTotal_ += coste;
          vectorCostes_[ruta].push_back(coste);
        }
      }
    }
    void mostrarRuta(Instancia &problema){
      cout << "Ruta: " << ruta_ij_.size() << " " << endl;
      for (unsigned ruta = 0; ruta < ruta_ij_.size(); ruta++) {
        cout << "Ruta " << ruta << ": " << endl;
        for (unsigned cliente = 0; cliente < ruta_ij_[ruta].size(); cliente++) {
          cout << ruta_ij_[ruta][cliente].first << " " << ruta_ij_[ruta][cliente].second << " - Coste: " << problema.getDistancia(ruta_ij_[ruta][cliente].first, ruta_ij_[ruta][cliente].second) << endl;
        }
      }
    }
    bool operator ==(Solucion& solucion) {
      if (solucion.getCosteTotal() == costeTotal_) {
        return true;
      }
      return false;
    }
    bool operator!=(const Solucion& solucion) {
      Solucion solucionCopia = solucion;
      return !(solucionCopia == *this);
    }
    int getNumeroRutas(){
      return numero_rutas_;
    }
    vector<vector<pair<int, int>>> getRuta(){
      return ruta_ij_;
    }
    void insertar(pair<int, int> cliente, int ruta, int posicion, Instancia &problema) {
      ruta_ij_[ruta][posicion] = cliente;
      actualizarCoste(problema);
    }
    void reInsertar(pair<int, int> cliente, int ruta, int posicion, Instancia &problema) {
      ruta_ij_[ruta].insert(ruta_ij_[ruta].begin() + posicion, cliente);
      actualizarCoste(problema);
    }
    void eliminar(pair<int, int> cliente, int ruta, int posicion, Instancia &problema) {
      ruta_ij_[ruta].erase(ruta_ij_[ruta].begin() + posicion);
      actualizarCoste(problema);
    }
    int getNumeroClientes(int ruta){
      return ruta_ij_[ruta].size();
    }

    void reiniciar() {
      costeTotal_ = 0;
    }
  private:
    int tiempo_;
    int numero_rutas_;
    int numeroClientes_;
    int costeTotal_ = 0;
    vector<vector<int>> vectorCostes_;
    vector<vector<pair<int, int>>> ruta_ij_;
};