#include <bits/stdc++.h>
using namespace std;

void findsubsets(vector<int>&arr,vector<int>&sub,vector<vector<int>>&res,int idx)
{
    res.push_back(sub);
    for(int i=idx;i<arr.size();i++)
    {
        sub.push_back(arr[i]);
        findsubsets(arr,sub,res,i+1);
        sub.pop_back();
    }
    return;
}
int main()
{
    vector<int> array = { 1, 2, 3};

    vector<int> subset;
    vector<vector<int>>res;
    findsubsets(array,subset,res,0);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
