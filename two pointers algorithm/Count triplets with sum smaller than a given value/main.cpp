#include <bits/stdc++.h>
using namespace std;

int count(int arr[],int n,int sum)
{
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        int l=i+1;
        int r=n-1;
        int x=arr[i];

        while(l<r)
        {
            if(x+arr[l]+arr[r]>=sum)
              r--;

            else
            {
                ans+= (r-l);
                l++;
            }
        }
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,X;
        cin>>N;
        cin>>X;
        int arr[N];

        for(int i=0;i<N;i++)
         cin>>arr[i];

        cout<<count(arr,N,X)<<endl;
    }
    return 0;
}
