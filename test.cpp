#include "hangman.hpp"
#include "wordreader.hpp"
#include <gtest/gtest.h>

TEST(HangmanTest, WordReaderTest) {
  WordReader wordreader;
  EXPECT_EQ(wordreader.from_file("testdict"), "testing");
  int key = 0;
  try {
    wordreader.from_file("doesn't exist");
  } catch (std::runtime_error &e) {
    ++key;
  }
  EXPECT_EQ(key, 1);
  try {
    wordreader.from_file("testdict2");
  } catch (std::runtime_error &e) {
    ++key;
  }
  EXPECT_EQ(key, 2);
}

TEST(HangmanTest, ConstMethodTests) {
  WordReader wordreader;
  Hangman hangman(wordreader.from_file("testdict"));

  EXPECT_EQ(hangman.get_lives(), 5);
  EXPECT_FALSE(hangman.all_letters_known());
  EXPECT_FALSE(hangman.lives_ended());
}

TEST(HangmanTest, GuessingTest) {
  WordReader wordreader;
  Hangman hangman(wordreader.from_file("testdict"));

  EXPECT_TRUE(hangman.guess_letter('t'));
  EXPECT_FALSE(hangman.guess_letter('p'));
  EXPECT_EQ(hangman.get_lives(), 4);
  EXPECT_TRUE(hangman.guess_letter('e'));
  EXPECT_TRUE(hangman.guess_letter('s'));
  EXPECT_TRUE(hangman.guess_letter('i'));
  EXPECT_TRUE(hangman.guess_letter('n'));
  EXPECT_TRUE(hangman.guess_letter('g'));
  EXPECT_TRUE(hangman.all_letters_known());
}

TEST(HangmanTest, WordPresentTest) {
  WordReader wordreader;
  std::string hidden_word = wordreader.from_file("testdict");
  Hangman hangman(hidden_word);

  EXPECT_EQ(hangman.get_known_letters(), "*******");
  EXPECT_TRUE(hangman.guess_letter('t'));
  EXPECT_FALSE(hangman.guess_letter('j'));
  EXPECT_EQ(hangman.get_lives(), 4);
  EXPECT_TRUE(hangman.guess_letter('e'));
  EXPECT_TRUE(hangman.guess_letter('s'));
  EXPECT_EQ(hangman.get_known_letters(), "test***");

  EXPECT_TRUE(hangman.guess_letter('i'));
  EXPECT_TRUE(hangman.guess_letter('n'));
  EXPECT_TRUE(hangman.guess_letter('g'));
  EXPECT_TRUE(hangman.all_letters_known());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
