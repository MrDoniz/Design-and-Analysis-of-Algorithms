#include "../include/problema.hpp"

Instancia::Instancia(string nombreFichero) {
  nombreFichero_ = "instancias/" + nombreFichero;
  leerInstancia();
};

Instancia::~Instancia() {
};

void Instancia::leerInstancia() {
  ifstream fichero;
  fichero.open(nombreFichero_);
  if (fichero.is_open()) {
    string linea;
    getline(fichero, linea);
    n_clientes = stoi(linea.substr(linea.find('\t') + 1));
    getline(fichero, linea);
    n_vehiculos = stoi(linea.substr(linea.find('\t') + 1));
    getline(fichero, linea);
    distancia.resize(n_clientes + 1);
    vector<int> numeros;
    while (getline(fichero, linea)) {
      stringstream ss(linea);
      int numero;
      while (ss >> numero) {
        numeros.push_back(numero);
      }
    }
    int k = 0;
    for (int i = 0; i < n_clientes + 1; i++) {
      distancia[i].resize(n_clientes + 1);
      for (int j = 0; j < n_clientes + 1; j++) {
        distancia[i][j].setValor(numeros[k]);
        k++;
      }
    }
    fichero.close();
  } else {
    cout << "No se ha podido abrir el fichero " << nombreFichero_ << endl;
  }
  for (int cliente = 0; cliente < n_clientes + 1; cliente++) {
    visitados.push_back(make_pair(cliente, false));
  }
};

int Instancia::getNumeroClientes() {
  return n_clientes;
};

int Instancia::getNumeroVehiculos() {
  return n_vehiculos;
};

vector<vector<Nodo>> Instancia::getDistanciaTotal() {
  return distancia;
};

int Instancia::getDistancia(int i, int j) {
  return distancia[i][j].getValor();
};

void Instancia::visitar(int j, bool valor) {
  visitados[j].second = valor;
};

bool Instancia::getVisitado(int j) {
  return visitados[j].second;
};
