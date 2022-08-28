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
void increase_cell_value(cell_t board[HEIGHT][WIDTH], int x, int y);
void display_board(cell_t board[HEIGHT][WIDTH]);
void reveal_board(cell_t board[HEIGHT][WIDTH]);


int main()
{
    cell_t board[HEIGHT][WIDTH];
  
    generate_board(board);
    reveal_board(board);

    return 0;
}

//// GENERATION

/*
** Fill board with randomly placed mines
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

    // random number generation (based on Floyd algorithm)
    // generate a set of `MINES` unique positive number < `SIZE`

    const int SIZE = HEIGHT * WIDTH;
    int i_m = 0;
    char is_used[SIZE];
    
    for (int i = 0; i < SIZE; i++)
        is_used[i] = 0;

    for (int i_s = SIZE - MINES; i_s < SIZE && i_m < MINES; ++i_s, ++i_m) {
        int r = rand() % i_s;

        if (is_used[r])
            r = i_s; // use 'i_s' instead of the generated number

        place_mine(board, r / HEIGHT, r % WIDTH);
        is_used[r] = 1;
    }
}

/*
** Place a mine at given coordinates (x vertical, y horizontal)
*/
void place_mine(cell_t board[HEIGHT][WIDTH], int x, int y)
{
    board[x][y].symbol = 'X';

    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            if (i != j || i != 0)
                increase_cell_value(board, x + i, y + j);
}

/*
** If an empty cell exists at given coordinates, increase its value
*/
void increase_cell_value(cell_t board[HEIGHT][WIDTH], int x, int y)
{
    if (x >= 0 && y >= 0 && x < HEIGHT && y < WIDTH && board[x][y].symbol != 'X')
        board[x][y].symbol++;
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
