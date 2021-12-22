#include <bits/stdc++.h>
using namespace std;

int count_subarray(int arr[],int n)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
     mp[arr[i]]=1;

     int N=mp.size();

     mp.clear();

     int ans=0, right=0, window=0;

     for(int left=0;left<n;++left)
     {
         while(right<n && window<N)
         {
             ++mp[arr[right]];
             if(mp[arr[right]]==1)
                ++window;
            ++right;
         }

         if(window==N)
          ans+= (n-right+1);

         --mp[arr[left]];
         if(mp[arr[left]]==0)
          --window;
     }
     return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
         cin>>arr[i];

        cout<<count_subarray(arr,n)<<endl;
    }
    return 0;
}
