#include <bits/stdc++.h>
using namespace std;

int max_sum(int arr[],int k,int n)
{
    int maxx=0;
    int current_window=0;
    for(int i=0;i<k;i++)
        maxx+=arr[i];

    current_window=maxx;
    for(int i=k;i<n;i++)
    {
        current_window+=arr[i]- arr[i-k];
        maxx=max(maxx,current_window);
    }
    return maxx;
}
int main()
{
    int arr[]={1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nmax sum is :"<<max_sum(arr,k,n);
    return 0;
}
