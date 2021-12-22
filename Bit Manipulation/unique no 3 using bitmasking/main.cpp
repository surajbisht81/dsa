#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"\nenter size of array:";
    cin>>n;
    int *arr=new int[n];

    cout<<"\nenter array:";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int count[32]={0};

    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        int j=0;
        while(num>0)
        {
            count[j]+= (num & 1);
            j++;
            num=num>>1;
        }
    }
    int ans=0;
    int power=1;
    for(int i=0;i<32;i++)
    {
        count[i]=count[i]%3;
        ans+= count[i]*(power);
        power=power<<1;
    }
    cout<<ans<<endl;
}
