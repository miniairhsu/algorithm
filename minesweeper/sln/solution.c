#include <minesweeper.h>

/**
 * @brief You have been provided a zero initialized Minesweeper board.
 * Populate the board with the requested number of mines at random locations
 * on the board. In addition for all locations that hold a mine, update the
 * mine count for its direct neighbors (up, down, left and right).
 * @param cells - the minesweeper board. Individual cells can be accessed via cells[r][c] notation
 * @param num_rows - number of rows in the board.
 * @param num_cols - number of columns in the board
 * @param num_mines - requested number of mines to be populated on the board
 */
void setup_board(cell_t** cells, uint32_t num_rows, uint32_t num_cols, uint32_t num_mines)
{
    int i = 0;
    int j = 0;
    time_t t;
    srand((unsigned)time(&t));
    while (i < num_mines) {
        printf("1\r\n");
        int row = rand() % (num_rows);
        int col = rand() % (num_cols);
        if(cells[row][col].is_mine != true) {
            cells[row][col].is_mine = true;
            i++;
        } 
    }

    for (i = 1; i < num_rows-1; i++) {
        for (j = 1; j < num_cols-1; j++) {
            int mineCount = 0;
            if(cells[i-1][j].is_mine == 1) {
                mineCount++;
            }
            if(cells[i+1][j].is_mine == 1) {
                mineCount++;
            }
            if(cells[i][j-1].is_mine == 1) {
                mineCount++;
            }
            if(cells[i][j+1].is_mine == 1) {
                mineCount++;
            }
            cells[i][j].mines_nearby = mineCount;
        }
    }

    for(j = 1; j < num_cols-1; j++) {
        if(cells[0][j+1].is_mine == 1) {
            cells[0][j].mines_nearby += 1 ;
        }
        if(cells[0][j-1].is_mine == 1) {
            cells[0][j].mines_nearby += 1 ;
        }
        if(cells[1][j].is_mine == 1) {
            cells[0][j].mines_nearby += 1 ;
        }
        if(cells[num_rows-1][j+1].is_mine == 1) {
            cells[num_rows-1][j].mines_nearby += 1 ;
        }
        if(cells[num_rows-1][j-1].is_mine == 1) {
            cells[num_rows-1][j].mines_nearby += 1 ;
        }
        if(cells[num_rows-2][j].is_mine == 1) {
            cells[num_rows-1][j].mines_nearby += 1 ;
        }
    }

    for(i = 1; i < num_rows-1; i++) {
        if(cells[i-1][0].is_mine == 1) {
            cells[i][0].mines_nearby += 1 ;
        }
        if(cells[i+1][0].is_mine == 1) {
            cells[i][0].mines_nearby += 1 ;
        }
        if(cells[i][1].is_mine == 1) {
            cells[i][0].mines_nearby += 1 ;
        }
        if(cells[i-1][num_cols-1].is_mine == 1) {
            cells[i][num_cols-1].mines_nearby += 1 ;
        }
        if(cells[i+1][num_cols-1].is_mine == 1) {
            cells[i][num_cols-1].mines_nearby += 1 ;
        }
        if(cells[i][num_cols-2].is_mine == 1) {
            cells[i][num_cols-1].mines_nearby += 1 ;
        }
    }

}
