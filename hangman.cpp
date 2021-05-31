#include "hangman.hpp"

Hangman::Hangman(const std::string &word_, size_t lives_) {
  word = word_;
  lives = lives_;
  for (auto it = word.begin(); it < word.end(); ++it) {
    missed_letters.insert(*it);
  }
}

Hangman::Hangman(const Hangman &copy) {
  word = copy.word;
  known_letters = copy.known_letters;
  missed_letters = copy.missed_letters;
  lives = copy.lives;
}

auto Hangman::guess_letter(char letter) -> bool {
  auto find_letter = std::find(word.begin(), word.end(), letter);
  if (find_letter != word.end()) {
    known_letters.insert(letter);
    missed_letters.erase(letter);
    return true;
  }
  if (lives != 0U) {
    --lives;
  }
  return false;
}

size_t Hangman::get_lives() const { return lives; }

bool Hangman::all_letters_known() const { return missed_letters.empty(); }

bool Hangman::lives_ended() const { return (lives == 0); }

std::set<char> Hangman::get_missed_letters() const { return missed_letters; }
