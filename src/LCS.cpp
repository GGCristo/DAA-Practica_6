// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "../include/LCS.hpp"

LCS::LCS() {
  std::cout << "Introduzca un string\n";
  std::cin >> string1_;
  std::cout << "Introduzca otro string\n";
  std::cin >> string2_;
  tabla_.resize(string1_.size() + 1);
  for (size_t i = 0; i < tabla_.size(); ++i) {
    tabla_[i].resize(string2_.size() + 1);
  }
  construirTabla();
}

LCS::LCS(const std::string& string1, const std::string& string2) :
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


std::vector<std::string> LCS::getSecuence() {
  return getSecuence(tabla_.size() - 1 , tabla_[0].size() - 1);
}

std::vector<std::string> LCS::getSecuence(int i, int j) {
  std::vector<std::string> secuences;
  puntoPendiente::stringSize_ = tabla_[i][j];
  puntoPendiente inicial (i, j);
  std::queue<puntoPendiente> queue;
  queue.push(inicial);
  while(!queue.empty()) {
    i = queue.front().i_;
    j = queue.front().j_;
    std::string result = queue.front().soFar_;
    while(i > 0 && j > 0) {
      if (tabla_[i - 1][j] == tabla_[i][j]) {
        if (tabla_[i][j - 1] == tabla_[i][j]) {
          queue.push(puntoPendiente(i, j - 1, result));
        }
        --i;
      } else if (tabla_[i][j - 1] == tabla_[i][j]) {
        --j;
      } else {
        result.insert(0, 1, string2_[j - 1]);
        --i; --j;
      }
    }
    queue.pop();
    if (find(secuences.begin(), secuences.end(), result) == secuences.end()) {
      secuences.push_back(result);
    }
  }
  return secuences;
}

std::ostream& LCS::showTable(std::ostream& os) {
  std::cout << "String filas: " << string1_ << '\n';
  std::cout << "String columnas: " << string2_ << '\n';
  for (size_t i = 1; i < tabla_.size(); ++i) {
    for (size_t j = 1; j < tabla_[0].size(); ++j) {
      os << tabla_[i][j] << ' ';
    }
    os << '\n';
  }
  return os;
}
