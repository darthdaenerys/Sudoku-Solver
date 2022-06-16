#include<bits/stdc++.h>
#include "./Sudoku-Generator.h"
using namespace std;
void displaySudoku(vector<vector<int>> &sudoku)
{
    cout<<" -------------------";
    for(int i=0;i<9;i++)
    {
        if(i%3==0)
            cout<<'\n';
        for(int j=0;j<9;j++)
        {
            if(j%3==0)
                cout<<" ";
            cout<<sudoku[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<" -------------------\n";
}
bool solveSudoku(vector<vector<int>> &sudoku,int row,int col)
{
    if(row==8 && col==9)
        return 1;
    if(col==9)
    {
        row++;
        col=0;
    }
    if(sudoku[row][col]!=0)
        return solveSudoku(sudoku,row,col+1);
    for(int i=1;i<=9;i++)
    {
        if(isSafe(sudoku,row,col,i))
        {
            sudoku[row][col]=i;
            if(solveSudoku(sudoku,row,col+1))
                return 1;
        }
        sudoku[row][col]=0;
    }
    return 0;
}
void solve()
{
    cout<<"Now, enter your Sudoku (0 refers to blank)\n";
    vector<vector<int>> sudoku;
    int i,j,x;
    for(i=0;i<9;i++)
    {
        vector<int> row;
        for(j=0;j<9;j++)
        {
            cin>>x;
            row.push_back(x);
        }
        sudoku.push_back(row);
    }
    if(solveSudoku(sudoku,0,0))
        displaySudoku(sudoku);
    else
        cout<<"Solution does not exists!\n";
}
int main()
{
    cout<<"------------\ns: Sudoku Solver\ng: Sudoku Generator\nq: quit\n------------\n";
    char choice;
    cout<<"Enter your choice: ";
    cin>>choice;
    while(choice!='q')
    {
        switch(choice)
        {
            case 's':
                solve();
                break;
            case 'g':
                int tough;
                cout<<"Enter the touchness: (1-Infirm to 9-Extreme): ";
                cin>>tough;
                if(tough==0 || tough>9)
                {
                    cout<<"Invalid toughness!\n";
                    break;
                }
                else
                {
                    vector<vector<int>> sudoku=generator(tough);
                    displaySudoku(sudoku);
                    break;
                }
            default:
                cout<<"Wrong choice entered!\n";
                break;
        }
        cout<<"Enter your choice: ";
        cin>>choice;
    }
}