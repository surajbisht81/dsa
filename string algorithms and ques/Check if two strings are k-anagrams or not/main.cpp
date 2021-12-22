#include <bits/stdc++.h>
using namespace std;

#define M 26
bool arekAnagrams(string str1, string str2, int k)
{
    int n = str1.length();
    if(str2.length()!=n)
        return false;

    int count1[M]={0}, count2[M]={0};

    for(int i=0; i<n; i++)
    {
        count1[str1[i]-'a']++;
        count2[str2[i]-'a']++;
    }
    int count=0;
    for(int i=0; i<M; i++)
    {
        if(count1[i]> count2[i])
            count = count + abs(count1[i]-count2[i]);
    }
    if(count<=k)
    return true;
    return false;
}
int main()
{
    string str1 = "anagram";
    string str2 = "grammar";
    int k = 2;
    if (arekAnagrams(str1, str2, k))
        cout << "Yes";
    else
        cout<< "No";
    return 0;
}
