#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';

void drawBoard()
{
    cout << "     0     1     2" << endl;
    cout << "  -----------------" << endl;
    for (int row = 0; row < 3; row++)
    {
        cout << row << " ";
        for (int col = 0; col < 3; col++)
        {
            cout << "|  " << board[row][col] << "  ";
        }
        cout << "|" << endl;
        cout << "  -----------------" << endl;
    }
}

bool isValidMove(int row, int col)
{
    if (row < 0 || row > 2 || col < 0 || col > 2)
    {
        return false;
    }
    else if (board[row][col] != ' ')
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool hasWon(char symbol)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        {
            return true;
        }
        else if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
        {
            return true;
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
        return true;
    }
    else if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    {
        return true;
    }
    return false;
}

bool isTie()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int row, col;
    while (!hasWon('X') && !hasWon('O') && !isTie())
    {
        drawBoard();
        cout << "Player " << player << ", enter row and column: ";
        cin >> row >> col;
        if (isValidMove(row, col))
        {
            board[row][col] = player;
            if (player == 'X')
            {
                player = 'O';
            }
            else
            {
                player = 'X';
            }
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }
    drawBoard();
    if (hasWon('X'))
    {
        cout << "Player X wins!" << endl;
    }
    else if (hasWon('O'))
    {
        cout << "Player O wins!" << endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }
    return 0;
}
