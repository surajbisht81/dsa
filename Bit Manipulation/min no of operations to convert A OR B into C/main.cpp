#include <bits/stdc++.h>
using namespace std;

int min_no_of_operations(int a,int b,int c)
{
    int cnt=0;
    for(int i=0;i<32;i++)
    {
        bool x=false,y=false,z=false;
        if(a & (1<<i))
            x=true;
        if(b & (1<<i))
            y=true;
        if(c & (1<<i))
            z=true;

        if(z==true)
        {
            if(x==false && y==false)
                cnt++;
        }
        else
        {
            if(x==true && y==true)
               cnt+=2;
            if((x==true && y==false) or (x==false && y==true))
                cnt++;
        }
    }
        return cnt;
}
int main()
{
    int A,B,C;
    cout<<"enter A,B and C: ";
    cin>>A>>B>>C;
    cout<<"\nmin no of operations:"<<min_no_of_operations(A,B,C);
    return 0;
}
