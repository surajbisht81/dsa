#include <bits/stdc++.h>
using namespace std;

void SortArray(string arr[], int n, int I, int X)
{
    map<pair<string, string>, int> mp;

    for(int i=0; i<n; i++)
    {
        string str1 = arr[i];
        string str2 = str1.substr(I,X);
        mp[{str2, str1}] +=1;
    }

    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        for(int i=0; i<it->second; i++)
        {
            cout<<it->first.second<<endl;
        }
    }
}

int main()
{
     string arr[] = {"baqwer", "zacaeaz", "aaqzzaa", "aacaap", "abbatyo", "bbbacztr", "bbbdaaa"};
     int n = sizeof(arr)/sizeof(arr[0]);

     int I = 2, X = 2;
     SortArray(arr, n, I, X);
     return 0;
}
