#include <iostream>

#include "Word.h"

int LIFE = 5;

int main()
{
    Word MysteryWord("dictionary");

    char GuessedLetter = ' ';

    std::cout << "> Welcome to \"The Gallow\" game!" << std::endl;
    std::cout << "> You have no more than " << LIFE << " attempts to make a mistake." << std::endl;

    while(LIFE != 0)
    {
        std::cout << "> Guess a letter: " << std::endl;
        std::cout << "< ";
        std::cin >> GuessedLetter;

        if (MysteryWord.IsLetterInWord(GuessedLetter))
            std::cout << "> Hit!" << std::endl;
        else
        {
            LIFE--;
            std::cout << "> Missed, you have only " << LIFE << " attempts now." << std::endl;    
        }
        std::cout << "> " << std::endl;
        MysteryWord.PrintWord();
        
        if (MysteryWord.GuessToWin == 0)
        {
            std::cout << "> YOU WON!" << std::endl;
            break;
        }
    }

    if (LIFE == 0)
        std::cout << "> Haha, you lost!" << std::endl;

    return 0;
}