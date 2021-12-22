#include <bits/stdc++.h>
using namespace std;

bool compare(int arr1[],int arr2[],int M)
{
    for(int i=0;i<M;i++)
    {
        if(arr1[i]!=arr2[i])
            return false;
    }
    return true;
}
void anagram_search(char *patt,char *txt)
{
    int M=strlen(patt);
    int N=strlen(txt);

    int countp[M]={0},countt[M]={0};
    for(int i=0;i<M;i++)
    {
        (countp[patt[i]])++;
        (countt[txt[i]])++;
    }

    for(int i=M;i<N;i++)
    {
        if(compare(countp,countt,M))
            cout<<"\npattern found at :"<<i-M;

        (countt[txt[i]])++;
        (countt[txt[i-M]])--;
    }
}
int main()
{
    char txt[]="isdiserve";
    char patt[]="is";
    anagram_search(patt,txt);
    return 0;
}
