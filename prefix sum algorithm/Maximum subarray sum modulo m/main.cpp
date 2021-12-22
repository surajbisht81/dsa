/*
  This is brute force approach;
#include <bits/stdc++.h>
using namespace std;

int MaxSum(int arr[], int n, int m)
{
    int maxim=0;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            sum= (sum+arr[j]) % m;
            maxim = max(maxim, sum);
        }
    }
    return maxim;
}
int main()
{
    int arr[] = {3, 3, 9, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m=7;
    cout<<MaxSum(arr, n, m);
    return 0;
}
*/


//This is prefix sum algorithm approach
/*Let prefix sum for index i be prefixi, i.e.,
prefixi = (arr[0] + arr[1] + .... arr[i] ) % m

Let maximum sum ending with i be, maxSumi.
Let this sum begins with index j.

maxSumi = (prefixi - prefixj + m) % m

From above expression it is clear that the
value of maxSumi becomes maximum when
prefixj is greater than prefixi
and closest to prefixi*/

#include<bits/stdc++.h>
using namespace std;

int MaxSum(int arr[], int n, int m)
{
    int maxim=-1;
    int prefix=0;

    set<int> s;
    s.insert(0);

    for(int i=0; i<n; i++)
    {
       prefix = (prefix+arr[i]) % m;

       maxim = max(maxim, prefix);

       auto it = s.upper_bound(prefix);

       if(it!=s.end())
            maxim = max(maxim, prefix-(*it)+m );

       s.insert(prefix);
    }
    return maxim;
}
int main()
{
    int arr[] = {3, 3, 9, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m=7;
    cout<<MaxSum(arr, n, m);
    return 0;
}
