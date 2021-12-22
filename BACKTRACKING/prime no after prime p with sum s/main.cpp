#include <bits/stdc++.h>
using namespace std;

vector<int>prime;
vector<int> sett;
void display()
{
    int l=sett.size();
    for(int i=0;i<l;i++)
    {
        cout<<sett[i]<<" ";
    }
    cout<<endl;
}
bool isprime(int x)
{
    if(x==1)
        return true;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
void primesum(int idx,int S,int N,int total)
{
    //base case
    if(total==S && N==sett.size())
    {
        display();
        return;
    }
    if(total>S || idx==prime.size())
        return;

    sett.push_back(prime[idx]);
    primesum(idx+1,S,N,total+prime[idx]);
    sett.pop_back();
    primesum(idx+1,S,N,total);    //backtracking
}
void allprime(int S,int N,int P)
{
    for(int i=P+1;i<=S;i++)
    {
        if(isprime(i))
            prime.push_back(i);
    }
    if(prime.size()<N)
        return;
    primesum(0,S,N,0);
}
int main()
{
    int S = 54, N = 2, P = 3;
    allprime(S,N,P);
    return 0;
}
