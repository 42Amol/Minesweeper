#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Clear console screen on windows and linux
#ifdef _WIN32
    #include <conio.h> // on windows, use clrsrc() from conio lib
#else
    #define clrscr() printf("\e[1;1H\e[2J") // on linux, use ASCII escape codes
#endif


const int HEIGHT = 10;
const int WIDTH = 10;
const int SIZE = HEIGHT * WIDTH;
const int MINES = 15;

typedef struct {
    char symbol;
    short hidden;
} cell_t;


void generate_board(cell_t board[HEIGHT][WIDTH]);
void place_mine(cell_t board[HEIGHT][WIDTH], int x, int y);
void increase_cell_value(cell_t board[HEIGHT][WIDTH], int x, int y);
int play(cell_t board[HEIGHT][WIDTH]);
int get_x();
int get_y();
int replay();
void display_board(cell_t board[HEIGHT][WIDTH]);
void reveal_board(cell_t board[HEIGHT][WIDTH]);


int main()
{
    cell_t board[HEIGHT][WIDTH];

    do
    {
        generate_board(board);

        int result = play(board);
        clrscr();
        result == 0
          ? printf("Congratulations! You won!\n\n")
          : printf("You lost...\n\n");
        reveal_board(board); 
    } while (replay() == 1); 

    return 0;
}

//// GENERATION

/*
** Generate initial board with every cell hidden and mines placed
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

    // random number generation (based on Floyd algorithme)
    // generate a set of `MINES` unique positive number < `SIZE`
    int i_m = 0;
    char is_used[SIZE];

    srand(time(NULL));
    
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


//// GAME

/*
** Manage game actions
** Return 0 if won, 1 if lost
*/
int play(cell_t board[HEIGHT][WIDTH])
{
    int to_dig = SIZE - MINES;

    while (1)
    {
        clrscr();
        display_board(board);

        int x = get_x();
        int y = get_y();
        cell_t *target = &board[x][y];

        if (target->symbol == 'X')
            return 1; // mine dug => lose

        if (target->hidden == 0)
            printf("You already dug this cell");
        else
        {
            target->hidden = 0; // mark as dug
            if (--to_dig == 0)
                return 0; // all blank cells have been dug
        }
    }
}

int get_x()
{
    int x = -1;
    while (x < 0 || x >= HEIGHT)
    {
        printf("Please give vertical coordinate:\n");
        scanf("%d", &x);
    }
    return x;
}

int get_y()
{
    int y = -1;
    while (y < 0 || y >= WIDTH)
    {
        printf("Please give horizontal coordinate:\n");
        scanf("%d", &y);
    }
    return y;
}

int replay()
{
    char ans;
    while (1)
    {
        printf("Play again? (y/n): ");
        scanf("%c", &ans);

        if (ans == 'y' || ans == 'Y')
          return 1;
        if (ans == 'n' || ans == 'N')
          return 0;
    }
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
