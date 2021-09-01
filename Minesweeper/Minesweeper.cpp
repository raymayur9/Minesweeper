// Project : Minesweeper game (having three difficulty levels & two playing modes)
// Author : Mayur Ray
// GitHub Profile : https://github.com/raymayur9

// ************************** NOTE **************************
// In this project, input is taken mostly in the form of strings, so as to avoid termination of program in case of unexpected input type as much as possible.

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// struct inputType is used for taking input for digging, flagging or ungflagging cells. type denotes what operation to perform, x & y are the cartesian coordinates.
struct inputType
{
    string type;
    string x;
    string y;
};

// ------------------------------------------------------------------------ FUNCTION PROTOTYPES --------------------------------------------------------------------------------
int modeFunction();
void singlePlayerFunction();
void multiPlayerFunction();
int difficultyLevelFunction();
int boardSizeFunction(int difficulty, int &noOfMines);
void helpGuideFunction(int boardSize, int numOfMines);
vector<vector<char> > myBoardFunction(int difficulty);
vector<vector<char> > realBoardFunction(int boardSize, int noOfMines, int &countDigs, vector<vector<char> > &myBoard);
vector<vector<char> > manualBoardFunction(int boardSize, int numOfMines, int &countDigs, vector<vector<char> > &myBoard, string &name1, string &name2);
void updateBoardFunction(vector<vector<char> > &myBoard, vector<vector<char> > &realBoard, int boardSize, int &countDigs, string type, int x, int y);
void printBoardFunction(vector<vector<char> > &board);
void IO_Function(vector<vector<char> > &myBoard, vector<vector<char> > &realBoard, int boardSize, int flag, int numOfMines, int &countDigs, string &name, string name2 = "");
inputType inputConstraintFunction(vector<vector<char> > &myBoard, int boardSize, int flag);
void lostBoardFunction(vector<vector<char> > &myBoard, vector<vector<char> > &realBoard, int boardSize, string name, string name2 = "");
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// This function is used to select between single player & multiplayer modes
int modeFunction()
{
    cout << "\nYou have two modes :\n"
         << "Single player mode : The Mine field will be generated randomly.\n"
         << "Multiplayer mode : Player 2 will set the positions of the mines manually, while player 1 will play the game as usual.\n";
    cout << "\nPlease select the mode :\n"
         << "Enter 1 for single player\n"
         << "Enter 2 for multiplayer\n"
         << ": ";

    string mode;
    getline(cin, mode);

    if (mode == "1")
    {
        return 1;
    }
    else if (mode == "2")
    {
        return 2;
    }
    else
    {
        cout << "Wrong input! Please try again.\n";
        return modeFunction();
    }
}

// For single player mode, this function will take control of all the things
void singlePlayerFunction()
{
    cout << "\nEnter your username : ";
    string name;
    getline(cin, name);

    //difficulty will store the difficulty selected by the player
    int difficulty = difficultyLevelFunction();

    //numOfMines will store the number of mines in the Mine field based on the difficulty, boardSize will store the length (or breadth) of the Mine field.
    int numOfMines;
    int boardSize = boardSizeFunction(difficulty, numOfMines);

    helpGuideFunction(boardSize, numOfMines);

    //myBoard is the board that will be shown to the user everytime
    vector<vector<char> > myBoard = myBoardFunction(boardSize);
    printBoardFunction(myBoard);

    //countDigs will store the count of cells dug by the player
    int countDigs = 0;

    //realBoard is the board that will contain the mines & the values of each cell, it will never be shown to the user
    vector<vector<char> > realBoard = realBoardFunction(boardSize, numOfMines, countDigs, myBoard);
    IO_Function(myBoard, realBoard, boardSize, numOfMines, numOfMines, countDigs, name);
}

