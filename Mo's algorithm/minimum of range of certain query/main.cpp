#include<bits/stdc++.h>
using namespace std;

struct Query
{
    int l,r;
};
int blocks;
int F[20];
bool compare(Query a,Query b)
{
    if(a.l/blocks!=b.l/blocks)
        return a.l/blocks<b.l/blocks;
    return a.r<b.r;
}
int minValueInBlocks(int idx,int a[])
{
    int F=INT_MAX;
    for(int i=idx*blocks;i<blocks+(idx*blocks);i++)
        F=min(F,a[i]);
    return F;
}
void findminimum(int a[],int n,Query q[],int m)
{
    sort(q,q+m,compare);

    for(int j=0;j<m;j++)
    {
        int LB=q[j].l/blocks;
        int RB=q[j].r/blocks;
        int mn=INT_MAX;
        if(LB==RB)
        {
            for(int i=q[j].l;i<=q[j].r;i++)
                mn=min(mn,a[i]);
        }
        else
        {
            for(int i=q[j].l;i<blocks*(LB+1);i++)
                mn=min(mn,a[i]);

            for(int i=LB+1;i<RB;i++)
                mn=min(mn,minValueInBlocks(i,a));

            for(int i=RB*blocks;i<=q[j].r;i++)
                mn=min(mn,a[i]);
        }
        cout<<"\nmin in range ["<<q[j].l<<"] and ["<<q[j].r<<"] is="<<mn;
    }
}
int main()
{
    int n,m;
    int a[]={1,3,0,5,9,3,6,5,9,2,8,9,3,5,8,3,8,0,2,5,1,6};
    Query q[]={{5,16},{3,4},{3,9}};
    n=sizeof(a)/sizeof(a[0]);
    m=sizeof(q)/sizeof(q[0]);
    blocks=(int)sqrt(n);
    findminimum(a,n,q,m);
    return 0;
}
