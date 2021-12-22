#include <bits/stdc++.h>
using namespace std;

int MaxSubarraySum(int arr[], int n)
{
    int min_prefix_sum = 0;
    int res=INT_MIN;

    int prefix[n];
    prefix[0]=arr[0];
    for(int i=1; i<n; i++)
        prefix[i]=prefix[i-1]+arr[i];

    for(int i=0; i<n; i++)
    {
        res = max(res, prefix[i]-min_prefix_sum);

        min_prefix_sum = min(min_prefix_sum, prefix[i]);
    }
    return res;
}

int main()
{
     int arr1[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout<<MaxSubarraySum(arr1, n1);
    return 0;
}
