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

      std::cout << ">> The word: " << hangman.get_known_letters() << std::endl;
    }
  } catch (std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }
}
