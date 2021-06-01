#include "hangman.hpp"

Hangman::Hangman(const std::string &word, size_t lives)
    : word(word), lives(lives) {
  for (auto it = word.begin(); it < word.end(); ++it) {
    missed_letters.insert(*it);
  }
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

std::string Hangman::get_known_letters() {
  std::string known_letters = "";
  for (auto it = word.begin(); it < word.end(); ++it) {
    if (missed_letters.find(*it) == missed_letters.end()) {
      known_letters += *it;
    } else {
      known_letters += '*';
    }
  }
  return known_letters;
}
