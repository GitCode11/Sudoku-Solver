#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0        // For Unassigned Cells
#define N 9                 // Size of Grid N*N

// This function finds an entry in grid that is still unassigned
bool FindUnassignedLocation(int grid[N][N],int &row, int &col);

// Checks whether it will be legal to assign num to the given row, col
bool NoConflicts(int grid[N][N], int row,int col, int num);
/*
Main Function to Solve Sudoku
*/
bool SolveSudoku(int grid[N][N])
{
    int row, col;
    /*
    Checks if any Unassigned Location are there or not
    */
    if (!FindUnassignedLocation(grid, row, col))
    {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (NoConflicts(grid, row, col, num))
        {
            grid[row][col] = num;               // Tentative Assignment

            if(SolveSudoku(grid))              // SUCCESS
                return true;

            grid[row][col] = UNASSIGNED;        // FAILURE
        }
    }
    return false;                           // Triggers Backtracking
}

/*
To find,if any, unassigned location in the Grid
*/
bool FindUnassignedLocation(int grid[N][N],int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
/*
To check whether the given entry matches any other entry in specified row
*/
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
/*
To check whether the given entry matches any other entry in specified column
*/
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
/*
To check whether a number is present in 3*3 block or not
*/
bool UsedInBox(int grid[N][N], int boxStartRow,int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        {
        for (int col = 0; col < 3; col++)
            {
                if (grid[row + boxStartRow][col + boxStartCol] == num)
                {
                    return true;
                }
            }
        }
    return false;
}
/*
To check whether it is legal to assign num to given row and column
*/
bool NoConflicts(int grid[N][N], int row,int col, int num)
{
    return !UsedInRow(grid, row, num) &&!UsedInCol(grid, col, num) &&!UsedInBox(grid, row - row % 3 ,col - col % 3, num) &&grid[row][col] == UNASSIGNED;
}

void printGrid(int grid[N][N])      // UTILITY FUNCTION TO PRINT GRID
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Driver Code
int main()
{
    cout<<"Welcome to Sudoku Solver"<<endl<<endl;
    cout<<"Function: SolveSudoku"<<endl<<endl;
    cout<<"Takes a partially filled-in grid and attempts to assign values to all unassigned locations in "<<endl;
    cout<<"such a way to meet the requirements for Sudoku solution (non-duplication across rows, columns, "<<endl;
    cout<<"and boxes). The function operates via recursive backtracking: it finds an unassigned "<<endl;
    cout<<"location with the grid and then considers all digits from 1 to 9 in a loop. "<<endl<<endl;
    cout<<"If a digit is found that has no existing conflicts, tentatively assign it and recur to attempt "<<endl;
    cout<<"to fill in rest of grid. If this was successful, the puzzle is solved. If not, unmake that decision "<<endl;
    cout<<"and try again. If all digits have been examined and none worked out, return false "<<endl;
    cout<<"to backtrack to previous decision point."<<endl<<endl;

    /*int grid[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>grid[i][j];
        }
    }*/
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if(SolveSudoku(grid)==true)
    {
        cout<<"Solution to Given Sudoku is :"<<endl<<endl;
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists";
    }
    return 0;
}
