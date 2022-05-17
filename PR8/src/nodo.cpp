#include "../include/nodo.hpp"

Nodo::Nodo(float value, float upper_bound) {
  valor_ = value;
  limite_superior_ = upper_bound;
  is_podado_ = false;
  is_solucion_ = false;
  is_expandido_ = false;
}

void Nodo::agregarPunto(Punto punto) { solucion_parcial_.agregarPunto(punto); }

void Nodo::setSolucion(Solucion solucion) { solucion_parcial_ = solucion; }

void Nodo::setIsExpandido(bool expanded) { is_expandido_ = expanded; }

void Nodo::setIsPodado(bool pruned) { is_podado_ = pruned; }

void Nodo::setIsSolucion(bool solucion) { is_solucion_ = solucion; }

float Nodo::getValor() { return valor_; }

Solucion Nodo::getSolucion() { return solucion_parcial_; }

float Nodo::getLimiteSuperior() { return limite_superior_; }

bool Nodo::getIsPodado() { return is_podado_; }

bool Nodo::getIsExpandido() { return is_expandido_; }

bool Nodo::getIsSolucion() { return is_solucion_; }
