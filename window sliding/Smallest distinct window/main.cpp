//Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
//For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

#include <bits/stdc++.h>
using namespace std;

int smallest_window(string str,int n)
{
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[str[i]]=1;
    }
    int k=mp.size();
    mp.clear();

    int min=INT_MAX;
    int window=0,right=0;
    for(int left=0; left<n; left++)
    {
        while(right<n && window<k)
        {
            mp[str[right]]++;
            if(mp[str[right]]==1)
             window++;

            right++;
        }
        if(window==k)
         {
             if(min>right-left)
             min=right-left;
         }

        mp[str[left]]--;
        if(mp[str[left]]==0)
          window--;
    }
    return min;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;

        int n=str.length();
        cout<<smallest_window(str,n)<<endl;
    }
    return 0;
}
