/*Given an array and an integer K. We need to find the maximum of every segment of length K which has no duplicates in that segment.

Examples:

Input : a[] = {1, 2, 2, 3, 3}, 
          K = 3.
Output : 1 3 2
For segment (1, 2, 2), Maximum = 1.
For segment (2, 2, 3), Maximum = 3.
For segment (2, 3, 3), Maximum = 2. 

Input : a[] = {3, 3, 3, 4, 4, 2},
          K = 4.
Output : 4 Nothing 3
Time Complexity : O(N Log K)*/


#include <bits/stdc++.h>
using namespace std;

void find_max(int arr[], int k,int n)
{
    unordered_map<int,int>mp;
    set<int>st;

    for(int i=0;i<k-1;i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]]==1)
            st.insert(arr[i]);
        else
            st.erase(arr[i]);
    }

    for(int i=k-1;i<n;i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]]==1)
            st.insert(arr[i]);
        else
            st.erase(arr[i]);

        if(st.size()==0)
            cout<<"\nnothing."<<endl;
        else
        {
            auto it=st.rbegin();
            cout<<*it<<endl;
        }

        int x= i - k+1;
        mp[arr[x]]--;
        if(mp[arr[x]]==1)
            st.insert(arr[x]);
        else
            st.erase(arr[x]);
    }
}
int main()
{
    int arr[] = { 1, 2, 2, 3, 3 };
    int k=3;
    int n = sizeof(arr)/sizeof(arr[0]);

    find_max(arr,k,n);
    return 0;
}
