#include <bits/stdc++.h>
using namespace std;

struct Query
{
    int l,r;
};
int block;
bool compare(Query a,Query b)
{
    if(a.l/block!=b.l/block)
        return a.l/block<b.l/block;
    return a.r<b.r;
}
void queryResults(int a[],int n,Query q[],int m)
{
    block=(int)sqrt(n);
    sort(q,q+m,compare);
    int sum=0;
    int ML=0,MR=-1;
    for(int i=0;i<m;i++)
    {
        int L=q[i].l;
        int R=q[i].r;

        while(ML<L)
        {
          sum-=a[ML];
          ML++;
        }
        while(ML>L)
        {
            sum+=a[ML];
            ML--;
        }
        while(MR<R)
        {
            MR++;
            sum+=a[MR];
        }
        while(MR>R)
        {
            sum-=a[MR];
            MR--;
        }
        cout<<"sum of ["<<L<<"] and ["<<R<<"] is"<<sum<<endl;
    }
}
int main()
{
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    int n = sizeof(a)/sizeof(a[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4}};
    int m = sizeof(q)/sizeof(q[0]);
    queryResults(a, n, q, m);
    return 0;
}
