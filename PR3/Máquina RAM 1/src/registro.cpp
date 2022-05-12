#include "../include/registro.hpp"


int Registro::operator[](int id) {
  return banco_registros_[id];
}

void Registro::mostrarRegistro(int id) {
  std::cout << "R[" << id << "]: " << banco_registros_[id];
}

void Registro::assign(int register_size) {
  for (int id = 0; id < register_size; id++) {
    banco_registros_.insert({id, 0});
  }
}

void Registro::push(int id, int value) { 
  banco_registros_[id] = value; 
}

void Registro::clear() { banco_registros_.clear(); }