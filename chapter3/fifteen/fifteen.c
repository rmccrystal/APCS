// Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);

void greet(void);

void init(void);

void draw(void);

bool move(int tile);

bool won(void);

void swap(int *a, int *b);

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    init();

    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
        clear();

        // Draw the current state of the board
        draw();

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        int tile = get_int("Tile to move: ");

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        //usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    int counter = d * d - 1;
    // the number of tiles is odd we have to swap 1 and 2
    bool odd = counter % 2 == 1;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int value = counter;
            if (odd)
            {
                if (counter == 2)
                {
                    value = 1;
                } else if (counter == 1)
                {
                    value = 2;
                }
            }
            board[i][j] = value;
            counter--;
        }
    }
}

// Prints the board in its current state
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int val = board[i][j];
            if (val == 0)
            {
                printf("-");
            } else
            {
                printf("%i", val);
            }
            if (j < d - 1)
            {
                printf("\t|");
            }
        }
        printf("\n");
    }
}

// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
    // -1 is no index found
    int tile_index[2] = {-1, -1};
    int empty_index[2] = {-1, -1};

    // populate indexes
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                tile_index[0] = i;
                tile_index[1] = j;
            } else if (board[i][j] == 0)
            {
                empty_index[0] = i;
                empty_index[1] = j;
            }
        }
    }

    if (tile_index[0] == -1)
    {
        // could not find tile index
        return false;
    }
    if (empty_index[0] == -1)
    {
        // could not find empty index
        return false;
    }

    // check first index to see if the indexes are next to each other
    bool align1 = false;
    bool align2 = false;

    if (tile_index[0] == empty_index[0])
    {
        align1 = true;
    }
    if (tile_index[1] == empty_index[1])
    {
        align2 = true;
    }

    if (tile_index[0] - 1 >= 0 && tile_index[0] - 1 == empty_index[0])
    {
        align1 = true;
    } else if (tile_index[0] + 1 < d && tile_index[0] + 1 == empty_index[0])
    {
        align1 = true;
    } else if (tile_index[1] - 1 >= 0 && tile_index[1] - 1 == empty_index[1])
    {
        align2 = true;
    } else if (tile_index[1] + 1 < d && tile_index[1] + 1 == empty_index[1])
    {
        align2 = true;
    }

    bool valid = align1 && align2;

    if (valid)
    {
        swap(&board[tile_index[0]][tile_index[1]], &board[empty_index[0]][empty_index[1]]);
    }

    return valid;
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
    // basically generate a winning board on the fly and verify
    // the counter is equal to the actual position
    int counter = 1;
    int max = (d * d) - 1;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (counter > max)
            {
                return true;
            }
            int value = board[i][j];
            if (counter != value)
            {
                return false;
            }
            counter++;
        }
    }

    printf("we should not be here");
    return true;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
