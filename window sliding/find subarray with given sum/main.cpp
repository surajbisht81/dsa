#include <bits/stdc++.h>
using namespace std;

void subArrsum(int arr[],int sum,int n)
{
    vector<pair<int,int>>v;

    int curr_sum=0, start=0;

    for(int i=0;i<n;i++)
    {
        curr_sum=curr_sum+arr[i];

        if(curr_sum>sum)
        {
            while(curr_sum>sum)
            {
                curr_sum=curr_sum-arr[start];
                start++;
            }
        }
        if(curr_sum==sum)
        {
            v.push_back(make_pair(start,i));
        }

    }

    bool flag=0;
    for(auto i=0;i<v.size();i++)
    {
        flag=1;
        cout<<"\nsum is found at indices :"<<v[i].first<<" and "<<v[i].second;
    }
    if(!flag)
        cout<<"\nno subarray found.";
}
int main()
{
    int arr[]={15, 3, 4, 8, 8, 5, 10, 23};
    int sum=10;
    int n=sizeof(arr)/sizeof(arr[0]);
    subArrsum(arr,sum,n);
    return 0;
}
