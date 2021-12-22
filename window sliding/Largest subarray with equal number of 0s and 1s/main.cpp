#include <bits/stdc++.h>
using namespace std;

int largest_subarray(int arr[],int n)
{
    int sum=0,largest_sum=0;
    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        sum+= (arr[i]==0 ? -1:arr[i]);
        if(sum==0)
        {
            if(largest_sum<i+1)
                largest_sum=i+1;
        }
        else if(mp.find(sum)!=mp.end())
        {
            if(largest_sum < i-mp[sum])
                largest_sum=i-mp[sum];
        }
        else
            mp[sum]=i;
    }
    return largest_sum;
}
int main()
{
    int arr[] = {1, 0, 1, 1, 1, 0, 0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nlargest subarray containing equal no of 0's and 1's is :"<<largest_subarray(arr,n);
    return 0;
}
