#include <bits/stdc++.h>
using namespace std;

string RemoveString(string str, char X)
{
    if(str.length()==0)
        return "";

    if(str[0]==X)
    {
       return RemoveString(str.substr(1), X);
    }

    return str[0]+ RemoveString(str.substr(1), X);
}
int main()
{
    string str = "geeksforgeeks";
    char X = 'e';
    cout<<RemoveString(str, X);
    return 0;
}
