#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <minesweeper.h>
#include <assert.h>

static std::string usage_string(char *name)
{
  std::stringstream strm;
  strm << "USAGE:\n\t" << name << " <BoardWidth> <BoardHeight> <NumMines>" << std::endl;
  strm << "\t Restrict BoardWidth & BoardHeight to 1000 X 1000";
  return strm.str();
}

static std::string to_string(cell_t **cells, uint32_t num_rows, uint32_t num_cols)
{
  std::stringstream strm;
  for (uint32_t r = 0; r < num_rows; r++) {
    for (uint32_t c = 0; c < num_cols; c++) {
      strm << "|";
      if (cells[r][c].is_mine) {
        strm << "X";
      } else if (cells[r][c].mines_nearby) {
        strm << cells[r][c].mines_nearby;
      } else {
        strm << "-";
      }
    }
    strm << "|\n";
  }
  return strm.str();
}

int main(int argc, char **argv)
{
  uint32_t board_width = 6;
  uint32_t board_height = 4;
  uint32_t num_mines = 3;

  if (argc == 4) {
    try {
      board_width = std::stol(argv[1]);
      board_height = std::stol(argv[2]);
      num_mines = std::stol(argv[3]);
      if(board_width > 1000) {
        board_width = 1000;
        std::cout << "Capping Board Width to 10000" << std::endl;
      }
      if(board_height > 10000) {
        board_height = 10000;
        std::cout << "capping Board height to 10000" << std::endl;
      }
    } catch (const std::exception& exp) {
      std::cout << "Bad Arguments\n" << usage_string(argv[0]) << std::endl;
      return 1;
    }
  } else if (argc > 1) {
    std::cout << "Bad Arguments\n" << usage_string(argv[0]) << std::endl;
    return 1;
  }
  cell_t **cells;
  cells = new cell_t *[board_height]{};
  assert(cells);
  for (uint32_t i = 0; i < board_height; i++) {
    cells[i] = new cell_t[board_width]{};
    assert(cells[i]);
  }

  setup_board(cells, board_height, board_width, num_mines);

  std::cout << "Board Dimensions: "
            << board_width << " X " << board_height
            << ", Mines: " << num_mines << std::endl;
  std::cout << to_string(cells, board_height, board_width) << std::endl;

  for (uint32_t i = 0; i < board_height; i++) {
    delete[] cells[i];
  }
  delete[] cells;
  return 0;
}
