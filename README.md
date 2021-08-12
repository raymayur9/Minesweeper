## <p align="center">Guide to Minesweeper</p>

**Basic Intro** <br>
Minesweeper is  generally a single-player (except here) puzzle video game. The objective of the game is to clear a square board containing hidden "mines" or bombs without detonating any of them, with help from clues about the number of neighbouring mines in each field. You can read the history and more from [Wikipedia](https://en.wikipedia.org/wiki/Minesweeper_(video_game)).

**Modes & Difficulty levels**
- Single player - The mines are set randomly. You can win only when you reveal all the cells except those containing mine, else you lose. It has 3 difficulty levels. 
  - BEGINNER - 9x9 Mine field containing 10 mines.
  - INTERMEDIATE - 16x16 Mine field containing 40 mines.
  - ADVANCED - 24x24 Mine field with 99 mines.
- Multiplayer - Player 2 sets the mines manually. This mode supports only 9x9 Mine field containing 10 mines. Player 1 wins only when (s)he reveals all the cells except those containing mine, else player 2 wins.

**Rules**
- The board is divided into cells, with some mines distributed in them.
- The number on a cell shows the number of mines adjacent to it.
- Using this information, you can determine cells that are safe, and cells that contain mines.
- You will have some flags (equal to the number of mines), which you can use to mark `F` the cells that might contain a mine.
- The row and column numbers will be mentioned on the left and upper side respectively to help you.
- Input format :
  - `D x y` - Dig the cell located at (x, y), provided the cell is not revealed yet and unflagged.
  - `F x y` - Flag the cell located at (x, y), provided the cell is not revealed yet.
  - `U x y` - Unflag the cell located at (x, y), provided the cell is flagged.
- The first cell revealed is always safe.
- For achieving this in multiplayer mode, player 2 needs to give 1 extra input, so that it can be used to replace the mine from the first dug cell to it (provided the first dug cell contains a mine) to make it safe.
- Input format is always mentioned in the game. Wrong input format may lead to termination of the game.

**In case of any issues, mark it here.**
