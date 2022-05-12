#include "../include/argumentos.hpp"

Argumentos::Argumentos(int argc, char *argv[]) {
  const char* const short_opts = "ha:";
  const option long_opts[] = {{"help", no_argument, nullptr, 'h'},
                              {"algorithm", required_argument, nullptr, 'a'},
                              {nullptr, no_argument, nullptr, 0}};

  bool is_option = false;
  int opt;

  lista_argumentos_.push_back(argv[0]);

  while ((opt = getopt_long(argc, argv, short_opts, long_opts, nullptr)) !=
         -1) {
    is_option = true;
    switch (opt) {
      case 'h':
        usage();
        throw false;

      case 'a': {
        std::string name_algorithm = optarg;
        setNombreAlgoritmo(name_algorithm);
        break;
      }

      case '?':
        std::cerr << "Unknown command line argument\n";

      default:
        std::cerr << argv[0] << " -h or --help\n";
        throw false;
    }
  }

  if (!is_option) {
    if (argc < 2) {
      std::cerr << argv[0] << " -h or --help\n";
      throw false;
    } else {
      for (int i = 1; i < argc; i++) {
        lista_argumentos_.push_back(argv[i]);
      }
    }
  }
}

void Argumentos::setNombreAlgoritmo(std::string name_algorithm) {
  nombre_algoritmo_ = name_algorithm;
}

void Argumentos::usage() {
  std::cerr << "USAGE\n";
  std::cerr << "SYNOPSIS\n";
  std::cerr << "\t" << lista_argumentos_[0] << " input_problem.txt\n";

  std::cerr << "DESCRIPTION\n";
  std::cerr << "\tMaximum Diversity problem\n ";

  std::cerr << "OPTIONS\n";
  std::cerr << "\t[-h][--help]            Help manual\n";
}

vector<std::string> Argumentos::getListaArgumentos() {
  return lista_argumentos_;
}