/* "Copyright [year] <Copyright Owner>" */
#include "Word.h"

Word::Word(const std::string &File) {
    std::ifstream Dictionary(File);
    if (!Dictionary.is_open()) {
        this->String = nullptr;
        this->GuessedLetters = nullptr;
        this->Capacity = 0;
        this->Size = 0;
        this->GuessToWin = this->Size;
    } else {
        unsigned int seed = time(0);

        int LineOfWord = rand_r(&seed) % 6;
        while (LineOfWord != 0) {
            while (Dictionary.get() != '\n') {}
            LineOfWord--;
        }

        this->Capacity = 16;
        this->String = new char[this->Capacity];
        this->Size = 0;

        while ((this->String[this->Size] = Dictionary.get()) != '\n')
            this->Size++;

        this->GuessedLetters = new char[this->Size];
        for (int i = 0 ; i < this->Size ; ++i)
            this->GuessedLetters[i] = '*';
        this->GuessToWin = this->Size;
    }
    Dictionary.close();
}


Word::Word(const Word &Copy) {
    this->Capacity = Copy.Capacity;
    this->Size = Copy.Size;
    this->GuessToWin = Copy.GuessToWin;

    if (this->String)
        delete[] String;
    if (this->GuessedLetters)
        delete[] GuessedLetters;

    this->String = new char[this->Capacity];
    this->GuessedLetters = new char[this->Size];

    for (int i = 0 ; i < this->Size ; ++i) {
        this->String[i] = Copy.String[i];
        this->GuessedLetters[i] = Copy.GuessedLetters[i];
    }
}


Word::~Word() {
    if (this->GuessedLetters)
        delete[] GuessedLetters;
    if (this->String)
        delete[] String;
}


bool Word::IsLetterInWord(char Letter) {
    bool Assumption = false;

    if (IsLetterInGuessed(Letter))
        Assumption = true;

    if (!Assumption) {
        for (int i = 0 ; i < this->Size ; ++i) {
            if (Letter == this->String[i]) {
                AddToGuessedLetters(Letter);
                Assumption = true;
                break;
            }
        }
    }

    return Assumption;
}


bool Word::IsLetterInGuessed(char Letter) {
    bool IsTrue = false;

    for (int i = 0 ; i < this->Size ; ++i) {
        if (Letter == this->GuessedLetters[i]) {
            IsTrue = true;
            break;
        }
    }

    return IsTrue;
}


void Word::AddToGuessedLetters(char Letter) {
    for (int i = 0 ; i < this->Size ; ++i) {
        if (Letter == this->String[i]) {
            this->GuessedLetters[i] = this->String[i];
            this->GuessToWin--;
        }
    }
}


void Word::PrintWord() {
    std::cout << "> The word: " << GuessedLetters << std::endl;
    std::cout << "> " << std::endl;
}
