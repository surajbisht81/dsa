#include <bits/stdc++.h>
using namespace std;

int findnewString(string s)
{
    int ans = 0;
    int freq[26]={0};

    for(int i=0; i<s.length(); i++)
    {
        ans += freq[s[i]-'a'];

        freq[s[i]-'a']++;
    }
    return ans;
}

int main()
{
    string str = "aaabaaa";
    cout<<findnewString(str);
    return 0;
}
