#include <bits/stdc++.h>
using namespace std;
#define  n 4

int canmove(int maze[n][n],int x,int y)
{
    return (maze[x][y]==1 && x<n && x>=0 && y<n && y>=0);
}
int solvemaze(int maze[n][n],int sol[n][n],int xmove[2],int ymove[2],int x,int y)
{
    if(x*y==9)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }
    int k,next_x,next_y;
    for( k=0;k<2;k++)
    {
        next_x=x+xmove[k];
        next_y=y+ymove[k];
        if(canmove(maze,next_x,next_y))
        {
            sol[next_x][next_y]=1;
            if(solvemaze(maze,sol,xmove,ymove,next_x,next_y)==1)
                return 1;
            else
                sol[next_x][next_y]=0;
        }
    }
    return 0;
}
int main()
{
    int maze[n][n] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    int sol[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            sol[i][j]=0;
    }
    sol[0][0]=1;
    int xmove[2]={0,1};
    int ymove[2]={1,0};
    solvemaze(maze,sol,xmove,ymove,0,0);
    return 0;
}
