#include "wordreader.hpp"

std::string WordReader::from_file(const std::string &filename) const {
  std::ifstream file(filename);
  std::string word;

  if (!file.is_open()) {
    throw std::runtime_error("Can't open a file!");
  } else {
    std::vector<std::string> words_from_dict;
    std::copy(std::istream_iterator<std::string>(file),
              std::istream_iterator<std::string>(),
              std::back_inserter(words_from_dict));

    uint32_t seed = time(0);
    int line;
    if (words_from_dict.size() != 0U) {
      line = rand_r(&seed) % words_from_dict.size();
      word = words_from_dict[line];
    } else {
      throw std::runtime_error("No words in dictionary!");
    }
  }
  file.close();

  return word;
}
