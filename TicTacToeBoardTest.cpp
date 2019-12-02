/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(TicTacToeBoardTest, switchFromX){
  TicTacToeBoard game1;
  ASSERT_EQ(game1.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, switchFromO){
  TicTacToeBoard game2;
  ASSERT_EQ(game2.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, switchSanity){
  TicTacToeBoard game3;
  ASSERT_NE(game3.toggleTurn(), Invalid);
}
/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
