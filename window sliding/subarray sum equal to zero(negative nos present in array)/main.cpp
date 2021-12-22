#include<bits/stdc++.h>
using namespace std;


bool subarray_with_sum0(int arr[],int n,int sum)
{
    unordered_map<int,int>mp;
    int curr_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum==0)
        cout<<"\nsubarray is present at :"<<i;

        if(mp.find(curr_sum-0)!=mp.end())
         cout<<"\nsubarray is present at :"<<mp[curr_sum-sum]+1 <<"to"<< i;

         mp[curr_sum]=i;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum=0;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];

        subarray_with_sum0(arr,n,sum);
    }
    return 0;
}
