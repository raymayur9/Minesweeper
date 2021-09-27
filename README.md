# <p align="center">Guide to Minesweeper</p>

### Basic Intro
Minesweeper is  generally a single-player (except here) puzzle video game. The objective of the game is to clear a square board containing hidden "mines" or bombs without detonating any of them, with help from clues about the number of neighbouring mines in each field. You can read the history and more from [Wikipedia](https://en.wikipedia.org/wiki/Minesweeper_(video_game)).

### Modes & Difficulty levels
- Single player - The mines are set randomly. You can win only when you reveal all the cells except those containing mine, else you lose. It has 3 difficulty levels. 
  - BEGINNER - 9x9 Mine field containing 10 mines.
  - INTERMEDIATE - 16x16 Mine field containing 40 mines.
  - ADVANCED - 24x24 Mine field with 99 mines.
- Multiplayer - Player 2 sets the mines manually. This mode supports only 9x9 Mine field containing 10 mines. Player 1 wins only when (s)he reveals all the cells except those containing mine, else player 2 wins.

### Rules
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


### Gameplay Screenshots
- **Single player mode** 

`Welcome Message and Help Guide` <br>
<img width="851" alt="Screenshot 2021-09-27 at 6 35 24 PM" src="https://user-images.githubusercontent.com/62625019/134918657-c015150c-d688-4fab-b087-0c70fc7b28bc.png">

`First move - Dig (3, 6) - reveals multiple cells` <br>
<img width="263" alt="Screenshot 2021-09-27 at 6 39 50 PM" src="https://user-images.githubusercontent.com/62625019/134922538-7316ce6c-c98d-4ec4-a55d-8fb321f4a364.png">

`Flagging a cell - Flag (1, 3)` <br>
<img width="281" alt="Screenshot 2021-09-27 at 6 42 21 PM" src="https://user-images.githubusercontent.com/62625019/134923591-0a812caf-d2cd-4b1d-950a-8250fd572ae0.png">
 
 `Digging a cell - Dig (1, 2)` <br>
 <img width="281" alt="Screenshot 2021-09-27 at 6 45 05 PM" src="https://user-images.githubusercontent.com/62625019/134924532-a7f080f3-5adf-4d38-be4c-64ec6bb4091c.png">

`Unflagging a cell - Unflag (1, 3)` <br>
<img width="281" alt="Screenshot 2021-09-27 at 6 45 18 PM" src="https://user-images.githubusercontent.com/62625019/134924714-57930b60-4976-4676-aafe-832258953976.png">

`Error message for invalid input` <br>
<img width="392" alt="Screenshot 2021-09-27 at 6 49 03 PM" src="https://user-images.githubusercontent.com/62625019/134925073-358363c5-f841-453e-ab81-785f1b6b5144.png">

`Winning state` <br>
<img width="288" alt="Screenshot 2021-09-27 at 6 51 54 PM" src="https://user-images.githubusercontent.com/62625019/134925130-0ceaa218-9b1d-4c6b-aaf6-80735b89ed83.png">

- **Multiplayer mode** 

`Help Guide and input from Player 2` <br>
<img width="993" alt="Screenshot 2021-09-27 at 6 55 51 PM" src="https://user-images.githubusercontent.com/62625019/134925371-4f888eac-60dc-4e8b-a3aa-2075793abcd4.png">

`Input from Player 1` <br>
<img width="332" alt="Screenshot 2021-09-27 at 6 57 15 PM" src="https://user-images.githubusercontent.com/62625019/134925633-f05899a0-4a78-4b48-9791-1614a4fc3da3.png">

`Losing state - revealing of mines - misplaced flags are marked with X` <br>
<img width="332" alt="Screenshot 2021-09-27 at 6 58 09 PM" src="https://user-images.githubusercontent.com/62625019/134925790-fa95e741-f4d0-4526-9f49-b59996ac3e33.png">

