#pragma once
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

class WordReader {
public:
  std::string from_file(const std::string &filename) const;
};
