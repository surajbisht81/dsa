#include <bits/stdc++.h>
using namespace std;

void result(vector<int>arr,int n,int **query,int m)
{
  int prefix[n+1];
  prefix[0]=arr[0];
  for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]^arr[i];
  for(int i=0;i<m;i++)
  {
      int L=query[i][0];
      int R=query[i][1];
      if(L==0)
        cout<<prefix[R]<<" ";
      else
      {int ans=prefix[R]^prefix[L-1];
      cout<<ans<<" ";
      }
  }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
     {
        int x;
        cin>>x;
        arr.push_back(x);
     }
     int m;
     cin>>m;
     int **query=new int*[m];
     for(int i=0;i<m;i++)
       query[i]=new int[2];
     for(int i=0;i<m;i++)
     {
         cout<<endl<<"enter"<<i+1<<"query:";
         for(int j=0;j<2;j++)
         {
             cin>>query[i][j];
         }
     }
    result(arr,n,query,m);
    return 0;
}
