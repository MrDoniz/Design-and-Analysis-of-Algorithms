#include <vector>
#include <algorithm>

#include "solucion.hpp"
#include "problema.hpp"

class Voraz {
  public:
    Voraz ();
    ~Voraz ();
    Solucion resolverVorazmente(Problema problema);
    int getCIUDAD_INICIAL();
  private:
    int ciudad_inicial = 0;
};