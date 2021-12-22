#include <bits/stdc++.h>
using namespace std;

void find_triplets(int arr[], int n,int sum)
{
    //use sorting technique to sort
    sort(arr,arr+n);
    bool found=0;
    for(int i=0;i<n-1;i++)
    {
        int l=i+1;
        int r=n-1;
        int x=arr[i];
        while(l<r)
        {
            if(x+arr[l]+arr[r]==sum)
            {
                cout<<"[ "<<x<<", "<<arr[l]<<", "<<arr[r]<<" ]"<<endl;
                found=1;
            }
            if(x+arr[l]+arr[r]<sum)
                l++;
            else
                r--;
        }
    }
    if(found==0)
    {
      cout<<"\ntriplets are not found.";
    }
}
int main()
{
    int arr[]={1, 4, 45, 6, 10, 8 };
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=22;
    find_triplets(arr,n,sum);
    return 0;
}
