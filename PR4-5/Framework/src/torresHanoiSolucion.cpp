#include "../include/torresHanoiSolucion.hpp"

#include<iostream>

TorresHanoiSolucion::TorresHanoiSolucion() : Solucion::Solucion() {
}

TorresHanoiSolucion::~TorresHanoiSolucion() {
}


void TorresHanoiSolucion::resolver() {
	cout << _n << endl;
}

void TorresHanoiSolucion::mezcla(pair<Solucion*,Solucion*> subSoluciones) {
  // resuelve la mezcla de las dos soluciones
  int n1 = (((TorresHanoiSolucion*)subSoluciones.first))->_n;
  int n2 = ((TorresHanoiSolucion*)subSoluciones.second)->_n;
  _n = n1+n2;
}

Solucion* TorresHanoiSolucion::getInstance() {
	return new TorresHanoiSolucion();
}

void TorresHanoiSolucion::setValor(int n) {
	_n = n;
}