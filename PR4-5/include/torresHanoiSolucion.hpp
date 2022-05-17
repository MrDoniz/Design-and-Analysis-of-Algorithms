#include <vector>
#include <algorithm>

#include "solucion.hpp"

using namespace std;
#pragma once

class TorresHanoiSolucion : public Solucion {
public:
	TorresHanoiSolucion();
	virtual ~TorresHanoiSolucion();

	void resolver();
	void mezcla(pair<Solucion*,Solucion*>);
	Solucion* getInstance();

	void setValor(int);

private:
	int _n;
};