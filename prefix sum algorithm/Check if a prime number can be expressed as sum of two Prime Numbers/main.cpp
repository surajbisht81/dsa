#include <bits/stdc++.h>
using namespace std;
/*
bool prime(int n)
{
    for(int i=2; i*i<n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
bool CanExpress(int N)
{
    if(prime(N) and prime(N-2))
        return true;
    return false;
}

int main()
{
     int N = 13;

     if(CanExpress(N))
        cout<<"Yes";
     else
        cout<<"No";
     return 0;
}
*/
//checking if a no can be represented as a prime no or not

bool isPrime(int n)
{
    if(n<=1)
        return false;
    for(int i=2; i*i<n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
void CanExpress(int N)
{
    for(int i=2; i<=N; i++)
    {
        if(isPrime(i))
        {
            if(isPrime(N-i))
            {
                cout<<"Yes and ans is :"<<i<<" and "<<N-i<<endl;
            }
        }
    }
}
int main()
{
    int N=20;
    CanExpress(N);
    return 0;
}
