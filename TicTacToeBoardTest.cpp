/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
using namespace std;
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, checkWinner)
{
  TicTacToeBoard TTT;
  bool check=false;
  if(TTT.getWinner() == X || TTT.getWinner() == O)
  {
    check=true;
  }
  ASSERT_FALSE(check);
}
TEST(TicTacToeBoardTest, checkWinnerBlank)
{
  TicTacToeBoard TTT;
  bool check=false;
  if(TTT.getWinner() == Invalid)
    check=true;
  ASSERT_TRUE(check);
}
TEST(TicTacToeBoardTest, checknoWinner)
{
  TicTacToeBoard TTT;
  TTT.placePiece(0,0);
  TTT.placePiece(0,1);
  TTT.placePiece(0,2);
  TTT.placePiece(1,0);
  TTT.placePiece(2,0);
  TTT.placePiece(1,1);
  TTT.placePiece(2,1);
  TTT.placePiece(2,2);
  TTT.placePiece(1,2);
  ASSERT_TRUE(TTT.getWinner()==Blank);
}
TEST(TicTacToeBoardTest, checkWinnerdiagonalreverse)
{
  TicTacToeBoard TTT;
  bool check=false;
  TTT.placePiece(0,0);
  TTT.placePiece(1,0);
  TTT.placePiece(1,1);
  TTT.placePiece(2,0);
  TTT.placePiece(2,2);
  if(TTT.getWinner() == X)
    check=true;
  ASSERT_TRUE(check);
}

TEST(TicTacToeBoardTest, checkWinnerdiagonalforward)
{
  TicTacToeBoard TTT;
  bool check=false;
  TTT.placePiece(2,0);
  TTT.placePiece(1,0);
  TTT.placePiece(1,1);
  TTT.placePiece(0,0);
  TTT.placePiece(0,2);
  if(TTT.getWinner() == X)
    check=true;
  ASSERT_TRUE(check);
}
TEST(TicTacToeBoardTest, checkWinnerrowwise)
{
  TicTacToeBoard TTT;
  bool check=false;
  TTT.placePiece(0,0);
  TTT.placePiece(1,0);
  TTT.placePiece(0,1);
  TTT.placePiece(1,1);
  TTT.placePiece(0,2);
  if(TTT.getWinner() == X)
    check=true;
  ASSERT_TRUE(check);
}

TEST(TicTacToeBoardTest, checkWinnercolumnwise)
{
  TicTacToeBoard TTT;
  bool check=false;
  TTT.placePiece(0,0);
  TTT.placePiece(0,1);
  TTT.placePiece(1,0);
  TTT.placePiece(1,1);
  TTT.placePiece(2,0);
  if(TTT.getWinner() == X)
    check=true;
  ASSERT_TRUE(check);
}
TEST(TicTacToeBoardTest, checkClearBoard)
{ 
  TicTacToeBoard TTT;
  bool check=true;
  TTT.clearBoard();
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if(TTT.getPiece(i,j)!=' ') {
        check=false;
      }    
    }
  }
  ASSERT_TRUE(check);
}

TEST(TicTacToeBoardTest, checkPlacePiece) {
  TicTacToeBoard TTT;
  bool check=false;
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if(TTT.placePiece(i,j)== 'X' || TTT.placePiece(i,j)=='O' || TTT.placePiece(i,j)==' ')
      {
        check=true;
      }
    }
  }
  ASSERT_TRUE(check);
}

TEST(TicTacToeBoardTest, placePieceExistValue) {
  TicTacToeBoard TTT;
  
  TTT.placePiece(0,0);
 // std::cout<<TTT.placePiece(0,0)<<std::endl;
  ASSERT_TRUE(TTT.placePiece(0,0)==X);
}


TEST(TicTacToeBoardTest, placePieceInvalidrow)
{
   TicTacToeBoard TTT;
	ASSERT_TRUE(TTT.placePiece(-1,-2)==Invalid);
}
