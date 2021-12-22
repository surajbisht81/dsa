#include <bits/stdc++.h>
using namespace std;

void find_four_elements(int arr[],int n,int x)
{
    unordered_map<int,pair<int,int>>mp;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            mp[arr[i]+arr[j]] = {i, j};
        }
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            int sum=arr[j]+arr[i];

            if(mp.find(x-sum)!=mp.end())
            {
                pair<int,int>p= mp[x-sum];

                if(p.first!=i && p.second!=j && p.first!=j && p.second!=i)
                {
                    cout<<arr[i]<<", "<<arr[j]<<", "<<arr[p.first]<<", "<<arr[p.second]<<endl;
                    return;
                }
            }
        }
    }
}
int main()
{
    int arr[] = { 10, 20, 30, 40, 1, 2 };
    int x=91;
    int n=sizeof(arr)/sizeof(arr[0]);

    find_four_elements(arr,n,x);
    return 0;
}