// For multiplayer mode, this function will take control of all the things
void multiPlayerFunction()
{
    cout << "\nEnter player 1's username : ";
    string name1;
    getline(cin, name1);
    cout << "Enter player 2's username : ";
    string name2;
    getline(cin, name2);

    //difficulty is set to 1, so that 9x9 Mine field containing 10 mines is always selected for multiplayer mode
    int difficulty = 1;

    //numOfMines will store the number of mines in the Mine field based on the difficulty, boardSize will store the length (or breadth) of the Mine field.
    int numOfMines;
    int boardSize = boardSizeFunction(difficulty, numOfMines);

    helpGuideFunction(boardSize, numOfMines);

    //myBoard is the board that will be shown to the user everytime
    vector<vector<char> > myBoard = myBoardFunction(boardSize);

    //countDigs will store the count of cells dug by the player
    int countDigs = 0;

    //realBoard is the board that will contain the mines & the values of each cell, it will never be shown to the user
    vector<vector<char> > realBoard = manualBoardFunction(boardSize, numOfMines, countDigs, myBoard, name1, name2);
    IO_Function(myBoard, realBoard, boardSize, numOfMines, numOfMines, countDigs, name1, name2);
}

// This function is used to select the difficulty level for single player mode
int difficultyLevelFunction()
{
    cout << "\nSelect difficulty :\n"
         << "Enter 1 for BEGINNER (9x9 board & 10 mines)\n"
         << "Enter 2 for INTERMEDIATE (16x16 board & 40 mines)\n"
         << "Enter 3 for ADVANCED (24x24 board & 99 mines)\n"
         << ": ";

    string difficulty;
    getline(cin, difficulty);

    if (difficulty == "1")
    {
        return 1;
    }
    else if (difficulty == "2")
    {
        return 2;
    }
    else if (difficulty == "3")
    {
        return 3;
    }
    else
    {
        cout << "Wrong input! Please try again.\n";
        return difficultyLevelFunction();
    }
}

// This function is used to set the board size and number of mines
int boardSizeFunction(int difficulty, int &numOfMines)
{
    int size;
    switch (difficulty)
    {
    case 1: //BEGINNER
        size = 9;
        numOfMines = 10;
        break;
    case 2: //INTERMEDIATE
        size = 16;
        numOfMines = 40;
        break;
    case 3: //ADVANCED
        size = 24;
        numOfMines = 99;
        break;
    default:
        break;
    }
    return size;
}

// This will show the help guide to the players
void helpGuideFunction(int boardSize, int numOfMines)
{
    cout << "\nHelp Guide :\n"
         << "You will be given a " << boardSize << "x" << boardSize << " Mine field, containing " << numOfMines << " mines.\n"
         << "You will have " << numOfMines << " flags, which you can use to mark the cells that might contain a mine.\n"
         << "The row and column numbers will be mentioned on the left and upper side respectively to help you.\n"
         << "Input format : \n"
         << "D x y - Dig the cell located at (x, y), provided the cell is not revealed yet and unflagged.\n"
         << "F x y - Flag the cell located at (x, y), provided the cell is not revealed yet.\n"
         << "U x y - Unflag the cell located at (x, y), provided the cell is flagged.\n";
}

// This creates the initial myBoard
vector<vector<char> > myBoardFunction(int boardSize)
{
    vector<vector<char> > myBoard(boardSize, vector<char>(boardSize, '-'));
    return myBoard;
}

