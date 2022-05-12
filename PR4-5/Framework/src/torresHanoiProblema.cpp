#include "../include/torresHanoiProblema.hpp"

TorresHanoiProblema::TorresHanoiProblema(int n) : Problema::Problema() {
	_n = n;
}

TorresHanoiProblema::~TorresHanoiProblema() {

}

bool TorresHanoiProblema::esCasoMinimo() {
	return (_n == 0);
}

pair<Problema*,Problema*> TorresHanoiProblema::descomponer() {
  std::pair<Problema*, Problema*> subProblemas;
	return subProblemas;
}

void TorresHanoiProblema::solver(Solucion* s) {
	if (_n == 0){
		_n = 1;
	}
	((TorresHanoiSolucion*)s)->setValor(_n);
}