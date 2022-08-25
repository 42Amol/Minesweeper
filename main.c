#include <stdio.h>


const int HEIGHT = 10;
const int WIDTH = 8;
const int MINES = 15;

struct Cell {
  char symbol;
  short hidden;
};


void intro() {
  printf("Welcome to Minesweeper!\n\n");
}

void init_board(struct Cell board[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      board[i][j].symbol = '-';
      board[i][j].hidden = 1;
    }
  } 
}


void print_board(struct Cell board[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf(" %s ", board[i][j].hidden == 0 ? board[i][j].symbol : '#');
    }
    printf("\n");
  } 
}

int main() {
  struct Cell board[HEIGHT][WIDTH];
  
  printf("board initialization ...\n");
  init_board(board);
  printf("board printing ...\n");
  print_board(board);

  return 0;
}
