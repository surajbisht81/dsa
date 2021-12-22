#include <bits/stdc++.h>
using namespace std;

void compute_LPS(int M,char *patt,int *lps)
{
    lps[0]=0;
    int i=1;
    int j=0;
    while(i<M)
    {
        if(patt[i]==patt[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
void KMP_search(char *txt,char *patt)
{
    int M=strlen(patt);
    int N=strlen(txt);
    int lps[M];
    compute_LPS(M,patt,lps);

    int i=0,j=0;
    while(i<N)
    {
        if(txt[i]==patt[j])
        {
            i++;
            j++;
        }
        if(j==M)
        {
            cout<<"\npattern found at index: "<<i-j<<endl;
        }
        else if(i<N && patt[j]!=txt[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
}
int main()
{
    char txt[]="ABABDABACDABABCABAB";
    char patt[]="ABABCABAB";
    KMP_search(txt,patt);
    return 0;
}
