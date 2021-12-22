#include<bits/stdc++.h>
using namespace std;

void printpath(vector<int>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void printAll_path(int mat[3][4],int row,int col,vector<int>v)
{
    if(row==2 && col==3)
    {
        v.push_back(mat[row][col]);
        printpath(v);
        return;
    }

    if(row>2|| col>3)
        return;
    v.push_back(mat[row][col]);

    //down
    printAll_path(mat,row+1,col,v);
    //right
    printAll_path(mat,row,col+1,v);
    v.pop_back();
}
int main()
{
    /* 1 2 3
       4 5 6 */
    int mat[3][4] = { {1, 2, 3, 4}, {45, 5, 6, 7}, {8, 9, 10, 11} };
    vector<int> v(0);
    printAll_path(mat,0,0,v);
    return 0;
}
