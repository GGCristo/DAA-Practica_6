// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "../include/LCS.hpp"

LCS::LCS() {
  std::cout << "Introduzca un string\n";
  // std::cin >> string1_;
  std::cout << "Introduzca otro string\n";
  // std::cin >> string2_;
  tabla_.resize(string1_.size() + 1);
  for (size_t i = 0; i < tabla_.size(); ++i) {
    tabla_[i].resize(string2_.size() + 1);
  }
  construirTabla();
}

LCS::LCS(std::string_view string1, std::string_view string2) :
  string1_(string1), string2_(string2), tabla_(string1.size() + 1,
  std::vector<int>(string2.size() + 1)) {
  construirTabla();
}

void LCS::construirTabla() {
  for (size_t i = 1; i < tabla_.size(); ++i) {
    for (size_t j = 1; j < tabla_[i].size(); ++j) {
      tabla_[i][j] = string1_[i - 1] != string2_[j - 1] ? std::max(tabla_[i - 1][j],
          tabla_[i][j - 1]) : 1 + tabla_[i - 1][j - 1];
    }
  }
}

std::string LCS::getSecuence(int i, int j) {
  if (i == -1) i = tabla_.size() - 1;
  if (j == -1) j = tabla_[0].size() - 1;
  std::string result;
  result.reserve(tabla_[i][j]);
  while(i > 0 && j > 0) {
    if (tabla_[i - 1][j] == tabla_[i][j]) {
      // std::cout << "Arriba\n";
      --i;
    } else if (tabla_[i][j - 1] == tabla_[i][j]) {
      // std::cout << "Izquierda\n";
      --j;
    } else {
      // std::cout << "Diagonal\n";
      result.insert(0, 1, string2_[j - 1]);
      --i; --j;
    }
  }
  if (tabla_[i][j] > 0) {
    result.insert(0, 1, string2_[j - 1]);
  }
  return result;
}

std::ostream& LCS::showTable(std::ostream& os) {
  for (size_t i = 1; i < tabla_.size(); ++i) {
    for (size_t j = 1; j < tabla_[0].size(); ++j) {
      os << tabla_[i][j] << ' ';
    }
    os << '\n';
  }
  return os;
}
