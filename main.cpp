#include <iostream>

#include "hangman.hpp"
#include "wordreader.hpp"

int main() {
  try {
    WordReader wordreader;
    std::string hidden_word = wordreader.from_file("dictionary");
    Hangman hangman(hidden_word);
    std::set<char> missed_letters;

    std::cout << ">> Welcome to the game HANGMAN" << std::endl;
    std::cout << ">> You have only " << hangman.get_lives()
              << " chances to miss" << std::endl;
    std::cout << ">> GLHF" << std::endl;
    char guessed_letter;
    while (true) {
      std::cout << ">> Guess Letter: ";
      std::cin >> guessed_letter;
      if (hangman.guess_letter(guessed_letter))
        std::cout << ">> Hit!" << std::endl;
      else
        std::cout << ">> Missed, now you have " << hangman.get_lives()
                  << " attempts" << std::endl;

      std::cout << ">>" << std::endl;
      if (hangman.lives_ended()) {
        std::cout << ">> You lost!" << std::endl;
        break;
      } else if (hangman.all_letters_known()) {
        std::cout << ">> You won!" << std::endl;
        break;
      }

      missed_letters = hangman.get_missed_letters();
      std::cout << ">> ";
      for (auto it = hidden_word.begin(); it < hidden_word.end(); ++it) {
        if (missed_letters.find(*it) == missed_letters.end()) {
          std::cout << *it;
        } else {
          std::cout << '*';
        }
      }
      std::cout << std::endl << ">>" << std::endl;
    }
  } catch (...) {
    std::cout << "Something went wrong..." << std::endl;
  }
}
