#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int n=str.length();

    int no_of_subsequence= (1<<n)-1;
    cout<<"{ }"<<endl;
    for(int i=1;i<=no_of_subsequence;i++)
    {
        int temp=i,j=0;
        while(temp>0)
        {
            if(temp & 1)
                cout<<str[j];
            j++;
            temp=temp>>1;
        }
        cout<<endl;
    }
    return 0;
}
