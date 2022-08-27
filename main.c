#include <stdio.h>


const int HEIGHT = 10;
const int WIDTH = 10;
const int MINES = 15;

typedef struct {
    char symbol;
    short hidden;
} cell_t;


void init_board(cell_t board[HEIGHT][WIDTH]);
void display_board(cell_t board[HEIGHT][WIDTH]);
void reveal_board(cell_t board[HEIGHT][WIDTH]);


int main()
{
    cell_t board[HEIGHT][WIDTH];
  
    init_board(board);
    display_board(board);

    return 0;
}


void init_board(cell_t board[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
          board[i][j].symbol = '0';
          board[i][j].hidden = 1;
        }
    } 
}

void display_board(cell_t board[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++) 
            printf(" %c", board[i][j].hidden == 0 ? board[i][j].symbol : '-');
        printf("\n");
    } 
}

void reveal_board(cell_t board[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++) 
            printf(" %c", board[i][j].symbol);
        printf("\n");
    } 
}
