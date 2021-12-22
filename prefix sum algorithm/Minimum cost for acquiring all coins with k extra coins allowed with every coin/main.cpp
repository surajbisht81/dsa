#include <bits/stdc++.h>
using namespace std;

// simple greedy method
/*int MinCoinCost(int arr[], int k, int n)
{
    int Min_coin_remove = ceil( 1.0 * n/(k+1) );

    sort(arr, arr+n);
    int ans = 0;
    for(int i=0; i<Min_coin_remove; i++)
    {
        ans+=arr[i];
    }
    return ans;
}*/

int main()
{
    int arr[] = {100, 20, 50, 10, 2, 5};
    int k=3;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<MinCoinCost(arr, k, n);
    return 0;
}

// prefix sum algorithm method

void preprocess(int arr[], int n)
{
   sort(arr, arr+n);
   for(int i=1; i<n; i++)
    {
      arr[i] +=arr[i-1];
    }
}

int MinCoinCost(int arr[], int k, int n)
{
   int min_cost = ceil(1.0* n/(k+1) );
   return arr[min_cost -1];
}   
int main()
{
    int arr[] = {100, 20, 50, 10, 2, 5};
    int k=3;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<MinCoinCost(arr, k, n);
    return 0;
}
