#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class LCS {
  public:
    LCS();
    LCS(const std::string&, const std::string&);
    std::vector<std::string> getSecuence();
    std::vector<std::string> getSecuence(int, int);
    std::ostream& showTable(std::ostream& os = std::cout);
  private:
    void construirTabla();
    std::string string1_;
    std::string string2_;
    std::vector<std::vector<int>> tabla_;
};

struct puntoPendiente {
  int i_, j_;
  std::string soFar_;
  inline static int stringSize_ = 0;
  puntoPendiente(int i, int j) :
    i_(i), j_(j) {
      soFar_.reserve(stringSize_);
    }
  puntoPendiente(int i, int j, const std::string& soFar) :
    i_(i), j_(j), soFar_(soFar) {
      soFar_.reserve(stringSize_);
    }
};
