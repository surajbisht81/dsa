#include <bits/stdc++.h>
using namespace std;

void find_subarray(int arr[],int n)
{
    unordered_map<int,int>mp;
    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum+= arr[i];

        if(sum==0)
            cout<<"\nsum is found at index : 0 and "<<i;
        else if(mp.find(sum)!=mp.end())
        {
            cout<<"\nsum is found at index : "<<mp[sum]+1 <<"and "<<i;
        }
        else
            mp[sum]=i;
    }
}
int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int n=sizeof(arr)/sizeof(arr[0]);
    find_subarray(arr,n);
    return 0;
}
