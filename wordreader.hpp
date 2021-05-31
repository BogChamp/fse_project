#pragma once
#include <ctime>
#include <fstream>
#include <iostream>

class WordReader {
public:
  std::string from_file(const std::string &filename) const;
};
