#include <bits/stdc++.h>
using namespace std;
int block;
struct quary
{
    int l,r,i;
};

bool compa(quary a,quary b)
{
    //if they are not in same block
    if(a.l/block!=b.l/block)
        return a.l/block<b.l/block;
    return a.r<b.r;
}
int cnt=0;
void add(int pos,int freq[],int arr[])
{
    freq[arr[pos]]++;
    if(freq[arr[pos]]==1)
        cnt++;
}
void remove(int pos,int freq[],int arr[])
{
    freq[arr[pos]]--;
    if(freq[arr[pos]]==0)
        cnt--;
}
int main()
{
    int arr[20],ans[20],freq[20];
    quary Q[20];
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
      cin>>arr[i];
    for(int i=0;i<q;i++)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].i=i;
    }
    block=(int)sqrt(n);
    sort(Q,Q+q,compa);

    int ML=0,MR=-1;

    for(int i=0;i<q;i++)
    {
        int L=Q[i].l;
        int R=Q[i].r;
        // if quary's indices are not less than ML AND MR
        while(L<ML)
        {
            ML--;
            add(ML,freq,arr);
        }
        while(R<MR)
        {
            MR--;
            remove(MR,freq,arr);
        }
        while(L>ML)
        {
            ML++;
            remove(ML,freq,arr);
        }
        while(R>MR)
        {
            MR++;
            add(MR,freq,arr);
        }
        ans[Q[i].i]=cnt;
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
    return 0;
}
