#include <stdio.h>


const int HEIGHT = 10;
const int WIDTH = 10;
const int MINES = 15;

typedef struct Cell {
  char symbol;
  short hidden;
} cell;


void intro();
void init_board(cell board[HEIGHT][WIDTH]);
void print_board(cell board[HEIGHT][WIDTH]);

int main() {
  cell board[HEIGHT][WIDTH];
  
  printf("board initialization ...\n");
  init_board(board);
  printf("board printing ...\n");
  print_board(board);

  return 0;
}


void intro() {
  printf("Welcome to Minesweeper!\n\n");
}

void init_board(cell board[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      board[i][j].symbol = '-';
      board[i][j].hidden = 1;
    }
  } 
}

void print_board(cell board[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) 
      printf(" %c", board[i][j].hidden == 0 ? board[i][j].symbol : '#');
    printf("\n");
  } 
}
