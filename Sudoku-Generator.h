#include<cstdlib>
#include<ctime>
using namespace std;
bool isSafe(vector<vector<int>> &sudoku,int row,int col,int num)
{
    int xblock=row-row%3,yblock=col-col%3;
    for(int i=0;i<9;i++)
    {
        if(sudoku[row][i]==num && i!=col)
            return 0;
    }
    for(int i=0;i<9;i++)
    {
        if(sudoku[i][col]==num && i!=row)
            return 0;
    }
    for(int i=xblock;i<xblock+3;i++)
    {
        for(int j=yblock;j<yblock+3;j++)
        {
            if(sudoku[i][j]==num && i!=row && j!=col)
                return 0;
        }
    }
    return 1;
}
vector<vector<int>> generator(int strength)
{
    vector<vector<int>> mat={
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };
    int i,j;
    srand(time(0));
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            int to_fill=rand()%(strength+1);
            if(to_fill==0)
            {
                int num=rand()%9+1;
                while(1)
                {
                    if(isSafe(mat,i,j,num))
                    {
                        mat[i][j]=num;
                        break;
                    }
                    else
                    {
                        num++;
                        if(num==10)
                            num=1;
                    }
                }
            }
        }
    }
    return mat;
}