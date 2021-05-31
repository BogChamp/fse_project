#include "wordreader.hpp"

std::string WordReader::from_file(const std::string &filename) const {
  std::ifstream file(filename);
  std::string word = "";

  if (!file.is_open()) {
    throw std::exception();
  } else {
    size_t count_lines = 0;
    std::ifstream lines_counter(filename);

    while (!lines_counter.eof()) {
      if (lines_counter.get() == '\n')
        ++count_lines;
    }

    uint32_t seed = time(0);
    int line;
    if (count_lines != 0U) {
      line = rand_r(&seed) % count_lines;
      while (line != 0) {
        while (file.get() != '\n')
          ;
        line--;
      }
    }
    int c;
    while ((c = file.get()) != '\n')
      word += c;
  }
  file.close();

  return word;
}
