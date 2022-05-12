#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Memoria {
  public:
    Memoria(void);
    void store(int pos, int val);
    int  load(int pos);
    void mostrarMemoria(void);
    
  private:
    vector<int> memoria_;
};