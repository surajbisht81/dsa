#include <bits/stdc++.h>
using namespace std;
#define N 9
bool usedinrow(int grid[N][N],int row,int num)
{
    for(int col=0;col<N;col++)
        if(grid[row][col]==num)
         return true;
return false;
}
bool usedincol(int grid[N][N],int col,int num)
{
    for(int row=0;row<N;row++)
        if(grid[row][col]==num)
        return true;
    return false;
}
bool usedinbox(int grid[N][N],int startrow,int startcol,int num)
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(grid[row+startrow][col+startcol]==num)
                return true;
        }
    }
    return false;
}
bool issafe(int grid[N][N],int row,int col,int num)
{
    return (!usedinrow(grid,row,num) && !usedincol(grid,col,num)&& !usedinbox(grid,(row-row%3),(col-col%3),num) && grid[row][col]==0);
}
bool findunassignedlocation(int grid[N][N],int &row,int &col)
{
    for( row=0;row<N;row++)
    {
        for( col=0;col<N;col++)
        {
            if(grid[row][col]==0)
                return true;
        }
    }
    return false;
}

bool solvesudoku(int grid[N][N])
{
    int row,col;

    if(!findunassignedlocation(grid,row,col))
        return true;

    for(int num=1;num<=N;num++)
    {
        if(issafe(grid,row,col,num))
        {
            grid[row][col]=num;
            if(solvesudoku(grid)==true)
                return true;
            grid[row][col]=0;
        }
    }
    return false;
}
void printsudoku(int grid[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int grid[N][N]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(solvesudoku(grid)==true)
        printsudoku(grid);
    else
        cout<<"soln doesn't exist.";
    return 0;
}
