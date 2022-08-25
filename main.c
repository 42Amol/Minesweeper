#include <stdio.h>


const int HEIGHT = 10;
const int WIDTH = 8;
const int MINES = 15;


void intro()
{
  printf("Welcome to Minesweeper!\n\n");
}

void init_board(int board[HEIGHT][WIDTH])
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      board[i][j] = 0;
    }
  } 
}


void print_board(int board[HEIGHT][WIDTH])
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      printf(" %d ", board[i][j]);
    }
    printf("\n");
  } 
}

int main() {
  int board[HEIGHT][WIDTH];

  init_board(board);
  print_board(board);

  return 0;
}
