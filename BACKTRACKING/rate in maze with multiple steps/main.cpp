#include <bits/stdc++.h>
using namespace std;

#define N 4
void printsol(int sol[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool issafe(int maze[N][N],int x,int y)
{
    if(x<N && x>=0 && y<N && y>=0 &&maze[x][y]!=0)
        return true;
    return false;
}
bool solveutil(int maze[N][N],int sol[N][N],int x,int y)
{
    if(x==N-1 && y==N-1)
    {
        sol[x][y]=1;
        printsol(sol);
        return true;
    }

    if(issafe(maze,x,y))
    {
        sol[x][y]=1;
        for(int i=1;i<=maze[x][y] && i<N ;i++)
        {
            if(solveutil(maze,sol,x+i,y))
                return true;
            if(solveutil(maze,sol,x,y+i))
                return true;
        }
        sol[x][y]=0;
        return false;
    }
    return false;
}
void solvemaze(int maze[N][N])
{
    int sol[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            sol[i][j]=0;
    }
    solveutil(maze,sol,0,0);
}
int main()
{
    int maze[N][N] = { { 2, 1, 0, 0 }, { 3, 0, 0, 1 }, { 0, 1, 0, 1 }, { 0, 0, 0, 1 } };

    solvemaze(maze);
    return 0;
}
