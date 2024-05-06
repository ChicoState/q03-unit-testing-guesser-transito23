/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, checks_if_matches) {
	Guesser guess("secret");
	bool match = guess.match("secret");
	ASSERT_EQ(true, match);
}

TEST(GuesserTest, checks_if_no_match) {
	Guesser guess("secret");
	bool match = guess.match("seCret");
	ASSERT_EQ(false, match);
}

TEST(GuesserTest, checks_if_no_match_and_remaining_2) {
	Guesser guess("secret");
	bool match = guess.match("seCret");
	unsigned int num = guess.remaining();
	ASSERT_EQ(false, match);
	ASSERT_EQ(2, num);
}

TEST(GuesserTest, checks_if_no_match_and_remaining_1) {
	Guesser guess("secret");
	bool match = guess.match("seCret");
	unsigned int num = guess.remaining();
	bool second_match = guess.match("secret9");
	unsigned int sec_num = guess.remaining();
	ASSERT_EQ(false, second_match);
	ASSERT_EQ(1, sec_num);
}

TEST(GuesserTest, checks_if_no_match_and_remaining_0) {
	Guesser guess("secret");
	bool match = guess.match("seCret");
	unsigned int num = guess.remaining();
	bool second_match = guess.match("secret9");
	unsigned int sec_num = guess.remaining();
	bool third_match = guess.match("secret10");
	unsigned int thir_num = guess.remaining();
	ASSERT_EQ(false, third_match);
	ASSERT_EQ(0, thir_num);
}

TEST(GuesserTest, checks_if_match_and_remaining_0) {
	Guesser guess("secret");
	bool match = guess.match("seCret");
	unsigned int num = guess.remaining();
	bool second_match = guess.match("secret9");
	unsigned int sec_num = guess.remaining();
	bool third_match = guess.match("secret10");
	unsigned int thir_num = guess.remaining();
	bool fourth_match = guess.match("secret");
	unsigned int fourth_num = guess.remaining();
	ASSERT_EQ(false, fourth_match);
	ASSERT_EQ(0, fourth_num);
}

TEST(GuesserTest, checks_if_resets_guess) {
	Guesser guess("secret");
	bool match = guess.match("seCret");
	// num should be set to 2 here
	unsigned int num = guess.remaining();
	bool sec_match = guess.match("secret");
	unsigned int num2 = guess.remaining();
	ASSERT_EQ(true, sec_match);
	ASSERT_EQ(3, num2);
}

TEST(GuesserTest, checks_for_32_chars) {
	Guesser guess("abcdefghijklmnopqrstuvwxyz1234567890");
	unsigned int num = guess.remaining();
	ASSERT_EQ(3, num);
	// this should be true because the 32 char cap
	bool match = guess.match("abcdefghijklmnopqrstuvwxyz123456");
	ASSERT_EQ(true, match);
}

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/