// This takes the first input from player, creates the realBoard randommly & updates the myBoard accordingly
vector<vector<char> > realBoardFunction(int boardSize, int numOfMines, int &countDigs, vector<vector<char> > &myBoard)
{
    cout << "Enter coordinates (D x y) : ";
    inputType input;
    cin >> input.type >> input.x >> input.y;

    //Checking whether the command is correct or not and the provided input is inside board or not
    while (input.type != "D" || stoi(input.x) < 0 || stoi(input.x) >= boardSize || stoi(input.y) < 0 || stoi(input.y) >= boardSize)
    {
        if (input.type != "D")
        {
            cout << "\"" << input.type << "\" is not a valid command. Please try again.\n\n";
        }
        else if (stoi(input.x) < 0 || stoi(input.x) >= boardSize || stoi(input.y) < 0 || stoi(input.y) >= boardSize)
        {
            cout << "(" << stoi(input.x) << ", " << stoi(input.y) << ") lies out of the mine field. Please try again.\n\n";
        }
        cout << "Enter coordinates (D x y) : ";
        cin >> input.type >> input.x >> input.y;
    }

    vector<vector<char> > realBoard(boardSize, vector<char>(boardSize, '-'));
    realBoard[stoi(input.x)][stoi(input.y)] = '?';

    //Assigns mines to the cells randomly, while ensuring that there's no repition & the first cell dug by the player & all the cells adjacent to it are safe
    while (numOfMines)
    {
        int xMine = rand() % boardSize;
        int yMine = rand() % boardSize;
        if (abs(xMine - stoi(input.x)) > 1 && abs(yMine - stoi(input.y)) > 1 && realBoard[xMine][yMine] == '-')
        {
            realBoard[xMine][yMine] = '*';
            numOfMines--;
        }
    }

    //Counting the number of adjacent mines for each cell & assigning the value to the realBoard
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (realBoard[i][j] != '*')
            {
                int count = 0;
                //checking the top left corner for mine
                if (i != 0 && j != 0 && realBoard[i - 1][j - 1] == '*')
                {
                    count++;
                }
                //checking the top right corner for mine
                if (i != 0 && j != boardSize - 1 && realBoard[i - 1][j + 1] == '*')
                {
                    count++;
                }
                //checking the bottom left corner for mine
                if (i != boardSize - 1 && j != 0 && realBoard[i + 1][j - 1] == '*')
                {
                    count++;
                }
                //checking the bottom right corner for mine
                if (i != boardSize - 1 && j != boardSize - 1 && realBoard[i + 1][j + 1] == '*')
                {
                    count++;
                }
                //checking left for mine
                if (i != 0 && realBoard[i - 1][j] == '*')
                {
                    count++;
                }
                //checking right for mine
                if (i != boardSize - 1 && realBoard[i + 1][j] == '*')
                {
                    count++;
                }
                //checking up for mine
                if (j != 0 && realBoard[i][j - 1] == '*')
                {
                    count++;
                }
                //checking down for mine
                if (j != boardSize - 1 && realBoard[i][j + 1] == '*')
                {
                    count++;
                }
                realBoard[i][j] = '0' + count;
            }
        }
    }

    //updates myBoard based on the first dug cell and the realBoard
    updateBoardFunction(myBoard, realBoard, boardSize, countDigs, input.type, stoi(input.x), stoi(input.y));
    return realBoard;
}

