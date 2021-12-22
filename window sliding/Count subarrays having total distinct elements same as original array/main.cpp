#include <bits/stdc++.h>
using namespace std;

int countSubarray(int arr[],int n)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=1;
    }
    int k=mp.size();
    mp.clear();

    int right=0,window=0,ans=0;
    for(int left=0;left<n;left++)
    {
        while(right<n && window<k)
        {
            ++mp[arr[right]];

            if(mp[arr[right]]==1)
                ++window;
            ++right;
        }
        if(window==k)
            ans+=(n-right+1);
        --mp[arr[left]];

        if(mp[arr[left]]==0)
            --window;
    }
    return ans;
}
int main()
{
    int arr[]={2, 1, 3, 2, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nall subarray having distinct element as in original array:"<<countSubarray(arr,n);
    return 0;
}
