#include <bits/stdc++.h>
using namespace std;

void find_triplets(int arr[],int n)
{
    sort(arr,arr+n);

     bool found=0;
    for(int i=0;i<n;i++)
    {
        int l=0;
        int r=n-1;
        int x=arr[i];

        while(l<r)
        {
            if(i!=l && i!=r)
            {
                if(x==arr[l]+arr[r])
                {
                    cout<<x<<", "<<arr[l]<<", "<<arr[r]<<endl;
                    found=1;
                }
            }
            if(arr[l]+arr[r]<x)
                l++;
            else
                r--;
        }
    }
    if(found==0)
        cout<<"no triplets are found";
}
int main()
{
     int arr[] = { 5, 32, 1, 7, 10, 50, 19, 21, 2 };
     int n=sizeof(arr)/sizeof(arr[0]);

     find_triplets(arr,n);
     return 0;
}
