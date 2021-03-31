#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

typedef struct
{
  bool is_mine;
  uint32_t mines_nearby;
}cell_t;

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
void setup_board(cell_t** cells, uint32_t num_rows, uint32_t num_cols, uint32_t num_mines);

#ifdef __cplusplus
};
#endif
