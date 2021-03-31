#pragma once
#include <iostream>
#include <vector>
#include <string_view>

class LCS {
  public:
    LCS();
    LCS(std::string_view, std::string_view);
    std::string getSecuence(int i = -1, int j = -1);
    std::ostream& showTable(std::ostream& os = std::cout);
  private:
    void construirTabla();
    std::string_view string1_;
    std::string_view string2_;
    std::vector<std::vector<int>> tabla_;
};
