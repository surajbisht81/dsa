// This code will not run

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

void Seive(vector<int> &v)
{
   bool prime[MAX];
   memset(prime, true, sizeof(prime));

   for(int i=2; i*i<MAX; i++)
   {
       if(prime[i])
       {
           for(int p=i*i; p<=MAX; p+=i)
           {
               prime[p]=false;
           }
       }
   }
   for(int i=2; i<=MAX; i++)
   {
       if(prime[i])
        v.push_back(i);
   }
}
int LSCPutil(int limit, vector<int> primes, long long int sum_primes[])
{
    int max_length=-1;
    int prime=-1;

    for(int i=0; primes[i]<limit; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(sum_primes[i]-sum_primes[j]>limit)
                break;
            long long int consum = sum_primes[i]-sum_primes[j];
            if(binary_search(primes.begin(), primes.end(), consum))
            {
                if(max_length<i-j+1)
                {
                    max_length=i-j+1;
                    prime=consum;
                }
            }
        }
    }
    return prime;
}
void LSCP(int arr[], int n)
{
    vector<int > primes;
    Seive(primes);

    long long int sum_primes[primes.size()+1];
    sum_primes[0]=0;

    for(int i=1; i<=primes.size(); i++)
      sum_primes[i] = sum_primes[i-1]+primes[i-1];

    for(int i=0; i<n; i++)
        cout<<LSCPutil(arr[i], primes, sum_primes)<<" ";
}
int main()
{
    int arr[] = {10, 30, 40, 50, 1000};
    int n = sizeof(arr)/sizeof(arr[0]);
    LSCP(arr, n);
    return 0;
}
