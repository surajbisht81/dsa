#include <bits/stdc++.h>
using namespace std;


void FindPair(int ar1[], int ar2[], int x, int n, int m)
{
    int arr[n+m];
    int k=0;
    map<int, int> mp;
    
    for(int i=0; i<n; i++)
     {
         arr[k]=ar1[i];
         k++;
         mp[ar1[i]]=1;;
     }
    for(int i=0; i<m; i++)
    {
        arr[k]=ar2[i];
        k++;
        mp[ar2[i]]=2;
    }
    
    sort(arr, arr+(n+m));
    
    int diff=INT_MAX;
    
        int l=0;
        int r=n+m-1;
        int first=0, second=0;
        
        while(l<r)
        {
            if(mp[arr[l]]==1 and mp[arr[r]]==2 and abs(arr[l]+arr[r]-x)<diff)
            {
                diff = abs(arr[l]+arr[r]-x);
                first = arr[l];
                second = arr[r];
            }
            else if(mp[arr[l]]==1 and mp[arr[r]]==2 and arr[l]+arr[r]>x)
             r--;
            else
            l++;
        }
    
    cout<<first<<" "<<second;
}

int main() 
{
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int x = 32;
    int n = sizeof(ar1)/sizeof(ar1[0]);
    int m = sizeof(ar2)/sizeof(ar2[0]);
    
    FindPair(ar1, ar2, x, n, m);
    return 0;
}