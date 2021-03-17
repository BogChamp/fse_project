#ifndef MAIN_WORD_H
#define MAIN_WORD_H

#include <fstream>
#include <string>
#include <ctime>
#include <iostream>

struct Word
{
    Word(const std::string &File = " ");
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

#endif 