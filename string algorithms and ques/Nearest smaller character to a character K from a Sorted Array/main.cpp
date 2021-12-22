#include <bits/stdc++.h>
using namespace std;
/*
void NearestSmallerChar(char arr[], char k)
{
    int smaller=INT_MAX;
    int n=sizeof(arr)/sizeof(arr[0]);
    char ans='@';
    for(int i=0; i<n; i++)
    {
       int small = (k-'0')-(arr[i]-'0');
       if(small<smaller and small>=0)
        {
            smaller=small;
            ans = arr[i];
        }
    }
    if(ans!='@')
     cout<<ans;
    else
        cout<<"-1";
}

int main()
{
    char arr[] = {'e', 'g', 't', 'y'};
    char K = 'a';
    NearestSmallerChar(arr, K);
    return 0;
}
*/


// Using Binary Search O(log n)
char NearestSmallerChar(char arr[], int n, char k)
{
    int start=0, end=n-1;

    char ans = '@';

    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(arr[mid]==k)
            end=mid-1;

        else if(arr[mid]<k)
        {
            start=mid+1;
            ans = arr[mid];
        }
        else
            end=mid-1;
    }
    return ans;
}

int main()
{
    char arr[] = {'e', 'g', 't', 'y'};
    char K = 'u';
    int n = sizeof(arr)/sizeof(arr[0]);

    char ch=NearestSmallerChar(arr, n, K);
    if(ch=='@')
        cout<<"-1";
    else
        cout<<ch;
    return 0;
}