// This takes the position of mines from player 2 manually, takes the first input from player 1, creates the realBoard & updates the myBoard accordingly
vector<vector<char> > manualBoardFunction(int boardSize, int numOfMines, int &countDigs, vector<vector<char> > &myBoard, string &name1, string &name2)
{
    //A copy is made so that we have the original value for using later
    int numOfMinesCopy = numOfMines;

    //Copy is incremented by 1 as we need 1 extra input than the number of mines
    numOfMinesCopy++;

    //vector manualInput will store the input provided by player 2. manualInputX & manualInputY act as temporary variables for taking input.
    vector<pair<int, int> > manualInput;
    string manualInputX, manualInputY;
    cout << "\n"
         << name2 << ", you have to provide " << numOfMinesCopy << " pairs of coordinates for placing mines (1 extra so as to avoid losing of game in the first turn of " << name1 << ").\n";

    //Taking the input from player 2
    while (numOfMinesCopy)
    {
        cout << "Enter coordinates (x y) : ";
        cin >> manualInputX >> manualInputY;

        //Checking whether the provided input is inside board or not
        if (stoi(manualInputX) < 0 || stoi(manualInputX) >= boardSize || stoi(manualInputY) < 0 || stoi(manualInputY) >= boardSize)
        {
            cout << "(" << stoi(manualInputX) << ", " << stoi(manualInputY) << ") lies out of the mine field. Please try again.\n";
        }
        else if (1)
        {
            //Checking whether duplicate of input exist or not
            bool check = true;
            for (int i = 0; i < manualInput.size(); i++)
            {
                if (manualInput[i].first == stoi(manualInputX) && manualInput[i].second == stoi(manualInputY))
                {
                    check = false;
                    cout << "You have already entered (" << stoi(manualInputX) << ", " << stoi(manualInputY) << ") earlier. Please try again.\n";
                    break;
                }
            }
            //If no duplicate is found, we push the new coordinates
            if (check)
            {
                manualInput.push_back(make_pair(stoi(manualInputX), stoi(manualInputY)));
                numOfMinesCopy--;
            }
        }
    }

    //The following statement is printed 1000 times so that player 1 can't see player 2's input
    for (int i = 0; i < 1000; i++)
    {
        cout << "Preparing Mine field...\n";
    }

    cout << "\n"
         << name1 << ", it's your turn!\n";
    printBoardFunction(myBoard);

    //First input from player 1
    cout << "Enter coordinates (D x y) : ";
    inputType input;
    cin >> input.type >> input.x >> input.y;

    //Checking whether the command is correct or not and the provided input is inside board or not
    while (input.type != "D" || stoi(input.x) < 0 || stoi(input.x) >= boardSize || stoi(input.y) < 0 || stoi(input.y) >= boardSize)
    {
        if (input.type != "D")
        {
            cout << "\"" << input.type << "\" is not a valid command. Please try again.\n\n";
        }
        else if (stoi(input.x) < 0 || stoi(input.x) >= boardSize || stoi(input.y) < 0 || stoi(input.y) >= boardSize)
        {
            cout << "(" << stoi(input.x) << ", " << stoi(input.y) << ") lies out of the mine field. Please try again.\n\n";
        }
        cout << "Enter coordinates (D x y) : ";
        cin >> input.type >> input.x >> input.y;
    }

    vector<vector<char> > realBoard(boardSize, vector<char>(boardSize, '-'));
    realBoard[stoi(input.x)][stoi(input.y)] = '?';

    //Setting up the real board, while ensuring that the first dug cell of player 1 is always safe
    for (int i = 0; i < manualInput.size(); i++)
    {
        if (realBoard[manualInput[i].first][manualInput[i].second] == '-')
        {
            realBoard[manualInput[i].first][manualInput[i].second] = '*';
            numOfMines--;
        }
        if (numOfMines == 0)
        {
            break;
        }
    }

    //Counting the number of adjacent mines for each cell & assigning the value to the realBoard
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (realBoard[i][j] != '*')
            {
                int count = 0;
                //checking the top left corner for mine
                if (i != 0 && j != 0 && realBoard[i - 1][j - 1] == '*')
                {
                    count++;
                }
                //checking the top right corner for mine
                if (i != 0 && j != boardSize - 1 && realBoard[i - 1][j + 1] == '*')
                {
                    count++;
                }
                //checking the bottom left corner for mine
                if (i != boardSize - 1 && j != 0 && realBoard[i + 1][j - 1] == '*')
                {
                    count++;
                }
                //checking the bottom right corner for mine
                if (i != boardSize - 1 && j != boardSize - 1 && realBoard[i + 1][j + 1] == '*')
                {
                    count++;
                }
                //checking left for mine
                if (i != 0 && realBoard[i - 1][j] == '*')
                {
                    count++;
                }
                //checking right for mine
                if (i != boardSize - 1 && realBoard[i + 1][j] == '*')
                {
                    count++;
                }
                //checking up for mine
                if (j != 0 && realBoard[i][j - 1] == '*')
                {
                    count++;
                }
                //checking down for mine
                if (j != boardSize - 1 && realBoard[i][j + 1] == '*')
                {
                    count++;
                }
                realBoard[i][j] = '0' + count;
            }
        }
    }

    updateBoardFunction(myBoard, realBoard, boardSize, countDigs, input.type, stoi(input.x), stoi(input.y));
    return realBoard;
}

