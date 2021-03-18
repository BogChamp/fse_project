/* "Copyright [year] <Copyright Owner>" */
#ifndef WORD_H_
#define WORD_H_

#include <fstream>
#include <string>
#include <ctime>
#include <iostream>

struct Word {
    explicit Word(const std::string &File = " ");
    Word(const Word &Copy);
    ~Word();

    bool IsLetterInWord(char Letter);
    bool IsLetterInGuessed(char Letter);

    void AddToGuessedLetters(char Letter);
    void PrintWord();

    char* String;
    char* GuessedLetters;
    int Capacity;
    int Size;
    int GuessToWin;
};

#endif  // WORD_H_
