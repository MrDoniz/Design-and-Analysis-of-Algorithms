#include <iostream>
#include "estrategia.hpp"
#include "matriz.hpp"
using namespace std;


class Interfaz {
  public:
    Interfaz() {
      estrategia_ = NULL;
    }

    Interfaz(Estrategia *estrategia) {
      estrategia_ = estrategia;
    }
    
    void set_estrategia(Estrategia *estrategia) {
      estrategia_ = estrategia;
    }

    void operacion(Matriz &a, Matriz &b) {
      if(estrategia_)
        estrategia_ -> multiplicar(a,b);
      else
        std::cout << "No se ha establecido una estrategia\n";
    }
    
  protected:
    Estrategia *estrategia_;
};