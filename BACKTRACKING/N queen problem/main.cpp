#include<bits/stdc++.h>
using namespace std;
bool canplace(char board[][20],int row,int col,int n)
{
    for(int i=0;i<n;i++)
    {
        if(board[row][i]=='Q')
            return false;
    }
    for(int i=0;i<n;i++)
    {
        if(board[i][col]=='Q')
            return false;
    }
    int i=row,j=col;
    while(i>=0 && j>=0)
    {
        if(board[i][j]=='Q')
            return false;
        i--;
        j--;
    }
    i=row,j=col;
    while(i>=0 && j<=n)
    {
        if(board[i][j]=='Q')
            return false;
        i--;
        j++;
    }
    return true;
}
bool solveNqueen(char board[][20],int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
              cout<<board[i][j]<<" ";
            cout<<endl;
        }
        cout<<"\n\n";
        return false;
    }

    for(int pos=0;pos<n;pos++)
    {
        if(canplace(board,row,pos,n))
        {
            board[row][pos]='Q';
            int nextqueen=solveNqueen(board,n,row+1);
            if(nextqueen==true)
                return true;
        }
        board[row][pos]='.';
    }
    return false;   //backtracking;
}
int main()
{
    char board[20][20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]='.';
        }
    }
    solveNqueen(board,n,0);
    return 0;
}


