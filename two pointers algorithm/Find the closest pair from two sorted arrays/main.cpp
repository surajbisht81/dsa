#include <bits/stdc++.h>
using namespace std;

void closet_pair(int arr1[],int arr2[],int n,int m,int X)
{
    int i,j;
    i=0,j=m-1;
    int curr_i,curr_j;

    int minn=INT_MAX;
    while(i<n && j>=0)
    {
        int curr_min = abs(arr1[i]+arr2[j] -X);
        if(curr_min<minn)
        {
            minn=curr_min;
            curr_i=i;
            curr_j=j;
        }

        if(arr1[i]+arr2[j]< X)
            i++;
        else
            j--;
    }

    cout<<"closest pair is : ["<<arr1[curr_i]<<","<<arr2[curr_j]<<"]";
}
int main()
{
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int n=sizeof(ar1)/sizeof(ar1[0]);
    int m=sizeof(ar2)/sizeof(ar2[0]);

    int X=38;
    closet_pair(ar1,ar2,n,m,X);
    return 0;
}
