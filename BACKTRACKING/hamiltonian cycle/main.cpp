#include <bits/stdc++.h>
using namespace std;
#define V 5
bool issafe(int graph[V][V],int path[],int i,int pos)
{
    if(graph[path[pos-1]][i]==0)
        return false;
    for(int j=0;j<pos;j++)
        if(path[j]==i)
        return false;
    return true;
}
bool hamiltonian(int graph[V][V],int path[],int pos)
{
    if(V==pos)
    {
      if(graph[path[0]][path[pos-1]]==1)
      {for(int i=0;i<V;i++)
            cout<<path[i]<<" ";
        cout<<path[0];
        return true;
      }
      else
        cout<<"soln does not exist.";
    }


    for(int i=1;i<V;i++)
    {
        if(issafe(graph,path,i,pos))
           {
               path[pos]=i;
               if(hamiltonian(graph,path,pos+1)==true)
                 return true;

                 path[pos]=-1;
           }
    }
    return false;//backtracking;
}
int main()
{
    int graph[V][V]={{0, 1, 0, 1, 0}, {1, 0, 1, 1, 1}, {0, 1, 0, 0, 1}, {1, 1, 0, 0, 1}, {0, 1, 1, 1, 0}};

    int path[V];
    for(int i=0;i<V;i++)
        path[i]=-1;

    path[0]=0;
    hamiltonian(graph,path,1);
    return 0;
}
