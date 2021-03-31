// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <chrono>
#include "../include/LCS.hpp"


int main() {
  auto t1 = std::chrono::high_resolution_clock::now();
  // LCS lcs("AAACCGTGAGTTATTCGTTCTAGAA", "CACCCCTAAGGTACCTTTGGTTC");
  LCS lcs("babce", "abdace");
  auto t2 = std::chrono::high_resolution_clock::now();
  // LCS lcs;
  lcs.showTable();
  std::vector<std::string> resultado = lcs.getSecuence();
  std::cout << "Time:\n"
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  std::cout << "Longitud: " << puntoPendiente::stringSize_ << '\n';
  for (size_t i = 0; i < resultado.size(); ++i) {
    std::cout << i + 1 << ": " << resultado[i] << '\n';
  }
  return 0;
}
