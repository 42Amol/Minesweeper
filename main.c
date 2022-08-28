#include <stdio.h>
#include <stdlib.h>


const int HEIGHT = 10;
const int WIDTH = 10;
const int MINES = 15;

typedef struct {
    char symbol;
    short hidden;
} cell_t;


void generate_board(cell_t board[HEIGHT][WIDTH]);
void place_mine(cell_t board[HEIGHT][WIDTH], int x, int y);
void display_board(cell_t board[HEIGHT][WIDTH]);
void reveal_board(cell_t board[HEIGHT][WIDTH]);


int main()
{
    cell_t board[HEIGHT][WIDTH];
  
    generate_board(board);
    display_board(board);

    return 0;
}

//// GENERATION

/*
** Place mines on board and match surrounding cells
*/
void generate_board(cell_t board[HEIGHT][WIDTH])
{
    // empty board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
          board[i][j].symbol = '0';
          board[i][j].hidden = 1;
        }
    } 
}

void place_mine(cell_t board[HEIGHT][WIDTH], int x, int y)
{
    board[x][y].symbol = 'X';

    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (i != j || i != 0)
                increase_cell_value(board, x + i, y + j);
}

void increase_cell_value(cell_t board[HEIGHT][WIDTH], int x, int y)
{
    if (x >= 0 && y >= 0 && x < HEIGHT && y < WIDTH && cell_t[x][y].symbol != 'X')
        cell_t[x][y].symbol++;
}


//// DISPLAY

/*
** Print board in stdout following current cells state
*/
void display_board(cell_t board[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++) 
            printf(" %c", board[i][j].hidden == 0 ? board[i][j].symbol : '-');
        printf("\n");
    } 
}

/*
** Print board in stdout ignoring hidden cells
*/
void reveal_board(cell_t board[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++) 
            printf(" %c", board[i][j].symbol);
        printf("\n");
    } 
}
