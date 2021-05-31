#include "hangman.hpp"
#include "wordreader.hpp"
#include <gtest/gtest.h>

TEST(FooTest, TEST1) {
  WordReader wordreader;
  EXPECT_EQ(wordreader.from_file("testdict"), "testing");
  int key = 0;
  try {
    wordreader.from_file("does'nt exist");
  } catch (std::exception &) {
    ++key;
  }
  EXPECT_EQ(key, 1);
}

TEST(FooTest, TEST2) {
  WordReader wordreader;
  Hangman hangman(wordreader.from_file("testdict2"));

  EXPECT_EQ(hangman.get_lives(), 5);
  EXPECT_FALSE(hangman.all_letters_known());
  EXPECT_FALSE(hangman.lives_ended());
}

TEST(FooTest, TEST3) {
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

TEST(FooTest, TEST4) {
  WordReader wordreader;
  std::string hidden_word = wordreader.from_file("testdict");
  Hangman hangman(hidden_word);

  std::stringstream stream;
  std::set<char> missed_letters = hangman.get_missed_letters();
  for (auto it = hidden_word.begin(); it < hidden_word.end(); ++it) {
    stream << '*';
  }
  EXPECT_EQ(stream.str(), "*******");
  stream.str("");
  EXPECT_TRUE(hangman.guess_letter('t'));
  EXPECT_FALSE(hangman.guess_letter('j'));
  EXPECT_EQ(hangman.get_lives(), 4);
  EXPECT_TRUE(hangman.guess_letter('e'));

  Hangman hangman2(hangman);
  EXPECT_EQ(hangman2.get_lives(), 4);
  EXPECT_TRUE(hangman2.guess_letter('s'));
  missed_letters = hangman2.get_missed_letters();
  for (auto it = hidden_word.begin(); it < hidden_word.end(); ++it) {
    if (missed_letters.find(*it) == missed_letters.end()) {
      stream << *it;
      std::cout << "yes" << std::endl;
    } else {
      stream << '*';
      std::cout << "no" << std::endl;
    }
  }
  std::cout << stream.str() << std::endl;
  EXPECT_EQ(stream.str(), "test***");
  stream.str("");

  EXPECT_TRUE(hangman2.guess_letter('i'));
  EXPECT_TRUE(hangman2.guess_letter('n'));
  EXPECT_TRUE(hangman2.guess_letter('g'));
  missed_letters = hangman2.get_missed_letters();
  for (auto it = hidden_word.begin(); it < hidden_word.end(); ++it) {
    stream << *it;
  }
  EXPECT_EQ(stream.str(), "testing");
  stream.str("");
  EXPECT_TRUE(hangman2.all_letters_known());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
