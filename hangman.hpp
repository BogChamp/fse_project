#pragma once
#include <algorithm>
#include <iostream>
#include <set>
#include <string>

class Hangman {
  std::string word;
  size_t lives;
  std::set<char> missed_letters;
  std::set<char> known_letters;

public:
  Hangman(const std::string &word_ = "hangman", size_t lives_ = 5);
  bool guess_letter(char letter);
  size_t get_lives() const;
  bool all_letters_known() const;
  bool lives_ended() const;
  std::string get_known_letters();
};
