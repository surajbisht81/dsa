/*Given a string S with lowercase alphabets only and Q queries where each query contains a pair {L, R}.
 For each query {L, R}, there exists a substring S[L, R], the task is to find the value of the product of the frequency
 of each character in substring with their position in alphabetical order. */

#include <bits/stdc++.h>
using namespace std;

int go(string S, int l, int r)
{
    int freq[26] = {0};
    string str = S.substr(l, r-l+1);
    for(int i=0; i<str.length(); i++)
    {
        freq[str[i]-'a']++;
    }

    int ans=0;
    for(int i=0; i<str.length(); i++)
    {
       ans += freq[str[i]-'a'] * ((int)str[i] - 97 +1);
    }
    return ans;
}

int main()
{
    string S = "abcd";
    int Q[2][2] = { {2, 4}, {1, 3} };
    vector<pair<int, int>> v;
    v.push_back(make_pair(2, 4));
    v.push_back(make_pair(1, 3));

    for(int i=0; i<v.size(); i++)
    {
        cout<<go(S, v[i].first-1, v[i].second-1)<<endl;
    }
    return 0;
}
