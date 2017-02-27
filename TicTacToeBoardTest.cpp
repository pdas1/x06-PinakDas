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

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, checkWinner)
{
  TicTacToeBoard TTT;
  bool check;
  if(TTT.getWinner() == X || TTT.getWinner() == O)
  {
    check=true;
  }
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
