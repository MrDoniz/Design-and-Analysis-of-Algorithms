#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Memoria {
  public:
    Memoria(void);
    void store(int pos, int val);
    int  load(int pos);
    
  private:
    vector<int> memoria_;
};