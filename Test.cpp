#include "Word.h"
#include <gtest/gtest.h>


TEST(FooTest, IsLetterInGuessed) {
  Word f("dictionary");
  EXPECT_EQ(f.IsLetterInGuessed(f.String[0]), false);
}

TEST(FooTest, IsLetterInWord) {
  Word f("dictionary");
  EXPECT_EQ(f.IsLetterInWord(f.String[0]), true);
}

TEST(FooTest, IsLetterInWord2) {
  Word f("dictionary");
  EXPECT_EQ(f.IsLetterInWord('~'), false);
}

TEST(FooTest, IfGuessedWholeWorld) {
  Word f("dictionary");
  EXPECT_EQ(f.IfGuessedWholeWord(), false);
}

TEST(FooTest, IfEmpty) {
  Word f;
  EXPECT_EQ(f.IfGuessedWholeWord(), true);
}

TEST(FooTest, LetterInEmpty) {
  Word f;
  EXPECT_EQ(f.IsLetterInGuessed('D'), false);
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
