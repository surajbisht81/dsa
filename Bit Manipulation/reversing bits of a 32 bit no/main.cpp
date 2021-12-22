#include <bits/stdc++.h>
using namespace std;

unsigned int reverse_bit(unsigned int num)
{
   unsigned int temp=num,i;
   unsigned reversed=0;
   for(i=0;i<32;i++)
   {
       reversed|= ((num>>i)&1)<<(32-1-i);
   }
   return reversed;
}
int main()
{
    unsigned int n,i;
    cin>>n;
    unsigned int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    for( i=0;i<n;i++)
    {
        cout<<reverse_bit(arr[i])<<" ,";
    }
}
