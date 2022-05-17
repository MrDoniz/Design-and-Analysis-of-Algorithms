#include "solucion.hpp"

using namespace std;
#pragma once

class Nodo {
 public:
  Nodo() {}
  Nodo(float valor, float limite_superior);
  ~Nodo() {}

  void agregarPunto(Punto point);
  void setSolucion(Solucion solucion);
  void setIsExpandido(bool expandido);
  void setIsPodado(bool podado);
  void setIsSolucion(bool solucion);

  float getValor();
  Solucion getSolucion();
  float getLimiteSuperior();
  bool getIsPodado();
  bool getIsExpandido();
  bool getIsSolucion();

 private:
  Solucion solucion_parcial_;
  float valor_;
  float limite_superior_;
  bool is_expandido_;
  bool is_podado_;
  bool is_solucion_;
};
