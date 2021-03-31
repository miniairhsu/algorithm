# MineSweeper game board initialization

You are to implement a function that is called by the Minesweeper game
engine to setup a MineSweeper board for play. The problem should take
no longer than an hour to complete so please make sure to have set aside at least an hour to dedicate yourself to the task.

## Some background on MineSweeper
[MineSweeper](https://en.wikipedia.org/wiki/Microsoft_Minesweeper) came with the early windows operating system and was quite popular during its time.

Its a single player game where the player is presented with a rectangular
board of cells where each cell is displayed "covered". The player is expected to reveal cells one by one making sure that they don't reveal a mine. As clues, if the player reveals a location that is adjacent to a mine, a number is displayed on the revealed cell, indicating that a mine is nearby. Cells that are adjacent to multiple mines, will have their counts reflect this.

## The Task
The function that you will implement is defined in [solution.c](sln/solution.c) and has the following signature

```c
void setup_board(cell_t** cells, uint32_t num_rows, uint32_t num_cols, uint32_t num_mines);
```

The function is called during game initialization. You are given a game board that is represented as a 2D array of `cell_t` objects and all its elements have been zero initialized.

```c
typedef struct
{
  bool is_mine;
  uint32_t mines_nearby;
}cell_t;
```

A Cell is just an encapsulation of the neighborhood mine count and a boolean which indicates if the cell contains a mine.

The dimensions of the board (`num_rows` and `num_cols`) along with the requested number of mines (`num_mines`) are provided as additional parameters.

Your implementation should place (set `is_mine` to `true` at the appropriate locations) the requested number of mines randomly on the board. In addition it should update the mine counts (`mines_nearby`) for locations that are adjacent to mines. For the purpose of this assignment every cell need only be concerned with its four neighbors directly above, below, to the left or to the right of the given cell.

You are expected to use standard C and the standard library only. The project is setup to use the C11 standard. Please feel free to use the internet to lookup documentation.

### BONUS !!! (Optional)
If you have time to spare, extend your solution to update the mine count for all eight corners around a given cell.

## Build and run
The project uses [cmake](https://cmake.org/). Please [install](https://cmake.org/download/) it if you haven't already done so on your system.

Navigate a terminal window to where you extracted this project archive
, eg.`~/Downloads/minesweeper`, and create a build folder (a folder where your executable will be built ) within and `cd` into it.

```bash
cd ~/Downloads/minesweeper
mkdir build
cd build
```

Invoke cmake to configure and generate the build files for your project
### MacOSX or Linux
```
cmake ..
```

on Mac you can generate an Xcode project if you wish to use the Xcode IDE
```
cmake -G "Xcode" ..
```

You can then open the project in Xcode and compile and run from there.

### Windows
You can use `minGW` and follow the steps above. Alternatively, if you have Visual Studio installed, you can have Cmake generate a visual studio project and build and execute the program in Visual Studio.

To do this, install the Cmake windows tools and use the Cmake GUI in windows, to configure the project and launch it in Visual Studio.

### Run on unix like command line
After you invoke cmake in the `build` directory, the build files will be generated and you can compile the project using
```bash
make
```

This will generate an executable called `mine_layout`.
`mine_layout` can be invoked either with no arguments or with 3 arguments.
The three arguments are
1. The width of the game board
2. The height of the game board
3. The requested number of mines.

If no arguments are supplied a board of size (6 X 4) is used as default with a requested mine count of 3.

```
./mine_layout
Board Dimensions: 6 X 4, Mines: 3
|-|1|1|X|1|-|
|1|X|1|2|-|-|
|-|1|1|X|1|-|
|-|-|-|1|-|-|
```

```
./mine_layout 10 10 10
Board Dimensions: 10 X 10, Mines: 10
|X|1|-|-|-|-|-|1|-|-|
|1|-|-|1|-|-|1|X|1|-|
|-|-|1|X|1|-|-|1|-|-|
|-|1|-|1|-|-|1|-|-|-|
|1|X|1|-|-|1|X|1|-|-|
|1|1|-|-|-|-|1|-|-|-|
|X|1|-|-|-|1|-|-|-|-|
|1|-|-|-|2|X|1|-|-|-|
|1|-|-|1|X|2|-|1|-|-|
|X|1|-|-|1|-|1|X|1|-|
```
# Submission
Please implement your solution in [solution.c](sln/solution.c). Make sure it builds and runs. Zip everything back up and then send the archive back to KeepTruckin.

