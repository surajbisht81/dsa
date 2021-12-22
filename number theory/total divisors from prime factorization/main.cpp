#include <bits/stdc++.h>
using namespace std;
int total_divisors(int num)
{
    int res=1;
    vector<int> v;
    for(int i=2;i<=num;i++)
        if(num%i==0)
        {
          int cnt=0;
          while(num%i==0)
          {
            cnt++;
            num=num/i;
          }
          v.push_back(cnt);
        }
  for(int i=0;i<v.size();i++)
  {
      res=res*(v[i]+1);
  }
  return res;
}
int main()
{
    int num;
    cout<<"\nenter number :";
    cin>>num;
    cout<<"\ntotal divisors="<<total_divisors(num);
    return 0;
}
