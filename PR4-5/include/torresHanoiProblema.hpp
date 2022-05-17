#include <vector>
#include <algorithm>

#include "problema.hpp"
#include "torresHanoiSolucion.hpp"

using namespace std;
#pragma once

class TorresHanoiProblema : public Problema {
public:
	TorresHanoiProblema(int);
	virtual ~TorresHanoiProblema();

	bool esCasoMinimo();
	pair<Problema*,Problema*> descomponer();
	void solver(Solucion* s);
	vector<string> getRecurrencia() {
      return {a, b, c};
    }

private:
	int _n;
	string a = "2";
	string b = "n/2";
	string c = "n";
};