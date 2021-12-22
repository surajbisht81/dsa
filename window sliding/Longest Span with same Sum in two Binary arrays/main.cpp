#include <bits/stdc++.h>
using namespace std;

int longest_span(int arr1[],int arr2[],int n)
{
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=arr1[i]-arr2[i];

    int sum=0,max_len=0;
    map<int,int>mp;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
            if(max_len < i+1)
                max_len=i+1;
        }
        else if(mp.find(sum)!=mp.end())
        {
            if(max_len < i-mp[sum])
                max_len = i-mp[sum];
        }
        else
            mp[sum]=i;
    }
    return max_len;
}
int main()
{
    int  arr1[] = {0, 1, 0, 1, 1, 1, 1};
    int  arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n=sizeof(arr1)/sizeof(arr1[0]);
     cout<<"\nlongest span with same sum is :"<<longest_span(arr1,arr2,n);
     return 0;
}
