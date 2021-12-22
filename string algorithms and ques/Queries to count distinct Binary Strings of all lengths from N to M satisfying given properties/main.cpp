#include <bits/stdc++.h>
using namespace std;
const int mod =1000000007;
const int N =  1e5+5;
long dp[N];

void countStrings(vector<vector<int> > Q, int K)
{
   dp[0]=1;

   for(int i=1; i<N; i++)
   {
       dp[i]=dp[i-1];

       if(i>=K)
       {
           dp[i] = (dp[i] + dp[i-K])%mod;
       }
   }
   for(int i=1; i<N; i++)
    dp[i]= (dp[i] + dp[i-1])%mod;

   for(int i=0; i<Q.size(); i++)
   {
       long ans = (dp[Q[i][1]]-dp[Q[i][0]-1]);

       cout<<ans<<endl;
   }

}
int main()
{
    int K = 3;
    vector<vector<int> > Q
        = { { 1, 4 }, { 3, 7 } };

  countStrings(Q, K);
  return 0;
}
