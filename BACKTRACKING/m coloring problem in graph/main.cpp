#include <bits/stdc++.h>
#define V 4
using namespace std;

void printcolor(int color[V])
{
    for(int i=0;i<V;i++)
      cout<<color[i]<<" ";
      cout<<endl;
}
bool issafe(int graph[V][V],int color[V],int current_vertex,int c)
{
    for(int i=0;i<V;i++)
    {
        if(graph[current_vertex][i] && color[i]==c)
            return false;
    }
    return true;
}
bool solve_m_color(int graph[V][V],int color[V],int m,int current_vertex)
{
    // base case;
    if(current_vertex==V)
    {
        printcolor(color);
        return false;
    }

    for(int i=1;i<=m;i++)
    {
         if(issafe(graph,color,current_vertex,i))
         {
             color[current_vertex]=i;

             if(solve_m_color(graph,color,m,current_vertex+1)==true)
                return true;

             color[current_vertex]=0;
         }
    }
    return false;
}
int main()
{
    int graph[V][V]={{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
    int m=3;

    int color[V]={0};
    solve_m_color(graph,color,m,0);
    return 0;
}