// This function updates the myBoard after each input
void updateBoardFunction(vector<vector<char> > &myBoard, vector<vector<char> > &realBoard, int boardSize, int &countDigs, string type, int x, int y)
{
    if (type == "F")
    {
        myBoard[x][y] = 'F';
    }
    else if (type == "U")
    {
        myBoard[x][y] = '-';
    }
    else
    {
        myBoard[x][y] = realBoard[x][y];
        countDigs++;

        //If the dug cell has no adjacent mines, then all its adjacent mines are opened up recursively
        if (realBoard[x][y] == '0')
        {
            //checking the top left corner for value
            if (x != 0 && y != 0 && myBoard[x - 1][y - 1] == '-')
            {
                updateBoardFunction(myBoard, realBoard, boardSize, countDigs, type, x - 1, y - 1);
            }
            //checking the top right corner for value
            if (x != 0 && y != boardSize - 1 && myBoard[x - 1][y + 1] == '-')
            {
                updateBoardFunction(myBoard, realBoard, boardSize, countDigs, type, x - 1, y + 1);
            }
            //checking the bottom left corner for value
            if (x != boardSize - 1 && y != 0 && myBoard[x + 1][y - 1] == '-')
            {
                updateBoardFunction(myBoard, realBoard, boardSize, countDigs, type, x + 1, y - 1);
            }
            //checking the bottom right corner for value
            if (x != boardSize - 1 && y != boardSize - 1 && myBoard[x + 1][y + 1] == '-')
            {
                updateBoardFunction(myBoard, realBoard, boardSize, countDigs, type, x + 1, y + 1);
            }
            //checking left for value
            if (x != 0 && myBoard[x - 1][y] == '-')
            {
                updateBoardFunction(myBoard, realBoard, boardSize, countDigs, type, x - 1, y);
            }
            //checking right for value
            if (x != boardSize - 1 && myBoard[x + 1][y] == '-')
            {
                updateBoardFunction(myBoard, realBoard, boardSize, countDigs, type, x + 1, y);
            }
            //checking up for value
            if (y != 0 && myBoard[x][y - 1] == '-')
            {
                updateBoardFunction(myBoard, realBoard, boardSize, countDigs, type, x, y - 1);
            }
            //checking down for value
            if (y != boardSize - 1 && myBoard[x][y + 1] == '-')
            {
                updateBoardFunction(myBoard, realBoard, boardSize, countDigs, type, x, y + 1);
            }
        }
    }
}

// Prints the board in proper format
void printBoardFunction(vector<vector<char> > &board)
{
    cout << "\nYour current board :\n"
         << "     ";

    //Prints column number
    for (int i = 0; i < board.size(); i++)
    {
        cout << setw(2) << i << " ";
    }
    cout << "\n\n\n";
    for (int i = 0; i < board.size(); i++)
    {
        //Prints row number
        cout << setw(2) << i << "    ";

        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << "  ";
        }
        cout << "\n\n";
    }
}

// Controls the input-output & winning-losing status of the game
void IO_Function(vector<vector<char> > &myBoard, vector<vector<char> > &realBoard, int boardSize, int flag, int numOfMines, int &countDigs, string &name, string name2)
{
    printBoardFunction(myBoard);

    //input stores the input, which is constrained properly with the help of inputConstraintFunction() function
    inputType input = inputConstraintFunction(myBoard, boardSize, flag);

    //losing case
    if (input.type == "D" && realBoard[stoi(input.x)][stoi(input.y)] == '*')
    {
        lostBoardFunction(myBoard, realBoard, boardSize, name, name2);
        return;
    }
    //flagging case
    else if (input.type == "F")
    {
        flag--;
    }
    //unflagging case
    else if (input.type == "U")
    {
        flag++;
    }

    //updates myBoard for each case except the losing one
    updateBoardFunction(myBoard, realBoard, boardSize, countDigs, input.type, stoi(input.x), stoi(input.y));

    //checks for winning case, as at that moment, all the cells (except those containing mines) are dug, & then prints myBoard
    if (countDigs == (boardSize * boardSize - numOfMines))
    {
        printBoardFunction(myBoard);
        cout << "You won the game, " << name << "!\n";
        if (name2 != "")
        {
            cout << "You lost the game, " << name2 << "!\n";
        }
        return;
    }

    //Goes for next i/o recursively
    IO_Function(myBoard, realBoard, boardSize, flag, numOfMines, countDigs, name, name2);
}

