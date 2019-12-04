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
  game2.toggleTurn();
  ASSERT_EQ(game2.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, switchSanity){
  TicTacToeBoard game3;
  ASSERT_NE(game3.toggleTurn(), Invalid);
}

TEST(TicTacToeBoardTest, placeFirstPeice){
	TicTacToeBoard game4;
	ASSERT_EQ(game4.placePiece(2,2), X);
}

TEST(TicTacToeBoardTest, placeSecondPeice){
	TicTacToeBoard game5;
	game5.placePiece(2,2);
	ASSERT_EQ(game5.placePiece(1,2), O);
}

TEST(TicTacToeBoardTest, placePeiceOnTop){
	TicTacToeBoard game6;
	game6.placePiece(2,2);
	ASSERT_EQ(game6.placePiece(2,2), X);
}

TEST(TicTacToeBoardTest, PlaceOutRow){
	TicTacToeBoard game7;
	ASSERT_EQ(game7.placePiece(4,2), Invalid);
}

TEST(TicTacToeBoardTest, PlaceOutCol){
	TicTacToeBoard game8;
	ASSERT_EQ(game8.placePiece(2,4), Invalid);
}

TEST(TicTacToeBoardTest, PlaceOutRowandCol){
	TicTacToeBoard game9;
	ASSERT_EQ(game9.placePiece(4,4), Invalid);
}

TEST(TicTacToeBoardTest, getNormalPiece){
	TicTacToeBoard game10;
	game10.placePiece(1,1);
	ASSERT_EQ(game10.getPiece(1,1), X);
}

TEST(TicTacToeBoardTest, getBlank){
	TicTacToeBoard game11;
	ASSERT_EQ(game11.getPiece(1,1), Blank);
}

TEST(TicTacToeBoardTest, getoutofboundsRow){
	TicTacToeBoard game12;
	ASSERT_EQ(game12.getPiece(4,1), Invalid);
}

TEST(TicTacToeBoardTest, getoutofboundsCol){
	TicTacToeBoard game13;
	ASSERT_EQ(game13.getPiece(1,4), Invalid);
}

TEST(TicTacToeBoardTest, getoutofboundsRowandCol){
	TicTacToeBoard game14;
	ASSERT_EQ(game14.getPiece(4,4), Invalid);
}

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
