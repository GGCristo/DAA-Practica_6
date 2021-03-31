// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <chrono>
#include "../include/LCS.hpp"


int main() {
  auto t1 = std::chrono::high_resolution_clock::now();
  LCS lcs("AAACCGTGAGTTATTCGTTCTAGAA", "CACCCCTAAGGTACCTTTGGTTC");
  // LCS lcs("abdace", "babce");
  // LCS lcs;
  auto t2 = std::chrono::high_resolution_clock::now();
  // LCS lcs;
  std::cout << "TEST1 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  lcs.showTable();
  std::cout << lcs.getSecuence();
  return 0;
}
