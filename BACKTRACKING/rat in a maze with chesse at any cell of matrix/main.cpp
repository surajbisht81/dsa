#include <bits/stdc++.h>
using namespace std;
#define N 3

bool canmove(int maze[][N],int x,int y,int sol[][N])
{
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]!=0 && sol[x][y]==-1)
        return true;
    return false;
}
bool ratinmaze(int maze[][N],int x,int y,int xmove[4],int ymove[4],int sol[][N])
{
    //base case
    if(maze[x][y]==9)
        return true;

    for(int i=0;i<4;i++)
    {
        int next_x=x+xmove[i];
        int next_y=y+ymove[i];
        if(canmove(maze,next_x,next_y,sol))
        {
            sol[next_x][next_y]=1;
            if(ratinmaze(maze,next_x,next_y,xmove,ymove,sol))
                return true;
            else
                sol[next_x][next_y]=-1;
        }
    }
    return false;
}
int main()
{
    cout<<"\nenter the maze:\n";
    int maze[N][N];
    int sol[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            { cin>>maze[i][j];
              sol[i][j]=-1;
            }

    int xmove[4]={1,0,-1,0};
    int ymove[4]={0,1,0,-1};

    if(maze[0][0]==0)
        cout<<"\n -1";

    else
    {
         sol[0][0]= 1;
      if(ratinmaze(maze,0,0,xmove,ymove,sol))
        cout<<"\n 1";
     else
        cout<<"\n -1";
    }
    return 0;
}
