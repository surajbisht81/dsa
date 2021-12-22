/*Given two strings A and B. Minimize the number of unique characters in string A by either swapping A[i] with B[i] or keeping it unchanged. The number of swaps
 can be greater than or equal to 0. Note that A[i] can be swapped only with same index element in B. Print the minimum number of unique characters. 

Examples:

Input : A = ababa
        B = babab
Output : 1
Swapping all b's in string A, with
a's in string B results in string
A having all characters as a. 

Input : A = abaaa
        B = bbabb
Output : 2/*

#include <bits/stdc++.h>
using namespace std;

int countmin(string A,string B,int res,int idx,unordered_map<char,int>mp)
{
   if(idx==A.length())
   {
       res=min(res,(int)mp.size());
       return res;
   }

   swap(A[idx],B[idx]);
   mp[A[idx]]++;
   countmin(A,B,res,idx+1,mp);

   mp[A[idx]]--;

   if(mp[A[idx]]==0)
    mp.erase(A[idx]);

   swap(A[idx],B[idx]);
   mp[A[idx]]++;
   countmin(A,B,res,idx+1,mp);

   mp[A[idx]]--;
   if(mp[A[idx]]==0)
    mp.erase(A[idx]);
}
int main()
{

    string A = "abaaa";
    string B = "bbabb";
    int res=A.length();
    unordered_map<char,int>mp;

    cout<<"\nmin no of unique character:"<<countmin(A,B,res,0,mp);
    return 0;
}
