/*Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x. The same repeated number may be chosen from arr[] unlimited number of times. Elements in a combination (a1, a2, …, ak) must be printed in non-descending order. (ie, a1 <= a2 <= … <= ak).
The combinations themselves must be sorted in ascending order, i.e., the combination with smallest first element should be printed first. If there is no combination possible the print "Empty" (without quotes).

Examples:

Input : arr[] = 2, 4, 6, 8
            x = 8
Output : [2, 2, 2, 2]
         [2, 2, 4]
         [2, 6]
         [4, 4]
         [8]*/

#include <bits/stdc++.h>
using namespace std;

void combinationalsum(vector<int> &ar,int sum,vector<vector<int>> &res,vector<int>&r,int i)
{
    //base cases
    if(sum<0)
        return;
    if(sum==0)
    {
        res.push_back(r);
        return;
    }

    while(i<ar.size() && sum-ar[i]>=0)
    {
        r.push_back(ar[i]);
        combinationalsum(ar,sum-ar[i],res,r,i);
        r.pop_back();
        i++;
    }

}

int main()
{
    vector<int> ar;
    ar.push_back(8);
    ar.push_back(1);
    ar.push_back(8);
    ar.push_back(6);
    ar.push_back(8);

    int sum=12;
    vector<vector<int>> res;
    vector<int> r;
    sort(ar.begin(),ar.end());
    ar.erase(unique(ar.begin(),ar.end()), ar.end());
    combinationalsum(ar,sum,res,r,0);

    for(int i=0;i<res.size();i++)
    {
      if(res[i].size()>0)
        for(int j=0;j<res[i].size();j++)
      {
          cout<<res[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}
