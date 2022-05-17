#include "algoritmo.hpp"
#include "../nodo.hpp"

using namespace std;
#pragma once

class Ramaypoda : public Algoritmo {
  public:
    Ramaypoda() {}
    Ramaypoda(int size_solucion, Solucion solucion_inicial,
                int estrategia_de_expansion = 0);
    ~Ramaypoda() {}

    Solucion ejecutar(Problema &problema);
    void generarPrimerNivelArbol(Problema &problema, int total_nodos);
    void podar(vector<int> &nodos_activos);
    void expandirNodo(int nodo_posicion, vector<int> &nodos_activos,
                    Problema &problema);
    float calcularLimiteSuperior(Problema &problema,
                                vector<Punto> puntos_procesados);
    float valorLimiteSuperior(int puntos_procesados_size,
                            vector<float> limite_superior,
                            int numero_de_limite_superior);

    int nodo_expandido_minimo();
    bool esMayorIgual(float numero, float otro_numero);

  private:
    unsigned size_solucion_;
    float limite_inferior_;
    Solucion solucion_inicial_;
    vector<Nodo> arbol_;
    const int estrategia_profunda_ = 1;
    const int estrategia_minimo_nivel_ = 0;
    int estrategia_de_expansion_;

};