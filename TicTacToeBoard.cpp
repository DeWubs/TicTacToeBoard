#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X){
    turn = O;
    return O;
  }
  else if(turn == O){
    turn = X;
    return X;
  }
  else
    return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location.
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row > BOARDSIZE || column > BOARDSIZE)
    return Invalid;
  if(board[row][column] == Blank){
    if(turn == X){
      board[row][column] = X;
      toggleTurn();
      return X;
    }
    else{
      board[row][column] = O;
      toggleTurn();
      return O;
    }
  }
  else{
    return board[row][column];
  }

}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row > BOARDSIZE || column > BOARDSIZE)
    return Invalid;
  if(board[row][column] == Blank)
    return Blank;
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  //check top row
  if(board[0][0] == board[0][1] && board[0][1] == board[0][2]){
    if(board[0][0] != Blank)
      return board[0][0];
    return Invalid;
  }
  //check middle row
  else if(board[1][0] == board[1][1] && board[1][1] == board[1][2]){
    if(board[1][0] != Blank)
      return board[1][0];
    return Invalid;
  }
  //check bottom row
  else if(board[2][0] == board[2][1] && board[2][1] == board[2][2]){
    if(board[2][0] != Blank)
      return board[2][0];
    return Invalid;
  }
  //check left vertical
  else if(board[0][0] == board[1][0] && board[1][0] == board[2][0]){
    if(board[0][0] != Blank)
      return board[0][0];
    return Invalid;
  }
  //check middle vertical
  else if(board[0][1] == board[1][1] && board[1][1] == board[2][1]){
    if(board[0][1] != Blank)
      return board[0][1];
    return Invalid;
  }
  //check right vertical
  else if(board[0][2] == board[1][2] && board[1][2] == board[2][2]){
    if(board[0][2] != Blank)
      return board[0][2];
    return Invalid;
  }
  //check topLeft diag
  else if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
    if(board[0][0] != Blank)
      return board[0][0];
    return Invalid;
  }
  //check top right diag
  else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
    if(board[0][2] != Blank)
      return board[0][2];
    return Invalid;
  }
  // else{
  //   for(int i = 0; i < BOARDSIZE; i++){
  //     for(int j = 0; j < BOARDSIZE; j++){
  //       if(board[i][j] == Blank)
  //         return Invalid;
  //     }
  //   }
  // }
  return Blank;
}
