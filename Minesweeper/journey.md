## <p align="center">My Journey With Minesweeper</p>



**3rd August 2021**
- First and foremost, I read the [Minesweeper problem](https://ankitkeshavdbg.github.io/MineSweeper/).
- Initially I was confused, as I thought I had to develop the game, but soon found out that the provided problem focused on developing the mine field by taking input from user in the form of coordinates of the mine.
- I decided to merge both the ideas, so there will be a part that will create the mine field by taking input from the user, & the other part will generate the mine field randomly, & then the user can play the game.
- I was still bit confused about how the cells open up/reveal, as because many a times I saw that multiple cells open with a single click, wheras at other times it was just one per click.
- This from [Coding Ninjas](https://www.codingninjas.com/codestudio/problems/minesweeper_1376421) solved the doubt. 
```
If the revealed cell is empty ('.') with no neighbouring mines revealed, then change it to revealed blank ('_'), 
and all of its neighbouring unrevealed cells should be revealed recursively.
```
- I thought of showing the (position of the) cells as 0, 1, 2, ..., 62, 63, 64, ... kinda like that, instead of the 2D coordinate system, so that the user can easily provide which cell (s)he wants to select in input with a single integer.
- How to make the first move always safe?
- What about multiple difficulty levels?

**6th August 2021**
- I found this article on [GeeksforGeeks](https://www.geeksforgeeks.org/cpp-implementation-minesweeper-game/) which pretty much synced with my idea.
- I refined my ideas pretty quick.
  - There will be two kinds of gameplay : single player (mine field will be generated randomly) & multiplayer (mine field will be created by taking input from the user).
  - There will be three difficulty levels : Beginner, Intermediate & Advanced.
  - The unrevealed cells will be shown using `-` & the revealed cells will be shown using integers, which will denote the number of mines in adjacent cells. User may use flags to mark cells containing mines, & the number of flags available will be equal to the number of the mines. Flags will be shown using `F` in the mine field.
  - At the end of the game, mines will be revealed and shown using `*`.
  - 2D coordinate system will be followed, as showing both the position of the cell & the number of mines in integer format won't be possoble together.
  - Input format will be like this : `D x y` or `F x y`, where D = dig cell, F = flag cell, x & y are the x-coordinates & y-coordinates respectively.
  - First move can be made safe in single player (the proper way is yet to be figured out), but it can't be done in case of multiplayer, as we can neither change the mine field as set by one of the two players, nor give any hint to the other.
  - In case of multiplayer, I will print around 1000 lines of `Making Mine Field`, in order to hide the input of the first player who was placing the mines.

**7th August 2021**
- I refined one of my ideas again. Since first move is always safe in a traditional Minesweeper game (as it's a logic based game, not a luck based one), so the same will be followed for multiplayer too. In case the second player chooses a cell containing a mine in the first go, then the position of the mine will be altered automatically, & will be placed in a random new location.
- This can be made better by taking one extra input from the first player, so that the mine can be placed in that extra position, if required.

**8th August 2021**
- Read more about [Minesweeper](https://itp.uni-frankfurt.de/~mwagner/teaching/C_WS17/projects/Minesweeper.pdf).

**11th August 2021**
- Started implementing the game.

**12th August 2021**
- Completed implementation and writing the code.
- Documented everything and published it in its parent folder.
