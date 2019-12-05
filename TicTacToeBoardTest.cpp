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

TEST(TicTacToeBoardTest, notOver){
	TicTacToeBoard game15;
	ASSERT_EQ(game15.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, catsGame){
	TicTacToeBoard game16;
	game16.placePiece(0,0);//top row x
	game16.placePiece(0,2);//''' o
	game16.placePiece(0,1);//''' x
	game16.placePiece(1,0);// o
	game16.placePiece(1,1); //x
	game16.placePiece(2,0);//o
	game16.placePiece(1,2);// x
	game16.placePiece(2,1); //o
	game16.placePiece(2,2);
	ASSERT_EQ(game16.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, topwinX){
	TicTacToeBoard game17;
	game17.placePiece(0,0);
	game17.placePiece(2,2);
	game17.placePiece(0,1);
	game17.placePiece(2,2);
	game17.placePiece(0,2);

	ASSERT_EQ(game17.getWinner(), X);
}

TEST(TicTacToeBoardTest, middlewinX){
	TicTacToeBoard game18;
	game18.placePiece(1,0);
	game18.placePiece(2,2);
	game18.placePiece(1,1);
	game18.placePiece(2,2);
	game18.placePiece(1,2);
	ASSERT_EQ(game18.getWinner(), X);
}

TEST(TicTacToeBoardTest, botWIn){
	TicTacToeBoard game19;
	game19.placePiece(2,0);
	game19.placePiece(0,0);
	game19.placePiece(2,1);
	game19.placePiece(0,0);
	game19.placePiece(2,2);
	ASSERT_EQ(game19.getWinner(), X);
}

TEST(TicTacToeBoardTest, leftVert){
	TicTacToeBoard game20;
	game20.placePiece(0,0);
	game20.placePiece(2,2);
	game20.placePiece(1,0);
	game20.placePiece(2,2);
	game20.placePiece(2,0);
	ASSERT_EQ(game20.getWinner(), X);
}

TEST(TicTacToeBoardTest, midVert){
	TicTacToeBoard game21;
	game21.placePiece(0,1);
	game21.placePiece(0,0);
	game21.placePiece(1,1);
	game21.placePiece(0,0);
	game21.placePiece(2,1);
	ASSERT_EQ(game21.getWinner(), X);
}

TEST(TicTacToeBoardTest, rightVert){
	TicTacToeBoard game22;
	game22.placePiece(0,2);
	game22.placePiece(0,0);
	game22.placePiece(1,2);
	game22.placePiece(0,0);
	game22.placePiece(2,2);
	ASSERT_EQ(game22.getWinner(), X);
}

TEST(TicTacToeBoardTest, topLeftDiag){
	TicTacToeBoard game23;
	game23.placePiece(0,0);
	game23.placePiece(0,1);
	game23.placePiece(1,1);
	game23.placePiece(0,1);
	game23.placePiece(2,2);
	ASSERT_EQ(game23.getWinner(), X);
}

TEST(TicTacToeBoardTest, topRightDiag){
	TicTacToeBoard game24;
	game24.placePiece(0,2);
	game24.placePiece(0,1);
	game24.placePiece(1,1);
	game24.placePiece(0,1);
	game24.placePiece(2,0);
	ASSERT_EQ(game24.getWinner(), X);
}

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