// Checks whether the inputs are correct or not, conditions are self-explanatory by the cout statements
inputType inputConstraintFunction(vector<vector<char> > &myBoard, int boardSize, int flag)
{
    cout << flag << ((flag == 1) ? " flag remaining.\n" : " flags remaining.\n") << "Enter coordinates (D/F/U x y) : ";

    inputType input;
    cin >> input.type >> input.x >> input.y;

    if (input.type != "D" && input.type != "F" && input.type != "U")
    {
        cout << "\"" << input.type << "\" is not a valid command. Please try again.\n\n";
        return inputConstraintFunction(myBoard, boardSize, flag);
    }
    else if (stoi(input.x) < 0 || stoi(input.x) >= boardSize || stoi(input.y) < 0 || stoi(input.y) >= boardSize)
    {
        cout << "(" << stoi(input.x) << ", " << stoi(input.y) << ") lies out of the mine field. Please try again.\n\n";
        return inputConstraintFunction(myBoard, boardSize, flag);
    }
    else if (input.type == "D" && myBoard[stoi(input.x)][stoi(input.y)] == 'F')
    {
        cout << "You already used a flag here. Please try again.\n\n";
        return inputConstraintFunction(myBoard, boardSize, flag);
    }
    else if (input.type == "D" && myBoard[stoi(input.x)][stoi(input.y)] != '-')
    {
        cout << "This cell is already dug. Please try again.\n\n";
        return inputConstraintFunction(myBoard, boardSize, flag);
    }
    else if (input.type == "F" && flag <= 0)
    {
        cout << "You don't have any flag remaining. Please try again.\n\n";
        return inputConstraintFunction(myBoard, boardSize, flag);
    }
    else if (input.type == "F" && myBoard[stoi(input.x)][stoi(input.y)] == 'F')
    {
        cout << "You already used a flag here. Please try again.\n\n";
        return inputConstraintFunction(myBoard, boardSize, flag);
    }
    else if (input.type == "F" && myBoard[stoi(input.x)][stoi(input.y)] != '-')
    {
        cout << "This cell is already dug. Please try again.\n\n";
        return inputConstraintFunction(myBoard, boardSize, flag);
    }
    else if (input.type == "U" && myBoard[stoi(input.x)][stoi(input.y)] != 'F')
    {
        cout << "You don't have any flag here. Please try again.\n\n";
        return inputConstraintFunction(myBoard, boardSize, flag);
    }
    else
    {
        //returns only when the input is correct, else the function is again called recursively
        return input;
    }
}

// Updates and prints the myBoard upon losing
void lostBoardFunction(vector<vector<char> > &myBoard, vector<vector<char> > &realBoard, int boardSize, string name, string name2)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            //updates myBoard with mine if there's a mine in a cell & it's not flagged
            if (realBoard[i][j] == '*' && myBoard[i][j] != 'F')
            {
                myBoard[i][j] = '*';
            }

            //updates myBoard with cross if there's no mine in a cell but it's flagged
            if (myBoard[i][j] == 'F' && realBoard[i][j] != '*')
            {
                myBoard[i][j] = 'X';
            }
        }
    }

    printBoardFunction(myBoard);
    cout << "You lost the game, " << name << "!\n";
    if (name2 != "")
    {
        cout << "You won the game, " << name2 << "!\n";
    }
}

// This is the master function, & marks the beginning of the game
void masterFunction()
{
    srand(time(NULL));
    //Introductory message
    cout << "\n\nWelcome to Minesweeper!\n";

    int mode = modeFunction();
    if (mode == 1)
    {
        singlePlayerFunction();
    }
    else
    {
        multiPlayerFunction();
    }
}

// main function calls the masterFunction
int main()
{
    masterFunction();
    return 0;
}
