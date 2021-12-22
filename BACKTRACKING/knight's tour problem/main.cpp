#include <bits/stdc++.h>
using namespace std;
#define N 8

int issafe(int sol[N][N],int x,int y)
{
    return (sol[x][y]==-1 && x>=0 && x<N && y>=0 && y<N);

}
int solveKT(int sol[N][N],int xmove[N], int ymove[N],int movei,int x,int y)
{
   //base case
   if(movei==N*N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }

    for(int k=0;k<N;k++)
    {
        int next_x=x+xmove[k];
        int next_y=y+ymove[k];
        if(issafe(sol,next_x,next_y))
        {
            sol[next_x][next_y]=movei;
            if(solveKT(sol,xmove,ymove,movei+1,next_x,next_y)==1)
                return 1;
            else
                sol[next_x][next_y]=-1;
        }
    }
    return 0;
}
int main()
{
    int sol[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
         sol[i][j]=-1;
    }

    int xmove[N]={2,1,-1,-2,-2,-1,1,2};
    int ymove[N]={1,2,2,1,-1,-2,-2,-1};
    sol[0][0]=0;
    solveKT(sol,xmove,ymove,1,0,0);
    return 0;
}
